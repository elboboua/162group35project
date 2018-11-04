/**
 * Author: Eben Wight
 * Date: 2018/10/03
 * Description: menu module to display user promts and read in answers
 **/
#ifndef MENU
#define MENU

#include <string>
#include <vector>

const std::string PLEASE_INT = "Please enter an integer value";
const std::string SIGNED_FORM = " of the format (-)NNNNN";
const std::string PLEASE_FILENAME =
    "Please enter a filename consisting of [a-zA-z][-_.][a-zA-Z]. \nName must start and end with a letter character and contain no space";
const int FILENAME = 0;
const int FREEFORM = 1;
class Menu {

  private:
  public:
    // const std::map<int, std::string> stringValidationMessages{ { FILENAME, PLEASE_FILENAME } };
    Menu();
    ~Menu();
    // static const StringTypes stringTypes;
    bool singleChoice(std::string prompt, std::vector<std::string> prompts, std::vector<char> options, char &response);
    void printPrompts(std::vector<std::string> prompts);
    bool isAllowedOption(std::vector<char> &options, char &response);
    bool singleInteger(std::string prompt, int &number, bool signedInt);
    bool stringInput(std::vector<std::string> prompt, std::string &input, int type = -1);
};
#endif // MENU