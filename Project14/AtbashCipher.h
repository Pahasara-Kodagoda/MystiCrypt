#pragma once
#include <string>
#include <cctype>

class AtbashCipher {
public:
    static std::string Encrypt(const std::string& message) {
        std::string result;
        for (char ch : message) {
            if (std::isupper(static_cast<unsigned char>(ch))) {
                result += 'Z' - (ch - 'A');
            }
            else if (std::islower(static_cast<unsigned char>(ch))) {
                result += 'z' - (ch - 'a');
            }
            else {
                result += ch;
            }
        }
        return result;
    }

    static std::string Decrypt(const std::string& message) {
        // Atbash is symmetric: encryption and decryption are the same
        return Encrypt(message);
    }
};