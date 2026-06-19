#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,l,xs;
ll d[113000],v[113000],a[113000];
ll qzh[1000005];
bool jy[1000005];
vector<ll> vj[1000005];
ll zd;
double jl;
set<ll> st;
set<ll>::iterator it;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ll T;
	cin>>T;
	while(T--){
		cin>>n>>m>>l>>xs;
		for(ll i=0;i<=l;i++){qzh[i]=0;jy[i]=0;vj[i].clear();}
		for(ll i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
		}
		for(ll i=1;i<=m;i++){
			ll j;
			cin>>j;
			qzh[j]++;
			jy[j]=1;
		}
		for(ll i=1;i<=l;i++)qzh[i]=qzh[i-1]+qzh[i];
		ll ans=0;
		for(ll i=1;i<=n;i++){
			if(a[i]==0){
				if(v[i]>xs){
					if(qzh[l]-qzh[d[i]-1]>0){
						ans++;
						vj[d[i]].push_back(l);
					}
				}
			}
			else if(a[i]<0){
				if(v[i]<=xs)continue;
				jl=(double((xs*xs)-(v[i]*v[i])))/(double(2*a[i]));
				if(double(floor(jl))==jl)zd=floor(jl)-1;
				else zd=floor(jl);
				zd+=d[i];
				zd=min(zd,l);
				//cout<<i<<" "<<zd<<endl;
				if(qzh[zd]-qzh[d[i]-1]>0){
					ans++;
					vj[d[i]].push_back(zd);
				}
			}
			else{
				if(v[i]>xs){
					if(qzh[l]-qzh[d[i]-1]>0){
						ans++;
						vj[d[i]].push_back(l);
					}
					continue;
				}
				jl=(double((xs*xs)-(v[i]*v[i])))/(double(2*a[i]));
				if(double(ceil(jl))==jl)zd=floor(jl)+1;
				else zd=ceil(jl);
				zd+=d[i];
				if(zd>l)continue;
				if(qzh[l]-qzh[zd-1]>0){
					ans++;
					vj[zd].push_back(l);
				}
			}
		}
		cout<<ans<<" ";
		if(ans==0){
			cout<<m<<endl;
			continue;
		}
		st.clear();
		ll jans=0;
		for(ll i=0;i<=l;i++){
			for(ll o=0;o<vj[i].size();o++)st.insert(vj[i][o]);
			if(st.empty()){
				continue;
			}
			it=st.begin();
			if(qzh[*it]-qzh[i]==0&&jy[i]){
				st.clear();
				jans++;
			}
			//cout<<jans<<" "<<i<<endl;
		}
		cout<<m-jans<<endl;
	}
	return 0;
}
