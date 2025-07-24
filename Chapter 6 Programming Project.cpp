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

void showLowest(string regName, int numAccidents);
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

    std::cout << "Safest Driving Area\n\n";

    //initialize using first region
    getRegInfo(regName, numAccidents);
    lowestReg = regName;
    lowestAccidents = numAccidents;

    //Iterate through remaining regions
    for (int j = 1; j < REGIONS; ++j) {
        getRegInfo(regName, numAccidents);
        if (isLower(numAccidents, lowestAccidents)) {
            lowestReg = regName;
            lowestAccidents = numAccidents;
        }
    }

    showLowest(lowestReg, lowestAccidents);

    return 0;
}

//defining prototypes here

void getRegInfo(string& regName, int& numAccidents) {
    std::cout << "Enter name of region: ";
    getline(cin >> ws, regName);

    do {
        std::cout << "Enter # of accidents in " << regName << ": ";
        std::cin >> numAccidents;

        if (numAccidents < 0 || cin.fail()) {
            std::cout << "Invalid Input, must be positive.\n";
            std::cin.clear();
        }
    } while (numAccidents < 0);
}

bool isLower(int a, int b) {
    return (a <= b);
}

void showLowest(string regName, int numAccidents) {
    std::cout << "\nThe Region with the lowest accident rate:\n";
    std::cout << "Region: " << regName << "\n";
    std::cout << "Number of Accidents: " << numAccidents << endl;
}