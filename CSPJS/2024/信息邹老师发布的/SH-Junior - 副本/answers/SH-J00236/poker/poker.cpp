#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,ans;
	char a;
	cin>>n;
	for(int i=0;i<n;i++)cin>>a;
	ans=52-n;
	if(ans<0)ans=0;
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
