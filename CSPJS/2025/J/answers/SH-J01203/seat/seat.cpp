#include<bits/stdc++.h>
using namespace std;
int a[109];
int b[19][19];
bool cmp(int x,int y){
	if(x<y) return false;
	return true;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int t=n*m;
	for(int i=1;i<=t;i++){
		cin>>a[i];	
	}
	int r=a[1];
	sort(a+1,a+t+1,cmp);
	int i=1;
	for(int j=1;j<=n;j++){
		for(int k=1;k<=m;k++){
			b[j][k]=a[i];
			i++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==r){
				cout<<i<<" "<<j<<endl;
				break;
			}
		}
	}
	return 0;
} 
