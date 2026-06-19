#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int const maxn=1e3+5;
inline void read(ll &x){
	int res=1;char c;c=getchar();ll p=0;
	while(c<'0'||c>'9'){if(c=='-')res=-1;c=getchar();}
	while(c>='0'&&c<='9'){p=(p<<3)+(p<<1)+(c-'0');c=getchar();}
	p*=res;
	x=p;
}
struct robot{
	ll d,x,y;
};
ll n,m,num,k,T,ans;
char ch;
robot r;
ll a[maxn][maxn],flag[maxn][maxn];
bool check(robot rt){
	if(rt.x<1||rt.x>n||rt.y<1||rt.y>m)return true;
	if(a[rt.x][rt.y])return true;
	else return false;
}
void update(ll x,ll y){
	if(!flag[x][y])ans++;
	flag[x][y]++;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	scanf("%lld",&T);
	for(int sa=1;sa<=T;sa++){
		ans=0;
		memset(flag,0,sizeof(flag));
		memset(a,0,sizeof(a));
		//scanf("%lld%lld%lld%lld%lld%lld",&n,&m,&k,&r.x,&r.y,&r.d);
		read(n);read(m);read(k);read(r.x);read(r.y);read(r.d);
		update(r.x,r.y);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>ch;
				if(ch=='.')a[i][j]=0;
				else a[i][j]=1;
			}
		}
		for(int i=1;i<=k;i++){
			if(r.d==0){
				r.y++;
				if(check(r)){r.y--;r.d=(r.d+1)%4;}
				update(r.x,r.y);
			}else if(r.d==1){
				r.x++;
				if(check(r)){r.x--;r.d=(r.d+1)%4;}
				update(r.x,r.y);
			}else if(r.d==2){
				r.y--;
				if(check(r)){r.y++;r.d=(r.d+1)%4;}
				update(r.x,r.y);
			}else{
				r.x--;
				if(check(r)){r.x++;r.d=(r.d+1)%4;}
				update(r.x,r.y);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
