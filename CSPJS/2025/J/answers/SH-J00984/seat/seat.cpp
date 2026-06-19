#include <iostream>
#include <algorithm>
using namespace std;
struct csp {
	int no;
	int score;
};
bool cmp(csp a,csp b) {
	return a.score>b.score;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	csp k[110];
	for(int i=0; i<n*m; i++) {
		cin>>k[i].score;
		k[i].no=i;
	}
	sort(k,k+n*m,cmp);
	csp ans[150][150];
	int x=1,y=1,index=0;
	//for(int i=0;i<n*m;i++){
	//	cout<<k[i].no<<"|"<<k[i].score<<endl;
	//}
	while (true) {
		ans[x][y].no=k[index].no;
		ans[x][y].score=k[index].score;
		//cout<<"!"<<" "<<k[index].no<<" "<<x<<" "<<y<<" "<<endl;
		index++;
		if((x==n&&y==m&&m%2==1)||(x==n&&y==1&&(m%2==0)))break;
		else if(x==n&&y%2==1)y++;
		else if(x==n&&y%2==0)x--;
		else if(x==1&&y%2==0)y++;
		else if(x==1&&y%2==1)x++;
		else if(y%2==1)x++;
		else if(y%2==0)x--;
		//cout<<x<<" "<<y<<endl;
	}
	for(int i=1; i<=n; i++)for(int j=1; j<=m; j++) {
			if(ans[i][j].no==0) {
				cout<<i<<" "<<j<<endl;
				return 0;
			}
		}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
