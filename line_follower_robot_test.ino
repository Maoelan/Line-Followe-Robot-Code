#define In1 7 //deklarasi pin MotorDriver untuk penggerak dinamo 1
#define In2 8 //deklarasi pin MotorDriver untuk penggerak dinamo 1
#define In3 9 //deklarasi pin MotorDriver untuk penggerak dinamo 2
#define In4 10 //deklarasi pin MotorDriver untuk penggerak dinamo 2

#define sensor1 2 //deklarasi untuk sensor infrared 1
#define sensor2 3 //deklarasi untuk sensor infrared 2

#define trigPin 12 //deklarasi untuk trig pin sensor ultrasonic
#define echoPin 13 //deklarasi untuk echo pin sensor ultrasonic

int buzzer = 6; //deklarasi pin untuk buzzer

void setup() { //fungsi untuk menentukan input dan output
  // put your setup code here, to run once:
  pinMode(sensor1, INPUT); //sensor1 infrared akan digunakan sebagai input
  pinMode(sensor2, INPUT); //sensor2 infrared akan digunakan sebagai input
  pinMode(In1, OUTPUT); //motordriver ln1 digunakan sebagai output penggerak dinamo
  pinMode(In2, OUTPUT); //motordriver ln1 digunakan sebagai output penggerak dinamo
  pinMode(In3, OUTPUT); //motordriver ln1 digunakan sebagai output penggerak dinamo
  pinMode(In4, OUTPUT); //motordriver ln1 digunakan sebagai output penggerak dinamo
  pinMode(echoPin, INPUT); //echopin sensor ultrasonic sebagai input
  pinMode(trigPin, OUTPUT); //trigpin sensor ultrasonic sebagai output
  pinMode(buzzer, OUTPUT); //buzzer sebagai output
  Serial.begin(9600); //untuk memulai serial
}

void maju(){ //fungsi agar motordriver ke dinamo bisa berjalan maju
  digitalWrite(In1, HIGH); //ln1 bernilai high atau roda kanan maju
  digitalWrite(In2, LOW); //ini bernilai low apabila high roda kanan akan mundur
  digitalWrite(In3, HIGH); //ln1 bernilai high atau roda kiri maju
  digitalWrite(In4, LOW); //ini bernilai low apabila high roda kiri akan mundur
}

void mundur(){ //fungsi agar motordriver ke dinamo bisa berjalan mundur
  digitalWrite(In1, LOW); //ini bernilai low apabila high roda kanan akan maju
  digitalWrite(In2, HIGH); //ln1 bernilai high atau roda kanan mundur
  digitalWrite(In3, LOW); //ini bernilai low apabila high roda kiri akan 
  digitalWrite(In4, HIGH); //ln1 bernilai high atau roda kiri mundur
}

void berhenti(){ //fungsi agar motordrive ke dinamo tidak bergerak
  digitalWrite(In1, LOW); //bernilai low maka akan diam
  digitalWrite(In2, LOW); //bernilai low maka akan diam
  digitalWrite(In3, LOW); //bernilai low maka akan diam
  digitalWrite(In4, LOW); //bernilai low maka akan diam
}

void loop() { //menjelankan program
  int nilaiSensor1 = digitalRead(sensor1); //membaca masukan dari sensor1
  int nilaiSensor2 = digitalRead(sensor2); //membaca masukan dari sensor2

  Serial.print(buzzer); //untuk menampilkan nilai output dari buzzer

  if(nilaiSensor1 == LOW){ //apabila sensor1 bernilai LOW
    Serial.println("Bukan Garis"); //menampilkan Bukan Garis pada serial monitor
  }
  if(nilaiSensor1 == HIGH){ //apabila sensor1 bernilai HIGH
    Serial.println("Garis"); //menampilkan Garis pada serial monitor
  }

  if(nilaiSensor2 == LOW){ //apabila sensor1 bernilai LOW
    Serial.println("Bukan Garis"); //menampilkan Bukan Garis pada serial monitor
  }
  if(nilaiSensor2 == HIGH){ //apabila sensor1 bernilai HIGH
    Serial.println("Garis"); //menampilkan Garis pada serial monitor
  }
  
  long duration, distance; //deklarasi duration dan distance untuk sensor ultrasonic
  digitalWrite(trigPin, LOW); //trigpin bernilai LOW
  digitalWrite(trigPin, HIGH); //trigpin bernilai HIGH
  digitalWrite(trigPin, LOW); //trigpin bernilai LOW
  duration = pulseIn(echoPin, HIGH); //untuk menentukan durasi dari ultrasinoc
  distance = (duration/2) / 29.1; //agar sensor ultrasonic dapat menentukan jarak
  Serial.print("Jarak: ");  //menampilkan kata jarak pada serial monitor
  Serial.print(distance); //menampilkan nilai distance 
  Serial.println("cm"); //menampilkan kata cm pada serial monitor

  if (distance < 8){ //apabila sensor ultrasonic mendeteksi benda berjarak kurang dari 8 cm
    if((nilaiSensor1 == LOW) && (nilaiSensor2 == LOW)){ //jika nilai sensor 1 dan 2 LOW
      mundur(); //robot akan berjalan mundur
      delay(200); //delay200
      digitalWrite(buzzer, HIGH); //buzzer akan berbunyi
      delay(200); //delay 200
    }
  } 
  else { //apabila robot tidak mendeteksi benda pada jarak lebih dari 7 cm
    if((nilaiSensor1 == LOW) && (nilaiSensor2 == LOW)){ //jika sensor 1 dan 2 bernilai LOW
      berhenti(); //robot akan berhenti
      delay(200); //delay 200
      digitalWrite(buzzer, LOW); //buzzer tidak akan berbunyi
      delay(200); //delay 200
    }
    else if((nilaiSensor1 == HIGH) && (nilaiSensor2 == HIGH)){ //jika sensor 1 dan 2 bernilai HIGH
      maju(); //robot akan maju mengikuti garis
      delay(200); //delay 200
      digitalWrite(buzzer, LOW); //buzzer tidak akan berbunyi
      delay(200); //delay 200
    }
   }
 }
