#include <bits/stdc++.h>
using namespace std;

struct node{
	int a,b,c,id,flag=0;
};
int ans_1,ans_2,ans_3;
bool cmp(node x,node y){
	if(x.flag!=y.flag){
		return x.flag>y.flag;
		return x.id>y.id;
	}else{
		return x.id>y.id;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		//cout<<"t:"<<t<<endl;
		node v[100010];
		//cout<<"v[0].a:"<<v[0].a<<endl;
		int ans=0,ans_1=0,ans_2=0,ans_3=0;
		int n;
		cin>>n;
		//cout<<"n:"<<n<<endl;
		for(int i=0;i<n;i++){
			int x,y,z;
			cin>>x>>y>>z;
			v[i].a=x;
			v[i].b=y;
			v[i].c=z;
			v[i].id=max(x,max(y,z));
			if(v[i].a==0 && v[i].b==0){
				v[i].flag=1;
				continue;
			}else if(v[i].a==0 && v[i].c==0){
				v[i].flag=1;
				continue;
			}else if(v[i].c==0 && v[i].b==0){
				v[i].flag=1;
				continue;
			}
			
		}
		int f=0;
		sort(v,v+n,cmp);
		for(int i=0;i<n;i++){
			if(v[i].id==v[i].a){
				f=0;
			}else if(v[i].id==v[i].b){
				f=1;
			}else{
				f=2;
			}
			if(f==0){
				if(ans_1<n/2){
					ans_1++;
					ans+=v[i].a;
				}else{
					v[i].id=max(v[i].b,v[i].c);
					bool flag1=false;
					if(v[i].id==v[i].b){
						if(ans_2<n/2){
							ans_2++;
							ans+=v[i].b;
							flag1=true;
						}
					}else{
						if(!flag1){
							ans_3++;
							ans+=v[i].c;
						}
					}
				}
			}else if(f==1){
				if(ans_2<n/2){
					ans_2++;
					ans+=v[i].b;
				}else{
					v[i].id=max(v[i].a,v[i].c);
					bool flag1=false;
					if(v[i].id==v[i].a){
						if(ans_1<n/2){
							ans_1++;
							ans+=v[i].a;
							flag1=true;
						}
					}else{
						if(!flag1){
							ans+=v[i].c;
							ans_3++;
						}
					}
				}
			}else{
				if(ans_3<n/2){
					ans_3++;
					ans+=v[i].c;
				}else{
					v[i].id=max(v[i].b,v[i].a);
					bool flag1=false;
					if(v[i].id==v[i].a){
						if(ans_1<n/2){
							ans_1++;
							ans+=v[i].a;
							flag1=true;
						}
					}else{
						if(!flag1){
							ans+=v[i].b;
							ans_2++;
						}
					}
				}
			}
			//cout<<"ans:"<<ans<<endl;
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
