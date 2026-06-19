#include<cstring>
#include<iostream>
using namespace std;
static const int maxn=1000001;
int n,k,a[maxn];
//q是单调队列，存放数据元素，p是元素对应编号。head头结点，tail尾结点
int q[maxn],head,tail,p[maxn];
void hqueue_max() { //单调最大值 队列中保存的是区间的最大值
	head=1;
	tail=0;
	for(int i=1; i<=n; ++i) {//n个数
		while(head<=tail&&q[tail]<=a[i])//队列有元素且队首<=当前的a[i]
			tail--;
		q[++tail]=a[i];
		p[tail]=i;
		while(p[head]<=i-k)//18 17 16 15
			head++;
		if(i>=k) printf("%d ",q[head]);
	}
	return;
}
void hqueue_min() {
	//head对应首元素，tail对应尾元素，所以当tail>=head时，说明有元素。
	head=1;
	tail=0;
	for(int i=1; i<=n; i++) { //a[i]表示当前要处理的数值
		//只要队列里有元素，并且尾元素比待处理值大，
		//即表示尾元素已经不可能出场，所以出队。直到尾元素小于待处理值，满足"单调"。
		while(head<=tail&&q[tail]>=a[i])
			tail--;
		q[++tail]=a[i];//待处理值入队。
		p[tail]=i;//同时存下其编号
		////如果队首元素不在元素区间范围内，出队。
		while(p[head]<=i-k)
			head++;
		//i>=k表示，处理k个元素以上，应该输出，内容是队首元素
		if(i>=k)printf("%d ",q[head]);
	}
}
int main() {
	int i,j;
	scanf("%d %d",&n,&k);
	for(int i=1; i<=n; i++)
		scanf("%d",&a[i]);
	hqueue_min();
	cout<<endl;
	hqueue_max();
	return 0;
}