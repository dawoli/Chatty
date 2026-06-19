#include<bits/stdc++.h>
using namespace std;
queue<int> qu;
int fen[111];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r");
	freopen("seat.out","w");
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>fen[i];
	}
	int a=fen[1];
	sort(fen+1,fen+(n*m)+1,cmp);
	for(int i=1;i<=n*m;i++){
		qu.push(fen[i]);
	}
	for(int i=1;i<=m;i++){
		if(i%2){
			for(int j=1;j<=n;j++){
				if(qu.front()==a){
					cout<<i<<' '<<j;
					return 0;
				}
				qu.pop();
			}
		}else{
			for(int j=n;j>=1;j--){
				if(qu.front()==a){
					cout<<i<<' '<<j;
					return 0;
				}
				qu.pop();
			}
		}
	}
	return 0;
}
