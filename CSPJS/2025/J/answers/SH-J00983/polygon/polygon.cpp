#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
const int mod=998244353;

int n,m;
int a[N],c[N];
int b[N];
int maxn;
ll ans;

int cal(int x,int y){
	if(y*2>x)return cal(x,x-y);
	int num=1;
	for(int i=x;i>=x-y+1;i--)num=num*i%mod;
	for(int i=1;i<=y;i++)num=num/i%mod;
	return num;
}

void show(int ss){
	if(ss==0)cout<<0;
	while(ss>0){
		cout<<ss%2;
		ss/=2;
	}
	cout<<" ";
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(c[a[i]]==0)b[++m]=a[i];
		c[a[i]]++;
		maxn=max(maxn,a[i]);
	}
//	for(int i=1;i<=maxn;i++){
//		if(c[i]==0)continue;
//		printf("c[%d]=%d\n",i,c[i]);
//	}
	if(maxn==1){
		ll sum=0;
		for(int i=3;i<=n;i++){
			int mul=1;
			mul=cal(n,i);
			sum+=mul;
			sum%=mod;
		}
		cout<<sum<<endl;
		return 0;
	}
	if(n<=20){
		for(int s=0;s<(1<<n);s++){
			int m=0,sum=0;
			maxn=0;
			for(int i=1;i<=n;i++){
				if((1&(s>>(i-1)))==1){
				
					m++;
					maxn=max(maxn,a[i]);
					sum+=a[i];
				}
			}
			//show(s);
			//printf("%d %d %d\n",m,maxn,sum);
			if(m<3)continue;
			if(sum>2*maxn)ans++;
			ans%=mod;
		}
		cout<<ans<<endl;
		return 0;
	}
//	for(int i=1;i<=maxn;i++){
//		if(c[i]==0)continue;
//		printf("c[%d]=%d\n",i,c[i]);
//		for(int i=1;i<=m;i++){
//			int num=b[i];
//			
//		}
//	}
	
	
	return 0;
}
