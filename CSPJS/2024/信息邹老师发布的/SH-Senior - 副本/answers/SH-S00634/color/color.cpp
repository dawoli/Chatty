#include<bits/stdc++.h>
using namespace std;
#define rp(i) for(cl[i]=0;cl[i]<=1;cl[i]++)
int t,n,a[20];
int cl[20];
int check(){
		int lll=0;
	for(int i=1;i<=n;i++){
		if(i==1)continue;
	
		for(int j=1;j<=i;j++){
			if(a[i]==a[j]&&cl[i]==cl[j])lll+=a[i];
		}
	}return lll;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		int ans=0;
		switch(n){
			case 1:
				
				break;
			case 2:
				rp(1)rp(2)ans=max(ans,check());
				break;
			case 3:
				rp(1)rp(2)rp(3)ans=max(ans,check());
				break;
			case 4:
				rp(1)rp(2)rp(3)rp(4)ans=max(ans,check());
				break;
			case 5:
				rp(1)rp(2)rp(3)rp(4)rp(5)ans=max(ans,check());
				break;
			case 6:
				break;
			case 7:
				break;
			case 8:
				break;
			case 9:
				break;
			case 10:
				break;
			case 11:
				break;
			case 12:
				break;
			case 13:
				break;
			case 14:
				break;
			case 15:
				break;
		}
	}
	return 0;
}
