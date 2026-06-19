#include <bits/stdc++.h>
using namespace std;

int a[109];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,t=0,ms;
	cin>>n>>m;
	int snake[m*2][2];
	for(int i=0;i<m;i++){
		snake[i][0]=1;
		snake[i][1]=i+1;
	}
	for(int i=m-1;i>=0;i--){
		snake[m+i][0]=2;
		snake[m-1+m-i][1]=i+1;
	}
	for(int i=0;i<n*m;i++){
		cin>>a[i];
		if(!i)
			ms=a[i];
	}
	sort(a,a+n*m);
	int g=0;
	for(int i=m*n-1;i>=0;i-=2*m){
		for(int j=i;j>i-2*m;j--){
			if(a[j]!=ms){
				g++;
				continue;
			}
			else{
				cout<<t*2+snake[g][0]<<" "<<snake[g][1];
				break;
			}
		}
		g=0;
		t++;	
	}
	return 0;
}
