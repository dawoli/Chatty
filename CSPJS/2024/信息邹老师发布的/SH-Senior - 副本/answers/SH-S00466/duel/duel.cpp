#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,i,j,sum;
LL r[100005];
bool pd[100005],gj[100005];//是否生存，是否攻击过 
bool gongji(){
	for(LL i=1;i<=n;i++){
		if(pd[i]==true&&gj[i]==true)return false;
	}
	return true;
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;//卡牌个数 
	sum=n;
	for(LL i=1;i<=n;i++)cin>>r[i];//攻击力&防御力
	for(LL i=1;i<=n;i++)pd[i]=gj[i]=true;
	sort(r+1,r+n+1);
	//for(int i=1;i<=n;i++)cout<<r[i];
	while(!gongji()){
	for(LL i=1;i<=n-1;i++)
		for(LL j=i+1;j<=n;j++){
			if((r[j]>r[i])&&(pd[i]==true)&&(pd[j]==true)&&(gj[j]==true)){
				sum--;
				gj[j]=false;
				pd[i]=false;
				gj[i]=false;/*cout<<i<<j*/
				
				break;//攻击力小于等于防御力，无事发生，否则，防御打破，退出游戏。 
			}
			else continue; 
		}
	for(LL i=1;i<=n-1;i++)
		for(LL j=i+1;j<=n;j++)
		if((r[j]==r[i])&&(pd[i]==true)&&(pd[j]==true)&&(gj[j]==true)){
			gj[j]=false;gj[i]=false;
		}
	}
	cout<<sum;
	return 0;
}
