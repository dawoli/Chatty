#include <bits/stdc++.h>
using namespace std;
int T,n,t1,t2,t3,ans;
vector<int> num;
struct node{
	int x,y,z,c;
}a[100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while (T--){
		cin>>n;
		t1=0,t2=0,t3=0,ans=0;
		num.clear();
		for (int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if (a[i].x>a[i].y and a[i].x>a[i].z){
				t1++;
				a[i].c=1;
				ans+=a[i].x;
			}else{
				if (a[i].y>=a[i].x and a[i].y>=a[i].z){
					t2++;
					a[i].c=2;
					ans+=a[i].y;
				}else{
					t3++;
					a[i].c=3;
					ans+=a[i].z;
				}
			}
			
		}
		if (t1<=n/2 and t2<=n/2 and t3<=n/2){
			cout<<ans<<endl;
			continue;
		}
		if (t1>n/2){
			for (int i=1;i<=n;i++){
				if (a[i].c==1){
					num.push_back(a[i].x-max(a[i].y,a[i].z));
				}
			}
			sort(num.begin(),num.end());
			for (int i=0;i<t1-n/2;i++){
				ans-=num[i];
			}
			cout<<ans<<endl;
		}
		if (t2>n/2){
			for (int i=1;i<=n;i++){
				if (a[i].c==2){
					num.push_back(a[i].y-max(a[i].x,a[i].z));
				}
			}
			sort(num.begin(),num.end());
			for (int i=0;i<t2-n/2;i++){
				ans-=num[i];
			}
			cout<<ans<<endl;
		}
		if (t3>n/2){
			for (int i=1;i<=n;i++){
				if (a[i].c==3){
					num.push_back(a[i].z-max(a[i].x,a[i].y));
				}
			}
			sort(num.begin(),num.end());
			for (int i=0;i<t3-n/2;i++){
				ans-=num[i];
			}
			cout<<ans<<endl;
		}
	}
	return 0; 
}
