//Selena Ouyang
//HW 3
//10-15-2024 

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main () {

    ifstream inFile; //input file stream variable
    ofstream outFile; //output file stream variable

    double totalMoney; //variable for total money 
	int numTransactions; //variable for number of transactions
	char typeTransaction; //variable for typeTransaction
	double amount;   //variable for amount for debit and/or credit
	char Debit; //sets variable, Debit, equal to 'D'
	char Credit; //sets variable Credit equal to 'C'
	double totalDebit = 0.00; //sets starting debit amount to 0
	double totalCredit = 0.00; //sets staring credit amount to 0

    //open files
    inFile.open("inData.txt"); 
    outFile.open("outData.txt");
	
    inFile >> "How much money was in your bank account at the start of the day?";
    inFile >> "How many bank transactions were done?" << endl; //user direction to input number of bank transactions
	
    
    inFile.close();
    outFile.close ();

/*
	while (numTransactions > 0) //while the number of transactions is greater than 0, the loops runs
	{
		cout << "Type of Transaction. Enter D for Debit and C for Credit." << endl; //directions for user to enter 'D' or 'C'
		cin >> typeTransaction;
		cout << "Enter amount of Transaction:" << endl; //direction to enter amount of transaction
		cin >> amount;
		
		//if the transaction is debit:
		if (typeTransaction == Debit)
		{
			cout << "Total: $" << totalMoney - amount << endl;
			totalMoney = totalMoney - amount; //updates starting amount after each transaction. Subtracts deposit from total
			totalDebit = totalDebit + amount; //updates the total debit after each transaction. Adds this deposit to deposit total 
		}

        //if the transaction is credit:
		if (typeTransaction == Credit)
		{
		    cout << "Total: $" << totalMoney + amount << endl;
			totalMoney = totalMoney + amount; //updates starting amount after each transaction. Adds credit from total
			totalCredit = totalCredit + amount; //updates the total credit after each transaction. Adds this credit to credit total 
		}
		
		cout << "Number of Transactions left: " << numTransactions - 1 << endl << endl; //Displays number of transactions left

		numTransactions = numTransactions - 1; //subtracts 1 from the total transactions. Shows that 1 transactions is completed
    	}

	cout << "Total: $" << totalMoney << endl; //prints out "Total: $"
	cout << "Total Debit Amount: $" << totalDebit << endl; //prints out "Total Debit Amount: $" followed by the total debit 
	cout << "Total Credit Amount: $" << totalCredit << endl; //prints out "Total Credit Amount: $" followed by the total credit 
	*/
return 0;


}
