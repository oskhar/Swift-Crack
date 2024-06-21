# Swift Crack

Swift Crack provides essential tools for efficiently generating and managing wordlists, specifically designed for hacking and security applications. It features Python scripts for smaller wordlists and optimized C++ programs for handling large datasets. The repository includes functionalities for splitting large wordlists and generating targeted lists based on specific keywords, enhancing efficiency in password cracking and security testing.

### Overview

This repository offers tools for generating and managing wordlists efficiently, tailored for various hacking and security applications. All functionalities are accessible through a single Python script (`main.py`) for ease of use.

### Main Tool (`main.py`)

The `main.py` script is the central hub for all wordlist management operations. It provides a user-friendly interface to choose different functionalities based on your needs:

1. **Filter Wordlist for Basic WiFi Hacking (Python)**
2. **Filter Wordlist for Advanced WiFi Hacking (C++)**
3. **Filter Wordlist with Deep Multi-Threading (C++)**
4. **Generate Wordlist with Specific Keywords (Python)**
5. **Exit**

### Features and Usage Instructions

1. **Filter Wordlist for Basic WiFi Hacking (Python)**

   Use Python's native capabilities to filter wordlists from a provided file. This approach is suitable for moderate-sized wordlists.

   To use this feature:

   ```
   ~$ python3 main.py
   ```

   Select option `[1]` from the menu and follow the instructions.

2. **Filter Wordlist for Advanced WiFi Hacking (C++)**

   When dealing with large wordlists (exceeding 1GB), switch to C++ for enhanced memory management and processing speed.

   To use this feature:

   ```
   ~$ python3 main.py
   ```

   Select option `[2]` from the menu. The program will check if the C++ source file is compiled and will compile it if necessary before execution.

3. **Filter Wordlist with Deep Multi-Threading (C++)**

   Splitting massive wordlists into smaller, manageable files enhances performance during brute-force attacks, enabling efficient multi-threading.

   To use this feature:

   ```
   ~$ python3 main.py
   ```

   Select option `[3]` from the menu. The program will check if the C++ source file is compiled and will compile it if necessary before execution.

4. **Generate Wordlist with Specific Keywords (Python)**

   Create specialized wordlists by extracting keywords relevant to specific targets, optimizing cracking efforts.

   To use this feature:

   ```
   ~$ python3 main.py
   ```

   Select option `[4]` from the menu and follow the instructions.

5. **Exit**

   Exit the program.

### Notes

- Ensure Python and C++ environments are properly configured.
- Adjust settings and filenames as per your specific requirements.
- Monitor system resources when handling large datasets for optimal performance.
