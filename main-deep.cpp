#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

void process_wordlist(const std::string& input_file, int pembagian_file) {
    std::ifstream infile(input_file);
    if (!infile.is_open()) {
        std::cerr << "Error opening input file." << std::endl;
        return;
    }

    std::string line;
    auto unique_lines = std::make_unique<std::set<std::string>>();

    // Baca dan simpan baris unik
    while (getline(infile, line)) {
        if (line.size() >= 8) {
            unique_lines->insert(line);
        }
    }
    infile.close();

    // Konversi set ke vektor untuk kemudahan pengurutan dan pembagian
    std::vector<std::string> sorted_lines(unique_lines->begin(), unique_lines->end());

    // Hitung jumlah baris per file
    size_t total_lines = sorted_lines.size();
    size_t lines_per_file = (total_lines + pembagian_file - 1) / pembagian_file; // Pembulatan ke atas

    for (int i = 0; i < pembagian_file; ++i) {
        // Buat nama file output
        std::string output_file = "output_" + std::to_string(i + 1) + ".txt";
        std::ofstream outfile(output_file);
        if (!outfile.is_open()) {
            std::cerr << "Error opening output file " << output_file << std::endl;
            return;
        }

        // Tulis baris ke file
        size_t start = i * lines_per_file;
        size_t end = std::min(start + lines_per_file, total_lines);
        for (size_t j = start; j < end; ++j) {
            outfile << sorted_lines[j] << '\n';
        }
        outfile.close();
    }

    std::cout << "Processing complete. Total files created: " << pembagian_file << std::endl;
}

int main() {
    std::string file_name;
    int pembagian_file;

    std::cout << "Nama file [.txt]: ";
    std::cin >> file_name;
    std::cout << "Pembagian file: ";
    std::cin >> pembagian_file;

    process_wordlist(file_name, pembagian_file);

    return 0;
}
