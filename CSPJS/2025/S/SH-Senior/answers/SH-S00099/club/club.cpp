#include<bits/stdc++.h>
using namespace std;

const int MAX=100000;
int ans=0,t,n,m,a1[MAX+5],a2[MAX+5],a3[MAX+5];

int bfs(int x,int p1,int p2)
{
	if(x>n)
		return 0;
	if(p1>=m)
		return a2[x]+bfs(x+1,p1,p2+1);
	if(p2>=m)
		return a1[x]+bfs(x+1,p1+1,p2);
	ans=max(a1[x]+bfs(x+1,p1+1,p2),a2[x]+bfs(x+1,p1,p2+1));
	
	return ans;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int i,j;
	cin>>t;
	for(i=1; i<=t; i++)
	{
		cin>>n;
		for(j=1; j<=n; j++)
			cin>>a1[j]>>a2[j]>>a3[j];
		m=n/2;
		bfs(1,0,0);
		cout<<ans<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
