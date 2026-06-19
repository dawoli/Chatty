#include<bits/stdc++.h>
using namespace std;
bool a['Z'+1]['Z'+1];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		char x,y;
		cin>>x>>y;
		ans++;
		if(a[x][y]) ans--;
		a[x][y]=1;
	}	
	cout<<52-ans;
	return 0;
}

