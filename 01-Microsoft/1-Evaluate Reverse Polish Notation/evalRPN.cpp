#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int evalRPN(vector<string>& tokens) {
            stack<int> stk;
        for(int i=0;i<tokens.size();i++) {
            if(tokens[i]!="+" && tokens[i]!="-" && tokens[i]!="/" && tokens[i]!="*")    {
                stk.push(stoi(tokens[i]));
            } else {
                long long firstnum = stk.top();
                stk.pop();

                long long secondnum = stk.top();
                stk.pop();

                if(tokens[i]=="+")
                    stk.push(secondnum+firstnum);
                else if(tokens[i]=="-")
                    stk.push(secondnum-firstnum);
                else if(tokens[i]=="/")
                    stk.push(secondnum/firstnum);
                else if(tokens[i]=="*")
                    stk.push(secondnum*firstnum);
            }
        }
        return stk.top();
        }
};

int main()
{
    Solution rpn;
    vector<string> tokens={"2","1","+","3","*"};
    int res = rpn.evalRPN(tokens);
    cout << res;
    return 0;
}