#include<iostream>
#include<algorithm>
using namespace std;
#define N 100005
int n,r[N],ans,l;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>r[i];
	}
	sort(r+1,r+n+1);
	l=1;
	for(int i=1;i<=n;i++){
		if(l<i&&r[i]>r[l]){
			l++;
			ans++;
		}
	}
	cout<<n-ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
