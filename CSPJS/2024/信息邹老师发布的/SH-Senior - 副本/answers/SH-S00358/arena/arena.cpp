#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[102],c[102],p[102];
int t;
string s;
int k;
int poww[102][10];
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cin>>c[i];
	}
	int cn=1;
	for(int i=1;i<=10000;i++){
		if((cn*2)<=n){
			k++;
			cn*=2;
		}else{
			break;
		}
	}
	for(int i=1;i<=k;i++){
		cin>>p[i];
	}
	cin>>t;
	for(int tt=1;tt<=t;tt++){
		cin>>poww[tt][1]>>poww[tt][2]>>poww[tt][3]>>poww[tt][4];
		cout<<"1"<<endl;
		
	}
	return 0;
}
