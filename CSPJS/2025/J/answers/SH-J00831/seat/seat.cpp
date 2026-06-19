#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
int r[15][15];
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	int nm=n*m;
	r[1][1]=1; // 1st high
	int curi=1,curj=1;
	int move=-1; // truly true
	for(int id=1;id<=nm;id++){
		r[curi][curj]=id;
		if(1<curi && curi<n) curi+=move;
		else if(curi==1 && (curj&1^1)) curj++;
		else if(curi==n && (curj&1)) curj++;
		else { move=-move; curi+=move; }
//printf("id= %3d done. cur (%3d, %3d)\n",id,curi,curj);
	}
//for(int i=1;i<=n;i++,printf("\n"))for(int j=1;j<=m;j++)printf("%3d ",r[i][j]);
	for(int i=1;i<=nm;i++) scanf("%d",&a[i]);
	int R_rank=0;
	for(int i=1;i<=nm;i++)
		if(a[i]>=a[1]) R_rank++;
//printf("R: #%d\n",R_rank);
	for(int j=1;j<=m;j++)
		for(int i=1;i<=n;i++)
			if(r[i][j]==R_rank){ // sit here!
				printf("%d %d\n",j,i);
				return 0;
			}
}

