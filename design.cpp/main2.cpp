#include <iostream>
using namespace std;
extern int sharedVar;

void printVar(){
    cout<<sharedVar<<endl;
}

// int main(){
//     cout<<"hi "<<sharedVar<<endl;
// }