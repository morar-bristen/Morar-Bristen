#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    int n=0,random_number=rand()%101,attempt=10;
    
    while(n!=random_number||attempt==0)
    {
        
        cin>>n;
    if(n>random_number)
    {
        attempt--;
    
        cout<<"too high try again"<<endl<<"u have "<<attempt<<"remaining"<<endl;
    
    }


    if(n<random_number)
    {
        attempt--;
        cout<<"too low try again"<<endl<<"u have "<<attempt<<"remaining"<<endl;
    
    }

    if(attempt==0)
    {
        cout<<"no more attempts"<<endl;
    return 0;}


    if(n==random_number)
    {
        cout<<"congratiulations u have won"<<endl;
    
        return 0;}
    }
    return 0;}