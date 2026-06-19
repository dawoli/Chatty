#include<bits/stdc++.h>
using namespace std;
const int N=109;
int r,c,a[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>r>>c;
	for(int i=1;i<=r*c;i++){
		cin>>a[i];
	}
	int cur=a[1];
	sort(a+1,a+1+r*c);
	int ptr=lower_bound(a+1,a+1+r*c,cur)-a;
	ptr=r*c+1-ptr;
	int curi=1,curj=1,addv=1;
	for(int i=1;i<ptr;i++,curi+=addv){
		if(curi==r&&addv==1||curi==1&&addv==-1){
			curj++;
			i++;
			addv*=-1;
			if(i==ptr)break;
		}
	}
	cout<<curj<<" "<<curi;
	return 0;
}

