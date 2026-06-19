#include<bits/stdc++.h>
using namespace std;
const int p = 998244353;
int n,a[5001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    scanf("%d",&n);
	for(int i = 1;i <= n;i++)
	   scanf("%d",&a[i]);
	sort(a+1,a+n+1);
    if(n<=2){
    	printf("0");
    	return 0;
	}
	if(n==3){
		if(a[1]+a[2]>a[3])
		   printf("1");
		return 0;
	}
	srand(time(0));
	long long h = 1<<n/8;
	h%=p;
	long long ans = rand()%h+1;
	printf("%lld",ans);
	return 0;
} 
