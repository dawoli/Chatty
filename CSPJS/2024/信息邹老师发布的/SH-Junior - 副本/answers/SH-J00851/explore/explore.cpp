#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int n,m,k,x,y,d;
bool world[1000+9][1000+9];
bool vst[1000+9][1000+9];
int ans=1;
void input(){
    cin>>n>>m>>k>>x>>y>>d;
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=m;j++){
    		char ch;
    		cin>>ch;
    		world[i][j]=(ch=='.');
		}
	}
	vst[x][y]=1;
}
void solve(){
    for(int i=0;i<k;i++){
    	int _x,_y;
    	if(d==0) {_x=x;_y=y+1;}
    	else if(d==1) {_x=x+1;_y=y;}
    	else if(d==2) {_x=x;_y=y-1;}
    	else {_x=x-1;_y=y;}
    	if(1<=_x&&_x<=n&&1<=_y&&_y<=m&&world[_x][_y]){
    		x=_x;y=_y;
    		if(!vst[x][y]){
    			vst[x][y]=1;
    			ans++;
//    			cout<<"ans++";
    	    }
		}
		else{
			int _d=(d+1)%4;
			d=_d;
		}
//		printf("x==%i,y==%i\n",x,y);
	}
	cout<<ans<<endl;
}
bool match1(){
	return 0;
}
void solve1(){
	solve();
}
bool match2(){
	return 0;
}
void solve2(){
	solve();
}
bool match3(){
	return 0;
}
void solve3(){
	solve();
}
void clear(){
	ans=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			vst[i][j]=0;
		}
	}
}
int T;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	for(int t=0;t<T;t++){
		input();
	    if(match1()) solve1();
	    else if(match2()) solve2();
	    else if(match3()) solve3();
	    else solve();
	    clear();
	}
}

