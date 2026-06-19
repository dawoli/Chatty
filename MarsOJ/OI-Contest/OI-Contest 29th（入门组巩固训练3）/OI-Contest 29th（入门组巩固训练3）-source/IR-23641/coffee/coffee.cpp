#include<bits/stdc++.h>
#define int long long
using namespace std;
int t;
int day[10]={0};
int week;
int n,m;
signed main(){
	freopen("coffee.in","r",stdin);
	freopen("coffee.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		memset(day,0,sizeof(day));
		week=0;
		string s;
		for(int d=1;d<=5;d++){
			for(int j=1;j<=8;j++){
				cin>>s;
				if(s=="math")day[d]++,week++;
			}
		}
		scanf("%lld%lld",&n,&m);
		if(n%7==0){
			printf("%lld\n",n/7*week);
			continue;
		}
		int ans=0;
		ans+=n/7*week;
		if(m!=1){
			for(int i=m;i<=5;i++)ans+=day[i];
		}
		if(m!=1&&n-(7-m+1+n/7*7)!=0){
			for(int i=1;i<=min(n-(7-m+1+n/7*7),5LL);i++){
				ans+=day[i];
			}
		}
		else if(m==1&&n-(n/7*7)!=0){
			for(int i=1;i<=min(n-(n/7*7),5LL);i++){
				ans+=day[i];
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
