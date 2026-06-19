#include<bits/stdc++.h>
using namespace std;
char a[100][100];

void pro(){
	long n,m,k,x,y,d,ans=1;
	cin>>n>>m>>k>>x>>y>>d;
	for(int i=m-1;i>=0;i--){
		for(int j=n-1;j>=0;j--){
		    cin>>a[i][j];
	    }
	}
	x--;
	y--;
	a[x][y]=='L';
	for (int i=0;i<k;i++){
		int nx=x,ny=y;
		if(d==0){
			ny++;
		}
		if(d==1){
			nx++;
		}
		if(d==2){
			ny--;
		}
		if(d==3){
			nx--;
		}
		//cout<<a[ny][nx]<<nx<<ny<<" ";
		if(0<=nx&&0<=ny&&nx<n&&ny<m&&!(a[ny][nx]=='x')){
			x=nx;y=ny;
			//cout<<a[ny][nx]<<x<<y<<"$ ";
			if(a[ny][nx]=='.'){
			    a[ny][nx]='L';
			    ans++;
			}
//			}else{
//				cout<<2;
//			}
		}else{
			//
			d=(d+1)%4;
		}
	}
	cout<<ans<<endl;
}
int main(){
	cin.tie(0);
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
	pro();
	}
return 0;}
