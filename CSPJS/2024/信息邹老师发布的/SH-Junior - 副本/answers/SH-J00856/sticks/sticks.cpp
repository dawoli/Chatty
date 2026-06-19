#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	const string a[7]={"8","10","18","22","20","28","80"};
	const string g[8]={"-1","-1","1","7","4","2","0","8"};
	int b,c;
	cin>>b;
	string f[b];
	for(c=0;c<b;c++){
		int d,e;
		cin>>d;
		if(d<=7){
			f[c]=g[d];
			continue;
		}
		f[c]=a[d%7];
		d-=7;
		d/=7;
		for(e=0;e<d;e++){
			f[c]=f[c]+"8";
		}
	}
	for(c=0;c<b;c++){
		cout<<f[c]<<endl;
	}
	return 0;
}
