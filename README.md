# Secure List

Secure List provides essential tools for efficiently generating and managing wordlists, specifically designed for hacking and security applications. It features Python scripts for smaller wordlists and optimized C++ programs for handling large datasets. The repository includes functionalities for splitting large wordlists and generating targeted lists based on specific keywords, enhancing efficiency in password cracking and security testing.

### Overview

This repository offers tools for generating and managing wordlists efficiently, tailored for various hacking and security applications.

### Python Tool (`main.py`)

Use Python's native capabilities to generate wordlists from a provided file. This approach is suitable for moderate-sized wordlists.

### C++ Optimization (`main.cpp`)

When dealing with large wordlists (exceeding 1GB), switch to C++ for enhanced memory management and processing speed.

### Managing Large Wordlists (`main-deep.cpp`)

Splitting massive wordlists into smaller, manageable files enhances performance during brute-force attacks, enabling efficient multi-threading.

### Targeted Keyword Generation (`chiper-word.py`)

Create specialized wordlists by extracting keywords relevant to specific targets, optimizing cracking efforts.

### Usage Instructions

1. **Python Execution**

   - Run `main.py` and input your wordlist filename.

   ```
   ~$ python3 main.py
   ```

2. **C++ Compilation and Execution**

   - Compile `main.cpp` and execute it for handling large wordlists.

   ```
   ~$ g++ main.cpp
   ~$ ./a.out
   ```

3. **Splitting Wordlists**

   - Use `main-deep.cpp` to split large wordlists into multiple files for efficient processing.

   ```
   ~$ g++ main-deep.cpp
   ~$ ./a.out
   ```

4. **Generating Targeted Wordlists**
   - Utilize `chiper-word.py` to create wordlists tailored to specific targets based on associated keywords.
   ```
   ~$ python3 chiper-word.py
   ```

### Notes

- Ensure Python and C++ environments are properly configured.
- Adjust settings and filenames as per your specific requirements.
- Monitor system resources when handling large datasets for optimal performance.
