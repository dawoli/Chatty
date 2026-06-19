//Perhas KMP?
//However,I can't remember how to write it
//......
//CCF PLEASEEEE

#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)

using namespace std;
const int N=2e5+5;
int n,q,p[N];
string a,b;
string s[N][2];
bool repla(string b,string a,string k,string las){
	/*memset(p,0,sizeof(p));
	int la=a.length(),lb=b.length();
	a=a+'#'+b;
	rep(i,la+1,la+lb){
		int j=p[i-1];
		while(j>0&&a[i]!=a[j+1])j=p[j];
		if(a[i]==a[j+1])j++;
		p[i]=j;
		//if(p[i]==la-1)
			cout<<p[i]<<endl;
		//cout<<p[i]<<endl;
	}
	return " ";*/
	int la=a.length(),lb=b.length();
	rep(i,0,la-lb){
		//cout<<a.substr(i,lb)<<endl;
		if(a.substr(i,lb)==b){
			//cout<<a.substr(i,lb)<<endl;
			string tmp="";
			rep(j,0,i-1)tmp+=a[j];
			rep(j,0,lb-1)tmp+=k[j];
			rep(j,i+lb,la-1)tmp+=a[j];
		//	cout<<tmp<<endl;
			if(tmp==las)return true;
		}
	}
	return false;
}
void solve(){
	//string xx,yy;
	//cin>>xx>>yy;
	//repla(xx,yy,"");
//	return;
	cin>>n>>q;
	rep(i,1,n)cin>>s[i][0]>>s[i][1];
	rep(i,1,q){
		cin>>a>>b;
		//if(a.length()!=b.length()){
		//	cout<<0<<endl;
		//	continue;
		//}
		int ans=0;
		rep(j,1,n)
			if(repla(s[j][0],a,s[j][1],b))
				ans++;
		cout<<ans<<endl;
	}
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(false);
	int TEST=1;
	//cin>>TEST;
	while(TEST--)
		solve();
	return 0;
} 
