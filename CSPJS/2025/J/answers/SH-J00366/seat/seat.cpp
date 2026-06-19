#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	
	int n,m,flag,a[105];
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
	}
	flag=a[1];
	sort(a+1,a+n*m+1,cmp);
	int ansx=1,ansy=1,der=1;
	for(int i=1;i<=m*n;i++){
		if(a[i]==flag){
			cout<<ansx<<" "<<ansy;
			
		}
		if(ansy==n&&der==1){
			ansx+=1;
			der=-der;
			continue;
		}
		if(ansy==1&&der==-1){
			ansx+=1;
			der=-der;
			continue;
		}
		ansy+=der;
		
	}
	return 0;
}
