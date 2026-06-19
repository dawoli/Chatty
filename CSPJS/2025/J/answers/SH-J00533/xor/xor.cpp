#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
long long a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	if(n==1)
	if(n==2){
		int cnt=0;
		if(a[1]==k)
			cnt++;
		if(a[2]==k)
			cnt++;
		if((a[1]^a[2])==k)
			cnt++;
		cout<<cnt;
		return 0;
	}
} 
