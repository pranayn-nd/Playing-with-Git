#include <bits/stdc++.h>
using namespace std;

class jiraTicket{
    static int a;
    public:
    static void print_static();
};
int jiraTicket::a=5;
void jiraTicket::print_static(){
    cout<<a<<endl;
}

int main(){
    
    jiraTicket::print_static();
    return 0;
}
