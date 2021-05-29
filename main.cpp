#include <iostream>
#include <climits>
#include <cstring>
#include <ios>

//Cannot convert from string to array
using namespace std;

//FastExp Loop signature
double fastExp(double base, int exp, double acc);

double fastExp(double base, int exp);

double addup(char variation, int varCorr, int gradeWeight);

int main()
{
    cout << "Welcome to CGPA calculator!" << endl;

    cout << endl << "Enter the number of grades: ";
    int numOfGrades;
    cin >> numOfGrades;

    string grade[numOfGrades];

    double calc = 0.0;
    int credits = 0;

    cin.ignore();
    cout << endl;

    char * grd;
    for(int count = 0; count < numOfGrades; count++)
    {
        cout << "Enter grade#" << (count+1) << ": ";

        getline(cin, grade[count]);

        grd = new char[3];

        for(int counter = 0; counter < grade[count].length(); counter++)
            grd[counter] = grade[count].at(counter);

        grd[grade[count].length()] = ' ';

        credits += (grd[2] == 'l' ? 1: 3);
        calc += ( addup(grd[1], (grd[2] == 'l' ? 1: 3), grd[0] ) );

        delete grd;
    }
    cout << "Total credits earned: " << credits << endl;
    cout << "Your cgpa is: " << calc/credits << endl;

    return 0;
}

double addup(char variation, int varCorr, int gradeWeight)	//Track variation +/-
{
	if(variation == '-')
		return (69 - gradeWeight) * (double)varCorr - varCorr / 3.0;
	else if(variation == '+')
		return (69 - gradeWeight) * (double)varCorr + varCorr / 3.0;

	return (69 - gradeWeight) * varCorr;
}

//Fast Exponential Loop Defined
double fastExp(double base, int exp)
{
    double acc = 1.0;

    while(exp != 0)
    {
        if(exp % 2 == 0) {
            base *= base;
            exp /= 2;
        }
        else
        {
            exp -= 1;
            acc *= base;
        }
    }
    return acc;
}

//Fast Exponential Recursive
double fastExp(double base, int exp, double acc)
{
    if(exp == 0)
        return acc;
    else if(exp % 2 == 0)
        return fastExp(base * base, exp/2, acc);
    else
        return fastExp(base, exp-1, base * acc);
}
