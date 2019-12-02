//
// Created by john on 12/1/19.
//

#ifndef CODEWILLINGQUESTIONS_TEXTPARSER_H
#define CODEWILLINGQUESTIONS_TEXTPARSER_H

#include <fstream>
#include <string>

using std::string;

#include <exception>

using std::exception;

#include <iostream>

#include <sstream>
using std::stringstream;
#include <unordered_map>
using std::cout;
using std::endl;
class TextParser {
public:
    TextParser(string filename);

    string getMostCommonWord();

private:
    std::unordered_map<string, int> frequencies;



};


#endif //CODEWILLINGQUESTIONS_TEXTPARSER_H
