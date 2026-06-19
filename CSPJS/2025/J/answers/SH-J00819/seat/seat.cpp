#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){return x>y;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(NULL);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	int vv[105],nn;
	cin>>nn;vv[0]=nn;
	for(int i=1;i<n*m;i++)cin>>vv[i];
	sort(vv,vv+m*n,cmp);
	int seatss=0;
	while(1){if(vv[seatss]==nn)break;seatss++;}
	seatss+=1;
	int lie=(seatss-1)/n+1;
	int gggg=(seatss-1)%n+1;
	if(lie%2==1)cout<<gggg;
	else cout<<n-gggg+1;
	cout<<endl;
	return 0;
}
