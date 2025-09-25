#include <bits/stdc++.h>
using namespace std;

class Stack{
    vector<int> st;
public:
    Stack(){
        st={};
    }
    void push(int x){
        st.push_back(x);
        cout<<"pushed element"<<endl;
    }
    bool pop(){
        if(st.size() == 0){
            cout<<"cannot pop element"<<endl;
            return false;
        }
        st.pop_back();
        cout<<"popped element"<<endl;
        return true;
    }
    int top() const{ // ...does not change any member variables...
        if (st.empty()) {
            throw runtime_error("Stack is empty");
        }
        return st.back();
    }
};

int main(){
    Stack* st = new Stack();
    st->push(9);
    st->pop();
    st->pop();
    st->top();
    return 0;
}