//Marc Pfeiffer
//Assignment 6
//Due Thursday April 23rd, 2015:

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void readsentence(string & );                               //Function 1 Prototype
void makewords(string, string &, string &, string &);       //Function 2 Prototype
void makechanges(string &);                                 //Function 3 Prototype

ifstream infile ("Assignment6_input.txt");
ofstream outfile("Assignment6_output.txt");


int main()
{
    //This program will:
    //1)Read in a three word sentence.
    //2)Separate the three words into three different strings.
    //3)Change the word depending on the amount of characters.

    string orig, word1, word2, word3, allwords;

    while(getline(infile, orig))
    {
        readsentence(orig);
        makewords(orig, word1, word2, word3);

        //Optional 1: part 1
        allwords+= word1+" "+word2+" "+word3;

        makechanges(word1);
        makechanges(word2);
        makechanges(word3);
        outfile<<endl<<endl<<endl;

        //Optional 1: part 2
        allwords+=" "+word1+" "+word2+" "+word3+"\n\n";
    }
    //Optional 1: part 3
    outfile<<allwords;

    cout<<endl<<endl<<"\t"<<"The program is complete!!!"<<endl<<endl;

    infile.close();
    outfile.close();

    return 0;
}
//Function 1
void readsentence(string &str)
{
    //This function will:
    //1)Read in a three word sentence.

    outfile<<"The Original Sentence is >> ";
    outfile<<str<<endl;
}
//Function 2
void makewords(string main, string &w1, string &w2, string &w3)
{
    //This program will:
    //2)Separate the three words into three different strings.
    //*******Optional 2 included**********




    outfile.setf(ios::left);
    outfile.width(12);

    string::size_type len1, finder;
    string abc= "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    len1 = main.length();
    bool newword=false;
    int z=1;

    w1.clear();
    w2.clear();
    w3.clear();

    for(int x=0;x <= len1 ;x++)
    {

        finder=abc.find(main[x],0);
        if (finder != string::npos)
        {
            newword=true;
            switch(z)
                {
                    case 1:
                    w1+=main[x];
                break;
                    case 2:
                    w2+=main[x];
                break;
                    default:
                    w3+=main[x];
                break;
                }
        }
        else
        {
            if(newword)
            {
                switch(z)
                {
                    case 1:
                    outfile<<w1<<"\t";
                break;
                    case 2:
                    outfile<<w2<<"\t\t";
                break;
                    default:
                    outfile<<w3<<endl<<endl;
                break;
                }
            newword=false;
            z++;
            }
        }
    }
}

//Function 3
void makechanges(string &change)
{
    //This Function will:
    //Change the word depending on the amount of characters.

    outfile.setf(ios::left);
    outfile.width(10);

    string::size_type len;
    len=change.length();

    outfile<<change<<"\t"<<len<<"\t";



    if (len<3)
    {
        change.insert(0,"mp");
        change.insert(len+2,"mp");
        outfile<<change<<endl;
    }
    else if(len>=3 && len<=5)
    {
        change.insert(3, "Marc");
        outfile<<change<<endl;
    }
    else
    {
        change.replace (1,4,"Pfeiffer");
        outfile<<change<<endl;
    }
}
