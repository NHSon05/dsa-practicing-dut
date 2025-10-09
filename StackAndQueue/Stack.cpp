// #include <bits/stdc++.h>
#include <iostream>
#include <stack>
#include <string>
#include <sstream>
using namespace std;
// LIFO: Last in the first out
// push
// pop
// top
// size
// empty
// O(1)
// python java php c++ js
// js c++ php java python

int main() {
    string s;
    getline(cin, s);
    stringstream ss(s);
    string token;
    stack<string> st;
    while (ss >> token){
        st.push(token);
    }
    while (!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}