#include<bits/stdc++.h>
using namespace std;
int score[105];
int n,m,num,pos,score_p;
int parel,line,count;
int ceiling(int x,int y){
	if(x%y==0)return x/y;
	else return x/y+1;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>score[i];
	}
	score_p=score[1];
	num=n*m;
	sort(score+1,score+1+num);
	for(int i=num;i>=1;i--){
		if(score[i]==score_p){
			pos=num-i+1;
			break;
		}
	}
	line=ceiling(pos,n);
	if(line%2==0){
		int r=pos%n;
		parel=n-r+1;	
	} 
	else{
		int r=pos%n;
		parel=r;
		if(r==0)parel=n;
		
	}
	cout<<line<<" "<<parel;
	return 0;
} 
