#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define up(i,a,b) for (ll i=(a);i<=(b);++i)
#define down(i,a,b) for (ll i=(a);i>=(b);--i)
const ll N=2e5+10;
const ll P=29;
ll n,Q;
struct Coupl{
	string s[2];
	ll len;
	ull hsh[2];
	bool operator <(const Coupl &b) const{
		return len<b.len;
	}
} coup[N];
ull powAns[N];
void GetPowAns() {
	powAns[0]=1;
	up(i,1,N-1) {
		powAns[i]=powAns[i-1]*P; 
	}
}
ll hshS[N],hshT[N];
void getHsh(string &s,ll lens,ll* hsh) {
	up(i,0,lens-1) {
		ll x=(s[i]-'a'+1);
		hsh[i]=hsh[i-1]*P+x;
	}
}
ll GetHshSingle(string &s,ll lens) {
	ll hsh=0;
	up(i,0,lens-1) {
		ll x=(s[i]-'a'+1);
		hsh=hsh*P+x;
	}	
	return hsh;
}
ll retHsh(ll* hshA,ll lA,ll rA) {
	ll lenA=rA-lA+1;
	if (lenA<=0) {
		return 0;
	}
	ll ansA=hshA[rA]-hshA[lA-1]*powAns[lenA];
	return ansA;
}
bool isSame(ll* hshA,ll* hshB,ll lA,ll rA,ll lB,ll rB) {
	ll lenA=rA-lA+1;
	ll lenB=rB-lB+1;
	if (lenA!=lenB) return false;
	ll ansA=retHsh(hshA,lA,rA);
	ll ansB=retHsh(hshB,lB,rB);
	return ansA==ansB;
}
namespace BF{
	void solve() {
		while (Q--) {
			string S,T;
			cin>>S>>T;
			ll lenS=S.size();
			ll lenT=T.size();
			getHsh(S,lenS,hshS);
			getHsh(T,lenT,hshT);
			if (lenS!=lenT) {
				cout<<"0\n";
				continue;
			}
			ll ans=0;
			up(k,1,n) {
				up(i,0,lenS-1) {
					ll j=i+coup[k].len-1; //Ìæ»»[i,j] 
					if (j>lenS-1) break;
					if (i>0 && !isSame(hshS,hshT,0,i-1,0,i-1)) continue;
					if (j<lenS-1 && !isSame(hshS,hshT,j+1,lenS-1,j+1,lenS-1)) continue;
					if (retHsh(hshS,i,j)==coup[k].hsh[0] && retHsh(hshT,i,j)==coup[k].hsh[1]) {
						++ans;
					} 
				}
			}
			cout<<ans<<'\n';
		}
	}
}
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>Q;
	up(i,1,n) {
		cin>>coup[i].s[0]>>coup[i].s[1];
		coup[i].len=coup[i].s[0].size();
		coup[i].hsh[0]=GetHshSingle(coup[i].s[0],coup[i].len);
		coup[i].hsh[1]=GetHshSingle(coup[i].s[1],coup[i].len);
	}
	sort(coup+1,coup+n+1);
	GetPowAns();
	if (n<=100 && Q<=100) {
		BF::solve();
		return 0;
	}
	return 0;
}

