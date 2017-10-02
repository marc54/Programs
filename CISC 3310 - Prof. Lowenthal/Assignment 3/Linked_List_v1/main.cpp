///Marc Pfeiffer
///Assignment 3 - Widgets Inventory
#include <iostream>
#include <fstream>

using namespace std;

ifstream dataIn("infile.txt");
ofstream dataOut("outfile.txt");


struct Node{

    int amount;
    double price;
    Node* next;

};

class Shipment{

public:

    friend ifstream & operator>> (ifstream & dataIn , Shipment& order);
    char getType(){return type;}
    int getAmount(){return amount;}
    double getPrice() {return price;}

private:

    char type;
    int amount;
    double price;

};

///Overloaded ifstream operator
ifstream& operator >>(ifstream& dataIn, Shipment& order){

    dataIn>>order.type;

    if(order.type == 'R'){

        dataIn>>order.amount>>order.price;

    }
    else if(order.type == 'S'){

        dataIn>>order.amount;

    }
    else{

        dataIn>>order.price;

    }
    return dataIn;

}

bool isEmpty( Node* head);
void insertFirstNode(Node* &head, Node* &last, Shipment &order);
void insertNode(Node* &head, Node* &last, Shipment& obj);
void removeNode(Node *&head, Node* &last, Shipment &obj);
void printList(Node *current);

///Checks to see if List is empty
bool isEmpty(Node* head){

    if(head == NULL){
        return true;
    }
    else {
        return false;
    }


}

///Inserts the first Node in list  if empty
void insertFirstNode(Node* &head, Node* &last, Shipment &obj){

    Node *temp = new Node;
    temp->amount = obj.getAmount();
    temp->price = obj.getPrice();
    temp->next = NULL;
    head = temp;
    last = temp;
}

///Inserts Node in rear of list
void insertNode(Node* &head, Node* &last, Shipment& obj){

    if( isEmpty(head) ){

        insertFirstNode(head, last , obj);
    }
    else{

        Node *temp = new Node;
        temp->amount = obj.getAmount();
        temp->price = obj.getPrice();
        temp->next = NULL;
        last->next = temp;
        last = temp;

    }
}

///pops node off front of List
void removeNode(Node* &head, Node* &last, Shipment& obj){

    if(isEmpty(head)){

        dataOut<<"The List is Empty\n";
    }
    else if(head == last){

        delete head;
        head = NULL;
        last = NULL;
    }
    else {

        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

///prints out current status of List
void printList(Node* current){

    if(isEmpty(current)){

        dataOut<<"The List is empty\n";
    }
    else{

        dataOut<<"CURRENT STOCK\n\n";
        while(current != NULL){

            dataOut<<current->amount<<" at "<<current->price<<endl;
            current = current->next;
        }
    }

}

int main(){

    Shipment order;
    Node *List = NULL, *Rear=NULL;

    dataOut.setf(ios::fixed ,ios::floatfield);
    dataOut.precision(2);

    int amountNeeded = 0, promotionVal= 0;
    double totalPrice, promotion=1.00;

    while(!dataIn.eof()){

        dataIn>>order;

        ///if receive order
        if(order.getType()=='R'){

            dataOut<<"Order of "<<order.getAmount()<<" Widgets at $"<<order.getPrice()<<" per piece has been received\n\n\n\n";
            insertNode(List, Rear, order);

        }

        ///if sales record
        else if(order.getType() == 'S'){

            amountNeeded = order.getAmount();

            if(isEmpty(List)){

                dataOut<<"\nRemainder of "<<amountNeeded<<" Widgets, not available\n\n";

            }

            else{

                totalPrice = 0.00;

                if(order.getAmount() > List->amount){

                    dataOut<<amountNeeded<<" widgets ordered\n";
                    dataOut<<List->amount<<" at "<<(List->price*1.30)<<" each\t Sales: $"<<(List->price*1.30)*List->amount<<endl;
                    totalPrice += ((List->price*1.30)*List->amount);
                    amountNeeded -= List->amount;

                    while(amountNeeded != 0){

                        removeNode(List, Rear , order);

                        if(!isEmpty(List)){

                            if(amountNeeded > List->amount){

                                dataOut<<List->amount<<" at "<<(List->price*1.30)<<" each\t Sales: $"<<(List->price*1.30)*List->amount<<endl;
                                totalPrice += ((List->price*1.30)*List->amount);
                                amountNeeded -= List->amount;
                            }
                            else{

                                List->amount -= amountNeeded;
                                dataOut<<amountNeeded<<" at "<<List->price*1.30<<" each\t Sales: $"<<(List->price*1.30)*amountNeeded<<endl;
                                totalPrice += ((List->price*1.30)*amountNeeded);
                                amountNeeded = 0;

                            }
                        }

                        else{

                            dataOut<<"\nRemainder of "<<amountNeeded<<" Widgets, not available\n\n";
                            amountNeeded = 0;
                        }
                    }

                    if(promotionVal != 0){
                        dataOut<<"\t\t   Total Sales: $"<<totalPrice*promotion<<endl<<endl<<endl;
                        promotionVal --;
                    }

                    else{
                        dataOut<<"\t\t   Total Sales: $"<<totalPrice<<endl<<endl<<endl;
                    }
                }

            else if(order.getAmount() == List->amount){

                dataOut<<amountNeeded<<" widgets sold\n";
                dataOut<<List->amount<<" at "<<(List->price*1.30)<<" each\t Sales: $"<<(List->price*1.30)*List->amount<<endl;
                totalPrice += ((List->price*1.30)*List->amount);
                removeNode(List, Rear, order);

                if(promotionVal != 0){

                        dataOut<<"\t\t   Total Sales: $"<<totalPrice*promotion<<endl<<endl<<endl;
                        promotionVal --;
                    }

                    else{
                        dataOut<<"\t\t   Total Sales: $"<<totalPrice<<endl<<endl<<endl;
                    }
            }
            else{

                dataOut<<amountNeeded<<" widgets sold\n";
                List->amount -= amountNeeded;
                dataOut<<amountNeeded<<" at "<<List->price*1.30<<" each\t Sales: $"<<(List->price*1.30)*amountNeeded<<endl;
                totalPrice += ((List->price*1.30)*amountNeeded);
                if(promotionVal != 0){
                        dataOut<<"\t\t   Total Sales: $"<<totalPrice*promotion<<endl<<endl<<endl;
                        promotionVal --;
                    }
                    else{
                        dataOut<<"\t\t   Total Sales: $"<<totalPrice<<endl<<endl<<endl;
                    }
                }
            }


        }
        ///If promotional was used
        else{

            promotion = order.getPrice();
            promotionVal = 2;
            dataOut<<"Promotional discount of "<<promotion*100<<"% has been applied for the next 2 orders out\n\n";

        }
    }


    printList(List);

    return 0;
}

