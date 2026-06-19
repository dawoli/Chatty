#include <bits/stdc++.h>
using namespace std;
string s;
int n,m;
struct note{
	int id,p;
}a[1005];
bool cmp(note x,note y){
	return x.p>y.p;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i].p;
		a[i].id=i;
	}
	sort(a,a+n*m,cmp);
	int xx=1,yy=1,cnt=0;
	if(a[0].id==0){
		cout<<"1 1"<<endl;
		return 0;
	}
	while(a[cnt].id!=0){
		if(yy%2==1){
			int xxx=xx+1;
			if(xxx<=n){
				xx=xxx;
			}
			else{
				yy++;
			}
			cnt++;
		}
		else{
			int xxx=xx-1;
			if(xxx>=1){
				xx=xxx;
			}
			else{
				yy++;
			}
			cnt++;
		}
	}
	cout<<yy<<' '<<xx<<endl;
	return 0;
} 
