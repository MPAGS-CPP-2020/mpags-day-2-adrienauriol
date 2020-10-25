#ifndef MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
#define MPAGSCIPHER_PROCESSCOMMANDLINE_HPP

#include <string>
#include <vector>
#include <iostream>

//process command line function
bool processCommandLine(
    const std::vector<std::string> &cmdLineArgs,
    bool &helpRequested,
    bool &versionRequested,
    std::string &inputFile,
    std::string &outputFile,
    std::string &key,
    bool &encrypt);

#endif //MPAGSCIPHER_PROCESSCOMMANDLINE_HPP