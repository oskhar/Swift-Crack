import os
import subprocess
import platform

def run_python_script(script_name):
    try:
        subprocess.run(['python3', script_name], check=True)
    except subprocess.CalledProcessError as e:
        print(f"Error running {script_name}: {e}")

def run_cpp_program(source_file, output_file):
    if platform.system() == "Windows":
        output_file += ".exe"

    if not os.path.exists(output_file):
        print(f"Compiling {source_file}...")
        try:
            subprocess.run(['g++', source_file, '-o', output_file], check=True)
        except subprocess.CalledProcessError as e:
            print(f"Error compiling {source_file}: {e}")
            return
    try:
        subprocess.run([f"./{output_file}"], check=True)
    except subprocess.CalledProcessError as e:
        print(f"Error running {output_file}: {e}")

def main():
    while True:
        print("\nSwift Crack Menu:")
        print("[1] Filter Wordlist for Basic WiFi Hacking (Python)")
        print("[2] Filter Wordlist for Advanced WiFi Hacking (C++)")
        print("[3] Filter Wordlist with Deep Multi-Threading (C++)")
        print("[4] Generate Wordlist with Specific Keywords (Python)")
        print("[5] Exit")
        
        choice = input("Enter your choice: ")

        if choice == '1':
            run_python_script('filtering.py')
        elif choice == '2':
            run_cpp_program('filtering.cpp', 'filtering')
        elif choice == '3':
            run_cpp_program('deep-filtering.cpp', 'deep-filtering')
        elif choice == '4':
            run_python_script('chiper-word.py')
        elif choice == '5':
            print("Exiting the program. Goodbye!")
            break
        else:
            print("Invalid choice. Please enter a number between 1 and 5.")

if __name__ == "__main__":
    main()