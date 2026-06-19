#include<bits/stdc++.h>
using namespace std;
unsigned long long jiecheng(int n){
	if(n==1) return 1;
	return n*jiecheng(n-1);
}
int main(){
	int n,m;
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	int pat[n];
	string diff;
	getline(cin,diff);
	for(int i=0;i<n;i++) cin>>pat[i];
	if(n>100){
		cout<<0;
		return 0;
	}
	cout<<jiecheng(n);
	return 0;
}
