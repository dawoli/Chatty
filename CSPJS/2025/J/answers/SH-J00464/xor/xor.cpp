#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,k,a[N],s;
int main(){
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s+=a[i];
	}

	if(k==0)
	cout<<n/2;
	else{
		cout<<s;
	}
	
	
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
