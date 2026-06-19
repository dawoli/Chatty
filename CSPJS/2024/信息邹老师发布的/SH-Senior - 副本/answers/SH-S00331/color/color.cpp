#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,t,a[N],ans,lb,lr;
bool s[N];//1 red 0 blue
void sync(){
	ios::sync_with_stdio(0);
	cin.tie(NULL),cout.tie(NULL);
}
void freopen(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
}
void dfs(int x){
	if(x==n+1){
		int mid=0,lb=0,lr=0;
		for(int i=1;i<=n;i++){
			if(s[i]){
				if(lr==a[i]) mid+=a[i];
				lr=a[i];
			}
			else{
				if(lb==a[i]) mid+=a[i];
				lb=a[i];
			}
		//	cout<<mid<<" ";
		}
		ans=max(ans,mid);
	//	cout<<"\n";
		return;
	} 
	s[x]=1;
	dfs(x+1);
	s[x]=0;
	dfs(x+1);
	return;
}
int main(){
	freopen();
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		dfs(1);
		cout<<ans<<"\n";
	}
	return 0;
}
