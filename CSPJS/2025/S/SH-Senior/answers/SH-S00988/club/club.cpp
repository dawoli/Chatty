#include<bits/stdc++.h>
using namespace std;
int t;
struct comb{
	int f,s,dif;
}diff[100005];
struct node{
	int uni,bi,tri,dif1,dif2;
}stu[100005];

bool cmp(comb x,comb y){
	return x.dif<y.dif;
}
bool cmp2(node x,node y){
	return max(x.dif1,x.dif2)<max(y.dif1,y.dif2);
}
int main(){
	freopen("club.out","w",stdout);
	freopen("club.in","r",stdin);
	cin>>t;
	while(t--){
		int n,a1[100005],a2[100005],a3[100005],capa=1,capb=1;
		cin>>n;
		for (int i=1;i<=n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
			if(a3[i]!=0)
			{
				capa=capb=0;
			}
			if(a2[i]!=0){
				capa=0;
			}
		}
		if(capa){
			sort(a1+1,a1+n+1);
			int ans=0;
			for (int i=n;i>=n/2;i--){
				ans+=a1[i];
			}
			cout<<ans<<endl;
			continue;
		}
		if(capb){
			int num1=0,num2=0,ans=0;
			for (int i=1;i<=n;i++){
				diff[i].dif=abs(a1[i]-a2[i]);
				diff[i].s=a2[i];
				diff[i].f=a1[i];
			}
			cout<<endl;
			sort(diff+1,diff+n+1,cmp);
			int i=n;
			for(int i=n;i>=1;i--){
				if(diff[i].f>diff[i].s){
					if(num1<n/2){
						num1++;
						ans+=diff[i].f;
					}
					else{
						num2++;
						ans+=diff[i].s;
					}
				}
				if(diff[i].f<diff[i].s){
					if(num2<n/2){
						num2++;
						ans+=diff[i].s;
					}
					else{
						num1++;
						ans+=diff[i].f;
					}
				}
				if(diff[i].f==diff[i].s){
					ans+=diff[i].s;
				}
			}
			cout<<ans<<endl;
			continue;
		}
	}
}
