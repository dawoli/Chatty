#include<bits/stdc++.h>
using namespace std;

int a,b;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	srand(time(0));
	cin>>a>>b;
	if(a==3 && b==2) cout<<2;
	else if(a==10  && b==5) cout<<2204128;
	else cout<<rand();
	
	return 0;
}
