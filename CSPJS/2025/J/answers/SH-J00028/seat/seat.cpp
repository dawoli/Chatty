#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	int l[n*m];
	int r;
	for(int i = 0;i<n*m;i++){
		cin>>l[i];
	}
	r = l[0];
	sort(l,l+n*m);
	int lie = 1,hang = 1;
	for(int i = n*m-1;i>=0;i--){
		if(l[i]==r){
			cout<<lie<<' '<<hang;
			break;
		}
		if(hang==n && lie%2==1){
			lie++;
		}
		else if(hang==1 & lie%2==0){
			lie++;
		} 
		else if(lie%2==1){
			hang++;
		}
		else{
			hang--;
		}
	}
	return 0;
}
