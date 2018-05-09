//Marc Pfeiffer
//Homework 3


//This program will read in 3 numbers at a time
//and will determine which of them is the smallest.
//It will then print a message the amount of
//times that the smallest number is.
//(only if between 1 and 10). The program also
//prints out how many times the program ran.
//Look in homework_3.txt to see results.
//Enter  three numbers that add up to 0 to exit program:

#include <iostream>
#include <fstream>
#include <cmath>

void introduction();                        //Function Prototype 1
int findsmallest(int, int, int);            //Function Prototype 2
void printmessage(int);                     //Function Prototype 3
int mymsg(int, int&);                       //Function Prototype 4 - Optional 1
void smllrg(int, int&,int&);                //Function Prototype 5 - Optional 2

using namespace std;
ofstream outfile("homework_3.txt");
int main()
{
    int a, b, c, d, e;
    int timesrun=0, msg=0;
    int lrg=-100000000, sml=100000000;

    //Step 0
    //introduction

    introduction();

    //step 1
    //Read in 3 intergers
    //and print them out.

    cout<<"Please Enter First Number: ";
    cin>>a;
    cout<<"Please Enter Second Number: ";
    cin>>b;
    cout<<"Please Enter Third Number: ";
    cin>>c;
    cout<<endl;

    //Step 4
    //while loop steps 1,2, and 3

    e=a+b+c;

    //if you add the 3 numbers and
    // it equals zero the program will shut off

            while (e != 0)
            {

            outfile<<"the three intergers are "<<a<<"  "<<b<<"  "<<c<<endl;

            //Step 2
            //Program calls function findsmallest
            //which finds the smallest integer
            //and sends answer back to program.

            d=findsmallest(a, b ,c);

            outfile<<d<<" is the smallest integer."<<endl;

            //Step 3
            //Program calls a function printmessage


            printmessage(d);
            outfile<<endl;

            //Step 5
            //count amount of time data was run.

            timesrun++;

           //Opional 1
           //calls a function which counts the
           //number of times the message is printed

            mymsg(d, msg);

            //Optional 2
            //calls a functio to find the largest smallest inerger
            //and the smallest, smallest interger

            smllrg(d, lrg, sml);

            //step 1
            //Read in 3 intergers
            //and print them out.

            cout<<"Enter three numbers that add up to zero to exit program: "<<endl<<endl<<endl;

            cout<<"Please Enter First Number: ";
            cin>>a;
            cout<<"Please Enter Second Number: ";
            cin>>b;
            cout<<"Please Enter Third Number: ";
            cin>>c;

            cout<<endl;

            e=a+b+c;
            }



    //Step 5
    //Print number of times data was run

    outfile<<endl<<"Data ran "<<timesrun<<" times"<<endl<<endl;
    cout<<endl<<"Data ran "<<timesrun<<" times"<<endl<<endl;

    //Optional 1 - Part 2
    outfile <<"Optional 1"<<endl<<endl;
    outfile<<"The Message was printed "<<msg<< " times."<<endl<<endl;
    outfile <<"Optional 2"<<endl<<endl;
    outfile<<"The largest, smallest interger was: "<<lrg<<endl<<"The smallest, smallest interger was: "<<sml<<endl<< endl;


    outfile.close();

    return 0;
}
    //Funtion 1

    void introduction()
    {

    // this is just an introduction.
    //its a void and just print outs a message

    cout<<"This program will read in 3 numbers at a time\nand will determine which of them is the smallest.\nIt will then print a message the amount of\ntimes that the smallest number is.\n(only if between 1 and 10). The program also\nprints out how many times the program ran.\n\nLook in homework_3.txt to see results. "<<endl<<endl<<"Enter  three numbers that add up to zero to exit program:"<<endl<<endl;
    outfile<<"This program will read in 3 numbers at a time\nand will determine  which of them is the smallest.\nIt will then print a message the amount of\ntimes that the smallest number is.\n(only if between 1 and 10). The program also\nprints out how many times the program ran.\n\nLook in homework_3.txt to see results."<<endl<<endl<<"Enter  three numbers that add up to zero to exit program:"<<endl<<endl;
    return ;
    }

    //Funtion 2

    int findsmallest(int x, int y, int z)
    {

    //this funtion finds the
    //smallest of all the intergers
    //x, y, z and prints out an int.

    int smallhold;
    if (x<=y)
        {
        smallhold=x;
        }
    else
        {
        smallhold=y;
        }

    if (smallhold<=z)
        {
        return smallhold;
        }
    else
        {
        return z;
        }
    }
    //Funtion 3

    void printmessage (int w )
{
    //This Funtion prints a message as many
    //times as the smallest interger is (w).


    if (0<w)
    {
        if(w<=10)
        {
        for (int num=1;num<=w;num++)
            {
                outfile<<"supercalafragilisticexpialidocious"<<endl;
            }
        }
        else
            {
                outfile<<"Not possible to print."<<endl;
            }
    }
    else
    {
        outfile<<"Not possible to print."<<endl;
    }

        return ;
}
    //Function 4 - Optional 1

    int mymsg(int r , int &k)
{
    //This Funtion counts how many
    //times my message(from function 3) was printed
    //and print out an interger (k).

    if (0<r)
    {
        if(r<=10)
            {
            for (int num=1;num<=r;num++)
                {
                    k++;
                }
            }
        else
            {
                k=k;
            }

    }
    else
    {
        k=k;
    }
        return k;
        }
    //Function 5 - Optional 2

     void smllrg(int g, int& largest, int&smallest)
{
      //This function takes the smallest interger (g)
      //and dtermines if it can be the smallest smallest integer or
      //the largest integer. its a void and its a pass by reference

      if (g>largest)
                {
                    if(g<100000000)
                        {
                            largest=g;
                        }

                }


            if (g<smallest)
                {
                    if (g>-100000000)
                        {
                            smallest=g;
                        }
                }
            return ;
}







