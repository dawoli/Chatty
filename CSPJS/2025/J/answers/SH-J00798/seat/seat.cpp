#include<bits/stdc++.h>
using namespace std;
int n,m,c,r,i,j,b,d,rscore,a[110],z[12][12];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1,b=0;i<=n;i++){
		for(j=1;j<=m;j++){
			b++;
			cin>>a[b];
		}
	}
	rscore=a[1];
	sort(a+1,a+b+1);
	//cout<<a[1]<<" "<<a[b];
	for(j=1,i=n+1,b++,d=1;j<=m;j++){
		for(i=(j%2==1)?1:n;n-i>=0&&i>0;i+=d){
			b--;
			z[i][j]==a[b];
			if(a[b]==rscore){
				cout<<j<<" "<<i;
				//cout<<" "<<rscore<<" "<<a[b]<<' '<<b;
				return 0;
			}
			//cout<<j<<" "<<i<<" ";
		}
		d=-d;
	}
	
	return 0;
}
