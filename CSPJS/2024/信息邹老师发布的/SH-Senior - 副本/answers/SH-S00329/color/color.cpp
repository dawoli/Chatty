#include<bits/stdc++.h>
using namespace std;
int n,m[100005];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t,n,m[10000];
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>m[i];
		}
		int tax=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(m[i]==m[j]){
					tax=max(tax,m[i]);
				}
			}
		}
		cout<<tax<<endl;
	}
	return 0;
} 
