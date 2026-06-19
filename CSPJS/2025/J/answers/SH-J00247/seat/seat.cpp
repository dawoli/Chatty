#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n,maxx,maxy,goal2,goal;
int a[500];
void sort_(){
	for(int i=0;i<n;i++){
		for(int j=i;j>0;j--){
			if(a[j]>a[j-1])swap(a[j-1],a[j]);
		}
	}
}
void find_(int x, int y, int time){
	if(time==goal2){
		cout<<x+1<<" "<<y+1;
		return;
	}
	else{
		if(x>0&&y==0&&x%2==1)find_(x+1,y,time+1);
		else{
			if(x%2==0&&y==maxy-1)find_(x+1,y,time+1);
			else{
				if(x==0||x%2==0)find_(x,y+1,time+1);
				else find_(x,y-1,time+1);
			}
		}
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>maxx>>maxy;
	n=maxx*maxy;
	for(int i=0;i<n;i++)cin>>a[i];
	goal=a[0];
	sort_();
	for(int i=0;i<n;i++)if(a[i]==goal)goal2=i;
	find_(0,0,0);
	return 0;
}
