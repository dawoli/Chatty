#include<bits/stdc++.h>
using namespace std;
int s[1005][2005],l[1005];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int T;
	cin>>T;
	for(int t=0;t<T;t++)
	{
		int n,k,q,now1=1,now2;
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++)
		{
			cin>>l[i];
			for(int j=1;j<=l[i];j++)
			{
				cin>>s[i][j];
			}
		}
		for(int i=0;i<q;i++)
		{
			int r,c;
			cin>>r>>c;
			now2=(now1+r)%n;
			for(int j=1;j<=l[now2];j++)
			{
				if(l[j]==c)
				{
					cout<<1<<endl;
					now1=now2;
					break;
				}
			}
			cout<<0<<endl;
			now1=now2;	
		}
	}
	return 0;
} 
