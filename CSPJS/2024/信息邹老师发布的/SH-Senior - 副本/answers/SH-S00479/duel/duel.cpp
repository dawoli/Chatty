#include<bits/stdc++.h>
using namespace std;
int a[100005];
bool cmp(int x,int y){
	return x<=y;
}
struct stru{
	int l,ne;
}b[100005];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n,cnt11,cnt22;
	bool bo=true;
	cin>>n;
	int ans=n;
	for(int i = 1;i<= n;i++){
		cin>>a[i];
		if(bo){
			if(a[i]==1){
				cnt11++;
			}
			else if(a[i]==2){
				cnt22++;
			}
			else{
				bo=false;
			}
		}
	}
	if(bo){
		if(cnt22>cnt11){
			cout<<cnt22;
		}
		else{
			cout<<cnt11;
		}
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	b[n+1].l=0;
	a[n+1]=-1;
	for(int i=n;i>=1;i--){
		b[i].ne=i;
		if(a[i]==a[i+1]){
			b[i].l=b[i+1].l+1;
		}
		else{
			b[i].l=1;
		}
	}
	for(int i = 1;i<= n;i++){
		if(i+b[i].l<=n){
			if(b[i+b[i].l].ne<=n){
				ans--;
				b[i+b[i].l].ne++;
			}
			else{
				break;
			}
		}
		else{
			break;
		}
	}
	cout<<ans;
	return 0;
}
