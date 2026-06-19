#include<bits/stdc++.h>
using namespace std;
struct seat{
	int val,index;
};
seat s[110];
bool cmp(seat a,seat b){
	return a.val>b.val;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int sum=n*m;
	for(int i=1;i<=sum;i++){
		cin>>s[i].val;
		s[i].index=i;
	}
	sort(s+1,s+sum+1,cmp);
	int x=1,y=1;
	for(int i=1;i<=sum;i++){
		if(s[i].index==1){
			cout<<x<<" "<<y<<endl;
			break;
		}
		if(x%2==0){
			if(y==1){
				x++;
			}
			else{
				y--;
			}
		}
		else{
			if(y==n){
				x++;
			}
			else{
				y++;
			}
		}
	}
	return 0;
}
