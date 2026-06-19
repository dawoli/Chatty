#include<bits/stdc++.h>
using namespace std;
struct seat{
	int num;bool R;
}s[19][19],a[109];
bool cmp(seat &x,seat &y){
	return x.num>y.num;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i].num;
	a[1].R=true;
	sort(a+1,a+1+n*m,cmp);
	int j=1,i=1,cnt=1;
	while(j<=m){
		if(j%2==1){
			for(;i<=n;i++,cnt++){
				s[i][j].num=a[cnt].num;
				if(a[cnt].R)s[i][j].R=true;
			}
			j++;i--;
		}else{
			for(;i>=1;i--,cnt++){
				s[i][j]=a[cnt];
				if(a[cnt].R)s[i][j].R=true;
			}
			j++;i++;
		}
	}
	for(int x=1;x<=n;x++)
		for(int y=1;y<=m;y++)
			if(s[x][y].R)cout<<y<<" "<<x;
	return 0;
} 
