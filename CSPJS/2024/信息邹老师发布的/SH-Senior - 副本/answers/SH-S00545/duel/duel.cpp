#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
int a[N];
bool b[N];
int main(){
	freeopen("duel.in","r",stdin);
	freeopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		int maxx=0,index=0;
		for(int j=1;j<=n;j++){
			if(a[i]>a[j]&&b[j]==0){
				if(a[j]>maxx){
					maxx=a[j];
					index=j;
				}
			}
		}
		if(maxx==0){
			continue;
		}else{
			b[index]=1;	
			cnt++;
		}
	}
	printf("%d\n",n-cnt);
	return 0;
}
