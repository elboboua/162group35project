/**
 * Author: Eben Wight
 * Date: 2018/10/06
 * Description: just a simple logging facility
 **/

#ifndef LOGGER
#define LOGGER
#include <string>

void debug(const std::string msg);
void debug(const char *msg);
void debug(const bool msg);

#endif
