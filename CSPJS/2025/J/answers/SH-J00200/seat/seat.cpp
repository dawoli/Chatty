#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> score(n*m);
	for(int i=0;i<n*m;i++) cin>>score.at(i);
	int ans=score.front();
	sort(score.begin(),score.end(),cmp);
	int c=1,r=1,d=1;
	while(1){
		if(score.front()==ans){
			cout<<c<<" "<<r;
			break;
		}
		if(d==1){
			if(r<n) r++;
			else{
				c++;
				d=0;
			}
		}else{
			if(r>1) r--;
			else{
				c++;
				d=1;
			}
		}
		score.erase(score.begin());
	}
	return 0;
}
