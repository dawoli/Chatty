#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105],r=1;
	cin>>n>>m;
	for (int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	for (int i=2;i<=n*m;i++){
		if (a[i]>a[1]){
			r++;
		}
	}
	int c,rr;
	c=(r-1)/m+1;
	if (c%2==1){
		if (r%m==0){
			rr=m;
		}
		else{
			rr=r%m;
		}
	}
	else{
		if (r%m==0){
			rr=1;
		}
		else{
			rr=m-r%m+1;
		}
    }
	cout<<c<<" "<<rr;
	return 0; 
}
