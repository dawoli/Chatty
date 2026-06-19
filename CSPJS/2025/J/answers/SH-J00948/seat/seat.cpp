#include<bits/stdc++.h>
using namespace std;
int n,m,a[1010],sc,ts,st[110][110],ai,aj;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	sc=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n;i++){
		if(i%2){
			for(int j=1;j<=m;j++){
				st[i][j]=a[++ts];
				if(a[ts]==sc){
					ai=i;
					aj=j;
				}
			}
		}
		else{
			for(int j=m;j>=1;j--){
				st[i][j]=a[++ts];
				if(a[ts]==sc){
					ai=i;
					aj=j;
				}
			}
		}
	}
	cout<<ai<<' '<<aj;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
