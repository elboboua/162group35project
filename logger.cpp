/**
 * Author: Eben Wight
 * Date: 2018/10/06
 * Description: just a simple logging facility
 **/
#include "logger.hpp"
#include <iostream>
#include <string>

#if defined(DEBUG)

static bool testing = true;
#else

static bool testing = false;
#endif // DEBUG

/**
 * output text to cout
 **/
void debug(const std::string msg) {
    if (!testing)
        return;
    else
        std::cout << "debug: " << msg << std::endl;
}
/**
 * output text to cout
 **/
void debug(const char *msg) {
    if (!testing)
        return;
    else
        std::cout << "debug: " << msg << std::endl;
}
/**
 * output text to cout
 **/
void debug(const bool msg) {
    if (!testing)
        return;
    else
        std::cout << "debug: " << msg << std::endl;
}
