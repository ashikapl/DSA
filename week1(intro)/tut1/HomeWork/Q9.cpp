//print max of three no.

#include<iostream>
using namespace std;

int main(){

    int num1, num2, num3;

    cout<<"Enter three no."<<" ";
    cin>>num1>>num2>>num3;

    int max = num1; //initialize max value
    
    if(num2>max){
        max=num2;
    }

    if(num3>max){
    max=num3;
    }
    
    cout<<" The maximum no. of the three no. is:"<<" "<<max;

    return 0;
}