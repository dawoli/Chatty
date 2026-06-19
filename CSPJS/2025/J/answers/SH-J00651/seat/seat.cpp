#include<bits/stdc++.h>
using namespace std;
struct xy{
	int x,y;
}a[110];
int n,m,ans,score[108];
void sort0(){
	int x=1,y=1;
	for(int i=1;i<=n*m;i++){
		a[i].x=x,a[i].y=y;
		if(x%2){
		    y++;
		    if(y>n) y=n,x++;
		}
		else{
		    y--;
		    if(y<1) y=1,x++;
		}
	}
}
bool cmp(int x,int y){return x>y;}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>score[i];
	sort0();
	ans=score[1];
	sort(score+1,score+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(score[i]==ans){
		    cout<<a[i].x<<" "<<a[i].y;
		    return 0;
		}
	}
}
