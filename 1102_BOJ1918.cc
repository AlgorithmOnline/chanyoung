#include <stack>
#include <iostream>
using namespace std;

int priority(char c)
{
    if (c == '(') return 1;
    else if (c == '+' || c == '-') return 2;
    else if (c == '*' || c == '/') return 3;
}

int main(void)
{
    string str;
    cin >> str;
    stack<char> stk;

    for (int i = 0; i < str.size(); ++i)
    {
        char now = str[i];
        if ('A' <= now && now <= 'Z') cout << now;
        else if (now == '(') stk.push(now);
        else if (now == ')')
        {
            while (!stk.empty() && stk.top() != '(')
            {
                cout << stk.top();
                stk.pop();
            }
            stk.pop();
        }
        //operator
        else
        {
            while (!stk.empty() && priority(stk.top()) >= priority(now))
            {
                cout << stk.top();
                stk.pop();
            }
            stk.push(now);
        }
    }

    while (!stk.empty())
    {
        cout << stk.top(); 
        stk.pop();
    }

    return 0;
}