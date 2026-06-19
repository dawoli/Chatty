#include<bits/stdc++.h>
using namespace std;
int a,b,c;
const long long M=998244353;
int l[10009];
int n;
bool flag=1;
long long t(int k){
	long long ans=1;
	for(int i=2;i<=k;i++)
	ans=(ans*i)%M;
	return ans;
}
long long ca(int x,int y){
	long long p=t(x);
	long long q=t(y)*t(x-y)%M;
	while(p%q!=0)
	p+=M;
	return p/q;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	long long cnt=0;
	if(n==3){
		cin>>a>>b>>c;
		if(a+b+c>2*max(c,max(a,b)))
		cout<<1;
		else
		cout<<0;
		return 0;
	}
	else{
		for(int i=1;i<=n;i++){
			cin>>l[i];
			if(l[i]!=1)
			flag=0;
		}
		if(flag){
			for(int i=3;i<=n;i++)
			cnt+=ca(n,i);
		}
	}
	cnt%=M;
	cout<<cnt;
	return 0;
}
