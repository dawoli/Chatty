#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[11][11],b;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	b=a[1][1];
	for(int j=1;j<=m;){
		//cout<<j<<'\n';
		for(int i=1;i<=n;i++){
			//cout<<i<<'-'<<'\n';
			int mpi=i,mpj=j;
			for(int k=j;k<=m;){
				for(int p=1;p<=n;p++){
					if(k==j&&p<i) continue;
					if(a[p][k]>a[mpi][mpj]){
						mpi=p,mpj=k;
					}
				}
				k++;
				for(int p=n;k<=m&&p>=1;p--){
					if(a[p][k]>a[mpi][mpj]){
						mpi=p,mpj=k;
					}
				}
				k++;
			}
			swap(a[i][j],a[mpi][mpj]);
		}
		j++;
		for(int i=n;j<=m&&i>=1;i--){
			int mpi=i,mpj=j;
			for(int k=j;k<=m;){
				for(int p=n;k<=m&&p>=1;p--){
					if(k==j&&p>i) continue;
					if(a[p][k]>a[mpi][mpj]){
						mpi=p,mpj=k;
					}
				}
				k++;
				for(int p=1;p<=n;p++){
					if(a[p][k]>a[mpi][mpj]){
						mpi=p,mpj=k;
					}
				}
				k++;
			}
			swap(a[i][j],a[mpi][mpj]);
		}
		j++;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==b){
				cout<<j<<' '<<i;
				return 0;
			}
		}
	}
	return 0;
} 
