#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
bool cmp(int x,int y){
	return x>y;
}
int ansn;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int sp=a[1];
	int pos=-1;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==sp){
			pos=i;
			break;
		}
	}
	int ansm,ansn;
	if(pos%n==0){
		ansm=pos/n;
		if(ansm%2==0) ansn=1;
		else ansn=n;
	}
	else{
		ansm=pos/n+1;
		if(ansm%2==0) ansn=n+1-pos%n;
		else ansn=pos%n;
	}
	
	cout<<ansm<<" "<<ansn;
	return 0;
}
