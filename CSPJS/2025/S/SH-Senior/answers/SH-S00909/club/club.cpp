#include <bits/stdc++.h>
#define int long long
using namespace std;
int t,n,a[5][100086];
int mem[110][110][110];

int solve(int c1,int c2,int c3,int cur){
	if(c1+c2+c3==n)return 0;
	int d1,d2,d3,d;
	if(!mem[c1][c2][c3]){
		
		d1 = solve(c1+1,c2,c3,cur+1) + a[1][cur];
		d2 = solve(c1,c2+1,c3,cur+1) + a[2][cur];
		d3 = solve(c1,c2,c3+1,cur+1) + a[3][cur];
		if(c1== n>>1)d = max(d2,d3);
		else if(c2 == n >>1)d = max(d1,d3);
		else if (c3 ==n>>1)d = max(d1,d2);
		else d = max(max(d1,d2),d3);
		mem[c1][c2][c3] = d;
	}
	else d = mem[c1][c2][c3];
	return d;
}

signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	//cout<<LONG_LONG_MAX<<endl;
	cin>>t;
	while(t--){
		int ans = 0;
		int flag = 0;
		memset(mem,0,sizeof(mem));
		cin>>n;
		for(int i = 1; i <=n; ++i){
			cin>>a[1][i]>>a[2][i]>>a[3][i];
			if(a[2][i]||a[3][i])flag = 1;
			
		}
		if(!flag){
			sort(a[1]+1,a[1]+n+1);
			for(int i = n; i >=n/2+1; --i){
				ans+=a[1][i];
			}
		}
		else{
			ans = solve(0,0,0,1);
		}
		cout<<ans<<endl;
		
	}
	return 0;
}

