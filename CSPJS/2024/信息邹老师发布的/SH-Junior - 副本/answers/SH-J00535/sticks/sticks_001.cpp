#include<bits/stdc++.h>
using namespace std;

int a[100001]={-1,-1,1,7,4,2,6,8,10,18,22,20,28,102,88,108,188,500,208,288,688,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,88888827};
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int num, T;
    cin >> T;
    while(T--)
    {
        cin >> num;
        if(num%7==0)for(int i = 1; i <= num/7; i++)cout<<8;
        else cout<<a[num];
        cout<<endl;
    }
    return 0;
}
