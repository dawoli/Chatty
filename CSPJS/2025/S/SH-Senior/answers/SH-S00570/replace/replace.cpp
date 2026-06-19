#include<bits/stdc++.h>
#define int long long
using namespace std;
int qpow(int x,int y,int mod){
	if(y==0) return 1;
	int res=qpow(x,y/2,mod);
	if(y%2==0) return res*res%mod;
	else return res*res%mod*x%mod;
}
int n,q;
string st1[1000006];
string st2[1000006];
int pp1=100000007;
int mod1=1000000007;
int pp2=10000019;
int mod2=998244353;
struct fffff{
	int lp;
	int p1;
	int p2;
	int ls;
	int s1;
	int s2;
	int lx;
	int x11;
	int x12;
	int x21;
	int x22;
	bool operator <(const fffff &b)const{
		return x11<b.x11;
	}
} p[1000006];
string t1;
int h11[10000007];
int h12[10000007];
string t2;
int h21[10000007];
int h22[10000007];
int hsh11(int st,int ed){
	return (h11[ed]-(h11[st-1]*qpow(pp1,ed-st+1,mod1)%mod1)+mod1)%mod1;
}
int hsh12(int st,int ed){
	return (h12[ed]-(h12[st-1]*qpow(pp2,ed-st+1,mod2)%mod2)+mod2)%mod2;
}
int hsh21(int st,int ed){
	return (h21[ed]-(h21[st-1]*qpow(pp1,ed-st+1,mod1)%mod1)+mod1)%mod1;
}
int hsh22(int st,int ed){
	return (h22[ed]-(h22[st-1]*qpow(pp2,ed-st+1,mod2)%mod2)+mod2)%mod2;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>st1[i]>>st2[i];
		st1[i]="#"+st1[i];
		st2[i]="#"+st2[i];
	}
	for(int i=1;i<=n;i++){
		int len=st1[i].size()-1;
		bool flag=1;
		int st=0;
		int ed=0;
		for(int j=1;j<=len;j++){
			if(flag&&st1[i][j]!=st2[i][j]){
				flag=0;
				st=j;
			}
			if(st1[i][j]!=st2[i][j]){
				ed=j;
			}
		}
		p[i].lp=st-1;
		p[i].lx=ed-st+1;
		p[i].ls=len-ed;
		for(int j=1;j<st;j++){
			p[i].p1*=pp1;
			p[i].p1+=st1[i][j];
			p[i].p1%=mod1;
			p[i].p2*=pp2;
			p[i].p2+=st1[i][j];
			p[i].p2%=mod2;
		}
		for(int j=st;j<=ed;j++){
			p[i].x11*=pp1;
			p[i].x11+=st1[i][j];
			p[i].x11%=mod1;
			p[i].x12*=pp2;
			p[i].x12+=st1[i][j];
			p[i].x12%=mod2;
			p[i].x21*=pp1;
			p[i].x21+=st2[i][j];
			p[i].x21%=mod1;
			p[i].x22*=pp2;
			p[i].x22+=st2[i][j];
			p[i].x22%=mod2;
		}
		for(int j=ed+1;j<=len;j++){
			p[i].s1*=pp1;
			p[i].s1+=st1[i][j];
			p[i].s1%=mod1;
			p[i].s2*=pp2;
			p[i].s2+=st1[i][j];
			p[i].s2%=mod2;
		}
	}
//	for(int i=1;i<=n;i++){
//		cout<<p[i].lp<<" "<<p[i].p1<<" "<<p[i].lx<<" "<<p[i].x11<<" "<<p[i].x21<<" "<<p[i].ls<<" "<<p[i].s1<<endl;
//	}cout<<endl;
	sort(p+1,p+n+1);
//	for(int i=1;i<=n;i++){
//		cout<<p[i].lp<<" "<<p[i].p1<<" "<<p[i].lx<<" "<<p[i].x11<<" "<<p[i].x21<<" "<<p[i].ls<<" "<<p[i].s1<<endl;
//	}cout<<endl;
	while(q--){
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			puts("0");
		}else{
			t1="#"+t1;
			t2="#"+t2;
			int len=t1.size()-1;
			bool flag=1;
			int st;
			int ed;
			for(int j=1;j<=len;j++){
				h11[j]=(h11[j-1]*pp1+t1[j])%mod1;
				h12[j]=(h12[j-1]*pp2+t1[j])%mod2;
				h21[j]=(h21[j-1]*pp1+t2[j])%mod1;
				h22[j]=(h22[j-1]*pp2+t2[j])%mod2;
				if(flag&&t1[j]!=t2[j]){
					flag=0;
					st=j;
				}
				if(t1[j]!=t2[j]){
					ed=j;
				}
			}
			int lp=st-1;
			int lx=ed-st+1;
			int ls=len-ed;
			int xx11=hsh11(st,ed);
			int xx12=hsh12(st,ed);
			int xx21=hsh21(st,ed);
			int xx22=hsh22(st,ed);
			int l=0;
			int r=n+1;
			while(l<r-1){
				int mid=(l+r)/2;
				if(p[mid].x11<xx11) l=mid;
				else r=mid;
			}
			int cur=r;
			int ans=0;
			while(p[cur].x11==xx11&&cur<=n){
				if(p[cur].x12==xx12&&p[cur].x21==xx21&&p[cur].x22==xx22&&lx==p[cur].lx&&lp>=p[cur].lp&&ls>=p[cur].ls){
					if(hsh11(st-p[cur].lp,st-1)==p[cur].p1&&hsh12(st-p[cur].lp,st-1)==p[cur].p2&&hsh11(ed+1,ed+p[cur].ls)==p[cur].s1&&hsh12(ed+1,ed+p[cur].ls)==p[cur].s2) ans++;
				}
				cur++;
			}
//			cout<<lp<<" "<<st-p[3].lp<<" "<<st-1<<" "<<hsh11(st-p[3].lp,st-1)<<endl;
//			cout<<lx<<" "<<xx11<<" "<<xx21<<" "<<endl;
//			cout<<ls<<" "<<ed+1<<" "<<ed+p[3].ls<<" "<<hsh11(ed+1,ed+p[3].ls)<<endl;
			cout<<ans<<endl;
		}
	}
}
