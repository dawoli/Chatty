#include<bits/stdc++.h>
using namespace std;
string a[1001];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int cot[5];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	int n,m,k,x,y,d,cnt;
	cin>>T;
	for(int i = 0;i<T;i++){
		int ab = 1;
		cnt = 0;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int j = 1;j<=n;j++){
			cin>>a[j];
		}
		for(int h = 0;h<k;h++){
			if(x+dx[d]<=n and x+dx[d]>0 and y+dy[d] <=m and y+dy[d] > 0 and a[x+dx[d]][y+dy[d]-1] == '.'){
				cnt += 1;
				x+=dx[d];
				y+=dy[d];
			}else{
				d = (d+1)%4;
				if(x==1 and y==1 and ab == 1){
					cnt += 1;
					ab = 0;
				};
			}
		}
		cot[i] = cnt;;
	}
	for(int i = 0;i<T;i++){
		cout<<cot[i]<<endl;
	}
	return 0;
}
