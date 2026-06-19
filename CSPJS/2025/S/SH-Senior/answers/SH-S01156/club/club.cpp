#include<bits/stdc++.h>
using namespace std;
int w[100001];
struct node{
	int dep,val,val1,pos;
};
node a[100001][5];
node temp[100001];
int b[100001][5];
bool cmp(node x,node y){
	return x.val>y.val;
}
bool cmp1(node x,node y){
	if(x.val!=y.val) return x.val>y.val;
	else return x.val1<y.val1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,cnta=0,cntb=0,cntc=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1].val>>a[i][2].val>>a[i][3].val;
			a[i][1].dep=1,a[i][2].dep=2,a[i][3].dep=3;
			b[i][1]=a[i][1].val,b[i][2]=a[i][2].val,b[i][3]=a[i][3].val;
			sort(a[i]+1,a[i]+4,cmp);
			if(a[i][1].dep==1){
				w[i]=1;
				cnta++;
			}
			else if(a[i][1].dep==2){
				w[i]=2;
				cntb++;
			}
			else{
				w[i]=3;
				cntc++;
			}
		}
		if(cnta>n/2){
			int tcnt=0;
			for(int i=1;i<=n;i++){
				if(w[i]==1){
					tcnt++;
					temp[tcnt].val1=a[i][1].val;
					temp[tcnt].val=a[i][2].val;
					temp[tcnt].dep=a[i][2].dep;
					temp[tcnt].pos=i;
				}
			}
			sort(temp+1,temp+cnta+1,cmp1);
			for(int i=1;i<=cnta-n/2;i++) w[temp[i].pos]=temp[i].dep;
		}
		else if(cntb>n/2){
			int tcnt=0;
			for(int i=1;i<=n;i++){
				if(w[i]==2){
					tcnt++;
					temp[tcnt].val1=a[i][1].val;
					temp[tcnt].val=a[i][2].val;
					temp[tcnt].dep=a[i][2].dep;
					temp[tcnt].pos=i;
				}
			}
			sort(temp+1,temp+cntb+1,cmp1);
			for(int i=1;i<=cntb-n/2;i++) w[temp[i].pos]=temp[i].dep;
		}
		else if(cntc>n/2){
			int tcnt=0;
			for(int i=1;i<=n;i++){
				if(w[i]==3){
					tcnt++;
					temp[tcnt].val1=a[i][1].val;
					temp[tcnt].val=a[i][2].val;
					temp[tcnt].dep=a[i][2].dep;
					temp[tcnt].pos=i;
				}
			}
			sort(temp+1,temp+cntc+1,cmp1);
			for(int i=1;i<=cntc-n/2;i++) w[temp[i].pos]=temp[i].dep;
		}
		long long num=0;
		for(int i=1;i<=n;i++){
			num+=b[i][w[i]];
		}
		cout<<num<<endl;
	}
	fclose(stdin);
	fclose(stdout);
}
