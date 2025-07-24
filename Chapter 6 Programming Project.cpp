//determines which geographic regions within a major city had the fewest reported car accidents last year

#include <iostream>
#include <string>

using namespace std;

//Function Prototypes Here

void getRegInfo(string& regName, int& numAccidents);
//gets the name and # of accidents that occure in the prior year in the region
//validates that numAccident >= 0
//writes values to reference variables

bool isLower(int a, int b);
//takes two integers as inputs,
//returns true if int a < int b
//false otherwise

void showLowest(string lowestReg, int lowestAccidents);
//gets name of reg w/ lowest accidents, and num of accidents and displays them
//does not return anything

int main()
{
    const int REGIONS = 5;
    string regions[REGIONS] = {
        "Norht","South","East","West","Central"
    };
    string regName, lowestReg;
    int numAccidents, lowestAccidents;




    return 0;
}

//defining prototypes here

void getRegInfo(string& regName, int& numAccidents) {
    std::cout << "Enter name of region: ";
    getline(cin >> ws, regName);

    do {
        std::cout << "Enter # of accidents in " << regName << ": ";
        std::cin >> numAccidents;

        if (numAccidents < 0) {
            std::cout << "Invalid Input, must be positive.\n";
            std::cin.clear();
        }
    } while (numAccidents < 0);
}