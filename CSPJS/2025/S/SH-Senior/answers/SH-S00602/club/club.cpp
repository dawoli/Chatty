#include<bits/stdc++.h>
using namespace std;
int t,n,p[100010][3];
int dfs(int k){
	int ans=0;
	if (k==n){
		return 0;
	}
	for (int i=0;i<=2;i++){
		if (p[100005][i]<n/2){
			p[100005][i]++;
			ans=max(ans,dfs(k+1)+p[k][i]);
			p[100005][i]--;
		}
	}return ans;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for (int i=0;i<t;i++){
		cin>>n;
		for (int j=0;j<n;j++){
			cin>>p[j][0]>>p[j][1]>>p[j][2];
		}cout<<dfs(0)<<endl;
		
	}return 0;
}
