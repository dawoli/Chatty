#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100009];
int id[100009];
bool cmp(int &x,int &y){
	return a[x]>a[y];
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i],id[i]=i;
	sort(id+1,id+n*m+1,cmp);
	int k=id[1];
	cout<<(k-1)/n+1<<" ";
	if(((k-1)/n+1)%2==0){
		if(k%n==0)cout<<1;
		else cout<<n+1-k%n;
	}
	else{
		if(k%n==0)cout<<n;
		else cout<<k%n;
	}
	cout<<endl;
	return 0;
}


