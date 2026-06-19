#include <iostream>
#include <string>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char a[1000005];
    cin >> a;
    int num[10]={0,0,0,0,0,0,0,0,0,0};
    for(int i=0;i<a.length();i++)
    {
       	char c=a[i];
		if(c-'0'>=0&&c-'0'<=9)
		{
            int n=c-'0';
            num[n]++;
    	}
    }
    for(int i=9;i>=0;i--)
    {
        for(int j=1;j<=num[i];j++)
        {
            cout << i;
        }
    }
}
