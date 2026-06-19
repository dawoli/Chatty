#include<bits/stdc++.h>
#define ll long long
#define N 390039
#define INF 3939393939393939
using namespace std;
inline ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') x=x*10+(ch-'0'),ch=getchar();
	return x*f;
}
inline void write(ll x,bool mode){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10,0);
	putchar(x%10+'0');
	if(mode==true) putchar('\n');
}
ll n,r[N],cnt1,cnt2,maxx=-INF,cnt[N],maxxx=-INF;
bool vis[N];
ll p2(){
	for(ll i=1;i<=n;i++)
		if(r[i]==1) cnt1++;
		else cnt2++;
	return max(cnt1,cnt2);
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	n=read();
	for(ll i=1;i<=n;i++) r[i]=read(),maxx=max(maxx,r[i]);
	if(maxx==2){
		write(p2(),1);
		return 0;
	}
	for(ll i=1;i<=n;i++) cnt[r[i]]++;
	for(ll i=1;i<=maxx;i++) maxxx=max(maxxx,cnt[i]);
	write(maxxx,1);
	return 0;
}
//可能是对的，+升天+ 
