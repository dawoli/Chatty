#include<bits/stdc++.h>
using namespace std;
int t,n,c[5];
vector<int> c1,c2,c3;
bool flag[100005];
int ans;
struct node{
	int x,y,z,id;
	int v1,v2,v3;
	int n1,n2,n3;
}a[100005];
struct temp{
	int val,id;
	bool operator>(const temp&x)const{
		return val>x.val;
	}
};
priority_queue<temp,vector<temp>,greater<temp>>G1,G2,G3;
bool cmp(temp x,temp y){
	return x.val>y.val||(x.val==y.val&&x.id<y.id);
}
void init(){
	for(int i=1;i<=n;i++)	flag[i]=false;
	c[1]=0,c[2]=0,c[3]=0;
	ans=0;
	c1.clear();
	c2.clear();
	c3.clear();
	return;
}
void get_v_n(int i){
	temp aa[5];
	aa[1]={a[i].x,1},aa[2]={a[i].y,2},aa[3]={a[i].z,3};
	sort(aa+1,aa+4,cmp);
	a[i].v1=aa[1].val,a[i].v2=aa[2].val,a[i].v3=aa[3].val;
	a[i].n1=aa[1].id,a[i].n2=aa[2].id,a[i].n3=aa[3].id;
	return;
}
void G123_clear(){
	while(!G1.empty())	G1.pop();
	while(!G2.empty())	G2.pop();
	while(!G3.empty())	G3.pop();
	return;
} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--){
		G123_clear();
		init();
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			get_v_n(i);
			ans+=a[i].v1;
			c[a[i].n1]++;
			if(a[i].n1==1){
				c1.push_back(i);
			}	
			else if(a[i].n1==2){
				c2.push_back(i);
			}
			else{
				c3.push_back(i);
			}
		}
		if(c[1]>n/2){
			G123_clear();
			for(auto i:c1){
				G2.push({a[i].x-a[i].y,i});
				G3.push({a[i].x-a[i].z,i});
			}
			int cc=c[1]-n/2;
			for(int i=1;i<=cc;i++){
				while(flag[G2.top().id])	G2.pop();
				while(flag[G3.top().id])	G3.pop();
				if(c[2]>=n/2){
					ans-=G3.top().val;
					flag[G3.top().id]=true;
					G3.pop();
					c[3]++;
					c[1]--;
				}
				else if(c[3]>=n/2){
					ans-=G2.top().val;
					flag[G2.top().id]=true;
					G2.pop();
					c[2]++;
					c[1]--;
				}
				else{
					if(G2.top().val<G3.top().val){
						ans-=G2.top().val;
						flag[G2.top().id]=true;
						G2.pop();
						c[2]++;
						c[1]--;
					}
					else if(G2.top().val>G3.top().val){
						ans-=G3.top().val;
						flag[G3.top().id]=true;
						G3.pop();
						c[3]++;
						c[1]--;
					}
					else{
						if(c[2]<c[3]){
							ans-=G2.top().val;
							flag[G2.top().id]=true;
							G2.pop();
							c[2]++;
							c[1]--;
						}
						else{
							ans-=G3.top().val;
							flag[G3.top().id]=true;
							G3.pop();
							c[3]++;
							c[1]--;
						}
					}
				}
			}
		}
		for(auto i:c1)	flag[i]=false;
		if(c[2]>n/2){
			G123_clear();
			for(auto i:c2){
				G1.push({a[i].y-a[i].x,i});
				G3.push({a[i].y-a[i].z,i});
			}
			int cc=c[2]-n/2;
			for(int i=1;i<=cc;i++){
				while(flag[G1.top().id])	G1.pop();
				while(flag[G3.top().id])	G3.pop();
				if(c[1]>=n/2){
					ans-=G3.top().val;
					flag[G3.top().id]=true;
					G3.pop();
					c[3]++;
					c[2]--;
				}
				else if(c[3]>=n/2){
					ans-=G1.top().val;
					flag[G1.top().id]=true;
					G1.pop();
					c[1]++;
					c[2]--;
				}
				else{
					if(G1.top().val<G3.top().val){
						ans-=G1.top().val;
						flag[G1.top().id]=true;
						G1.pop();
						c[1]++;
						c[2]--;
					}
					else if(G1.top().val>G3.top().val){
						ans-=G3.top().val;
						flag[G3.top().id]=true;
						G3.pop();
						c[3]++;
						c[2]--;
					}
					else{
						if(c[1]<c[3]){
							ans-=G1.top().val;
							flag[G1.top().id]=true;
							G1.pop();
							c[1]++;
							c[2]--;
						}
						else{
							ans-=G3.top().val;
							flag[G3.top().id]=true;
							G3.pop();
							c[3]++;
							c[2]--;
						}
					}
				}
			}
		}
		for(auto i:c2)	flag[i]=false;
		if(c[3]>n/2){
			G123_clear();
			for(auto i:c3){
				G1.push({a[i].z-a[i].x,i});
				G2.push({a[i].z-a[i].y,i});
			}
			int cc=c[3]-n/2;
			for(int i=1;i<=cc;i++){
				while(flag[G1.top().id])	G1.pop();
				while(flag[G2.top().id])	G2.pop();
				if(c[1]>=n/2){
					ans-=G2.top().val;
					flag[G2.top().id]=true;
					G2.pop();
					c[2]++;
					c[3]--;
				}
				else if(c[2]>=n/2){
					ans-=G1.top().val;
					flag[G1.top().id]=true;
					G1.pop();
					c[1]++;
					c[3]--;
				}
				else{
					if(G1.top().val<G2.top().val){
						ans-=G1.top().val;
						flag[G1.top().id]=true;
						G1.pop();
						c[1]++;
						c[3]--;
					}
					else if(G1.top().val>G2.top().val){
						ans-=G2.top().val;
						flag[G2.top().id]=true;
						G2.pop();
						c[2]++;
						c[3]--;
					}
					else{
						if(c[1]<c[2]){
							ans-=G1.top().val;
							flag[G1.top().id]=true;
							G1.pop();
							c[1]++;
							c[3]--;
						}
						else{
							ans-=G2.top().val;
							flag[G2.top().id]=true;
							G2.pop();
							c[2]++;
							c[3]--;
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
