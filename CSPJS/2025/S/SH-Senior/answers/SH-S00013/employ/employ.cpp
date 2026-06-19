#include<bits/stdc++.h> 
using namespace std;
const int maxn=505,mod=998244353;
int n,m,num=0,ans,c[maxn]; 
string di;

bool check(string di){
	for(int i=0;i<di.length();i++){
		if(di[i]==0) return false;
	}
	return true;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>di;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0) num++;
	}
	if(check(di)){
		if((n-num)<m) cout<<0;
		else{
			ans=1;
			for(int i=n;i>1;i--){
				ans*=(n%mod);
				ans%=mod;
			}
			cout<<ans;
		}
	}
	return 0;
}
