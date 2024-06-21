import itertools

# Fungsi untuk membaca daftar kata dari file input
def read_words_from_file(filename):
    words = []
    with open(filename, 'r') as file:
        for line in file:
            words.append(line.strip())  # Menambahkan kata tanpa karakter newline
    return words

# Fungsi untuk menghasilkan kombinasi kata
def generate_passwords(words):
    passwords = []
    # Menggabungkan 2 kata atau lebih
    for r in range(2, len(words) + 1):
        for combo in itertools.combinations(words, r):
            # Menggabungkan kata-kata dalam satu string
            password = "".join(combo)
            passwords.append(password)
            # Jika ingin juga mempertimbangkan variasi dengan spasi
            passwords.append(" ".join(combo))
            # Jika ingin mempertimbangkan variasi dengan perubahan case
            for variant in itertools.permutations(combo):
                passwords.append("".join(variant))
                passwords.append(" ".join(variant))
                passwords.append("".join(variant).lower())
                passwords.append(" ".join(variant).lower())
                passwords.append("".join(variant).upper())
                passwords.append(" ".join(variant).upper())
                # Menambahkan variasi dengan capitalize huruf pertama
                capitalize_variant = " ".join(word.capitalize() for word in variant)
                passwords.append(capitalize_variant)
                passwords.append(capitalize_variant.replace(" ", ""))
    return passwords

# Memanggil fungsi untuk membaca kata-kata dari file input
input_filename = str(input("File input: "))
kata = read_words_from_file(input_filename)

# Memanggil fungsi generate_passwords untuk daftar kata yang Anda miliki
result = generate_passwords(kata)

# Menampilkan hasilnya
for password in result:
    print(password)
