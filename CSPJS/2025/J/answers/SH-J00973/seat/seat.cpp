#include<bits/stdc++.h>
using namespace std;
int n,m,a[125],pl[15][15];
bool cmp(int f, int s){
	return f>s;
}
int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int tot=n*m;
	for (int i=1;i<=tot;i++){
		cin>>a[i];
	}
	int mark=a[1];
	sort(a+1,a+tot+1,cmp);
	for (int i=1;i<=tot;i++){
		if(a[i]!=mark)continue;
		int x,y;
		x=(i+n-1)/n;
		if(x%2){
			y=i%n;
			if(y==0){
				y=n;
			}
		}
		else{
			y=n+1-i%n;
		}
		cout<<x<<" "<<y;
	}
}
