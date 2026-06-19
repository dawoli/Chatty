#include<bits/stdc++.h>
using namespace std;
int n,k,ans=0;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0)ans++;
			else if(a[i]==1){
				if(a[i-1]!=2000000){
					a[i]=2000000;
				}
				else if(a[i-1]==2000000){
					ans++;
					a[i]=0;
				}
			}
		}
		printf("%d\n",ans);
		return 0;
	}
	else if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1)ans++;
		}
		printf("%d\n",ans);
		return 0;
	}
	return 0;
}
