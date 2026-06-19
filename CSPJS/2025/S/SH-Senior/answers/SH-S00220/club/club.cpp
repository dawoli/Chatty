#include<bits/stdc++.h>
using namespace std;
unsigned long long p[114514][4],q[114514];unsigned long long a,b,c;
bool cmp(int x,int y){
	if(x>y){
		return true;
	}
	return false;
}
void fun()
{
	memset(p,0,sizeof(p));
	memset(q,0,sizeof(q));
	a=b=c=0;
	unsigned long long t;cin>>t;
	unsigned long long s=0;
	for(int i=0;i<t;i++){
		cin>>p[i][1]>>p[i][2]>>p[i][3];
		q[i]=p[i][0]=min(p[i][1],min(p[i][2],p[i][3]));
		for(int j=0;j<i;j++){
			if(q[i]>q[j])swap(p[i],p[j]),swap(q[i],q[j]);
		}
	}
	//sort(q,q+t,cmp);
//	cout<<endl;
//	for(int i=0;i<t;i++){
//		cout<<q[i]<<" "<<p[i][0]<<endl;
//	}
//	cout<<endl;
	for(int i=t-1;i>=0;i--){
		if(p[i][1]>=p[i][2]&&p[i][1]>=p[i][3]){
			if(a<t/2){
				++a,s+=p[i][1];
				continue;
			}
			if(p[i][2]>=p[i][3]){
				if(b<t/2){
					++b,s+=p[i][2];
					continue;
				}
			}
			if(c<t/2)++c,s+=p[i][3];
			continue;
		}
		if(p[i][2]>=p[i][1]&&p[i][2]>=p[i][3]){
			if(b<t/2){
				++b,s+=p[i][2];
				continue;
			}
			if(p[i][1]>=p[i][3]){
				if(a<t/2){
					++a,s+=p[i][1];
					continue;
				}
			}
			if(c<t/2)++c,s+=p[i][3];
			continue;
		}
		if(p[i][3]>=p[i][2]&&p[i][3]>=p[i][1]){
			if(c<t/2){
				++c,s+=p[i][3];
				continue;
			}
			if(p[i][2]>=p[i][1]){
				if(b<t/2){
					++b,s+=p[i][2];
					continue;
				}
			}
			if(a<t/2)++a,s+=p[i][1];
			continue;
		}
	}
	cout<<s<<endl;
	return;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int xx;
	cin>>xx;
	while(xx--)fun();
	return 0;
}
