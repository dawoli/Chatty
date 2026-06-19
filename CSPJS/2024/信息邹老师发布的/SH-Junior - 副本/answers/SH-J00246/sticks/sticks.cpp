#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,n;
ll a[10]={6,2,5,5,4,5,6,3,7,6};
vector<ll>v;
ll minn=1e17;
ll con(string s){
	stringstream ss;
	ss<<s;
	ll temp;
	ss>>temp;
	return temp;
}
void dfs(ll cur,string s,ll ma,ll sticks){
	if (cur==ma+1){
		if (sticks==n) minn=min(minn,con(s));
		return ;
	}
	if (cur==1){
		for (ll i=1;i<=9;i++){
			dfs(cur+1,s+char(i+'0'),ma,sticks+a[i]);
		}
	}else{
		for (ll i=0;i<=9;i++){
			dfs(cur+1,s+char(i+'0'),ma,sticks+a[i]);
		}
	}
	
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	while (T--){
		cin>>n;
		ll digits=ceil(n/7.0);
		minn=1e17;
		dfs(1,"",digits,0);
		if (minn==1e17) cout<<-1<<endl;
		else cout<<minn<<endl;
	}
	
	
	
	return 0;
} 
