#include<bits/stdc++.h>
using namespace std;
int t,n,ans,cnt;
int a[100005][4];
int Left[4]; 

void dfs(int cur){
	if(cur>=n+1){
		ans=max(ans,cnt);
		return;
	}
	for(int i=1;i<=3;i++){
		if(Left[i]>0){
			Left[i]--;
			cnt+=a[cur][i];
			dfs(cur+1);
			Left[i]++;
			cnt-=a[cur][i];
		}
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[j][1]>>a[j][2]>>a[j][3];
		}
		for(int j=1;j<=3;j++){
			Left[j]=n/2;
		}
		ans=0;
		cnt=0;
		dfs(1);
		cout<<ans<<endl;
	}
	return 0; 
} 
