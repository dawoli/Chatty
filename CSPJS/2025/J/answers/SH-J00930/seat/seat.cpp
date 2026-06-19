#include<bits/stdc++.h>
using namespace std;
int n,m;
int ans_i,ans_j;
int a[20][20],b[400];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>b[i];
	int score=b[1];
	sort(b+1,b+n*m+1,cmp);
	int j=1;
	for(int i=1;i<=m;i++) {
	    if(i%2==1) {
			for(int k=1;k<=n;k++) {
				a[k][i]=b[j];
				if(b[j]==score) ans_i=i,ans_j=k;
				j++;
			}
		} else {
			for(int k=n;k>=1;k--) {
				a[k][i]=b[j];
				if(b[j]==score) ans_i=i,ans_j=k;
				j++;
			}
		}
	}
	cout<<ans_i<<" "<<ans_j;
	return 0;
}
