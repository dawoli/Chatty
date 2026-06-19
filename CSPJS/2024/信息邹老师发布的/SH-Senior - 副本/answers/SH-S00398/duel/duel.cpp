#include<bits/stdc++.h>
using namespace std;
int n,minn=0,ans;
int mons[100005];
bool attacked[100005];
bool visited[100005];
void solve(){
	for(int i=0;i<n;i++){
		if(mons[i]>mons[minn] and attacked[i]==0){
			visited[minn]=1;
			minn+=1;
			attacked[i]=1;
		}
	}
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>mons[i];
	}
	sort(mons,mons+n);
	solve();
	for(int i=0;i<n;i++){
		if(visited[i]) ans++;
	}
	cout<<n-ans<<endl;
	return 0;
}
