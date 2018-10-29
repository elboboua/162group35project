/**
 * Author: Eben Wight
 * Date: 2018/10/03
 * Description: menu module to display user promts and read in answers
 **/
#include "Menu.hpp"
#include "inputHandler.hpp"
#include "logger.hpp"
#include <algorithm>
#include <iostream>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::find;
using std::string;
using std::vector;

Menu::Menu() {
}

Menu::~Menu() {
}

/**
 * prints a menu to the screen with a description and a list of options.
 * validates the choice as a single character and as one of the supplied options to choose.
 * sets the value of the reference parameter to the resulting choice
 * returns true if successfully run, shold never really return false
 **/
bool Menu::singleChoice(string description, vector<string> prompts, vector<char> options, char &response) {

    string optionsList = "";

    for (char c : options) {
        optionsList += (string(1, c) + " ");
    }

    cout << description << endl;
    printPrompts(prompts);

    bool charRead = false;
    bool allowed = false;

    while (!charRead || !allowed) {

        charRead = inputHandler::readSingleChar(response);
        allowed = isAllowedOption(options, response);

        if (!charRead) {

            cout << "please enter a single character selection" << endl;
        } else if (!allowed) {
            cout << "please choose from one of the following options: " << endl;
            cout << optionsList << endl;
        }
    }

    return true;
}

/**
 * prints out an array of prompts of variable length (it doesn't care how many there are)
 **/
void Menu::printPrompts(vector<string> prompts) {

    for (string prompt : prompts) {
        cout << prompt << endl;
    }
}

/**
 * checks that the entered option is even one of the darn choices in the first place, smartasses.
 * usage of find() found at http://www.cplusplus.com/reference/algorithm/find/
 **/
bool Menu::isAllowedOption(vector<char> &options, char &response) {

    vector<char>::iterator it;

    it = find(options.begin(), options.end(), response);
    if (it == options.end()) {

        return false;
    } else {

        response = *it;
        return true;
    }
}

/**
 * prompts for the input of a single integer, either signed or unsigned
 * and validates that the input is in fact an integer
 * assigns resutant value to the reference parameter
 * returns true if success, shouldn't ever return false
 **/
bool Menu::singleInteger(std::string prompt, int &number, bool signedInt) {

    cout << prompt << endl;
    bool goodInt = false;

    string message = "";
    // formate the message appropriately
    if (signedInt) {
        message = PLEASE_INT + SIGNED_FORM;
    } else {
        message = PLEASE_INT;
    }

    while (!goodInt) {
        goodInt = inputHandler::readInt(number, signedInt);
        if (!goodInt) {

            cout << message << endl;
        }
    }

    return true;
}

/**
 * read in one contiguous string, no spaces allowed
 **/
bool Menu::stringInput(std::vector<std::string> prompt, std::string &input, int type) {

    printPrompts(prompt);
    bool stringRead = false;
    bool goodString = false;

    while (!stringRead || !goodString) {

        // try to read the single string
        stringRead = inputHandler::readSingleString(input);

        // if it got read try to validate it as one of the known types
        if (stringRead) {

            switch (type) {
                case FILENAME:
                    goodString = inputHandler::validateFileName(input);
                    if (!goodString) {

                        cout << PLEASE_FILENAME << endl; // stringValidationMessages[StringTypes::FILENAME] << endl;
                    }
                    break;

                default:
                    goodString = true;
                    debug("stringInput: using default case");
                    break;
            }
        }
    }

    // input should have taken a value by this point
    return goodString;
}