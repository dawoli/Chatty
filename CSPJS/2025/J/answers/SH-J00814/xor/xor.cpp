#include<bits/stdc++.h>
using namespace std;
int s[500005],a[500005],n,k;
int x(int a,int b){
	int m=0,k=1;
	while(a!=b){
		if((a%2)!=(b%2)){
			m+=k;
		}
		k*=2;
		a/=2;
		b/=2;
	}
	return m;
}
int r(int start){
	if(start==k) return start;
	int m=a[start];
	for(int i=start+1;i<n;i++){
		int m=x(m,a[i]);
		if(m==a[i]){
			return -1;
		}
		if(m==k){
			return i;
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int cnt=0,lastend=-1;
	scanf("%d %d",&n,&k);
	if(k==0){
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			if(a[i]==0||(a[i]==a[i-1]&&i>0)){
				cnt++;
			}
		}
		printf("%d",cnt);
		return 0;
	}
	if(k==1){
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			if(a[i]==1){
				cnt++; 
			}
		}
		printf("%d",cnt);
		return 0;
	}
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++){
		int t=r(i);
		if(t!=-1){
			s[t]=i;
		}
	}
	for(int i=0;i<n;i++){
		if(s[i]>lastend){
			lastend=i;
			cnt++;
		}
	}
	printf("%d",cnt);
	return 0;
} 
