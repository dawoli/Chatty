#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=505;
const int mod=998244353;
int n,m,suma[N],sumb[N],tota[N],totb[N],awa[N];
struct node{
	int l,r,a,b,ans;
}f[N<<4][505];//匹配n个，方案数 

int ksm(int x,int y){
	if(y==1) return x;
	if(y==0) return 1;
	int mid=ksm(x,y/2);
//	cout<<x<<" "<<y<<" "<<mid<<endl;
	if(y%2==0) return (mid*mid)%mod;
	return (((mid*mid)%mod)*x)%mod;
}
int ch(int a,int b){
//	cout<<ksm(1,mod-2);
	int a1=awa[a],a2=ksm(awa[b],mod-2),a3=ksm(awa[a-b],mod-2);
//	cout<<a<<" "<<b<<" "<<a1<<" "<<a2<<" "<<a3<<" "<<(((a1*a2)%mod)*a3)%mod<<endl;
//	cout<<a1<<" "<<a3<<" "<<(a1*a3)%mod<<endl;
	return (((a1*a2)%mod)*a3)%mod;
}
void push_up(int pos){
	int lpos=pos*2,rpos=pos*2+1;
	for(int i=0;i<=f[lpos][0].a;i++){
		for(int j=0;j<=f[rpos][0].b;j++){
			for(int k=0;k<=min(f[lpos][i].a,f[rpos][j].b);k++){
				f[pos][i+j+k].a=f[lpos][i].a+f[rpos][j].a-k;
				f[pos][i+j+k].b=f[lpos][i].b+f[rpos][j].b-k;
				f[pos][i+j+k].l=f[lpos][i].l;
				f[pos][i+j+k].r=f[rpos][j].r;
				int qwq=((ch(f[lpos][i].a,k)*ch(f[rpos][j].b,k)%mod)*awa[k])%mod;
				f[pos][i+j+k].ans+=(((f[lpos][i].ans*f[rpos][j].ans)%mod)*qwq)%mod;
				f[pos][i+j+k].ans=(f[pos][i+j+k].ans+mod)%mod;
			}
		}
	}
}
void build(int l,int r,int pos){
//	cout<<l<<" "<<r<<endl;
	if(l==r){
		for(int i=0;i<=min(tota[l],totb[l]);i++){
			f[pos][i].l=f[pos][i].r=l;
			f[pos][i].a=tota[l]-i;
			f[pos][i].b=totb[l]-i;
			f[pos][i].ans=(ch(tota[l],i)*ch(totb[l],i)*awa[i])%mod;
		//	cout<<l<<" "<<r<<" "<<i<<" "<<f[pos][i].a<<" "<<f[pos][i].b<<" "<<f[pos][i].ans<<endl;
		}
		return;
	}
	int mid=(l+r)/2,lpos=pos*2,rpos=pos*2+1;
	build(l,mid,lpos);build(mid+1,r,rpos);
	push_up(pos);
	for(int i=0;f[pos][i].ans!=0;i++){
//	/cout<<l<<" "<<r<<" "<<i<<" "<<f[pos][i].a<<" "<<f[pos][i].b<<" "<<f[pos][i].ans<<endl;
	}
}

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	awa[0]=1;
	for(int i=1;i<=500;i++) awa[i]=(awa[i-1]*i)%mod;
	for(int i=1;i<=n;i++){
		char a;
		cin>>a;
		suma[i]=suma[i-1];
		if(a=='1') tota[suma[i]+1]++;
		if(a=='0') suma[i]=suma[i-1]+1;
	}
	for(int i=1;i<=n;i++){
		cin>>sumb[i];
		totb[sumb[i]]++;
	}
	build(0,n,1);
	int sum=0;
	for(int i=m;i<=n;i++){
		sum+=f[1][i].ans;
		sum%=mod;
	}
	cout<<sum;
	return 0;
}

