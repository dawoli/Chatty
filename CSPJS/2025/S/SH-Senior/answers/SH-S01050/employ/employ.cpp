#include<bits/stdc++.h>
using namespace std;
const int N = 1e9;
int a;
int shu[N];
int main(){
	freopen("employ.cpp","r",stdin);
	freopen("enploy.cpp","w",stdout);
	int n,m;
	cin>>n>>m;
	int b;
	cin>>b;
	int count = n+m+b;
	for(int i = 0;i<n;i++){
		cin>>a;
		shu[i] = a;
		count+=a;
	}
	cout<<count%998244353;
}
