#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std; 
const int MAXN = 1e5+5;
int T;
int n;
struct Node{
	int max1,max2,cha,i1,i2;
}a[MAXN];
bool cmp(Node a,Node b){
	return a.cha>b.cha;
}
int op[3];
int cnt[10];
int sum;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cnt[1]=0;cnt[2]=0;cnt[3]=0;
		sum=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&op[1],&op[2],&op[3]);
			int i_1=1,i_2=1,max1=-1,max2=-1;
			//cout<<op[1]<<op[2]<<op[3]<<endl;
			for(int j=1;j<=3;j++){
				if(op[j]>max1){
					max1=op[j];
					i_1=j;
				}
			}
			for(int j=1;j<=3;j++){
				if(j!=i_1&&op[j]>max2){
					max2=op[j];
					i_2=j;
				}
			}
			a[i]={max1,max2,max1-max2,i_1,i_2};
			//cout<<max1<<max2<<i_1<<i_2<<endl;
		}
		sort(a+1,a+n+1,cmp);
		int cntmax=n/2;
		//cout<<cntmax<<endl;
		for(int i=1;i<=n;i++){
			if(cnt[a[i].i1]+1<=cntmax){
				sum+=a[i].max1;
				cnt[a[i].i1]++;
				//cout<<a[i].i1<<a[i].max1<<endl;
			}
			else{
				sum+=a[i].max2;
				cnt[a[i].i2]++;
				//cout<<a[i].i2<<' '<<a[i].max2<<endl;
			}
			//cout<<cnt[1]<<' '<<cnt[2]<<' '<<cnt[3]<<endl;
		}
		cout<<sum<<endl;
	} 
	return 0;
}
