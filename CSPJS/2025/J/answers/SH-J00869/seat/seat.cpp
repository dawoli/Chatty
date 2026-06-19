#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int a[1005];
int seat[15][15]; 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int node=0;
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++)cin>>a[i];
	int R=a[0];
	sort(a,a+n*m,cmp);
	int l=1,r=1;
	int nd=0;
	for(int i=0;i<n*m;i++){
		seat[l][r]=a[i];
		if(r==n&&l%2==1){
			node=1;
			l++;
		}
		else if(r==1&&l%2==0)
		{
			node=0;
			l++;
		}	
		else{
			if(node==0)r++;
			if(node==1)r--;
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
		{
			if(seat[i][j]==R){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
}
