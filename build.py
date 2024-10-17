import os

def read_ciphers(filename):
  ciphers = []
  with open(filename, "r") as file:
    lines = [(line.strip().split()[0]).strip().lower() for line in file.readlines() if line.strip()]
    for line in lines:
      cipher = ''.join([c.capitalize() if i != 0 else c for i, c in enumerate(line.split('-')) if c])
      ciphers.append(cipher)
  return ciphers

def create_script(
  ciphers, ext, br, exe_ext = None, extra = None,
  runner_prefix = "./", main_script = "main", test_file = "test"
  ):
  with open(f"{main_script}.{ext}", "w") as file:
    if extra: file.write(f"{extra}\n")

    file.write(f"g++ {test_file}.cpp {br}\n")
    file.writelines([f"  ciphers/{cipher}.cpp {br}\n" for cipher in ciphers])

    test_file_with_ext = f"{test_file}{f'.{exe_ext}' if exe_ext else ''}"
    file.write(f"  -o {test_file_with_ext}\n\n{runner_prefix}{test_file_with_ext}\n")

def update_includes(ciphers, file_path):
  header_files = [f'#include "ciphers/{cipher}.h"' for cipher in ciphers]
  
  with open(file_path, 'w') as cpp_file:
    cpp_file.writelines([include + '\n' for include in header_files])

def main():
  # Read the ciphers from the file
  ciphers = read_ciphers("ciphers.txt")

  # Create build-n-run script files
  create_script(ciphers, "ps1", "`")
  create_script(ciphers, "bat", "^", "exe", runner_prefix="")
  create_script(ciphers, "sh", "\\", extra = ("#" "!/bin/bash"))
 
  # Update test.cpp with necessary includes
  update_includes(ciphers, "ciphers.h")

if __name__ == "__main__":
  os.chdir(os.path.dirname(os.path.abspath(__file__)))
  main()
