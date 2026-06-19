#include<bits/stdc++.h>
using namespace std;
void file(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
}
string s[200005][2],t[200005][2];
int n,nQ;
void solve_BF(){
	for(int iQ=1;iQ<=nQ;iQ++){
	//	cout<<iQ<<endl;
		int res=0;
		if(t[iQ][0].size()!=t[iQ][1].size()){cout<<0<<endl;continue;}
		int l=t[iQ][0].size();
		for(int i=1;i<=n;i++){
			int len=s[i][0].size();
			for(int p=0;p+len-1<l;p++){
				if(t[iQ][0].substr(p,len)!=s[i][0])continue;
				string x=t[iQ][0].substr(0,p);
				string y=s[i][1];
				string z=t[iQ][0].substr(p+len);
				string tp=x+y+z;
			//	cout<<tp<<endl;
				if(tp==t[iQ][1])res++;
			}
		}
		cout<<res<<endl;
	}
}
int main(){
	file();
	cin>>n>>nQ;
	for(int i=1;i<=n;i++)cin>>s[i][0]>>s[i][1];
	for(int i=1;i<=nQ;i++)cin>>t[i][0]>>t[i][1];
	solve_BF();
	return 0;
}
