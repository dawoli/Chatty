#include<bits/stdc++.h>
using namespace std;

int t, n, m, k, robot[4], nxx, nxy, ans=0;
char mp[1003][1003];
bool pas[1003][1003], bj;

int main() {
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	cin>>t;
	for(int qpo=1;qpo<=t;qpo++) {
		cin>>n>>m>>k;
		for(int i=1;i<=3;i++) cin>>robot[i];
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=m;j++) cin>>mp[i][j];
		}
		memset(pas, 0, sizeof(pas));
		pas[robot[1]][robot[2]]=1;
		for(int i=1;i<=k;i++) {
			switch(robot[3]) {
				case 0:nxx=robot[1];nxy=robot[2]+1;break;
				case 1:nxx=robot[1]+1;nxy=robot[2];break;
				case 2:nxx=robot[1];nxy=robot[2]-1;break;
				case 3:nxx=robot[1]-1;nxy=robot[2];break;
			}
			bj=1;
			if(nxx<1||nxx>n||nxy<1||nxy>m) bj=0;
			else if(mp[nxx][nxy]=='x') bj=0;
			if(bj) {
				robot[1]=nxx;
				robot[2]=nxy;
				pas[robot[1]][robot[2]]=1;
			}
			else {
				robot[3]=(robot[3]+1)%4;
			}
		}
		ans=0;
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=m;j++) {
				if(pas[i][j]) ans++;
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
