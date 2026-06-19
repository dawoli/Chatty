#include<bits/stdc++.h>
using namespace std;
int dp[510][510][510];
int n,a[510];
int countt(0);
void bfs(vector<int>&now,int len,int lens){
	if (len==n){
		int maxn=0;
		int cnt=0;
		for (int i=0;i<lens;i++){
			int nn=now[i];
			maxn=max(maxn,nn);
			cnt+=nn;
		}
		if (lens>=3&&maxn<(cnt/2.0)){
			countt++;
		}
		return;
	}
	now.push_back(a[len]);
	bfs(now,len+1,lens+1);
	now.pop_back();
	bfs(now,len+1,lens);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	vector<int>now;
	bfs(now,0,0);
	cout<<countt<<endl;
	return 0;
}
