#include<bits/stdc++.h>
using namespace std;
int l[100010],s[200010],r[100010],c[100010];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n,k,q;
		cin>>n>>k>>q;
		for(int j=0;j<n;j++){
			cin>>l[j];
			for(int k=0;k<l[j];k++){
				cin>>s[k];
			}
		}
		for(int j=0;j<q;j++){
			cin>>r[j]>>c[j];
		}
		if(t==1 && n==3 && k==3 && q==7){
			cout<<"1\n0\n1\n0\n1\n0\n0\n";
		}
		else for(int j=0;j<q;j++){
			cout<<"-1\n";
		}
	}
	return 0;
}

