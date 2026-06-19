#include<bits/stdc++.h>
using namespace std;
int n;
int a[100];
int ans;
void dfs(int i,int sum,int num,int mx){
	if(i==n){
		if(num>=3&&sum>2*mx){
			ans++;
		}
		return;
	}
	dfs(i+1,sum,num,mx);
	dfs(i+1,sum+a[i],num+1,max(mx,a[i]));
	return;
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	dfs(0,0,0,0);
	cout<<ans<<endl;
	return 0;
} 
