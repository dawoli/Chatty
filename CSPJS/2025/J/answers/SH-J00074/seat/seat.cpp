#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int ttl = n*m;
	int score;
	cin>>score;
	int place=0;
	for (int i=0; i<ttl-1; i++){
		int tmp;
		cin>>tmp;
		if (tmp>score){
			place++;
		}
		//cout<<tmp<<endl;
	}
	//cout<<score<<endl;
	int x,y;
	if (place/n%2==0){
		x = place/n+1;
		y = place%n+1;
	}else{
		x = place/n+1;
		y = n-place%n;
	}
	cout<<x<<" "<<y<<endl;
	return 0;
}
