#include<bits/stdc++.h>
using namespace std;
char aa,bb;
int a[200],b[200],f[200][200],n,m;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	a['D']=1,a['C']=2,a['H']=3,a['S']=4;
	b['A']=1,b['T']=10,b['J']=11,b['Q']=12,b['K']=13;
	for(int i=1;i<=8;i++) b[i+'1']=i+1;
	cin>>n;m=52;
	for(int i=1;i<=n;i++){
		cin>>aa>>bb;
		f[a[aa]][b[bb]]++;
		if(f[a[aa]][b[bb]]==1) m--;
	}
	cout<<m;
	return 0;
}
