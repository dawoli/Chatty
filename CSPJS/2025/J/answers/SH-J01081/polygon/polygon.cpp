#include<bits/stdc++.h>
using namespace std;
const int P=998244353;
int n,a[5001],ans=0,sum=0,maxn=0;
int main(){
	freopen("polygon.in","R",stdin);
	freopen("polygon.out","W",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
		maxn=max(a[i],maxn);
	}
	if(sum>(2*maxn)){
		printf("1");
	}
	else{
		printf("0");
	}
	return 0;
}
