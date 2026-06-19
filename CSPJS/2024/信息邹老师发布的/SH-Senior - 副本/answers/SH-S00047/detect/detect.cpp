#include<bits/stdc++.h>
#define int long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,r,l) for(int i=(r);i>=(l);i--)
#define repn(i,n) for(int i=0;i<(n);i++)
using namespace std;
const int N=1e5+10;

int get_gcd(int x,int y){
	if(x==0||y==0) return x+y;
	return get_gcd(y,x%y);
}

int read(){
	int x=0; bool f=false; char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=true; ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0'; ch=getchar();}
	return f?-x:x;
}

int n,m,L,V,d[N],v[N],a[N],p[N];
int tot;
struct node{
	int l,r;
}s[N];
void add(int l,int r){
//	printf("add [%lld %lld]\n",l,r);
	r=min(r, L);
	if(l<=r) s[++tot]={l,r};
}

bool use[N];
int res1, res2;

// > V
void solve(){
	rep(i,1,n){
		if(v[i]>V){
			if(a[i]>=0){
				add(d[i], L);
			}
			else{
				int lhs=V*V - v[i]*v[i], rhs=2*a[i];
				if(lhs%rhs==0) add(d[i], d[i] + lhs/rhs-1);
				else add(d[i], d[i] + lhs/rhs);
			}
		}
		else{
			if(a[i]<=0) continue;
			else{
				int lhs=V*V - v[i]*v[i], rhs=2*a[i]; // 在 (lhs/rhs, +inf) 超速 
				add(d[i] + lhs/rhs + 1, L);
			}
		}
	}
	
	sort(s+1,s+tot+1,[](node lhs,node rhs){
		return lhs.r < rhs.r;
	});
	
//	rep(i,1,tot){
//		printf("[%lld, %lld]\n",s[i].l,s[i].r);
//	}
	
	int it=0; p[0]=-1; // 上一个使用在 p[it] 的 
	rep(i,1,tot){
//		printf("i %lld\n",i);
		if(use[it] && s[i].l<=p[it] && p[it]<=s[i].r){ // 可以成功覆盖
			res1++;
			if(!use[it]) use[it]=true;
			continue;
		}
		while(it+1<=m && p[it+1]<=s[i].r) it++;
		if(s[i].l<=p[it] && p[it]<=s[i].r){ // 可以成功覆盖，需要额外多花费 p[it] 
//			printf("  it = %lld, ++ ++\n",it);
			res1++;
			if(!use[it]) use[it]=true;
		}
//		else{
//			printf("  it = %lld, cant\n",it);
//		}
	}
	
	res2=m;
	rep(i,1,m) if(use[i]) res2--;
	
	cout<<res1<<' '<<res2<<endl;
}

signed main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int T=read();
	while(T--){
		n=read(); m=read(); L=read(); V=read(); 
		rep(i,1,n){
			d[i]=read(); v[i]=read(); a[i]=read();
		}
		rep(i,1,m){
			p[i]=read();
		}
		
		solve();
		
		rep(i,1,m) use[i]=false;
		res1=res2=tot=0;
	}

	return 0;
}

