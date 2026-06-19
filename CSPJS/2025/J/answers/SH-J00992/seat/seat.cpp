#include<bits/stdc++.h>
using namespace std;
int a[1005];
int n,m,sc;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;//hang,lie
	cin>>sc;
	a[1]=sc;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}sort(a+1,a+1+n*m,cmp);
	int id=1;
	for(id=1;id<=n*m;id++){
		if(a[id]==sc) break;
	}int lie=1,hang=0;
	while(id>2*n){
		id-=2*n;
		lie+=2;
	}
	if(id<=n){
		hang=id%n;
		if(hang==0) hang=n;
	}else {
		lie++;
		id-=n;
		hang=n-id+1;
	}cout<<lie<<" "<<hang;
	return 0;
}

