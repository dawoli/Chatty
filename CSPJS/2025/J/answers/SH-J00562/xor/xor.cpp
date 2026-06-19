#include<bits/stdc++.h>
using namespace std;
int a[500005],n,k,cnt;
bool b[500005];
int calc(int l,int r){
	int res=0;
	for(int i=l;i<=r;i++){
		if(b[i]==1) return -1;
		res^=a[i];
	}
	return res;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			if(calc(l,r)==k){
				for(int t=l;t<=r;t++) b[t]=1;
				cnt++;
			}
		}
	}
	printf("%d",cnt);
	return 0;
}
