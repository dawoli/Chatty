#include<bits/stdc++.h>
using namespace std;
char a[1005];
int main(){
	freopen("bomb.in","r",stdin);
	freopen("bomb.out","w",stdout);
	long long int t,n,m,i,j,x;
	scanf("%lld",&t);
	while(t--){
		scanf("%lld%lld",&n,&m);
		scanf("%s",a+1);
		x=0;
		for(i=0; i<strlen(a+1); i++)
			if(a[i]=='$')
				x++;
		printf("%lld %lld\n",x,m-1);
	}
	return 0;
}
