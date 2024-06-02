//check prime or not

#include<iostream>
using namespace std;

int main(){

    int n;
    cin>>n;
    
    bool isprime = false;

    if(n==0 || n==1) cout<<" Its not a prime no.";
    for(int i=2; i<n/2; i++){
        if(n%i==0){
            isprime = true;
            break;
        }
    }
    if(isprime==true){
        cout<<" Its not a prime no.";
    }
    else{
        cout<<" Its a prime no.";
    }
}  

