#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

class ColumnarTranspositionCipher {
public:
    // Encrypts plaintext using a columnar transposition with the given key
    static std::string Encrypt(const std::string& plaintext, const std::string& key) {
        if (key.empty()) return plaintext;

        // Remove spaces from key and create key order
        std::string cleanKey;
        for (char c : key) {
            if (!std::isspace(static_cast<unsigned char>(c)))
                cleanKey += c;
        }
        size_t cols = cleanKey.length();
        size_t rows = (plaintext.length() + cols - 1) / cols;

        // Fill the matrix row-wise
        std::vector<std::string> matrix(rows, std::string(cols, ' '));
        size_t idx = 0;
        for (size_t r = 0; r < rows && idx < plaintext.length(); ++r) {
            for (size_t c = 0; c < cols && idx < plaintext.length(); ++c) {
                matrix[r][c] = plaintext[idx++];
            }
        }

        // Create a vector of key indices for sorting
        std::vector<std::pair<char, size_t>> keyOrder;
        for (size_t i = 0; i < cols; ++i)
            keyOrder.emplace_back(cleanKey[i], i);
        std::sort(keyOrder.begin(), keyOrder.end());

        // Read columns in key order
        std::string ciphertext;
        for (const auto& pair : keyOrder) {
            size_t col = pair.second;
            for (size_t row = 0; row < rows; ++row) {
                if (matrix[row][col] != ' ')
                    ciphertext += matrix[row][col];
            }
        }
        return ciphertext;
    }

    // Decrypts ciphertext using a columnar transposition with the given key
    static std::string Decrypt(const std::string& ciphertext, const std::string& key) {
        if (key.empty()) return ciphertext;

        std::string cleanKey;
        for (char c : key) {
            if (!std::isspace(static_cast<unsigned char>(c)))
                cleanKey += c;
        }
        size_t cols = cleanKey.length();
        size_t rows = (ciphertext.length() + cols - 1) / cols;
        size_t total = rows * cols;
        size_t shortCols = cols - (total - ciphertext.length());

        // Create a vector of key indices for sorting
        std::vector<std::pair<char, size_t>> keyOrder;
        for (size_t i = 0; i < cols; ++i)
            keyOrder.emplace_back(cleanKey[i], i);
        std::vector<size_t> colOrder(cols);
        std::sort(keyOrder.begin(), keyOrder.end());
        for (size_t i = 0; i < cols; ++i)
            colOrder[keyOrder[i].second] = i;

        // Prepare the matrix
        std::vector<std::string> matrix(rows, std::string(cols, ' '));
        size_t idx = 0;
        for (size_t k = 0; k < cols; ++k) {
            size_t col = keyOrder[k].second;
            size_t thisColRows = (col < shortCols) ? rows : (rows - 1);
            for (size_t r = 0; r < thisColRows && idx < ciphertext.length(); ++r) {
                matrix[r][col] = ciphertext[idx++];
            }
        }

        // Read row-wise
        std::string plaintext;
        for (size_t r = 0; r < rows; ++r) {
            for (size_t c = 0; c < cols; ++c) {
                if (matrix[r][c] != ' ')
                    plaintext += matrix[r][c];
            }
        }
        return plaintext;
    }
};