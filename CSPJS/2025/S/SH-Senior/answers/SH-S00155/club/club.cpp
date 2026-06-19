#include<bits/stdc++.h>
using namespace std;
struct a{
	int a1,a2,a3;
}s1[100010];
struct b{
	int b1,b2,b3;
}s2[100010];
struct c{
	int c1,c2,c3;
}s3[100010];
bool cmp1(a x,a y){
	if(x.a2>=x.a3){
		if(y.a2>=y.a3){
			if(x.a1-x.a2>y.a1-y.a2){
				return 1;
			}
			return 0;
		}
		else{
			if(x.a1-x.a2>y.a1-y.a3){
				return 1;
			}
			return 0;
		}
	}
	else{
		if(y.a2>=y.a3){
			if(x.a1-x.a3>y.a1-y.a2){
				return 1;
			}
			return 0;
		}
		else{
			if(x.a1-x.a3>y.a1-y.a3){
				return 1;
			}
			return 0;
		}
	}
}
bool cmp2(b x,b y){
	if(x.b1>=x.b3){
		if(y.b1>=y.b3){
			if(x.b2-x.b1>y.b2-y.b1){
				return 1;
			}
			return 0;
		}
		else{
			if(x.b2-x.b1>y.b2-y.b3){
				return 1;
			}
			return 0;
		}
	}
	else{
		if(y.b1>=y.b3){
			if(x.b2-x.b3>y.b2-y.b1){
				return 1;
			}
			return 0;
		}
		else{
			if(x.b2-x.b3>y.b2-y.b3){
				return 1;
			}
			return 0;
		}
	}
}
bool cmp3(c x,c y){
	if(x.c1>=x.c2){
		if(y.c1>=y.c2){
			if(x.c3-x.c1>y.c3-y.c1){
				return 1;
			}
			return 0;
		}
		else{
			if(x.c3-x.c1>y.c3-y.c2){
				return 1;
			}
			return 0;
		}
	}
	else{
		if(y.c1>=y.c2){
			if(x.c3-x.c2>y.c3-y.c1){
				return 1;
			}
			return 0;
		}
		else{
			if(x.c3-x.c2>y.c3-y.c2){
				return 1;
			}
			return 0;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t,n,m1,m2,m3,k1,k2,k3;
	long long sum;
	cin>>t;
	while(t--){
		for(int i=1;i<=100000;i++){
			s1[i].a1=0;
			s1[i].a2=0;
			s1[i].a3=0;
			s2[i].b1=0;
			s2[i].b2=0;
			s2[i].b3=0;
			s3[i].c1=0;
			s3[i].c2=0;
			s3[i].c3=0;
		}
		cin>>n;
		k1=0,k2=0,k3=0,sum=0;
		for(int i=1;i<=n;i++){
			cin>>m1>>m2>>m3;
			if(m1>=m2 && m1>=m3){
				k1++;
				s1[k1].a1=m1;
				s1[k1].a2=m2;
				s1[k1].a3=m3;
			}
			else{
				if(m2>=m3 && m2>=m1){
					k2++;
					s2[k2].b1=m1;
					s2[k2].b2=m2;
					s2[k2].b3=m3;
				}
				else{
					k3++;
					s3[k3].c1=m1;
					s3[k3].c2=m2;
					s3[k3].c3=m3;
				}
			}
		}
		sort(s1+1,s1+1+k1,cmp1);
		sort(s2+1,s2+1+k2,cmp2);
		sort(s3+1,s3+1+k3,cmp3);
		if(k1>n/2){
			while(k1>n/2){
				if(s1[k1].a2>=s1[k1].a3){
					k2++;
					s2[k2].b1=s1[k1].a1;
					s2[k2].b2=s1[k1].a2;
					s2[k2].b3=s1[k1].a3;
				}
				else{
					k3++;
					s3[k3].c1=s1[k1].a1;
					s3[k3].c2=s1[k1].a2;
					s3[k3].c3=s1[k1].a3;
				}
				k1--;
			}
		}
		if(k2>n/2){
			while(k2>n/2){
				if(s2[k2].b1>=s2[k2].b3){
					k1++;
					s1[k1].a1=s2[k2].b1;
					s1[k1].a2=s2[k2].b2;
					s1[k1].a3=s2[k2].b3;
				}
				else{
					k3++;
					s3[k3].c1=s2[k2].b1;
					s3[k3].c2=s2[k2].b2;
					s3[k3].c3=s2[k2].b3;
				}
				k2--;
			}
		}
		if(k3>n/2){
			while(k3>n/2){
				if(s3[k3].c1>=s3[k3].c2){
					k1++;
					s1[k1].a1=s3[k3].c1;
					s1[k1].a2=s3[k3].c2;
					s1[k1].a3=s3[k3].c3;
				}
				else{
					k2++;
					s2[k2].b1=s3[k3].c1;
					s2[k2].b2=s3[k3].c2;
					s2[k2].b3=s3[k3].c3;
				}
				k3--;
			}
		}
		for(int i=1;i<=k1;i++){
			sum+=s1[i].a1;
		}
		for(int i=1;i<=k2;i++){
			sum+=s2[i].b2;
		}
		for(int i=1;i<=k1;i++){
			sum+=s3[i].c3;
		}
		cout<<sum<<"\n";
	}
	return 0;
}
