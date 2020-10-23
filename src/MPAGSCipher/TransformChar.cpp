// Standard Library includes
#include <string>

// Function include
#include "TransformChar.hpp"


//transliteration function
std::string transformChar(const char in_char)
{
  std::string transText{""};
  // If the character isn't alphabetic or numeric, DONT add it.
  // Our ciphers can only operate on alphabetic characters.
  // Uppercase alphabetic characters
  if (std::isalpha(in_char))
  {
    transText += std::toupper(in_char);
    return transText;
  }

  // Transliterate digits to English words
  switch (in_char)
  {
  case '0':
    transText += "ZERO";
    break;
  case '1':
    transText += "ONE";
    break;
  case '2':
    transText += "TWO";
    break;
  case '3':
    transText += "THREE";
    break;
  case '4':
    transText += "FOUR";
    break;
  case '5':
    transText += "FIVE";
    break;
  case '6':
    transText += "SIX";
    break;
  case '7':
    transText += "SEVEN";
    break;
  case '8':
    transText += "EIGHT";
    break;
  case '9':
    transText += "NINE";
    break;
  }
  return transText;
}
