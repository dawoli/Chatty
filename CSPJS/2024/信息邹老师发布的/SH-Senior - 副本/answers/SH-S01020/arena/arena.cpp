#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n;
int r[N];
int used_tot;
int ans;
//问r[1..n]中最少有多少个上升子序列
//每个序列中只有最大的予以保留 

struct LinkedList{
	int val;
	struct LinkedList *next;
};
struct LinkedList *head;
void init(){
	head=(LinkedList*)malloc(sizeof(LinkedList));
	head->val=0;
	head->next=NULL;
	return;
}
void del(struct LinkedList *p){ //删除p->next 
	p->next=p->next->next;
	return;
}
void debug(){
	struct LinkedList *p=head->next;
	while(p!=NULL){
		printf("%d ",p->val);
		p=p->next;
	}
	//getchar();
	//printf("\n");
}


int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",r+i);
	}
	sort(r+1,r+1+n);
	/*构造链表*/
	/*不然for(;;)中遍历used[i]时间复杂度太大无法接受*/
	init();
	struct LinkedList *p=head;
	for(int i=1;i<=n;i++){
		p->next=(LinkedList*)malloc(sizeof(LinkedList));
		p=p->next;
		p->val=r[i];
	}
	p->next=NULL;
	
	/*不再使用used，而是求出一个序列删除一个*/
	struct LinkedList *pre=head;
	p=head->next;
	for(;;){
		pre=head;
		p=head->next;
		int last=0;
		while(p!=NULL){
			if(p->val>last){
				last=p->val;
				used_tot++;
				del(pre);
			}
			pre=p;
			p=p->next;
			
			
		}
		debug();
		ans++;
		if(used_tot==n)break;
	}
	//for(int i=1;i<=n;i++){
	//	printf("%d ",r[i]);
	//}
	//原解如下 
	/*for(;;){
		int last=0;
		for(int i=1;i<=n;i++){
			if(!used[i] && r[i]>last){
				last=r[i];
				used[i]=1;used_tot++;
				//printf("%d ",r[i]);
			}
		}
		ans++;
		if(used_tot==n)break;
	}*/
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
