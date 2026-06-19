#include<bits/stdc++.h>
using namespace std;
int n,a[100],ans=52;
bool v[5][15];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	a['D']=1,a['C']=2,a['H']=3,a['S']=4;
	a['A']=1,a['T']=10,a['J']=11,a['Q']=12,a['K']=13;
	for(int i=50;i<=57;i++) a[i]=i-48;
	cin>>n;
	for(int i=1;i<=n;i++){
		char c,d;
		cin>>c>>d;
		int x=a[c],y=a[d];
		if(!v[x][y]) v[x][y]=1,ans--;
	}
	cout<<ans;
	return 0;
}
