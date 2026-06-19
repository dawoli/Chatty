#include <bits/stdc++.h>
using namespace std;
int t,n,ans,a,b;
struct node{
	int sat,num;
}member[100005][3],section[3][50002];;
int sum[3]={};
bool cmp(node x,node y){
	return x.sat>y.sat;
};
bool cmp2(node x,node y){
	if(x.sat !=0 && y.sat!=0){return x.sat<y.sat;}
	else return x.sat>y.sat;
	
};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int m=0;m<t;m++){
		ans=0;
		cin>>n;
		for(int i=0;i<n;i++){
			for(int m=0;m<3;m++){
				cin>>member[i][m].sat;
				member[i][m].num=m;
			}
			sort(member[i],member[i]+3,cmp);
		}
		for(int k=0;k<n;k++){
			b=member[k][0].num;
			a=section[b][0].num;
			if(sum[b]>n/2){
				if(member[k][0].sat>section[b][0].sat){
					//cout<<"y";
					ans=ans-section[b][0].sat;
					//cout<<ans;
					section[member[a][1].num][sum[member[a][1].num]].sat=member[a][1].sat;
					section[b][0].sat=member[k][0].sat;section[b][0].num=k;
					sum[b]++;
					ans=ans+member[k][0].sat+section[member[a][1].num][sum[member[a][1].num]++].sat;
				}
				else{
					section[member[k][1].num][sum[member[k][1].num]].sat=member[k][1].sat;
					sum[member[k][1].num]++;
					ans=ans+member[k][1].sat;
				}
			}
			else{
				section[member[k][0].num][sum[member[k][0].num]].sat=member[k][0].sat;
				sum[b]++;
				ans=ans+member[k][0].sat;
			}
			sort(section[0],section[0]+sum[0],cmp2);
			sort(section[1],section[1]+sum[1],cmp2);
			sort(section[2],section[2]+sum[2],cmp2);
		}
	cout<<ans<<endl;
	for(int z=0;z<n/2;z++){
		member[z][0].sat=0;member[z][1].sat=0;member[z][2].sat=0;
		member[z][0].num=0;member[z][1].num=0;member[z][2].num=0;
		section[0][z].sat=0;section[1][z].sat=0;section[2][z].sat=0;
		section[0][z].num=0;section[1][z].num=0;section[2][z].num=0;
	}
	for(int z=n/2;z<n;z++){
		member[z][0].sat=0;member[z][1].sat=0;member[z][2].sat=0;
		member[z][0].num=0;member[z][1].num=0;member[z][2].num=0;
	}
	//cout<<member[0][0].sat<<" "<<section[0][0].sat;
	}
}
