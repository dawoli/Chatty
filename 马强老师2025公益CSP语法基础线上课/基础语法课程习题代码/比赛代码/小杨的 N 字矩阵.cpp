
#include<bits/stdc++.h>
using namespace std;
char a[50][50],k;
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			a[i][j]='-';
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			a[i][1]='+';
			a[i][n]='+';
			if(i==j){
				a[i][j]='+';
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<a[i][j];
		}
		cout<<endl;
	}
	return 0;  
}
