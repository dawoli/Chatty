#include<bits/stdc++.h>
using namespace std;
int a[5005],ang;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n=3){
		int o=0,m=0;
		for(int i=1;i<=n;i++){
			o+=a[i];
			m=max(m,a[i];)
		}
		if(2*m<o){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	return 0;
} 
