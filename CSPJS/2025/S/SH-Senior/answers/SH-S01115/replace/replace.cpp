#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=998244353;
int n,q,len1[1000005],len2[1000005],len3[1000005],c1[5000005],c2[5000005];
string s1,s2,t1,t2;
struct node{
	int hsh1;
	unsigned long long hsh2;
	bool operator==(const node &x)const{
	    return hsh1==x.hsh1&&hsh2==x.hsh2;
	}
}h[5000005],h2[5000005],h3[5000005],h4[5000005];
node calc(int x,int y){
	//cout<<x<<".."<<y<<endl;
	if(x==0) return h2[y];
	return {(h2[y].hsh1-h2[x-1].hsh1*c1[y-x+1]+M*M)%M,h2[y].hsh2-h2[x-1].hsh2*c2[y-x+1]};
}
node calc2(int x,int y){
	if(x==0) return h3[y];
	return {(h3[y].hsh1-h3[x-1].hsh1*c1[y-x+1]+M*M)%M,h3[y].hsh2-h3[x-1].hsh2*c2[y-x+1]};
}
bool check(int x,int st,int ed,int sz){
	//cout<<x<<" "<<h[x].hsh2<<" "<<h4[x].hsh2<<endl;
	return st>=len1[x]&&sz-ed-1>=len2[x]&&ed-st+1==len3[x]&&calc(st-len1[x],ed+len2[x])==h[x]&&calc2(st-len1[x],ed+len2[x])==h4[x];
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	c1[0]=c2[0]=1;
	for(int i=1;i<=5e6;i++){
		c1[i]=c1[i-1]*26%M;
		c2[i]=c2[i-1]*26;
	}
	for(int i=1;i<=n;i++){
		cin>>t1>>t2;
		int st=1e9,ed=0;
		for(int j=0;j<t1.size();j++){
			if(t1[j]!=t2[j]){
				st=min(st,j);
				ed=j;
			}
		}
		if(st==1e9) continue;
		for(int j=0;j<t1.size();j++){
			h[i].hsh1=(h[i].hsh1*26+t1[j]-'a')%M;
			h[i].hsh2=h[i].hsh2*26+t1[j]-'a';
		}
		for(int j=0;j<t2.size();j++){
			h4[i].hsh1=(h4[i].hsh1*26+t2[j]-'a')%M;
			h4[i].hsh2=h4[i].hsh2*26+t2[j]-'a';
		}
		len1[i]=st;
		len2[i]=t1.size()-1-ed;
		len3[i]=ed-st+1;
	}
	for(int i=1;i<=q;i++){
		cin>>s1>>s2;
		if(s1.size()!=s2.size()){
			cout<<0<<endl;
			continue;
		}
		int st=1e9,ed=0;
		for(int j=0;j<s1.size();j++){
			if(s1[j]!=s2[j]){
				st=min(st,j);
				ed=j;
			}
		}
		int ans=0;
		h2[0].hsh1=h2[0].hsh2=s1[0]-'a';
		h3[0].hsh1=h3[0].hsh2=s2[0]-'a';
		for(int j=1;j<s1.size();j++){
			h2[j].hsh1=(h2[j-1].hsh1*26+s1[j]-'a')%M;
			h2[j].hsh2=h2[j-1].hsh2*26+s1[j]-'a';
		}
		for(int j=1;j<s1.size();j++){
			h3[j].hsh1=(h3[j-1].hsh1*26+s2[j]-'a')%M;
			h3[j].hsh2=h3[j-1].hsh2*26+s2[j]-'a';
		}
		for(int j=1;j<=n;j++){
			ans+=check(j,st,ed,s1.size());
			//cout<<j<<" "<<ans<<endl;
		}
		cout<<ans<<endl;
	}
}
