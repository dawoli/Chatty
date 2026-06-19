#include <bits/stdc++.h>
using namespace std;
#define N 200005
int s[N][N],r[N],c[N];
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
//	cin.tie(0);
//	ios::sync_with_stdio(false);
	int t,n,k,q,l;
	cin>>t;
	while(t--)
	{
		memset(s,sizeof(s),0);
		memset(r,sizeof(r),0);
		memset(c,sizeof(c),0);
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++)
		{
			cin>>l;
			for(int j=1;j<=l;j++)
				cin>>s[i][j];
		}
		for(int i=1;i<=q;i++)
			cin>>r[i]>>c[i];
	}
	cout<<"看完题目无思路尽力了"; 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
