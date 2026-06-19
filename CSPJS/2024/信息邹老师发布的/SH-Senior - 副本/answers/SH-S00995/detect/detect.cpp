#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+9,L=1e6+11,K=3e3+3;
struct Car{
	ll d,v,a;
	double x;
}c[N];
ll pos[N],cnt[L],s[L],a[N];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ll t;
	cin>>t;
	while(t--){
		memset(pos,0,sizeof(pos));
		memset(cnt,0,sizeof(cnt));
		memset(s,0,sizeof(s));
		memset(a,0,sizeof(a));
		ll n,m,l,v,ans1=0,flag1=0;
		cin>>n>>m>>l>>v;
		for(ll i = 1;i <= n;i++){
			cin>>c[i].d>>c[i].v>>c[i].a;
		}
		for(ll i = 1;i <= m;i++){
			cin>>pos[i];
			cnt[pos[i]]++;
		}
		for(ll i = 1;i <= l;i++){
			s[i]=s[i-1]+cnt[i];
		}
		for(ll i = 1;i <= n;i++){
			if(c[i].a!=0){
				c[i].x=double(v*v-c[i].v*c[i].v)/(2*c[i].a)+c[i].d;
			}
		}
		for(ll i = 1;i <= n;i++){
			if(c[i].a==0){
				if(c[i].v>v && s[l]-s[c[i].d-1] != 0){
					ans1++;
					if(pos[m]>=c[i].d && pos[m]<=l)a[i]=1;	
				}
			}
			else if(c[i].a<0){
				if(s[(ll)ceil(c[i].x)-1] - s[c[i].d-1] != 0){
					ans1++;
					if(pos[m]>=c[i].d && pos[m]<=(ll)ceil(c[i].x))a[i]=1;	
				}
			}
			else if(c[i].a>0){
				if(s[l] - s[(ll)(c[i].x)] != 0){
					ans1++; 
					if(pos[m]>=(ll)c[i].x+1 && pos[m]<=l)a[i]=1;	
				}
			}
		}
		cout<<ans1; 
		for(ll i = 1;i <= n;i++){
			flag1|=a[i];
		}
		if(flag1)cout<<" "<<m-1;
		else cout<<" "<<m;
		cout<<'\n';
	}
	return 0;
} 


