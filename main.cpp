#include <iostream>
#include <fstream>
#include <bitset>

int main() {
    std::ifstream file("yourfile.txt");  // Open text file
    std::ofstream write("writefile.bin", std::ios::binary);  // Open binary file

    if (file.is_open() && write.is_open()) {  // Ensure both files are open
        std::string line;
        while (getline(file, line)) {
            std::cout << "Text: " << line << std::endl;
            std::cout << "Binary: " << std::endl;
            write << std::endl;

            for (char c : line) {
                std::bitset<8> binary(c);  // Convert char to 8-bit binary
                std::cout << binary << " ";
                write << binary << " ";  // Write to file
            	//write.write(reinterpret_cast<const char*>(&c), sizeof(c));
	    }
            std::cout << std::endl;
        }
        file.close();
        write.close();
    } else {
        std::cout << "File is not here bro" << std::endl;
    }

    return 0;
}

