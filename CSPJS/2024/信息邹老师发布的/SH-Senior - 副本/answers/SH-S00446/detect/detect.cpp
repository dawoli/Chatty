#include<bits/stdc++.h>
using namespace std;
int t,n,m,l,v;
int pos,spd,add,cnt,ans;
long long ans2;
struct checker{
	int posi;
	int used;
}c[10003];
struct over{
	int start,finish;
	bool check;
}s[10003];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	while(t){
		t--;
		cnt=0;
		for(int i=1;i<=10000;i++){
			s[i].finish=0;
			s[i].start=0;
		}
		cin>>n>>m>>l>>v;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&pos,&spd,&add);
			if(add==0){
				if(spd>v){
					s[i].start=pos;
					s[i].finish=l;
				}
			}else if(add>0){
				if(spd>v){
					s[i].start=pos;
					s[i].finish=l;
				}
				else{
					if((pos+(v*v-spd*spd)/2*add+1)<=l){
						s[i].start=pos+(v*v-spd*spd)/2*add;
						s[i].finish=l;
					}
				}
			}else{
				if(spd>v){
					s[i].start=pos;
					s[i].finish=min(l,pos+(v*v-spd*spd)/2*add);
				}
			}
		}
		for(int i=1;i<=m;i++){
			c[i].used=0;
			cin>>c[i].posi;
			for(int j=1;j<=n;j++){
				if(s[j].start<=c[i].posi&&s[j].finish>=c[i].posi){
					if(s[j].check==0){
						s[j].check=1;
						cnt++;
					}
					c[i].used++;
				}
			}
		}
		for(int i=1;i<=m;i++){
			if(c[i].used==0) ans++;
		}
		cout<<cnt<<' '<<ans+cnt/2<<endl;
	}
	
	return 0;
}

