#include<iostream>
using namespace std;
int n,k,cnt;
void dfs(int sum,int i,int pre)
{
	if(i==k){
		if(sum==n){
			cnt++;
		}
		return;
	}
	for(int j=pre;j<=n;j++){
		if(j*(k-i)>n-sum){
			break;
		}
		dfs(sum+j,i+1,j);
	}
}
int main() {
	cin>>n>>k;
	dfs(0,0,1);
	cout<<cnt;
}
