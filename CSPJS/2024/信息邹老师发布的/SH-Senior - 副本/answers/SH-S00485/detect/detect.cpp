#include<bits/stdc++.h>
using namespace std;
int t;
struct information{
	int n;
	int m;
	int l;
	int v;
}in[22];
struct car{
	int v1;
	int ac;
	int d;
	bool status;
}c[21][100003];
struct detector{
	int place;
	int u;
	bool status=false;
}de[21][100003];
struct ans{
	int illegal=0;
	int num=0;
}k[22];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>in[i].n>>in[i].m>>in[i].l>>in[i].v;
		for(int j=1;j<=in[i].n;j++){
			cin>>c[i][j].d>>c[i][j].v1>>c[i][j].ac;
			c[i][j].status=true;
		}
		for(int x=1;x<=in[i].m;x++){
			cin>>de[i][x].place;
		}
	}
	for(int i=1;i<=t;i++){
		for(int j=1;j<=in[i].n;j++){
			 de[i][j].u=1;
			bool flag=false;
			double start;
			double end;
			if(c[i][j].ac==0){
				if(c[i][j].v1>in[i].v){
			        start=c[i][j].d;
			        end=in[i].l;
				}
				else{
					flag=true;
				}
			}
			else if(c[i][j].ac<0){
				if(c[i][j].v1<in[i].v){
					flag=true;
				}
				else{
				end=((in[i].v*in[i].v*1.0-c[i][j].v1*c[i][j].v1*1.0)/(2*c[i][j].ac));
				start=c[i][j].d;	
				}
			}
			else if(c[i][j].ac>0){
				if(c[i][j].v1>in[i].v){
					start=c[i][j].d;
					end=in[i].l;
				}
				else{
					start=(c[i][j].v1*c[i][j].v1*1.0)/(2*c[i][j].ac*1.0);
					end=in[i].l;
				}
			}
				c[i][j].status=true;
			if(flag==false){
				for(int x=1;x<=in[i].m;x++){
					if(start<=de[i][x].place&&de[i][x].place<=end){
						k[i].illegal++;
					}
				}
			}
		}
		}
	for(int i=1;i<=t;i++){
		cout<<k[i].illegal<<" "<<k[i].num<<endl;
	}
	return 0;
	
}
