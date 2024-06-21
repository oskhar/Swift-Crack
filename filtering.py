import sys

def process_wordlist(input_file, output_file):
    print("Memulai program\n")    

    # Menggunakan set untuk menyimpan baris unik
    unique_lines = set()

    print("Memperkirakan jumlah proses yang akan dikerjakan")

    # Menghitung jumlah total baris untuk progress bar
    with open(input_file, 'r', encoding='latin1') as infile:
        total_lines = sum(1 for line in infile)

    # Membaca file dan menyaring baris yang memenuhi kriteria
    with open(input_file, 'r', encoding='latin1') as infile:
        for i, line in enumerate(infile, 1):
            line = line.strip()  # Menghapus whitespace di awal/akhir
            if len(line) >= 8:  # Memeriksa panjang baris
                unique_lines.add(line)

            # Update progress bar
            progress = int(50 * i / total_lines)
            sys.stdout.write(f'\rProcessing: [{"#" * progress}{"." * (50 - progress)}] {i}/{total_lines} lines')
            sys.stdout.flush()

    # Menulis hasil ke file output
    with open(output_file, 'w', encoding='latin1') as outfile:
        for line in sorted(unique_lines):  # Menulis dalam urutan terurut jika diinginkan
            outfile.write(line + '\n')

    print("\nProcessing complete.")

# Memasukan nama wordlist file
file_name = str(input('Nama file [.txt]: '))

# Ganti 'wordlist.txt' dengan nama file input Anda
# Ganti 'cleaned_wordlist.txt' dengan nama file output yang diinginkan
process_wordlist(file_name, 'output.txt')

