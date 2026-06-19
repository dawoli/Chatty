#include<bits/stdc++.h>
using namespace std;
int n,m,a1,ai,k,hang,lie;
int main(){
	freopen("seat.in","r",stdin);freopen("seat.out","w",stdout);
	cin>>n>>m>>a1;
	for(int i=2;i<=n*m;i++){
		cin>>ai;
		if(ai>a1)k++;
	}
	lie=k/n+1;
	if(lie%2==1){
		hang=k%n+1;
	}else{
		hang=n-k%n;
	}
	cout<<lie<<' '<<hang;
	return 0;
} 
