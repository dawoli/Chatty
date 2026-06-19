#include <bits/stdc++.h>
using namespace std;
int r[100010],n;
int bucket[100010];
queue<int>nmb,amo,rest;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&r[i]);
		bucket[r[i]]++;
	}
	for(int i=100000;i>=1;i--){
		if(bucket[i])nmb.push(i),amo.push(bucket[i]),rest.push(0);
	}
	int ans=n;
	while(1){
//		cout<<endl<<endl;
		int t=amo.size();
//		cout<<t<<"********\n";
		if(t==0)break;
		int mb1=nmb.front(),mo1=amo.front(),rst1=rest.front();
//		cout<<mb1<<" "<<mo1<<" "<<rst1<<endl;
		nmb.pop(),amo.pop(),rest.pop();
		t--;
		bool flag=1;
		while(t>=0){
			int mb2=nmb.front(),mo2=amo.front(),rst2=rest.front();
//			cout<<mb2<<" "<<mo2<<" "<<rst2<<endl;
			nmb.pop(),amo.pop(),rest.pop();
			t--;
			bool bf=1;
			while(t>=0&&mo2<=mo1-rst1){
//				cout<<"ts2\n";
				flag=0;
				rst1+=mo2,ans-=mo2;
				if(t>=1){
					t--;
					mb2=nmb.front(),mo2=amo.front(),rst2=rest.front();
//					cout<<mb2<<" "<<mo2<<" "<<rst2<<endl;
					nmb.pop(),amo.pop(),rest.pop();
				}
				else{
					bf=0;
					break;
				}
			}
			if(t>=0&&mo1!=rst1){
//				cout<<t<<"kkk\n";
				flag=0;
				ans-=(mo1-rst1),mo2-=(mo1-rst1),rst2=max(rst2-(mo1-rst1),0),rst1=mo1;
				nmb.push(mb1),amo.push(mo1),rest.push(rst1);
				mb1=mb2,mo1=mo2,rst1=rst2;
			}
			else {
//				cout<<t<<"ts";
				if(mo1!=rst1||t<0)break;
				mb1=mb2,mo1=mo2,rst1=rst2;
				t--;
			}
		}
		if(flag)break;
	}
	cout<<ans;
	return 0;
}
