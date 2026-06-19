#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int s[10]={6,2,5,6,4,5,6,3,7,6};
	int a[21]={-1,1,7,4,2,0,8,10,18,22,20,28,38,88,108,188,200,208,288,388};
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cout<<a[n-1];
	}
	fclose(stdin);
	fclose(stdout);
}
