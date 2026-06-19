#include<bits/stdc++.h>
using namespace std;
int n,ans=0,ca=0,cb=0,cc=0;

struct T{
	int al,bl,cl;
	int tran;
};
T a[100005],b[100005],c[100005];
bool cmp(T a,T b){
	return a.tran<b.tran;
}

int maxx(int a,int b,int c){
	if(max(a,max(b,c))==a) return a;
	else{
		return max(b,c);
	}
}
int midd(int a,int b,int c){
	
	if(max(a,max(b,c))==a) return max(b,c);
	else{
		if(a<min(b,c)) return min(b,c);
		else return a;
	}
}
void ave(T t[],int len){
	sort(t+1,t+1+len,cmp);
	
	for(int i=1;i<=len-n/2;i++){
		
		ans-=t[i].tran;
	}
	return;
}

int main(){
	//cout<<maxx(3,5,7)<<maxx(5,6,5)<<midd(3,5,6)<<midd(3,3,3)<<midd(3,3,6)<<midd(6,6,9);
	//freopen("club","r",stdin);
	//freopen("club","w",stdout);
	int q,z1,z2,z3,k;
	cin>>q;
	while(q--)
	{
		cin>>n;
		ans=0;
		ca=0;
		cb=0;
		cc=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&z1,&z2,&z3);
			k=maxx(z1,z2,z3);
			if(k==z1){
				ans+=z1;
				ca++;
				a[ca].al=z1;
				a[ca].bl=z2;
				a[ca].cl=z3;
				a[ca].tran=z1-max(z2,z3);
				//cout<<a[ca].tran<<endl;
			}
			else if(k==z2){
				ans+=z2;
				cb++;
				b[cb].al=z1;
				b[cb].bl=z2;
				b[cb].cl=z3;
				b[cb].tran=z2-max(z1,z3);
				//cout<<b[cb].tran<<endl;
			}
			else{
				ans+=z3;
				cc++;
				c[cc].al=z1;
				c[cc].bl=z2;
				c[cc].cl=z3;
				c[cc].tran=z3-max(z2,z1);
				//cout<<c[cc].tran<<endl;
			}
		}
		//cout<<"^%^"<<ans<<endl;
		k=maxx(ca,cb,cc);
		if(k>n/2){
			//cout<<"^&*^&*"<<endl;
			if(k==ca){
				
				ave(a,ca);
			}
			else if(k==cb){
				
				ave(b,cb);
			}
			else{
				
				ave(c,cc);
			}
		}
		printf("%d\n",ans);
	}
}
