#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,m,num[17],ans,pos,sum;
string s[17][17];
signed main(){
	freopen("coffee.in","r",stdin);
	freopen("coffee.out","w",stdout);
	cin>>t;
	while(t--){
		memset(num,0,sizeof(num));
		ans=sum=0;
		for(int i=1;i<=5;i++){
			for(int j=1;j<=8;j++){
				cin>>s[i][j];
				if(s[i][j][0]=='m')num[i]++; 
			}
			sum+=num[i];
		} 
		scanf("%lld%lld",&n,&m);
		ans+=(n/7)*sum;
		pos=m;
		for(int i=1;i<=n%7;i++){
			ans+=num[pos];
			pos=(pos==7?1:pos+1);
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
