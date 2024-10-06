#include "ConwayGameOfLife.hpp"
#include "FilesParser.hpp"
#include "DataHolders.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <boost/range/adaptor/indexed.hpp>

using namespace std;

int main()
{
    //conway game
    // Conway::runConwayGame();

    //files workshop part 1
    FilesWorkshop::FilesParser<FilesWorkshop::Language> filesParser {};
    filesParser.readData("C:/Users/UserX/Documents/CPP_Projects/AdvancedCppTraining/FilesWorkshop/languages.txt");
    filesParser.printData();

    return 0;

}

