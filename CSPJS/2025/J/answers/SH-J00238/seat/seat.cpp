#include<bits/stdc++.h>
using namespace std;
int scor[110];
int seat[15][15];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>scor[i];
	}
	int r=scor[0],cnt=0;
	int k;
	bool f=true;
	sort(scor,scor+n*m,cmp);
	for(int i=0;i<m;i++){
		int j;
		if(f==true){
			k=1,j=0;
			f=false;
		}else{
			k=-1,j=n-1;
			f=true;
		}
		for(;j<n&&j>=0;j+=k){
			seat[j][i]=scor[cnt++];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(seat[i][j]==r){
				cout<<j+1<<" "<<i+1;
			}
		}
	}
	return 0;
} 
