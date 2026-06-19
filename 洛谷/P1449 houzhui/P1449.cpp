#include <bits/stdc++.h>
using namespace std;
namespace Soaring_WIngs
{
    void Soar()
    {
        stack<int> s;
        int n=0;
        char a;
        do
        {
            a=getchar();
            if(isdigit(a))
            {
                n=n*10+a-'0';
            }
            else if(a=='.')s.push(n),n=0;
            else if(a!='@')
            {
                int x=s.top();s.pop();
                int y=s.top();s.pop();
                switch (a)
                {
                case '+' :
                    s.push(x+y);
                    break;
                case '-' :
                    s.push(y-x);
                    break;
                case '*' :
                    s.push(x*y);
                    break;
                case '/' :
                    s.push(y/x);
                    break;
                default:
                    break;
                }
            }
        } while (a!='@');
        cout<<s.top();
    };
}
int main()
{
    Soaring_WIngs::Soar();
    return 0;
}