#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n;//<1e5
int a[N][5];//<2e4
struct node{
	int x,y,z;  //最大的满意度 其他两个 
	friend bool operator<(node a,node b){
		int mna=a.x-max(a.y,a.z);    //最小满意度减小值=最大的满意度-剩余两个满意度中较大的 
		int mnb=b.x-max(b.y,b.z);
		return mna>mnb;  //最小满意度减小值较小的放在队头 
	}
};
void change(priority_queue<node> &d1,priority_queue<node> &d2,priority_queue<node> &d3){//引用 
	while(d1.size()>n/2){ //当这个岗位上的人>n/2 
		node u=d1.top();//取出最小满意度减小值的人
		d1.pop();//调离 
		if(u.y>u.z){//找到这个最小值的来源 
			d2.push({u.y,u.x,u.z});//加入 注意把这个次大值放首位 
		} 
		else{ 
			d3.push({u.z,u.x,u.y}); //同理 
		}
	}
}
void solve(){
	priority_queue<node> d1,d2,d3;    //让满意度小的在前 最大时间复杂度nlogn 
	for(int i=1;i<=n;i++){
		if(a[i][1]>=a[i][2] && a[i][1]>=a[i][3]){    //第一个岗位满意度最大 
			d1.push({a[i][1],a[i][2],a[i][3]}); 
		}
		else if(a[i][2]>=a[i][1] && a[i][2]>=a[i][3]){ //第二个岗位满意度最大 
			d2.push({a[i][2],a[i][1],a[i][3]});
		}
		else{										//第三个岗位满意度最大 
			d3.push({a[i][3],a[i][1],a[i][2]});
		}
		
	}
	//先选好自己最满意的职位 
	//按调换岗位后满意度减少值从高到低排序 
	
	if(d1.size()>n/2){				
		change(d1,d2,d3); 
	}
	if(d2.size()>n/2){
		change(d2,d1,d3);
	}
	if(d3.size()>n/2){
		change(d3,d1,d2);
	} 
	//先调离队尾 满意值减少最低的 
	 
	long long ans=0;
	while(d1.size()){
		ans+=d1.top().x;
		d1.pop();
	}
	while(d2.size()){
		ans+=d2.top().x;
		d2.pop();
	}
	while(d3.size()){
		ans+=d3.top().x;
		d3.pop();
	}
	//计算满意值 
	cout << ans << endl; 
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;//测试组数 
	cin >> t;//输入 
	while(t--){
		cin >> n;//人数 
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin >> a[i][j]; 
			}
		}//输入满意度 
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
