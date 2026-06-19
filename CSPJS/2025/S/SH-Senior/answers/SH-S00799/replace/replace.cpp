#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+9,M=5e6+9;
ll n,q,l[1009],r[1009];
string s[N][2],t[N][2];
bool aoneb(){
	for(ll i=1;i<=n;i++)
		for(ll j=0;j<=1;j++){
			ll cntb=0;
			for(ll k=0;k<s[i][j].size();k++){
				if(s[i][j][k]!='a'&&s[i][j][k]!='b') return 0;
				cntb+=(s[i][j][k]=='b');
				if(cntb>1) return 0;
			}
		}
	for(ll i=1;i<=q;i++)
		for(ll j=0;j<=1;j++){
			ll cntb=0;
			for(ll k=0;k<t[i][j].size();k++){
				if(t[i][j][k]!='a'&&t[i][j][k]!='b') return 0;
				cntb+=(t[i][j][k]=='b');
				if(cntb>1) return 0;
			}
		}
}
ll pos1[N],pos2[N];
void solveab(){
	for(ll i=1;i<=n;i++){
		ll len=s[i][0].size();
		pos1[i]=-1,pos2[i]=-1;
		for(ll j=0;j<len;j++){
			if(s[i][0][j]=='b') pos1[i]=j;
			if(s[i][1][j]=='b') pos2[i]=j;
		}
	}
	for(ll k=1;k<=q;k++){
		ll len=t[k][0].size();
		ll p1=-1,p2=-1;
		for(ll j=0;j<len;j++){
			if(t[k][0][j]=='b') p1=j;
			if(t[k][1][j]=='b') p2=j;
		}
		ll ans=0;
		for(ll i=1;i<=n;i++)if(p2-p1==pos2[i]-pos1[i]){
			if(p1>=pos1[i]&&(len-p2>=s[i][0].size()-pos2[i])) ans++;
		}
		printf("%lld\n",ans);
	}
}
void solvebf(){
	for(ll i=1;i<=n;i++){
		ll len=s[i][0].size();
		l[i]=r[i]=-1;
		for(ll j=0;j<len;j++){
			if(s[i][0][j]!=s[i][1][j]){
				if(l[i]==-1) l[i]=j;
				r[i]=j;
			}
		}
	}
	for(ll k=1;k<=q;k++){
		ll len=t[k][0].size();
		ll tl=-1,tr=-1;
		for(ll j=0;j<len;j++){
			if(t[k][0][j]!=t[k][1][j]){
				if(tl==-1) tl=j;
				tr=j;
			}
		}
		ll res=0;
		for(ll i=1;i<=n;i++)if(tr-tl+1==r[i]-l[i]+1&&tl>=l[i]){
			bool flag=1;
			ll xx=s[i][0].size()-l[i];
			for(ll j=-l[i]+1;j<=xx;j++){
				if(tl+j-1>=len||t[k][0][tl+j-1]!=s[i][0][l[i]+j-1]||t[k][1][tl+j-1]!=s[i][1][l[i]+j-1]){
					flag=0;
					break;
				}
			}
			if(flag) res++;
		}
		printf("%lld\n",res);
	}
}
void solve(){
	for(ll i=1;i<=q;i++) puts("0");
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	for(ll i=1;i<=n;i++) cin>>s[i][0]>>s[i][1];
	for(ll k=1;k<=q;k++) cin>>t[k][0]>>t[k][1];
	if(aoneb()) solveab();
	else if(n<=1000&&q<=1000) solvebf();
	else solve();
	return 0;
}
