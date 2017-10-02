///Marc Pfeiffer
///Assignment 1 - Accounts/Receivable

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Customer{

public:

    Customer();
    friend ifstream& operator >>(ifstream &masterFile, Customer& info);
    int getNum(){return number;}
    string getName(){return name;}
    double getBal(){return previousBalance;}

private:

    int number;
    string name;
    double previousBalance;

};

///Constructor for Customer
Customer::Customer(){

    number=0;
    name ="";
    previousBalance = 0.00;
}

///Overloaded in-file Operator to read in each line from master file.
ifstream & operator >> (ifstream &masterFile, Customer &info){

    masterFile>>info.number>>info.name>>info.previousBalance;
    return masterFile;
}

class Record{

public:

    Record();
    friend ifstream& operator >>(ifstream &transactionFile, Record& accounts);
    int getCustNumb(){return custNumb;}
    int getTransNumber(){return transNumb;}
    double getAmount(){return (price*quantity);}
    char getTransType(){return transType;}
    string getItem(){return object;}

private:

    int custNumb;
    int transNumb;
    char transType;
    string object;
    double price;
    int quantity;
};

///Constructor for Record class
Record::Record(){

    custNumb=transNumb=quantity = 0;
    transType='a';
    object="";
    price=0.00;
}

///Overloaded in-file Operator reads in data from transaction file
ifstream & operator >>(ifstream &transactionFile, Record &accounts){

    transactionFile >> accounts.custNumb>>accounts.transNumb>> accounts.transType;

    if (accounts.transType=='o'){
        transactionFile>>accounts.object>>accounts.price>>accounts.quantity;
    }
    else{
        transactionFile>>accounts.price;
        accounts.quantity = 1;
    }

    return transactionFile;
}


int main()
{
    Record accounts;
    Customer info;
    double balance=0.00;
    int checker=0;

    ifstream transactionFile;
    ifstream masterFile;
    ofstream outpufFile("output.txt");
    outpufFile.precision(9);

    transactionFile.open("transfile.txt");

    transactionFile>>accounts;

    /// loops till the end of transaction file
    while (!transactionFile.eof()){

        ///if line started with a new number that was not used before
        if(accounts.getCustNumb() != checker){

            checker = accounts.getCustNumb();

            masterFile.open("masterfile.txt");
            masterFile>>info;

            /// searches for correct customer info
            while(info.getNum() != accounts.getCustNumb()){

                masterFile>>info;
            }

            balance = info.getBal();
            masterFile.close();

            outpufFile<<"CUSTOMER: "<<info.getName()<<" "
            <<"\tCUSTOMER ID: "<<info.getNum()
            <<"\n\n\t\t\tPREVIOUS BALANCE $"<<info.getBal()<<"\n\n";
        }

        ///continues printing out different transactions for same customer
        ///until the customer id changes
        while(accounts.getCustNumb() == checker){

            outpufFile<<accounts.getTransNumber()<<"\t";

            /// if transaction is  an order
            if(accounts.getTransType() == 'o'){

                outpufFile<<accounts.getItem()<<"\t\t"<<accounts.getAmount()<<endl;
                balance= balance + accounts.getAmount();
            }

            /// if transaction is a payment
            else{

                outpufFile<<"PAYEMENT\t$"<<accounts.getAmount()<<endl;
                balance = balance - accounts.getAmount();
            }
            transactionFile>>accounts;

        }

        outpufFile<<"\n\t\t\tBalance Due: $"<<balance<<"\n\n";

   }

return 0;
}
