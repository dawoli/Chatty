#include <bits/stdc++.h>
using namespace std;
int n,q,qw,hw;
string s,str;
map<int,vector<int> >mp;
struct node{
	int q,h,z;
}a[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>s>>str;
		for(int j=0;j<s.size();++j){
			if(s[j]=='b'){
				qw=j;
			}
		}
		for(int j=0;j<str.size();++j){
			if(str[j]=='b'){
				hw=j;
			}
		}
		a[i].z=qw-hw;
		a[i].q=qw;
		a[i].h=n-qw-1;
		mp[a[i].z].push_back(i);
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		cin>>s>>str;
		for(int j=0;j<s.size();++j){
			if(s[j]=='b'){
				qw=j;
			}
		}
		for(int j=0;j<str.size();++j){
			if(str[j]=='b'){
				hw=j;
			}
		}
		int c=qw-hw;
		for(int j=0;j<mp[c].size();++j){
			if(qw>=a[mp[c][j]].q&&s.size()-qw-1>=a[mp[c][j]].h)	ans++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
