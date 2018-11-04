/*********************************************************************
** Author: Eben Wight
** Date: 9/21/2018
** Description: inputHandler is a collection of utilities to read from
** stdin and to parse and validate various forms of input
*********************************************************************/
#ifndef INPUTHANDLER
#define INPUTHANDLER

#include <string>

namespace inputHandler {

bool readSingleLine(std::string &input);

bool readSingleString(std::string &input, bool multiline);

bool readInt(int &input, bool signedInt);

bool readSingleChar(char &input);

bool validateInt(std::string &input, bool signedInt);

bool isDigitOrSign(char thischar);

bool validateSingleChar(std::string &input);

bool validateIntRange(int input, int lower, int upper, bool inclusive);

bool validateFileName(std::string &input);

bool isDashOrDot(char thisChar);

std::string stringifyArray(int *arr, int size);

} // namespace inputHandler

#endif