#include<bits/stdc++.h>
using namespace std;
int n;
const int N=100005;
int a[N];
bool cmp(int a,int b){
	return a<b;
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	int ONE=0,TWO=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	int ans=n;
	int k=1;
	for(int i=1;i<=n;i++){
		if(a[i]>a[k]){
			ans--;
			k++;
		}
	}
	cout<<ans;
	return 0;
} 
