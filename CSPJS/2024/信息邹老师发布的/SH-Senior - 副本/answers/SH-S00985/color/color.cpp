#include<bits/stdc++.h>
const int N=200002;
int T,n,a[N];
int red,blue,ans,c;
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<n;i++)scanf("%d",a+i);
		if(n<=15){
			ans=0;
			for(int p=1;p<(1<<n);p++){
				red=0,blue=0,c=0;
				for(int i=0;i<n;i++)
					if(p&(1<<i))c+=(a[i]==red?red:0),red=a[i];
					else c+=(a[i]==blue?blue:0),blue=a[i];
				ans=std::max(ans,c);
			}
			printf("%d\n",ans);
		}else{
			printf("0\n");
		}
	}
	return 0;
}
