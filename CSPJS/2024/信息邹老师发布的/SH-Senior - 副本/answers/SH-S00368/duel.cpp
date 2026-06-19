#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e6+10;
int n;
int a[N];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	int ans=n;
	for(int i = 1;i <= n;i ++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++){
		for(int j=i;j>=1;j--){
			if(a[i]>a[j]){
				ans--;
				a[j]=N;
			break;
			}
		}
	}
	cout <<ans;
	return 0;
}
