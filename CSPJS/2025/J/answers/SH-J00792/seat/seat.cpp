#include<bits/stdc++.h>
using namespace std;
const int N=114;
int n,m,z;
int a[N];

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int q=n*m;
	for(int i=1;i<=q;i++){
		cin>>a[i];
	}
	int t=a[1];
	sort(a+1,a+q+1,cmp);
	
	for(int i=1;i<=q;i++){
		if(a[i]==t){
			z=i;
			break;
		}
	}
	if(n<=1){
		cout<<1<<" "<<z;
		return 0;
	}
	else{
		int x=z%n;
		int y=z/n;
		if(y%2==0){
			if(x==0){
				cout<<y<<" "<<1;
				return 0;
			}
			else{
				cout<<y+1<<" "<<x;
				return 0;
			}
		}
		else{
			if(x==0){
				cout<<y<<" "<<m;
				return 0;
			}
			else{
				cout<<y+1<<" "<<n-x+1;
				return 0;
			}
		} 
	}
	return 0;
} 
