#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n;
int a[5005];
bool allone(){
	bool f=1;
	for(int i=1;i<=n;i++)if(a[i]!=1)f=0;
	return f;
}
long long C(int x,int y){
	if(x==y || x==0)return 1;
	else return (C(x-1,y-1)+C(x,y-1))%mod;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(allone()){
		int count=0;
		for(int i=3;i<=n;i++){
			count+=C(i,n);
			count%=mod;
		}cout<<count;
	} 
	else if(n==3){
		if(a[1]+a[2]+a[3]>=2*max(a[1],max(a[2],a[3])))cout<<1;
		else cout<<0;
	}else if(n<=20){
		int count=0;
		for(long long i=0;i<(1<<n);i++){
			int cnt=0,maxx=-1,t=0;
			for(int j=0;j<n;j++){
				if((i>>j)&1){
					cnt+=a[j+1];
					maxx=max(maxx,a[j+1]);
					t++;
				}
			}if(t>=3)count+=(cnt>2*maxx);
		}cout<<count;
	}
} 
