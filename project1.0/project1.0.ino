include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2); 

int button = 2;
int lcd_val = 0;
int butt_state = 0;

int temp1 = A0;
float temp = 0;

int light = A1;

void setup() 
{
  Serial.begin(9600);
  lcd.init();       
  lcd.backlight();     

  pinMode(button, INPUT);
  pinMode(3, OUTPUT);   // fan
  pinMode(8, OUTPUT);   // light / LED
}

void temp_sensor(){
  float temp_val = analogRead(temp1);
  temp = temp_val * (5.0 / 1023.0) * 100.0; 

  lcd.setCursor(0,0);
  lcd.print("TEMPERATURE    ");
  lcd.setCursor(0,1);
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.print((char)223);
  lcd.print("C  "); 
}

void fan(){
  if(temp > 40){
    digitalWrite(3, HIGH); // fan ON
  } else {
    digitalWrite(3, LOW);  // fan OFF
  }
}

void light_sensor(){
  int light_val = analogRead(light);
  Serial.println(light_val);

  lcd.setCursor(0,1);
  lcd.print("Light: ");
  lcd.print(light_val);
  lcd.print("   ");

  if(light_val<100){      
    digitalWrite(8, HIGH);    
  } else {                    
    digitalWrite(8, LOW);    
  }
}

void loop() 
{
  butt_state = digitalRead(button);
  
  if(butt_state == HIGH){
    lcd_val++;
    while(digitalRead(button) == HIGH); // wait for release
    lcd.clear();
  }

  switch(lcd_val){
    case 1:
      temp_sensor();
      fan();
      break;

    case 2:
      lcd.setCursor(0,0);
      lcd.print("LIGHT SAVINGS  ");
      light_sensor();
      break;

    case 3:
      lcd.setCursor(0,0);
      lcd.print("Mode 3         ");
      break;

    default:
      lcd_val = 0;
      break;
  }

  delay(200); 
}

