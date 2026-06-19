/*
0:6
1:2
2:5
4:4
6:6
7:3
8:7
numbers:2-7
n=100时，开始dp
存储f[i]为所有数位
*/
#include<bits/stdc++.h>
using namespace std;
int T,n;
int f[205];
vector<int> dp[205];
int num[10]={6,2,5,5,4,5,6,3,7,6};
int main() {
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	while(T--) {
		cin>>n;
		if(n<2) {
			cout<<"-1\n";
			continue;
		}
		int eight=0;
		while(n>100) {
			eight++;
			n-=7;
		}
		memset(f,0x3f,sizeof(f));
		for(int j=2;j<=n;j++)  dp[j].clear();
		f[0]=0;
		for(int j=2;j<n;j++) {
			for(int d=0;d<10;d++) {
				int x=num[d];
				if(x>j)  continue;
				if(f[j-x]+1<f[j]) {
					f[j]=f[j-x]+1;
					dp[j].clear();
					for(int k:dp[j-x])  dp[j].push_back(k);
					dp[j].push_back(d);
				}
			}
		}
		for(int d=1;d<10;d++) {
			int x=num[d];
			if(x>n)  continue;
			if(f[n-x]+1<f[n]) {
				f[n]=f[n-x]+1;
				dp[n].clear();
				for(int k:dp[n-x])  dp[n].push_back(k);
				dp[n].push_back(d);
			}
		}
		sort(dp[n].begin(),dp[n].end());
		int cnt=0;
		for(int k=0;k<dp[n].size();k++) {
			if(dp[n][k]==0)  cnt++;
			else {
				printf("%d",dp[n][k]);
				for(int i=1;i<=cnt;i++)  printf("0");
				cnt=0;
			}
		}
		for(int i=1;i<=eight;i++)  printf("8");
		cout<<"\n";
	}
	return 0;
}
/*
3
19748
67842
47216
*/
