#include<bits/stdc++.h>
#include<string>
using namespace std;
int main()
{
    freopen("coffee.in","r",stdin);
    freopen("coffee.out","w",stdout);
    int T,n,m;
    cin>>T;
    while(T--)
    {
    	string a[6][9];
    	for(int i=1;i<=5;i++)
		{
			for(int j=1;j<=8;j++)cin>>a[i][j];
		}
		cin>>n>>m;
		int now=m,cnt=0,i=1;
        if(now==6){
            i+=2;
            now=1;
        }
        if(now==7){
            i++;
            now=1;
        }
		for( ;i<=n;i++)
		{
			for(int j=1;j<=8;j++)
			{
				if(a[now][j]=="math")cnt++;
			}
			now++;
            if(now>5){
                i+=2;
                now=1;
            }
		}
		cout<<cnt<<endl;
    }
    return 0;
}