#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a,b;
	cin>>a>>b;
	int l[a*b];
	int R;
	for(int i=0;i<a*b;i++){
		cin>>l[i];
	}
	R=l[0];
	int r;
	sort(l,l+a*b);
	/*
	for(int i=0;i<a*b;i++){
		cout<<l[i]<<" ";	
	}
	cout<<endl;
	*/
	for(int i=1;i<=a*b;i++){
		if(R==l[i-1]){
			r=a*b-i+1;
			break;
		}
	}
	//cout<<R<<" "<<r<<endl;	
	int m,n;
	n=r%a;
	
	if(n==0){
		//cout<<"#\n";
		n=a;
	}
	
	m=(r-1)/a+1;
	
	//cout<<m<<" "<<n<<"\n";
	
	if(m%2==0){
		//cout<<"@\n";
		n=a-n+1;
	}
	
	cout<<m<<" "<<n;
	return 0;
}
/*
4 5
13 2 5 9 12 15 4 7 11 10 18 3 6 16 14 19 20 17 18 1
*/

/*
3 3
94 95 96 97 98 99 100 93 92
*/
