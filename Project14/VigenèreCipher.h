#pragma once
#include <string>
#include <cctype>

class VigenereCipher {
public:
    // Encrypts the plaintext using the provided key
    static std::string Encrypt(const std::string& plaintext, const std::string& key) {
        std::string ciphertext;
        size_t keyLen = key.length();
        if (keyLen == 0) return plaintext;

        for (size_t i = 0, j = 0; i < plaintext.length(); ++i) {
            char c = plaintext[i];
            if (std::isalpha(c)) {
                char base = std::isupper(c) ? 'A' : 'a';
                char k = std::toupper(key[j % keyLen]) - 'A';
                ciphertext += static_cast<char>(base + (c - base + k) % 26);
                ++j;
            }
            else {
                ciphertext += c;
            }
        }
        return ciphertext;
    }

    // Decrypts the ciphertext using the provided key
    static std::string Decrypt(const std::string& ciphertext, const std::string& key) {
        std::string plaintext;
        size_t keyLen = key.length();
        if (keyLen == 0) return ciphertext;

        for (size_t i = 0, j = 0; i < ciphertext.length(); ++i) {
            char c = ciphertext[i];
            if (std::isalpha(c)) {
                char base = std::isupper(c) ? 'A' : 'a';
                char k = std::toupper(key[j % keyLen]) - 'A';
                plaintext += static_cast<char>(base + (26 + c - base - k) % 26);
                ++j;
            }
            else {
                plaintext += c;
            }
        }
        return plaintext;
    }
};