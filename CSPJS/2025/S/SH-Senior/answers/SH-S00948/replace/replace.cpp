#include<bits/stdc++.h>
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define el <<"\n"
#define fi first
#define sc second
using namespace std;
typedef long long ll;
const ll P1=131,P2=137;
const ll mod1=998244353,mod2=1e9+7;
string s1[200005],s2[200005];
ll pow1[1000005],pow2[1000005];
pair<ll,ll> hsh1[200005],hsh2[200005],hsh3[200005],hsh4[200005];
map<pair<ll,ll>,vector<int>> M;
pair<ll,ll> Hsh(string s){
	ll a=0,b=0;
	for(char c:s){
		a=a*P1+c;
		b=b*P2+c;
		a%=mod1;
		b%=mod2;
	}
	return {a,b};
}
pair<ll,ll> operator -(pair<ll,ll> A,pair<ll,ll> B){
	return {((A.fi-B.fi)%mod1+mod1)%mod1,((A.sc-B.sc)%mod2+mod2)%mod2};
}
pair<ll,ll> operator *(pair<ll,ll> A,ll B){
	return {A.fi*pow1[B]%mod1,A.sc*pow2[B]%mod2};
}
pair<ll,ll> operator +(pair<ll,ll> A,pair<ll,ll> B){
	return {(A.fi+B.fi)%mod1,(A.sc+B.sc)%mod2};
}
void log(pair<ll,ll> A){
	cout<<"<"<<A.fi<<" "<<A.sc<<"> ";
}
pair<ll,ll> substr(pair<ll,ll>*A,ll l,ll r){
	return A[l+r-1]-A[l-1]*r;
}
pair<ll,ll> add(pair<ll,ll>A,pair<ll,ll>B,int size_B){
	return A*size_B+B;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	pow1[0]=pow2[0]=1;
	rep(i,1,1000000){
		pow1[i]=pow1[i-1]*P1%mod1;
		pow2[i]=pow2[i-1]*P2%mod2;
	}
	int n,q;
	cin>>n>>q;
	rep(i,1,n){
		cin>>s1[i]>>s2[i];
		hsh1[i]=Hsh(s1[i]);
		hsh2[i]=Hsh(s2[i]);
		ll mi=1e9,ma=0;
		rep(j,0,s1[i].size()-1){
			if(s1[i][j]!=s2[i][j]){
				mi=min(j,mi);
				ma=max(j,ma);
			}
		}
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<"0\n";
			continue;
		}
		rep(i,0,t1.size()-1){
			if(i==0){
				hsh3[i].fi=hsh3[i].sc=t1[0];
			}else{
				hsh3[i].fi=hsh3[i-1].fi*P1+t1[i];
				hsh3[i].fi%=mod1;
				hsh3[i].sc=hsh3[i-1].sc*P2+t1[i];
				hsh3[i].sc%=mod2;
			}
			if(i==0){
				hsh4[i].fi=hsh4[i].sc=t2[0];
			}else{
				hsh4[i].fi=hsh4[i-1].fi*P1+t2[i];
				hsh4[i].fi%=mod1;
				hsh4[i].sc=hsh4[i-1].sc*P2+t2[i];
				hsh4[i].sc%=mod2;
			}
		}
		ll mi=1e9,ma=0;
		rep(i,0,t1.size()-1){
			if(t1[i]!=t2[i]){
				mi=min(i,mi);
				ma=max(i,ma);
			}
		}
		int ans=0;
		rep(i,0,t1.size()-1){
			rep(j,1,n){
//				cout<<t1.substr(i,s1[j].size())<<" ";
//				log((hsh3[i+s1[j].size()-1]-(hsh3[i-1]*s1[j].size())));cout el;
				if(i+s1[j].size()<=t1.size()&&substr(hsh3,i,s1[j].size())==hsh1[j]){
					string t=t1.substr(0,i)+s2[j]+t1.substr(i+s1[j].size());
//					cout<<i<<" "<<j<<" ";
//					log(substr(hsh3,0,i));
//					log(hsh2[j]);
//					log(substr(hsh3,i+s1[j].size(),t1.size()-i-s1[j].size()));
//					cout el;
					if(add(add(substr(hsh3,0,i),hsh2[j],s1[j].size()),
					substr(hsh3,i+s1[j].size(),t1.size()-i-s1[j].size()),t1.size()-i-s1[j].size())==hsh4[t2.size()-1]){
						ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
}
