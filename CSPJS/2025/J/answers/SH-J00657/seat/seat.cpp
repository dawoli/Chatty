#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int a,int b){
	return a>b;
}
int ansx=0,ansy=0;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int num=a[1],index=0;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i]==num)
			index=i;
//	cout<<index<<endl;
	int temp=index/(n*2);
	index=index%(n*2);
//	cout<<temp<<" "<<index<<endl;
	if(index>n){
		ansx=temp*2+2;
		ansy=2*n-index;
	}
	else{
		ansx=temp*2+1;
		ansy=index;
	}
	cout<<ansx<<" " <<ansy;
	return 0;
} 
//奶奶的可恶至极
//num=a[0]但是从1开始数数 
