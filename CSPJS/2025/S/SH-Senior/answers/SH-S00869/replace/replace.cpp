#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
string s[N][2],t[N][2];
int solve(string st,string goal){
	int cnt=0;
	string s1=st,s2=goal;
	for(int i=1;i<=n;i++){
		int len=s[i][0].size();
		if(s1.size()<len) continue;
		for(int j=0;j<=s1.size()-len;j++){
			if(s1.substr(j,len)==s[i][0]){
				string cps=s1; cps.erase(j,len); cps.insert(j,s[i][1]);
				if(cps==s2) cnt++;
			}
		}
	}
	return cnt;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	for(int i=1;i<=q;i++){
		cin>>t[i][0]>>t[i][1];
		if(t[i][0].size()!=t[i][1].size()) cout<<0<<endl;
		else cout<<solve(t[i][0],t[i][1])<<endl;
	}
	return 0;
}
