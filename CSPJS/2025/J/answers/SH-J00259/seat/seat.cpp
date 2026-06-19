#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int in,m,s,n;
	int a[1003],t=0;
	cin>>in>>m;
	cin>>a[0];
	n=in*m;
	
	for(int i=1;i<n;i++)
	{
		cin>>a[i];
		if(a[i]>a[0]) t++;
	}
	int l=t/in;
	cout<<l+1<<" ";
	if(l%2==1){
		cout<<in-t%in;
	}else{
		cout<<t%in+1;
	}
	return 0;
}
