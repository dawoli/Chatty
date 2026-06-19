#include<bits/stdc++.h>
using namespace std;
#define N 100001
typedef long long LL;
LL n,a[N],cnt=0,lower=1;
bool vst[N];		//vst[i]=0正常 vst[i]=1已攻击过 

int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		for(int j=lower;j<i;j++){
			if(a[i]>a[j]&&!vst[i]){	//攻击者没有攻击过 
				vst[i]=true;
				lower++;
				cnt++;	//统计下场的怪兽 
				break;
			}
		}
	}
	cout<<n-cnt;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
10
136 136 136 2417 136 136 2417 136 136 136
*/
