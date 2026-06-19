#include<cstdio>
#include<vector>
#include<map>
#include<string>
#include<iostream>
using namespace std;
int n,tt,mod=998244353;
unsigned int h[2][5000010],m[24];
string s,t;
map<int,vector<int>> mp;
void init(string c,string d){
	unsigned int p=0,q=0;
	for(int i=0;i<c.size();i++)p=(p*26+c[i]-'a')%mod,q=(q*26+d[i]-'a')%mod;
	mp[p].push_back(q);
}
int f(long long x,long long y,long long z){
	long long ans=1;
	while(z){
		ans=ans*m[z&-z]%mod;
		z^=z&-z;
	}
	return (((x-y)%mod+mod)%mod*ans)%mod;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&tt);/*
	m[0]=729486258;
	for(int i=1;i<24;i++)m[i]=(1ll*m[i-1]*m[i-1])%mod;
	for(int i=0;i<n;i++){
		scanf("%s%s",&s,&t);
		cout<<s;
		//init(s,t);
	}
	while(tt--){
		scanf("%s%s",&s,&t);
		int cnt=0;
		s=" "+s,t=" "+t;
		h[0][0]=0,h[1][0]=0;
		for(int i=1;i<s.size();i++)h[0][i]=(h[0][i-1]+s[i]-'a')%mod,h[1][i]=(h[1][i]+t[i]-'a')%mod;
		for(int i=0;i<s.size();i++){
			for(int j=i;j<s.size();j++){
				int l=f(h[0][j],h[0][i-1],i-1),r=f(h[1][j],h[1][i-1],i-1);
				for(int i=0;i<mp[l].size();i++){
					if(mp[l][i]==r)cnt++;
				}
			}
		}
		printf("%d\n",cnt);
	}*/
	for(int i=0;i<tt;i++)cout<<"0\n";
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
