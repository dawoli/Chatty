#include<bits/stdc++.h>
using namespace std;
int n,m,Rsc,Rlo,a[109];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	Rsc=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++) if(a[i]==Rsc) Rlo=i;
	int x;
	if(Rlo%n==0) x=Rlo/n;
	else x=Rlo/n+1;
	Rlo%=n;
	if(Rlo==0) Rlo=n;
	if(x%2==1) cout<<x<<" "<<Rlo<<endl;
	else cout<<x<<" "<<n-Rlo+1<<endl;
	return 0;
}
