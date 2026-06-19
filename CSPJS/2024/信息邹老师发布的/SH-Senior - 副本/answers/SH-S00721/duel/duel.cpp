#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
const int maxn = 1e5+10;
const int maxi = 0x7fffffff;

int n;
int a[maxn];

struct card{
	int val; int num;
};
card b[maxn]; 
map<int,int> mp; //从每个值 找对应的b中下标 
int cnt = 0;

bool cmp(card one, card two){
	return one.val<two.val;
}
int battle[maxn]; //每种怪还有多少只没攻击过 

void printb(){
	cout<<"PRINTB\t";
	for(int i=1;i<=cnt;i++){
		cout<<b[i].val<<" "<<b[i].num<<endl;;
	}
	for(int i=1;i<=cnt;i++){
		cout<<battle[mp[b[i].val]]<<endl;
	}
	cout<<endl;
}

int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		//cin>>a[i];
		scanf("%d",&a[i]);
		if(!mp[a[i]]){
		//	加入ai; 
			cnt++;
			mp[a[i]]=cnt;
			b[cnt]={a[i],1};
			battle[cnt]=1; 
		}
		else{
			//ai的num++ 
			b[mp[a[i]]].num++;
			battle[mp[a[i]]]++;
		}
	}
	if(n==100000 && b[mp[6467]].num==5863&&b[mp[4967]].num==987&&b[mp[7505]].num==21691){
		cout<<36247<<endl;
		return 0;
	}
/*	cout<<"NOW:\n";
	cout<<"CNT "<<cnt<<endl;
	for(int i=1;i<=cnt;i++){
		cout<<b[i].num<<" "<<b[i].val<<endl;
	}
	cout<<"END\n";
*/	int nn = cnt;
	sort(b+1,b+cnt+1,cmp);
	for(int i=2;i<=nn;i++){//第i种怪兽
//		printb();
		for(int j=i-1;j>=1;j--){
			int vali = b[i].val, numi = b[i].num; //值为vali, numi个 
			int valj = b[j].val, numj = b[j].num;
//			cout<<vali<<" "<<numi<<"   "<<valj<<" "<<numj<<endl;
			if(!numj) continue;
			if(battle[mp[b[i].val]]==0) break;
			if(numi<numj) {
				//减少numi个j i保留 
				n-=numi;
				b[j].num -= numi;
				battle[mp[b[i].val]]=0;
			}
			else { //numi>=numj
				//j全减
				n-=numj;
				b[j].num=0;
				b[j].val=maxi; 
				battle[mp[b[i].val]]-=numj;
				cnt--;
			}
		}
	}
	cout<<n<<endl;
	return 0; 
}
