#include<bits/stdc++.h>
using namespace std;
struct poke{
	char colo;
	char numb;
}a[1000];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].colo>>a[i].numb;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i;j++){
			if(a[i].colo==a[i+j].colo&&a[i].numb==a[i+j].numb){
				n--;
			}
		}
	}
	cout<<52-n<<endl;
	return 0;
}
