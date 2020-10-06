#include<iostream>
#include<string.h>
using namespace std;


int main(){
string A = "this is a test string";
string::iterator it;
for(it=A.begin();it!=A.end();it++){
    cout<<*it;
}
}