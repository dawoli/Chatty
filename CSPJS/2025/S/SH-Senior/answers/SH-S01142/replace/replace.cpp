#include<bits/stdc++.h>
using namespace std;
#define int long long
//一开始理解错题意了，只能使用一个谐音，不能同时用很多个
//太好了可以暴力做，我有救了 
int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return x*f;
}
int n,q;
struct node{
	string s1,s2;
}s[200005];
signed main(){//replace
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),q=read();
	for(int i=1;i<=n;i++){
		cin>>s[i].s1>>s[i].s2;
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<"\n";
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			string s1=s[i].s1,s2=s[i].s2;
			if(s1.size()>t1.size())continue;
			for(int j=0;j<t1.size()-s1.size()+1;j++){
				bool ok=1;
				for(int k=j;k<j+s1.size();k++){
					if(t1[k]!=s1[k-j]){
						ok=0;
						break;
					}
				}
				if(ok){
//					cout<<i<<"\n";
					string t=t1;
					for(int k=j;k<j+s1.size();k++)t[k]=s2[k-j];
//					cout<<t<<"\n";
					if(t==t2)ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

