#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void basicFileWriting() {
    std::cout << "=== Basic File Writing ===" << std::endl;

    // RAII: File automatically closed when ofstream goes out of scope
    std::ofstream outFile("example.txt");

    if (!outFile) {
        std::cerr << "Error: Could not open file for writing." << std::endl;
        return;
    }

    outFile << "Hello, World!" << std::endl;
    outFile << "This is a C++ file writing example." << std::endl;
    outFile << "Using std::ofstream for automatic resource management." << std::endl;

    // File automatically closed here
}

void appendToFile() {
    std::cout << "\n=== Appending to File ===" << std::endl;

    // Open file in append mode
    std::ofstream outFile("example.txt", std::ios::app);

    if (!outFile) {
        std::cerr << "Error: Could not open file for appending." << std::endl;
        return;
    }

    outFile << "This line was appended." << std::endl;
    outFile << "Appending mode preserves existing content." << std::endl;
}

void writeBinaryData() {
    std::cout << "\n=== Binary Data Writing ===" << std::endl;

    std::ofstream outFile("data.bin", std::ios::binary);

    if (!outFile) {
        std::cerr << "Error: Could not open binary file for writing." << std::endl;
        return;
    }

    // Write some binary data
    int numbers[] = {1, 2, 3, 4, 5};
    outFile.write(reinterpret_cast<char*>(numbers), sizeof(numbers));

    // Write a string as binary data
    std::string text = "Binary data example";
    outFile.write(text.c_str(), text.length());
}

void safeFileWritingWithExceptionHandling() {
    std::cout << "\n=== Safe File Writing with Exception Handling ===" << std::endl;

    try {
        std::ofstream outFile("safe_example.txt");

        // Enable exceptions for better error handling
        outFile.exceptions(std::ofstream::failbit | std::ofstream::badbit);

        outFile << "This file is written with exception safety." << std::endl;
        outFile << "If any error occurs, an exception will be thrown." << std::endl;

        // Simulate a potential error (commented out to avoid actual error)
        // throw std::runtime_error("Simulated error during file writing");

    } catch (const std::ofstream::failure& e) {
        std::cerr << "File operation failed: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "General error: " << e.what() << std::endl;
    }
}

void writeStructuredData() {
    std::cout << "\n=== Writing Structured Data ===" << std::endl;

    struct Person {
        std::string name;
        int age;
        double salary;
    };

    std::vector<Person> people = {
        {"Alice", 30, 50000.0},
        {"Bob", 25, 45000.0},
        {"Charlie", 35, 60000.0}
    };

    std::ofstream outFile("people.csv");

    if (!outFile) {
        std::cerr << "Error: Could not open CSV file for writing." << std::endl;
        return;
    }

    // Write CSV header
    outFile << "Name,Age,Salary" << std::endl;

    // Write structured data
    for (const auto& person : people) {
        outFile << person.name << ","
                << person.age << ","
                << person.salary << std::endl;
    }
}

void demonstrateFileManipulation() {
    std::cout << "\n=== File Manipulation Operations ===" << std::endl;

    std::ofstream outFile("operations.txt");

    if (!outFile) {
        std::cerr << "Error: Could not open file for operations." << std::endl;
        return;
    }

    // Get current position
    std::streampos pos = outFile.tellp();
    std::cout << "Initial position: " << pos << std::endl;

    outFile << "First line of text" << std::endl;

    pos = outFile.tellp();
    std::cout << "Position after first line: " << pos << std::endl;

    // Flush buffer to ensure data is written
    outFile.flush();
    std::cout << "Buffer flushed to disk" << std::endl;

    outFile << "Second line of text" << std::endl;

    // Check if file is in good state
    if (outFile.good()) {
        std::cout << "File stream is in good state" << std::endl;
    }
}

int main() {
    std::cout << "std::ofstream - File Handle Management Examples" << std::endl;
    std::cout << "=============================================" << std::endl;

    basicFileWriting();
    appendToFile();
    writeBinaryData();
    safeFileWritingWithExceptionHandling();
    writeStructuredData();
    demonstrateFileManipulation();

    std::cout << "\n=== Summary ===" << std::endl;
    std::cout << "std::ofstream provides RAII-based file handle management:" << std::endl;
    std::cout << "- Automatic file closing when object goes out of scope" << std::endl;
    std::cout << "- Exception safety when properly configured" << std::endl;
    std::cout << "- Support for text and binary modes" << std::endl;
    std::cout << "- Various opening modes (write, append, binary)" << std::endl;

    return 0;
}
