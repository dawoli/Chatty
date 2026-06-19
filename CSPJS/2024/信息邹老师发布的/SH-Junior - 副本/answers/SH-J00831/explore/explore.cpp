#include<bits/stdc++.h>
using namespace std;
int step(){
	char s[1009][1009];
	bool ok[1009][1009];
	int cnt;
	int n,m,k;
	int x,y,d;
	cin>>n>>m>>k>>x>>y>>d;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;i++){
			cin>>s[i][j];
		}
	}
	for(int i=0;i<k;i++){
		if(d==0){
			if(s[x][y+1]!='x' and y+1<=n)
				if(!ok[x][y+=1]){
					cnt++;
					ok[x][y]=true;}
			else d=(d+1)%4;
		}
		else if(d==1){
			if(s[x+1][y]!='x' and x+1<=m)
				if(!ok[x+=1][y]){
					cnt++;
					ok[x][y]=true;}
			else d=(d+1)%4;
		}
		else if(d==2){
			if(s[x][y-1]!='x' and y-1>=1)
				if(ok[x+=1][y]){
					cnt++;
					ok[x][y]=true;}
			else d=(d+1)%4;
		}
		else if(d==3){
			if(s[x-1][y]!='x' and x-1>=1)
				if(ok[x][y+=1]){
					cnt++;
					ok[x][y]=true;}
			else d=(d+1)%4;
		}
	}
	return cnt;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout); 
	int cnt[9]={};
	int T;
	cin>>T;
	for(int i=0;i<T;i++){
		cnt[i]=step();
	}
	for(int i=0;i<T;i++){
		cout<<cnt[i]<<endl;
	}
	return 0;
}
