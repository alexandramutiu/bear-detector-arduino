
//PIN Defifition
#define PIN_LED_RED   7
#define PIN_LED_WHITE 8
#define PIN_TRIG      2
#define PIN_ECHO      3
#define PIN_BUZZER    9

//Thresholds for the distances
const int DISTANCE_THRS = 150;
const long MEASURE_INTV = 100;

//State
bool alarmActive = false;
void setup() {
  pinMode(PIN_LED_RED, OUTPUT);
  pinMode(PIN_LED_WHITE, OUTPUT);
  pinMode(PIN_BUZZER, OUTPUT);
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);

  Serial.begin(9600);
  Serial.println("System ready. Detection on!");
}

void loop() {
  long distance = getDistance();
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if(distance>0 && distance <= DISTANCE_THRS){
    alarmActive = true;
  }
  if(alarmActive){
    runAlarm(distance);
  }else{
    allOff();
  }
  delay(MEASURE_INTV);
}

//Implementing the functions
long getDistance()
{
  digitalWrite(PIN_TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);

  long t = pulseIn(PIN_ECHO, HIGH, 30000);
  if(t == 0) return -1;

  return t*0.034/2;
}

void runAlarm(long currentDistance){
  digitalWrite(PIN_LED_WHITE, HIGH);
  static unsigned long lastFlash = 0;
  static bool redState = false;
  if(millis() - lastFlash >=200){
    redState=!redState;
    digitalWrite(PIN_LED_RED, redState);
    lastFlash=millis();
  }
  digitalWrite(PIN_BUZZER, redState);
  if (currentDistance >= DISTANCE_THRS || currentDistance == -1) {
    alarmActive = false;
    Serial.println("Intruder left — alarm OFF");
  }
}

void allOff()
{
  digitalWrite(PIN_LED_RED, LOW);
  digitalWrite(PIN_LED_WHITE, LOW);
  digitalWrite(PIN_BUZZER, LOW);

}
