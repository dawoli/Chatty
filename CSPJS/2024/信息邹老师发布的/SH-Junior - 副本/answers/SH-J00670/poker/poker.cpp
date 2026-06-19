#include <bits/stdc++.h>
using namespace std;

int n,d[15],c[15],h[15],f[15],ans;
string s;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n; i++)
	{
		cin >> s;
		if(s[0] == 'D')
		{
			if('2' <= s[1] && s[1] <= '9')	d[s[1]-'0'] =1;
			else{
				if(s[1] == 'A') d[1] = 1;
				if(s[1] == 'T') d[10] = 1;
				if(s[1] == 'J') d[11] = 1;
				if(s[1] == 'Q') d[12] = 1;
				if(s[1] == 'K') d[13] = 1;
			}  
		}
		else if(s[0] == 'C')
		{
			if('2' <= s[1] && s[1] <= '9')	c[s[1]-'0'] =1;
			else{
				if(s[1] == 'A') c[1] = 1;
				if(s[1] == 'T') c[10] = 1;
				if(s[1] == 'J') c[11] = 1;
				if(s[1] == 'Q') c[12] = 1;
				if(s[1] == 'K') c[13] = 1;
			}  
		}
		else if(s[0] == 'H')
		{
			if('2' <= s[1] && s[1] <= '9')	h[s[1]-'0'] =1;
			else{
				if(s[1] == 'A') h[1] = 1;
				if(s[1] == 'T') h[10] = 1;
				if(s[1] == 'J') h[11] = 1;
				if(s[1] == 'Q') h[12] = 1;
				if(s[1] == 'K') h[13] = 1;
			}  
		}
		else if(s[0] == 'S')
		{
			if(s[1] >= '2' && s[1] <= '9')	f[s[1]-'0'] = 1;
			else{
				if(s[1] == 'A') f[1] = 1;
				if(s[1] == 'T') f[10] = 1;
				if(s[1] == 'J') f[11] = 1;
				if(s[1] == 'Q') f[12] = 1;
				if(s[1] == 'K') f[13] = 1;
			}  
		}
	}
	for(int i = 1; i <= 13; i++)
	{
		ans += (d[i]+c[i]+h[i]+f[i]);
	}
	if(ans >= 52) cout << 0;
	else cout << 52-ans << endl;
	return 0;
}

