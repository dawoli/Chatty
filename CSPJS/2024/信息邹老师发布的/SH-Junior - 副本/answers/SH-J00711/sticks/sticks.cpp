#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

void k8(int k){
	for(int i=1;i<=k;i++)putchar('8');
}

int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	
	int T;scanf("%d",&T);
	while(T--){
		int n;scanf("%d",&n);
		if(n<7){
			if(n==1)puts("-1");
			if(n==2)puts("1");
			if(n==3)puts("7");
			if(n==4)puts("4");
			if(n==5)puts("2");
			if(n==6)puts("6");
			continue;
		}
		int d=n%7,k=n/7;
		if(d==0)k8(k);
		if(d==1)printf("10"),k8(k-1);
		if(d==2)printf("1"),k8(k);
		if(d==3)printf("22"),k8(k-1);
		if(d==4)printf("20"),k8(k-1);
		if(d==5)printf("2"),k8(k);
		if(d==6)printf("6"),k8(k);
		printf("\n");
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
