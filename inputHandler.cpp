/*********************************************************************
** Author: Eben Wight
** Date: 9/21/2018
** Description: inputHandler is a collection of utilities to read from
** stdin and to parse and validate various forms of input
*********************************************************************/

#include "inputHandler.hpp"
#include "logger.hpp"
#include <cctype>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

namespace inputHandler {

/*
 * simply read in a single line from cin
 * if the line read is blank return false
 */
bool readSingleLine(std::string &input) {

    std::string tmp = "";

    std::getline(std::cin, tmp);

    input = tmp;

    debug("readSingleLine() :read " + tmp);
    if (tmp.length() == 0) {
        // std::cout << "read blank line" << std::endl;
        debug("readSingleLine: read blank line");
        return false;
    } else {
    }

    return true;
};

/**
 * read in a single line from cin, containing one contiguous string
 * no whitespace allowed
 **/
bool readSingleString(std::string &input) {

    int wordCount = 0;
    std::string temp;
    bool lineRead = readSingleLine(temp);
    bool goodString = true;
    // read this repeatedly to see how many words it contains
    std::stringstream instream;
    instream << temp;

    // recycle temp
    temp = "";

    // populate the reused temp from the string stream
    // at the same time count how many times we can do this
    // more than once means it wasn't a single word on the imput line
    while ((instream >> temp) && goodString && lineRead) {
        wordCount++;
        goodString = (wordCount < 2);
        if (wordCount >= 2)
            debug("readSingleString: multiple words in input");
        if (!goodString) {
            return goodString;
        }
    }

    input = temp;
    return goodString;
}

/**
 * read in a single line from cin, containing one contiguous string
 * no whitespace allowed
 **/
bool readSingleString(std::string &input, bool multiword) {

    if (!multiword) {
        return readSingleString(input);
    }

    int wordCount = 0;
    std::string temp;
    std::stringstream tempss;
    bool lineRead = readSingleLine(temp);
    bool goodString = true;
    // read this repeatedly to see how many words it contains
    std::stringstream instream;
    instream << temp;

    if (instream.good()) {
        goodString = true;
        input = instream.str();
        return goodString;
    } else {
        goodString = false;
        debug("readSingleString() : there was something wrong with instream: instream.rdstate() " + instream.rdstate());
    }

    input = "";
    return goodString;
}
/**
 * attempt to read in an integer value (with optional leading minus sign)
 * if the input is empty or not an integer value return false
 **/
bool readInt(int &input, bool signedInt = true) {
    std::string tmp = "";
    bool lineRead = readSingleLine(tmp);

    bool goodInt = validateInt(tmp, signedInt);
    if (lineRead && goodInt) {
        input = std::stoi(tmp);
    }

    return goodInt;
}

/**
 * attempt to read in a single character value
 * if the input is empty or not an alphanumeric value return false
 **/
bool readSingleChar(char &input) {
    std::string tmp = "";
    bool lineRead = readSingleLine(tmp);

    bool goodChar = validateSingleChar(tmp);

    if (lineRead && goodChar) {
        input = static_cast<char>(tmp[0]);
    }

    return goodChar;
}

/**
 * check that the value entered is of the format (-)####
 **/
bool validateInt(std::string &input, bool signedInt) {
    bool validInt = true;
    int l = input.length();

    if (input.length() == 0) {
        // std::cout << "zero length input" << std::endl;
        debug("validateInt: zero length input");
        return false;
    } else {

        for (int i = 0; (i < l) && validInt; i++) {
            if (i == 0 && signedInt) {
                validInt = isDigitOrSign(input[i]);
            } else {
                validInt = isdigit(static_cast<unsigned char>(input[i]));
            }
        }
    }

    return validInt;
}

/**
 * check that this single character is either 0-9 or -
 **/
bool isDigitOrSign(char thischar) {

    return ((thischar == '-') || isdigit(static_cast<unsigned char>(thischar)));
}

/**
 * check that this single character is non blank and is alphanumeric
 **/
bool validateSingleChar(std::string &input) {
    if (input.length() == 0 || input.length() > 1) {
        return false;
    } else {
        return std::isalnum(static_cast<char>(input[0]));
    }
}

/**
 * check that an integer is within a range, either inclusive or exclusive of its bounds
 **/
bool validateIntRange(int input, int lower, int upper, bool inclusive = true) {

    if (inclusive && ((lower <= input) && (input <= upper))) {
        return true;
    } else if (!inclusive && ((lower < input) && (input < upper))) {
        return true;
    } else {
        return false;
    }
}

/**
 * confirm that string fits the general pattern of a filename
 * valid characters are [a-zA-Z][0-9][-_.]
 * no, you cannot use spaces, that's dumb
 **/
bool validateFileName(std::string &input) {
    bool validName = true;
    bool alpha = false;
    bool dashOrDot = false;
    int l = input.length();

    if (input.length() == 0) {
        // std::cout << "validateFileName: zero length input" << std::endl;
        debug("validateFileName: zero length input");
        return false;
    } else {

        for (int i = 0; (i < l) && validName; i++) {

            alpha = isalnum(static_cast<unsigned char>(input[i]));
            dashOrDot = isDashOrDot(static_cast<unsigned char>(input[i]));
            // you cant end in a dash, dot or underscore. I don't care if you think YOU can, you can't. so there.
            if (i == (l - 1)) {
                if (dashOrDot) {
                    validName = false;
                }
            } else {
                validName = (alpha || dashOrDot);
            }
        }
    }

    if (!validName) {
        debug("validateFileName: bad name _ " + input);
    }
    return validName;
}

/**
 * verify that a char is one of [-_.]
 * for use in filename checking
 **/
bool isDashOrDot(char thisChar) {

    return ((thisChar == '-') || (thisChar == '_') || (thisChar == '.'));
}

std::string stringifyArray(int *arr, int size) {

    std::stringstream out;
    out << "[";
    for (int i = 0; i < size; i++) {
        out << arr[i] << ", ";
    }

    out << "]";

    return out.str();
}

// checks if input is an int above parameter x
int isIntAboveX(int x) {

	std::string input;
    bool good;

    // two do while functions that check if the input is a digit and if it is above 0
    do {
        do  {
            
            good = true;

            std::cin >> input;
            
            // goes through each element in the string to see if it is a digit
            for (int i = 0; i < input.length(); i++) {

                
                if (!(isdigit(input[i]))) {
                    good = false;
                } 
            }
            if (!good) {
				std::cout << "ERROR! INCORRECT INPUT!" << std::endl;
				std::cout << "Please enter an integer above " << x << ":" << std::endl;
            }
        } while (!good);

        if (!(stoi(input) > x)) {

            std::cout << "ERROR! INCORRECT INPUT!" << std::endl;
            std::cout << "Please enter an integer above " << x << ":" << std::endl;
        }
    } while (!(stoi(input) > x));
    

    // return the good input
    return stoi(input);
}

// checks if input is an int above parameter x and below parameter y
int isIntBetweenXAndY(int x, int y) {

    std::string input;
    bool good;

    // two do while functions that check if the input is a digit and if it is above 0
    do {
        do  {
            
            good = true;

            std::cin >> input;
            
            // goes through each element in the string to see if it is a digit
            for (int i = 0; i < input.length(); i++) {

                
                if (!(isdigit(input[i]))) {
                    good = false;
                } 
            }
            if (!good) {
               std::cout << "ERROR! INCORRECT INPUT!" << std::endl;
               std::cout << "Please enter an integer between " << x << " and " << y << ":" << std::endl;
            }
        } while (!good);

        if ( stoi(input) < x || stoi(input) > y ) {

            std::cout << "ERROR! INCORRECT INPUT!" << std::endl;
               std::cout << "Please enter an integer between " << x << " and " << y << ":" << std::endl;
        }
    } while ( stoi(input) < x || stoi(input) > y );
    

    // return the good input
    return stoi(input);
}


} // namespace inputHandler
