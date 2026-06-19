#include<bits/stdc++.h>
using namespace std;
int a[5005],bj[5005],n;
long long p(int a){
	long long k=1;
	while(a>50){
		a-=50;
		k*=65980984;
		k=k%998244353; 
	}
	k*=pow(2,a);
	k=k%998244353;
	return k; 
}
int cnt=0;
void dfs(int f){
	if(f==n){
		int m=-1,t=0,h=0;
		for(int i=0;i<n;i++){
			if(bj[i]==1){
				t+=a[i];
				if(a[i]>m) m=a[i];
				h++;
			}
		}
		if(t>2*m&&h>=3) cnt++;
		return;
	}
	bj[f]=1;
	dfs(f+1);
	bj[f]=0;
	dfs(f+1);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int m=-1;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(a[i]>m) m=a[i];
	}
	if(n==3){
		if((a[0]+a[1]+a[2])>2*m) printf("%d",1);
		else printf("%d",0);
		return 0;
	}
	if(m==1){
		long long r=998244353+p(n)-(n*(n-1))/2-n-1;
		r=r%998244353;
		printf("%d",r);
		return 0;
	}
	dfs(0);
	printf("%d",cnt);
	return 0;
} 
