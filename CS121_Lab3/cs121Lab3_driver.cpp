

////////////////////////////////////////////////////////////////////////////////////////////
//
// File Name         : cs121Lab3_driver.cpp
//
// This program      : This program determines the student's grade.
//
// Programmer        : B.J. Streller AND M.B Katumba
//
// Date Written      : 9/19/23
//
// Date Last Revised : 9/25/23
//
////////////////////////////////////////////////////////////////////////////////////////////




#include <iostream>					// need cin,cout,etc.
#include <iomanip>					// need setf,precision
#include <string>

using namespace std;


// global variable declarations

int     t1,							// test 1 grade
        t2,							// test 2 grade
        t3;							// test 3 grade
double  Average_Of_Tests = 0.0;		// average of tests
char    Grade;						// course grade



////////////////////////////////////////////////////////////////////////////////////////////



int  main( )
{
    ////////////////prompt user for to enter their first name and last name;
    cout << "Enter your first name: ";
    cin >> f_name;
    cout << endl;
    cout << "Enter your last name: ";
    cin >> l_name;
    cout << endl;
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

    double sum = 0.0,				    // sum of the tests
           ave = 0.0,                   // average of tests
        sum_Of_t2_t3 = 0.0,             // sun of test2 and test3
        ave_Of_t2_t3 = 0.0;		        // average of test2 and test3

    sum = t1 + t2 + t3 ;			    // compute sum of tests
    ave = sum / 3.0;				    // compute average
    sum_Of_t2_t3 = t2 + t3;             // compute the sum of test2 and test3
    ave_Of_t2_t3 = sum_Of_t2_t3 / 2.0;  // compute average of test2 and test3

////////////////determines the course grade from Average_Of_Tests

    char grd;			// course grade


    // 'A' grade determination
    if (ave >= 90)
        grd = 'A';

    // 'A'-'B' range grade determination
    else
        if (ave >= 70 && ave < 90)
            if (t3 >= 90)
                grd = 'A';
            else
                grd = 'B';

    // 'C'-'D' range grade determination
        else
            if (ave >= 50 && ave < 70)
                if (ave_Of_t2_t3 >= 70)
                    grd = 'C';
                else
                    grd = 'D';

    // 'F' grade determination

            else
                grd = 'F';
    
    Grade = grd;  //set grd to Grade
    Average_Of_Tests = ave; // set ave to Average_Of_Tests

////////////////prints data echo, test average (two decimal places)
////////////////and the course grade


    cout.setf(ios::fixed|ios::showpoint);		// show the decimal point
    cout << setprecision(2);					// show two decimal places

    // print full name
    cout << "Your full name is: "
        << f_name << " " << l_name << "\n\n ";
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
/*
 Please enter your score from test 1 : 76
 Please enter your score from test 2 : 56
 Please enter your score from test 3 : 98

 You have entered the following three test grades :
 76 for test 1, 56 for test 2, and 98 for test 3,

  The average of the three tests that you entered is : 76.67

  Your course grade is A.
*/

