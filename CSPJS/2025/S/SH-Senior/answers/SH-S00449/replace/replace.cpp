#include<bits/stdc++.h>
#define mod 23456789
#define int long long
#define N 200009
using namespace std;
map<int,int> s,vst;
string aa[N][2];
int n,q,szs[N];
int hsh(string s){
	int ret=0;
	for(int i=0;i<s.size();i++){
		ret=(ret*27+s[i]-'a'+1)%mod;
	}
	return ret;
}
int qpow(int x,int y){
	if(y==1)return x;
	if(y==0)return 1;
	int k=qpow(x,y/2);
	if(y%2==1)return (((k*k)%mod)*x)%mod;
	else return (k*k)%mod;
}
int mmax(int x,int y){return x>y?x:y;}
int mmin(int x,int y){return x<y?x:y;}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>q;
	int cnt=0;
	for(int i=1;i<=n;i++){
		string x,y;
		cin>>x>>y;
		s[hsh(x)*mod+hsh(y)]++;
		aa[i][0]=x,aa[i][1]=y;
		if(vst[x.size()]!=1){
			szs[++cnt]=x.size();
			vst[x.size()]=1;
		}
	}
	sort(szs+1,szs+1+cnt);
//	cout<<"ok"<<endl;
	for(int tt=1;tt<=q;tt++){
		string x,y;
		cin>>x>>y;
		if(x.size()!=y.size()){cout<<0<<"\n";continue;}
		int a=-1,b;
		for(int k=0;k<x.size();k++)if(x[k]!=y[k]){
			if(a==-1)a=k;
			b=k;
		}
		//x.size()<=2299
		if(0){
			int sz=x.size();
			int ans=0,hx=0,hy=0;
			for(int i=0;i<=a;i++){
				hx=0,hy=0;
				for(int j=i;j<b;j++)hx=(hx*27+x[j]-'a'+1)%mod,hy=(hy*27+y[j]-'a'+1)%mod;
//				cout<<hx<<' '<<hy<<endl;
				for(int j=b;j<sz;j++){
					hx=(hx*27+x[j]-'a'+1)%mod,hy=(hy*27+y[j]-'a'+1)%mod;
					ans+=s[hx*mod+hy];
				}
			}
			cout<<ans<<"\n";
		}
		else{
			int ans=0;
			for(int i=1;i<=cnt;i++){
//				cout<<i<<endl;
				int sz=szs[i];
				if(sz<b-a+1)continue;
				if(sz>x.size())break;
				int hx=0,hy=0;
				for(int j=mmax(0,b-sz+1);j<mmax(0,b-sz+1)+sz-1;j++){
					hx=(hx*27+x[j]-'a'+1)%mod,hy=(hy*27+y[j]-'a'+1)%mod;
				}
				for(int j=mmax(0,b-sz+1)+sz-1;j<=mmin(x.size()-1,a+sz-1);j++){
					hx=(hx*27+x[j]-'a'+1)%mod,hy=(hy*27+y[j]-'a'+1)%mod;
//					cout<<hx<<' '<<hy<<endl;
//					cout<<x[j]<<' '<<x[j-sz]<<' '<<y[j]<<' '<<y[j-sz]<<endl;
					if(j!=mmax(0,b-sz+1)+sz-1)hx=(((hx-(x[j-sz]-'a'+1)*qpow(27,sz))%mod)+mod)%mod,hy=(((hy-(y[j-sz]-'a'+1)*qpow(27,sz))%mod)+mod)%mod;
//					cout<<hx<<' '<<hy<<endl;
					ans+=s[hx*mod+hy];
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}

