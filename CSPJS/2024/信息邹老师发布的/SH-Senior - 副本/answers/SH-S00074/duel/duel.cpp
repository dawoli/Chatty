#include<bits/stdc++.h>
using namespace std;
int num[100005],sun[100005];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n,a,sum=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a);
		num[a]++;
		sun[a]++;
	}
	for(int i=1;i<=100005;i++){
		if(num[i]==0){continue;}
		else{
			for(int j=i+1;j<=100005;j++){
				if(num[j]==0){continue;}
				else{
					while((num[i]>0)&&(sun[j]>0)){
						num[i]--;sun[j]--;
					}
				}
				if(num[i]==0){
					break;
				}
			}
		}
	}
	for(int i=1;i<=100005;i++){
		sum+=num[i];
	}
	printf("%d",sum);
	return 0;
}
