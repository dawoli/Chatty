#include<bits/stdc++.h>
using namespace std;
int _xor[500008],cnt,maxa;
bool used[500008];
int n,a[500008],k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]>maxa) maxa=a[i];
	}
	if(maxa<=1){
		if(k==0) for(int i=1;i<=n;i++){
			if(a[i]==0) cnt++;
			if(a[i]==1&&a[i-1]==1&&used[i-1]==0) used[i-1]=used[i]=1,cnt++;
		}
		if(k==1) for(int i=1;i<=n;i++) if(a[i]==1) cnt++;
	}
	printf("%d",cnt);
	return 0;
}
