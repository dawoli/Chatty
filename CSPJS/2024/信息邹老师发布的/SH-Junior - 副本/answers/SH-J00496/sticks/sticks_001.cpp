#include<bits/stdc++.h>
using namespace std;
int T,n;
long long mn=LONG_LONG_MAX;
int a[10]={6,2,5,5,4,5,6,3,7,6};
int ans[]={0,-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,200,208,288,688,888,1088,1888,2008,2088,2888,6888,8888,10888,18888,20088,20888,28888,68888,88888,-1,-1,200888,208888,288888,688888,888888,1088888,1888888,2008888,2088888,2888888,-1,-1,10888888,18888888,20088888,28888888,68888888};
long long f(long long x){
	long long ans=0;
	while(x!=0){
		ans+=a[x%10];
		x/=10;
	}
	return ans;
}
long long maxn(int n){
	long long ans=1;
	while(n>=0){
		n-=2,ans=ans*10+1;
	}
	return ans;
}
int scan(){
	int k=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-f;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		k=k*10+c-'0';
		c=getchar();
	}
	return k*f;
}
void print(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x<10){
		putchar(x+'0');
	}else{
		print(x/10);
		putchar(x%10+'0');
	}
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	T=scan();
	while(T--){
		mn=LONG_LONG_MAX;
		n=scan();
		printf("%d\n",ans[n]);
	}
	return 0;
}
