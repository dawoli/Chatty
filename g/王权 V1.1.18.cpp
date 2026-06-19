#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#include<windows.h>
#include<conio.h>
#define cls system("cls")
#define iv inline void
#define set1 SetConsoleTextAttribute
#define set2 GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY
#define sred FOREGROUND_RED
#define sgreen FOREGROUND_GREEN
#define sblue FOREGROUND_BLUE
#define set set1(set2 | sred | sgreen | sblue)
using namespace std;
using namespace __gnu_pbds;
//宗教，民众，军队，财富！ 
struct data{
	string a;//事件过程
	int a1,a2,a3,a4;//Y
	int b1,b2,b3,b4;//N
	string b,c;//b为Y得到技能名称,c为N得到技能名称 
}x[1005];
struct data2{
	int a,b;//起始年，驾崩年 
	string s;//名字 
};
struct data3{
	int a,b;//起始年，结束年
	string s;//我方名字
	int w;//是否胜利 
};
struct data_email{
	string a,b;//发送者、内容 
};
#define SIZe 17
int ra[SIZe*2+1];
int year=1,year2=1,qaq=0,qaq2=0,textspeed=3,Flag=0;
int auto_read=0,auto_file=0;
string version="V1.1.18";
data2 gq[1005];
data3 gq2[1005];
vector<string> banben;//可读版本列表 
vector<string> ach;//普通模式成就列表 
vector<string> skills_2nd;//普通模式技能列表 
vector<string> emails;//收到的邮件 
gp_hash_table<string,string> skills;//普通模式技能效果
gp_hash_table<string,bool> ach_judge;//成就完成判断 
gp_hash_table<string,string> ach_introduce;//成就介绍 
gp_hash_table<string,vector<string> > achs;//成就分类 
gp_hash_table<string,data_email> email_text;//根据标题为key储存发送者与内容
gp_hash_table<string,bool> email_judge;//根据标题为key储存是否已读
template <typename T>
inline string change(T a){stringstream ss;string s;ss.clear();ss.str("");ss<<a;ss>>s;return s;}
iv init()
{
	//可读版本 
	banben.push_back("V1.1.18");
	//普通&AI模式事件 
	x[1]=data{"大臣：国王，敌国的军队来攻打我们了。(Y:出军;N:没有动静)",0,-5,-10,-10,0,-15,0,0,"",""};
	x[2]=data{"传信人：我们的内部出现了内奸，散布虚假消息。(Y:解决;N:没有动静)",10,0,-5,0,-20,-10,0,0,"",""};
	x[3]=data{"大臣：在山下发现金矿。(Y:挖掘;N:没听见)",10,-10,-10,20,0,-10,0,0,"",""};
	x[4]=data{"大臣：我们可以下发民众调查，加善百姓生活。(Y:接受;N:不接受)",5,10,0,-10,0,-10,-5,5,"",""};
	x[5]=data{"军师：敌人可能要来进攻我们了，我们需要操练军队。(Y:接受;N:不接受)",5,-5,20,-10,0,0,0,0,"",""};
	x[6]=data{"传信人：民间出现了很多盗贼。我们最好解决？(Y:解决;N:没有动静)",0,20,-5,-10,0,-5,0,-5,"",""};
	x[7]=data{"大臣：建议造学校，普及知识。(Y:建造;N:没有动静)",10,10,0,-10,-5,0,-5,10,"",""};
	x[8]=data{"马戏团老板：我们能到您的城市演出吗？(Y:能;N:拒绝)",0,10,0,-20,0,-10,5,10,"",""};
	x[9]=data{"大臣：城市污染严重，可栽树否？(Y:栽树;N:没有动静)",-5,10,10,-10,0,-10,0,5,"",""};
	x[10]=data{"巫师：大人，我这儿有灵丹妙药。(Y:售卖;N:拒绝)",-5,10,0,-10,0,-5,-10,0,"",""};
	x[11]=data{"魔法师：国王，我能赐予您一种能力。(Y:接受;N:拒绝)",0,0,-15,0,0,0,0,0,"逃避",""};
	x[12]=data{"魔法师：我希望人间平安。(Y:接受;N:拒绝)",0,0,0,-25,0,0,0,0,"平安",""};
	x[13]=data{"魔法师：相反的魔法总是令人喜爱。(Y:认同;N:不认同)",-15,0,0,0,0,0,0,0,"倒置",""};
	x[14]=data{"大臣：我认为我们可以加进人才。(Y:同意;N:拒绝)",0,20,0,-10,0,-10,0,0,"",""};
	x[15]=data{"传信人：民间的传染病越加严重。(Y:解决;N:没有动静)",10,10,-10,-20,0,-20,-10,0,"",""};
	x[16]=data{"天文学家：我预测这几日天气状况不佳。(Y:认同;N:不认同)",0,10,-10,0,0,0,0,0,"",""};
	x[17]=data{"传信人：鼠疫导致民间人心惶惶。(Y:解决;N:没有动静)",0,20,0,-10,0,-15,-5,0,"",""};
	//普通&AI模式技能列表 
	skills_2nd.push_back("逃避");
	skills_2nd.push_back("平安");
	skills_2nd.push_back("倒置");
	//普通&AI模式技能介绍 
	skills["逃避"]="躲过这次选择，不接受也不拒绝";
	skills["平安"]="使任一属性回到50 (可选择)"; 
	skills["倒置"]="使做出选择后获得的增益倒置 (不包括获得、使用技能)，直到下一次使用倒置为止";
	//成就列表 
	ach.push_back("初登王位");
	ach.push_back("多重加害");
	ach.push_back("百寿");
	ach.push_back("竞争者");
	ach.push_back("两败俱伤");
	ach.push_back("常年争执");
	ach.push_back("殊途同归");
	ach.push_back("保持同步");
	ach.push_back("名字问题");
	ach.push_back("隐藏地域");
	//成就介绍
	ach_introduce["初登王位"]="第一次开始普通模式";
	ach_introduce["多重加害"]="同时因为多项属性而结束游戏";
	ach_introduce["百寿"]="一个人物活到100岁";
	ach_introduce["竞争者"]="第一次开始A.I.对战";
	ach_introduce["两败俱伤"]="因为双方同时死亡而结束游戏";
	ach_introduce["常年争执"]="一个人物与A.I.连续对战30年";
	ach_introduce["殊途同归"]="在若干回合后双方的数据重回一样";
	ach_introduce["保持同步"]="连续5回合与A.I.选择一样";
	ach_introduce["名字问题"]="......你真的以为我会让你使用它？";
	ach_introduce["隐藏地域"]="你是怎么发现这儿的？"; 
	//......然而成就的展示是按获取方式分。
	achs["普通模式"].push_back("初登王位"); 
	achs["普通模式"].push_back("多重加害");
	achs["普通模式"].push_back("百寿");
	achs["A.I.对战"].push_back("竞争者");
	achs["A.I.对战"].push_back("两败俱伤");
	achs["A.I.对战"].push_back("常年争执");
	achs["A.I.对战"].push_back("殊途同归");
	achs["A.I.对战"].push_back("保持同步");
	achs["隐藏成就"].push_back("名字问题");
	achs["隐藏成就"].push_back("隐藏地域");
	//邮件内容
	email_text["游戏介绍-普通模式"]=data_email{"紫陰花",
	"在这个游戏中，你需要控制一名君王来应对每一年所发生的事件，作出相应的对答。\n每一次相应的对答可以选择Y或N，你的国家拥有四种属性，不同的对答会造成每个属性的相应加减。\n四种属性分别是：宗教,民众,军队,财富。\n每个属性的初始状态都为50点。通过选择会加减属性，当一个属性<=0或>=100时，游戏结束，愤怒的臣民会杀掉你。\n你还拥有一项技能，这需要你在游戏中获得。技能是一次性的，得到新的技能会覆盖原技能。有技能时可以按S(Skill)触发效果。\n你的游戏目标是，活得尽量久。\n"}; 
	email_text["游戏介绍-A.I.对战"]=data_email{"紫陰花",
	"在普通模式的基础上，你需要与一个A.I.对战，你与其面对相同的问题而做出选择，最后活下的人胜利。"}; 
	email_text["欢迎来到王权"]=data_email{"紫陰花",
	"感谢您游玩王权！\n游戏制作者：紫陰花\n游戏团队：https://www.luogu.com.cn/team/23723"};
	email_text["hide1"]=data_email{"???","你为什么会到这儿？"};
	email_text["hide2"]=data_email{"???","你不应该来到这儿。离开。"};
	email_text["Hide1"]=data_email{"","The author thinks that you are too YOUNG too SIMPLE."};
	email_text["hacker1"]=data_email{"","(铃铃铃......)"};
	email_text["hacker2"]=data_email{"","你在这了。"};
	email_text["hacker3"]=data_email{"","如果有人玩到这个页面，请麻烦告知作者。"};
	email_text["hacker4"]=data_email{"","但恐怕......你只是一个肮脏的黑客吧？"};
}
iv say(string say1,int say2);
iv rs(){for(int i=1;i<=SIZe;i++)ra[i]=i;for(int i=SIZe+1;i<=SIZe*2;i++)ra[i]=rand()%SIZe+1;random_shuffle(ra+1,ra+1+SIZe*2);}
iv di_box(string title,string s1,string s2);
iv diq(string s){di_box("","",s);}
iv hacker(){ifstream fin("WDGaster.txt");char c;int ci=0;fin>>ci;ci++;fin.close();
	ofstream fout("WDGaster.txt");fout<<ci;fout.close();if(ci>1){if(ci<=6)cls,diq("你已经来了 "+change(ci)+" 次了。"),c=getch();cls;if(ci==2) diq("还不知足吗？");if(ci==3) diq("你知道，你在尝试修改代码。");
		if(ci==4) diq("蠢蛋，代码都改不动。");if(ci==5) diq("如果你看到了这条消息，就代表你不是个 OIer。");if(ci==6) diq("你的耐心......可真让我吃惊啊。");if(ci>6) diq("你就没有更重要的事情去做吗？");c=getch();}
	else for(int i=1;i<=4;i++) say("hacker"+change(i),2);exit(0);}
iv print(string a){for(int i=0;i<a.size();i++){putchar(a[i]);Sleep(textspeed);}}
iv print2(string a,int b){for(int i=0;i<a.size();i++){putchar(a[i]);Sleep(b);}}
iv start();
iv game();
iv ai_game();
iv red(string u){set1(set2 | sred);print(u);set;}
iv blue(string u){set1(set2 | sblue);print(u);set;}
iv red2(string u,int w){set1(set2 | sred);print2(u,w);set;}
iv green(string u){set1(set2 | sgreen);print(u);set;}
iv yellow(string u){set1(set2 | sred | sgreen);print(u);set;}
iv cyan(string u){set1(set2 | sgreen | sblue);print(u);set;}
iv pink(string u){set1(set2 | sred | sblue);print(u);set;}
iv rainbow(string u){for(int i=0;i<u.size();i++){int rainbo=rand()%7*rand()%7+1;switch(rainbo){case 1:print(change(u[i]));break;case 2:red(change(u[i]));break;case 3:green(change(u[i]));break;case 4:blue(change(u[i]));break;case 5:yellow(change(u[i]));break;case 6:cyan(change(u[i]));break;case 7:pink(change(u[i]));break;}} }
iv achieve(string u)
{
	if(u=="初登王位")
	{
		pink("+------------------+\n");
		pink("|获得成就：初登王位|\n");
		pink("|第一次开始普通模式|\n");
		pink("+------------------+\n");
	}
	if(u=="多重加害")
	{
		pink("+--------------------------+\n");
		pink("|获得成就：多重加害        |\n");
		pink("|同时因为多项属性而结束游戏|\n");
		pink("+--------------------------+\n");
	}
	if(u=="百寿")
	{
		pink("+-----------------+\n");
		pink("|获得成就：百寿   |\n");
		pink("|一个人物活到100岁|\n");
		pink("+-----------------+\n");
	}
	if(u=="竞争者")
	{
		pink("+------------------+\n");
		pink("|获得成就：竞争者  |\n");
		pink("|第一次开始A.I.对战|\n");
		pink("+------------------+\n");
	}
	if(u=="两败俱伤")
	{
		pink("+--------------------------+\n");
		pink("|获得成就：两败俱伤        |\n");
		pink("|因为双方同时死亡而结束游戏|\n");
		pink("+--------------------------+\n");
	}
	if(u=="常年争执")
	{
		pink("+--------------------------+\n");
		pink("|获得成就：常年争执        |\n");
		pink("|一个人物与A.I.连续对战30年|\n");
		pink("+--------------------------+\n");
	}
	if(u=="殊途同归")
	{
		pink("+------------------------------+\n");
		pink("|获得成就：殊途同归            |\n");
		pink("|在若干回合后双方的数据重回一样|\n");
		pink("+------------------------------+\n");
	}
	if(u=="保持同步")
	{
		pink("+-----------------------+\n");
		pink("|获得成就：保持同步     |\n");
		pink("|连续5回合与A.I.选择一样|\n");
		pink("+-----------------------+\n");
	}
	ach_judge[u]=1;
}
int long_di_box=50;
iv di_box(string title,string s1,string s2) //dialog box
{
	int kkk=20;
	int c=0,maxnkkk=-1;
	for(int i=0;i<s2.size();i++)
	{
		if(s2[i]=='\n') c=0;
		else c++;
		maxnkkk=max(maxnkkk,c);
	}
	kkk=max(kkk,maxnkkk);
	print("+"+string(kkk,'-')+"+\n");
	if(title.size()!=0)
		print("|"+title+string(kkk-title.size(),' ')+"|\n");
	if(s1.size()!=0)
	{
		print("|");
		cyan(s1);
		print(":"+string(kkk-1-s1.size(),' ')+"|\n");	
	}
	int s2u=0,summ=0;
	for(int i=0;i<s2.size();i++)
	{
		if(summ==kkk)
			print("|\n"),summ=0,s2u=0;
		if(s2u==0)
			print("|"),s2u=1;
		if(s2[i]!='\n')
			putchar(s2[i]),summ++;
		else
			print(string(kkk-summ,' ')),summ=kkk;
	}
	print(string(kkk-summ,' '));
	print("|\n+"+string(kkk,'-')+"+\n");
}
iv say(string say1,int say2)
{
	char c;
	cls;
	if(say2==1)
		di_box("",email_text[say1].a,email_text[say1].b);
	else
		diq(email_text[say1].b);
	c=getch();
}
iv num(int a)
{
	if(a>=25 and a<=75) set1(set2 | sgreen);
	if((a<25 and a>0) or (a>75 and a<100)) set1(set2 | sred | sgreen);
	if(a<=0 or a>=100)	set1(set2 | sred);
	print(change(a));set;
}
inline int div_int(int a,int b){return b==0?0:a/b;}
iv cho(int a){if(a>0) green("增加");if(a<0) red("减少");if(a==0) print("无");}
iv email() //邮件 
{
	cls;
	for(int i=emails.size()-1;i>=0;i--)
	{
		int &kkk=long_di_box;
		print("+"+string(kkk,'-')+"+\n");
		print("|信件"+change(i+1)+string(kkk-4-change(i+1).size(),' ')+"|\n");
		if(email_judge[emails[i]]==0)
		{
			print("|");
			red("未读");
			print(string(kkk-4,' ')+"|\n");
		}
		print("|发送者:");
		cyan(email_text[emails[i]].a);
		print(string(kkk-7-email_text[emails[i]].a.size(),' ')+"|\n");
		print("|标题:");
		yellow(emails[i]);
		print(string(kkk-5-emails[i].size(),' ')+"|\n");
		print("+"+string(kkk,'-')+"+\n");
	}
	cyan("输入信件编号阅读信件;输入0退出(需按回车)\n");
	int c;
	cin>>c;
	while(c<0 or c>emails.size()) cin>>c;
	if(c==0)
	{
		cls;
		start(); 
	}
	else
	{
		cls;
		di_box(emails[c-1],email_text[emails[c-1]].a,email_text[emails[c-1]].b);
		email_judge[emails[c-1]]=1;
		cyan("按1退出\n");
		char c=getch();
		while(c!='1') c=getch();
		cls;
		email();
	}
} 
iv file(int hi) //存档 
{
	/*
	version
	year year2 qaq qaq2 textspeed auto_read auto_file 
	gq[1].a gq[1].b gq[1].s
	...
	gq[qaq].a gq[qaq].b gq[qaq].s
	gq2[1].a gq2[1].b gq2[1].s gq2[1].w
	...
	gq2[qaq2].a gq2[qaq2].b gq2[qaq2].s gq2[qaq2].w
	emails.size()
	emails[0]
	...
	emails[emails.size()-1]
	email_judge[0]
	...
	email_judge[emails.size()-1]
	*/
	char c='N';
	if(hi==0)
	{
		red("你确定要存档？将会覆盖原有存档(Y确定，N退出)\n");
		c=getch();
		while(c!='Y' and c!='N') c=getch();
	}
	if(c=='Y' or hi==1)
	{
		ofstream fout("reignsfile.txt");
		fout<<version<<endl;
		fout<<year<<' '<<year2<<' '<<qaq<<' '<<qaq2<<' '<<textspeed<<' '<<auto_read<<' '<<auto_file<<'\n';
		for(int i=1;i<=qaq;i++)
			fout<<gq[i].a<<' '<<gq[i].b<<' '<<gq[i].s<<'\n';
		for(int i=1;i<=qaq2;i++)
			fout<<gq2[i].a<<' '<<gq2[i].b<<' '<<gq2[i].s<<' '<<gq2[i].w<<'\n';
		fout<<endl<<emails.size()<<endl;
		for(int i=0;i<emails.size();i++)
			fout<<emails[i]<<' ';
		fout<<endl;
		for(int i=0;i<emails.size();i++)
			fout<<email_judge[emails[i]]<<' '; 
		fout<<endl;
		fout.close();
		
		ofstream fout2("reignsach.txt");
		for(int i=0;i<ach.size();i++)
			fout2<<ach_judge[ach[i]]<<' ';
		fout2.close();
		
		if(hi==0)
		{
			green("存档成功！");
			Sleep(2000);
		}
	}
	if(hi==0)
	{
		cls;
		start();
	}
}
iv readfile(int hi) //读档 
{
	char c='N';
	if(hi==0)
	{
		red("你确定要读档？将会覆盖原有存档(Y确定，N退出)\n");
		c=getch();
		while(c!='Y' and c!='N') c=getch();
	}
	if(c=='Y' or hi==1)
	{
		string guyutxdy;
		ifstream fin("reignsfile.txt");
		fin>>guyutxdy;//版本占位符 
		fin>>year>>year2>>qaq>>qaq2>>textspeed>>auto_read>>auto_file;
		for(int i=1;i<=qaq;i++)
			fin>>gq[i].a>>gq[i].b>>gq[i].s;
		for(int i=1;i<=qaq2;i++)
			fin>>gq2[i].a>>gq2[i].b>>gq2[i].s>>gq2[i].w;
		int kkkk;
		fin>>kkkk;
		emails.clear();
		for(int i=0;i<kkkk;i++)
		{
			string sr1;
			fin>>sr1;
			emails.push_back(sr1);
		}
		for(int i=0;i<kkkk;i++)
		{
			bool sr1;
			fin>>sr1;
			email_judge[emails[i]]=sr1;
		}
		fin.close();
		
		ifstream fin2("reignsach.txt");
		for(int i=0;i<ach.size();i++)
			fin2>>ach_judge[ach[i]];
		fin2.close();
		
		if(hi==0)
		{
			green("读档成功！");
			Sleep(2000);
		}
	}
	if(hi==1) Flag=1;
	else 
	{
		cls;
		start();
	}
}
iv statistics() //统计 
{
	yellow("普通模式：\n"); 
	if(qaq==0) cyan("尚未有人坐上王座\n\n");
	else
	{
		cyan("到目前为止，有 ");
		print(change(qaq));
		cyan(" 个君王\n");
		int maxn=-1,maxnn;
		for(int i=1;i<=qaq;i++)
		{
			print(change(gq[i].a));
			cyan(" 年至 ");
			print(change(gq[i].b));
			cyan(" 年，为君王 ");
			yellow(gq[i].s);
			putchar('\n');
			if(maxn<gq[i].b-gq[i].a+1)
				maxn=gq[i].b-gq[i].a+1,maxnn=i;
		}
		cyan("最长统治者为 ");
		yellow(gq[maxnn].s);
		cyan(" ，统治了 ");
		print(change(maxn));
		cyan(" 年\n\n");
	}
	yellow("A.I.对战：\n"); 
	if(qaq2==0) cyan("尚未有人开始争夺\n\n");
	else
	{
		cyan("到目前为止，有 ");
		print(change(qaq2));
		cyan(" 场争夺\n");
		int maxn=-1,maxnn;
		for(int i=1;i<=qaq2;i++)
		{
			print(change(gq2[i].a));
			cyan(" 年至 ");
			print(change(gq2[i].b));
			cyan(" 年，为君王 ");
			yellow(gq2[i].s);
			cyan(" 与对方争夺，结果为");
			if(gq2[i].w==0)
				red("失败\n");
			if(gq2[i].w==1)
				green("成功\n");
			if(gq2[i].w==2)
				yellow("平局\n");
			if(maxn<gq2[i].b-gq2[i].a+1)
				maxn=gq2[i].b-gq2[i].a+1,maxnn=i;
		}
		cyan("最长时间争夺者为 ");
		yellow(gq2[maxnn].s);
		cyan(" ，争夺了 ");
		print(change(maxn));
		cyan(" 年\n\n");
	}
	cyan("按1退出\n");
	char c=getch();
	while(c!='1') c=getch();
	cls;
	start(); 
}
iv journal() //更新日志 
{
	yellow("V1.0.0:");pink("基础游戏设施 (2019.11.29)\n");
	yellow("V1.0.1:");pink("增加更新日志 设置 存档 读档 (2019.11.30)\n");
	yellow("V1.0.2:");pink("增加2条新的事件 (2019.12.2)\n");
	yellow("V1.0.3:");pink("增加自动读档 游戏公告 (2019.12.4)\n");
	yellow("V1.0.4:");pink("增加自动存档 修正部分文本 (2019.12.5)\n");
	yellow("V1.0.5:");pink("增加彩色字体 修复自动存档 (2019.12.7)\n");
	yellow("V1.0.6:");pink("修改统计 (2019.12.7)\n");
	yellow("V1.0.7:");pink("增加1条新的事件 (2019.12.9)\n");
	yellow("V1.1.0:");pink("增加技能 成就(未完工) (2019.12.11)\n");
	yellow("V1.1.1:");pink("修改技能 平安 增加技能 倒置 修复成就 (2019.12.14)\n");
	yellow("V1.1.2:");pink("增加2条成就 (2019.12.14)\n");
	yellow("V1.1.3:");pink("增加模式沦陷战役 开启沦陷战役-童话门 (2020.1.1)\n");
	yellow("V1.1.4:");pink("开启沦陷战役-世界门 (2020.1.4)\n");
	yellow("V1.1.5:");pink("邮件系统（未完工） (2020.1.15)\n");
	yellow("V1.1.6:");pink("邮件系统（将近完工） (2020.1.17)\n");
	yellow("V1.1.7:");pink("开启沦陷战役-人心门 (2020.1.24)\n");
	yellow("V1.1.8:");pink("修改沦陷战役-人心门 (2020.1.25)\n");
	yellow("V1.1.9:");pink("削弱沦陷战役-人心门强度 增加彩蛋 (2020.1.26)\n");
	yellow("V1.1.10:");pink("削弱沦陷战役-人心门 沦陷战役-世界门强度 (2020.1.28)\n");
	yellow("V1.1.11:");pink("制作沦陷战役-我们门（未完工） WARNING!!!!!!!!!!!!!!! (2020.2.5)\n");
	yellow("V1.1.12:");pink("更新成就（是的，这个人一直在拖更） (2020.2.28)\n");
	yellow("V1.1.13:");pink("暂时关闭了沦陷战役的模式，而且这个模式可能会删除 (2020.4.24)\n");
	yellow("V1.1.14:");pink("再见，沦陷战役（开始制作A.I.对战） (2020.4.28)\n");
	yellow("V1.1.15:");pink("开启 A.I.对战 (2020.5.9)\n");
	yellow("V1.1.16:");pink("优化 A.I. 的判断（关于 倒置 考虑得更具体，当选择Y可获得技能时特别判断） (2020.5.19)\n");
	yellow("V1.1.17:");pink("增加2条成就，修复 A.I.对战 双方同时死亡的BUG（转化成了一个成就） (2020.5.22)\n");
	yellow("V1.1.18:");pink("增加2条成就 (2020.6.2)\n");
	cyan("\n按1退出\n");
	char c=getch();
	while(c!='1') c=getch();
	cls;
	start(); 
}
iv setting() //设置 
{
	cyan("1.文本速度\n");
	cyan("2.自动读档（打开exe文件时）\n");
	cyan("3.自动存档（游戏结束后）\n");
	cyan("4.退出\n");
	char c=getch();
	while(c<'1' or c>'4') c=getch();
	if(c=='1')
	{
		cyan("输入文本速度 (目前一个汉字为 ");
		cyan(change(textspeed));
		cyan(" ms)\n");
		scanf("%d",&textspeed);
		cls;
		setting();
	}
	if(c=='2')
	{
		cyan("是否自动读档？ (打开exe文件时，1为是，0为否，目前为 ");
		cyan(change(auto_read));
		cyan(" )\n");
		scanf("%d",&auto_read);
		if(auto_read!=0 and auto_read!=1) auto_read=0;
		cls;
		setting();
	}
	if(c=='3')
	{
		cyan("是否自动存档？ (一场游戏后，1为是，0为否，目前为 ");
		cyan(change(auto_file));
		cyan(" )\n");
		scanf("%d",&auto_file);
		if(auto_file!=0 and auto_file!=1) auto_file=0;
		cls;
		setting();
	}
	if(c=='4'){cls;start();} 
}
iv achievement_name_judge(string &qwq)
{
	if(ach_judge[qwq]==0) red(string(qwq.size(),'?'));
	else green(qwq);
}
iv achievement() //成就 
{
	cyan("成就名是全为?的，表示未完成;绿色表示已完成\n\n");
	int usize=achs["普通模式"].size();
	yellow("普通模式:\n");
	for(int i=0;i<usize;i++)
		green("> "),achievement_name_judge(achs["普通模式"][i]),print(":"),yellow(ach_introduce[achs["普通模式"][i]]),putchar('\n');
	putchar('\n');
	usize=achs["A.I.对战"].size();
	yellow("A.I.对战:\n");
	for(int i=0;i<usize;i++)
		green("> "),achievement_name_judge(achs["A.I.对战"][i]),print(":"),yellow(ach_introduce[achs["A.I.对战"][i]]),putchar('\n');
	putchar('\n');
	usize=achs["隐藏成就"].size();
	yellow("隐藏成就:\n");
	for(int i=0;i<usize;i++)
		green("> "),achievement_name_judge(achs["隐藏成就"][i]),print(":"),yellow(ach_introduce[achs["隐藏成就"][i]]),putchar('\n');
	cyan("\n按1退出\n");
	char c=getch();
	while(c!='1') c=getch();
	cls;
	start(); 
}
iv reigns_data() //游戏机制资料 
{
	cyan("技能：\n\n");
	for(int i=0;i<skills_2nd.size();i++)
		pink(skills_2nd[i]+":"+skills[skills_2nd[i]]+"\n");
	cyan("\n按1退出\n");
	char c=getch();
	while(c!='1') c=getch();
	cls;
	start(); 
}
iv choose_game() //选择游戏 
{
	green("1.普通模式\n");
	green("2.A.I.对战\n");
	green("3.返回\n");
	cyan("\n请选择游戏模式：\n");
	char c=getch();
	while(!(c=='1' or c=='2' or c=='3' or c=='\\')) c=getch();
	cls;
	if(c=='1') game();
	if(c=='2') ai_game();
	if(c=='\\')
	{
		ach_judge["隐藏地域"]=1;
		say("hide1",1);
		say("hide2",1);
		cls;
		start();
	}
	if(c=='3')
	{
		cls;
		start();
	}
}
iv save_or_read() //选择存读档： 
{
	green("1.存档\n");
	green("2.读档\n");
	green("3.返回\n");
	cyan("\n请选择：\n");
	char c=getch();
	while(!(c=='1' or c=='2' or c=='3')) c=getch();
	cls;
	if(c=='1') file(0);
	if(c=='2') readfile(0);
	if(c=='3')
	{
		cls;
		start();
	}
}
iv start() //主界面 
{
	pink("The Game:");yellow("Reigns");pink(" (王权)\n");
	pink("Version:");yellow(version);pink("\n");
	pink("The Author:");yellow("紫陰花");pink(" (洛谷用户名)\n\n");
	if(Flag==0)
	{
		pink("正在检查您是否自动读档...\n");
		ifstream fin("reignsfile.txt");
		string op;
		fin>>op>>auto_read>>auto_read>>auto_read>>auto_read>>auto_read>>auto_read;
		fin.close();
		if(auto_read==0)
		{
			red("您没有自动读档或没有本地保存文件\n\n");
			emails.push_back("欢迎来到王权");
			emails.push_back("游戏介绍-普通模式");
			emails.push_back("游戏介绍-A.I.对战");
		}
		else
		{
			ifstream fin("reignsfile.txt");
			fin>>op;
			fin.close();
			int fLag=0;
			for(int i=0;i<banben.size();i++)
				if(op==banben[i])
				{
					fLag=1;
					break;
				}
			if(fLag==1)
			{
				readfile(1);
				red("已为您读档\n\n");
			}
			else
			{
				red("您的保存文件版本不兼容\n\n");
				emails.push_back("欢迎来到王权");
				emails.push_back("游戏介绍-普通模式");
			}
		}
		Flag=1;
	}
	int unreadnum=0;
	for(int i=0;i<emails.size();i++)
		if(email_judge[emails[i]]==0)
			unreadnum++;
	pink("1.开始游戏\n");
	pink("2.邮件");
	if(unreadnum>0)
		red("("+change(unreadnum)+")");
	pink("\n");
	pink("3.统计\n");
	pink("4.更新日志\n");
	pink("5.游戏设置\n");
	pink("6.存读档\n");
	pink("7.成就\n");
	pink("8.游戏机制资料\n");
	pink("X.退出游戏\n");
	char c=getch();
	while((c<'1' or c>'8') and c!='X') c=getch();
	cls;
	if(c=='1') choose_game();
	if(c=='2') email();
	if(c=='3') statistics();
	if(c=='4') journal();
	if(c=='5') setting();
	if(c=='6') save_or_read();
	if(c=='7') achievement();
	if(c=='8') reigns_data();
	if(c=='X') exit(0);
}
inline int inversion(int judge,int number)
{
	if(judge==0) return number;
	else return 0-number;
}
iv game() //普通模式 
{
	string name;
	string skill="无";
	int q=50,w=50,e=50,r=50;
	cyan("输入你的姓名（不含空格）：");
	cin>>name;
	if(name=="紫陰花")
	{
		ach_judge["名字问题"]=1;
		say("Hide1",2);cls;start();
		return;
	}
	cls;
	int k=year,j=1,inver=0;
	char c;
	rs();
	if(k==1)
		achieve("初登王位");
	while(1)
	{
		if(year-k+1==100 and ach_judge["百寿"]==0)
			achieve("百寿");
		print("君王:");yellow(name);putchar('\n');
		print("统治期 第 ");red(change(year));print(" 年\n");
		print("宗教:");num(q);putchar(' ');
		print("民众:");num(w);putchar(' ');
		print("军队:");num(e);putchar(' ');
		print("财富:");num(r);putchar('\n');
		print("技能:");cyan(skill);putchar('\n');
		if(inver==1) red("处于倒置状态\n");
		putchar('\n');
		
		if(q<=0 or q>=100 or w<=0 or w>=100 or e<=0 or e>=100 or r<=0 or r>=100) //死亡 
		{
			red("对你感到不满的臣民们一拥而上，杀死了你\n");
			gq[qaq+1]={k,year,name};
			qaq++;
			int guyu=0;
			if(q<=0 or q>=100) guyu++;
			if(w<=0 or w>=100) guyu++;
			if(e<=0 or e>=100) guyu++;
			if(r<=0 or r>=100) guyu++;
			if(guyu>=2 and ach_judge["多重加害"]==0)
				achieve("多重加害");
			Sleep(3000);
			if(auto_file==1) file(1);
			cls;
			start();
			return;
		}
		
		print("事件：\n");
		int v=ra[j];
		print(x[v].a);putchar('\n');
		
		print("Y:\n宗教:");cho(inversion(inver,x[v].a1));
		print("\n民众:");cho(inversion(inver,x[v].a2));
		print("\n军队:");cho(inversion(inver,x[v].a3));
		print("\n财富:");cho(inversion(inver,x[v].a4));
		putchar('\n');
		if(x[v].b!="") print("可得技能："),cyan(x[v].b),putchar('\n');
		
		print("N:\n宗教:");cho(inversion(inver,x[v].b1));
		print("\n民众:");cho(inversion(inver,x[v].b2));
		print("\n军队:");cho(inversion(inver,x[v].b3));
		print("\n财富:");cho(inversion(inver,x[v].b4));
		putchar('\n');
		if(x[v].c!="") print("可得技能："),cyan(x[v].c),putchar('\n');
		
		if(skill!="无") print("S:\n技能效果:\n"),cyan(skills[skill]);
		
		putchar('\n');
		
		c=getch(); 
		while(c!='Y' and c!='N' and ((c=='S' and skill=="无") or c!='S')) c=getch();
		if(c=='Y'){q+=inversion(inver,x[v].a1);w+=inversion(inver,x[v].a2);e+=inversion(inver,x[v].a3);r+=inversion(inver,x[v].a4);if(x[v].b!="") skill=x[v].b;} 
		if(c=='N'){q+=inversion(inver,x[v].b1);w+=inversion(inver,x[v].b2);e+=inversion(inver,x[v].b3);r+=inversion(inver,x[v].b4);if(x[v].c!="") skill=x[v].c;}
		if(c=='S')
		{
			if(skill=="平安") 
			{
				cyan("选择宗教按1、民众按2、军队按3、财富按4\n");
				c=getch();
				while(c<'1' or c>'4') c=getch();
				if(c=='1') q=50;
				if(c=='2') w=50;
				if(c=='3') e=50;
				if(c=='4') r=50;
				year--,j--;	
			}
			if(skill=="倒置") inver=1-inver,year--,j--;
			skill="无";
		}
		cls;
		year++;j++;
		if(j==SIZe*2+1)
			rs(),j=1;
	}
}
iv ai_game() //A.I.对战 
{
	string name;
	string skill="无",skill2="无";
	int q=50,w=50,e=50,r=50;
	int q2=50,w2=50,e2=50,r2=50;
	cyan("输入你的姓名（不含空格）：");
	cin>>name;
	if(name=="紫陰花")
	{
		ach_judge["名字问题"]=1;
		say("Hide1",2);cls;start();
		return;
	}
	cls;
	int k=year2,j=1,inver1=0,inver2=0;
	bool sttg=0;//殊途同归 成就判断 
	int bctb=0;//保持同步 成就判断 
	char c;
	rs();
	if(k==1)
		achieve("竞争者");
	while(1)
	{
		int tb_i_choose=0;
		if(sttg==0 and not(q==q2 and w==w2 and e==e2 and r==r2)) sttg=1;
		else if(sttg==1 and q==q2 and w==w2 and e==e2 and r==r2)
			if(ach_judge["殊途同归"]==0)
				achieve("殊途同归");
		if(bctb==5 and ach_judge["保持同步"]==0)
				achieve("保持同步");
		if(year2-k+1==30 and ach_judge["常年争执"]==0)
			achieve("常年争执");
		int ai_back=0;
		print("我方君王:");yellow(name);putchar('\n');
		print("敌方君王:");red("A.I.\n");
		print("争夺期 第 ");red(change(year2));print(" 年\n");
		yellow("我方:");print("宗教:");num(q);print(" 民众:");num(w);print(" 军队:");num(e);print(" 财富:");num(r);putchar('\n');
		red("敌方:");print("宗教:");num(q2);print(" 民众:");num(w2);print(" 军队:");num(e2);print(" 财富:");num(r2);putchar('\n');
		yellow("我方技能:");cyan(skill);putchar('\n');
		red("敌方技能:");cyan(skill2);putchar('\n');
		if(inver1==1) red("我方处于倒置状态\n");
		if(inver2==1) red("敌方处于倒置状态\n");
		putchar('\n');
		
		bool die_1=(q<=0 or q>=100 or w<=0 or w>=100 or e<=0 or e>=100 or r<=0 or r>=100);
		bool die_2=(q2<=0 or q2>=100 or w2<=0 or w2>=100 or e2<=0 or e2>=100 or r2<=0 or r2>=100);
		
		if(die_1 and die_2)
		{
			red("双方君王同时被杀\n");
			red("同时死亡，游戏平局\n");
			achieve("两败俱伤");
			gq2[qaq2+1]={k,year2,name,2};
			qaq2++;
			Sleep(3000);
			if(auto_file==1) file(1);
			cls;
			start();
			return;
		}
		if(die_1) //我方死亡 
		{
			red("对你感到不满的臣民们一拥而上，杀死了你\n");
			red("您先死亡，游戏失败\n");
			gq2[qaq2+1]={k,year2,name,0};
			qaq2++;
			Sleep(3000);
			if(auto_file==1) file(1);
			cls;
			start();
			return;
		}
		if(die_2) //敌方死亡 
		{
			red("敌方的统治失败，君王被杀\n");
			red("敌方死亡，游戏胜利\n");
			gq2[qaq2+1]={k,year2,name,1};
			qaq2++;
			Sleep(3000);
			if(auto_file==1) file(1);
			cls;
			start();
			return;
		}
		
		print("事件：\n");
		int v=ra[j];
		print(x[v].a);putchar('\n');
		
		print("Y:\n宗教:");cho(inversion(inver1,x[v].a1));
		print("\n民众:");cho(inversion(inver1,x[v].a2));
		print("\n军队:");cho(inversion(inver1,x[v].a3));
		print("\n财富:");cho(inversion(inver1,x[v].a4));
		putchar('\n');
		if(x[v].b!="") print("可得技能："),cyan(x[v].b),putchar('\n');
		
		print("N:\n宗教:");cho(inversion(inver1,x[v].b1));
		print("\n民众:");cho(inversion(inver1,x[v].b2));
		print("\n军队:");cho(inversion(inver1,x[v].b3));
		print("\n财富:");cho(inversion(inver1,x[v].b4));
		putchar('\n');
		if(x[v].c!="") print("可得技能："),cyan(x[v].c),putchar('\n');
		
		if(skill!="无") print("S:\n技能效果:\n"),cyan(skills[skill]);
		
		putchar('\n');
		
		c=getch(); 
		while(c!='Y' and c!='N' and ((c=='S' and skill=="无") or c!='S')) c=getch();
		if(c=='Y'){tb_i_choose=1,q+=inversion(inver1,x[v].a1);w+=inversion(inver1,x[v].a2);e+=inversion(inver1,x[v].a3);r+=inversion(inver1,x[v].a4);if(x[v].b!="") skill=x[v].b;} 
		if(c=='N'){tb_i_choose=2,q+=inversion(inver1,x[v].b1);w+=inversion(inver1,x[v].b2);e+=inversion(inver1,x[v].b3);r+=inversion(inver1,x[v].b4);if(x[v].c!="") skill=x[v].c;}
		if(c=='S')
		{
			if(skill=="平安") 
			{
				cyan("选择宗教按1、民众按2、军队按3、财富按4\n");
				c=getch();
				while(c<'1' or c>'4') c=getch();
				if(c=='1') q=50;
				if(c=='2') w=50;
				if(c=='3') e=50;
				if(c=='4') r=50;
				year2--,j--,ai_back=1;	
			}
			if(skill=="倒置") inver1=1-inver1,year2--,j--,ai_back=1;
			skill="无";
		}
		
		if(ai_back==0)
		{
			//A.I.判断部分
			int ai_a1=q2+inversion(inver2,x[v].a1),ai_b1=w2+inversion(inver2,x[v].a2),ai_c1=e2+inversion(inver2,x[v].a3),ai_d1=r2+inversion(inver2,x[v].a4);
			int ai_a2=q2+inversion(inver2,x[v].b1),ai_b2=w2+inversion(inver2,x[v].b2),ai_c2=e2+inversion(inver2,x[v].b3),ai_d2=r2+inversion(inver2,x[v].b4);
			int ai_max1=max(max(max(abs(ai_a1-50),abs(ai_b1-50)),abs(ai_c1-50)),abs(ai_d1-50));
			int ai_max2=max(max(max(abs(ai_a2-50),abs(ai_b2-50)),abs(ai_c2-50)),abs(ai_d2-50));
			int ai_o1=ai_a1+ai_b1+ai_c1+ai_d1,ai_o2=ai_a2+ai_b2+ai_c2+ai_d2;
			bool ai_s1=not(ai_a1<=0 or ai_a1>=100 or ai_b1<=0 or ai_b1>=100 or ai_c1<=0 or ai_c1>=100 or ai_d1<=0 or ai_d1>=100);
			bool ai_s2=not(ai_a2<=0 or ai_a2>=100 or ai_b2<=0 or ai_b2>=100 or ai_c2<=0 or ai_c2>=100 or ai_d2<=0 or ai_d2>=100);
			int choose;
			if(ai_s1 and ai_s2)
			{
				if(x[v].b!="")
				{
					if(skill2!="") choose=2;
					else
					{
						if(x[v].b=="逃避")
							if(abs(abs(ai_c1-50)-abs(e2-50))<10) choose=1;
							else choose=2;
						if(x[v].b=="平安")
							if(abs(abs(ai_d1-50)-abs(r2-50))<15) choose=1;
							else choose=2;
						if(x[v].b=="倒置")
							if(abs(abs(ai_a1-50)-abs(q2-50))<10) choose=1;
							else choose=2;
					}
				}
				else
				{
					if(ai_max1>ai_max2) choose=2;
					if(ai_max1<ai_max2) choose=1;
					if(ai_max1==ai_max2)
					{
						if(abs(ai_o1-200)>abs(ai_o2-200)) choose=2;
			 			if(abs(ai_o1-200)<abs(ai_o2-200)) choose=1;
						if(abs(ai_o1-200)==abs(ai_o2-200)) choose=rand()%2+1;
					}	
				}
			}
			if(ai_s1 and not(ai_s2)) choose=1;
			if(not(ai_s1) and ai_s2) choose=2;
			if(not(ai_s1) and not(ai_s2))
			{
				if(skill2=="逃避") skill2="无",choose=0;
				if(skill2=="倒置")
				{
					inver2=1-inver2;
					ai_a1=q2+inversion(inver2,x[v].a1),ai_b1=w2+inversion(inver2,x[v].a2),ai_c1=e2+inversion(inver2,x[v].a3),ai_d1=r2+inversion(inver2,x[v].a4);
					ai_a2=q2+inversion(inver2,x[v].b1),ai_b2=w2+inversion(inver2,x[v].b2),ai_c2=e2+inversion(inver2,x[v].b3),ai_d2=r2+inversion(inver2,x[v].b4);
					ai_max1=max(max(max(abs(ai_a1-50),abs(ai_b1-50)),abs(ai_c1-50)),abs(ai_d1-50));
					ai_max2=max(max(max(abs(ai_a2-50),abs(ai_b2-50)),abs(ai_c2-50)),abs(ai_d2-50));
					ai_o1=ai_a1+ai_b1+ai_c1+ai_d1,ai_o2=ai_a2+ai_b2+ai_c2+ai_d2;
					ai_s1=not(ai_a1<=0 or ai_a1>=100 or ai_b1<=0 or ai_b1>=100 or ai_c1<=0 or ai_c1>=100 or ai_d1<=0 or ai_d1>=100);
					ai_s2=not(ai_a2<=0 or ai_a2>=100 or ai_b2<=0 or ai_b2>=100 or ai_c2<=0 or ai_c2>=100 or ai_d2<=0 or ai_d2>=100);
					if(ai_s1 and ai_s2)
					{
						if(ai_max1>ai_max2) choose=2;
						if(ai_max1<ai_max2) choose=1;
						if(ai_max1==ai_max2)
						{
							if(abs(ai_o1-200)>abs(ai_o2-200)) choose=2;
				 			if(abs(ai_o1-200)<abs(ai_o2-200)) choose=1;
							if(abs(ai_o1-200)==abs(ai_o2-200)) choose=rand()%2+1;
						}	
					}
					if(ai_s1 and not(ai_s2)) choose=1;
					if(not(ai_s1) and ai_s2) choose=2;
					else choose=rand()%2+1;
				}
				else if(skill2=="平安")
				{
					int ai_flag=0,ai_now1=1,ai_now2=1,ai_ch1,ai_ch2;
					if(ai_a1<=0 or ai_a1>=100) ai_flag++,ai_ch1=1;
					if(ai_b1<=0 or ai_b1>=100) ai_flag++,ai_ch1=2;
					if(ai_c1<=0 or ai_c1>=100) ai_flag++,ai_ch1=3;
					if(ai_d1<=0 or ai_d1>=100) ai_flag++,ai_ch1=4;
					if(ai_flag>1) ai_now1=0;
					ai_flag=0;
					if(ai_a2<=0 or ai_a2>=100) ai_flag++,ai_ch2=1;
					if(ai_b2<=0 or ai_b2>=100) ai_flag++,ai_ch2=2;
					if(ai_c2<=0 or ai_c2>=100) ai_flag++,ai_ch2=3;
					if(ai_d2<=0 or ai_d2>=100) ai_flag++,ai_ch2=4;
					if(ai_flag>1) ai_now2=0;
					if(ai_now1 and ai_now2) 
					{
						if(ai_max1>ai_max2) choose=2;
						if(ai_max1<ai_max2) choose=1;
						if(ai_max1==ai_max2)
						{
							if(abs(ai_o1-200)>abs(ai_o2-200)) choose=2;
				 			if(abs(ai_o1-200)<abs(ai_o2-200)) choose=1;
							if(abs(ai_o1-200)==abs(ai_o2-200)) choose=rand()%2+1;
						}
					}
					if(ai_now1 and not(ai_now2))
					{
						choose=1;
						if(ai_ch1==1) q2=50;
						if(ai_ch1==2) w2=50;
						if(ai_ch1==3) e2=50;
						if(ai_ch1==4) r2=50;
					}
					if(not(ai_now1) and ai_now2)
					{
						choose=2;
						if(ai_ch2==1) q2=50;
						if(ai_ch2==2) w2=50;
						if(ai_ch2==3) e2=50;
						if(ai_ch2==4) r2=50;
					}
					else choose=rand()%2+1;
				}
				else choose=rand()%2+1;
			}
			//A.I.选择生效部分 
			if(choose==1){q2+=inversion(inver2,x[v].a1);w2+=inversion(inver2,x[v].a2);e2+=inversion(inver2,x[v].a3);r2+=inversion(inver2,x[v].a4);if(x[v].b!="") skill2=x[v].b;} 
			if(choose==2){q2+=inversion(inver2,x[v].b1);w2+=inversion(inver2,x[v].b2);e2+=inversion(inver2,x[v].b3);r2+=inversion(inver2,x[v].b4);if(x[v].c!="") skill2=x[v].c;}
			if(choose==tb_i_choose) bctb++;
			else bctb=0;
		}
		cls;
		year2++;j++;
		if(j==SIZe*2+1)
			rs(),j=1;
	}
}
int main()
{
	srand(time(NULL));
	init();
	start();
}
