#include <sstream>
#include <fstream>
#include <boost/algorithm/string.hpp>

#include "FilesParser.hpp"
#include "DataHolders.hpp"


namespace FilesWorkshop{

template<typename T>
void FilesParser<T>::readData(const std::string pathToFile)
{
    std::string line {};
    std::ifstream file(pathToFile);
    if (file.is_open()) {
        while (getline(file, line)) {
            std::vector<std::string> words;

            boost::split(words, line, boost::is_any_of(" "));

            const std::string lang = words.front();
            const int date = std::stoi(words.back());
            words.pop_back();
            words.erase(words.begin());

            std::string designer = boost::algorithm::join(words, " ");

            T dataHolder{lang, designer, date};
            parsedData.push_back(dataHolder);

        }
        file.close();
    }
}

template<typename T>
void FilesParser<T>::printData()
{
    for(auto& data : parsedData)
    {
        std::cout << data << '\n';
    }
}

//workaround for linking errors
template void FilesParser<Language>::readData(const std::string pathToFile);
template void FilesParser<Language>::printData();
}