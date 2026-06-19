#include <bits/stdc++.h>
using namespace std;
int a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,t,s,b=0,c,r;
	cin>>n>>m;
	for(int i=0;i<n*m;++i){
		cin>>a[i];
		if(i==0)
		   s=a[i];
	}
	for(int i=0;i<n*m;++i){
		for(int j=0;j<n*m;++j){
			if(a[j]<a[j+1]){
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	for(int i=0;i<n*m;++i){
		b++;
		if(a[i]==s)
		   break;
	}
	if(b%n==0){
		c=b/n;
		if(c%2!=0){
			r=n;
		}
		else
		    r=1;
	}
	else
	    c=b/n+1;
	    if(c%2!=0)
	       r=b-(c-1)*n;
	    else
	        r=n-(b-(c-1)*n);
	cout<<c<<" "<<r<<endl;
	return 0;
}
