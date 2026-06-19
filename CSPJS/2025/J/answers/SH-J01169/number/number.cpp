#include<bits/stdc++.h>
using namespace std;
int sz[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long a;
	scanf("%lld",&a);
	while(a!=0){
		long long b=a%10;
		sz[b]++;
		a/=10;
	}
	if(a<10){
		cout<<a;
		return 0;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=sz[i];j++){
			printf("%d",i);
		}
	}
	
	
	
	return 0;
} 
