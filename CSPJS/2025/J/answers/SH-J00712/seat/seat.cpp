#include<bits/stdc++.h>
using namespace std;
int a[101],q,c,ang;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cin>>c;
	a[c]++;
	for(int i=1;i<n*m;i++){
		scanf("%d",&q);
		a[q]++;
	}
	for(int i=100;i>=c;i--){
		
		if(a[i]==1 ){
			ang++;
		}
		
	}
	int h=ang%n,l=ang/n;
	if(h==0){
		h=n;
	}
	if(l*n!=ang){
		l++;
	}
	if(l%2==0){
		h=n-h+1;
	}
	cout<<l<<" "<<h;
	return 0;
} 
