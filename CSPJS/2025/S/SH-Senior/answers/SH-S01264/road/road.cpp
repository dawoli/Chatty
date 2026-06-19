#include <bits/stdc++.h>
using namespace std;


int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int fw;
	for(int i=0;i<m;i++){
		cin>>fw;
	}
	int _min=-1e9,x=0,p=0;
	for(int i=0;i<k;i++){
		cin>>x;
		for(int i=0;i<n;i++){
			cin>>p;
			x+=p;
		}
	}
	cout<<x<<endl; 
	return 0;
} 
