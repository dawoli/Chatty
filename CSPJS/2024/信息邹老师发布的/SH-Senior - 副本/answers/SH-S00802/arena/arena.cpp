#include<bits/stdc++.h>
using namespace std;
const int N=200009;
int n,m,a[N],A[N],c[N],k;
char R[20][N];
int t,x[4];
int check(int num){
	int B[N];
	for(int i=1;i<=num;i++) B[i]=A[i];
	for(int i=log2(num),d=1;i>=1;i--,d++){
		for(int j=1;j<=pow(2,log2(num)-i);j++)
			if(B[j*int(pow(2,d))]>=d) B[j*int(pow(2,d-1))+1]=B[j*int(pow(2,d))];
	}
	return B[1];
}
int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) cin>>c[i];
	if(n<2) k=2-n,n=2;
	else if(n<4) k=4-n,n=4;
	else if(n<8) k=8-n,n=8;
	int K=log2(n);
	for(int i=1;i<=K;i++)
		for(int j=1;j<=pow(2,K-i);j++)
			cin>>R[i][j];
	cin>>t;
	while(t--){
		for(int i=0;i<4;i++) cin>>x[i];
		for(int i=1;i<=n;i++){
			if(i<=n-k) A[i]=a[i]^x[i%4];
			else A[i]=-1;
		}
		int ans=0;
		for(int i=1;i<=m;i++) ans=ans^(i*check(c[i]));
	}
	return 0;
}
