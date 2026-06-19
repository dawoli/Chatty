#include<bits/stdc++.h>
using namespace std; 
int n,f=1,ans; 
string a[52]; 
int main(){
	freopen("poker.in","r",stdin); 
	freopen("poker.out","w",stdout); 
	cin>>n; 
	for(int i=0; i<n; i++){
		cin>>a[i]; 
		for(int j=0; j<i; j++){
			if(a[i]==a[j]) f=0; 
		}
		if(f==1) ans+=1; 
		f=1; 
	}
	cout<<52-ans; 
	fclose(stdin); 
	fclose(stdout); 
}
