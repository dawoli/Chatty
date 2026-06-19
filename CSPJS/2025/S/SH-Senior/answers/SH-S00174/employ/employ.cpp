#include<bits/stdc++.h>
using namespace std;
int c[100010];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int x=s.length();
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n==m){
		for(int i=0;i<x;i++){
			if(s[i]==0){
				cout<<"0";
				return 0;
			}
		}
	}
	if(m==1){
		cout<<n;
		return 0;
	}
	int sum=n;
	for(int i=1;i<=m-1;i++){
		sum*=(n-i);
	}
	cout<<sum;
	return 0;
}
