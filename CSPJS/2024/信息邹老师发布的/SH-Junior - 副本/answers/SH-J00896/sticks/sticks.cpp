#include<bits/stdc++.h>
using namespace std;
int T,n;
int a[9]; 
int b[100005],c[100005];
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	scanf("%d",&T);
	for(int i=1;i<=9;i++){
		a[i]=a[i-1]*10+1;
	}
	for(int i=1;i<=100000;i++){
		int num=i,sum=0;
		while(num){
			int x;
			if(num%10==0)x=6;
			if(num%10==1)x=2;
			if(num%10==2)x=5;
			if(num%10==3)x=5;
			if(num%10==4)x=4;
			if(num%10==5)x=5;
			if(num%10==6)x=6;
			if(num%10==7)x=3;
			if(num%10==8)x=7;
			if(num%10==9)x=6;
			num/=10;
			sum+=x;
		}
		b[i]=sum;
	}
	memset(c,0x3f,sizeof c);
	for(int i=1;i<=100000;i++){
		c[b[i]]=min(c[b[i]],i);
	}
	while(T--){
		scanf("%d",&n);
		if(n<=1) {
			puts("-1");
			continue; 
		}
		if(n%7==0){
			int c=n/7;
			printf("%d\n",8*a[c]);
		}else if(n%7==1){
			if(n==8) {
				printf("10\n");
				continue;
			}else{
				int c=n/7-1;
			int ans=a[c]*8+pow(10,c+1);
			printf("%d\n",ans);
			}
		}
		else{
			if(c[n]==0x3f3f3f3f)printf("-1\n");
			else printf("%d\n",c[n]);
		}
	}
	return 0;
}
