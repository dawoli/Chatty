#include<bits/stdc++.h>
using namespace std;
int n,m,c,r,x=0,y=0;
int a[105];
int seat[105][105];

bool cmp(int s,int t){
	return s>t;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int seat[n+1][m+1];
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int t=a[0];
	sort(a,a+n*m,cmp);
	for(int b=0;b<105;b++){
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				seat[i][j]=a[b];
				cout<<seat[i][j];
			}
		}
	}
	
	for(int c=0;c<n+1;c++){
		for(int r=0;r<m+1;r++){
			if(seat[c][r]==t)cout<<c+1<<" "<<r+1;
		}
	}
	return 0;
}
