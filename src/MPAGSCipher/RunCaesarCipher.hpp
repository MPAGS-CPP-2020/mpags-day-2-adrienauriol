#ifndef MPAGSCIPHER_RUNCAESARCIPHER_HPP
#define MPAGSCIPHER_RUNCAESARCIPHER_HPP

#include <string>

//Caesar cipher implementation
std::string runCaesarCipher(
    const std::string &inputText,
    const unsigned long &keyCaesar,
    const bool encrypt);

#endif //MPAGSCIPHER_RUNCAESARCIPHER_HPP