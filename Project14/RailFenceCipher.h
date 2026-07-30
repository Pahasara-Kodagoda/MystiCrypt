#pragma once
using namespace System;

public ref class RailFenceCipher
{
public:
    // Encrypt with 2 rails
    static String^ Encrypt(String^ input)
    {
        if (String::IsNullOrEmpty(input)) return "";

        System::Text::StringBuilder^ rail1 = gcnew System::Text::StringBuilder();
        System::Text::StringBuilder^ rail2 = gcnew System::Text::StringBuilder();

        // Put letters alternatively in two rails
        for (int i = 0; i < input->Length; i++)
        {
            if (i % 2 == 0)
                rail1->Append(input[i]);
            else
                rail2->Append(input[i]);
        }

        return rail1->ToString() + rail2->ToString();
    }

    // Decrypt with 2 rails
    static String^ Decrypt(String^ input)
    {
        if (String::IsNullOrEmpty(input)) return "";

        int half = input->Length / 2;
        if (input->Length % 2 != 0) half++;

        String^ rail1 = input->Substring(0, half);
        String^ rail2 = input->Substring(half);

        System::Text::StringBuilder^ result = gcnew System::Text::StringBuilder();

        int i = 0, j = 0;
        for (int k = 0; k < input->Length; k++)
        {
            if (k % 2 == 0 && i < rail1->Length)
                result->Append(rail1[i++]);
            else if (j < rail2->Length)
                result->Append(rail2[j++]);
        }

        return result->ToString();
    }
};
