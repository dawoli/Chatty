#include<bits/stdc++.h>
using namespace std;
#define N 200007 
#define M 1145141
#define ll unsigned long long
int n,m;
string s[N],t[N];
ll hsh1[N],hsh2[N];
int l[N];
ll pw[N];
int ksm(int a,int b){
	int ans=a%M;
	while(b){
		if(b&1) ans=ans*a%M;
		a=a*a%M;
		b>>=1;
	}
}
int main(){
	pw[0]=1;
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		pw[i]=pw[i-1]*M;
		cin>>s[i]>>t[i];
		l[i]=s[i].size();
		s[i]=" "+s[i]; 
		t[i]=" "+t[i];
		ll res=0;
		for(int j=1;j<=l[i];++j){
			res=res*M+s[i][j]-'0';
		}
		hsh1[i]=res;
		res=0;
		for(int j=1;j<=l[i];++j){
			res=res*M+t[i][j]-'0';
		}
		hsh2[i]=res;
	}
	//cerr<<"I AK CSP\n";
	vector<ll> hsh[2];
	while(m--){
		int ans=0;
		string a,b;
		cin>>a>>b;
		//cerr<<a<<'|'<<b<<'\n'; 
		int nn=a.size(),mm=b.size();
		if(nn!=mm){
			cout<<0<<'\n';
			continue;
		}
		a=' '+a,b=' '+b;
		int lll=1,rrr=n;
		while(lll<=nn&&a[lll]==b[lll]) ++lll;
		while(rrr>0&&a[rrr]==b[rrr]) --rrr;
		hsh[0].push_back(0);
		for(int j=1;j<=nn;++j){
			hsh[0].push_back(hsh[0][j-1]*M+a[j]-'0');
		}
		hsh[1].push_back(0ull);
		for(int j=1;j<=nn;++j){
			hsh[1].push_back(hsh[1][j-1]*M+b[j]-'0');
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=lll&&j+l[i]-1<=nn;++j){
				int k=j+l[i]-1;
				if(j+l[i]-1>=rrr){
					ll kk=hsh[0][k]-hsh[0][j-1]*pw[k-j+1];
					ll llll=hsh[1][k]-hsh[1][j-1]*pw[k-j+1];
					if(kk==hsh1[i]&&llll==hsh2[i]) ++ans;
				}
			}
		}
		while(hsh[0].size()){
			hsh[0].pop_back();
			hsh[1].pop_back();
		}
		cout<<ans<<'\n';
		 
		//cerr<<"I AK CSP\n";
	}
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

3 4
a b
b c
c d
aa bb
aa b
a c
b a


¾¡Á¦ÁË 
*/
