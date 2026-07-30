#pragma once
#include <string>

class SimpleXORCipher {
public:
    // Encrypts or decrypts the input using a numeric or single-character key
    static std::string Encrypt(const std::string& input, char key) {
        std::string output = input;
        for (size_t i = 0; i < output.size(); ++i) {
            output[i] ^= key;
        }
        return output;
    }

    // Overload for numeric key
    static std::string Decrypt(const std::string& input, int key) {
        return Encrypt(input, static_cast<char>(key));
    }
};