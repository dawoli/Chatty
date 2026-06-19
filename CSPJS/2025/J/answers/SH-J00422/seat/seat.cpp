#include<bits/stdc++.h>
using namespace std;
int n,m,un,a[1010],tp,lu=0,mat[20][20];
//si ren bang,dou shi huai dongxi!!
//pantu tewu yexinjia dajunfa 

//const int LUOGU=909552;
inline bool cmp(int a,int b){
	return a>b;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	tp=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==tp){
			lu=i;break;
		}
	}//cout<<lu<<endl;
	int cols=(lu/(2*n))*2,rows=0;
	int un=lu%(2*n);
	if(un>n)cols+=2,rows=2*n-un+1;
	else if(un==0)rows=1;
	else cols++,rows=un;
	cout<<cols<<" "<<rows;
	
//	cout<<'\n';
//	for(lu=1;lu<=n*m;lu++){
//		int cols=(lu/(2*n))*2,rows=0;
//		int un=lu%(2*n);
//		if(un>n)cols+=2,rows=2*n-un+1;
//		else if(un==0)rows=1;
//		else cols++,rows=un;
//		mat[rows][cols]=lu;
//	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++)cout<<mat[i][j]<<" ";
//		cout<<'\n';
//	}
	return 0;
}
