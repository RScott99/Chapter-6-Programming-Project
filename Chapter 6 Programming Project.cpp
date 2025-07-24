//determine price of paint job dependant on square footage, gallons of paint, and labor costs.
#include <iostream>
#include <iomanip>
#include <cmath> // for ceil

using namespace std;

//defining global constants
const double sqft_perGal = 110.0;
const double hours_perGal = 8.0;
const double labor_ratePerHour = 25.0;

//defining function prototypes here
int getRooms();
//gets number of rooms, validates that it is >= 1
//returns validated integer val

double getSqFt(int roomNum);
//gets the square footage of one room and validates that it is >= 0
//returns validated double val

double getPricePerGallon(int roomNum);
//gets price of paint per gallon for one room
//validates that it is >= 10.0 and returns the double

int gallonsForRoom(double sqFt);
//calculates number of gallons of paint required,  (rounded up)
//squarefeet must be >= 0, returns integer number of gallons

double laborHoursForRoom(double sqFt);
//calculates the hours of labor required for one room, sqft must be >= 0
//returns a double for the hours of labor

void displayEstimate(double paintCost, int totalGal, double laborCost, double laborHours);
//displays the summary for the final estimate and is written to screen

int main()
{
    int numRooms = getRooms();
    int totalGal = 0;
    double paintCost = 0.0, laborCost = 0.0, laborHours = 0.0;

    for (int j = 1; j <= numRooms; ++j) {//itterates through each function for each room
        double sqft = getSqFt(j);
        double pricePerGal = getPricePerGallon(j);
        int gals = gallonsForRoom(sqft);
        double hours = laborHoursForRoom(sqft);

        totalGal += gals;
        laborHours += hours;
        paintCost += (gals * pricePerGal);
        laborCost += (hours * labor_ratePerHour);
    }

    displayEstimate(paintCost, totalGal, laborCost, laborHours);
    return 0;
}

//defining functions

int getRooms() {
    int rooms;
    do {
        std::cout << "Enter number of rooms to paint: ";
        std::cin >> rooms;
        //validate that rooms are >= 1
        if (rooms < 1 || cin.fail()) {
            std::cout << "Error. Need at least 1 room.\n";
            std::cin.clear();
        }
    } while (rooms < 1);
    return rooms;
}

double getSqFt(int roomNum) {
    double sqft;
    do {
        std::cout << "Enter sqft of wall for room " << roomNum << ": ";
        std::cin >> sqft;
        //validate that sqft >= 0
        if (sqft < 0 || cin.fail()) {
            std::cout << "Error, sqft must be >= 0.\n";
            std::cin.clear();
        }
    } while (sqft < 0);
    return sqft;
}

double getPricePerGallon(int roomNum) {
    double price;
    do {
        std::cout << "Enter price per gallon of paint for room " << roomNum << ": ";
        std::cin >> price;
        //validate that price >= 10.0
        if (price < 10.0 || cin.fail()) {
            std::cout << "Error. Price must be >= $10.00.\n";
            std::cin.clear();
        }
    } while (price < 10.0);
    return price;
}

int gallonsForRoom(double sqFt) {
    return static_cast<int>(ceil(sqFt / sqft_perGal)); //forces double into int.
}

double laborHoursForRoom(double sqFt) {
    return ((sqFt / sqft_perGal) * hours_perGal);
}

void displayEstimate(double paintCost, int totalGal, double laborCost, double laborHours) {
    double totalCost = paintCost + laborCost;
    std::cout << fixed << setprecision(2);
    std::cout << "\n----- Paint Job Estimate -----\n";
    std::cout << "Gallons of paint needed:   " << totalGal << endl;
    std::cout << "Hours of labor needed:     " << laborHours << endl;
    std::cout << "Cost of paint:             $" << paintCost << endl;
    std::cout << "Labor Cost:                $" << laborCost << endl;
    std::cout << "-----------------------------\n";
    std::cout << "Total Cost for paint job:   $" << totalCost << endl;
}
