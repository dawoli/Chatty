#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,m,L,V,b[1000001],p[100001],d[100001],a[100001],v[100001],ans,ind=1,dp[3001][3001][2];
int lb(int x){
	return x&(-x);
}
int add(int i,int x){
	for(;i<=L;i+=lb(i)) b[i]+=x;
}
int sum(int i){
	int ans=0;
	for(;i;i-=lb(i)) ans+=b[i];
	return ans;
}
struct Line{
	int l;
	int r;
}line[100001];
bool cmp(Line a,Line b){
	if(a.l!=b.l)return a.l<b.l;
	return a.r<b.r;
}
void push(Line x){
	line[ind]=x;
	ind++;
}
void update(int &x,int y){
	if(y>x) x=y;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin >> t;
	while(t--){
		ind=1;
		ans=0;
		memset(b,0,sizeof(b));
		cin>>n>>m>>L>>V;
		//cout << n << ' ' << m << ' ' << L << ' ' <<V <<endl;
		//车辆数量 测速仪数量 主干道长度 道路限速
		for(int i=1;i<=n;i++){
			cin >> d[i] >> v[i] >> a[i];
		}
		for(int i=1;i<=m;i++){
			cin >> p[i];
			add(p[i],1);
		}
		for(int i=1;i<=n;i++){
			//cout << d[i] << ' ' << v[i] << ' ' << a[i] << endl << d[i]+double(V*V-v[i]*v[i])/(2*a[i]) << endl;
			if(v[i]>V&&a[i]>=0&&sum(L)-sum(d[i]-1)>0){
				//cout <<"one"<< endl;
				ans++;
				push((Line){d[i],L});
			}else if(v[i]>V&&a[i]<0&&sum(min(L,int(d[i]+double(V*V-v[i]*v[i])/(2*a[i]))))-sum(d[i]-1)>0){
				//cout <<"two"<< endl;
				ans++;
				push((Line){d[i],min(L,int(d[i]+double(V*V-v[i]*v[i])/(2*a[i])))});
			}else if(v[i]<=V&&a[i]>0&&sum(L)-sum(min(L,int(d[i]+double(V*V-v[i]*v[i])/(2*a[i]))))>0){
				//cout <<"three"<< endl;
				ans++;
				push((Line){min(L,int(d[i]+double(V*V-v[i]*v[i])/(2*a[i]))),L});
			}
		}
		cout << ans << ' ';
		//cout << endl;
		for(int i=1;i<ind;i++){
			//cout << line[i].l <<' ' << line[i].r << endl;
		}
		for(int i=1;i<=m;i++){
			//cout <<p[i]<<' ';
		}
		//cout << endl;
		sort(line+1,line+ind,cmp);
		dp[0][1][0]=1;
		for(int i=1;i<ind;i++){
			dp[i][0][0]=dp[i][0][1]=-1;
			int l=line[i].l;
			int r=line[i].r;
			for(int j=1;j<=m;j++){
				dp[0][j][0]=j;
				dp[0][j][1]=j-1;
				dp[i][j][0]=dp[i][j][1]=-1;
				if(j==1){
						//cout << max(dp[i-1][j][1],dp[i-1][j][0]) << ' ' <<l << ' ' << p[j] <<' '<< r << '|';
					if(dp[i-1][j][1]>=0&&l<=p[j]&&p[j]<=r){
						dp[i][j][1]=0;
					}else{
						dp[i][j][1]=dp[i][j][0]=-1;
					}
				}else{
					if(max(dp[i][j-1][0],dp[i][j-1][1])>=0){
						update(dp[i][j][0],max(dp[i][j-1][1],dp[i][j-1][0])+1);
						update(dp[i][j][1],max(dp[i][j-1][1],dp[i][j-1][0]));
					}
					if(l<=p[j]&&p[j]<=r){
						update(dp[i][j][1],dp[i-1][j][1]);
					}
				}
				//cout << max(dp[i][j][0],dp[i][j][1]) << ' '; 
				
			}
			//cout << endl;
		}
		if(ans)cout << max(dp[ind-1][m][0],dp[ind-1][m][1]) << endl;
		else cout << m<< endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
