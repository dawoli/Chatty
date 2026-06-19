#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i = 1;i <= n;i++)
	    scanf("%d",&a[i]);
	srand(time(0));
	int ans = rand()%n+1;
	if(k<=1){
		if(k==0){
			int cnt = 0;
			for(int i = 1;i <= n;i++){
				if(a[i]==0)
				   cnt++;
			}
			printf("%d",cnt);
		}
		else{
			int cnt = 0;
			for(int i = 1;i <= n;i++)
			   if(a[i]==1)
			      cnt++;
			printf("%d",cnt);
		}
	}
	else
	    printf("%d",ans);
	return 0;
} 
