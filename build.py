import os

main_script = "main"
test_file = "test"

# Function to read cipher list from file
def read_ciphers(filename):
  ciphers = []
  with open(filename, "r") as file:
    ciphers = [(line.split()[0]).strip().lower().replace('-', '') for line in file.readlines() if line.strip()]
  return ciphers

def create_script(ciphers, ext, br, exe_ext = None, extra = None, runner_prefix = "./"):
  with open(f"{main_script}.{ext}", "w") as file:
    if extra: file.write(f"{extra}\n")

    file.write(f"g++ {test_file}.cpp {br}\n")
    file.writelines([f"  ciphers/{cipher}.cpp {br}\n" for cipher in ciphers])

    test_file_with_ext = f"{test_file}{f'.{exe_ext}' if exe_ext else ''}"
    file.write(f"  -o {test_file_with_ext}\n\n{runner_prefix}{test_file_with_ext}\n")

# Function to add includes
def update_includes(ciphers, file_path):
  header_files = [f'#include "ciphers/{cipher}.h"' for cipher in ciphers]

  # Read the original file contents
  with open(file_path, 'r') as cpp_file:
    lines = cpp_file.readlines()

  # Write the updated file
  with open(file_path, 'w') as cpp_file:
    # Add all the cipher includes
    cpp_file.writelines([include + '\n' for include in header_files])
    
    for line in lines:
      # Skip over the existing includes '**.h' files
      if not (line.startswith('#include "') and line.endswith('.h"\n')):
        cpp_file.write(line)

def main():
  # read the ciphers from the file
  ciphers = read_ciphers("ciphers.txt")

  create_script(ciphers, "ps1", "`")
  create_script(ciphers, "bat", "^", "exe", runner_prefix="")
  create_script(ciphers, "sh", "\\", extra = ("#" "!/bin/bash"))
 
  # update test.cpp with necessary includes
  update_includes(ciphers, 'test.cpp')


if __name__ == "__main__":
  os.chdir(os.path.dirname(os.path.abspath(__file__)))
  main()
