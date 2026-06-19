#include<bits/stdc++.h>
using namespace std;
int a[1500];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,nm=0;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
		if(a[i]>a[0]) nm++;
	}
	cout<<nm/m+1<<" "<<(((nm/m+1)%2)?(nm%m+1):(n-nm%m));
	return 0;
} 
