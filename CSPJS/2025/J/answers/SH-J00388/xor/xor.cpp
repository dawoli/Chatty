#include<bits/stdc++.h>
using namespace std;
int n,k,ans,a[500005];
bool f;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(k>1){
		printf("0");
		return 0;
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				f=0;
				ans++;
			}
			else{
				if(f){
					ans++;
					f=0;
				}
				else{
					f=1;
				}
			}
		}
	}
	else{
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				ans++;
			}
		}
	}
	printf("%d",ans);
	return 0;
}
