#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,a[N][3],r[3],d[N];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(int T=1;T<=t;T++)
	{
		cin >> n;
		int sum=0;
		for(int i=0;i<=2;i++) r[i]=0;
		for(int i=1;i<=n;i++)
		{
			bool f=true;
	        cin >>a[i][0]>>a[i][1]>>a[i][2];
	        int maxn=max(a[i][0],max(a[i][1],a[i][2]));
	        int minn=min(a[i][0],min(a[i][1],a[i][2]));
	        int midn=a[i][0]+a[i][1]+a[i][2]-maxn-minn;
	        sum+=maxn;
	        if(a[i][0]==maxn)
			{
				r[0]++;
			}
	        else if(a[i][1]==maxn) r[1]++;
	        else r[2]++;
	        d[i]=maxn-midn;
		}
		sort(d+1,d+n+1);
		sort(r,r+3);
		if(r[2]>(n/2))
		{
			int k=1;
			while(r[2]>(n/2))
			{
				sum-=d[k];
				k++;
				r[2]--;
			}
		}
		cout<<sum<<endl;
	}
	    
	return 0;
}
