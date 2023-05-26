# PDB File Parser

This code is a simple PDB file parser written in C++. It reads a PDB file (`test.pdb`) and extracts the information about atoms and hetatoms present in the file. The parsed information is stored in a data structure called `Protein` which contains the crystallographic information, a vector of `Atom` structures, and a vector of `Hetatm` structures.

## Prerequisites

To run this code, you need the following:

- C++ compiler that supports C++11 or later.
- A PDB file named `test.pdb` in the same directory as the source code.

## Usage

1. Place the source code in a file named `main.cpp`.
2. Put the PDB file you want to parse in the same directory and name it `test.pdb`.
3. Compile the code using a C++ compiler.
4. Execute the compiled binary.

## Code Explanation

1. The code includes the necessary C++ libraries for file input/output, string manipulation, and vectors.
2. Several data structures are defined to represent the different components of the PDB file: `Atom`, `Hetatm`, `Cryst1`, and `Protein`.
3. The `main()` function is the entry point of the program.
4. It opens the PDB file using an input file stream (`protein_file`).
5. If the file is successfully opened, it starts reading the file line by line.
6. It uses string manipulation functions and `substr` to extract the relevant information from each line.
7. The extracted information is stored in the appropriate data structures (`Atom` or `Hetatm`) and added to the corresponding vectors in the `Protein` structure.
8. If the line contains the "CRYST1" record, the crystallographic information is extracted and stored in the `Cryst1` structure within the `Protein` structure.
9. Finally, the code prints the crystallographic information, followed by the information about each atom and hetatom, using `printf` statements.
10. If the file cannot be opened, an error message is displayed.

## Limitations

- This code assumes that the PDB file follows the standard format and does not handle all possible edge cases. It may not work correctly with non-standard or modified PDB files.
- The code does not perform any validation or error checking on the data read from the file. It assumes that the data is well-formed and does not contain any inconsistencies.
- The code uses C-style input/output functions (`sscanf` and `printf`). For more robust and modern C++ code, it is recommended to use C++-style alternatives (`std::istringstream` and `std::cout`).

Please note that this is a basic implementation and may need to be extended or modified for more complex scenarios or specific requirements.
