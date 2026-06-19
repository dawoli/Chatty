#include<bits/stdc++.h>
using namespace std;
int N,M,suru[105];
int cmp(int a,int b){
	return a>b; 
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>N>>M;
	for(int i=1;i<=N*M;i++){
		cin>>suru[i];   
	}
	int sr=suru[1];
	sort(suru+1,suru+N*M+1,cmp);
	int Seat[15][15];
	int k=1;
	for(int i=1;i<=M;i++){
		if(i%2==1){
			for(int j=1;j<=N;j++){
				Seat[i][j]=suru[k];
				if(suru[k]==sr){
					cout<<i<<" "<<j;
					return 0;
				}
				k++;
			}
		}
		if(i%2==0){
			for(int j=N;j>=1;j--){
				Seat[i][j]=suru[k];
				if(suru[k]==sr){
					cout<<i<<" "<<j;
					return 0;
				}
				k++;
			}
		}
	}
	return 0;
} 
