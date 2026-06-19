#include<bits/stdc++.h>
using namespace std; 
int n,a[100005],m,k=2; 
int main(){
	freopen("duel.in","r",stdin); 
	freopen("duel.out","w",stdout); 
	cin>>n; 
	m=n; 
	for(int i=1; i<=n; i++){
		cin>>a[i]; 
	}
	sort(a+1,a+n+1); 
	for(int i=2; i<=n; i++){
		if(a[1]<a[k]){
			for(int j=2; j<=n; j++) a[j-1]=a[j]; 
			m-=1; 
			k-=1; 
		}
		k+=1; 
	}
	cout<<m; 
	fclose(stdin); 
	fclose(stdout); 
	return 0; 
}
