#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[1005],r,b[1005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i]; 
	}
	r=a[1];
	sort(a,a+n*m+1);
	int j=1;
	for(int i=n*m;i>0;i--){
		b[j]=a[i];
		j++;
	}
	int x,y;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[(i-1)*n+j]==r){
				cout<<i<<" ";
				if(i%2==0){
					cout<<n-j+1;
				}else{
					cout<<j;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
