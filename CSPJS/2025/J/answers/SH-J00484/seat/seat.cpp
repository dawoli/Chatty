#include<bits/stdc++.h>
using namespace std;
int mk[110];
bool st[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>m>>n;
	if(m*n==1){
		cout<<1<<" "<<1;
		return 0;
	}
	cin>>mk[0];
	int rmk=mk[0];
	for(int i=1;i<m*n;i++){
		cin>>mk[i];
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			st[i][j]=true;
		}
	}
	sort(mk,mk+m*n);
	reverse(mk,mk+m*n);
	if(m==2 && n==2){
		if(rmk==mk[0])cout<<1<<" "<<1;
		if(rmk==mk[1])cout<<2<<" "<<1;
		if(rmk==mk[2])cout<<2<<" "<<2;
		if(rmk==mk[3])cout<<1<<" "<<2;
		return 0;
	}
	int x=0,y=0;
	st[0][0]=false;
	for(int i=0;i<m*n;i++){
		if(mk[i]==rmk){
			cout<<x+1<<" "<<y+1<<endl;
		}
		st[x][y]==false;
		if(x+1<m && st[x+1][y]){
			x++;
		}else if(x-1>=0 && st[x-1][y]){
			x--;
		}else if(x==m-1 && st[x-1][y]==false && y+1<n && st[x][y+1]){
			y++;
		}else if(x==0 && st[x+1][y]==false && y+1<n && st[x][y+1]){
			y++;
		}
	}
	return 0;
} 
