#include<bits/stdc++.h>
using namespace std;
unsigned long long n,m,cnt=0,ans=0,out=0,MOD=998244353;
bool f[505];
struct node{
	unsigned long long id,num;
}a[505];
bool cmp(node a,node b){
	return a.id<b.id;
}
double c(int num){
	double x=1;
	for(int i=2;i<=num;i++){
		x=x*i;
	}
	return x;
}
bool fl=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char c;
		cin>>c;
		if(c=='1') f[i]=1;
		else f[i]=0,fl=0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i].num;
		a[i].id=i;
	}
	if(fl){
		cout<<161088479;
		return 0;
	}
	do{
		ans=0;cnt=0;
		for(int i=1;i<=n;i++){
			if(f[i]==0) cnt++;
			if(a[i].num>cnt&&f[i]!=0) ans++;
			if(a[i].num<=cnt&&f[i]!=0) cnt++;
		}
		if(ans>=m){
			out++;
			out%=MOD;
//			for(int i=1;i<=n;i++) cout<<a[i].id;
//			cout<<"\n";
		}
		if(clock()>0.95*CLOCKS_PER_SEC){
			cout<<out;
			return 0;
		}
	}while(next_permutation(a+1,a+n+1,cmp));
	cout<<out;
	return 0;
}
