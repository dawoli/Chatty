#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	int n,m,a0,t,cnt=0,k1,k2;
	scanf("%d %d",&n,&m);
	scanf("%d",&a0);
	for(int i=1;i<n*m;i++){
		scanf("%d",&t);
		if(t>a0) cnt++;
	}
	k1=(cnt/n)+1;
	if(k1%2==0){
		k2=n-(cnt%n);
	}else{
		k2=(cnt%n)+1;
	}
	printf("%d %d",k1,k2);
	return 0;
} 
