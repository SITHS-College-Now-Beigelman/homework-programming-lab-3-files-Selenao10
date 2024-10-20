// Selena Ouyang
// HW3 Part I
// 10-16-2024

#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

int main() {

  ifstream inFile;  // input file stream variable

  //assigning variables
  float totalMoney, numTransactions, transactionAmount;  
  char typeofTransaction; 

  // open files
  inFile.open("Ouyang_Selena_transaction.txt");

  inFile >> totalMoney; //Assigns variable to input
  cout << fixed << setprecision(2); //two decimal places
  cout << "Starting Balance: " << totalMoney << endl << endl; //prints starting balance

  //runs the code until it reaches 7 transactions
  for (numTransactions = 0; numTransactions < 7; numTransactions++) 
  {
    inFile >> typeofTransaction >> transactionAmount; //order that variables are assigned to the variables in the inputs

    //if the type of transaction is a withdrawal, transaction amount is subtracted from tota
    if (typeofTransaction == 'W') {
      cout << "Amount of Transaction: " << -transactionAmount << endl;
      cout << "Balance after transaction: " << totalMoney - transactionAmount << endl; 
      totalMoney = totalMoney - transactionAmount;
      transactionAmount = 0; //resets transaction amount to 0
      } 

    //else if the type of transaction is a deposit, transaction amount is added to total
    else if (typeofTransaction == 'D') {
      cout << "Amount of Transaction: " << transactionAmount << endl;
      cout << "Balance after transaction: " << totalMoney + transactionAmount << endl; 
      totalMoney = totalMoney + transactionAmount;
      transactionAmount = 0; //resets transaction amount to 0
    }
  }
    //Prints ending balance
    cout << endl << "Ending Balance: " << totalMoney << endl; 

  // close files
  inFile.close();

  return 0;
}

/*
Starting Balance: 5000.00

Amount of Transaction: -200.00
Balance after transaction: 4800.00
Amount of Transaction: -800.00
Balance after transaction: 4000.00
Amount of Transaction: -40.00
Balance after transaction: 3960.00
Amount of Transaction: 90.00
Balance after transaction: 4050.00
Amount of Transaction: 100.00
Balance after transaction: 4150.00
Amount of Transaction: 1000.00
Balance after transaction: 5150.00
Amount of Transaction: -20.00
Balance after transaction: 5130.00

Ending Balance: 5130.00
*/
