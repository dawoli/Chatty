#include<bits/stdc++.h>
using namespace std;
long long n,m,r,k=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1,j; i<=n*m; i++){
		cin>>j;
		if(i==1){
			r=j;
		}else if(j>r){
			k++;
		}
	}
	cout<<(k-1)/n+1<<' ';
	if(((k-1)/n+1)%2==0){
		cout<<n-(k-1)%n;
	}else{
		cout<<(k-1)%n+1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
