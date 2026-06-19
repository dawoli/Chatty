#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int rscore,rrank,ri,rj;
bool f=0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)rscore=a[i];
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==rscore)rrank=i;
	}
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				rrank--;
				if(rrank==0){
					ri=i;
					rj=j;
					f=1;
					break;
				}
			}
		}
		else{
			for(int j=n;j>=1;j--){
				rrank--;
				if(rrank==0){
					ri=i;
					rj=j;
					f=1;
					break;
				}
			}
		}
		if(f)break;
	}
	cout<<ri<<" "<<rj;
	return 0;
}
