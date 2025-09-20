#include <bits/stdc++.h>
using namespace std;

int a;
int sharedVar;
class Complex{
    
    void mf(int);
    public:
    void mf1(int a){
        mf(a);
    }
};
void Complex::mf(int a){ // here complex is membership label and :: is score resolution operator
    cout<<a<<endl;
}

int main(){
    fstream file("testWrite.txt", ios::in | ios::out);
    string s;
    file <<"writing to test ofstream";
    file.seekg(0);
    cerr<<file.tellg()<<endl;
    getline(file,s);
    cerr<<s<<endl;
    return 0;
}