#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=100009,L=200009;
ll T,n,k,q,l[N],r[N],c[N];
vector<ll> s[N];
bool hugeflag=0;
//map<pair<ll,ll>,bool> f;
bool c1(){
	for(ll i=1;i<=q;i++) if(r[i]>1) return 0;
	return 1;
}
void solve1(){
	for(ll iq=1;iq<=q;iq++){
		bool bigflag=0;
		for(ll i=1;i<=n;i++){
			ll setr=-1,setp=-1,flag=0;
			for(ll j=0;j<s[i].size();j++){
				if(s[i][j]==c[iq]&&j<=setr&&j>=setp){
					flag=1;
					break;
				}
				if(s[i][j]==1)
					if(c[iq]==1&&j<=setr&&j>=setp){
						flag=1;
						break;
					} 
					else setp=j+1,setr=j+k-1;
			}
			if(flag==1){
				bigflag=1;
				break;
			}
		}
		cout<<bigflag<<endl;
	}
}
//bool cBF(){
//	ll suml=0;
//	for(ll iq=1;iq<=q;iq++){
//		if(r[iq]>10) return 0;
//	}
//	for(ll i=1;i<=n;i++) suml+=l[i];
//	if(suml<=2000&&n<=1000&&q<=1000) return 1;
//	return 0;
//}
//void solveBF(){
//	for(ll rr=2;rr<=maxr;rr++)
//		for(ll i=1;i<=n;i++){
//			for(ll j=0;j<l[i];j++){
//				for(ll k=max(0,j-k+1);k<=j-1;k++){
//					if(f[make_pair(i-1,s[
//				}
//			}
//		}
//}
//void solve11(ll iq){
//	bool bigflag=0;
//		for(ll i=1;i<=n;i++){
//		ll setr=-1,setp=-1,flag=0;
//		for(ll j=0;j<s[i].size();j++){
//			if(s[i][j]==c[iq]&&j<=setr&&j>=setp){
//				flag=1;
//				break;
//				}
//		if(s[i][j]==1)
//					if(c[iq]==1&&j<=setr&&j>=setp){
//						flag=1;
//						break;
//					} 
//					else setp=j+1,setr=j+k-1;
//			}
//			if(flag==1){
//				bigflag=1;
//				break;
//			}
//		}
//	cout<<bigflag<<endl;
//}
bool c23(){
	ll suml=0;
	for(ll iq=1;iq<=q;iq++){
		if(r[iq]>5) return 0;
	}
	for(ll i=1;i<=n;i++) suml+=l[i];
	if(suml<=20&&n<=10&&q<=100) return 1;
	return 0;
}
void dfs(ll ai,ll aj,ll ci,ll rr){
	if(rr==0&&s[ai][aj]==ci){
		hugeflag=1;
	}
	if(rr==0) return ;
	if(hugeflag==1) return ;
	for(ll i=1;i<=n;i++){
		if(i==ai) continue;
		for(ll j=0;j<l[i];j++){
			ll val=s[i][j];
			if(val!=s[ai][aj]) continue;
			for(ll o=j+1;o<=min(l[i]-1,j+k-1);o++){
				dfs(i,o,ci,rr-1);
			}
		}
	}
}
void solve23(){
	s[0].push_back(1);
//	cout<<s[0][0]<<'p'<<endl;
	for(ll iq=1;iq<=q;iq++){
//		if(r[iq]==1){
//		solve11(iq);
//		continue;
//	}
		hugeflag=0;
		dfs(0,0,c[iq],r[iq]);
		if(hugeflag) cout<<1<<endl;
		else cout<<0<<endl;
	}
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>k>>q;
		for(ll i=1;i<=n;i++){
			cin>>l[i];
			for(ll j=1;j<=l[i];j++){
				ll tmp;
				cin>>tmp;
				s[i].push_back(tmp);
			}
		}
		for(ll i=1;i<=q;i++) cin>>r[i]>>c[i];
		if(c1()){
			solve1();
			continue;
		}
//		if(cBF()){
//			solveBF();
//			continue;
//		}
//		if(c23()){
			solve23();
//			continue;
//		}
//		for(ll iq=1;iq<=q;iq++) cout<<0<<endl;
	}
	return 0;
}
