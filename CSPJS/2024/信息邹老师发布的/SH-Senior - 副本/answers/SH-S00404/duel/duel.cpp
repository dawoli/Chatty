#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int const maxn=1e5+5;
inline void read(ll &x){
	int res=1,p=0;char c;c=getchar();
	while(c<'0'||c>'9'){if(c=='-')res=-1;c=getchar();}
	while(c>='0'&&c<='9'){p=(p<<3)+(p<<1)+(c-'0');c=getchar();}
	p*=res;
	x=p;
}
ll n,r[maxn],k[maxn],num[maxn],tot=0,ans,j,res;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	read(n);
	ans=n;
	for(int i=1;i<=n;i++){
		read(r[i]);num[r[i]]++;
	}
	sort(r+1,r+n+1);
	for(int i=1;i<=n;i++){
		if(r[i]!=r[i-1])k[++tot]=r[i];
	}
	for(int i=2;i<=tot;i++){
		res+=num[k[i-1]];
		if(num[k[i]]>=res){ans-=res;res=0;}
		else{res-=num[k[i]];ans-=num[k[i]];} 
	}
	cout<<ans;
}
