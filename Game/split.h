#ifndef SPLIT_HH
#define SPLIT_HH

#include <string>
#include <vector>

namespace Student
{

namespace Split
{
    /**
     * @brief split splits given string by given spacer into a vector and returns it
     * @param line
     * @param spacer
     * @param bypass
     * @return vector of parts divided with spacer, bybass ignores whitespaces
     */
    std::vector<std::string> split(std::string line, char spacer, bool bypass = false);
}

}

#endif // SPLIT_HH
