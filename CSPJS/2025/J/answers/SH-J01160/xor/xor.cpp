#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[500010]; 
int forr(int x,int y){
	return (x|y)-(x&y);
}
int f[500010];
bool fn[500010];
int find(int c,int p,int cnt){
	if(p>n) return cnt;
	if(fn[p]) return f[p];
	int maxn=0;
	if(forr(a[p],c)==k){
		maxn=max(maxn,find(0,p+1,cnt+1));
	}
	maxn=max(maxn,find(forr(a[p],c),p+1,cnt));
	fn[p]=true;
	f[p]=maxn;
	return maxn; 
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	cout<<find(0,1,0)<<endl;
	return 0;
} 
