#include<bits/stdc++.h>
using namespace std;
long long n;
long long m;
int sti[20]={6,2,5,5,4,5,6,3,7,6,0};
long long now=0;
long long maxx=0x7f7f7f7f;
void dgg(long long a){
	if(a==0){
		maxx=min(maxx,now);
		return ;
	}
	else if(a<2){
		return ;
	}
	for(int i=0;i<=9;++i){
		now=now*10+i;
		dgg(a-sti[i]);
		now/=10;
	}
	
	return ;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	scanf("%d",&n);
	while(n--){
		now=0;
		maxx=0x7f7f7f7f;
		scanf("%d",&m);
		if(m<2){
			printf("-1\n");
			continue;
		}if(m==2){
			printf("1\n");continue;
		}if(m==3){
			printf("7\n");continue;
		}if(m==4){
			printf("4\n");continue;
		}if(m==5){
			printf("2\n");continue;
		}if(m==6){
			printf("6\n");continue;
		}
		for(int ci=1;ci<=9;++ci){
			now=ci;
			dgg(m-sti[ci]);
		}
		
		printf("%d\n",maxx);
	}
	return 0;
}

