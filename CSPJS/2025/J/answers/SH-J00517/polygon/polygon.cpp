#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const long long MOD=998244353;
int a[1000009];
bool vst[1000009];
vector<int>v;
bool check(){
	int mx=0;
	ll sum=0;
	for(int i=0;i<v.size()-1;i++)if(v[i]>v[i+1])return 0;
	for(int i=0;i<v.size();i++){
		sum+=v[i];
		mx=max(mx,v[i]);
	}
	return sum>mx*2;
}
long long cnt=0;
int lim=0;
int n;
void dfs(int pos){
	if(pos>lim){
		if(check()){
			cnt=(cnt+1)%MOD;
		}
		return;
	}
	for(int i=pos;i<=n;i++){
		if(!vst[i]){
			vst[i]=1;
			v.push_back(a[i]);
			dfs(pos+1);
			v.pop_back();
			vst[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(lim=3;lim<=n;lim++){
		dfs(1);
	}
	cout<<cnt;
	return 0;
}


