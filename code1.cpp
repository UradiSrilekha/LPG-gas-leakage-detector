#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0*27,16,2);
#include <SoftwareSerial.h>
SoftwareSerial BTSerial(10, 11); // RX, TX pins for HC05
const int gasSensorPin = A0;      // MQ-2 sensor connected to A0
const int threshold = 400;         // Set a threshold for gas detection
int led1=7;
int buzzer=13;
int GASA0=A0;
int gasvalue;
void setup() {
  lcd.init();
  lcd.backlight();
  BTSerial.begin(9600);
  Serial.begin(9600);
  pinMode(7,OUTPUT);
pinMode(buzzer,OUTPUT);
lcd.setCursor(2,0);
lcd.print("GAS LEAKAGE");
lcd.setCursor(2,1);
lcd.print("GAS LEAKAGE DETECTION");
delay(3000);
lcd.clear();
lcd.setCursor(2,0);
lcd.print("GAS LEAKAGE");
lcd.setCursor(0,1); 
lcd.print("GAS LEAKAGE DETECTED");
  Serial.begin(9600);              // Start serial communication with PC
  BTSerial.begin(9600);            // Start serial communication with HC05
  pinMode(gasSensorPin, INPUT);    // Set gas sensor pin as input
  Serial.println("Gas Leakage Detection System Initialized");
}

void loop() {
  int gasValue = analogRead(gasSensorPin); 
  lcd.setCursor(0, 1);                     // Set cursor to the second line
  lcd.print("Gas Level: ");                 // Print static message
  lcd.print(gasValue);  // Read gas sensor value
  Serial.print("Gas Level: ");
  Serial.println(gasValue);
  

  // Check if gas level exceeds threshold
  if (gasValue > threshold) {
    lcd.setCursor(0, 0);                   // Set cursor to first line
    lcd.print("Gas Leak Detected!   ");    // Display gas leak message
  } else {
    lcd.setCursor(0, 0);                   // Set cursor to first line
    lcd.print("No Gas Leak         ");      // Display no gas leak message
  }

  delay(1000); // Delay for 1 second before next reading
}
  digitalWrite(led1,HIGH);
  delay(1000);
  digitalWrite(led1,LOW);
{  
  delay(1000);
  }
  int sensorValue=analogRead(GASA0);
  BTSerial.println(sensorValue);
  }
  delay(1000);
}   
  }  }
  void sendSMS(String message) {
  BTSerial.print("AT+CMGF=1\r"); // Set SMS mode
  delay(1000);
  BTSerial.print("AT+CMGS=\"+xxxxxxxxxx\"\r"); // Replace with your mobile number
  delay(1000);
  BTSerial.print(message); // Message content
  delay(100);
  BTSerial.write(26); // Send Ctrl+Z to send the message
  Serial.println("SMS Sent: " + message);
}