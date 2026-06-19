#include<bits/stdc++.h>
using namespace std;
int num[100001]={};

int main(){
	freopen("duel4.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n,c;scanf("%d",&n);
	for(int i=1,j;i<=n;i++){scanf("%d",&j);num[j]++;}
	for(int i=1,k=1;i<=100000;i++){
		if(num[i]){c=num[k];num[k]=num[i];num[i]=c;k++;}
	}
	int i=1;int sum=0;
	while(num[i]){
		sum+=num[i];
		if(sum<=num[i+1]){
			sum=0;
		}
		else{sum-=num[i+1];}
		i++;
	}
	printf("%d",sum);
	return 0;
} 
