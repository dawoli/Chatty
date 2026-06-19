#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5005]={},cnt=0,sum,maxn;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	if(n=3){
		sum = a[0] + a[1] + a[2];
		if(sum>max(a[0],max(a[1],a[2]))*2) cnt++;
	}
	cout << cnt;
	return 0;
} 
