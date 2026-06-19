#include<bits/stdc++.h>
using namespace std;
long long _T,m,n,x,y,k,_x,_y,d;
string s[2000]={""};
long long leng=0;
bool ans[2000][2000]={true};
int _count=0;
bool isEmpty(int x,int y){
	if(!(x>=1&&x<=n&&y>=1&&y<=m))return false;
	if(s[x][y]=='.')return true;
	
	return false;
}
void turnRight(){
	d=(d+1)%4;
}
void addAsw(int x,int y){
	if(ans[x][y]){
		_count++;
		ans[x][y]=false;
	}
}




int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>_T;
	while(_T){
		_T--;
		cin>>n>>m>>k;
		cin>>_x>>_y>>d;
	    addAsw(_x,_y);
		for(int i=0;i<n;i++){
			cin>>s[i];
		}
		
		for(int i=k;i>0;k--){
		
		    if(d==0){
			    if(isEmpty(_x,_y+1)){
			    	_y+=1;
			    	addAsw(_x,_y);
			    }else{
			    	turnRight();
				}
		    }
		    if(d==1){
			    if(isEmpty(_x+1,_y)){
			    	_x+=1;
			    	addAsw(_x,_y);
			    }else{
			    	turnRight();
				}
		    }
		    if(d==2){
			    if(isEmpty(_x,_y-1)){
			    	_y+=-1;
			    	addAsw(_x,_y);
			    }else{
			    	turnRight();
				}
		    }
		    if(d==4){
			    if(isEmpty(_x-1,_y)){
			    	_x+=-1;
			    	addAsw(_x,_y);
			    }else{
			    	turnRight();
				}
		    }
	    }cout<<_count; _count=0;
	}
	
return 0;}
