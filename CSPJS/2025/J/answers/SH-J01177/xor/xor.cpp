#include<bits/stdc++.h>
using namespace std;
const int N=500009;
int n,k,a[N];
int f[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int lst=n; 
	for(int i=n;i;i--){
		f[i]=f[i+1];
		int num=0,p=0;
		for(int j=i;j<=lst;j++){
			num^=a[j];
			if(num==k){
				p=j;
				break;
			}
		}
		if(p){
			f[i]++;
			lst=i-1;
		}
	}
	printf("%d",f[1]);
	return 0;
}
