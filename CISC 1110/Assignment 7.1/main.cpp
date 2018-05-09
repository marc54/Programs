//Marc Pfeiffer
//Assignment 7.1
//Due: Tuesday, may 7, 2015

#include <iostream>
#include <fstream>

using namespace std;

void read3arrays(int[], int[], int[], int);                     //function prototype1
void print1array(int[], int);                                   //function prototype2
void makeanewarray (int[], int[], int [], int [], int );        //function prototype3


void sort1array(int[], int);                                    //Function Prototype4
void find2largestandsmallest(int[] ,int);                       //Function Prototype5

ifstream infile("Assignment_7_part1.txt");
ofstream outfile  ("outfile7.txt");

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

    //the print out of array sumscores
    outfile<<"\t"<<"Sumscores values"<<endl;
    print1array(sumscores, n);


     //the print out of array 1 sorted
    sort1array(score1, n);
    outfile<<"\t"<<"Array 1 values sorted "<<endl;
    print1array(score1, n);
    find2largestandsmallest(score1, n);

    //the print out of array 2 sorted
    sort1array(score2, n);
    outfile<<"\t"<<"Array 2 values sorted"<<endl;
    print1array(score2, n);
     find2largestandsmallest(score2, n);

    //the print out of array 3 sorted
    sort1array(score3, n);
    outfile<<"\t"<<"Array 3 values sorted"<<endl;
    print1array(score3, n);
    find2largestandsmallest(score3, n);

    //the print out of Sumscores sorted
    sort1array(sumscores, n);
    outfile<<"\t"<<"sumscores values sorted"<<endl;
    print1array(sumscores, n);
    find2largestandsmallest(sumscores, n);

     //adds up the 3 scores and prints it
    makeanewarray(score1, score2, score3, sumscores, n);


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
    outfile.setf(ios::right);
    outfile.width(1);
    int y, z=0;
    for(y=0; y<m;y++)
    {
        z++;
        outfile<<num[y]<<" ";
        if(z==6)
        {
         outfile<<endl;
         z=0;
        }

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
void sort1array(int sorting[], int m)
{
//this function will sort an array
//from lowest to highest.
int temp;
      for(int x=0;x<m-1;x++)
      {
        for(int y=x+1;y<m;y++)
        {
            if(sorting[x]>sorting[y])
            {

                temp=sorting[x];
                sorting[x]=sorting[y];
                sorting[y]=temp;

            }
        }
     }

}

//Function5

void find2largestandsmallest(int findthem[] ,int m)
{
    //This function will print out
    //the 2 highest and 2 smallest numbers
    outfile.setf(ios::left);
    outfile.width(10);
    outfile<<"The largest value is: "<<findthem[m-1]<<endl;
    outfile<<"The 2nd largest value is: "<<findthem[m-2]<<endl;
    outfile<<"The Smallest value is: "<<findthem[0]<<endl;
    outfile<<"The 2nd Smallest value is: "<<findthem[1]<<endl<<endl<<endl;
}
