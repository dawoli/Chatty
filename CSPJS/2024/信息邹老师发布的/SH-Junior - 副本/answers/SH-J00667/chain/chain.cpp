#include<bits/stdc++.h>
using namespace std;

int T,n,k,q,l[100005],s[200005][200005],r[100005],c[100005];

int main()
{
	cin>>T;
	while(T --)
	{
		cin>>n>>k>>q;
		for(int i = 0;i < n;i ++)
		{
			cin>>l[i];
			for(int j = 0;j < l[i];j ++)
				cin>>s[l[i]][j];
		}
		for(int i = 0;i < q;i ++)cin>>r[i]>>q[i];
	}
}
