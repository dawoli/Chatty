#include<iostream>
#include<algorithm>
using namespace std;

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
    int b[1000007];
    int cj;
    int ww= n*m;
    for(int i=1;i<=ww;i++){
    	cin >> b[i];
    	if(i==1){
    		cj=b[i];
		}
	}
	sort(b+1,b+ww+1,cmp);
	int zm=0;
	for(int i=1;i<=ww;i++){
		if(b[i]==cj){
			zm=i;
		}
	}
	int q,p;
	if(zm%n==0){
		q=zm/n;
		if(q%2!=0){
			p=n;
		}
		else{
			p=1;
		}
		cout << q << " " << p;
	}
	else{
		q=zm/n+1;
		if(q%2!=0){
			p=zm%n;
		}
		else{
			p=n-zm%n+1;
		}
		cout << q << " " << p;
	}
	return 0;
}
