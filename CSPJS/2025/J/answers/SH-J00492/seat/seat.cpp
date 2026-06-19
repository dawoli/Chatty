#include<bits/stdc++.h>
using namespace std;
bool ms(int a,int b){
	return(a>b);
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int x,y,m,n,ys[1000],hs[1000];
	cin>>n>>m;
	for(int i=0;i<(n*m);i++){
		cin>>ys[i];
		hs[i]=ys[i];
	}
	sort(hs,hs+(n*m),ms);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(hs[i*n+j]==ys[0]){
				if(i%2){
					cout<<i+1<<" "<<n-j;
				}
				else{
				cout<<i+1<<" "<<j+1;
				}
				return 0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

