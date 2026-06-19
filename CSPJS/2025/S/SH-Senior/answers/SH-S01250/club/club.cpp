# include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 1e5+10;
ll l[MAXN][4],c[4];
int a[MAXN][4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T,non;
	ll n;
	cin>>T;
	while(T--){
		c[1] = 0;
		c[2] = 0;
		c[3] = 0;//孩子们，memset咋写来着。 
		ll sum = 0,cnt = 0;
		cin>>n;
		if(n == 2){
			for(int i = 1;i<=n;i++){
				cin>>l[i][1]>>l[i][2]>>l[i][3];
			}
			sum = max(l[1][1]+l[2][2],max(l[1][1]+l[2][3],max(l[1][2]+l[2][1],max(l[1][2]+l[2][3],max(l[1][3]+l[2][1],l[1][3]+l[2][2])))));
			cout<<sum<<"\n";
		}else{
			for(int i = 1;i<=n;i++){
			cin>>l[i][1]>>l[i][2]>>l[i][3];
			//超级判断达人 
			if(l[i][1]>=l[i][2]){    //判断1>2？ 
				if(l[i][1]>=l[i][3]){  //判断1>3？ 
					if(l[i][2]>=l[i][3]){
						a[i][1] = 1;
						a[i][2] = 2;
						a[i][3] = 3;
					}else{
						a[i][1] = 1;
						a[i][2] = 3;
						a[i][3] = 2;
					}
				}else{
					a[i][1] = 3;
					a[i][2] = 1;
					a[i][3] = 2;//这就是传说中的屎山代码吗   老吃家了 
				}
			}else{
				if(l[i][1]>=l[i][3]){
					a[i][1] = 2;
					a[i][2] = 1;
					a[i][3] = 3;
				}else{
					if(l[i][2]>=l[i][3]){
						a[i][1] = 2;
						a[i][2] = 3;
						a[i][3] = 1;
					}else{
						a[i][1] = 3;
						a[i][2] = 2;
						a[i][3] = 1;
					} 
				}
			}//这里是判断完了（擦汗）
		}
		non = n/2;//这个是最大人数，叫做no n（不要n） 
		for(int i = 1;i<=n;i++){
			if(c[a[i][1]]<non){
				c[a[i][1]]++;
				sum+=l[i][a[i][1]];
				continue;
			}else if(c[a[i][2]]<non){
				c[a[i][2]]++;
				sum+=l[i][a[i][2]];
				continue;
			}else{
				c[a[i][3]]++;
				sum+=l[i][a[i][3]];
				continue;
			}
		}
		cout<<sum<<"\n"; 
		}
		
	}
	return 0;
}     
