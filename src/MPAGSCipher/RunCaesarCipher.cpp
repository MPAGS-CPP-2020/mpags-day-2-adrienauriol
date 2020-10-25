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
            std::cout << "indexAlphabet : " << indexAlphabet << std::endl;
            std::cout << "key : " << keyCaesar << std::endl;
            std::cout << "(indexAlphabet - key) : " << (indexAlphabet - keyCaesar) << std::endl;
            outCaesarCipher += alphabet[(indexAlphabet - keyCaesar) % 26];
        }
    }
    // outCaesarCipher = inputText;
    return outCaesarCipher;
}
