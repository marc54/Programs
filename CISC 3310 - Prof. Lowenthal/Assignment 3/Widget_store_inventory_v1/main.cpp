#include <iostream>
#include <fstream>

ifstream dataIn("testIN.txt");
ofstream dataOut("output.txt");

struct Node{

    int amount;
    double price;
    Node *next;

};
class Shipment{

public:

    friend ifstream& operator >>(ifstream& dataIn, Shipment &order);
    char getType(){return type;}
    int getAmount(){return amount};
    double getValue(){return value;}

private:

   char type;
   int amount;
   double value;

};

ifstream& operator>> (ifstream &dataIn, Shipment &order){

    dataIn>>order.type;
    if (order.type == 'R'){
        dataIn>>order.amount>>order.value;
    }
    if (order.type == 'S'){
        dataIn>>order.amount;
    }
    if order.type == 'P'){
        dataIn>>order.price;
    }

    return dataIn;
}
using namespace std;
void insertAfter(Node, int, double);
int main()
{
    Shipment order;

    Node *linList;
    linList = new Node;
    linList->next = NUll;

    dataOut::setf(ios::fixed, ios::floatfield);
    dataOut.precision(2);

    int promo = 0;
    double promoVal = 0.00;

    while(dataIn.eof()){

        dataIn>>order;

        if(order.getType()=='R'){

            insertAfter(,order.getAmount(),order.getValue());
        }
        if(order.getType()== 'S'){

            subtract();
            promo -- ;
        }
        if(order.getType() == 'P'){

            promo = 2;
            promoVal = order.getValue();
        }
    }










    return 0;
}

void insertAfter(Node p , int x, double y){

Node *Q;
Q = new Node;
Q->amount = x;
Q->value = y;
Q->next = P->next;
P->next = Q;

}



