#include<bits/stdc++.h>
using namespace std;

int t, n, m, l, v;
int car[100010][4], mon[100010],ans, fw[100010][3];
bool light[100010];

double calf(int a, int b) {
	if(car[a][1]>b) return 0;
	return sqrt(car[a][2]*car[a][2]+2.0*car[a][3]*(b-car[a][1]));
}

double cala(int a) {
	double ans=(v*v-car[a][2]*car[a][2])/1.0/2.0/car[a][3];
	if(ans<0) return 0;
	return ans;
}

int main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	cin>>t;
	for(int xunhuan=1;xunhuan<=t;xunhuan++) {
		memset(fw, 0, sizeof(fw));
		cin>>n>>m>>l>>v;
		for(int i=1;i<=n;i++) for(int j=1;j<=3;j++) scanf("%d", &car[i][j]);
		for(int i=1;i<=m;i++) scanf("%d", &mon[i]);
		sort(mon+1, mon+m+1);
		
		ans=0;
		for(int i=1;i<=n;i++) {
			if(car[i][3]>=0) {
				if(calf(i, mon[m])>v) ans++;
			}
			else {
				fw[i][1]=lower_bound(mon+1, mon+m+1, car[i][1])-mon;
				if(fw[i][1]>m) continue;
				if(calf(i, mon[fw[i][1]])>v) {
					ans++;
					fw[i][2]=lower_bound(mon+1, mon+m+1, car[i][1]+cala(i))-mon-1;
					if(upper_bound(mon+1, mon+m+1, cala(i))-lower_bound(mon+1, mon+m+1, cala(i))==1)
						fw[i][2]++;
				}
			}
		}
		cout<<ans<<' ';
		if(car[1][3]>=0){
			if(ans==0) cout<<m<<endl;
			else cout<<m-1<<endl;
		}
		else {
			memset(light, 0, sizeof(light));
			for(int i=1;i<=n;i++) light[fw[i][1]]=1;
			ans=0;
			for(int i=1;i<=m;i++) ans+=light[i];
			cout<<m-ans<<endl; 
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
