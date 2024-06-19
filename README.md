## Penggunaan

### Tentu saja Python

Seluruhnya hanya menggunakan libary bawaan python, jadi kamu hanya perlu menjalankan program `main.py`, dan langsung memasukan nama file wordlist milikmu untuk diproses

```
~$ python3 main.py
```

### Kenapa C++ ??

Python mungkin tidak dapat menampung file wordlist yang terlalu besar sampai lebih dari 1 Giga Byte. Saya telah mencoba melakukannya pada wordlist milik saya yang berukuran 3.7GB dan hasilnya force error. C++ mungkin bisa menjadi solusi karena dapat melakukan management memory dan resource dengan lebih mendalam

```
~$ g++ main.cpp
~$ ./a.out
```

### Wordlist masih terlalu besar

Saya terpikirkan untuk membagi pembuatan file menjadi beberapa bagian agar wordlist bisa digunakan oleh cracker dengan lebih effesien dengan membagi file output(wordlist yang sudak di filter) menjadi beberapa bagian. sehingga proses bruteforce bisa menggunakan banyak thread atau worker sekaligus.

Kamu hanya perlu memasukan nama file wordlist yang ingin diproses dan memasuka berapa banyak file yang ingin dicetak sebagai output, nanti program yang akan membagi setiap bagian output file secara rata.

```
~$ g++ main-deep.cpp
~$ ./a.out
```
