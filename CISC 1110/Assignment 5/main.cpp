//Marc Pfeiffer
//Assignment 5
//Due: Tuesday, April 14, 2015

#include <iostream>
#include <fstream>

using namespace std;

void read3arrays(int[], int[], int[], int);                     //function prototype1
void print1array(int[], int);                                   //function prototype2
void makeanewarray (int[], int[], int [], int [], int );        //function prototype3
void findsmallestandpos(int [], int , int&, int &);             //function prototype4

ifstream infile("Assignment5.txt");
ofstream outfile  ("outfile5.txt");

int const MAX=100;

int main()
{
    int n, score1[MAX], score2[MAX], score3[MAX],sumscores[MAX], smallest, position;

    cout<<"How many sets of grades do you want to enter. >> ";
    cin>>n;

    //read in and print of each group
    read3arrays (score1, score2, score3, n);

    //the print out of array 1
    outfile<<"\t"<<"Array 1 values"<<endl;
    print1array(score1, n);

    //the print out of array 2
    outfile<<"\t"<<"Array 2 values"<<endl;
    print1array(score2, n);

    //the print out of array 3
    outfile<<"\t"<<"Array 3 values"<<endl;
    print1array(score3, n);

    //adds up the 3 scores and prints it
    makeanewarray(score1, score2, score3, sumscores, n);

    //find the smallest number in each array
    //and fid ts corrosponding position
    findsmallestandpos( score1, n, smallest, position);

    outfile<<"The smallest element in array score1 is " <<smallest<<"."
    <<"\nThis value occurs in position "<<position<<" in the array."<<endl<<endl;

    findsmallestandpos( score2, n, smallest, position);

    outfile<<"The smallest element in array score2 is " <<smallest<<"."
    <<"\nThis value occurs in position "<<position<<" in the array."<<endl<<endl;

    findsmallestandpos( score3, n, smallest, position);

    outfile<<"The smallest element in array score3 is " <<smallest<<"."
    <<"\nThis value occurs in position "<<position<<" in the array."<<endl<<endl;

    findsmallestandpos( sumscores, n, smallest, position);

    outfile<<"The smallest element in array sumscores is " <<smallest<<"."
    <<"\nThis value occurs in position "<<position<<" in the array."<<endl<<endl;

    cout <<endl<<endl<<"Program Is Complete!!!"<<endl<<endl;

    infile.close();
    outfile.close();

    return 0;
}







//function 1
void read3arrays(int s1[], int s2[],int s3[], int k)
{
    //this function reads in the SAT scores
    //from the infile and places them in the
    //proper array:

    for(int x=0; x<k; x++)
    {
       // cout<<"Enter Sat Scores
       infile>>s1[x]>>s2[x]>>s3[x];
       outfile<<"The 3 SAT scores are: "<<s1[x]<<"  "<<s2[x]<<"  "<<s3[x]<<endl;
    }
    outfile<<endl;
}
//Function 2
void print1array(int num[], int m)
{
    // this function prints out all the values of each array

    int y=0;
    while(y!=m)
    {
        outfile<<num[y]<<"\t";
        if(y==5 || y==11)
        {
         outfile<<endl;
        }
        y++;
    }
    outfile<<endl<<endl;
}
//Function 3
void makeanewarray (int s1[], int s2[], int s3[], int newarr[], int k)
{
    //this function prints out all the scores in the perspective
    //arrays. then it adds them up and puts in in a new array:

    outfile<<"#"<<"\t"<<"SCORE1"<<"\t"<<"SCORE2"<<"\t"<<"SCORE3"<<"\t"<<"SUMSCORES"<<endl<<endl;
    for(int x=0; x<k; x++)
    {
        newarr[x]=(s1[x]+s2[x]+s3[x]);

        outfile<<x+1<<":\t"<<s1[x]<<"\t"<<s2[x]<<"\t"<<s3[x]<<"\t"<< newarr[x]<<endl;//
    }
    outfile<<endl;
}
//Function 4
void findsmallestandpos(int p[], int m, int  &small, int &pos)
{
    //this function determines the smallest value
    //and position for each array.

    small=2400;
    for(int x2=0; x2<m; x2++)
    {
        if (p[x2]<small)
           {
            small=p[x2];
            pos=x2;
           }
    }
}
