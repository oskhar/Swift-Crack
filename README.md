## Penggunaan

### Tentu saja Python

Seluruhnya hanya menggunakan libary bawaan python, jadi kamu hanya perlu menjalankan program `main.py`, dan langsung memasukan nama file wordlist milikmu untuk diproses

```
~$ python3 main.py
```

### Kenapa C++ ??

Python mungkin tidak dapat menampung file wordlist yang terlalu besar sampai bergiga giga. Saya telah mencoba melakukannya pada wordlist milik saya yang berukuran 3.7GB dan hasilnya force error. C++ mungkin bisa menjadi solusi karena dapat melakukan management memory dan resource dengan lebih mendalam

```
~$ g++ main.cpp
~$ ./a.out
```
