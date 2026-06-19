#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a,o,num=1;
	cin>>n>>m>>a;
	for(int i=0;i<n*m-1;i++){
		cin>>o;
		if(o>a) num++;
	}
	cout<<(num-1)/n+1<<' ';
	if((num-1)/n%2==0){
		cout<<(num-1)%n+1;
	} else {
		cout<<n-(num-1)%n;
	}
	return 0;
}
