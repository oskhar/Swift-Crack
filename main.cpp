#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

void process_wordlist(const std::string& input_file, const std::string& output_file) {
    std::ifstream infile(input_file);
    if (!infile.is_open()) {
        std::cerr << "Error opening input file." << std::endl;
        return;
    }

    std::string temp_file = "temp_unique_lines.txt";
    std::ofstream temp_outfile(temp_file);
    if (!temp_outfile.is_open()) {
        std::cerr << "Error opening temporary file." << std::endl;
        return;
    }

    // Menghitung jumlah total baris untuk progress bar
    infile.seekg(0, std::ios::end);
    size_t total_size = infile.tellg();
    infile.seekg(0, std::ios::beg);

    std::string line;
    size_t processed_size = 0;
    auto unique_lines = std::make_unique<std::set<std::string>>();

    while (getline(infile, line)) {
        processed_size += line.size() + 1; // +1 untuk newline character
        if (line.size() >= 8) {
            unique_lines->insert(line);
        }

        // Update progress bar
        int progress = static_cast<int>(50 * processed_size / total_size);
        std::cout << "\rProcessing: [";
        for (int i = 0; i < progress; ++i) std::cout << "#";
        for (int i = progress; i < 50; ++i) std::cout << ".";
        std::cout << "] " << processed_size << "/" << total_size << " bytes";
        std::cout.flush();
    }
    infile.close();

    for (const auto& str : *unique_lines) {
        temp_outfile << str << '\n';
    }
    temp_outfile.close();

    // Baca baris unik dari file sementara ke dalam set untuk menghilangkan duplikasi
    std::ifstream temp_infile(temp_file);
    auto final_unique_lines = std::make_unique<std::set<std::string>>();
    while (getline(temp_infile, line)) {
        final_unique_lines->insert(line);
    }
    temp_infile.close();

    // Menulis baris unik yang sudah diurutkan ke file output
    std::ofstream outfile(output_file);
    if (!outfile.is_open()) {
        std::cerr << "Error opening output file." << std::endl;
        return;
    }
    for (const auto& str : *final_unique_lines) {
        outfile << str << '\n';
    }
    outfile.close();

    std::cout << "\nProcessing complete." << std::endl;
}

int main() {
    std::string file_name;
    std::cout << "Nama file [.txt]: ";
    std::cin >> file_name;

    process_wordlist(file_name, "output.txt");

    return 0;
}
