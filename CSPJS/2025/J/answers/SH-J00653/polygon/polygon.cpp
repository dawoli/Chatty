#include<iostream>
#include<cstdio>
using namespace std;
int a[5005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<3) cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
