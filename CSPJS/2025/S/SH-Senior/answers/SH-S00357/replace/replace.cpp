#include<bits/stdc++.h>
using namespace std;
int n,m;
string s[200005];
map<string,string> re;
inline int find(string a,string b){
	int cnt=0,st=0;
	if(a.length()<b.length())return -1;
	for(int i=0;i<a.length();i++){
		if(b[cnt]==a[i]){
			cnt++;
			if(cnt+1==b.length())return st;
		}
		else {
			st=i+1;
			cnt=0;
		}
	}
	return -1;
}
inline string replace(string a,string b,int in){
	string c=a;
	for(int i=in;i<in+b.length();i++){
		c[i]=b[i-in];
	}
	return c;
}
inline bool cmp(string a,string b){
	if(a.length()!=b.length())return 0;
	for(int i=0;i<a.length();i++){
		if(a[i]!=b[i])return 0;
	}
	return 1;
}
int main(){
	freopen("replace.in","r",stdin);freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		string t;
		cin>>s[i]>>t;
		re[s[i]]=t;
	}
	for(int i=1;i<=m;i++){
		string t1,t2;
		cin>>t1>>t2;
		int ans=0;
		for(int j=1;j<=n;j++){
			int now=find(t1,s[j]);
//			cout<<t1<<" "<<s[j]<<" "<<now<<"\n";
			if(now!=-1){
				string c=replace(t1,re[s[j]],now);
				if(cmp(c,t2))ans++;
			}
		}
		cout<<ans<<"\n";
	}
}
