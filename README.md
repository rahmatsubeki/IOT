# IOT
Instalasi Board ESP8266 pada Arduino IDE:

1. Buka Arduino IDE:
   - Pastikan Arduino IDE sudah diunduh dan diinstal di komputer Anda.
2. Buka Preferences:
   - Pergi ke "File" -> "Preferences" (Windows/Linux) atau "Arduino" -> "Preferences" (Mac).
3. Tambahkan URL Papan ESP8266:
   - Di kolom "Additional Boards Manager URLs", tambahkan URL berikut:
     http://arduino.esp8266.com/stable/package_esp8266com_index.json
 
4. Buka Papan Board Manager:
   - Pergi ke "Tools" -> "Board" -> "Boards Manager..."
5. Instal Board ESP8266:
   - Cari "esp8266" dalam Boards Manager.
   - Pilih pustaka "esp8266" dan klik "Install" untuk mengunduh dan menginstal board.
6. Pilih Board ESP8266:
   - Setelah instalasi selesai, pilih papan ESP8266 dari "Tools" -> "Board" -> "ESP8266 Boards" dan pilih model yang sesuai dengan modul ESP8266 yang Anda gunakan (misalnya NodeMCU, Wemos D1 Mini, dll.).
7. Pilih Port:
   - Pilih port yang digunakan oleh ESP8266 dari "Tools" -> "Port".




Instalasi Library Pendukung Blynk:
1. Buka Library Manager:
   - Pergi ke "Sketch" -> "Include Library" -> "Manage Libraries..."
2. Cari dan Instal Blynk Library:
   - Di Library Manager, ketik "Blynk" pada kolom pencarian.
   - Pilih library "Blynk" yang dikembangkan oleh Blynk Inc., dan klik "Install".
