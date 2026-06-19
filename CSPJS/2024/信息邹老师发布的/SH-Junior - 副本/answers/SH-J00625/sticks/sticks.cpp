#include<bits/stdc++.h>
using namespace std;
int mtr[10]={6,2,5,5,4,5,6,3,7,6};
const int maxn=7,minn=2;
int f1(int n,int i,int s){
	for(int j=0;j<10;j++){
		if(j==0&&i==1) continue;
		if(n-mtr[j]<=s*maxn&&n-mtr[j]!=1&&n-mtr[j]>-1) return j;
	}
}
int f(){
	int n;
	cin>>n;
	if(n==1) return -1;
	int b=n/maxn;
	if(n%maxn==0) b--;
	unsigned long long ans=0;
	for(int i=1;n>0;i++){
		int s=f1(n,i,b);
		ans=ans*10+s;
		n-=mtr[s];
		b--;
	}
	return ans;
}
signed main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cout<<f()<<endl;
	}
	return 0;
}
