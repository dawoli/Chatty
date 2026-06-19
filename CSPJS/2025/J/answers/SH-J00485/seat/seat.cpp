#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int paimin=1;
	int reward;
	cin>>reward;
	for(int i=1;i<n*m;i++){
		int k;
		cin>>k;
		if(k>reward) paimin++;
	}
	int lie=paimin/n,hang=0;
	if(paimin%n!=0){
		lie++;
		hang=paimin%n;
	}else hang=n;
	if(lie%2==0) hang=n+1-hang;
	cout<<lie<<" "<<hang;
	return 0;
}
