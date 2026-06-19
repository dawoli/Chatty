#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
priority_queue<int> q; 
int x,y;
int sc;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int d;cin>>d;
			q.push(d);
			if(i==1&&j==1){
				sc=d;
			}
		}
	}
	x=y=1;
	q.pop();
	while(!q.empty()&&q.top()!=sc){
		q.pop();
		if(x%2==0){
			if(y==1){
				++x;
				y=1;
			}else{
				--y;
			}
		}else{
			if(y==n){
				++x;
				y=n;
			}else{
				++y;
			}
		}
	}
	if(x%2==0){
		if(y==1){
			++x;
			y=1;
		}else{
			--y;
		}
	}else{
		if(y==n){
			++x;
			y=n;
		}else{
			++y;
		}
	}
	cout<<x<<" "<<y;
	fclose(stdin);
	fclose(stdout);
}
