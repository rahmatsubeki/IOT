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

void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  pinMode(LED_BUILTIN, OUTPUT);  // Inisialisasi pin LED bawaan
  digitalWrite(LED_BUILTIN, HIGH);
}

BLYNK_WRITE(V1) {
  int ledState = param.asInt();
  Serial.println("tombol dirubah");
  Serial.println(ledState);
  if (ledState == HIGH) {
    digitalWrite(LED_BUILTIN, LOW);  // Kontrol LED bawaan
    // Lampu menyala, kirim tanda ke Blynk
    Blynk.virtualWrite(V2, "Lampu Menyala!");

  }else{
    digitalWrite(LED_BUILTIN, HIGH);  // Kontrol LED bawaan
    // Lampu menyala, kirim tanda ke Blynk
    Blynk.virtualWrite(V2, "Lampu Tidak Menyala!");
  }
}

void loop() {
  Blynk.run();
}
