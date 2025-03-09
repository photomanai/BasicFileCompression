#include <iostream>
#include <fstream>
#include <bitset>

std::ifstream file("yourfile.txt");  // Open text file
std::ofstream write("writefile.bin", std::ios::binary);  // Open binary file


void compression(std::string binary) {
    std::string zip_line;
    int count = 1;  

    for (size_t i = 0; i < binary.size() - 1; ++i) {
        if (binary[i] == binary[i + 1]) {
            count++;  
        } else {

			std::cout << count << " " << binary[i] << std::endl;
            
            zip_line += std::to_string(count) + binary[i];
            count = 1;  
        }
    }

    // For the last group of bits (because the loop stops before the last bit)
    zip_line += std::to_string(count) + binary[binary.size() - 1];

    std::cout << "Compressed: " << zip_line << std::endl;
    write<<zip_line;
}

int main() {
	std::string bin_line;
	std::bitset<8> binary(0);
	
    if (file.is_open() && write.is_open()) {  // Ensure both files are open
        std::string line;
        while (getline(file, line)) {
            std::cout << "Text: " << line << std::endl;
            std::cout << "Binary: " << std::endl;

            for (char c : line) {
                std::bitset<8> binary(c);  // Convert char to 8-bit binary				
                 bin_line += binary.to_string(); 
            	//write.write(reinterpret_cast<const char*>(&c), sizeof(c));
	    	}
	    	compression(bin_line);
	    	
	    	write << std::endl;
	    	
            std::cout << std::endl;
        }
        file.close();
        write.close();
    } else {
        std::cout << "File is not here bro" << std::endl;
    }

    return 0;
}

