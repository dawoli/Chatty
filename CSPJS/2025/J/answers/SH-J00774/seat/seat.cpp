#include<bits/stdc++.h>
using namespace std;
const int N=109;
int n,m,a[N];
int pos;
bool cmp(const int&x,const int&y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int tmp=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i]==tmp){
			pos=i;
			break;
		}
	int c=pos/n;
	if(pos%n==0){
		cout<<c<<" ";
		if(c%2==1) cout<<n<<endl;
		else cout<<1<<endl;
	}
	else{
		c+=1;
		cout<<c<<" ";
		int cnt=pos%n;
		if(c%2==1) cout<<cnt<<endl;
		else cout<<n-cnt+1<<endl;
	}
	return 0;
}

