#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m,num=1;
	cin>>n>>m;
	int a[m*n];
	cin>>a[1];
	for(int i=2;i<=m*n;i++){
	cin>>a[i];
		if(a[i]>a[1])
		num+=1;
	}
	int column,row;
	if(num%n==0){
	column=num/n;
	row=n;
	}
	if(num%n!=0){
	column=num/n+1;
	row=num%n;
	}
	if(column%2==1){
		cout<<column<<" "<<row;
	}
	if(column%2==0){
		cout<<column<<" "<<n+1-row;
	}
	return 0;
}
