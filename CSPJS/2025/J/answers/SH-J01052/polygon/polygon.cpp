#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	int a[13];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	if(a[0]+a[1]>a[2]){
		cout<<1;
	}else{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
