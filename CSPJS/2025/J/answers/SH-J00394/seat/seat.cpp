#include <bits/stdc++.h> 
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int a[15][15],b[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	int ans=b[1];
	sort(b+1,b+1+n*m,cmp);
	//for(int i=1;i<=n*m;i++)
		//cout<<b[i]<<' ';
	//cout<<endl;
	int s=1;
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				a[i][j]=b[s];
				//cout<<i<<' '<<j<<' '<<b[s]<<endl;
				s++;
			}	
		}if(i%2==0){
			for(int j=m;j>=1;j--){
				a[i][j]=b[s];
				//cout<<i<<' '<<j<<' '<<b[s]<<endl;
				s++;
			}	
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==ans){
				cout<<i<<' '<<j;
				break;
			}
		}
	}	
	fclose(stdin);
	fclose(stdout);
}
