#include<bits/stdc++.h>
using namespace std;
int n,m;
int map1[20][20];
struct Node{
	int a,i;
}a[105];
bool cmp(Node a,Node b){
	return a.a>b.a;
}
int main(){
	freopen("seat.in","r",stdin);freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].a;
		a[i].i=i;
	}
	sort(a+1,a+n*m+1,cmp);
	
	int cnt=0;
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++){
				map1[i][j]=a[++cnt].i;
				if(a[cnt].i==1){
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}
		else{
			for(int i=n;i>=1;i--){
				map1[i][j]=a[++cnt].i;
				if(a[cnt].i==1){
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}	
	}
	return 0;
}
