const int led_1 = 8;
const int led_2 = 11;

unsigned long led_1OnTime;
unsigned long led_2OnTime;

bool led_1On;
bool led_2On;

int incomingByte = Serial.read();  // переменная для хранения полученного байта


void setup() {
  pinMode (led_1, OUTPUT);
  pinMode (led_2, OUTPUT);

  led_1On = false;
  led_2On = false;
  
  Serial.begin(9600); // устанавливаем последовательное соединение
}


void loop() {
  if (Serial.available() > 0) {  //если есть доступные данные
    // считываем байт
    incomingByte = Serial.read();

    // прием данных с монитора порта
    if (incomingByte == 49) {
      digitalWrite(led_1, HIGH);
      //led_1On = true;
      led_1OnTime = millis();
      
      //установка времени для первого светодиода
      if(led_1On) {
         if ((millis() - led_1OnTime) > 30000) {
          led_1OnTime = millis();
          digitalWrite(led_1, LOW);
          led_1On = false;
          }
         }
        }
    else if (incomingByte == 50) {
      digitalWrite(led_2, HIGH);
      led_2On = true;
      // led_2OnTime = millis();

      // установка времени для второго светодиода
      if(led_2On) {
         if ((millis() - led_2OnTime) > 10000) {
          led_2OnTime = millis();
          digitalWrite(led_2, LOW);
          led_2On = false;
          }
         }
      }
    else {
      digitalWrite(led_1, LOW);
      digitalWrite(led_2, LOW);
      }
      
    // установка времени

    /*
    if(led_1On) {
      if (millis() - led_1OnTime > 30000) {
        digitalWrite(led_1, LOW);
        led_1On = false;
        }
      } */
    /*
    if(led_2On) {
      if (millis() - led_2OnTime > 30000) {
        digitalWrite(led_2, LOW);
        led_2On = false;
        }
      }  */
      
    // отсылаем то, что получили
    Serial.print("I received: ");
    Serial.println(incomingByte, DEC);
  }
}
