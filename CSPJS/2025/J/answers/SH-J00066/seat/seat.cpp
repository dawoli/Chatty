#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <algorithm>;
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,a[100000],b[100000],seat[101][101];
	int k=0,c=0;
	cin>>m>>n;
	for (int i=0;i<m*n;i++)
		cin>>a[i];
	c=a[0];
	sort(a,a+m*n);
	for (int i=0;i<m*n;i++)
		b[i]=a[m*n-i-1];
		
	for (int i=1;i<=m;i++){
		if(i%2){
			for (int j=1;j<=n;j++){
				seat[i][j]=b[k];
				k++;
			}
		}else{
			for (int j=n;j>=1;j--){
				seat[i][j]=b[k];
				k++;
			}	
		}
	}
	
	for (int j=1;j<=n;j++){
		for (int i=1;i<=m;i++)
			if(seat[i][j]==c)cout<<i<<' '<<j;
	}		
	return 0;
}
