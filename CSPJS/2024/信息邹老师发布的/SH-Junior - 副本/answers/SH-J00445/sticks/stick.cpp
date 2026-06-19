#include<bits/stdc++.h>
using namespace std;
int t,n,ans;
int a[10]={6,2,5,5,4,5,6,4,7,6};
int main(){
	freopen("stick.in","r",stdin);
	freopen("stick.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		if(n==1) printf("-1");
		if(n-a[1]%a[0]==0){
			ans=2;
			n-=2;
			while(n!=0){
				ans*=10;
				n-=6;
			}
		}
		printf("%d",ans);
	}
	return 0;
}
