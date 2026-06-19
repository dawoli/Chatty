#include<bits/stdc++.h>
using namespace std;
int T, n, cnt=1, num=2;
int main(){
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	cin>>T;
	for(int i=0;i<T;i++){
		cin>>n;
		for(int j=0;j<n/7;j++){
			cnt*=10;
			cnt+=1;
		}
		for(int j=0;j<n/7;j++){
			num*=10;
			num+=2;
		}
		for(int j=0;j<n/7;j++){
			cnt*=10;
		}
		cout<<cnt+num;
	}
	return 0;
}
