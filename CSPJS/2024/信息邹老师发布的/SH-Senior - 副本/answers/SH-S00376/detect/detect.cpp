#include<bits/stdc++.h>
using namespace std;
int d[200000],v[200000],a[200000],q[200000],c[2000000];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		memset(c,0,sizeof c);
		int n,m,L,V,cnt=0;
		int s=-1,e=-1;
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
		}
		for(int i=1;i<=m;i++){
			cin>>q[i];
		}
		for(int i=1;i<=n;i++){
			double x=-1;
			if(a[i]==0){
				if(v[i]>V){
					x=L;
				}
			}
			else x=(V*V-v[i]*v[i])/(2*a[i]);
			bool flag1=1,flag2=1;
			s=-1,e=-1;
			for(int j=1;j<=n;j++){
				if(flag1&&q[j]<d[i]){
					s=j;
				}
				else flag1=0;
				if(flag2&&q[j]<x){
					e=j;
				}
				else{
					flag2=0;
					e=j;
				}
			}
			if(s!=-1&&e!=-1){
				cnt++;
				for(int j=s;j<=e;j++){
					c[j]++;
				}
			}
		}
		cout<<cnt<<" ";
		int cnt1=0;
		int i=n;
		sort(c+1,c+1+n);
		while(cnt>0){
			cnt-=c[i];
			i--;
			cnt1++;
		}
		
		cout<<m-cnt1<<endl;
	}
	return 0;
}
/*
0 2 2 1 2
		2
  3 3 3 3
  4 4   

*/
