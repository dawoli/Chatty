#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,M=1e6+5;
int T,n,tong[M]; 
struct node{
	int d,yanse;
}a[N];
int main(){
//	freopen("color.in","r",stdin);
//	freopen("color.out","w",stdout);
	cin>>T;
	while(T--){//Åä¶Ô 
		cin>>n;
		long long cnt=0,maxn=-1e9;
		for(int i=1;i<=1e6;i++) tong[i]=0;
//		for(int i=1;i<=n;i++) cin>>a[i].d;
		for(int i=1;i<=n;i++){
			long long t;
			cin>>t;
			tong[t]++;
			maxn=max(maxn,t);
		}
		for(int i=1;i<=maxn;i++){
			if(tong[i]>1) cnt+=(tong[i]-1);
		}
		cout<<cnt<<endl;
	}
	return 0;
}
/*
3
3
1 2 1
4
1 2 3 4
8
3 5 2 5 1 2 1 4
*/
