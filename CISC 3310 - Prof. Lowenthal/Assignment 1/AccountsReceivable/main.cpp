#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

struct Record{


 char transactionType;
 int customerNumber;
 string transactionNumber;
 double amount;
 int quantity;


 } ;

using namespace std;

int main()
{
    Record transactions;

    ofstream outfile("output.txt");
    ifstream transactionfile;
    ifstream masterfile;

    transactionfile.open ("transactionFile.txt");
    masterfile.open("masterFile.txt");

    transactionfile>>transactions.customerNumber;

    outfile<<transactions.customerNumber;
 if (masterfile)
    {
    while (getline(masterfile, transactions.customerNumber ))
      {
      if (transactions.customerNumber == something)
        {
        ...
        }
      }
    masterfile.close();
    }
while (getline(transactionfile, line)){



}
    return 0;
}
