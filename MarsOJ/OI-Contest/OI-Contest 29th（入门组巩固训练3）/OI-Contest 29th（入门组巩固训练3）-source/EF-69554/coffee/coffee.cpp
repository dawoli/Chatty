#include<bits/stdc++.h>
using namespace std;
string s[10][10];
int flag[10];
int main(){
	freopen("coffee.in","r",stdin);
	freopen("coffee.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		memset(flag,0,sizeof(flag));
		for(int i=1;i<=5;i++)
		{
			for(int j=1;j<=8;j++)
			{
				cin>>s[i][j];
				if(s[i][j]=="math")
				{
					flag[i]++;
				}
			}
		}
		int n,m;
		cin>>n>>m;
		long long ans=0;
		long long cnt=1ll*n/7*(flag[1]+flag[2]+flag[3]+flag[4]+flag[5]);
		ans+=cnt;
		int left=n%7;
		while(left)
		{
			ans+=flag[m];
			m++;
			if(m==8)
			{
				m=1;
			}
			left--;
		}
		cout<<ans<<endl;
	}
	return 0;
} 
