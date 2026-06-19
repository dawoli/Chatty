#include<bits/stdc++.h>
using namespace std;

void FileIO(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
}
#define ll long long
const int N=2e5+5;

int n,q;
map<string,string> mp;
bool flag=0;

void solve(){
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s,t; cin>>s>>t;
		mp[s]=t;
	}
	for(int i=1;i<=q;i++){
		int ans=0;
		string s,t,x=""; cin>>s>>t;
		int n=s.length();
		for(int l=0;l<n;l++){
			string y="";
			for(int len=1;l+len-1<n;len++){
				y+=s[l+len-1];
				string z=s.substr(l+len);
				if(mp[y]=="") continue;
				string new_s=x+mp[y]+z;
				if(new_s==t) ans++; 
			} 
			x+=s[l];
		} 
		cout<<ans<<"\n";
	}
	
	return;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	FileIO();
	
	int T=1;
	while(T--){
		solve();
	}

	return 0;
}

