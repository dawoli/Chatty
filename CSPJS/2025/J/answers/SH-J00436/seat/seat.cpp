#include<bits/stdc++.h>
using namespace std;
int mp[1005][1005];
int a[100005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,ans=0,t=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	ans=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++)
				mp[j][i]=a[++t];
		}else{
			for(int j=n;j>=1;j--)
				mp[j][i]=a[++t];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(ans==mp[i][j]){
				cout<<j<<" "<<i;
				break;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
