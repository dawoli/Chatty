#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct edgee{ll id,zuixiaocha;};
bool cmp(edgee a,edgee b){return a.zuixiaocha<b.zuixiaocha;}
ll T;
ll n;
edgee arr[100005];
ll ans;
ll cnt[3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T>0){
		T--;
		cin>>n;
		int temp1,temp2,temp3;
		for(int i=0;i<n;i++){
			cin>>temp1>>temp2>>temp3;
			if(temp1>=temp2&&temp1>=temp3)arr[i].id=0,arr[i].zuixiaocha=temp1-max(temp2,temp3);
			else if(temp2>=temp1&&temp2>=temp3)arr[i].id=1,arr[i].zuixiaocha=temp2-max(temp1,temp3);
			else if(temp3>=temp2&&temp3>=temp1)arr[i].id=2,arr[i].zuixiaocha=temp3-max(temp2,temp1);
			ans=ans+max(max(temp1,temp2),temp3);
		}
		sort(arr+0,arr+n,cmp);
		for(int i=n-1;i>=0;i--){
			cnt[arr[i].id]++;
			if(cnt[arr[i].id]>n/2){
				cnt[arr[i].id]--;
			    ans=ans-arr[i].zuixiaocha;
			}
		}
		cout<<ans<<endl;
		ans=0;
		cnt[0]=0;
		cnt[1]=0;
		cnt[2]=0;
	}
	return 0;
}
