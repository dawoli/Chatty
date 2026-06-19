#include<bits/stdc++.h>
#define N 100009
using namespace std;
typedef long long ll;
inline ll read(){
	char c=getchar();ll x=0,f=1;
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	return x*f;
}
ll n,cnt[N],x,res;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) cnt[read()]++;
	for(int i=1;i<N;i++){
		if(cnt[i]>x) res+=x,x=cnt[i];
		else res+=cnt[i];
	}
	printf("%lld\n",n-res);
	return 0;
}
//Yu-Gi-Oh

