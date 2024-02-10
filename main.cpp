#include "ConwayGameOfLife.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <boost/range/adaptor/indexed.hpp>

using namespace std;

//passing by reference
int func(int& y)
{
    cout << "y is " << y << "\n";
    y = 1;
    return y;
}

//class definition&declaration example
class UrlAddress{
    public:
    UrlAddress(const string& protocol, const string& resource) : protocol(protocol), resource(resource) {}
    void printUrl()
    {
        cout << protocol << "://" << resource << "\n";
    }
    private:
    string protocol;
    string resource;
};

int main()
{
    //two dimensional array

    vector<vector<string>> names {{"fred", "wilma", "pebbles", "dino"}, 
    {"barney", "betty", "bamm-bamm", "hoppy"}};

    for (const auto & namesRow : names | boost::adaptors::indexed(0))
    {
        cout << namesRow.index() << " row elements:\n";  
        for (const auto & name : namesRow.value() | boost::adaptors::indexed(0))
        {
            cout << name.index() << ". " << name.value() << ", ";
        }
        cout << "\n";
    }

    //conway game
    Conway::runConwayGame();

    return 0;

}

