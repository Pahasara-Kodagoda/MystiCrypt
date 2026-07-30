#pragma once
#include <string>   // std::string
#include <cctype>   // isalpha, isupper
#include <stdexcept> // std::invalid_argument

class CaesarCipher {
public:
    static std::string Encrypt(const std::string& message, int key) {
        if (key < 0 || key > 25) {
            throw std::invalid_argument("Caesar cipher key must be between 0 and 25.");
        }
        std::string encrypted = "";
        for (char ch : message) {
            if (isalpha(static_cast<unsigned char>(ch))) {
                char base = isupper(static_cast<unsigned char>(ch)) ? 'A' : 'a';
                encrypted += static_cast<char>(((ch - base + key) % 26 + 26) % 26 + base);
            }
            else {
                encrypted += ch;
            }
        }
        return encrypted;
    }



    static std::string Decrypt(const std::string& message, int key) {
        if (key < 0 || key > 25) {
            throw std::invalid_argument("Caesar cipher key must be between 0 and 25.");
        }
        std::string decrypted = "";
        for (char ch : message) {
            if (isalpha(static_cast<unsigned char>(ch))) {
                char base = isupper(static_cast<unsigned char>(ch)) ? 'A' : 'a';
                decrypted += static_cast<char>(((ch - base - key) % 26 + 26) % 26 + base);
            }
            else {
                decrypted += ch;
            }
        }
        return decrypted;
    }

};