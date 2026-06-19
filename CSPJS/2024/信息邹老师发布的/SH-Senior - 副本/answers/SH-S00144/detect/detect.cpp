#include<bits/stdc++.h>
using namespace std;
int T,n,m,l,v;
struct node{
	int v,d,a;
	int l,r;
	bool over;
}car[100005];
int detect[100005]={-1};
long long place[1000005];
bool cmp(node a,node b){
	return a.l<b.l;
}
void work(){
	memset(place,0,sizeof(place));
	memset(detect,0,sizeof(detect));
	memset(car,0,sizeof(car));
	int ans=0;
	cin>>n>>m>>l>>v;
	for(int i=1;i<=n;i++){
		cin>>car[i].d>>car[i].v>>car[i].a;
	}
	int ll,rr;
	for(int i=1;i<=m;i++){
		cin>>detect[i];
		ll=detect[i-1];
		rr=detect[i];
		if(i==m)
			rr=l+1;
		for(int k=ll+1;k<rr;k++){
			if(i==1)
				place[k]=0;
			else if(i==m)
				place[k]=-2;
			else
				place[k]=i-1;
		}
		place[rr]=i*100005;
	}

	for(int i=1;i<=n;i++){
		if(car[i].a==0){
			if(car[i].v<=v||car[i].d>detect[m]){
				car[i].over=0;
			}
			else{
				car[i].over=1;
				ans++;
				if(place[car[i].d]>100000)
					car[i].l=place[car[i].d]/100005;
				else
					car[i].l=place[car[i].d]+1;
				car[i].r=m;
			}
		}
		else if(car[i].a>0){
			if(car[i].d>detect[m])
				car[i].over=0;
			else if(car[i].v>v){
				if(place[car[i].d]>100000)
					car[i].l=place[car[i].d]/100005;
				else
					car[i].l=place[car[i].d]+1;
				car[i].r=m;
				car[i].over=1;
				ans++;
			}
			else{
				long double ss=1.0*(v*v-car[i].v*car[i].v)/(1.0*2*car[i].a);
				int s=(int)(ss);
				if(s!=ss)
				    s++;
				if(car[i].d+s>detect[m])
					car[i].over=0;
				else{
					if(place[car[i].d+s]>100000)
						car[i].l=place[car[i].d+s]/100005;
					else
						car[i].l=place[car[i].d+s]+1;
					car[i].r=m;
					car[i].over=1;
					ans++;
				}		
			}	
		}
		else{
			if(car[i].d>detect[m]||car[i].v<=v)
				car[i].over=0;
			else{
				long long suum=1LL*car[i].v*car[i].v-v*v;
				long double ss=(1.0*suum)/(-1.0*2*car[i].a);
				int s=(int)(ss);
				if(s!=ss)
					s++;
				if(car[i].d+s<detect[m]&&place[car[i].d+s]==place[car[i].d])
					car[i].over=0;
				else{
					if(place[car[i].d+s]>100000)
						car[i].r=place[car[i].d+s]/100005;
					else
						car[i].r=place[car[i].d+s]+1;
					if(place[car[i].d]>100000)
						car[i].l=place[car[i].d]/100005;
					else
						car[i].l=place[car[i].d]+1;
					ans++;
					car[i].over=1;
					
				}
			}
		}	
	}
	cout<<ans<<" "<<m-1<<"\n";
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--){
		work();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;	
}
