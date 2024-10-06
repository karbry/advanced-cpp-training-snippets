#include <string>
#include <iostream>

namespace FilesWorkshop{

struct Language {
    std::string lang;
    std::string designer;
    int date;

    friend std::ostream& operator<<(std::ostream& os, const Language& lang) {
        os << lang.lang << ", " << lang.designer << ", " << lang.date;
        return os;
    }
};
}