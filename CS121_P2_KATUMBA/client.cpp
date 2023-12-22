//*****************************************************
//
//	Programmer:				Merveilles Katumba Biende
//  Instructor:				B.J. Streller
//  Course:					CS121
//  Date:					11/30/2023
//  Program Name:			Project2
//  Files:					cs121_P2_driver.cpp, banking.h, client.cpp
//  Input Files:			1. Accounts File -> containing number of entries, 
//                                              account number follow by customer name
//                          2. Transactions File -> containing account number with all deposits 
//                                                  and withdrawals with initial balance
//  Output Files:			The report will be written in the file monthly_report.txt 
//                          which the user will be prompted for the fully path 
//  Modules Used:			iostream - for input and output into the terminal screen
//                          fstream - for reading and writing into files
//							iomanip - for formatting output
//							stdio.h - for keeping the terminal screen open
//                          string - for string data type
//                          stdlib.h - for exit
//							
//
//  Purpose: This Program will generate a monthly report at the file path the user will input 
//           according to the recommended format based on the accounts file and transactions file 
//           that the user will also input, provided that the two files are correctly formatted.
//
//**********************************************


#include "banking.h"

int main() {
    fstream AccountFile, TransactionFile, ReportFile; //file handles for account database, transaction and report
    const int MAX_ACCOUNTS = 100; // Maximum number of accounts
    string accountFile, transactionFile, reportFile; // complete names including file path
    double totalDeposits = 0.0, totalWithdrawals = 0.0, beginningBalance = 0.0, amount = 0.0; // all double variables initialized
    int numDeposits = 0, numWithdrawals = 0; //integer variables initialized
    int i; // for loop index
    char transaction ;      // 'd' or 'w'
    // prompt user to enter filepath
    cout << "Please enter the path to the database accounts file!" << endl; 
    accountFile = getFileName();
    openFile(accountFile, AccountFile); // open file

    int numAccounts; //number of entries
    AccountFile >> numAccounts; //read number of entries

    cout << "Number of entries : " << numAccounts << endl; //output database size


    if (numAccounts == 0 || numAccounts < 0) { //check for a valid number of entries
        cout << "Number of entries is invalid!\n " << endl;
    } 
    else {
        Account accounts[MAX_ACCOUNTS];

        for (i = 0; i < numAccounts; ++i) {
            AccountFile >> accounts[i].acct_num >> accounts[i].name;

        }

        AccountFile.close();
        for (i = 0; i < numAccounts; i++)
        {
            cout << accounts[i].acct_num << " " << accounts[i].name << endl;
        }




        cout << "Please enter the path to the accounts monthly transactions file!" << endl;
        transactionFile = getFileName();
        openFile(transactionFile, TransactionFile);
        int accountNum;

        for (i = 0; i < numAccounts; ++i) {
            TransactionFile >> accountNum >> beginningBalance;
            //accounts[i].acct_num = accountNum;
            accounts[i].beginning_balance += beginningBalance;



            while (!TransactionFile.eof()) {
                char look = TransactionFile.peek();
                if (look == '\n') {
                    break;
                }
                else if (look == ' ' || look == '\t') {
                    TransactionFile.ignore();
                }
                else {
                    TransactionFile >> transaction;
                    if (accounts[i].acct_num == accountNum) {
                        TransactionFile >> amount;
                        if (transaction == 'd') {
                            accounts[i].acct_bal += amount;

                            totalDeposits += amount;
                            accounts[i].total_deposits = totalDeposits;
                            numDeposits++;
                            accounts[i].num_deposits = numDeposits;

                        }
                        else if (transaction == 'w') {
                            accounts[i].acct_bal -= amount;
                            totalWithdrawals += amount;
                            accounts[i].total_withdrawals = totalWithdrawals;
                            numWithdrawals++;
                            accounts[i].num_withdrawals = numWithdrawals;
                        }
                    }
                    else {
                        cerr << "wrong format file!" << endl;
                        exit(1);
                    }
                }
            }

            accounts[i].ending_balance = accounts[i].acct_bal + accounts[i].beginning_balance;



            //print report to the console

            cout << " i : " << i << endl;
            cout << "Account number: " << accounts[i].acct_num << endl;
            cout << "Account: " << accounts[i].name << ", Account number: "
                << accounts[i].acct_num << ", Balance: $" << accounts[i].ending_balance << endl;
            cout << "Beginning Balance: $" << fixed << setprecision(2) << accounts[i].beginning_balance << "\n";
            cout << "Ending Balance: $" << fixed << setprecision(2) << accounts[i].ending_balance << "\n";
            cout << "Amount Deposited: $" << fixed << setprecision(2) << accounts[i].total_deposits << "\n";
            cout << "Number of Deposits: " << accounts[i].num_deposits << endl;
            cout << "Amount Withdrawn: $" << fixed << setprecision(2) << accounts[i].total_withdrawals << "\n";
            cout << "Number of Withdrawals: " << accounts[i].num_withdrawals << endl << endl;


            numDeposits = 0;
            numWithdrawals = 0;
            totalDeposits = 0.0;
            totalWithdrawals = 0.0;
        }

        TransactionFile.close();

        // Generate report file
        cout << "Please enter the path to the monthly report file" << endl;
        reportFile = getFileName();
        openFile(reportFile, ReportFile);
        for (i = 0; i < numAccounts; ++i) {
            ReportFile << "Name: " << accounts[i].name << "\n";
            ReportFile << "Account Number: " << accounts[i].acct_num << "\n";
            ReportFile << "Beginning Balance: $" << fixed << setprecision(2) << accounts[i].beginning_balance << "\n";
            ReportFile << "Ending Balance: $" << fixed << setprecision(2) << accounts[i].ending_balance << "\n";
            ReportFile << "Amount Deposited: $" << fixed << setprecision(2) << accounts[i].total_deposits << "\n";
            ReportFile << "Number of Deposits: " << accounts[i].num_deposits << endl;
            ReportFile << "Amount Withdrawn: $" << fixed << setprecision(2) << accounts[i].total_withdrawals << "\n";
            ReportFile << "Number of Withdrawals: " << accounts[i].num_withdrawals << endl << endl;

            numDeposits = 0;
            numWithdrawals = 0;
            totalDeposits = 0.0;
            totalWithdrawals = 0.0;
        }
        std::cout << "Monthly report generated successfully!" << std::endl;
        ReportFile.close();
    }
    
    

    cout << "\nPress any key to exit" << endl;
    cin.ignore();
    char ch = getchar();
    return 0;
}

