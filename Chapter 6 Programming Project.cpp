//should create a table showing the conversion between celsius and fahrenheit temps between 0 and 20 degrees.
#include <iostream>
#include <iomanip>

using namespace std;

//defining global constants
const int minFahrenheit = 0;
const int maxFahrenheit = 20;

//defining function prototype

double getCelsius(int fahrenheit);
//should convert a temp in fahrenheit into celsius
//inputs an integer that represents the temp in fahrenheit
//returns the equivalent temperature in celsius



int main()
{

    //Display title and headers of table
    std::cout << "Celsius Temp. Conversion Table\n";
    std::cout << setw(10) << "Fahrenheit" << setw(15) << "Celsius\n";
    std::cout << "-------------------------------\n";

    //Display rows of table
    for (int j = minFahrenheit; j <= maxFahrenheit; ++j) {
        double celsius = getCelsius(j);
        std::cout << fixed << setprecision(1);
        std::cout << setw(10) << j << setw(15) << celsius << endl;

    }
    return 0;
}

//defining function
double getCelsius(int fahrenheit) {
    return ((5.0 / 9.0) * (fahrenheit - 32));
}