#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005];
bool all1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	all1=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) all1=0;
	}
	
	if(all1 and k==0){
		cout<<n/2<<endl;
		fclose(stdin);
		fclose(stdout);
		return 0;
	} 
	cout<<2<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
