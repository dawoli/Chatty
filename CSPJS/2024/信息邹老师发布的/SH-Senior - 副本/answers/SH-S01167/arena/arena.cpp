#include<bits/stdc++.h>
using namespace std;
int t,n,m,basea[100005],x[4],a[100005],c[100005],d[100005],l,ans[100005];
string s;
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>basea[i];
	for(int i=1;i<=m;i++)cin>>c[i];
	for(int i=1;i<=ceil(log(n)/log(2));i++){
		cin>>s;
		for(int j=0;j<s.size();j++)d[++l]=s[j]-'0';
	}
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>x[0]>>x[1]>>x[2]>>x[3];
		for(int i=1;i<=n;i++)a[i]=basea[i]^x[i%4];
		if(n<=8){
			for(int j=1;j<=m;j++){
				if(c[j]==1)ans[j]=1;
				else if(c[j]==2){
						if(d[1]&&a[2]>=1)ans[j]=2;
						if(d[1]&&a[2]<1)ans[j]=1;
						if(!d[1]&&a[1]>=1)ans[j]=1;
						if(!d[1]&&a[1]<1)ans[j]=2;
					}
				else if(c[j]==3){
					int adv[2];
					if(d[1]&&a[2]>=1)adv[0]=2;
					if(d[1]&&a[2]<1)adv[0]=1;
					if(!d[1]&&a[1]>=1)adv[0]=1;
					if(!d[1]&&a[1]<1)adv[0]=2;
					if(!d[2]){
						if(a[3]>=1)adv[1]=3;
						else adv[1]=4;
					}
					if(d[2])adv[1]=7;
					if(d[3]==0){
						if(a[adv[0]]>=2)ans[j]=adv[0];
						else ans[j]=adv[1];
					}
					if(d[3]){
						if(adv[1]==7){
							if(a[3]>=2)ans[j]=7+adv[0];
							else ans[j]=4+adv[0];
						}
						else if(adv[1]==3){
							if(a[3]>=2)ans[j]=3;
							else ans[j]=adv[0];
						}
						else{
							ans[j]=4+adv[0];
						}
					}
				}
				else if(c[j]==4){
					int adv[2];
					if(d[1]&&a[2]>=1)adv[0]=2;
					if(d[1]&&a[2]<1)adv[0]=1;
					if(!d[1]&&a[1]>=1)adv[0]=1;
					if(!d[1]&&a[1]<1)adv[0]=2;
					if(d[2]&&a[4]>=1)adv[1]=4;
					if(d[2]&&a[4]<1)adv[1]=3;
					if(!d[2]&&a[3]>=1)adv[1]=3;
					if(!d[2]&&a[3]<1)adv[1]=4;
					if(d[3]){
						if(a[adv[1]]>=2)ans[j]=adv[1];
						else ans[j]=adv[0];
					}
					else{
						if(a[adv[0]]>=2)ans[j]=adv[0];
						else ans[j]=adv[1];
					}
				}
				else {
					int adv[6];
					if(d[1]&&a[2]>=1)adv[0]=2;
					if(d[1]&&a[2]<1)adv[0]=1;
					if(!d[1]&&a[1]>=1)adv[0]=1;
					if(!d[1]&&a[1]<1)adv[0]=2;
					if(d[2]&&a[4]>=1)adv[1]=4;
					if(d[2]&&a[4]<1)adv[1]=3;
					if(!d[2]&&a[3]>=1)adv[1]=3;
					if(!d[2]&&a[3]<1)adv[1]=4;
					if(d[5]){
						if(a[adv[1]]>=2)adv[4]=adv[1];
						else adv[4]=adv[0];
					}
					else{
						if(a[adv[0]]>=2)adv[4]=adv[0];
						else adv[4]=adv[1];
					}
					if(c[j]==5){
						if(d[3])adv[2]=11;
						else if(a[5]>=1)adv[2]=5;
						else adv[2]=6;
						if(d[6])adv[5]=26;
						else if(a[5]>=2)adv[5]=26;
						else adv[5]=21;
						if(d[7]){
							if(adv[5]==21)ans[j]=21+adv[4];
							else if(a[5]>=3)ans[j]=26+adv[4];
							else ans[j]=21+adv[4];
						}
						else{
							if(a[adv[4]]>=3)ans[j]=adv[4];
							else ans[j]=adv[5];
						}
					}
					if(c[j]==6){
						if(d[3]){
							if(a[6]>=1)adv[2]=6;
							else adv[2]=5;
						}
						else{
							if(a[5]>=1)adv[2]=5;
							else adv[2]=6;
						}
						if(d[6])adv[5]=15+adv[2];
						else{
							if(a[adv[2]]>=2)adv[5]=adv[2];
							else adv[5]=15;
						}
						if(d[7]){
							if(adv[5]==15)ans[j]=adv[4]+15;
							if(adv[5]==20){
								if(a[5]>=3)ans[j]=20+adv[4];
								else ans[j]=15+adv[4];
							}
							if(adv[5]==21){
								if(a[6]>=3)ans[j]=21+adv[4];
								else ans[j]=15+adv[4];
							}
							if(adv[5]==adv[2]){
								if(a[adv[2]]>=3)ans[j]=adv[2];
								else ans[j]=adv[4];
							}
						}
						else{
							if(a[adv[4]]>=3)ans[j]=adv[4];
							else ans[j]=adv[5];
						}
					}
					if(c[j]==7){
						if(d[3]){
							if(a[6]>=1)adv[2]=6;
							else adv[2]=5;
						}
						else{
							if(a[5]>=1)adv[2]=5;
							else adv[2]=6;
						}
						if(d[4])adv[3]=15;
						else if(a[3]>=1)adv[3]=7;
						else adv[3]=8;
						if(d[6]){
							if(adv[3]==15){
								if(a[7]>=2)adv[5]=15+adv[2];
								else adv[5]=8+adv[2];
							}
							if(adv[3]==7){
								if(a[7]>=2)adv[5]=7;
								else adv[5]=adv[2];
							}
							if(adv[3]==8)adv[5]=8+adv[2];
						}
						else{
							if(a[adv[2]]>=2)adv[5]=adv[2];
							else adv[5]=adv[3];
						}
						if(d[7]){
							if(adv[5]<8){
								if(a[adv[5]]>=3)ans[j]=adv[5];
								else ans[j]=adv[4];
							}
							if(adv[5]==8)ans[j]=8+adv[4];
							if(adv[5]==15){
								if(a[7]>=3)ans[j]=15+adv[4];
								else ans[j]=8+adv[4];
							}
							if(adv[5]==8+adv[2]){
								if(a[adv[2]]>=3)ans[j]=adv[5]+adv[4];
								else ans[j]=8+adv[4];
							}
							if(adv[5]==15+adv[2]){
								if(a[adv[2]]<3)adv[5]-=adv[2];
								if(a[7]<3)adv[5]-=7;
								ans[j]=adv[5]+adv[4];
							}
						}
						else{
							if(a[adv[4]]>=3)ans[j]=adv[4];
							else ans[j]=adv[5];
						}
					}
					if(c[j]==8){
						if(d[3]&&a[6]>=1)adv[2]=6;
						if(d[3]&&a[6]<1)adv[2]=5;
						if(!d[3]&&a[5]>=1)adv[2]=5;
						if(!d[3]&&a[5]<1)adv[2]=6;
						if(d[4]&&a[8]>=1)adv[3]=8;
						if(d[4]&&a[8]<1)adv[3]=7;
						if(!d[4]&&a[7]>=1)adv[3]=7;
						if(!d[4]&&a[7]<1)adv[3]=8;
						if(d[6]){
							if(a[adv[3]]>=2)adv[5]=adv[3];
							else adv[5]=adv[2];
						}
						else{
							if(a[adv[2]]>=2)adv[5]=adv[2];
							else adv[5]=adv[3];
						}
						if(d[7]){
							if(a[adv[5]]>=3)ans[j]=adv[5];
							else ans[j]=adv[4];
						}
						else{
							if(a[adv[4]]>=3)ans[j]=adv[4];
							else ans[j]=adv[5];
						}
					}
				}
			}
			int tot=0;
			for(int j=1;j<=m;j++)tot=tot^(ans[j]*j);
			cout<<tot<<endl;
		}
	}
	return 0;
}
