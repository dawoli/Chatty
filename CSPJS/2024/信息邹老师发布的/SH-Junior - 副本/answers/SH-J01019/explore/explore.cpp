#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

char a[1005][1005];
bool b[1005][1005];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t,n,m,k;
	int st,sa,d;
	cin>>t;
	while(t--){
		memset(b,false,sizeof(b));
		int cnt=0;
		cin>>n>>m>>k;
		cin>>st>>sa>>d;
		b[st][sa]=true;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=k;i++){
			if(d==0){
				if(a[st][sa+1]=='x' || sa+1>m){
					d=(d+1)%4;
				}
				else{
					b[st][sa+1]=true;
					sa++;
				}
			}
			else if(d==1){
				if(a[st+1][sa]=='x' || st+1>n){
					d=(d+1)%4;
				}
				else{
					b[st+1][sa]=true;
					st++;
				}
			}
			else if(d==2){
				if(a[st][sa-1]=='x' || sa-1<1){
					d=(d+1)%4;
				}
				else{
					b[st][sa-1]=true;
					sa--;
				}
			}
			else{
				if(a[st-1][sa]=='x' || st-1<1){
					d=(d+1)%4;
				}
				else{
					b[st-1][sa]=true;
					st--;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(b[i][j]) cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
