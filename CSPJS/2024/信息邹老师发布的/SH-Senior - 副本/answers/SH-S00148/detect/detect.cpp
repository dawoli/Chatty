#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxn 200010
#define fo(i,a,b) for(int i=(a);i<=(b);i++)
#define rep(i,a,b) for(int i=(a);i>=(b);i--)
ll n,m,l,V,t;
ll s[maxn],v[maxn],a[maxn],p[maxn];
vector<pair<ll,ll> >seg;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>t;
//	cout<<t<<endl;
	while(t--){
		seg.clear();
		cin>>n>>m>>l>>V;
		fo(i,1,n)cin>>s[i]>>v[i]>>a[i];
		fo(i,1,m)cin>>p[i];
		sort(p+1,p+m+1);
		fo(i,1,n){
			if(a[i]==0){
				if(v[i]<=V)continue;
				else{
					int x=lower_bound(p+1,p+m+1,s[i])-p;
					seg.push_back(make_pair(x,m));
				}
			}
			else if(a[i]>0){
				double St0=(2.0*a[i]*s[i]+V*V-v[i]*v[i])/(2.0*a[i]);
				ll St=ll(St0);
				int x=upper_bound(p+1,p+m+1,St)-p;
				if(x>m){
//					cout<<i<<endl;
					continue;
				}
				seg.push_back(make_pair(x,m));
			}
			else if(a[i]<0){
				if(v[i]<=V)continue;
				else{
					int l=lower_bound(p+1,p+m+1,s[i])-p;
					double St0=(2.0*a[i]*s[i]+V*V-v[i]*v[i])/(2.0*a[i]);
					ll St=ceil(St0);
					int r=lower_bound(p+1,p+m+1,St)-p;
//					cout<<"!"<<l<<' '<<r<<endl;
					r--;
					if(l>r)continue;
					seg.push_back(make_pair(l,r));
				}
			}
		}
		cout<<seg.size()<<' ';
		for(auto &x:seg){
			swap(x.first,x.second);
		}
		sort(seg.begin(),seg.end());
		for(auto &x:seg){
			swap(x.first,x.second);
//			cout<<x.first<<' '<<x.second<<endl;
		}
		int R=-1,ans=0;
		for(auto x:seg){
			int l=x.first,r=x.second;
			if(l<=R)continue;
			else R=r,ans++;
		}
		cout<<m-ans<<endl;
	}
	
	return 0;
}
