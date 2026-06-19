#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
	int vl;
	bool mk;
}a[109],s[19][19];
bool cmp(node x,node y){
	return x.vl>y.vl;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i].vl;
	}
	a[0].mk=1;
	sort(a,a+n*m,cmp);
	int ii=0,jj=0;
	bool od=0;
	for(int k=0;k<n*m;k++){
		s[ii][jj]=a[k];
		if(!od) ii++;
		else ii--;
		if(!od&&ii==n) jj++,ii=n-1,od=1;
		else if(od&&ii==-1) jj++,ii=0,od=0;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(s[i][j].mk){
				cout<<i+1<<' '<<j+1<<endl;
				return 0;
			}
		}
	}
	return 0;
} 
