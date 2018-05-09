/* 
Marc Pfeiffer          
Homework 1
due 2/17/15

This program will solve for x and get y. it will also tell us wheather y is 
negitive, positive, or zero. the opional 1 shows which value of x brings y closest to zero 
without acually hitting zero. opional 2 count how many times the y value is positive, negitive  or zero.
*/
#include <iostream>
#include <cmath>
using namespace std ;
int main()

{
	
double y, x, Lowest = 10, xval = 10;
int POSITIVE, NEGITIVE, ZERO;
POSITIVE=0;
NEGITIVE=0;
ZERO=0;

cout<< "\tMARC PFEIFFER-HOMEWORK # 1\n\nTHe purpose of this program is to input the values of x\n";
cout<< "into an equation and will tell us the y value \nand also tell us if y is positive, negitive or zero"<<endl<<endl;
cout<<"Value of X\t Value of Y\t Property of Y"<<endl<<endl;

for(x=-4;x<=3;x=x+.5)
	{

	y=(-4*(x*x*x)-(12*x*x)+x+15)/(sqrt(2*(x*x)+1)+7*abs(x-2.5));
	
	cout<<"X="<<x<<"\t\tY = "<<y<<"\t";
		
	if (y==0){
	cout<<"\tY is ZERO"<<endl;
	ZERO++;
	}
	
	if (y>0) {
	cout<<"Y is POSITIVE"<<endl;
	POSITIVE++;
	}

	if (y<0){
	cout<<"Y is NEGITIVE"<<endl;
	NEGITIVE++;}
	

	if (abs(y)<Lowest){
	Lowest=y;
	xval=x;	}
	
	}
cout<<endl<<"\tOPTIONAL # 1 \n"<<endl<<"X="<<xval<<"\t"<<"Y="<<Lowest<<"\tAmount to Zero  "<<abs(Lowest)<<endl<<endl;	

cout <<endl<<"\tOPTIONAL # 2\n"<<endl<< "POSITIVES:  "<< POSITIVE <<"\tNEGITIVES:  "<<NEGITIVE<<"\tZERO:  " <<ZERO<<endl<<endl;

cout<< "\tEND OF PROGRAM 1"<<endl<<endl;	

system("pause");
return 0;
}
	

	
