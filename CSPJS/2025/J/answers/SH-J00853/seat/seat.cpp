#include <bits/stdc++.h>
using namespace std;
int x[103];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>x[i];
	int o=x[1];
	sort(x+1,x+n*m+1);
	int l=1,c=1;
	for(int i=1;i<=n*m;i++){
		if(x[n*m-i+1]==o){
			cout<<c<<" "<<l<<endl;
			return 0;
		}
		if((i+1)%n==1) c++;
		else if((i/n)%2==0) l++;
		else l--;
	}
	return 0;
}
