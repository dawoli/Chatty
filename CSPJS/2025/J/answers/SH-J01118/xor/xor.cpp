#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=5e5+5;
int n,k,s[N],t[3*N];
int lcp,p[N],Hand[N];  //t[] Ͱ 
struct Pair{
	int l,r;
}cp[N]; 
int f[N],top[N],bst[3*N];
int query(int x){
	int ans=0;
	while(x){
		int u=(x&-x);
		ans=max(ans,bst[x]);
		x-=u; 
	}
	return ans;
}
int modify(int x,int d){
	while(x<=n+1){
		int u=(x&-x);
		bst[x]=max(d,bst[x]);
		x+=u; 
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		int a; cin>>a;
		s[i]=s[i-1]^a;
		top[i]=i;
	}
	memset(t,0xff,sizeof(t));
	memset(p,0xff,sizeof(p));
	for(int i=0;i<=n;i++){
		int u=t[s[i]];
		if(~u) {
			p[top[u]]=i;
			top[u]=i;
		}
		else t[s[i]]=i;	
	}
	for(int i=0;i<=n;i++) Hand[i]=t[s[i]];
	for(int i=0;i<=n;i++){
		int cpi=t[s[i]^k];
		if(cpi<0) continue;
		while(Hand[cpi]<=i&& ~Hand[cpi]) 
			Hand[cpi]=p[Hand[cpi]];
		if(~Hand[cpi]) {
			lcp++;
			cp[lcp].l=i;
			cp[lcp].r=Hand[cpi];
		}
	}
	for(int i=1;i<=lcp;i++){
		f[i]=query(cp[i].l+1)+1;
		modify(cp[i].r+1,f[i]);
	}
	int maxn=0;
	for(int i=1;i<=lcp;i++)
		maxn=max(maxn,f[i]);
	cout<<maxn;
	return 0;
} 
