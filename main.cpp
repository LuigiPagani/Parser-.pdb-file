#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>


struct Atom {
    std::string record_name;
    int serial_number;
    std::string atom_name;
    char alt_loc;
    std::string residue_name;
    char chain_id;
    int residue_sequence_number;
    char insertion_code;
    float x;
    float y;
    float z;
    float occupancy;
    float temp_factor;
    std::string element_symbol;
};

struct Hetatm {
    std::string record_name;
    int serial_number;
    std::string hetatm_name;
    char alt_loc;
    std::string residue_name;
    char chain_id;
    int residue_sequence_number;
    char insertion_code;
    float x;
    float y;
    float z;
    float occupancy;
    float temp_factor;
    std::string element_symbol;
};

struct Cryst1{
    float a;
    float b;
    float c;
    float alpha;
    float beta;
    float gamma;
};

struct Protein {
    std::string name;
    Cryst1 cryst1;
    std::vector<Atom> atoms;
    std::vector<Hetatm> hetatms;
};

int main() {

    std::ifstream protein_file("test.pdb");
    std::string line;
    Protein protein;

    if(protein_file.is_open()) {

        while (std::getline(protein_file, line)) {

            if (line.find("CRYST1") != std::string::npos) {
                sscanf(line.c_str(), "%*s %f %f %f %f %f %f", &protein.cryst1.a, &protein.cryst1.b, &protein.cryst1.c,
                       &protein.cryst1.alpha, &protein.cryst1.beta, &protein.cryst1.gamma);
            }

            if (line.substr(0, 4) == "ATOM" || line.substr(0, 6) == "HETATM") {
                Atom atom;

                atom.record_name = line.substr(0, 6);
                atom.serial_number = std::stoi(line.substr(6, 5));
                atom.atom_name = line.substr(12, 4);
                atom.alt_loc = line[16];
                atom.residue_name = line.substr(17, 3);
                atom.chain_id = line[21];
                atom.residue_sequence_number = std::stoi(line.substr(22, 4));
                atom.insertion_code = line[26];
                atom.x = std::stod(line.substr(30, 8));
                atom.y = std::stod(line.substr(38, 8));
                atom.z = std::stod(line.substr(46, 8));
                atom.occupancy = std::stod(line.substr(54, 6));
                atom.temp_factor = std::stod(line.substr(60, 6));
                atom.element_symbol = line.substr(76, 2);
                protein.atoms.push_back(atom);
            }
            if (line.substr(0, 6) == "HETATM") {
                Hetatm hetatm;

                hetatm.record_name = line.substr(0, 6);
                hetatm.serial_number = std::stoi(line.substr(6, 5));
                hetatm.hetatm_name = line.substr(12, 4);
                hetatm.alt_loc = line[16];
                hetatm.residue_name = line.substr(17, 3);
                hetatm.chain_id = line[21];
                hetatm.residue_sequence_number = std::stoi(line.substr(22, 4));
                hetatm.insertion_code = line[26];
                hetatm.x = std::stod(line.substr(30, 8));
                hetatm.y = std::stod(line.substr(38, 8));
                hetatm.z = std::stod(line.substr(46, 8));
                hetatm.occupancy = std::stod(line.substr(54, 6));
                hetatm.temp_factor = std::stod(line.substr(60, 6));
                hetatm.element_symbol = line.substr(76, 2);
                protein.hetatms.push_back(hetatm);
            }

        }
    }else{
        std::cout << "Unable to open file";
    }

    printf("CRYST1:%f %f %f %f %f %f \n", protein.cryst1.a,protein.cryst1.b,protein.cryst1.c,protein.cryst1.alpha,protein.cryst1.beta,protein.cryst1.gamma);

    for (const auto& atom : protein.atoms) {
        printf("%d %s %s %c %d %f %f %f %f %f \n" , atom.serial_number,atom.atom_name.c_str(),atom.residue_name.c_str(),atom.chain_id,atom.residue_sequence_number,atom.insertion_code,atom.x,atom.y,atom.z,atom.occupancy,atom.temp_factor);
    }

    for (const auto& hetatm : protein.hetatms) {
        printf("%d %s %s %c %d %f %f %f %f %f \n" , hetatm.serial_number,hetatm.hetatm_name.c_str(),hetatm.residue_name.c_str(),hetatm.chain_id,hetatm.residue_sequence_number,hetatm.insertion_code,hetatm.x,hetatm.y,hetatm.z,hetatm.occupancy,hetatm.temp_factor);
    }
    
    return 0;
}

