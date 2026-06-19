#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e3+2;
ll T,n,m,k,x,y,d,ans=0;
bool fi[N][N];
bool vst[N][N];
bool check1(string s){
	for(int i=0;i<s.size();i++){
		if(s[i]=='x') return 0;
	}
	return 1;
}
void solve1(){
	for(int i=1;i<=k;i++){
		if(!vst[x][y]) ans++;
		vst[x][y] = 1;
		if(d==0){
			if(x>=1&&x<=n&&y+1>=1&&y+1<=m){
				y++;
			}
			else{
				d = (d+1)%4;
			}
		}
		else if(d==1){
			if(x+1>=1&&x+1<=n&&y>=1&&y<=m){
				x++;
			}
			else{
				d = (d+1)%4;
			}
		}
		else if(d==2){
			if(x>=1&&x<=n&&y-1>=1&&y-1<=m){
				y--;
			}
			else{
				d = (d+1)%4;
			}
		}
		else if(d==3){
			if(x-1>=1&&x-1<=n&&y>=1&&y<=m){
				x--;
			}
			else{
				d = (d+1)%4;
			}
		}
	}
	if(!vst[x][y]) ans++;
	vst[x][y] = 1;
	cout << ans << endl;
}
void dfs(){
	if(!vst[x][y]) ans++;
	vst[x][y] = 1;
	if(d==0){
		if(x>=1&&x<=n&&y+1>=1&&y+1<=m&&(!fi[x][y+1])){
			y++;
		}
		else{
			d = (d+1)%4;
		}
	}
	else if(d==1){
		if(x+1>=1&&x+1<=n&&y>=1&&y<=m&&(!fi[x+1][y])){
			x++;
		}
		else{
			d = (d+1)%4;
		}
	}
	else if(d==2){
		if(x>=1&&x<=n&&y-1>=1&&y-1<=m&&(!fi[x][y-1])){
			y--;
		}
		else{
			d = (d+1)%4;
		}
	}
	else if(d==3){
		if(x-1>=1&&x-1<=n&&y>=1&&y<=m&&(!fi[x-1][y])){
			x--;
		}
		else{
			d = (d+1)%4;
		}
	}
}
void solve2(string s){
	bool f = 0;
	if(d==0){
		if(x>=1&&x<=n&&y+1>=1&&y+1<=m&&(!fi[x][y+1])){
			f = 1;
			y++;
		}
	}
	else if(d==1){
		if(x+1>=1&&x+1<=n&&y>=1&&y<=m&&(!fi[x+1][y])){
			f = 1;
			x++;
		}
	}
	else if(d==2){
		if(x>=1&&x<=n&&y-1>=1&&y-1<=m&&(!fi[x][y-1])){
			f = 1;
			y--;
		}		
	}
	else if(d==3){
		if((x-1>=1&&x-1<=n&&y>=1&&y<=m&&(!fi[x-1][y]))){
			f = 1;
			x--;
		}
	}
	if(f){
		cout << 2 << endl;
	}
	else{
		cout << 1 << endl;
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin >> T;
	for(int i=1;i<=T;i++){
		string s;
		ans = 0;
		cin >> n >> m >> k;
		cin >> x >> y >> d;
		for(int i=1;i<=n;i++){
			cin >> s;
			for(int j=0;j<m;j++){
				if(s[j]=='x') fi[i][j+1] = 1;
				else fi[i][j+1] = 0;
			}
		}
		for(int j=1;j<=n;j++){
			for(int l=1;l<=m;l++){
				vst[j][l] = 0;
			}
		}
		if(check1(s)){
			solve1();
		}
		else if(k==1){
			solve2(s);
		}
		else{
			for(int i=1;i<=k;i++){
				dfs();			
			}
			if(!vst[x][y]) ans++;
			cout << ans << endl;
		}
	}
	return 0;
} 
