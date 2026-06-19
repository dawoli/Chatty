#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int b,m,n,a[100],rec,res[100][100],c=1,ans1,ans2,sTemp=1;;
	cin>>m>>n;
	rec=m*n;
	for(int i=1; i<=rec; i++) {
		cin>>a[i];
	}
	b=a[1];
	for(int i=1; i<rec; i++) {
		for(int j=i+1; j<=rec; j++)
			if(a[i]<a[j])swap(a[i],a[j]);
	}
	for(int i=1; i<=n; i++ ) {
		if(i%2!=0) {
			for(int j=1; j<=m; j++) {
				res[i][j]=a[c];
				c++;
				if(res[i][j]==b)ans1=i,ans2=j;
			}
		} else {
			for(int j=m; j>=1; j--) {
				res[i][j]=a[c];
				c++;
				if(res[i][j]==b)ans1=i,ans2=j;
			}
		}
	}
	cout<<ans1<<" "<<ans2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
