// ''' This program reads data from "runners.txt" and uses parallel arrays to store the total numbers of miles and average numbers of miles run for each person. 
// The data from the text file is used to make the calculations for the total and average miles per week. The data is displayed using a table which contains columns for the names and
// the days with the respective number of miles run on that day, along with the calculated averages and totals for each person. The columns are aligned using setw(). '''


// Insert libraries 
#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>

using namespace std;

// Global arrays to store average and total miles run for each person
double average[5];   // Array to store average number of miles run for each person 
double totalMiles[5]; // Array to store total miles run for each person

// Function prototypes: 

// Function to get the data from runners.txt
// Precondition: The file "runners.txt" must exist and be readable. The arrays n and runData must be large enough to hold the data.
// Postcondition: The arrays n and runData are filled with the data from the file.
void getData(ifstream& inf, string n[], double runData[][8], int count);

// Function to calculate average number of miles per week for each person 
// Precondition: The array runData must be filled with the data.
// Postcondition: The global arrays average and totalMiles are filled with the calculated averages and totals.
void calculateAverage(double runData[][8], int count);

// Function to display the data 
// Precondition: The arrays n and runData must be filled with the data. The global arrays average and totalMiles must be filled with the calculated averages and totals.
// Postcondition: The data is printed to the console.
void print(string n[], double runData[][8], int count);

// Create main function
int main()
{
    // Local arrays to store names and running data
    string names[5];
    double runningData[5][8];
    // Open the file
    ifstream inputfile("runners.txt");
    if (inputfile)
    {
        getData(inputfile, names, runningData, 5);
    }
    else
    {
        // If the file is not open, print an error message and exit
        cout << "Sorry! Unable to open the file." << endl;
        return 0;
    }
    inputfile.close();

    // Calculate the averages and print the data
    calculateAverage(runningData, 5);
    print(names, runningData, 5);

    return 0;
}
// Function to get the data from the file
void getData(ifstream& inf, string n[], double runData[][8], int count)
{
    // While not at the end of the file, read the data into the arrays
    while (!inf.eof())
    {
        for (int i = 0; i < count; i++)
        {
            inf >> n[i];
            for (int j = 0; j < 7; j++)
            {
                inf >> runData[i][j];
            }
        }
    }
}
// Calculate the average number of miles ran per week for each person 
void calculateAverage(double runData[][8], int count)
{
    double total;
    for (int i = 0; i < count; i++)
    {
        total = 0;
        for (int j = 0; j < 7; j++)
        {
            total += runData[i][j];
        }
        // Calculate total miles run for each person
        average[i] = total / 7;
        totalMiles[i] = total;
    }
}
// Output data 
void print(string n[], double runData[][8], int count)
{
    cout << setfill(' ') << setw(80) << " " << endl;
    cout << setfill(' ');
    // Print the names and data
    cout << setw(10) << "Name";
    for (int i = 0; i < 7; i++)
        cout << setw(9) << "Day " << (i + 1);
    cout << setw(22) << "Average" << setw(18) << "Total Miles" << endl;
    cout << setfill(' ') << setw(80) << " " << endl;
    cout << setfill(' ');
    for (int i = 0; i < count; i++)
    {
        cout << setw(10) << n[i];
        for (int j = 0; j < 7; j++)
        {
            cout << setw(10) << setprecision(2) << fixed << runData[i][j];
        }
        cout << setw(22) << average[i] << setw(14) << totalMiles[i] << endl;
    }
}