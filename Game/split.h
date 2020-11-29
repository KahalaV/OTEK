#ifndef SPLIT_HH
#define SPLIT_HH

#include <string>
#include <vector>
namespace Student
{

namespace Split
{
    /**
     * @brief split
     * @param line
     * @param spacer
     * @param bypass
     * @return
     */
    std::vector<std::string> split(std::string line, char spacer, bool bypass = false);
}

}

#endif // SPLIT_HH
