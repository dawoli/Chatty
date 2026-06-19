#include<bits/stdc++.h>
using namespace std;
const int N=100009;
int T,n,sum;
int s[N][4],c[4],uis[N],fix[N];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	for(int k=1;k<=T;k++)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>s[i][1]>>s[i][2]>>s[i][3];
			if(s[i][1]>max(s[i][2],s[i][3])) sum+=s[i][1],c[1]++,uis[i]=1;
			else if(s[i][2]>s[i][3]) sum+=s[i][2],c[2]++,uis[i]=2;
			else sum+=s[i][3],c[3]++,uis[i]=3;
		}
		if(max(c[1],max(c[2],c[3]))>n/2)
		{
			int p;
			if(c[1]>max(c[2],c[3])) p=1;
			else if(c[2]>c[3]) p=2;
			else p=3;
			int t=0;
			for(int i=1;i<=n;i++)
			{
				if(uis[i]!=p) continue;
				bool che=0;t++;
				for(int j=1;j<=3;j++)
					if(j==p) continue;
					else if(che==0) fix[t]=s[i][p]-s[i][j],che++;
					else fix[t]=min(fix[t],s[i][p]-s[i][j]); 
			}
			sort(fix+1,fix+t+1);
			int i=0;
			while(c[p]>n/2) c[p]--,i++,sum-=fix[i];
		}
		cout<<sum<<"\n";
		sum=c[1]=c[2]=c[3]=0;
	}
	return 0;
}
