#include<iostream>
using namespace std;
int num=0;
void dfs(int n){
	num++;
	for(int i=1;i<=n/2;i++){
		dfs(i);
	}
}
int main(){
	int n;
	cin>>n;
	dfs(n);
	cout<<num;
}
