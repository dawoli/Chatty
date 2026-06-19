#include<bits/stdc++.h>
using namespace std;
int t,n,dp[205][205][205];
struct node{
	int a,b,c;
}k[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		cin >> n;
		bool flag=true;
		for(int i=1;i<=n;i++){
			cin >> k[i].a >> k[i].b >> k[i].c;
			if(k[i].c) flag=false;
		}
		if(flag){
			priority_queue<int> q;
			int cnt=0;
			for(int i=1;i<=n;i++){
				cnt+=k[i].a;
				q.push(k[i].b-k[i].a);
			}
			for(int i=1;i<=n/2;i++){
				cnt+=q.top();
				q.pop();
			}
			cout << cnt << endl;
			continue;
		}
		int maxn=0;
		dp[0][1][1]=k[1].b;
		dp[1][0][1]=k[1].a;
		dp[0][0][1]=k[1].c;
		for(int i=2;i<=n;i++){
			for(int _a=0;_a<=min(i,n/2);_a++){
				for(int _b=0;_b<=min(i,n/2);_b++){
					dp[_a][_b][i]=0;
					int _c=i-_a-_b;
					if(_c<0||_c>n/2) continue;
					if(_a!=0) dp[_a][_b][i]=max(dp[_a-1][_b][i-1]+k[i].a,dp[_a][_b][i]);
					if(_b!=0) dp[_a][_b][i]=max(dp[_a][_b-1][i-1]+k[i].b,dp[_a][_b][i]);
					if(_a+_b!=i) dp[_a][_b][i]=max(dp[_a][_b][i-1]+k[i].c,dp[_a][_b][i]);
					if(i==n) maxn=max(maxn,dp[_a][_b][i]);
				}
			}
		}
		cout << maxn << endl;
	}
	return 0;
} 
