//find simple interest

#include<iostream>
using namespace std;

int main(){
 
   int P, R, T;

   cout<<"Enter Price"<<endl;
   cin>>P;

   cout<<"Enter Rate"<<endl;
   cin>>R;

   cout<<"Enter Time"<<endl;
   cin>>T;

   int SimpleInterest = P*R*T/2;

   cout<<"S.I.="<<" "<<SimpleInterest<<endl;
   cin>>SimpleInterest;

   return 0;

}