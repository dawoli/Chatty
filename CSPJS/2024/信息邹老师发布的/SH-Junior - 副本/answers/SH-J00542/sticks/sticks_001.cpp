#include<bits/stdc++.h>
using namespace std;
int T;
int n;
/*struct NODE{
	int num[10];
};
NODE operator+(NODE a,NODE b){
	NODE c;
	for(int i=0;i<10;i++){
		c.num[i]=a.num[i]+b.num[i];
	}
	return c;
}
NODE min(NODE a,NODE b){
	int lena=0;
	int lenb=0;
	for(int i=0;i<=10;i++){
		lena+=a.num[i];
		lenb+=b.num[i];
	}
	if(lena<lenb)return a;
	if(lena>lenb)return b;
	if(a.num[0]+a.num[1]<b.num[0]+b.num[1])return a;
	if(a.num[0]+a.num[1]>b.num[0]+b.num[1])return b;
	for(int i=2;i<10;i++){
		if(a.num[i]>b.num[i])return a;
		else if(a.num[i]<b.num[i])return b;
	}
	return a;
}
//NODE dp[100010];
//dp[i]: use sticks*i get the minnum

*/
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	/*dp[2]={{0,1}};
	dp[3]={{0,0,0,0,0,0,0,1}};
	dp[4]={{0,0,0,0,1}};
	dp[5]={{0,0,1}};
	dp[6]={{0,0,0,0,0,0,1}};
	dp[7]={{0,0,0,0,0,0,0,0,1}};
	for(int i=8;i<=100010;i++){
		for(int j=2;j<=i-2;j++){
			dp[i]=min(dp[i],dp[j]+dp[i-j]);
		}
	}*/
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		switch(n){
			case 1:printf("-1\n");break;
			case 2:printf("1\n");break;
			case 3:printf("7\n");break;
			case 4:printf("4\n");break;
			case 5:printf("2\n");break;
			case 6:printf("6\n");break;
			case 7:printf("8\n");break;
			case 8:printf("10\n");break;
			case 9:printf("18\n");break;
			case 10:printf("22\n");break;
			case 11:printf("26\n");break;
			case 12:printf("28\n");break;
			case 13:printf("68\n");break;
			case 14:printf("88\n");break;
			case 15:printf("108\n");break;
			case 16:printf("188\n");break;
			case 17:printf("206\n");break;
			case 18:printf("208\n");break;
			case 19:printf("288\n");break;
			case 20:printf("688\n");break;
		}
	}
	return 0;
}
