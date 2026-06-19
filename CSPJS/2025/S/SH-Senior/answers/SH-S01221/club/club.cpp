#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[4][100010];
int tmp[100010];
int flag[4];
int max1=INT_MIN;
void dfs(int k,int sum) {
	if(k==n+1) {
		max1=max(sum,max1);
		return ;
	}
	for(int i=1; i<=3; i++) {
		if(flag[i]+1<=n/2) {
			sum=sum+a[i][k];
			flag[i]++;
			dfs(k+1,sum);
			sum-=a[i][k];
			flag[i]--;
		}
	}
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		cin>>n;
		memset(a,0,sizeof a);
		memset(flag,0,sizeof flag);
		max1=INT_MIN;
		int flag3=0,flag2=0;
		for(int i=1; i<=n; i++) {
			cin>>a[1][i]>>a[2][i]>>a[3][i];
			tmp[i]=a[1][i];
			if(a[2][i]!=0) flag2=1;
			if(a[3][i]!=0) flag3=1;
		}
		if(flag2==0&&flag3==0){
			sort(tmp+1,tmp+1+n);
			cout<<tmp[n]+tmp[n-1]<<endl;
			continue;
		}
		dfs(1,0);
		cout<<max1<<endl;
	}
	return 0;
}
