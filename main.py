def process_wordlist(input_file, output_file):
    # Menggunakan set untuk menyimpan baris unik
    unique_lines = set()

    # Membaca file dan menyaring baris yang memenuhi kriteria
    with open(input_file, 'r') as infile:
        for line in infile:
            line = line.strip()  # Menghapus whitespace di awal/akhir
            if len(line) >= 8:  # Memeriksa panjang baris
                unique_lines.add(line)

    # Menulis hasil ke file output
    with open(output_file, 'w') as outfile:
        for line in sorted(unique_lines):  # Menulis dalam urutan terurut jika diinginkan
            outfile.write(line + '\n')

# Memasukan nama wordlist file
file_name = str(input('Nama file: '))

# Ganti 'wordlist.txt' dengan nama file input Anda
# Ganti 'cleaned_wordlist.txt' dengan nama file output yang diinginkan
process_wordlist(file_name+'.txt', 'cleaned_'+file_name+'.txt')
