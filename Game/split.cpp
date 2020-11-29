#include "split.h"

namespace Student
{

namespace Split
{

std::vector<std::string> split(std::string line, char spacer, bool bypass)
{
    int length = 1;
    if (!bypass) {
        std::string::size_type index = line.find(spacer);
        while (index != std::string::npos) {
            length++;
            index = line.find(spacer, index + 1);
        }
    } else {
        std::string::size_type index = line.find(spacer);
        std::string::size_type index2 = line.find(spacer, index + 1);

        while (index != std::string::npos) {
            if (index2 - index > 1) {
                length++;
            }
            index = line.find(spacer, index + 1);
            if (index < line.length() - 2) {

                index2 = line.find(spacer, index + 1);
            }
        }
        if (line.at(0) == spacer) {
            length--;
        }
        if (length >= 1) {
            std::string::size_type back = line.rfind(spacer);
            if (back == line.length() - 1) {
                length--;
            }
            while ((line.length() > 0) && (back == line.length() - 1)) {
                if (line.at(back) == spacer) {
                    line.pop_back();
                }
                back = line.rfind(spacer);
            }
        }
    }
    if (length <= 0) {
        std::vector<std::string> partless = {};
        return partless;
    }
    std::vector<std::string> parts(static_cast<std::string::size_type>(length));
    unsigned long j = 0;

    if (!bypass){
        for (auto o : line) {
            if (o == spacer) {
                j++;
                parts.at(j) = "";

            } else {
                parts.at(j) += o;
            }
        }
    } else {
        std::string::size_type i = 0;
        while (line.at(i) == spacer) {
            i++;
        }
        for (; i < line.length(); i++) {
            if (line.at(i) == spacer and line.at(i+1) == spacer) {
                continue;
            } else if (line.at(i) == spacer and line.at(i+1) != spacer) {
                j++;
            } else {
                parts.at(j) += line.at(i);
            }
        }
    }

    return parts;
}

}

}
