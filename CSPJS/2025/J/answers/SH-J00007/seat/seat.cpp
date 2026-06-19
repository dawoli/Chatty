#include<bits/stdc++.h>
using namespace std;
struct P{
	int v,i;
}a[10005];
int n,m,c=0,r=0;
bool cmp(P x,P y){
	return x.v>y.v;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].v;
		if(i==1) a[1].i=1;
		else a[i].i=0;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(c%2==1){
			if(r+1<=n) r++;
			else{
				r=n;c++;
			}
		} else{
			if(r-1>=1) r--;
			else{
				r=1;c++;
			}
		}
		//cout<<c<<r<<endl;
		if(a[i].i==1){
			cout<<c<<" "<<r<<endl;
			break;
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
} 

