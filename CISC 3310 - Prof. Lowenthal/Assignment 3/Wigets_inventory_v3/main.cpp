#include <iostream>
#include <fstream>


using namespace std;

ifstream input("infile.txt");
ofstream output("outfile.txt");



class Shipment{

public:

    friend ifstream & operator >> (ifstream &input, Shipment & order);
    char getType(){return type;}
    int getAmount() {return amount;}
    double getPrice() {return priceOrPromo;}

private:

    char type;
    int amount;
    double priceOrPromo;

};

ifstream & operator >>(ifstream& input , Shipment   &order){

    input>>order.type;

    if(order.getType()=='R'){
        input>>order.amount>>order.priceOrPromo;
    }
    if(order.getType()=='S'){
        input>>order.amount;
        order.priceOrPromo = 0.00;
    }
    if(order.getType()=='P'){
        input>>order.priceOrPromo;
        order.amount = 0;
    }

    return input;
}


class Node{

public:

    Node* getNode( Shipment&);
   // Node* insertNode(Node *, Shipment &);
    int amount;
    double price;
    Node *next;

};
//Node& Node::operator = (const Node &node ){
// amount = node.amount;

//}
 Node* insertNode(Node *rear, Shipment &obj){

    Node *p;
                p = new Node;
                p->amount = obj.getAmount();
                p->price = obj.getPrice();
                p->next = NULL;
                rear->next = p;
                rear = p;
        return rear;
}

Node* Node::getNode(Shipment& obj){

        Node *p;
        p= new Node;
        p->amount = obj.getAmount();
        p->price = obj.getPrice();
        p->next = NULL;

        return p;


}

int main()
{
    Shipment order;
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);

    Node *root = NULL, *rear,  *p;

    int promoNum=0;
    double promoVal = 1.00;

    while(!input.eof()){
        p= root;
        input>> order;


        if(order.getType() == 'R'){
            cout<<"Order Received "<< order.getAmount()<<" Widgets at a cost of $"<<order.getPrice()<<"per Widget\n\n";
            if(root == NULL){

                /*root = new Node;
                root->amount = order.getAmount();
                root->price = order.getPrice();
                root->next = NULL;
                rear = root;*/

                root = root->getNode(order);
                rear = root;



            }
            else {

             insertNode(rear, order);


            }
        }
while(j!= NULL){
    cout<<p->amount<<" ";
    p= p->next;

}

       /*  if(order.getType() == 'S'){

            int sold = order.getAmount();
            int need = sold;
            double sales = 0.00;


            while(need != 0){


                if(root->amount >= need){

                    if(root->amount == sold){

                        if(promoNum == 0){
                            promoVal = 1.00;
                        }

                        sales +=((root->price *1.30)*sold);

                        cout<<order.getAmount()<<" at "<<(root->price * 1.30)<<" each\tSales: $ "<<((root->price *1.30)*sold)*promoVal;
                        cout<<"\n\n\t\t\tTotal Sales: $"<<sales<<endl<<endl;

                        promoNum --;

                        if(root->next==rear->next){
                            root = NULL;

                        }
                        else{


                        root = root->next;


                        }

                    }
                    else{

                        if(promoNum == 0){
                            promoVal = 1.00;
                        }

                        sales +=((root->price *1.30)*sold);

                        cout<<order.getAmount()<<" at "<<(root->price *1.30)<<" each\tSales: $ "<<((root->price*1.30)*sold)*promoVal;
                        cout<<"\n\n\t\t\tTotal Sales: $"<<sales<<endl<<endl;

                        promoNum --;

                        root->amount -= need;
                    }
                    need = 0;
                }

             else{

                if(promoNum == 0){
                    promoVal = 1.00;

                }
                promoNum--;
                cout<< root->amount<<" at  "<<(root->price *1.30)<<" each\tSales: $ "<<((root->price*1.30)*sold)*promoVal;




                    need -= root->amount;

                    if(root->next==rear->next){
                            root = NULL;
                            cout<<"\nremainder of "<< need <<" is currently unavailable\n";
                            need = 0;
                        }
                        else{


                        root = root->next;


                        }
                cout<<"test";
             }


            }

         }
            if(order.getType() == 'P'){
            cout<<"Promotion Card entered "<<order.getPrice()*100<<"% off\n\n";
                promoNum = 2;
                promoVal = order.getPrice();

            }*/



    }










    return 0;
    }
