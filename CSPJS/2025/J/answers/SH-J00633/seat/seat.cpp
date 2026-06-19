#include<bits/stdc++.h>
using namespace std;
int n,m,aim,t,a[110],s[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	aim=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				s[j][i]=++t;
				if(a[(i-1)*n+j]==aim){
					cout<<i<<" "<<j;
					fclose(stdin);
					fclose(stdout);
					return 0;
				}
			}
		}
		else{
			for(int j=n;j>=1;j--){
				s[j][i]=++t;
				if(a[(i-1)*n+n-j+1]==aim){
					cout<<i<<" "<<j;
					fclose(stdin);
					fclose(stdout);
					return 0;
				}
			}
		}
	}
	return 0;
}
