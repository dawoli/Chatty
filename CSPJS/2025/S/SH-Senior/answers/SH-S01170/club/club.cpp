#include <bits/stdc++.h>
using namespace std;
int n;
int a[100006][3];
int dif[100006][3];
int rep[100006];
int maxn=-1;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin >> T;
	while (T--){
		maxn=0;
		cin >> n;
		int k1=0,k2=0,k3=0;
		for (int i=1; i<=n; i++){
			cin >> a[i][0] >> a[i][1] >> a[i][2];
			int ky=max(a[i][0],max(a[i][1],a[i][2]));
			//cout << rep[i] << endl;
			//
			maxn+=ky;
			if (a[i][0]==ky){
				k1++;
			}else if (a[i][1]==ky){
				k2++;
			}else{
				k3++;
			}
		}
		if (max(k1,max(k2,k3))>n/2){
			for (int i=1; i<=n; i++){
				int ky=max(a[i][0],max(a[i][1],a[i][2]));
				dif[i][0]=a[i][0]-ky;
				dif[i][1]=a[i][1]-ky;
				dif[i][2]=a[i][2]-ky;
				int dd0=dif[i][0];
				int dd1=dif[i][1];
				int dd2=dif[i][2];
				rep[i]=dd0+dd1+dd2-max(dd0,max(dd1,dd2))-min(dd0,min(dd1,dd2));
			//
			}
			int errn=max(k1,max(k2,k3))-n/2;
			//cout << errn << "$\n";
			sort(rep+1,rep+n+1);
			for (int i=n-errn+1; i<=n; i++){
				maxn+=rep[i];
			}
		}
		cout << maxn << endl;
	}
	fclose(stdin);
	fclose(stdout);
}
/*
14:38 Start Typing.
What de Heel T1 Is So Hard!!!
I first Do 1-8+9+12
14:47 Finished DFS 1st Draft!
14:52 Dfs Ok
16:43 I found the solution, But I lost it aaaaaaaaaaa!
I have to write It Again!!!!!
17:00 I finished!
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
