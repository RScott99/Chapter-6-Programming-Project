//should take 5 scores, add them up, remove highest and lowest score, then average 
//the remaining three scores for the contenstants final score
#include <iostream>
#include <iomanip>

using namespace std;

//defining global constants
const int judges = 5;
const double min_Score = 0.0;
const double max_Score = 10.0;

//Function Prototypes Here
double getScore();
//gets judges score & validates it
//must be number from 0.0-10.0 inclusive and returns a double

bool isLower(double a, double b);
//returns true if a <= b
//takes two doubles as inputs

bool isHigher(double a, double b);
//returns true if a >= b
//takes two doubles as inputs

double calcAverage(double total, double minScore, double maxScore);
//calculates the average after subtracting lowest&highest scores
//takes the total of all 5 scores, min score, and max score as inputs
//returns the average of the three scores in the middle.



int main()
{
    double total = 0.0, score, minScore, maxScore, average;

    //setting decimal point
    std::cout << fixed << setprecision(2);
    std::cout << "Star Search Score Calc\n\n";

    //initialize first score
    score = getScore();
    total += score;
    minScore = score;
    maxScore = score;

    //Itterate through remaining scores
    for (int j = 1; j < judges; ++j) {
        score = getScore();
        total += score;

        if (isLower(score, minScore)) {
            minScore = score;
        } if (isHigher(score, maxScore)) {
            maxScore = score;
        }
    }

    //Get Average and display it
    average = calcAverage(total, minScore, maxScore);
    std::cout << "\nFinal Score: " << average << endl;

    return 0;
}

//Defining Function
double getScore() {
    double score;
    do { //get score
        std::cout << "Enter judge's score (0.0 to 10.0): ";
        std::cin >> score;

        //validate that score is between 0.0 and 10.0
        if (cin.fail() || score < min_Score || score > max_Score) {
            std::cout << "Invalid input, must be in range (0.0 to 10.0).\n";
            std::cin.clear();
        }
    } while (score < min_Score || score > max_Score);
    return score;
}

bool isLower(double a, double b) {
    return (a <= b);
}

bool isHigher(double a, double b) {
    return (a >= b);
}

double calcAverage(double total, double minScore, double maxScore) {
    return ((total - minScore - maxScore) / 3.0);
}