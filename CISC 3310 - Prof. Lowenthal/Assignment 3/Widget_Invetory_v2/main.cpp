#include <iostream>
#include <fstream>

using namespace std;

ifstream inFile("inputFile.txt");
ofstream outFile("outputFile.txt");

class Shipment{

public:
    friend ifstream& operator >> (ifstream& inFile, Shipment& order);
    char getType(){return type;}
    int getAmount(){return amount;}
    double getPrice(){return price;}

private:
    char type;
    int amount;
    double price;
};

ifstream& operator >>(ifstream& inFile, Shipment& order){

    inFile>>order.type;

    if(order.type == 'R')
        inFile>>order.amount>> order.price;
    if(order.type == 'S'){
        inFile>>order.amount;
        order.price = 0.00;
    }
    if(order.type == 'P'){
        inFile>>order.price;
        order.amount = 0;
    }
    return inFile;
}

class Node{

public:
    Node();
    Node(  Shipment&);
    Node operator = ( const Node&);
    Node(   Node &);
   // void insertNode(Node &, Shipment& );



    int amount;
    double pricePerUnit;
    Node *next;

};

Node::Node(){

    amount = 0;
    pricePerUnit = 0.00;
    next = NULL;


}
Node::Node( Shipment& obj){

    Node *p;
    p = new Node;
    p->amount = obj.getAmount();
    p->pricePerUnit = obj.getPrice();
    p->next = NULL;


}

 Node::Node( Node &obj ){

    amount = obj.amount;
    pricePerUnit= obj.pricePerUnit;
    next = obj.next;


}

Node Node::operator=(const Node &obj){

    delete next;
    amount = obj.amount;
    pricePerUnit= obj.pricePerUnit;
    next = obj.next;

    return *this;
}

void insertNode(Node &rear, Shipment& obj){

    Node *p;
    p = new Node();
    p->amount= obj.getAmount();
    p->pricePerUnit = obj.getPrice();
    p->next = NULL;
    rear.next = p;



}



int main()
{

    Shipment order;
    Node List , rear;
    List.next = NULL;
    rear = List;

    while( !inFile.eof()){

        inFile>>order;

        if(order.getType() == 'R'){

            if(List.next == NULL){
                List = Node(order);
            }
            else{

                insertNode(rear , order);
            }
        }

            Node p;
            p = List;
            while(p.next != NULL){
            cout<<"LOL";
            p = *p->next;

            }




    }





    return 0;
}
