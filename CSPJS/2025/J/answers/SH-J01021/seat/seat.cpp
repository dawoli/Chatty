#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
/*========================*/
int n,m;//考场行数和列数
int score[10005];//学生成绩
int rli=1,rhe=1;//小R的列 
bool sh=1;
int l=1;
int R_locate=1;
/*========================*/
bool cmp(int a,int b){
	return a > b;
}
struct sv{
	int num;
	int x;
	int y;
};
/*========================*/
void Solve()
{
	cin>>n>>m;
	//cout<<"----------------------0-----------------"<<endl;
	for(int i = 1;i <= n * m - 1;i++){
		cin >> score[i];
	}
	
	int R_score = score[1];//小R成绩 
	sort(score + 1, score + n * m + 1,cmp);
	//cout<<"--------------------1-----------------"<<endl;
	
	for(int i = 1;i <= n * m; i++){
		//cout<<score[i]<<" ";
		if(score[i] == R_score){
			break;
		}
		else R_locate++;
	}
	//cout<<R_locate<<endl;
	//cout<<"-------------------------2----------------------"<<endl;
	sv a[10005];
	int xx=1,yy=1;
	bool fg=1;
	a[1].num=1;
	a[1].x=1;
	a[1].y=1;
	for(int i=1;i<=m*n;i++)
	{
		a[i].num=i;
		a[i].x=xx;
		a[i].y=yy;
		if(fg){
			xx++;
		}
		else {
			xx--;
		}
		if(xx>n){
			xx--;
			yy++;
			fg=0;
		}
		else if(xx<1){
			xx++;
			yy++;
			fg=1;
		}
		//cout<<a[i].x<<" "<<a[i].y<<" "<<a[i].num<<endl;
	}
	cout<<a[R_locate].y<<" "<<a[R_locate].x;
	
		
	
	return ;
}
/*========================*/
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	Solve();
	return 0;
}
