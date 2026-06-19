#include <bits/stdc++.h>
using namespace std;

int n,m;
struct node{
	int sc,in;
}a[105];

bool cmp(node x,node y){
	return x.sc>y.sc;
}

int main(){
	freopen("seat.in","r",stdin); 
	freopen("seat.out","w",stdout); 
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i].sc;
		a[i].in=i;
	}
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;i++)
		if(a[i].in==0){
			cout<<i/n+1<<" ";
			if((i/n+1)%2==1)
				cout<<i%n+1<<endl;
			else
				cout<<n-i%n<<endl;
		}
	return 0;
}
