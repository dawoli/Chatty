#include<bits/stdc++.h>
using namespace std;
int a[10000],c[10000],book[10000];
int n,ans=0;
bool check(int d){
	if(d<4) return 0;
	int mi=-1,sum=0;
	for(int i=1;i<d;i++){
		sum+=c[i];
		mi=max(mi,c[i]);
	}
	return sum>2*mi;
}
void dfss(int now,int p,int y){
	if(check(p)){
		ans++;
	}
	for(int i=y;i<=n;i++){
		if(book[i]) continue;
		book[i]=1;
		c[p]=a[i];
		dfss(i,p++,y);
		c[p]=0;
		book[i]=0;
	}
	return;
}
int main(){
	freopen("polygon","r",stdin);
	freopen("polygon","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		book[i]=1;
		c[1]=a[i];
		dfss(i,2,i);
		
		book[i]=0;
	}
	cout<<ans;
	return 0;
}
