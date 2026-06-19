#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],d=0,c=0,e=0,g=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) d=1,c++;
		if(a[i]==1) e++;
	}
	if(k==1){
		cout<<e;
	}
	else if(d){
		for(int i=1;i<n;i++){
			if(a[i]==1&&a[i+1]==1){
				g++;
				i++;
			}
		}
		cout<<g+c;
	}
	else if(k==0&&d==0){
		cout<<e/2;
	}
	return 0; 
}
