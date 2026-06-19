#include<bits/stdc++.h>
using namespace std;
int T;
struct node{
	int a,b,c;
	int maxx,maxi;
	int cha;
}person[100005];
bool cmp(node x,node y){
	return x.cha>y.cha;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    cin>>T;
	while(T--){
		memset(person,0,sizeof(person));
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>person[i].a>>person[i].b>>person[i].c;
			if(person[i].a>=person[i].b&&person[i].a>=person[i].c){
				person[i].maxx=person[i].a;
				person[i].maxi=1;
				if(person[i].b>person[i].c){
					person[i].cha=person[i].a-person[i].b;
				}
				else{
					person[i].cha=person[i].a-person[i].c;
				}
			}
			if(person[i].b>=person[i].a&&person[i].b>=person[i].c){
				person[i].maxx=person[i].b;
				person[i].maxi=2;
				if(person[i].a>person[i].c){
					person[i].cha=person[i].b-person[i].a;
				}
				else{
					person[i].cha=person[i].b-person[i].c;
				}
			}
			if(person[i].c>=person[i].b&&person[i].c>=person[i].a){
				person[i].maxx=person[i].c;
				person[i].maxi=3;
				if(person[i].a>person[i].b){
					person[i].cha=person[i].c-person[i].a;
				}
				else{
					person[i].cha=person[i].c-person[i].b;
				}
			}
		}
		sort(person+1,person+n+1,cmp);
		long long ans=0;
		int club[4]={0};
		for(int i=1;i<=n;i++){
			if(club[person[i].maxi]<n/2){
				ans+=person[i].maxx;
				club[person[i].maxi]++;
			}
			else{
				ans+=(person[i].maxx-person[i].cha);
			}
		}
		cout<<ans<<'\n';
	} 
	return 0;
}
