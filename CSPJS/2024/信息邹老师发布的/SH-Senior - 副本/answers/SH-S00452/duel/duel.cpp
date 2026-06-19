#include <bits/stdc++.h>
using namespace std;
struct node{
	int mem,atk;
	bool f=1;
};
bool cmp(node x,node y){
	if(y.mem==0 && x.mem>0)
		return x.mem>y.mem;
	if(y.mem>0 && x.mem>0)
		return x.atk<y.atk;
}
node num[100100];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin>>n;
	int l[n+1];
	int ans=0;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		num[x].mem++;
		num[x].atk=x;
	}
	sort(num,num+100000,cmp);
	int mt=0;
	for(int i=0;i<n;i++){
		if(num[i].mem!=0)
			mt++;
		else break;
	}
	for(int j=0;j<mt;j++){
		if(num[1].mem==0)
			break;
		for(int i=0;i<mt;i++){
			if(num[i].mem==0)
				break;
			if(num[i].mem<num[i+1].mem){
				ans+=num[i].mem;
				num[i].mem=0;
			}
			else if(num[i].mem>=num[i+1].mem && num[i+1].f==1){
				ans+=num[i+1].mem;
				num[i].mem-=num[i+1].mem;
				num[i+1].f=0;
			}	
		}
		sort(num,num+mt,cmp);
	}
	cout<<n-ans;
	
}
