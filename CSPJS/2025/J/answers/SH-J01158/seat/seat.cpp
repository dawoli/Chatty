






#include <bits/stdc++.h>
using namespace std;
int a,aa,q=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int c,r;
	cin>>c>>r;
	cin>>aa;
	for(int i=1;i<=c*r-1;i++){
		cin>>a;
		if(a>aa){
			q++;

		}
	}
	int cnt=1;
	int cc=q%c;

	if(cc==0&&q>1){
		cnt=0;
		cc=c;
	}
	while(q>=c){

		q-=c;
		cnt++;
	}

	if(cnt%2){
		cout<<cnt<<" "<<cc;
	}else{
		cout<<cnt<<" "<<c-cc+1;
	}
	return 0;
}
