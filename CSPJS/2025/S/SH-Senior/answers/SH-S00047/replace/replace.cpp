#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200005][3];
string t1,t2;
bool check(string a,string b){
	if(a.size()<b.size()) return 0;
	int cur=0;
	for(int i=0;i<a.size();i++){
		if(a[i]==b[cur]){
			cur++;
			if(cur==b.size()) return 1;
		}
		else cur=0;
	}
	return 0;
}
string rep(string a,string b,string c){
	int cur=0,id=0;
	for(int i=0;i<a.size();i++){
		if(a[i]==b[cur]){
			if(cur==0) id=i;
			cur++;
			if(cur==b.size()) break;
		}
		else cur=0;
	}
	cur=0;
	for(int i=id;i<=id+b.size()-1;i++)
		a[i]=c[cur++];
	return a;
}
int main(){
	freopen("replace.in","r",stdin);freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	while(q--){
		cin>>t1>>t2;
		int ans=0;
		for(int i=1;i<=n;i++){
			if(!check(t1,s[i][1])) continue;
			if(rep(t1,s[i][1],s[i][2])==t2) ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
