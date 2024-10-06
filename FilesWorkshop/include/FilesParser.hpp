#include <string>
#include <vector>

namespace FilesWorkshop{

template<typename T>
class FilesParser
{
    public:
        void readData(const std::string pathToFile);
        void printData();

    private:
        std::vector<T> parsedData {};

};

}