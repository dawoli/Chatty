#include <bits/stdc++.h>
using namespace std;
int n,m;
string s;
int c[600];
int val[600<<2],lazy[600<<2];
void pushup(int rt){
	val[rt]=val[rt*2]+val[rt*2+1];
	lazy[rt]=lazy[rt*2]+lazy[rt*2+1];
}
void build(int rt,int l,int r,int l1,int r1){
	int mid=(l+r)/2;
	val[rt]=c[rt]*s[rt];
	build(rt*2,l,mid,l1,r1);
	build(rt*2+1,mid+1,r,l1,r1);
}
void update(int rt,int pos,int dis,int l,int r){
	val[pos&-pos]+=dis*c[pos];
	lazy[pos]=lazy[rt*2+1+pos];
	pushup(rt);
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++) cin<<c[i];
	build(1,1,n,1,n);
	return 0;
}
