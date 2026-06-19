#include<bits/stdc++.h>
using namespace std;
int a[15][15];
int score[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	int num=m*n;
	for(int i=1;i<=num;i++){
		scanf("%d",&score[i]);
	}
	int xm=1;
	for(int i=1;i<=num;i++){
		for(int j=1;j<=num-1;j++){
			if(score[j]<score[j+1]){
				swap(score[j],score[j+1]);
				if(xm==j){
					xm++;
				}
				else if(xm==j+1){
					xm--;
				}
			}
		}
	}
	int i=1,j=1,iz=1;
	for(int k=1;k<xm;k++){
		if(iz==0){
			j++;
			if(i==1){
				iz=1;
			}
			else{
				iz=-1;
			}
		}
		else if(iz==1){
			i+=1;
			if(i+1>n){
				iz=0;
			}
		}
		else if(iz==-1){
			i-=1;
			if(i-1==0){
				iz=0;
			}
		}
	}
	printf("%d %d",j,i);
}
