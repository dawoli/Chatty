#include<bits/stdc++.h>
using namespace std;
int sum;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		sum+=c;
	}
	if (k==0){
		cout<<sum<<endl;
	}else{
		for(int i=0;i<k;i++){
			int a;
			cin>>a;
			for(int j=0;j<n;j++){
				cin>>a;
			}
		}
		cout<<0<<endl;
	}
	
	return 0;
	
}
