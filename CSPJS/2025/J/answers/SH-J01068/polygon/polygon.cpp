#include<bits/stdc++.h>
#define mod 988244353
using namespace std;
int n,a[5008];
int d,c,b,cn[28],op,maxop,maxa;
long long cnt,add;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(a[i]>maxa) maxa=a[i];
	}
	if(n<=20){
		for(int i=1;i<(1<<n);i++){
			c=i,b=(1<<(n-1)),d=n-1;
			while(c!=0){
				if(c-b>=0) c-=b,cn[d]=1;
				b/=2,d--;
			}
			for(int j=0;j<n;j++){
				if(cn[j]){
					op+=a[j];
					if(maxop<a[j]) maxop=a[j];
				}
			}
			if(op>maxop*2) cnt++;
			maxop=op=0;
			for(int i=0;i<n;i++) cn[i]=0;
		}
	}
	else if(maxa==1){
		cnt=1,add=3;
		for(int i=4;i<=n;i++){
			cnt=cnt*2+add;
			add+=i-1;
			cnt%=mod;
			add%=mod;
		}
	}
	printf("%d",cnt);
	return 0;
}
