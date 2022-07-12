//Athavan Jesunesan

#include "operations.cpp"
using namespace std;

int main(){
    Set a; //Set A
    Set b; //Set B
    Set c; //Set C to test results of operations on A and B

    cout<<"Universe"<<endl;
    cout<<+a;
    cout<<"Empty Set"<<endl;
    cout<<-a;
    c = (a+1)+(b+2);
    cout<<"adding index 1 element to a and index 2 to b, then outputting the union"<<endl;
    cout<<c;
    cout<<"checking if b is a subset of a"<<endl;
    cout<<(a<=b)<<endl;
    a+2;
    a-1;
    cout<<"checking again"<<endl;
    cout<<(a<=b)<<endl;
    //cin>>c;       //this works but I commented it out so that it does not ask for 256 inputs when testing. uncomment it when testing it.
}
