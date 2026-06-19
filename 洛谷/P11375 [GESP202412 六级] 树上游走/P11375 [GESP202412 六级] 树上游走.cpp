#include<bits/stdc++.h>
#define int long long
#define INF 1e12
using namespace std;
int n,s,t=0;
signed main()
{
	cin>>n>>s;
	for(int i=1;i<=n;i++)
	{
		char c;
		cin>>c;
		switch(c)
		{
		case 'U':
			if(s==1)break;
			if(t>0)t--;
			else s/=2;
			break;
		case 'L':
			if(s*2>1e12){t++;break;}
			s*=2;break;
		case 'R':
			if(s*2+1>1e12){t++;break;}
			s*=2;s+=1;break;
		}
	}
	cout<<s;
	return 0;
}