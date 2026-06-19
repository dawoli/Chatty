#include<bits/stdc++.h>
using namespace std;
int t;
int largesta(int q,int p,int z){
	if(q>p&&q>z){
		return 0;
	}
	else if(p>q&&p>z){
		return 1;
	}
	else{
		return 2;
	}
}
int middlee(int q,int p,int z){
	if(q>=p&&q<=z||q>=z&&q<=p){
		return 0;
	}
	else if(p>=z&&p<=q||p<=z&&p>=q){
		return 1;
	}
	else{
		return 2;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int j=0;j<t;j++){
		int n;
		int a[100001][3]={0};
		int b[3][20001]={0};
		int l[3]={0};
		int sum=0;
		cin>>n;
		for(int i=0;i<n;i++) cin>>a[i][0]>>a[i][1]>>a[i][2];
		for(int i=0;i<n;i++){
			int o= largesta(a[i][0],a[i][1],a[i][2]);
			int z= middlee(a[i][0],a[i][1],a[i][2]);
			l[o]++;
			sum+=a[i][o];
			int s=a[i][o]-a[i][z];
			b[o][s]+=1;
		}
		int d=n/2;
		if(l[0]>d){
			int cha=l[0]-d;
			int zm=0;
			int qp=0;
			while(cha>0){
				if(b[0][zm]!=0){
					while(b[0][zm]>0){
						cha--;
						sum-=zm;
						b[0][zm]--;
						if(cha<1){
							break;
						}
					}
				}
				zm++;
			}
		}
		else if(l[1]>d){
			int cha=l[1]-d;
			int zm=0;
			int qp=0;
			while(cha>0){
				if(b[1][zm]!=0){
					while(b[1][zm]>0){
						cha--;
						sum-=zm;
						b[1][zm]--;
						if(cha<1){
							break;
						}
					}
				}
				zm++;
			}
		}
		else if(l[2]>d){
			int cha=l[2]-d;
			int zm=0;
			int qp=0;
			while(cha>0){
				if(b[2][zm]!=0){
					while(b[2][zm]>0){
						cha--;
						sum-=zm;
						b[2][zm]--;
						if(cha<1){
							break;
						}
					}
				}
				zm++;
			}
		}
		if(j==t-1){
			cout<<sum;
		}
		else{
			cout<<sum<<endl;
		}
	}
	return 0;
} 
