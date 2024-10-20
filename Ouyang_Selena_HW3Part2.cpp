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
  float totalMoney, transactionAmount;  
  char typeofTransaction; 

  // open files
  inFile.open("userInput.txt");
  outFile.open("outData.txt");

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
      outFile << setw (1) << typeofTransaction << setw(16) << transactionAmount << setw(23) << totalMoney << endl; //prints type, amount, and remaining balance 
    }
    //else if the transactions is a withdrawal
    else if (typeofTransaction == 'W') {
      numWithdrawals++; //number of withdrawals increments by one
      totalMoney -= transactionAmount; //subtracts transaction amount from starting amount
      outFile << setw (1) << typeofTransaction << setw(16) << transactionAmount << setw(23) << totalMoney << endl; //prints type, amount, and remaining balance 
    }
  }
  
  //prints final balance, total withdrawals, total deposits, and total transactions
  outFile << endl << "Final Balance: $" << totalMoney << endl << "Total Withdrawals: " << numWithdrawals << endl << "Total Deposits: " << numDeposits << endl << "Total Transacitons: " << numTransactions;
  
  // close files
  inFile.close();
  outFile.close();

  return 0;
}
