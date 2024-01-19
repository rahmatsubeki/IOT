//kode blink
#define BLYNK_TEMPLATE_ID "TMPL6iafnQzxN"
#define BLYNK_TEMPLATE_NAME "smpk"
#define BLYNK_PRINT Serial
//kode esp yang ke blynk
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// deklarasi token
char auth[] = "fAwPATmNdEmqGV6_y6Tcl-3ATXsKcmZV";
//deklarasi inter jaringan
char ssid[] = "RMT";
char pass[] = "dawarblandong";

//deklarasi led
const int ledU = D2;
const int ledM = D5;
const int ledK = D4;
const int ledH = D3;
int traficStatus = 0;

void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  pinMode(ledU, OUTPUT);  // Inisialisasi pin LED 3 Warna
  pinMode(ledM, OUTPUT);  // Inisialisasi pin LED Merah
  pinMode(ledK, OUTPUT);  // Inisialisasi pin LED Kuning
  pinMode(ledH, OUTPUT);  // Inisialisasi pin LED Hijau
}

BLYNK_WRITE(V1) {
  int ledState = param.asInt();
  Serial.println("tombol dirubah");
  Serial.println(ledState);
  if (ledState == HIGH) {
    digitalWrite(ledU, HIGH);  // Kontrol LED Utama
    
    Blynk.virtualWrite(V2, "Lampu Menyala!"); // Lampu menyala, kirim tanda ke Blynk
  }else{
    digitalWrite(ledU, LOW);  // Kontrol LED bawaan
    
    Blynk.virtualWrite(V2, "Lampu Tidak Menyala!"); // Lampu tidak menyala, kirim tanda ke Blynk
  }
}

BLYNK_WRITE(V3) {
  int ledStatus = param.asInt();
  if (ledStatus == HIGH) {
    traficStatus = 1;  // Set traficStatus menjadi 1 jika tombol diaktifkan
  } else {
    traficStatus = 0;  // Set traficStatus menjadi 0 jika tombol dinonaktifkan
  }
}

void loop() {
  Blynk.run();
  if (traficStatus == 1) {
    trafficControl();  // Panggil fungsi trafic() jika traficStatus == 1
  }
}

void trafficControl(){
  digitalWrite(ledM, HIGH);
  delay(10000);
  digitalWrite(ledM, LOW);

  for (int i = 0; i < 2; i++) {
    digitalWrite(ledK, HIGH);
    delay(500);
    digitalWrite(ledK, LOW);
    delay(500);
  }

  for (int i = 0; i < 3; i++) {
    digitalWrite(ledK, HIGH);
    delay(500);
    digitalWrite(ledK, LOW);
  }

  digitalWrite(ledH, HIGH);
  delay(15000);
  digitalWrite(ledH, LOW);

}
