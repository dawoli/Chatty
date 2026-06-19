#include <bits/stdc++.h>
using namespace std;
//单个数的权值为自身
//异或的逆运算为异或 

void debug(string a,int n,int end){
	cout<<a<<" "<<n;
	if(end) cout<<"\n";
	else cout<<"	";
}

const int MAXN=500005;
int n,k,a[MAXN],pre[MAXN],ans;

int bits_reverse(int x){
	int res;
	while(x){
		res=res<<1;
		res+=x%2;
		x=x>>1;
	}
	return res;
}

int my_xor(int x,int y){
	int res=0;
	if(x==0) return y;
	if(y==0) return x;
	while(x!=0||y!=0){
		int bx=x%2,by=y%2;
		if(bx!=by) res+=1;
		x=x>>1;
		y=y>>1;
		res=res<<1;
	}
	return bits_reverse(res);
}

int range_xor(int l,int r){  //[l,r]异或和 
	return my_xor(pre[r],pre[l-1]);
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre[i]=my_xor(pre[i-1],a[i]);
	}
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			if(k==range_xor(l,r)){
				ans++;
				l=r+1;
			}
		}
	}
	cout<<ans;
	return 0;
}
