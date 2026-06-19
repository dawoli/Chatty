#include<bits/stdc++.h>
using namespace std;
long h,w,d,x,y,face,all,ans[100];
long m(char map[100][100],int h,int w,int d,int x,int y,int face){
	if(d>=0){
		d-=1;
		if(face==0){
			if(y+1<w&&map[x][y+1]!='x'){
				return m(map,h,w,d,x,y+1,face)+1;
			}
			else
			{
				return m(map,h,w,d,x,y,face+1);
			}
		}
		if(face==1){
			if(x+1<h&&map[x+1][y]!='x'){
				return m(map,h,w,d,x+1,y,face)+1;
			}
			else{
				return m(map,h,w,d,x,y,face+1);
			}
		}
		if(face==2){
			if(y-1>=0&&map[x][y-1]!='x'){
				return m(map,h,w,d,x,y-1,face)+1;
			}
			else{
				return m(map,h,w,d,x,y,face+1);
			}
		}
		if(face==3){
			if(x-1>=0&&map[x-1][y]!='x'){
				return m(map,h,w,d,x-1,y,face)+1;
			}
			else{
				return m(map,h,w,d,x,y,face-3);
			}
		}
	}
	else return 0;
}
int main(){
	char map[100][100];
	cin>>all;
	for(int i=0;i<all;i++){
		cin>>h>>w>>d>>x>>y>>face;
		for(int j=0;j<h;j++){
			for(int k=0;k<w;k++){
				cin>>map[j][k];
			}
		}
		ans[i]=m(map,h,w,d,x-1,y-1,face);
	}
	for(int i=0;i<all;i++) cout<<ans[i]<<' ';
}
