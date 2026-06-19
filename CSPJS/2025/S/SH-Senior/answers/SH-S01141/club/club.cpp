#include<bits/stdc++.h>
using namespace std;
int t,n,a[100086][4],b[100086],cnt[4],ans;
void dfs(int k,int ct){
	if(k==n+1){
		ans=max(ans,ct);
		return;
	}
	for(int i=1;i<=3;i++)
		if(cnt[i]<n/2){
			cnt[i]++;
			dfs(k+1,ct+a[k][i]);
			cnt[i]--;
		}
	return;
}
void solve_A(){
	for(int i=1;i<=n;i++) b[i]=a[i][1];
	sort(b+1,b+n+1);
	for(int i=n;i>n/2;i--) ans+=b[i];
}
void solve_B(int k,int ct){
	if(k==n+1){
		ans=max(ans,ct);
		return;
	}
	for(int i=1;i<=2;i++)
		if(cnt[i]<n/2){
			cnt[i]++;
			dfs(k+1,ct+a[k][i]);
			cnt[i]--;
		}
	return;
}
void solve(){
	cnt[1]=0; cnt[2]=0; cnt[3]=0; ans=0;
	bool B=1,C=1;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		if(a[i][2]) B=0;
		if(a[i][3]) C=0;
	}
	if(B&&C) solve_A();
	else if(C) solve_B(1,0);
	else dfs(1,0);
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++) solve();
	return 0;
}
