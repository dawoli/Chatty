/*
  一重循环，枚举算法
 */
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,flag=0;
	cin>>n;
	for(int i=1;i<=n;i++)
		if(i*i*i==n){
			flag=1;
			break;
		}
	if(flag==1) cout<<"Yes";
	else cout<<"No";
	return 0;
}
