#include <Servo.h> 
#include <math.h> 

Servo myservo;
char veri;
int fan = 3;
int aydinlatma = 13; 

void setup() {
  // Kurulum

  myservo.attach(9);
  myservo.write(0);
  pinMode(fan, OUTPUT);
  pinMode(aydinlatma, OUTPUT);

  Serial.begin(9600);

}

void loop() {
  veri = Serial.read(); // Bluetooth'dan Gelen Değeri Veri Değişkenine Ata


//Kapı kontrol

  // Gelen Değer 3 İse kapıyı açacak
  if(veri=='3'){
     Serial.print("kapı açılacak");
    myservo.write(90);
  }

  //Gelen Değer 4 İse kapıyı kapatacak

  if(veri=='4'){
    Serial.print("kapı kapanacak");
    myservo.write(10);

  }
  if(veri=='5'){
    Serial.print("Klima Devrede");
    digitalWrite(fan, HIGH);
  }

  //Gelen Değer 6 İse Fanı Kapat
  if(veri=='6'){
    
    Serial.print("Klima Kapali");
    digitalWrite(fan, LOW);
  }
  
  if(veri=='0'){
    
    Serial.print("Aydınlatmalar Kapaniyor..");
    digitalWrite(aydinlatma, LOW);

  }
  
  // Gelen Değer 1 İse Aydınlatmaları Aç
  if(veri=='1'){
    
    Serial.print("Aydınlatmalar Aciliyor..");
    digitalWrite(aydinlatma, HIGH);


  }

 
}

