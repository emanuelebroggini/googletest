#include <iostream>
#include <fstream>
#include <string>
#include "./string_functions.cc" // Include the file containing the ToUpperCase() function

int main(int argc, char* argv[]) {
    // Check if the correct number of command-line arguments is provided
    if (argc != 3) {
        std::cerr << "Usage: ./main.exe <inputFilePath> <outputFilePath>" << std::endl;
        return 1;
    }

    // Extract the input and output file paths from the command-line arguments
    std::string inputFilePath = argv[1];
    std::string outputFilePath = argv[2];

    // Open the input file
    std::ifstream inputFile(inputFilePath);
    if (!inputFile) {
        std::cerr << "Failed to open the input file." << std::endl;
        return 2;
    }

    // Open the output file
    std::ofstream outputFile(outputFilePath);
    if (!outputFile) {
        std::cerr << "Failed to open the output file." << std::endl;
        return 3;
    }

    std::string line;
    while (std::getline(inputFile, line)) {

        // Write the uppercase data to the file
        outputFile << ToUpperCase(line) << std::endl;
    }

    // Close the input and output files
    inputFile.close();
    outputFile.close();

    std::cout << "Output file generated successfully." << std::endl;

    return 0;
}
