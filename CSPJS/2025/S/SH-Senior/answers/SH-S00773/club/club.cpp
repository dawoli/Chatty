#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100009;
inline int read(){
	register int x(0),f(1);
	register char c(getchar());
	while(c<'9'||c>'9'){if(c=='-'){f=-1,c=getchar();}}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^'0'); c=getchar();}
	return x*f;
}
int T,n,ans;
struct Node{
	ll a,b,c,mx[4];
	ll ch;
}x[N];
bool cmp(const Node&g,const Node&h){
	return (g.mx[1]-g.mx[2])>(h.mx[1]-h.mx[2])
	||((g.mx[1]-g.mx[2])==(h.mx[1]-h.mx[2]))&&(g.mx[1]-g.mx[2])>(h.mx[1]-h.mx[2])
	||(g.mx[1]-g.mx[2])==(h.mx[1]-h.mx[2])&&(g.mx[2]-g.mx[3])==(h.mx[2]-h.mx[3])&&(g.mx[1]>h.mx[1])
	||(g.mx[1]-g.mx[2])==(h.mx[1]-h.mx[2])&&(g.mx[2]-g.mx[3])==(h.mx[2]-h.mx[3])&&(g.mx[1]==h.mx[1])&&(g.mx[2]>h.mx[2])
	||(g.mx[1]-g.mx[2])==(h.mx[1]-h.mx[2])&&(g.mx[2]-g.mx[3])==(h.mx[2]-h.mx[3])&&(g.mx[1]==h.mx[1])&&(g.mx[3]>h.mx[3]);
}
ll cnt[4];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		cin>>n;
		ll cnta=0,cntb=0,cntc=0;
		for(ll i=1;i<=n;i++){
			scanf("%lld",&x[i].a);
			scanf("%lld",&x[i].b);
			scanf("%lld",&x[i].c);
			ll a1=x[i].a,b1=x[i].b,c1=x[i].c;
			if(a1<b1) swap(a1,b1);
			if(a1<c1) swap(a1,c1);
			if(b1<c1) swap(b1,c1);
			x[i].mx[1]=a1,x[i].mx[2]=b1,x[i].mx[3]=c1;
		}
		sort(x+1,x+1+n,cmp);
		ll ans1=0;
		for(ll i=1;i<=n;i++){
			if(x[i].mx[1]==x[i].a){
				if(cnta==n/2){
					if(x[i].mx[2]==x[i].b){
						if(cntb==n/2){
							ans1+=x[i].mx[3];
							cntc++;
						}
						else{
							cntb++;
							ans1+=x[i].mx[2];
						}
					}
					else{
						if(cntc==n/2){
							cntb++,ans1+=x[i].mx[3];
						}
						else{
							cntc++;
							ans1+=x[i].mx[2];
						}
					}
				}
				else{
					cnta++;
					ans1+=x[i].mx[1];
				}
			}
			else if(x[i].mx[1]==x[i].b){
				if(cntb==n/2){
					if(x[i].mx[2]==x[i].a){
						if(cnta==n/2){
							cntc++,ans1+=x[i].mx[3];
						}
						else{
							cnta++;
							ans1+=x[i].mx[2];
						}
					}
					else{
						if(cntc==n/2){
							cnta++,ans1+=x[i].mx[3];
						}
						else{
							cntc++;
							ans1+=x[i].mx[2];
						}
					}
				}
				else{
					cntb++,ans1+=x[i].mx[1];
				}
			}
			else if(x[i].mx[1]==x[i].c){
				if(cntc==n/2){
					if(x[i].mx[2]==x[i].b){
						if(cntb==n/2) ans1+=x[i].mx[3],cnta++;
						else ans1+=x[i].mx[2],cntb++;
					}
					else{
						if(cnta==n/2) ans1+=x[i].mx[3],cntb++;
						else cnta++,ans1+=x[i].mx[2];
					}
				}
				else{
					cntc++,ans1+=x[i].mx[1];
				}
			}
		}
		cout<<ans1<<endl;
	}
			
	return 0;
}
