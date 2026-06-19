#include<bits/stdc++.h>
using namespace std;
int a[1005],mm,n;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>mm;
	int num=n*mm;
	for(int i=1;i<=num;i++){
		cin>>a[i];
	}
	int m=a[1],pos;
	sort(a+1,a+1+num);
	for(int i=num;i>=1;i--){
		if(a[i]==m)pos=num-i+1;
	}
	if(pos%n==0){
		cout<<pos/n<<" "<<mm;
		return 0;
	}
	int lie=pos/n;
	int now=pos-n*lie;
	if(lie%2==0){
		cout<<lie+1<<" "<<now;
	}
	else cout<<lie+1<<" "<<mm-now+1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
