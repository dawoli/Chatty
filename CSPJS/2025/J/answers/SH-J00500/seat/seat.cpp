#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(pair<int,bool> a,pair<int,bool> b){
	return a.first>b.first;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	pair<int,bool> sc[n*m];
	for(int i=0;i<n*m;i++){
		cin>>sc[i].first;
		if(i==0)sc[i].second=true;
		else sc[i].second=false;
	}
	sort(sc,sc+n*m,cmp);
	int i=1,j=1,cnt=0;
	bool dir=true;
	while(!sc[cnt].second){
		i+=dir?1:-1;
		if(i>n){
			j++;
			i--;
			dir=!dir; 
		}
		if(i<=0){
			j++;
			i++;
			dir=!dir;
		}
		cnt++;
	}
	cout<<j<<' '<<i;
	return 0;
}

