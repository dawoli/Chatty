#include<bits/stdc++.h>
using namespace std;
int num[20]={6,2,5,5,4,5,6,3,7,6};
int ans21[30]={-1,1,7,4,2,6,8,10,18,
22,20,28,68,88,108,188,200,208,288,688,888};
int ans7[10]={88,108,188,200,208,288,688};
int t,n,ans;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;ans=ans21[n-1];
		int dig=n/7-2;
		if(n>21) ans=ans7[n%7];
		printf("%d",ans);
		if(n>21){
			for(int i=0;i<dig/20;i++) printf("%s","88888888888888888888");
			for(int i=0;i<dig%20;i++) printf("%d",8);
		}
		printf("\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
