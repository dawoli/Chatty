#include <iostream>
#include <string>
using namespace std;
int change(const string a)
{
    int number;
    for(int i = 0; i < a.length(); ++i)
	number = number * 10 + a[i] - '0';
    return number;
}
int main() {
    string s,f,g;
    int a,b,c;
    getline(cin,s);
    for (size_t i = 0; i < s.length(); ++i) {
        if (s[i] == ' ') {
            s.erase(i, 1);
            --i;
        }
    }
    int i=0;
    while(s[i]!='+')
    {
        f+=s[i];
        i++;
    }
    a=change(f);
    i+=3;
    int d=s.length()-1;
    while(i!=d)
    {
        g+=s[i];
    }
    c=change(g);
    cout<<c-a;
    return 0;
}
