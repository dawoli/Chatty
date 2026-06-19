#include<bits/stdc++.h>
using namespace std;
bool f[188][188];
char h[4]={'C','D','H','S'};
char m[13]={'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;cin>>n;
	for(int i = 1;i<=n;i++)
	{
		string s;cin>>s;
		f[s[0]][s[1]]=1;
		
	}
	int ans=0;
	for(int i = 0;i<4;i++)
	{
		for(int j = 0;j<13;j++)
		{
			if(!f[h[i]][m[j]])ans++;
			
			
		}
	}
	cout<<ans;
	return 0;
} 
