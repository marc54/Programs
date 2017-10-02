///Marc Pfeiffer
///Assignment 4 - Trees

#include <iostream>
#include <fstream>

using namespace std;

ifstream dataIn("infile.txt");
ofstream dataOut("outfile.txt");


class Node{

public:
    int num;
    Node* left;
    Node* right;
    Node* father;
};

Node* makeTree(int );
void setLeft(Node* , int );
void setRight(Node* , int );
void inTrav(Node*  );
void preTrav(Node* );
void postTrav(Node*  );
int countTrav(Node* );
void children(Node* );
void insrt(Node *, int );
int findSmallest(Node *);
void removeNode(Node *, int );
void removeRootNode(Node* );
void removeMatch(Node*, Node*, bool);

///Makes tree
Node* makeTree(int x){

    Node* p;
    p = new Node;
    p->num = x;
    p->right=NULL;
    p->left =NULL;
    p->father = NULL;

    return p;
}

///Sets node to left Son
void setLeft(Node* p, int x){

    Node* Q;
    Q = new Node;
    Q->num = x;
    Q->right = NULL;
    Q->left = NULL;
    Q->father = p;
    p->left = Q;

}

///Sets node to right Son
void setRight(Node* p, int x){

    Node* Q;
    Q = new Node;
    Q->num = x;
    Q->right = NULL;
    Q->left = NULL;
    Q->father = p;
    p->right = Q;


}

///prints out tree in-order
 void inTrav(Node* p ){

    if(p != NULL){

        inTrav(p->left);
        dataOut<<p->num<<" ";
        inTrav(p->right);

    }
 }

///prints out tree Pre-Order
void preTrav(Node* p ){

    if(p!= NULL){

        dataOut<<p->num<<" ";
        preTrav(p->left);
        preTrav(p->right);

    }
 }

///Prints out tree post-order
 void postTrav(Node* p ){

    if(p!= NULL){

        postTrav(p->left);
        postTrav(p->right);
        dataOut<<p->num<<" ";

    }
 }

///counts Number of Nodes
 int countTrav(Node* p){

    int counter=0;

    if(p){

        counter += countTrav(p->left) ;
        counter +=countTrav(p->right) ;

        counter++;

    }

    return counter;
 }

///prints out how many children each node has
 void children(Node* p){

    if(p!= NULL){
        children(p->left);
    if(p->left != NULL && p->right != NULL){
        dataOut<<"Node "<<p->num<<" has 2 childern"<<endl;
    }
    else if((p->left == NULL && p->right != NULL)||(p->left != NULL && p->right == NULL) ){
        dataOut<<"Node "<<p->num<<" has 1 child"<<endl;

    }
    else{
        dataOut<<"Node "<<p->num<<" has 0 children"<<endl;
    }
        children(p->right);
    }
 }
///insert function
void insrt(Node *Tree, int x){
    Node *Q, *P;
    Q = P = Tree;
    if(Tree == NULL){
        Tree = makeTree(x);
        return;
    }

    while((x!= P->num) &&( Q!= NULL)){

        P=Q;
        if(x< P->num){
            Q= Q->left;

        }
        else{
            Q=Q->right;
        }
    }
         if(P->num==x){

           dataOut<<"Duplicate";

        }
        else  if( x  < (P->num)){
            setLeft(P,x);
        }
        else{
            setRight(P,x);
    }



}

/// find the smallest Node
int findSmallest(Node *Tree){

    if(Tree == NULL){

        dataOut<<"tree is empty"<<endl;
        return -9999;

    }
    else{

        if(Tree->left!=NULL){

            return findSmallest(Tree->left);
        }
        else{

            return Tree->num;
        }
    }
}

///remove node if its the root
void removeRootNode(Node* root){

    if(root!=NULL){

        Node* delptr = root;
        int value = root->num;
        int smallest;

        if(root->left == NULL && root->right == NULL){

            root =NULL;
            delete delptr;
        }
        else if(root->left == NULL && root->right != NULL){

            root = root->right;
            delptr->right = NULL;
            root->father = NULL;
            delete delptr;

        }
        else if(root->left != NULL && root->right == NULL){

            root = root->left;
            delptr->left = NULL;
            root->father = NULL;
            delete delptr;

        }
        else{

            smallest = findSmallest(root->right);
            removeNode(root, smallest);
            root->num = smallest;
        }


    }
    else{

        dataOut<<"Cannot remove, Tree is already empty\n";
    }

}

///remove node decides which remove function to use
void removeNode(Node *root, int value){

   if(root!=NULL){

        if(root->num == value){

            removeRootNode(root);
        }
        else{

            if(value < root->num && root->left != NULL){

                if(root->left->num == value){

                    removeMatch(root, root->left, true);
                }
                else{
                    removeNode(root->left, value);
                }
            }
            else if( value> root->num && root->right != NULL){

                if(root->right->num == value){

                    removeMatch(root, root->right , false);

                }
                else {

                    removeNode(root->right, value);
                }
            }
            else{
                dataOut<<value<<" doesnt exsist withing Tree\n";
            }
        }

   }
   else{

    dataOut<<"The tree is Empty\n";
   }
}

///remove a non-root
void removeMatch(Node* root, Node* match, bool left){

    if(root != NULL){

        Node* delptr;
        int matchValue =match->num;

        if(match->left == NULL && match->right == NULL){

            delptr = match;
            if(left == true){
                root->left = NULL;
            }
            else{
                root->right = NULL;
            }
            delete delptr;

        }
        else if(match->left == NULL && match->right != NULL){


            if(left == true){
                root->left = match->right;
            }
            else{
                root->right = match->right;
            }
            match->right = NULL;
            match->father =NULL;
            delptr= match;
            delete delptr;

        }
           else if(match->left != NULL && match->right == NULL){


            if(left == true){
                root->left = match->left;
            }
            else{
                root->right = match->left;
            }
            match->left = NULL;
            match->father = NULL;
            delptr= match;
            delete delptr;

        }
        else{
            int smallest = findSmallest(match->right);
            removeNode(match, smallest);
            match->num = smallest;
        }


    }

    else{
        dataOut<<"cannot remove, no Match";
    }


}


int main()
{
    int value;


while(!dataIn.eof()){

    Node *Tree = NULL;
    dataIn>>value;
    dataOut<<"\t\t\t\tNEW SET OF DATA\n\n\n\n\n";

    while(value != -999){

        if(Tree == NULL){
            Tree = makeTree(value);
        }
        else{
            insrt(Tree, value);
        }
        dataIn>>value;
    }

    dataOut<<"\nINORDER   ::  ";inTrav(Tree);dataOut<<endl<<endl;
    dataOut<<"PREORDER  ::  ";preTrav(Tree); dataOut<<endl<<endl;
    dataOut<<"POSTORDER :: ";postTrav(Tree);dataOut<<endl<<endl;


    int amount = countTrav(Tree);

    dataOut<<"There are "<<amount<<" nodes in this tree"<<endl<<endl;

    children(Tree);

    string what;
    dataIn>>what;

    while(what != "new_set"){

        dataIn>>value;
        if(what == "insert"){

            insrt(Tree, value);

        }
        else if(what == "delete"){

            removeNode(Tree, value);

        }

        dataIn>>what;

    }

    dataOut<<"\nINORDER   ::  ";inTrav(Tree);dataOut<<endl<<endl;
    dataOut<<"PREORDER  ::  ";preTrav(Tree); dataOut<<endl<<endl;
    dataOut<<"POSTORDER :: ";postTrav(Tree);dataOut<<endl<<endl;
    amount = countTrav(Tree);

    dataOut<<"There are "<<amount<<" nodes in this tree"<<endl<<endl;

    children(Tree);

    delete Tree;
    dataOut<<"\n\n\n\n\n";
    }




    return 0;
}

