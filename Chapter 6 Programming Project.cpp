//This code gets the length & width of a rectangle, it then calculates and displays the perimeter
//and area of the rectangle, it then asks if the user wants to process another rectangle and continues
//until the user decides to quit

#include <iostream>
#include <string>

using namespace std;

//Function Prototypes Here

//getLength_Width - no inputs, gets the length&width of rectangle and validates that they are > 0, then returned to call
void getLength_Width(double& length, double& width);


//calcPerimeter - takes length and width as inputs and calculates the perimeter of the rectangle using the quantities gathered prior, then returned to call
double calcPerimeter(double length, double width);


//calcArea - takes length and width as inputs, assumes they are valid, and the calculates and returns area of the rectangle
double calcArea(double length, double width);


//displayProperties - takes the perimeter&area as inputs, displays them and does not return a value
void displayProperties(double perimeter, double area);




int main()
{
    double length, width, perimeter, area;
    string doQuit;

    std::cout << "Rectangle Properties Calc\n";

    do {
        getLength_Width(length, width);
        perimeter = calcPerimeter(length, width);
        area = calcArea(length, width);
        displayProperties(perimeter, area);

        //prompt if user wants to quit
        std::cout << "\nWould you like to quit? ('Quit' if yes): ";
        std::cin >> doQuit;

    } while (doQuit != "Quit");

    std::cout << "\nQuitting...";

    return 0;
}



//Defining Function Prototypes Here

void getLength_Width(double& length, double& width) {
    do { //querying length value
        std::cout << "\nEnter the length of the rectangle: ";
        std::cin >> length;
        if (length <= 0 || cin.fail()) { //validating positive length
            std::cout << "Invalid input, length must be positive.\n";
            std::cin.clear();
        }
    } while (length <= 0);

    do { //querying width value
        std::cout << "Enter the width of the rectangle: ";
        std::cin >> width;
        if (width <= 0 || cin.fail()) { //validating positive width
            std::cout << "Invalid input, width must be positive.\n";
            cin.clear();
        }
    } while (width <= 0);
}

double calcPerimeter(double length, double width) {
    return (2 * (length + width));
}

double calcArea(double length, double width) {
    return (length * width);
}

void displayProperties(double perimeter, double area) {
    std::cout << "\nProperties of Rectangle:\n";
    std::cout << "Perimeter: " << perimeter << endl;
    std::cout << "Area: " << area << endl;
}