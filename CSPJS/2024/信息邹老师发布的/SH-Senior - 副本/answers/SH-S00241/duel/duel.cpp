#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int n,a[100001],ans,j=1;

int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
	cin >> n;
	ans=n;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(a[j]<a[i]){
			ans--;
			j++;
		}
	}
	cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
