#include<bits/stdc++.h>
using namespace std;

//0124678
//6254637
int ta[15]={6,2,5,0,4,0,6,3,7,0}
int f(int n,int w){
	if(n==2){
		return 1;
	}
	if(n==3){
		return 7;
	}
	if(n==4){
		return 4;
	}
	if(n==5){
		return 2;
	}
	if(n==6&&w==1){
		return 6;
	}else if(n==6){
		return 0;
	}
	if(n==7){
		return 8;
	}
}
void f2(int n){
	long long ms=100000000000,s[int(n/7)+5][20]={0};
	for(int k=1;k<=n+7;k++){
		for(int i=1;i<=int(n/7)+1;i++){
			for(int j=2;j<=7;j++){
				for(int l=2;l<=7;l++){
					s[i][j]=s[i-1][l]+f(j,i);
					s[i][j+7]=s[i-1][l+7]
				}
					
			}
		}
		if(t==n)
		ms=min(ms,t)
	}
}
int main(){
	int n;
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T,n;
	cin>>T;
	for(int i=0;i<T;i++){
		cin>>n;
		if(n<=1){
			cout<<-1;
			continue;
		}
		if(n<=8){
			cout<<f(n,1);
			return 0;
		}
		else{
			f1(n)
		}
	}
	return 0;
}


