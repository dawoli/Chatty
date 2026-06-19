#include<bits/stdc++.h>
using namespace std;
int n,a[5][19];
char pri,num;
int p,u,ans=52;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>pri>>num;
		if (pri=='D') p=1;
		if (pri=='C') p=2;
		if (pri=='H') p=3;
		if (pri=='S') p=4;
		if (num=='A') u=1;
		if (num=='T') u=10;
		if (num=='J') u=11;
		if (num=='Q') u=12;
		if (num=='K') u=13;
		if (num>='2' and num<='9') u=int(num-'0');
		if (a[p][u]==0){
			ans--;
			a[p][u]=1;
		}
	}
	cout<<ans<<endl;
	return 0;
}
