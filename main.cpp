#include <iostream>
#include <fstream>
#include <unordered_set>
#include <string>

void process_wordlist(const std::string& input_file, const std::string& output_file) {
    std::ifstream infile(input_file);
    if (!infile.is_open()) {
        std::cerr << "Error opening input file." << std::endl;
        return;
    }

    std::ofstream outfile(output_file);
    if (!outfile.is_open()) {
        std::cerr << "Error opening output file." << std::endl;
        return;
    }

    // Calculate total file size for progress indication
    infile.seekg(0, std::ios::end);
    size_t total_size = infile.tellg();
    infile.seekg(0, std::ios::beg);

    std::string line;
    size_t processed_size = 0;
    std::unordered_set<std::string> unique_lines;

    while (getline(infile, line)) {
        processed_size += line.size() + 1; // +1 for newline character
        if (line.size() >= 8) {
            unique_lines.insert(line);
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

    // Write unique lines directly to the output file
    for (const auto& str : unique_lines) {
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
