#include <bits/stdc++.h>
using namespace std;
#define debug cout<<"ok\n";
const int N=1e7+7;
string s[N];
string ss1,ss2;
int n,m,k,na1,nb,na2;

void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	for(int i=1;i<=m;i++)
	{
		cin>>ss1>>ss2;
		for(int j=1;j<=n;j+=2)
		{
			if(s[j]==ss1 && s[j+1]==ss2){
				cout<<1<<"\n";
				goto ma;
			}
		
		}
		cout<<"0\n";
		ma:
			continue;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T=1;
	while(T--)
	{
		solve();
	}
 	return 0;
}

