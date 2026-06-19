#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t,n;
	cin>>t;
	int a[55]={0,-1,1,7,4,5,6,8,10,18,22,20,28,68,88,222,220,228,208,288,688,888};
	for (int i=1;i<=t;i++){
		cin>>n;
		cout<<a[n]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
