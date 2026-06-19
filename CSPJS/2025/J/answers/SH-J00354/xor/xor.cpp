#include <bits/stdc++.h>
using namespace std;
int n,k; 
int num[114514];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>num[i];
	}
	cout<<n/k;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
