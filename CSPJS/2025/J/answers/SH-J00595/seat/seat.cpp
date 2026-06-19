#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[110],build[15][15];
int n,m;
bool cmp(int a,int b){
	return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
    	cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+n*m+1,cmp);
	int turn=1;
	int h=1,l=1;
	for(int i=1;i<=n*m;i++){
		build[h][l]=a[i];
		if(h+turn>n||h+turn<=0){
			turn*=-1;
			l++;
		}
		else{
			h+=turn;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			if(build[i][j]==r){
				cout<<j<<" "<<i<<endl;
				return 0;
			}
			
	}
    fclose(stdin);
    fclose(stdout);
	return 0;
}

