#include <bits/stdc++.h>
using namespace std;
int t,n,x[200009],y[200009],c;
int color(){
	c=0;
	for(int i=1;i<=200000;i++){
		y[i]=0;
	}
	for(int i=1;i<=n;i++){
		if(y[x[i]])c+=x[i];
		else{
			y[x[i]]++;
		}
	}
	cout<<c<<endl;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>x[j];
		}
		color();
	}
	return 0;
}

