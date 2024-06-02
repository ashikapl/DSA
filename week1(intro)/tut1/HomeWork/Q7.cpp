//valid triangle or not

#include<iostream>
using namespace std;

    bool isValidTriangle (int a, int b, int c){
       
    //    check the valid traingle conditions
    return (a+b>c && b+c>a && c+a>b);

    }

    int main(){

        int side1, side2, side3;

        cout<<"Enter the three sides of triangle"<<" "<<endl;
        cin>>side1>>side2>>side3;

        if(isValidTriangle(side1, side2, side3)){
          cout<<"These side lengths can form a valid triangle."<<endl;
        }
        else{
            cout<<"These side lengths can not form a valid triangle."<<endl;
        }

        return 0;
    }