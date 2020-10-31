// Standard Library includes
#include <iostream>
#include <string>
#include <vector>

// For std::isalpha and std::isupper
#include <cctype>

// For file streams
#include <fstream>

// Function include
#include "TransformChar.hpp"
#include "ProcessCommandLine.hpp"
#include "RunCaesarCipher.hpp"

// Main function of the mpags-cipher program
int main(int argc, char *argv[])
{
  // Convert the command-line arguments into a more easily usable form
  const std::vector<std::string> cmdLineArgs{argv, argv + argc};

  // Options that might be set by the command-line arguments
  bool helpRequested{false};
  bool versionRequested{false};
  std::string inputFile{""};
  std::string outputFile{""};
  std::string key{""};
  bool encrypt{true};

  // Processing the command line. Exit if error occurs.
  if (!processCommandLine(cmdLineArgs, helpRequested, versionRequested, inputFile, outputFile, key, encrypt))
  {
    return 1;
  }

  // Handle help, if requested
  if (helpRequested)
  {
    // Line splitting for readability
    std::cout
        << "Usage: mpags-cipher [-i <file>] [-o <file>]\n\n"
        << "Encrypts/Decrypts input alphanumeric text using classical ciphers\n\n"
        << "Available options:\n\n"
        << "  -h|--help        Print this help message and exit\n\n"
        << "  --version        Print version information\n\n"
        << "  -i FILE          Read text to be processed from FILE\n"
        << "                   Stdin will be used if not supplied\n\n"
        << "  -o FILE          Write processed text to FILE\n"
        << "                   Stdout will be used if not supplied\n\n"
        << "  -key ARG         Key used for encrypt/decrypt (default = 0)\n\n"
        << "  --encrypt        Encrypt the message (default)\n\n"
        << "  --decrypt        Decrypt the message\n\n";
    // Help requires no further action, so return from main
    // with 0 used to indicate success
    return 0;
  }

  // Handle version, if requested
  // Like help, requires no further action,
  // so return from main with zero to indicate success
  if (versionRequested)
  {
    std::cout << "0.1.0" << std::endl;
    return 0;
  }

  // Initialise variables for processing input text
  char inputChar{'x'};
  std::string inputText{""};
  std::string outputText{""};

  // Read in user input from stdin/file
  // Warn that input file option not yet implemented
  if (inputFile.empty())
  {
    // Loop over each character from user input
    // (until Return then CTRL-D (EOF) pressed)
    while (std::cin >> inputChar)
    {
      inputText += transformChar(inputChar);
    }
  }
  else
  {
    //Instantiate an instance of an ofstream type
    std::ifstream in_file{inputFile};
    bool ok_to_read{in_file.good()};
    if (ok_to_read)
    {
      while (in_file >> inputChar)
      {
        inputText += transformChar(inputChar);
      }
    }
    else
    {
      std::cerr << "[error] Failed to read the input file" << std::endl;
    }
  }

  // outputText = inputText;

  unsigned long keyCaesar{99999};
  if (!key.empty())
  {
    keyCaesar = std::stoul(key);
  }
  else
  {
    keyCaesar = 0;
  }
  
  outputText = runCaesarCipher(inputText, keyCaesar, encrypt);

  // Output the transliterated text
  // Warn that output file option not yet implemented
  if (!outputFile.empty())
  {
    std::ofstream out_file{outputFile, std::ios::app};
    bool ok_to_write{out_file.good()};
    if (ok_to_write)
    {
      out_file << outputText << std::endl;
    }
    else
    {
      std::cerr << "[error] Failed to open the output file" << std::endl;
    }
  }
  else
  {
    std::cout << outputText << std::endl;
  }

  // No requirement to return from main, but we do so for clarity
  // and for consistency with other functions
  return 0;
}
