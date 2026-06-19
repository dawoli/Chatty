#include<iostream>
#include<algorithm>>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[1001],ans,h=1,l=1;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
	cin>>a[i];
	}
	ans=a[0];
	sort(a,a+n*m);
	for(int i=0;i<n*m;i++){
	if(a[i]==ans) {ans=n*m-i;break;
	}
	}
	for(int i=0;i<ans;i++){
	if(h==n&&l%2==1) {l++;i++;}
	if(l%2==1) {h++;}
	if(l%2==0&&h==1){l++;i++;}
	if(l%2==0){h--;}
	}
	
	cout<<l<<" "<<h;
	return 0;
}
