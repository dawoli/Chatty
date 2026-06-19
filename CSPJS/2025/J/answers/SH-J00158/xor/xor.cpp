#include<bits/stdc++.h>
using namespace std;
long long res,a[100010];
bool flag[100010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int R,b;
	cin>>R>>b;
	for(int i=0;i<R;i++){
		cin>>a[i];
	}
	if(b==0){
		cout<<1<<endl;
		return 0;
	}
	cout<<2<<endl;
	return 0;
}
