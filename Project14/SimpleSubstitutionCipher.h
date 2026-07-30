#pragma once
#include <string>
#include <unordered_map>
#include <cctype>

class SimpleSubstitutionCipher {
public:
    // key: 26-letter string
    static std::string Encrypt(const std::string& plaintext, const std::string& key) {
        if (key.length() != 26) return plaintext;
        std::string ciphertext;
        for (char c : plaintext) {
            if (std::isupper(c)) {
                ciphertext += key[c - 'A'];
            }
            else if (std::islower(c)) {
                ciphertext += std::tolower(key[c - 'a']);
            }
            else {
                ciphertext += c;
            }
        }
        return ciphertext;
    }

    static std::string Decrypt(const std::string& ciphertext, const std::string& key) {
        if (key.length() != 26) return ciphertext;
        // Build reverse mapping
        std::unordered_map<char, char> upperMap, lowerMap;
        for (int i = 0; i < 26; ++i) {
            upperMap[std::toupper(key[i])] = 'A' + i;
            lowerMap[std::tolower(key[i])] = 'a' + i;
        }
        std::string plaintext;
        for (char c : ciphertext) {
            if (std::isupper(c)) {
                auto it = upperMap.find(c);
                plaintext += (it != upperMap.end()) ? it->second : c;
            }
            else if (std::islower(c)) {
                auto it = lowerMap.find(c);
                plaintext += (it != lowerMap.end()) ? it->second : c;
            }
            else {
                plaintext += c;
            }
        }
        return plaintext;
    }
};