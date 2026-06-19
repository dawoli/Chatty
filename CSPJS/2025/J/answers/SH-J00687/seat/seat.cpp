#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
int seat[11][11];
struct Node{
	int id;
	int score;
}p[101];
bool cmp(Node x,Node y){
	return x.score>y.score;
}
int main(){
	freopen("seat.in","r",stdin); 
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>p[i].score;
		p[i].id=i;
	}
	sort(p+1,p+n*m+1,cmp);
	int pos=0;
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				pos++;
				if(p[pos].id==1){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}else{
			for(int j=m;j>=1;j--){
				pos++;
				if(p[pos].id==1){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
}
