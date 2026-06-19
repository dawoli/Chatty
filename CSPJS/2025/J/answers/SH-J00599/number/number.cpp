#include <bits/stdc++.h>
using namespace std;
char e[10000],a[1000];
int r=0;
int main(){
	for(int i=1;i<=1000000;i++){
		cin>>e[i];
			r++;
		if(e[i]){
			break;
		
		}
		
	}
	int p=1;
	for(int i=1;i<=r;i++){
		if(e[i]<='9'){
			a[p]=e[i];
			p++;
			
		}
	}
	for(int i=2;i<=p;i++){
		if(a[i]>a[i-1]){
			char w=a[i];
			a[i]=a[i-1];
			a[i-1]=w;
		}
	}
	for(int i=p;i>=1;i--){
		cout<<a[i];
	}
	
}
