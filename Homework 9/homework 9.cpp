//creator: Robert Ward
//homework 9
/*this program is to find the average of 4 users and then eventually finding the standard deviation from the final result, 
it also gets the input from the txt file inside of the folder.
*/


#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <cstdlib>

using namespace std;

//I decided to only create an average method because it was being pesky for some reason, this is the only way I figured out how to fix it.
double avg(double a, double b, double c, double d) {
    return (a + b + c + d) / 4;
}

int main() {
    const char* username = getenv("USER");
    string filePath = "/Users/" + string(username) + "/Desktop/homework 9/your_file.txt";
    
    ifstream inputFile(filePath);

    double num[4], dev[4];
    double average;
    double variance = 0.0; // Initialize variance to 0.0
    double standardDev;

    if (inputFile.is_open()) {
        if (inputFile >> num[0] >> num[1] >> num[2] >> num[3]) {
            cout << "Numbers read from the file: " << num[0] << ", " << num[1] << ", " << num[2] << ", " << num[3] << endl;
        } else {
            cerr << "Error: Unable to read four numbers from the file." << endl;
            return 1;
        }
    } else {
        cerr << "Error: Unable to open the file." << endl;
        return 1;
    }

    // Calculate the average
    average = avg(num[0], num[1], num[2], num[3]);

    cout << endl << "Average: " << average << endl << endl;

    // Calculate variance
    for (int i = 0; i < 4; i++) {
        dev[i] = (num[i] - average) * (num[i] - average); // Use square of deviations
        variance += dev[i];
    }

    variance /= 4; // Average of squared deviations

    // Calculate the standard deviation
    standardDev = sqrt(variance);

    cout << "The standard deviation is: " << standardDev << endl << endl;

    return 0;
}