#include<bits/stdc++.h>
using namespace std;
int n;
int a[5010];
int ans;
void dfs(int step,int maxx,int sum,int num){
	if(step>=n) return;
//	cout<<a[step]<<" ";
	if(num>=3&&((maxx*2)<sum)){
		ans++;
		return;
	}
	for(int i=step;i<=n;i++){
		dfs(i+1,max(maxx,a[i]),sum+a[i],num+1);
		dfs(i+1,maxx,sum,num);
	}
	
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1,0,0,1);
	cout<<ans;
	return 0;
} 
