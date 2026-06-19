#include<bits/stdc++.h>
using namespace std;
int n,m;
int score[199];
bool PPs(int x,int y){
	return x>y;
	
}
struct a{
	int x;
	int y;
};
int up(double r){
	int i=0;
	for(;i*n>r;i++){
		
	}
	return i*n;
}
a pd(int c){
	c++;
	int x=up(c);
	int y=c%n;
	if (x%2==0){
		y=n-y;
	}
	a s;
	s.x=x+1;
	s.y=y;
	return s;
	
}
int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>score[i];
	}
	int xm=score[0];
	
	sort(score+0,score+n*m,PPs);
	int pps;
	for(int i=0;i<n*m;i++){
		if(score[i]==xm){
			pps=i;
		}
	}
	a w=pd(pps);
	cout<<w.x<<" "<<w.y;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
