#include<bits/stdc++.h>
using namespace std;
int n;
int a[100005];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int ans=n,sum=0,num=0;
	for(int i = 1;i<=n;i++){
		if(a[i]!=a[i-1]){
			sum+=num;num=0;
		}
		num++;
		if(sum>0){
			ans--;sum--;
		}
	}
	printf("%d",ans); 
	return 0;
} 
/*
10
136 136 136 2417 136 136 2417 136 136 136
*/
