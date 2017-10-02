#include <iostream>
#include <fstream>
#include <string>



using namespace std;

class Shipment{

public:

 char type;
 string city;
 int amt1;
 int amt2;
 int amt3;

};
int main()
{
    Shipment log;
    double price1 = 2.00, price2 = 7.00, price3 = 8.50;
    int warehouse[5][3];

    /// set the warehouse to be empty
    for(int i=0; i<5 ; i++){
        for(int j = 0; j<3; j++){
            warehouse[i][j] = 0;
        }
    }

    ///ifstream infile(shipmentl.txt);
    ifstream input;
    input.open("shipmentLog.txt");
    ///ofstream outfile(outfile.txt);
    ofstream outfile("outputfile.txt");
    ///while(infile)
    while(input){
    /// read in first line to object
    input>>log.type>> log.city>>log.amt1>>log.amt2>>log.amt3;
    /// find correct city to put in
switch (log.city){

case "Chicago":
    int arraynum = 0;
    if(log.type=='o'){
        subtractFunct(warehouse, arraynum ,log.am1, log.amt2, log.amt3);
    }
    else{
        addFunct(warehouse, arraynum ,log.amt1,log.amt2, log.amt3);
    }
      break;
case "Houston":
    int arraynum = 1;
    if(log.type=='o'){
        subtractFunct(warehouse, arraynum ,log.am1, log.amt2, log.amt3);
    }
    else{
        addFunct(warehouse, arraynum ,log.amt1,log.amt2, log.amt3);
    }
      break;

case "LasAngeles":
    int arraynum = 2;
    if(log.type=='o'){
        subtractFunct(warehouse, arraynum ,log.am1, log.amt2, log.amt3);
    }
    else{
        addFunct(warehouse, arraynum ,log.amt1,log.amt2, log.amt3);
    }
      break;

case "Miami":
    int arraynum = 3;
    if(log.type=='o'){
        subtractFunct(warehouse, arraynum ,log.am1, log.amt2, log.amt3);
    }
    else{
        addFunct(warehouse, arraynum ,log.amt1,log.amt2, log.amt3);
    }
      break;

case "NewYork"
int arraynum = 4;
    if(log.type=='o'){
        subtractFunct(warehouse, arraynum ,log.am1, log.amt2, log.amt3);
    }
    else{
        addFunct(warehouse, arraynum ,log.amt1,log.amt2, log.amt3);
    }
      break;
}
    ///if s +
    /// if o -
    /// if not enough check for most
    /// add 10% of cost
    /// if none  ship without that object
   }
    ///infile.close();
    ///outfile.close();
    return 0;
}

void subtractFunct ( int arr[5][3], int place, int amt1, int amt2, int amt3 double price1,double price2, double price3){

    if(arr[place][1]>amt1){
        arr[place][1]=arr[place][1]-amt1;

    }
    else {

        takeFromLargest(arr, place, price1 amt1);
    }
}

void takeFromLargest(int arr[5][3], int place; int price,  int amout){
largest == arr[place][0];
for(int i=1 ; i<5; i++){
    if(arr[place][i]> largest){
        largest = arr[place][i];
        int placeholder = i;
    }
}
 if (largest>= amount){
    arr[place][placeholder]=arr[place][placeholder]-amount;
    outfile<<"order sent from different warehouse customer charged"<<(amount*price)*1.10;
 }
else
    outfile<<"order is unfilled of item "<< place + 1<<"\n";
}

void addFunct(int arr[5][3], int place , int amt1,int amt2, int amt3){

arr[place][0] += amt1;
arr[place][1] += amt2;
arr[place][2] += amt3;
}
