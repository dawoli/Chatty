#include<bits/stdc++.h>
using namespace std;
int t,n,m,l,vl,vlpow;
int d[100005];
int v[100005];
int a[100005];
//int p[100005];
map <int,map<int,bool> > mas;
int fat[100005];
bool f[100005];
int cnt,cntp;
bool isaz;
int dz[100005];
struct tst{
	int loc;
	int cont;
} p[100005];
bool cmp(tst a,tst b) {
	return a.cont<b.cont;
}
int main() {
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	while(t--) {
		cin>>n>>m>>l>>vl;
		vlpow=vl*vl;
		cnt=0;
		cntp=0;
		mas.clear();
		isaz=1;
		for(int i=1;i<=n;i++) {
			cin>>d[i]>>v[i]>>a[i];
			if(a[i]!=0) {
				isaz=0;
			}
			f[i]=0;
			fat[i]=0;
			if(a[i]<0) {
				dz[i]=int(d[i]+v[i]*v[i]*-1/(2*a[i]));
			}
		}	
		
		for(int i=1;i<=m;i++) {
			cin>>p[i].loc;
			p[i].cont=0;
		}
		if(isaz==1) {
			for(int i=1;i<=n;i++) {
				if(v[i]>vl) {
					cnt++;
				}
			}
			cntp=m-1;
			cout<<cnt<<' '<<cntp<<endl;
			continue;
		}
		for(int i=1;i<=m;i++) {
			int dis=p[i].loc;
			for(int j=1;j<=n;j++) {
				if(dis<d[j]) {
					continue;
				}
				if(a[j]<0) {
					if(dz[j]<dis) {
						continue;
					}
				}
				int vpow;
				vpow=2*(dis-d[j])*a[j]+v[j]*v[j];
				if(vpow>vlpow) {
					mas[p[i].loc][j]=1;
					fat[j]++;
					p[i].cont++;
					if(f[j]==0) {
						f[j]=1;
						cnt++;
					}
				}
			}
		}
		sort(p+1,p+1+m,cmp);
//		for(int i=1;i<=m;i++) {
//			cout<<p[i].loc<<p[i].cont<<endl;
//		}
		for(int i=1;i<=m;i++) {
			bool flag=0;
			for(int j=1;j<=n;j++) {
				if(mas[p[i].loc][j]!=1) {
					continue;
				}
				if(fat[j]==1) {
					flag=1;
				}
			}
			if(flag==0) {
				cntp++;
			}
			for(int j=1;j<=n;j++) {
				if(mas[p[i].loc][j]!=1) {
					continue;
				}
				fat[j]--;
			}
		}
		cout<<cnt<<' '<<cntp<<endl;
	}
	return 0;
}
