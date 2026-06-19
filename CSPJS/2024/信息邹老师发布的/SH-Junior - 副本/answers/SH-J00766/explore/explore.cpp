#include <bits/stdc++.h>
using namespace std;
struct student{
	bool tf;
	char s;
};
int cal(int n,int m,int k,int x,int y,int d){
	int ans=1;
	student ma[1001][1001];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>ma[i][j].s;
			ma[i][j].tf=true; 
//			cout<<ma[i][j].s;
		}
	}
	ma[x][y].tf=false;
	int kk=1;
	while(kk<=k){
		if(d%4==0){
			if(ma[x][y+1].s=='x'||y+1>m){
				d++;
				kk++;
			}
			else if(ma[x][y+1].s=='.'){
				y++;
				kk++;
				if(ma[x][y].tf==true){
					ans++;
//					cout<<"x---"<<x<<' '<<"y---"<<y<<endl;
				}
				ma[x][y].tf=false;
			}
		}
		else if(d%4==1){
			if(ma[x+1][y].s=='x'||x+1>n){
				d++;
				kk++;
			}
			else if(ma[x+1][y].s=='.'){
				x++;
				kk++;
				if(ma[x][y].tf==true){
					ans++;
//					cout<<"x---"<<x<<' '<<"y---"<<y<<endl;
				}
				ma[x][y].tf=false;
			}
		}
		else if(d%4==2){
			if(ma[x][y-1].s=='x'||y-1<=1){
				d++;
				kk++;
			}
			else if(ma[x][y-1].s=='.'){
				y--;
				kk++;
				if(ma[x][y].tf==true){
					ans++;
//					cout<<"x---"<<x<<' '<<"y---"<<y<<endl;
				}
				ma[x][y].tf=false;
			}
		}
		else if(d%4==3){
			if(ma[x-1][y].s=='x'||x-1<=1){
				d++;
				kk++;
			}
			else if(ma[x-1][y].s=='.'){
				x--;
				kk++;
				if(ma[x][y].tf==true){
					ans++;
//					cout<<"x---"<<x<<' '<<"y---"<<y<<endl;
				}
				ma[x][y].tf=false;
			}
		}
	}
	return ans;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T=0;
	cin>>T;
	for(int i=0;i<T;i++){
		int n=0,m=0,k=0,x=0,y=0,d=0;
		cin>>n>>m>>k>>x>>y>>d;
		cout<<cal(n,m,k,x,y,d)<<endl;	
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
