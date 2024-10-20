// Selena Ouyang
// HW3 Part II
// 10-16-2024

#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

int main() {

  ifstream inFile;  // input file stream variable
  ofstream outFile; // output file stream variable

  //assigning variables
  int numWithdrawals = 0, numDeposits = 0, numTransactions = 0; 
  float totalMoney, transactionAmount, depositAmount = 0, withdrawalAmount = 0;  
  char typeofTransaction; 

  // open files
  inFile.open("transaction.txt");
  outFile.open("Ouyang_Selena_outData.txt");

  //two decimal places
  outFile << fixed << setprecision(2); 

  //assign variable to inputs
  inFile >> totalMoney;
  outFile << "Starting Balance: " << '$' << totalMoney << endl << endl; //prints starting balance
  outFile << setfill('_') << setw(4) << "Type" << setw(13) << "Amount" << setw(23) << "Balance" << endl;

  //while loop to read in file
  while (!inFile.eof()) {

    inFile >> typeofTransaction >> transactionAmount; //reads transaction type and amount

    numTransactions++; //increments number of transactions by one

    //if the transactions is a deposit
    if (typeofTransaction == 'D') {
      numDeposits++; //number of deposits increments by one
      totalMoney += transactionAmount; //adds transaction amount to starting amount
      depositAmount += transactionAmount; //updates total deposit amount
      outFile << setw (1) << typeofTransaction << setw(16) << transactionAmount << setw(23) << totalMoney << endl; //prints type, amount, and remaining balance 
    }
    //else if the transactions is a withdrawal
    else if (typeofTransaction == 'W') {
      numWithdrawals++; //number of withdrawals increments by one
      totalMoney -= transactionAmount; //subtracts transaction amount from starting amount
      withdrawalAmount += transactionAmount; //updates total withdrawal amount
      outFile << setw (1) << typeofTransaction << setw(16) << transactionAmount << setw(23) << totalMoney << endl; //prints type, amount, and remaining balance 
    }
  }

  //prints information about final balance, withdrawals, deposits, transactions
  outFile << endl << "Final Balance: $" << totalMoney << endl << endl;
  outFile << "Number of Withdrawals: " << numWithdrawals << endl;
  outFile << "Total Withdrawl Amount: $" << withdrawalAmount << endl << endl;
  outFile << "Number of Deposits: " << numDeposits << endl;
  outFile << "Total Deposit Amount: $" << depositAmount << endl << endl;
  outFile << "Number of Total Transactions: " << numTransactions;

  // close files
  inFile.close();
  outFile.close();

  return 0;
}

/*
Starting Balance: $5000.00

Type_______Amount________________Balance
W__________200.00________________4800.00
W__________800.00________________4000.00
W___________40.00________________3960.00
D___________90.00________________4050.00
D__________100.00________________4150.00
D_________1000.00________________5150.00
W___________20.00________________5130.00

Final Balance: $5130.00

Number of Withdrawals: 4
Total Withdrawl Amount: $1060.00

Number of Deposits: 3
Total Deposit Amount: $1190.00

Number of Total Transactions: 7
*/
