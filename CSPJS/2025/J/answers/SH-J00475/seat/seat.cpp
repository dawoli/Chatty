#include<bits/stdc++.h>

using namespace std;
int n,m;
struct node{
	int id;
	int score;
};
node a[2007];
int s[107][107];
bool cmp(node x,node y){
	return x.score>y.score;
}
int cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].score;
		a[i].id=i;
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				s[i][j]=a[++cnt].id;
			}
		}
		else{
			for(int j=m;j>=1;j--){
				s[i][j]=a[++cnt].id;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]==1){
				cout<<i<<" "<<j<<endl;
				return 0;
			}
		}
	}
	return 0;
}
