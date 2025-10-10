#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include <stdexcept>

class FileReader {
private:
    std::ifstream file;
    std::string filename;

public:
    explicit FileReader(const std::string& filename) : filename(filename) {
        file.open(filename);
        if (!file.is_open()) {
            throw std::runtime_error("Failed to open file: " + filename);
        }
        std::cout << "File opened: " << filename << std::endl;
    }

    ~FileReader() {
        if (file.is_open()) {
            file.close();
            std::cout << "File closed: " << filename << std::endl;
        }
    }

    std::string readAll() {
        std::string content;
        std::string line;
        while (std::getline(file, line)) {
            content += line + "\n";
        }
        return content;
    }

    std::vector<std::string> readLines() {
        std::vector<std::string> lines;
        std::string line;
        while (std::getline(file, line)) {
            lines.push_back(line);
        }
        return lines;
    }

    bool readLine(std::string& line) {
        return static_cast<bool>(std::getline(file, line));
    }

    std::ifstream& getStream() { return file; }

    bool isOpen() const { return file.is_open(); }

    void reset() {
        file.clear();
        file.seekg(0, std::ios::beg);
    }
};

void demonstrateBasicFileReading() {
    std::cout << "\n=== Basic File Reading ===\n";

    std::ifstream file("sample.txt");
    if (!file.is_open()) {
        std::cerr << "Failed to open sample.txt\n";
        return;
    }

    std::string line;
    int line_number = 1;
    while (std::getline(file, line)) {
        std::cout << "Line " << line_number++ << ": " << line << std::endl;
    }

    file.close();
    std::cout << "File closed automatically\n";
}

void demonstrateRAIIFileHandling() {
    std::cout << "\n=== RAII File Handling ===\n";

    try {
        FileReader reader("sample.txt");
        std::cout << "File is open: " << (reader.isOpen() ? "Yes" : "No") << std::endl;

        std::string content = reader.readAll();
        std::cout << "File content (" << content.length() << " chars):\n" << content << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "FileReader object out of scope - file automatically closed\n";
}

void demonstrateSmartPointerFileHandling() {
    std::cout << "\n=== Smart Pointer File Handling ===\n";

    auto fileReader = std::make_unique<FileReader>("sample.txt");

    if (fileReader->isOpen()) {
        auto lines = fileReader->readLines();
        std::cout << "Read " << lines.size() << " lines:\n";
        for (size_t i = 0; i < lines.size(); ++i) {
            std::cout << "  [" << i+1 << "] " << lines[i] << std::endl;
        }
    }

    std::cout << "Unique_ptr going out of scope - file automatically closed\n";
}

void demonstrateFilePositionOperations() {
    std::cout << "\n=== File Position Operations ===\n";

    std::ifstream file("sample.txt");
    if (!file.is_open()) {
        std::cerr << "Failed to open sample.txt\n";
        return;
    }

    std::string firstLine;
    std::getline(file, firstLine);
    std::cout << "First line: " << firstLine << std::endl;
    std::cout << "Current position: " << file.tellg() << std::endl;

    file.seekg(0, std::ios::beg);
    std::cout << "Reset to beginning, position: " << file.tellg() << std::endl;

    file.seekg(0, std::ios::end);
    std::cout << "Seek to end, position: " << file.tellg() << std::endl;
    std::cout << "File size: " << file.tellg() << " bytes" << std::endl;

    file.close();
}

void demonstrateErrorHandling() {
    std::cout << "\n=== Error Handling ===\n";

    std::ifstream file("nonexistent.txt");

    std::cout << "File open status: " << (file.is_open() ? "Open" : "Closed") << std::endl;
    std::cout << "Fail bit: " << (file.fail() ? "Set" : "Not set") << std::endl;
    std::cout << "Bad bit: " << (file.bad() ? "Set" : "Not set") << std::endl;

    if (!file) {
        std::cout << "File stream is in error state\n";
        file.clear();
        std::cout << "Error state cleared\n";
    }
}

void demonstrateBinaryFileReading() {
    std::cout << "\n=== Binary File Reading ===\n";

    std::ifstream file("sample.txt", std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Failed to open sample.txt for binary reading\n";
        return;
    }

    file.seekg(0, std::ios::end);
    size_t fileSize = file.tellg();
    file.seekg(0, std::ios::beg);

    std::vector<char> buffer(fileSize);
    file.read(buffer.data(), fileSize);

    std::cout << "Read " << file.gcount() << " bytes in binary mode\n";
    std::cout << "Content as string: " << std::string(buffer.begin(), buffer.end()) << std::endl;

    file.close();
}

int main() {
    std::cout << "=== std::ifstream File Handle Management Demo ===\n";
    std::cout << "This demonstrates RAII principles for file handling\n";

    demonstrateBasicFileReading();
    demonstrateRAIIFileHandling();
    demonstrateSmartPointerFileHandling();
    demonstrateFilePositionOperations();
    demonstrateErrorHandling();
    demonstrateBinaryFileReading();

    std::cout << "\n=== File Handle Management Summary ===\n";
    std::cout << "• std::ifstream automatically closes files when destructor is called\n";
    std::cout << "• RAII ensures files are properly closed even when exceptions occur\n";
    std::cout << "• Smart pointers provide additional safety for file management\n";
    std::cout << "• Always check file.is_open() after attempting to open a file\n";
    std::cout << "• Use try-catch blocks for proper error handling\n";
    std::cout << "• File streams support both text and binary modes\n";
    std::cout << "• seekg/tellg allow random access to file content\n";

    return 0;
}
