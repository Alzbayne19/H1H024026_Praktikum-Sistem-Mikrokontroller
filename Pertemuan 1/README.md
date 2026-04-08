# **Jawaban Pertanyaan Praktikum Modul I: Percabangan dan Perulangan**

## **Percobaan 1A: Percabangan (Poin 1.5.4)**

**1\. Pada kondisi apa program masuk ke blok if?** Program akan mengeksekusi blok kode di dalam pernyataan if ketika variabel timeDelay memiliki nilai kurang dari atau sama dengan 100 (logika timeDelay \<= 100). 1

**2\. Pada kondisi apa program masuk ke blok else?** Program akan masuk ke blok else apabila kondisi pada pernyataan if tidak terpenuhi, yang dalam hal ini berarti nilai variabel timeDelay masih lebih besar dari 100\. 1

**3\. Apa fungsi dari perintah delay(timeDelay)?** Perintah delay(timeDelay) berfungsi untuk menghentikan sementara (jeda) eksekusi program selama durasi waktu yang ditentukan oleh isi variabel timeDelay dalam satuan milidetik. 2

**4\. Source Code**

Untuk source code ada di folder source code.

## ---

**Percobaan 2A: Perulangan (Poin 1.6.4)**

**1\. Rangkaian Schematic**

Rangkaian schematic ada di folder dokumentasi.

**2\. Jelaskan bagaimana program membuat efek LED berjalan dari kiri ke kanan\!** Efek LED berjalan dari kiri ke kanan dihasilkan oleh struktur perulangan for yang melakukan penambahan (*increment*) nomor pin secara berurutan mulai dari pin digital terendah (pin 2\) hingga pin tertinggi (pin 7). 3 Pada setiap tahap perulangan, pin tersebut diatur ke status HIGH, diberi jeda waktu, lalu diatur kembali ke LOW sebelum berlanjut ke pin berikutnya.

**3\. Jelaskan bagaimana program membuat LED kembali dari kanan ke kiri\!** Efek kembali dihasilkan oleh struktur perulangan for kedua dengan logika pengurangan (*decrement*), di mana nomor pin dimulai dari pin digital tertinggi (pin 7\) dan berkurang satu per satu hingga mencapai pin terendah (pin 2). 3 Hal ini menciptakan impresi visual cahaya yang bergerak mundur.

**4\. Source Code**

Untuk source code ada di folder source code.

#### **Karya yang dikutip**

1. Modul I Percabangan dan Perulangan (1) (1).pdf  
2. arduino untuk pemula \- CV WIDINA MEDIA UTAMA (WBP Bandung), diakses April 7, 2026, [https://repository.penerbitwidina.com/media/publications/564569-arduino-untuk-pemula-memahami-dasar-dasa-875444c2.pdf](https://repository.penerbitwidina.com/media/publications/564569-arduino-untuk-pemula-memahami-dasar-dasa-875444c2.pdf)  
3. Untitled \- Eureka Media Aksara Repository, diakses April 7, 2026, [https://repository.penerbiteureka.com/media/publications/559673-cara-mudah-kuasai-mikrokontroler-arduino-8e3c01a3.pdf](https://repository.penerbiteureka.com/media/publications/559673-cara-mudah-kuasai-mikrokontroler-arduino-8e3c01a3.pdf)  
4. Implementasi Teknik I/O Interfacing berbasis Arduino \- Neliti, diakses April 7, 2026, [https://media.neliti.com/media/publications/246013-implementasi-teknik-io-interfacing-berba-943ab820.pdf](https://media.neliti.com/media/publications/246013-implementasi-teknik-io-interfacing-berba-943ab820.pdf)