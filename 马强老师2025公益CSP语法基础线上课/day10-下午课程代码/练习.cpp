#include <bits/stdc++.h>
using namespace std;
int n,cnt=0;
int main(){
	cin>>n;
	int a[1005]={};
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(a[j]>a[j+1]){
				swap(a[j],a[j+1]);
				cnt++;
			}
		}
	}cout<<cnt;
	return 0;
}
/*
4
4 3 2 1
*/
