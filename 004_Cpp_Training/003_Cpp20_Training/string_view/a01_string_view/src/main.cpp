#include <algorithm>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

int main()
{
    std::cout << "=== C++20 std::string_view Examples ===\n\n";

    // Example 1: Basic string_view creation and usage
    std::cout << "1. Basic string_view creation:\n";
    std::string str = "Hello, World!";
    std::string_view sv = str;
    std::cout << "   Original string: \"" << str << "\"\n";
    std::cout << "   String view: \"" << sv << "\"\n";
    std::cout << "   String view size: " << sv.size() << "\n\n";

    // Example 2: string_view from string literal
    std::cout << "2. string_view from string literal:\n";
    std::string_view literal_sv = "This is a string literal";
    std::cout << "   Literal view: \"" << literal_sv << "\"\n";
    std::cout << "   First word: \"" << literal_sv.substr(0, 4) << "\"\n\n";

    // Example 3: Substring operations without copying
    std::cout << "3. Substring operations (zero-copy):\n";
    std::string long_text = "C++20 string_view is efficient and powerful";
    std::string_view text_sv = long_text;

    auto word1 = text_sv.substr(0, 5); // "C++20"
    auto word2 = text_sv.substr(6, 10); // "string_vie"
    auto word3 = text_sv.substr(21, 9); // "efficient"

    std::cout << "   Original: \"" << long_text << "\"\n";
    std::cout << "   Word 1 (0,5): \"" << word1 << "\"\n";
    std::cout << "   Word 2 (6,10): \"" << word2 << "\"\n";
    std::cout << "   Word 3 (21,9): \"" << word3 << "\"\n\n";

    // Example 4: string_view as function parameter (avoiding copies)
    std::cout << "4. string_view as function parameter:\n";
    auto print_length = [](std::string_view text) {
        std::cout << "   Text: \"" << text << "\", Length: " << text.length()
                  << "\n";
    };

    std::string temp = "Temporary string";
    print_length(temp); // From std::string
    print_length("Literal"); // From string literal
    print_length(temp.substr(0, 9)); // From substring
    std::cout << "\n";

    // Example 5: String manipulation operations
    std::cout << "5. String manipulation operations:\n";
    std::string data = "  C++20 Programming  ";
    std::string_view data_sv = data;

    // Remove leading and trailing whitespace
    auto start = data_sv.find_first_not_of(" ");
    auto end = data_sv.find_last_not_of(" ");
    auto trimmed = data_sv.substr(start, end - start + 1);

    std::cout << "   Original: \"" << data << "\"\n";
    std::cout << "   Trimmed: \"" << trimmed << "\"\n";
    std::cout << "   Contains '20': "
              << (data_sv.find("20") != std::string_view::npos ? "Yes" : "No")
              << "\n\n";

    // Example 6: string_view with STL algorithms
    std::cout << "6. string_view with STL algorithms:\n";
    std::string sentence = "The quick brown fox jumps over the lazy dog";
    std::string_view sentence_sv = sentence;

    // Count words
    size_t word_count = 1;
    for (char c : sentence_sv) {
        if (c == ' ')
            word_count++;
    }
    std::cout << "   Sentence: \"" << sentence_sv << "\"\n";
    std::cout << "   Word count: " << word_count << "\n";

    // Find all words containing 'o'
    std::vector<std::string_view> words_with_o;
    size_t start_pos = 0;
    size_t found = sentence_sv.find(' ');

    while (found != std::string_view::npos) {
        std::string_view word
            = sentence_sv.substr(start_pos, found - start_pos);
        if (word.find('o') != std::string_view::npos) {
            words_with_o.push_back(word);
        }
        start_pos = found + 1;
        found = sentence_sv.find(' ', start_pos);
    }

    // Last word
    std::string_view last_word = sentence_sv.substr(start_pos);
    if (last_word.find('o') != std::string_view::npos) {
        words_with_o.push_back(last_word);
    }

    std::cout << "   Words containing 'o': ";
    for (const auto& word : words_with_o) {
        std::cout << "\"" << word << "\" ";
    }
    std::cout << "\n\n";

    // Example 7: string_view comparison operations
    std::cout << "7. string_view comparison operations:\n";
    std::string_view sv1 = "Hello";
    std::string_view sv2 = "Hello";
    std::string_view sv3 = "World";

    std::cout << "   sv1: \"" << sv1 << "\"\n";
    std::cout << "   sv2: \"" << sv2 << "\"\n";
    std::cout << "   sv3: \"" << sv3 << "\"\n";
    std::cout << "   sv1 == sv2: " << (sv1 == sv2 ? "true" : "false") << "\n";
    std::cout << "   sv1 < sv3: " << (sv1 < sv3 ? "true" : "false") << "\n";
    std::cout << "   sv1.compare(sv3): " << sv1.compare(sv3) << "\n\n";

    // Example 8: string_view with different string encodings/parts
    std::cout << "8. Working with string_view on different string parts:\n";
    std::string csv_data = "John,25,Engineer;Jane,30,Doctor;Bob,35,Teacher";
    std::string_view csv_sv = csv_data;

    std::cout << "   CSV data: \"" << csv_sv << "\"\n";

    // Process records
    size_t record_start = 0;
    size_t record_end = csv_sv.find(';');

    while (record_end != std::string_view::npos) {
        std::string_view record
            = csv_sv.substr(record_start, record_end - record_start);
        std::cout << "   Record: \"" << record << "\"\n";

        // Extract fields
        size_t comma1 = record.find(',');
        size_t comma2 = record.find(',', comma1 + 1);

        std::string_view name = record.substr(0, comma1);
        std::string_view age = record.substr(comma1 + 1, comma2 - comma1 - 1);
        std::string_view profession = record.substr(comma2 + 1);

        std::cout << "     Name: \"" << name << "\", Age: \"" << age
                  << "\", Profession: \"" << profession << "\"\n";

        record_start = record_end + 1;
        record_end = csv_sv.find(';', record_start);
    }

    // Process last record
    std::string_view last_record = csv_sv.substr(record_start);
    std::cout << "   Last record: \"" << last_record << "\"\n\n";

    // Example 9: string_view with remove_prefix and remove_suffix
    std::cout << "9. remove_prefix and remove_suffix operations:\n";
    std::string full_path = "/home/user/documents/file.txt";
    std::string_view path_sv = full_path;

    std::cout << "   Full path: \"" << path_sv << "\"\n";

    // Remove leading slash
    if (path_sv.starts_with('/')) {
        path_sv.remove_prefix(1);
    }
    std::cout << "   After remove_prefix(1): \"" << path_sv << "\"\n";

    // Remove file extension
    if (path_sv.ends_with(".txt")) {
        path_sv.remove_suffix(4);
    }
    std::cout << "   After remove_suffix(4): \"" << path_sv << "\"\n";

    // Extract directory and filename
    size_t last_slash = path_sv.rfind('/');
    if (last_slash != std::string_view::npos) {
        std::string_view directory = path_sv.substr(0, last_slash);
        std::string_view filename = path_sv.substr(last_slash + 1);
        std::cout << "   Directory: \"" << directory << "\"\n";
        std::cout << "   Filename: \"" << filename << "\"\n";
    }
    std::cout << "\n";

    // Example 10: Performance benefits - string_view vs string copying
    std::cout << "10. Performance comparison (conceptual):\n";
    std::string large_text = "This is a very large text string that we want to "
                             "process efficiently. "
                             "Using std::string_view allows us to create "
                             "substrings without copying data. "
                             "This is especially useful when working with "
                             "large strings or when performance is critical.";

    std::string_view large_sv = large_text;

    // Create multiple "substrings" without copying
    std::string_view first_sentence = large_sv.substr(0, large_sv.find('.'));
    std::string_view second_sentence = large_sv.substr(large_sv.find('.') + 2,
        large_sv.find('.', large_sv.find('.') + 2) - large_sv.find('.') - 2);
    std::string_view word_copying
        = large_sv.substr(large_sv.find("copying"), 6);
    std::string_view word_efficiently
        = large_sv.substr(large_sv.find("efficiently"), 11);

    std::cout << "   Original text length: " << large_text.length()
              << " characters\n";
    std::cout << "   First sentence: \"" << first_sentence << "\"\n";
    std::cout << "   Second sentence: \"" << second_sentence << "\"\n";
    std::cout << "   Found word: \"" << word_copying << "\"\n";
    std::cout << "   Found word: \"" << word_efficiently << "\"\n";
    std::cout << "   Note: All substrings above are zero-copy views!\n\n";

    return 0;
}