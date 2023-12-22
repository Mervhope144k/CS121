

////////////////////////////////////////////////////////////////////////////////////////////
//
// File Name         :
//
// This program
//
// Programmer        : B.J. Streller AND Merveilles B Katumba
//
// Date Written      :
//
// Date Last Revised :
//
////////////////////////////////////////////////////////////////////////////////////////////




#include <iostream>					// need cin,cout,etc.
#include <iomanip>					// need setf,precision

using namespace std;


// global variable declarations

int     t1,							// test 1 grade
        t2,							// test 2 grade
        t3;							// test 3 grade
double  Average_Of_Tests = 0.0;		// average of tests
char    Grade;						// course grade
string f_name, l_name;






////////////////////////////////////////////////////////////////////////////////////////////



int  main( )
{
    cin >> f_name; 
    cin >> l_name;
////////////////prompt user for three test scores; validates entries;
////////////////prints any re-entered scores

    // prompt for test1
    cout << " \n\n Please enter your score from test 1 : ";
    cin >> t1;

    // validate test1
    if( (t1 > 100) || (t1 < 0) )
        // correct if necessary
        {
            cout << " \n INVALID GRADE! \n ";
            cout << "Please re-enter a test 1 score from 0 to 100 : ";
            cin >> t1;
            cout << " \n Thank you\n ";
            cout << " \n You have now entered " << t1 << " for test 1.\n\n";
        }


    // prompt for test2
    cout << " Please enter your score from test 2 : ";
    cin >> t2;

    // validate test2
    if( (t2 > 100) || (t2 < 0) )
        // correct if necessary
        {
            cout << " \n INVALID GRADE! \n ";
            cout << "Please re-enter a test 2 score from 0 to 100 : ";
            cin >> t2;
            cout << " \n Thank you\n ";
            cout << " \n You have now enterd "<< t2 <<" for test 2.\n\n";
        }


    // prompt for test3
    cout << " Please enter your score from test 3 : ";
    cin >> t3;

    // validate test3
    if( (t3 > 100) || (t3 < 0) )
        // correct if necessary
        {
            cout << " \n INVAILID GRADE!\n ";
            cout << "Please re-enter a test 3 score from 0 to 100 : ";
            cin >> t3;
            cout << " \n Thank you\n ";
            cout << " \n You have now enterd "<< t3 << " for test 3.\n\n";
        }

    cout << endl;





////////////////calculates the average of the three tests that the user entered

    //local variable declarations

    double sum = 0.0,				// sum of the tests
           ave = 0.0;				// average of tests

    sum = t1 + t2 + t3 ;			// compute sum of tests
    ave = sum / 3.0;				// compute average

    Average_Of_Tests = ave;






////////////////determines the course grade from Average_Of_Tests

    char grd;			// course grade


    // 'A' grade determination
    //YOU ADD YOUR CODE HERE
    if (ave >= 90)
        cout << grd;


    // 'A'-'B' range grade determination
    //YOU ADD YOUR CODE HERE



    // 'C'-'D' range grade determination
    //YOU ADD YOUR CODE HERE


    // 'F' grade determination
    //YOU ADD YOUR CODE HERE

    Grade = grd;  //set grd to Grade







////////////////prints data echo, test average (two decimal places)
////////////////and the course grade


    cout.setf(ios::fixed|ios::showpoint);		// show the decimal point
    cout << setprecision(2);					// show two decimal places


    // data echo
    cout << " You have entered the following three test grades : "
         << " \n " << t1 << " for test 1, " << t2 << " for"
         << " test 2, and " << t3 << " for test 3, " << "\n\n ";

    // print average
    cout << " The average of the three tests that you"
         << " entered is : "<< Average_Of_Tests << "\n\n ";

    // print final grade
    cout << " Your course grade is "<< Grade << "."<< "\n\n\n";






    return 0;


}


////////////////////////////////////////////////////////////////////////////////////////////

