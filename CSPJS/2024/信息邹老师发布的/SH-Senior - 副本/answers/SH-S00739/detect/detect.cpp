#include<bits/stdc++.h>
using namespace std;
int cnt,T,n,m,canoff,flag;
bool flaga,book[3001][3001],book1[3001],book2[3001][3001];
long double V,len,d[100001],a[100001],v[100001],p[100001];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		memset(book,0,sizeof book);
		memset(book1,0,sizeof book1);
		cin>>n>>m>>len>>V;
		cnt=0,canoff=0;
		for(int i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
			if(a[i]!=a[i-1]) flaga=1;
		}
		for(int i=1;i<=m;i++){
			cin>>p[i];
		}
		if(flaga==0){
			for(int i=1;i<=n;i++){
				if(v[i]>V&&d[i]<=p[m]) cnt++;
			}
			cout<<cnt<<" ";
			if(cnt==0) cout<<m;
			else cout<<m-1;		
		}
		else{
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					if(d[i]<=p[j]){
						double route=p[j]-d[i];
						double v1=sqrt(v[i]*v[i]+2*a[i]*route);
						if(v1>V) book[i][j]=1;
					}
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					if(book[i][j]){
						cnt++;
						break;
					}
				}
			}
			cout<<cnt<<" ";
			int num=pow(2,m);
			for(int k=1;k<=num;k++){
				for(int i=1;i<=n;i++){
					for(int j=1;j<=m;j++) book2[i][j]=book[i][j];
				}
				int x=k,len2=0;
				for(int i=m;i>=1;i--){
					book1[i]=x%2;
					x/=2;
					if(book1[i]) len2++;
				}
				for(int i=1;i<=m;i++){
					if(book1[i]){
						for(int j=1;j<=n;j++){
							book2[j][i]=0;
						}
					}
				}
				int cnt111=0;
				for(int i=1;i<=n;i++){
					for(int j=1;j<=m;j++){
						if(book2[i][j]){
							cnt111++;
							break;
						}
					}
				}
				if(cnt111==cnt) canoff=max(canoff,len2);
			}
			cout<<canoff;
		}
		cout<<endl;
	}
	return 0;
}
