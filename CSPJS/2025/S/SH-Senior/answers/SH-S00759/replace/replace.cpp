#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,b) for(ll i=(a);i<=(b);++i)
#define Rep(i,a,b) for(ll i=(b);i>=(a);--i)
#define all(x) x.begin(),x.end()
#define ld long double
#define ull unsigned long long
#define cll const long long
#define Set(x,y) memset(x,y,sizeof(x))
#define Cpy(x,y) memcpy(x,y,sizeof(x))
using namespace std;
bool st;
cll N=200009,BS=9982443535353,L=5e6+9;
string S1[N],S2[N],t1[N],t2[N]; ll n,m; ull p[L];
bool SP(string s){
	ll len=s.size();
	rep(i,0,len-1)if(s[i]!='a'&&s[i]!='b')return 0;
	ll c=0; rep(i,0,len-1)if(s[i]=='b')c++;
	return c==1;
}
struct Node{
	ll llen,rlen,id;
	ull L,R;//string m1,m2;
};
map<pair<ull,ull>,vector<Node>> mp;
ull lh[N],rh[N];
ll x[140];
ll v(char c){return x[c];}
void work(){
	ll n,m;cin>>n>>m; 
	p[0]=1;rep(i,1,L-1)p[i]=p[i-1]*BS;
	mt19937 rnd(time(0));
	rep(i,0,139)x[i]=rnd()%BS;
	rep(i,1,n){
		string s1,s2;cin>>s1>>s2; S1[i]=s1,S2[i]=s2;
		ll len=s1.size();
		ll Lp=0,Rp=0; ull hm1=0,hm2=0,hl=0,hr=0;
		rep(j,0,len-1){
			if(s1[j]!=s2[j]){Lp=j; break;}
			hl+=p[j]*v(s1[j]);
		}
		Rep(j,0,len-1){
			if(s1[j]!=s2[j]){Rp=j; break;}
			hr+=p[len-j-1]*v(s1[j]);
		} 
		rep(j,Lp,Rp){
			hm1+=p[j-Lp]*v(s1[j]),hm2+=p[j-Lp]*v(s2[j]);
		}
		mp[{hm1,hm2}].push_back((Node){Lp,len-Rp-1,i,hl,hr});
	}
	rep(i,1,m){
		string t1,t2;cin>>t1>>t2; ll len=t1.size();
		ll Lp=0,Rp=0; ull hm1=0,hm2=0; lh[0]=rh[len]=0;
		rep(j,0,len-1){
			if(t1[j]!=t2[j]){Lp=j; break;}
			lh[j+1]=lh[j]+p[j]*v(t1[j]);
		}
		Rep(j,0,len-1){
			if(t1[j]!=t2[j]){Rp=j; break;}
			rh[j]=rh[j+1]+p[len-j-1]*v(t1[j]);
		}
		rep(j,Lp,Rp)hm1+=p[j-Lp]*v(t1[j]),hm2+=p[j-Lp]*v(t2[j]); Lp--,Rp++;
		vector<Node> vc=mp[{hm1,hm2}];
		ll ans=0;
		for(auto x:vc){
			ll lp=x.llen,rp=x.rlen,id=x.id;
			lp=Lp-lp+1, rp=Rp+rp-1;
			if(lp<0||rp>=len)continue;
			if(lh[Lp+1]-lh[lp]==x.L*p[lp]&&rh[Rp]-rh[rp+1]==x.R*p[len-rp-1]){
//				if(S1[id]==t1.substr(lp,S1[id].size())&&S2[id]==t2.substr(lp,S2[id].size())) 
				ans++;
			}
		}
		cout<<ans<<endl;
	}
}
bool ed;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	ll T=1;//cin>>T;
	while(T--)work();
	return 0;
}

