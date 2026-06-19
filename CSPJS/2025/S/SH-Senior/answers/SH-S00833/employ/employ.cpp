// 12 11 13
// 9.7
// 13.6 3.5 6.* 6.*
// 2^2*3^3*13441
// 2^3*3^2*11443
// wh?
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500+5;
const int Mod=998244353;
int n,m,c[N],can[N];
void solve1_2(){
	int p[15];
	for(int i=1;i<=n;i++) p[i]=i;
	// day i: person i
	int cnt=0;
	do {
		int L=0;
		for(int i=1;i<=n;i++){
			if(L>=c[p[i]]) L++;
			else if(can[i]==0) L++;
		}
		cnt+=(n-L>=m);
	} while(next_permutation(p+1,p+n+1));
	printf("%d\n",cnt%Mod);
}
bool A(){
	for(int i=1;i<=n;i++)
		if(can[i]==0) return false;
	return true;
}
void solve6_8_16_17(){ // all can
	int np=n;
	for(int i=1;i<=n;i++)
		if(c[i]==0) np--;
//printf("np = %lld\n",np);
	if(np<m){ printf("0\n"); return; }
	// ans = fact(n)
	ll res=1;
	for(int i=2;i<=n;i++){
		res=(res*i)%Mod;
//printf("%3d: %9lld\n",i,res);
	}
	printf("%lld\n",res);
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d %d",&n,&m);
	string s;
	cin>>s;
	for(int i=1;i<=n;i++) can[i]=(s[i-1]=='1');
//for(int i=1;i<=n;i++) printf("%c","NY"[can[i]]);printf("\n");
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	sort(c+1,c+n+1);
//for(int i=1;i<=n;i++)printf("%d%c",c[i],i<n?32:10);
	if(n<=10){ solve1_2(); return 0; }
	if(A()){ solve6_8_16_17(); return 0; }
	return 0;
}

