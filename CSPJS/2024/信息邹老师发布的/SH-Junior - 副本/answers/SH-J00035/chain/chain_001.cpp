#include <bits/stdc++.h> 
using namespace std;

int t,n,k,q,l,r,c,cnt=0,a[210000],p[120000];

int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin >> t;
	for(int i = 1; i <= t; i++)
	{
		memset(p,0,sizeof(p));
		cin >> n >> k >> q;
		for(int j = 1; j <= n; j++)
		{
			cin >> l;
			for(int j2 = 1; j2 <= l;j2++)
			{
				cin >> a[j2+cnt];
			}
			cnt += l;
			p[j] = cnt;
		}
		for(int j = 1; j <= q; j++)
		{
			cin>>r>>c;
			if(r==1){
				int temp=-704704,flag=0;
				for(int j2 = 1; j2 <= n; j2++)
				{
					temp=-704704;
					for(int j3=p[j2-1]+1; j3 <= p[j2]; j3++)
					{
						if(a[j3]==c && j3-temp <= k-1 && j3-temp>=1)
						{
							flag=1;
							break;
						}
						if(a[j3]==1) temp = j3;
						
					}
					if(flag==1)break;
				}
				cout << flag << endl;
			}
		}
	}
}
