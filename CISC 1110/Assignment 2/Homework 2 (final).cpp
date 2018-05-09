#include <iostream>
#include <cmath>
using namespace std;
int main()

{
	int id, TP, wins, losses, nodecisions, numplayer, idb, idb2;
	double average, average2, average3, total, WIP, best, best2, avg;


    cout<<"This program takes the wins, losses,\n and no decisions and then add them up\nand computes the amout of total games\nplayed, how many games left in the season,\nthe average, and the WIP "<<endl;
    cout<<endl<< "Type a negitive number as player id number to close program"<<endl<<endl;
	cout<<"Please Enter Player ID Number: ";
	cin>>id;

	while (id>=0)
    {
    cout.setf(ios::fixed, ios::floatfield);
	cout.precision(0);

	cout<<"Please Enter Number of Wins: ";
	cin>>wins;
	cout<<"Please Enter Number of Losses: ";
	cin>>losses;
	cout<<"Please Enter Number of No Decisions: ";
	cin>>nodecisions;

        if (total<=30)
        {
        total=(wins+losses+nodecisions);
        }
    TP=30-total;
    numplayer++;
    cout<<endl<<endl<<endl<<"Pitcher "<<id<<endl
	<<wins<<" Wins  "<<losses<<" Losses  "<<nodecisions<<" No Decision"<<endl
	<<"Total Number of Games Pitched: "<<total<<"\t\t";

        if (TP==0)
        {
        cout<<"Pitcher Pitched A Full Season"<<endl;
        }
        else
        {
        cout<<TP<<" games still remaining "<<endl;
        }
	average=(wins)/(total);
	avg=(wins)/(total);
	cout.precision(4);

	cout <<"The Pitchers Winnig Average is: ";

        if (total==30)
        {
        cout<<avg;
        }
        else
        {
     cout<<average;
        }
     cout<<endl;

if (nodecisions>=wins)
cout<<"The Number of Games With No Decision are Greater or Equal to the Games Won."<<endl;
else
cout<<"The Number of Games With No Decision are Less to the Games Won."<<endl;

if (nodecisions>=losses)
cout<<"The Number of Games With No Decision are Greater Then the Games Lost."<<endl;
else
cout<<"The Number of Games With No Decision are Less Then the Games Lost."<<endl;


     WIP=(wins)+(nodecisions)-(losses*2 );
cout.precision(0);
if (WIP>=0)
cout<<"WIP is equal to "<<WIP<<endl<<endl;
else
 cout<<"WIP is equal to 0"<<endl<<endl;

 average2=(wins+(30-total))/((wins+(30-total))+losses+nodecisions) ;
 average3=(wins)/((wins)+losses+(30-total)+nodecisions) ;




if (total<30){

cout<<"Adding the extra games as wins"<<endl<<wins+(30-total)<<" Wins  "<<losses<<" Losses  "<<nodecisions<<" No Decisions";
 cout.precision(4);
 cout<< "\tPitching Average is "<<average2<<endl<<endl;


 cout.precision(0);

cout<<"Adding the extra games as losses"<<endl<<wins<<" Wins  "<<losses+(30-total)<<" Losses  "<<nodecisions<<" No Decisions";
 cout.precision(4);
 cout<< "\tPitching Average is "<<average3<<endl<<endl;
}

    cout.precision(4);

    best==0.0000;
    best2==0.0000;

	if(total==30) {

		if (avg<1){

			if (best<avg){
  			best=avg;
  			idb=id;
           	}}}

      else {

		  if (average<1){

			if (average>best2){
            best2=average;
            idb2=id;
			}}}

    cout<<endl<<"Please Enter Player ID Number: ";
	cin>>id;}
else{
	cout <<endl<<endl<< "ERROR:: DATA ENTERED WAS INSUFICENT \nPLEASE ENTER CORRECT DATA"<<endl<<endl;
	cout<<"Please Enter Player ID Number: ";
	cin>>id;
}}

  cout<<endl<<"Pitcher with Full Season "<<endl<<"Pitcher "<<idb<<" had the best average of "<<best<<endl<<endl;
  cout<<"Pitcher without Full Season "<<endl<<"Pitcher "<<idb2<<" had the best average of "<<best2<<endl<<endl;
  cout<<endl<<endl<<"Amount of pitchers procesed: "<<numplayer<<endl<<endl;
	cin.get();
	return(0);
	}
