#include<bits/stdc++.h>
using namespace std;
int t;
int n;
struct problem{
	int num;
	int color;
}a[1000000];
int ans[12]={0};
int transform(int x, int m){
	int a[22]={0};
	int u=0;
	int f=0;
	int v;
	int k=x;
	while(k!=0){
		u++;
		k/=2;
	}
	while(x!=0){
		v=x%2;
		x/=2;
		a[u-f]=v;
		f++;
	}
	return a[m];
}
int main(){
	freopen("color.in","r",stdin);
	freoepn("color.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[i].num;
		}
		for(int j=0;j<=pow(2,n);j++){
			for(int k=1;k<=n;k++){
				a[k].color=transform(j,k);
				int key=0;
				for(int z=n;z>=1;z--){
					for(int u=z;u>=1;u--){
						if(a[u].color==a[z].color){
							if(a[u].num==a[z].num){
								key+=a[u].num;
							}
							else{
								break;
							}
						}
					}
				}
				ans[i]=max(ans[i],key);
				key=0;
			}
		}
}
for(int i=1;i<=t;i++){
	cout<<ans[i]<<endl;
}
		return 0;
	}
