#include<bits/stdc++.h>
using namespace std;
const int maxn=15;
int n,m,rk,S;
int sc[maxn];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>sc[i];
		if(i==1) S=sc[i];
	}
	sort(sc+1,sc+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(sc[i]==S){
			rk=i;
			break;
		}
	}
	int lie=0;
	if(rk%m==0) lie=rk/m;
	else lie=rk/m+1;
	if(lie%2) cout<<lie<<' '<<(rk-(lie-1)*n);
	else cout<<lie<<' '<<n-(rk-(lie-1)*n)+1;
	return 0;
}
