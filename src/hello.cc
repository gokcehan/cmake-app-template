/// @file hello.cc
/// @brief
/// @author
/// @version
/// @date

#include "hello.h"

/// @brief greets a person
///
/// @param name name of the person
///
/// @return 0 if successful
int hello(std::string name)
{
    std::cout << "hello " << name << std::endl;
    return 0;
}
