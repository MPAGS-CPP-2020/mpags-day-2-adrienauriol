// Standard Library includes
#include <string>
#include <iostream>

// Function include
#include "RunCaesarCipher.hpp"

std::string runCaesarCipher(
    const std::string &inputText,
    const unsigned long &keyCaesar,
    const bool encrypt)
{
    bool debug{false};
    std::string outCaesarCipher{""};
    unsigned int indexAlphabet{999};
    int sizeInput{999};
    const std::string alphabet{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

    // Loop over the input text
    sizeInput = inputText.size();

    if (encrypt)
    {
        for (int i = 0; i < sizeInput; i++)
        {
            indexAlphabet = alphabet.find(inputText[i]);
            outCaesarCipher += alphabet[(indexAlphabet + keyCaesar) % 26];
        }
    }

    else
    {
        for (int i = 0; i < sizeInput; i++)
        {
            indexAlphabet = alphabet.find(inputText[i]);
            if (debug)
            {
                std::cout << "indexAlphabet : " << indexAlphabet << std::endl;
                std::cout << "key : " << keyCaesar << std::endl;
                std::cout << "(indexAlphabet - key) : " << (indexAlphabet - keyCaesar) << std::endl;
            }
            outCaesarCipher += alphabet[(indexAlphabet+26000 - keyCaesar +26000) % 26]; //+26000 (works with any multiple of 26) are here to ensure that (indexAlphabet-keyCaesar) stay >0 (even with huge value of keyCaesar)
        }
    }
    // outCaesarCipher = inputText;
    return outCaesarCipher;
}
