import os

main_script = "main"
test_file = "test"

# Function to read cipher list from file
def read_ciphers(filename):
  ciphers = []
  with open(filename, "r") as file:
    ciphers = [(line.split()[0]).strip().lower() for line in file.readlines() if line.strip()]
  return ciphers

def create_sh_script(ciphers):
  with open(f"{main_script}.sh", "w") as sh_file:
    sh_file.write("#!/bin/bash\n")
    sh_file.write(f"g++ {test_file}.cpp \\\n")
    for cipher in ciphers:
      sh_file.write(f"  ciphers/{cipher}.cpp \\\n")
    sh_file.write(f"  -o {test_file}\n")
    sh_file.write(f"\n./{test_file}\n")

def create_bat_script(ciphers):
  with open(f"{main_script}.bat", "w") as bat_file:
    bat_file.write(f"g++ {test_file}.cpp ^\n")
    for cipher in ciphers:
      bat_file.write(f"  ciphers/{cipher}.cpp ^\n")
    bat_file.write(f"  -o {test_file}.exe\n")
    bat_file.write(f"\n{test_file}.exe\n")

def create_ps1_script(ciphers):
  with open(f"{main_script}.ps1", "w") as ps1_file:
    ps1_file.write(f"g++ {test_file}.cpp `\n")
    for cipher in ciphers:
      ps1_file.write(f"  ciphers/{cipher}.cpp `\n")
    ps1_file.write(f"  -o {test_file}\n")
    ps1_file.write(f"\n./{test_file}\n")

# Function to add missing includes and sort them
def update_includes(ciphers, file_path):
  header_files = [f'#include "ciphers/{cipher}.h"' for cipher in ciphers]

  # Read the original file contents
  with open(file_path, 'r') as cpp_file:
    lines = cpp_file.readlines()

  # Write the updated file with sorted includes
  with open(file_path, 'w') as cpp_file:
    cpp_file.writelines([include + '\n' for include in header_files])
    cpp_file.write('\n')
    
    for line in lines:
      # Skip over the existing includes
      if line.startswith('#include "') and line.endswith('.h"\n'):
        continue
      cpp_file.write(line)

def main():
  # read the ciphers from the file
  ciphers = read_ciphers("ciphers.txt")

  # create the ps1, bat and sh script files
  create_ps1_script(ciphers)
  create_bat_script(ciphers)
  create_sh_script(ciphers)
 
  # update test.cpp with necessary includes
  update_includes(ciphers, 'test.cpp')


if __name__ == "__main__":
  os.chdir(os.path.dirname(os.path.abspath(__file__)))
  main()
