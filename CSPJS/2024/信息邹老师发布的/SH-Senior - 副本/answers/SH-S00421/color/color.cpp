#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n,a[1000000];
		bool c=true;
		cin>>n;
		for(int j=0;j<n;j++){
			int b;
			cin>>b;
			if(a[b]>0){
				c=false;
			} 
			a[b]++;
		}
		if(c) cout<<"0\n";
	}
}
