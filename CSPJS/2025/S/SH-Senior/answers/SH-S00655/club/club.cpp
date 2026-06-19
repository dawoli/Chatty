#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+10;

struct st{
	int bua;
	int bub;
	int buc;
	int maxl;
}stud[N];
int numb[4];
int t=0;
deque<int> nua,nub,nuc;

int cmp(st a,st b){
	return a.maxl<b.maxl;
}

int checka(st a,st b){
	int ama=max(a.bub,a.buc);
	int bma=max(b.bub,b.buc);
	if(a.bua+bma>b.bua+ama){
		if(bma == b.bub){
			return 1;
		}else{
			return 2;
		}
	}else{
		if(ama == a.bub){
			return 3;
		}else{
			return 4;
		}
	}
}
int checkb(st a,st b){
	int ama=max(a.bua,a.buc);
	int bma=max(b.bua,b.buc);
	if(a.bub+bma>b.bub+ama){
		if(bma == b.bua){
			return 1;
		}else{
			return 2;
		}
	}else{
		if(ama == a.bua){
			return 3;
		}else{
			return 4;
		}
	}
}
int checkc(st a,st b){
	int ama=max(a.bua,a.bub);
	int bma=max(b.bua,b.bub);
	if(a.buc+bma>b.buc+ama){
		if(bma == b.bub){
			return 1;
		}else{
			return 2;
		}
	}else{
		if(ama == a.bub){
			return 3;
		}else{
			return 4;
		}
	}
}

int pusha(int q){
	deque<int> linshi;
	if(nua.front()<q){
		nua.push_front(q);
	}else{
		while(!nua.empty() && nua.back()<q){
			
			linshi.push_back(nua.back());
			nua.pop_back();
		}
		nua.push_back(q);
		while(!linshi.empty()){
			nua.push_back(linshi.back());
			linshi.pop_back();
		}
	}
}

int pushb(int q){
	deque<int> linshi;
	if(nub.front()<q){
		nub.push_front(q);
	}else{
		while(!nub.empty() && nub.back()<q){
			linshi.push_back(nub.back());
			nub.pop_back();
		}
		nub.push_back(q);
		while(!linshi.empty()){
			nub.push_back(linshi.back());
			linshi.pop_back();
		}
	}
}

int pushc(int q){
	deque<int> linshi;
	if(nuc.front()<q){
		nuc.push_front(q);
	}else{
		while(!nuc.empty() && nuc.back()<q){
			linshi.push_back(nuc.back());
			nuc.pop_back();
		}
		nuc.push_back(q);
		while(!linshi.empty()){
			nuc.push_back(linshi.back());
			linshi.pop_back();
		}
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(stud,0,sizeof(stud));
		memset(numb,0,sizeof(numb));
		while(!nua.empty()){
			nua.pop_front();
		}
		while(!nub.empty()){
			nub.pop_front();
		}
		while(!nuc.empty()){
			nuc.pop_front();
		}
		int num=0,ans=0,maxnum,maxpl;
		cin>>num;
		for(int i=0;i<num;i++){
			cin>>stud[i].bua>>stud[i].bub>>stud[i].buc;
			maxnum = max(stud[i].bua,stud[i].bub);
			stud[i].maxl= max(maxnum,stud[i].buc);
		}
		sort(stud,stud+num,cmp);
		for(int i=0;i<num;i++){
			if(stud[i].maxl==stud[i].bua){
				if(numb[0]<num/2){
					ans+=stud[i].bua;
					nua.push_back(i);
					numb[0]++;
				}else{
					int che = checka(stud[i],stud[nua.front()]);
					if(che == 1){
						nua.push_back(i);
						ans-=stud[nua.front()].bua;
						ans+=stud[nua.front()].bub;
						pushb(nua.front());
						numb[1]++;
						nua.pop_front();
						ans+=stud[i].bua;
					}
					else if(che == 2){
						nua.push_back(i);
						ans-=stud[nua.front()].bua;
						ans+=stud[nua.front()].buc;
						pushc(nua.front());
						numb[2]++;
						nua.pop_front();
						ans+=stud[i].bua;
					}else{
						if(stud[i].bub>stud[i].buc){
						if(numb[1]<num/2){
							ans+=stud[i].bub;
							numb[1]++;
						}else{
							ans+=stud[i].buc;
							numb[2]++;
						}
					}else{
						if(numb[2]<num/2){
							ans+=stud[i].buc;
							numb[2]++;
						}else{
							ans+=stud[i].bub;
							numb[1]++;
							}
						}
						}	
					}
				}
			else if(stud[i].maxl==stud[i].bub){
				if(numb[1]<num/2){
					ans+=stud[i].bub;
					nub.push_back(i);
					numb[1]++;
				}else{
					int che = checkb(stud[i],stud[nub.front()]);
					if(che == 1){
						nua.push_back(i);
						ans-=stud[nub.front()].bub;
						ans+=stud[nub.front()].bua;
						pusha(nub.front());
						numb[0]++;
						nub.pop_front();
						ans+=stud[i].bub;
					}
					else if(che == 2){
						nua.push_back(i);
						ans-=stud[nub.front()].bub;
						ans+=stud[nub.front()].buc;
						pushc(nub.front());
						numb[2]++;
						nub.pop_front();
						ans+=stud[i].bub;
					}else{			
					if(stud[i].bua>stud[i].buc){
						if(numb[0]<num/2){
							ans+=stud[i].bua;
							numb[0]++;
						}else{
							ans+=stud[i].buc;
							numb[2]++;
						}
					}else{
						if(numb[2]<num/2){
							ans+=stud[i].buc;
							numb[2]++;
						}else{
							ans+=stud[i].bua;
							numb[0]++;
						}
					}
					}
				}
			}
			else if(stud[i].maxl==stud[i].buc){
				if(numb[2]<num/2){
					ans+=stud[i].buc;
					nuc.push_back(i);
					numb[2]++;
				}else{
					int che = checkc(stud[i],stud[nuc.front()]);
					if(che == 1){
						nuc.push_back(i);
						ans-=stud[nuc.front()].buc;
						ans+=stud[nuc.front()].bub;
						pushb(nuc.front());
						numb[1]++;
						nuc.pop_front();
						ans+=stud[i].buc;
					}
					else if(che == 2){
						nuc.push_back(i);
						ans-=stud[nuc.front()].buc;
						ans+=stud[nuc.front()].bua;
						pusha(nuc.front());
						numb[0]++;
						nuc.pop_front();
						ans+=stud[i].buc;
					}else{
						if(stud[i].bub>stud[i].bua){
						if(numb[1]<num/2){
							ans+=stud[i].bub;
							numb[1]++;
						}else{
							ans+=stud[i].bua;
							numb[0]++;
						}
					}else{
						if(numb[0]<num/2){
							ans+=stud[i].bua;
							numb[0]++;
						}else{
							ans+=stud[i].bub;
							numb[1]++;
						}
					}
					}						
				}
			}
			
		}
		cout<<ans<<endl;
	}
	
	
	return 0;
}
