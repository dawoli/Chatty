#include<bits/stdc++.h>
using namespace std;
int n,m;
string s1[200010],s2[200010],a,b;
inline int exist(string x,string y){
	if(x.size()<y.size())return -1;
	if(x==y)return 0;
	
	for(int k=0;k<x.size();k++){
		int now=k;
		bool flag=1;
		for(int j=0;j<y.size();j++,now++){
			if(x[now]!=y[j]){flag=0;}
		}
		if(flag)return k;
	}
	return -1;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>s1[i]>>s2[i];
	if(m!=1||n>1e4){
		for(int i=1;i<=m;i++)cout<<"0\n";
	}
	while(m--){
		cin>>a>>b;
		int ans=0;
		if(a.size()!=b.size()){cout<<"0\n";continue;}
		for(int i=1;i<=n;i++){
			string c=a;
			int st=exist(c,s1[i]);
			if(st!=-1){
				for(int j=st,k=0;j<st+s2[i].size();j++,k++)c[j]=s2[i][k];
				if(c==b)ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
