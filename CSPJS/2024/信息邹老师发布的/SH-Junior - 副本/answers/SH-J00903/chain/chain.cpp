#include<iostream>
using namespace std;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,k,q;
		string a[1010];
		cin>>n>>k>>q;
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			for(int j=0;j<x;j++){
				char y;
				cin>>y;
				if(y!=' ')a[i]+=y;
			}
		}
		for(int i=0;i<q;i++){
			char x,y;
			cin>>x>>y;
			int f;
			for(int j=0;j<a[0].length();j++){
				if(a[0][j]==y){
					f=j;
					break;
				}
			}
			for(int j=f;j>=0;j--){
				if(f-j+1>k){
					cout<<0;
					break;
				}
				if(a[0][j]=='1'){
					cout<<1;
					break;
				}
			}
		} 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
