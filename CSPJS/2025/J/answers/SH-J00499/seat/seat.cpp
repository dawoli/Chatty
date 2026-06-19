#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int f=n*m;
	int r,ansx,ansy;
	vector<int> seats(n*m);
	vector<vector<int> > pos(n,vector<int>(m));
	for(int i=0;i<f;i++){
		cin>>seats[i];
		if(i==0){
			r=seats[i];
		}
	}
	sort(seats.begin(),seats.end(),greater<int>());
	int x=0,y=0,p=1;;
	for(int i=0;i<f;i++){
		if(x>n-1){
			x--;y++;p=-1;
		}
		if(x<0){
			x++;y++;p=1;
		}
		if(seats[i]==r){
			ansx=x+1;ansy=y+1;
			break;
		}
		pos[x][y]=seats[i];
		x+=p;
	}
	cout<<ansy<<" "<<ansx<<endl;
	return 0;
}
