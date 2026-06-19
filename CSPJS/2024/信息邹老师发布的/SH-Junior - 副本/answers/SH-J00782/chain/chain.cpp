#include<iostream>
#include<stdio.h>
#include<map>
using namespace std;
map<int,bool> mp;
int n,k,q;
int t;
int l;
int r,c;
int x;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		mp.clear();
		cin>>n>>k>>q;
		for(int j=1;j<=n;j++){
			cin>>l;
			bool flag=0;
			for(int k=1;k<=l;k++){
				cin>>x;
				if(flag) mp[x]=1;
				if(x==1) flag=1;
			}
		}
		for(int j=1;j<=q;j++){
			cin>>r>>c;
			cout<<mp[c]<<endl;
		}
	}
	return 0;
}
