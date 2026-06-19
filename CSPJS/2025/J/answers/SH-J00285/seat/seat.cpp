#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
long long a1,a[150]={},n,m,l,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a1;
	a[1]=a1;
	for (int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n*m);
	l=1;
	r=1;
	for (int i=n*m;i>=1;i--){
		if (a[i]==a1){
			cout<<l<<" "<<r;
			break;
		}
		if (l%2==1){
			r++;
			if (r>n){
				r=n;
				l++;
			}
		}else{
			r--;
			if (r<1){
				r=1;
				l++;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
