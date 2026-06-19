#include <bits/stdc++.h>
using namespace std;
int n,m,s[105],w,l,h;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>s[i];
	}
	int r=s[1];
	sort(s+1,s+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(s[i]==r){
			w=i;
		}
	}
	if(w%n==0) l=w/n;
	else l=w/n+1;
	if(l%2==1) h=w%m;
	else{
		if(w%n==0) h=1;
		else h=n-w%n+1;
	}
	if(h==0) h=n;
	cout<<l<<" "<<h;
	return 0;
}
