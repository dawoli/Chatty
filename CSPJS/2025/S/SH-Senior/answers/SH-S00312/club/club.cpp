#include<bits/stdc++.h>
using namespace std;
int a[100001],b[100001],c[100001];
int n,maxn=0;
void dfs(int s1,int s2,int s3,int sum,int step){
	if(step>n){
		maxn=max(maxn,sum);
		return ;
	}
	if(n/2>s1) dfs(s1+1,s2,s3,sum+a[step],step+1);
	if(n/2>s2) dfs(s1,s2+1,s3,sum+b[step],step+1);
	if(n/2>s3) dfs(s1,s2,s3+1,sum+c[step],step+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		maxn=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		dfs(0,0,0,0,1);
		cout<<maxn<<endl;
	}
	return 0;
}
