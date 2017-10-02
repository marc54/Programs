//Marc Pfeiffer
//Recursive Array Printing - Extra Credit
#include <iostream>
#include <fstream>
using namespace std;

ifstream dataIn("infile.txt");
ofstream dataOut("outfile.txt");

void recursivePrint3(int[][10][10], int, int, int, int,int);


int main()
{

    int arr1[100], arr2[100][100], arr3[10][10][10];
    int dimention, num1, num2, num3;

while(!dataIn.eof()){
    int counter=1;
    dataIn>>dimention;


    if(dimention == 1){
        dataIn>>num1;
        for(int i = 0; i<1; i++){
            for(int j = 0 ; j<1; j ++){
                for(int k = 0; k<num1 ; k++){
                    arr3[i][j][k] = counter;
                    counter++;
                }
            }
        }
        recursivePrint3(arr3, 1,1,num1,1,num1);
        dataOut<<endl<<endl;
    }
    else if(dimention == 2){
        dataIn>>num1>>num2;
        for(int i = 0; i<1; i++){
            for(int j = 0 ; j<num1; j ++){
                for(int k = 0; k<num2 ; k++){
                    arr3[i][j][k] = counter;
                    counter++;
                }
            }
        }
         recursivePrint3(arr3, 1, num1,num2,num1,num2);
         dataOut<<endl<<endl;
    }
    else if(dimention == 3){

        dataIn>>num1>>num2>>num3;

        for(int i = 0; i<num1; i++){
            for(int j = 0 ; j<num2; j ++){
                for(int k = 0; k<num3 ; k++){
                    arr3[i][j][k] = counter;
                    counter++;
                }
            }
        }
        recursivePrint3(arr3, num1,num2,num3,num2,num3);
        dataOut<<endl<<endl;
    }
}



return 0;
}

void recursivePrint3(int arr[10][10][10],int num1, int num2 ,int num3, int place1 ,  int place2){

    if(num3 == 1){
        if(num2 == 1){
            if(num1 == 1){
                dataOut<<arr[0][0][0];
            }
            else{

                recursivePrint3(arr,num1-1 , place1, place2, place1, place2);
                dataOut<<"\n\n"<<arr[num1-1][num2-1][num3-1];
            }
        }
        else{
            recursivePrint3(arr,num1 , num2-1, place2, place1, place2);
                dataOut<<"\n"<<arr[num1-1][num2-1][num3-1];
        }

    }
    else{
        recursivePrint3(arr,num1 , num2, num3-1, place1, place2);
                dataOut<<" "<<arr[num1-1][num2-1][num3-1];
    }

}
