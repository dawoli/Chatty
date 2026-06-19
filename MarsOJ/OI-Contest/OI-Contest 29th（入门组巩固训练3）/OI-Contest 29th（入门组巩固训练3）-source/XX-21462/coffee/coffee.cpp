#include<bits/stdc++.h>
using namespace std;
string a[6][9];
int b[6];
int main(){
	freopen("coffee.in","r",stdin);
	freopen("coffee.out","w",stdout);
	int t,n,m,bll=0;cin>>t;
	long long ans=0;
	while(t--){
		for(int i=1;i<=5;i++){
			for(int j=1;j<=8;j++){
				cin>>a[i][j];
				if(a[i][j]=="math")	b[i]++;
			}
			bll+=b[i];
		}
		scanf("%d %d",&n,&m);
		if(m!=1){
			for(int i=m;i<6;i++)
				ans+=b[i];
			n=n-8+m;
		}
		ans=ans+(long long)((n/7)*bll);
		n=n%7;
		for(int i=1;i<6&&i<=n;i++)
			ans+=b[i];
		printf("%lld\n",ans);
		ans=bll=0;memset(b,0,sizeof(b));
	}
	return 0;
}
