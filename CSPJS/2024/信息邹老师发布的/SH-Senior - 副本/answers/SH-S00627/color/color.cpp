#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[200009],C,r = -1,b = -1;
void init(){
	C = 0;
	r = -1;
	b = -1;
}
void dfs(long long x,long long ans){
	if(x == n){
		C = max(C,ans);
		return;
	}
	int rr = 0,bb = 0,rrr = r;
	if(r != -1 and a[r] == a[x]){
		rr = a[x];
	}
	if(b != -1 and a[b] == a[x]){
		bb = a[x];
	}
	r = x;
	dfs(x + 1,ans + rr);
	r = rrr;
	b = x;
	dfs(x + 1,ans + bb);
	return;
}
void input(){
	cin>>n;
	for(long long i = 0;i < n;i++){
		cin>>a[i];
	}
	dfs(0,0);
	cout<<C<<endl;
	init();
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;
	cin>>T;
	for(int i = 0;i < T;i++){
		input();
	}
	return 0;
}
