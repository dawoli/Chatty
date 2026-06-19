#include<bits/stdc++.h>
using namespace std;
int shu[100000];
int main(){
	freopen("road.cpp","r",stdin);
	freopen("road.cpp","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i = 0;i<n;i++){
		int a;
		cin>>a;
		shu[i] = a;
	}
	cout<<n+m+k;
}
