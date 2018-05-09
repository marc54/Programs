/* Marc Pfeiffer
   Assignment 4

This program takes SAT scores and finds if they are valid scores
(200 to 800). It also rates the scores individually and finds the sum and average.
the program also rate the average of the 3 scores; the program then counts how many
sets of data was input, valid inputs and invalid inputs.
*/

#include <iostream>
using namespace std;
bool isitavalidgroup(int, int, int);    // Function Prototype
void classify(int, int, int);           // Function Prototype
void ratescore(int );                   // Function Prototype
int findsumandavg(int, int, int);       // Function Prototype
int main()
{
    int x, y, z, notvalid = 0, valid = 0, total = 0;

    cout<<"This program takes SAT scores and finds if they are valid scores"<<endl
    <<"(200 to 800). It also rates the scores individually and finds the sum "<<endl
    <<"and average. The program then rates the average of the 3 scores; then "<<endl
    <<"program counts how many sets of data were processed, valid inputs," <<endl
    <<"and invalid inputs"<<endl<<endl;

    cout <<"::Enter Zero Three Times to Exit the Program::"<<endl<<endl;

    cout<<"Please enter the First score ";
    cin>>x;
    cout<<"Please enter the Second score ";
    cin>>y;
    cout<<"Please enter the Third score ";
    cin>>z;

    // type in 3 zeros to shut the program.

    while (x!=0 || y!=0 || z!=0)
    {
        cout<<endl<< "The 3 Values are "<<x<<"  "<<y<<"  "<<z<<endl;
        if(isitavalidgroup(x, y, z))
        {
            valid++;            //counter 1
            total++;            //counter 2
            classify(x, y, z);
        }
        else
        {
            cout<<"The group is invalid"<<endl;
            notvalid++;         //counter 3
            total++;

        }
        cout<< endl<<endl;

        cout<<"Please enter the First score ";
        cin>>x;
        cout<<"Please enter the Second score ";
        cin>>y;
        cout<<"Please enter the Third score ";
        cin>>z;
 }
    // Print out the 3 counters

    cout<<endl<<"the total amout of data processed was "<<total<<endl;
    cout<<"the total amout of not valid data processed was "<<notvalid<<endl;
    cout<<"the total amout of valid data processed was "<<valid<<endl;

    return 0;
}








bool isitavalidgroup(int a, int b, int c)
{
    //this function determines its a valid group or not

   if (a>=200 && b>=200 && c>=200 && a<=800 && b<=800 && c<=800)
        {
            cout<<"The group is valid"<<endl;
            return true;
        }
   else
        {
            if ( a<=200 || a>=800)
                cout <<a<<" is invalid"<<endl;

            if ( b<=200 || b>=800)
                cout <<b<<" is invalid"<<endl;

           if ( c<=200 || c>=800)
                cout <<c<<" is invalid"<<endl;



            return false;
        }


}
void classify(int d, int e, int f)
{
    // this function classifys the 3 scores and  the average

    int g;
    ratescore(d);
    ratescore(e);
    ratescore(f);
    g = findsumandavg(d, e, f);
    ratescore(g);

}
int findsumandavg(int d, int e, int f)
{
    //this function finds the sum and average
    //it returns the average to classify

   int sum, avg;
   sum=d+e+f;
   avg=(d+e+f)/3;
   cout<<"the sum is "<<sum<<" and the average is "<<avg<<endl;
    return avg;
}
void ratescore(int m)
{
    // this function rates the the score

    if(m==200)
    cout<<m<<" is Exactly 200"<<endl;
    else if (m>200 && m<500)
    cout<<m<<" is higher then 200 and lower then 500"<<endl;
    else if (m==500)
    cout<<m<<" is Exactly 500"<<endl;
    else if (m>500 && m<800)
    cout<<m<<" is higher then 500 and lower then 800"<<endl;
    else if (m==800)
    cout<<m<<" is Exactly 800"<<endl;
}
