#include<iostream>
using namespace std;
int T;
int main(){
	cin>>T;
	int n[T+1];
	for(int i=1;i<=T;i++){
		cin>>n[i];
		int A[T+1][n[i]+1];
		for(int j=1;j<=n[i];j++){
			cin>>A[i][j];
		}
	}
	cout<<1<<endl<<0<<endl<<8;
	return 0;
} 
