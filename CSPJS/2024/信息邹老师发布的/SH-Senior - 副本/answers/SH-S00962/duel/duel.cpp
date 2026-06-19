#include<bits/stdc++.h>

using namespace std;

int n;
int r[100010];
bool used[100010];
bool dead[100010];


int greedy(){
	sort(r+1,r+1+n);
	int cnt=n; //还剩下多少
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(r[j]>r[i] && (!used[j])){
				used[j]=true;
				cnt--;
			}
		}
	} 
	printf("%d\n", cnt);
	return 0;
}

int dfsans=0x3f3f3f3f;
int countdead=0;
int countused=0;
int forceful(){
	//cout<<"DEBUG"<<endl;//DEL
	
	bool flag=false;
	//在场上选择两个怪兽决斗:i向j发起进攻 
	for(int i=1;i<=n;i++){
		if(dead[i])continue; 
		if(used[i])continue;
		for(int j=1;j<=n;j++){
			if(j==i)continue;
			if(dead[j])continue;
			
			flag=true;
			if(r[i]>r[j])dead[j]=true;
			used[i]=true;
			countdead++;
			countused++;
			
			forceful();
			
			countdead--;
			countused--;
			dead[j]=false;
			used[i]=false;
		}
	}
	if(flag==false){
		//没有攻击发起
		//1.场上所有的怪兽都发起过攻击
		//2.场上有怪兽没有发起过攻击->那么它是唯一的怪兽，失败
		if(countused!=n)return 0;
		dfsans=min(dfsans, n-countdead);
	}
	
	return 0;
}

int main(){
	
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	
	scanf("%d", &n);
	for(int i=1;i<=n;i++){
		scanf("%d", &r[i]);
	}

	greedy();  //贪心是错的 
	//forceful();
	//cout<<dfsans<<endl;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}


/*

首先我想贪心，但我不知道对不对
如果贪心，对于一个怪兽，让权值比他大的最小的怪兽干掉他
那么我先对怪兽排序，然后O(n)*O(n)，第二个o(n)可以优化掉
然而事情没有那么简单：你选定的怪兽可能已经被干掉了
那么我们从小到大干掉怪兽 

*/
