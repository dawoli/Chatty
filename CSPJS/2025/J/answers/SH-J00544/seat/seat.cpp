#include<bits/stdc++.h>
using namespace std;
const int N=109;
int a[N],b[19][19];
bool cmp(int x,int y){
	return x>y;
} 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int k=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int j=1;j<=m;j++){
		if(j%2==1)
			for(int i=1;i<=n;i++) b[i][j]=(j-1)*n+i;
		else
			for(int i=1;i<=n;i++) b[i][j]=(j-1)*n+n-i+1;
	}
	int rk=0;
	for(int i=1;i<=n*m;i++)
		if(a[i]==k) rk=i;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(b[i][j]==rk){
				cout<<j<<" "<<i<<endl;
				return 0;
			}
	return 0;
}
