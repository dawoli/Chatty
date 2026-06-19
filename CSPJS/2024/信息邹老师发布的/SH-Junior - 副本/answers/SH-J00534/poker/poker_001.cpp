#include<bits/stdc++.h>
using namespace std;
int n,t,open;
string m,a[60];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		open=1;
		cin>>m;
		for(int i=0;i<t;i++){
			if(a[i]==m) open=0;
		}
		if(open) a[t++]=m;
	}
	cout<<52-t;
	return 0;
}
