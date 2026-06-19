#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
int weici=1;
int lie,hang;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
		if(a[i]>a[0])weici++;
	}
	if(weici%n==0)lie=weici/n;
	else lie=weici/n+1;
	if(lie%2==1){
		if(weici%n!=0)hang=weici%n;
		else hang=n;
	}
	else hang=n-(weici%n)+1;
	cout<<lie<<" "<<hang;
	return 0;
} 
