#include <bits/stdc++.h>
using namespace std;
int n=0,m=0,arr=0;
priority_queue<int> q;
int seats[20][20];
bool check(int c,int i){
	if(c==1){
		return (i<=n);
	}
	else if(c==-1){
		return (i>=1);
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		
		int x=0;
		cin>>x;
		if(i==1){
			arr=x;
		}
		q.push(x);
	}
	int flag=1,s=1;
	for(int j=1;j<=m;j++){
		for(int i=s;check(flag,i);i+=flag){
			int x=q.top();q.pop();
			seats[i][j]=x;
		}
		if(flag==1){
			flag=-1;
			s=n;
		}
		else if(flag==-1){
			flag=1;
			s=1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(seats[i][j]==arr){
				cout<<j<<' '<<i;
			}
		}
	}
	
	
	return 0;
}
