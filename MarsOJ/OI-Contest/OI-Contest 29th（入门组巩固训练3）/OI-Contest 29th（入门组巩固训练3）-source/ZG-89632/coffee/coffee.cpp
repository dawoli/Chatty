#include <bits/stdc++.h>
using namespace std;
int T,a[11];
int main(){
	freopen("coffee.in","r",stdin);
	freopen("coffee.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		memset(a,0,sizeof(a));
		char s[100];int day,week,sum=0;
		for(int i=1;i<=5;i++){
			for(int j=1;j<=8;j++){
				scanf("%s",s);
				if(s[0]=='m')a[i]++,sum++;
			}
			a[i]=a[i-1]+a[i];
		}
		scanf("%d%d",&day,&week);
		a[6]=a[7]=a[5];
		long long ret=0;
		if(week<=5)ret+=a[5]-a[week-1];
		day-=7-week+1;
		ret+=1LL*day/7*sum;
		if(day%7!=0)ret+=a[day%7];
		printf("%lld\n",ret);
	}	
	return 0;
}
