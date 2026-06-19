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
struct data_th{ //沦陷战役_童话门
	string a;
	int a1,a2,a3;//善、恶、HP 
	int b1,b2,b3;
}th[1005];
struct data_sj{ //沦陷战役_世界门
	string a;
	int a1,a2;//我方军力、敌方军力
	int b1,b2;
	int v;//我方/敌方事件 
}sj[1005];
struct data_email{
	string a,b;//发送者、内容 
};
#define SIZe 16
#define SIZe_th 11
#define SIZe_sj 10
int ra[SIZe*2+1],ra_th[SIZe_th*2+1],ra_sj[SIZe_sj*2+1];
int th_rx[15][25],rx_sum=5;
int year=1,qaq=0,textspeed=5,Flag=0;
int HP=0,judge1=0,judge2=0,judge3=0,judge4=0;
int auto_read=0,auto_file=0;
string wm="无名之主";
string version="V1.1.12";
data2 gq[1005];
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
	banben.push_back("V1.1.12");
	//普通模式事件 
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
	x[15]=data{"传信人：民间的传染病越加严重。(Y:解决;N:没有动静)",10,10,-20,20,0,-20,-10,0,"",""};
	x[16]=data{"天文学家：我预测这几日天气状况不佳。(Y:认同;N:不认同)",0,10,-10,0,0,0,0,0,"",""};
	//沦陷战役模式_童话门事件
	th[1]=data_th{"您无意间走进了魔王的山洞。(Y:抵抗;N:逃跑)",10,-5,-5,-10,5,-15};
	th[2]=data_th{"您的面前有一瓶「HP」灵药。(Y:喝下;N:离开)",0,0,20,0,0,-10}; 
	th[3]=data_th{"您的面前有一瓶「善」灵药。(Y:喝下;N:离开)",20,0,0,0,0,-10}; 
	th[4]=data_th{"您的面前有一瓶「恶」灵药。(Y:喝下;N:离开)",0,20,0,0,0,-10}; 
	th[5]=data_th{"您的面前有一瓶「HP」魔药。(Y:喝下;N:离开)",0,0,-20,0,0,-10}; 
	th[6]=data_th{"您的面前有一瓶「善」魔药。(Y:喝下;N:离开)",-20,0,0,0,0,-10}; 
	th[7]=data_th{"您的面前有一瓶「恶」魔药。(Y:喝下;N:离开)",0,-20,0,0,0,-10}; 
	th[8]=data_th{"您遇见了一个小女孩。(Y:拯救;N:放弃)",10,10,0,0,0,0};
	th[9]=data_th{"您在路上遭到伏击。(Y:反击;N:放弃挣扎)",10,-10,-25,0,20,-10};
	th[10]=data_th{"您遇见了一只兔子。（Y:食之;N:离开)",0,-10,10,0,0,-5};
	th[11]=data_th{"您撞见了一个可怜人。(Y:拯救;N:杀死)",10,15,-10,0,5,0};
	//沦陷战役模式_世界门事件
	sj[1]=data_sj{"您有一次主动出击攻击敌方的机会。(Y:出击;N:忽略)",-10,-15,0,0,0};
	sj[2]=data_sj{"您有一次招募军队的机会。(Y:招募;N:忽略)",20,0,0,0,0};
	sj[3]=data_sj{"您有一次偷袭敌方的机会。(Y:偷袭;N:忽略)",-10,-20,0,0,0};
	sj[4]=data_sj{"您被敌军偷袭。(Y:反抗;N:忽略)",-20,-10,-10,-5,0};
	sj[5]=data_sj{"您有一次训练军队的机会。(Y:训练;N:忽略)",10,0,0,0,0};
	sj[6]=data_sj{"敌军训练了军队。",0,10,0,0,1};
	sj[7]=data_sj{"敌军主动出击攻击我方。",-15,-10,0,0,1}; 
	sj[8]=data_sj{"敌军招募了军队。",0,20,0,0,1};
	sj[9]=data_sj{"敌军偷袭了我方军队。",-10,0,0,0,1}; 
	sj[10]=data_sj{"您有一次大量招募军队的机会。(Y:招募;N:忽略)",30,0,0,0,0};
	//普通模式技能列表 
	skills_2nd.push_back("逃避");
	skills_2nd.push_back("平安");
	skills_2nd.push_back("倒置");
	//普通模式技能介绍 
	skills["逃避"]="躲过这次选择，不接受也不拒绝";
	skills["平安"]="使任一属性回到50 (可选择)"; 
	skills["倒置"]="使做出选择后获得的增益倒置 (不包括获得、使用技能)，直到下一次使用倒置为止";
	//成就列表 
	ach.push_back("初登王位");
	ach.push_back("多重加害");
	ach.push_back("百寿");
	ach.push_back("名字问题1");
	ach.push_back("名字问题2");
	ach.push_back("隐藏地域");
	//成就介绍
	ach_introduce["初登王位"]="第一次开始游戏";
	ach_introduce["多重加害"]="同时因为多项属性而结束游戏";
	ach_introduce["百寿"]="一个人物活到100岁";
	ach_introduce["名字问题1"]="......你真的以为我会让你使用它？";
	ach_introduce["名字问题2"]="这不太礼貌。";
	ach_introduce["隐藏地域"]="你是怎么发现这儿的？"; 
	//......然而成就的展示是按获取方式分。
	achs["普通模式"].push_back("初登王位"); 
	achs["普通模式"].push_back("多重加害");
	achs["普通模式"].push_back("百寿");
	achs["隐藏成就"].push_back("名字问题1");
	achs["隐藏成就"].push_back("名字问题2");
	achs["隐藏成就"].push_back("隐藏地域");
	//邮件内容
	email_text["游戏介绍-普通模式"]=data_email{"Doom_Deterrence",
	"在这个游戏中，你需要控制一名君王来应对每一年所发生的事件，作出相应的对答。\n每一次相应的对答可以选择Y或N，你的国家拥有四种属性，不同的对答会造成每个属性的相应加减。\n四种属性分别是：宗教,民众,军队,财富。\n每个属性的初始状态都为50点。通过选择会加减属性，当一个属性<=0或>=100时，游戏结束，愤怒的臣民会杀掉你。\n你还拥有一项技能，这需要你在游戏中获得。技能是一次性的，得到新的技能会覆盖原技能。有技能时可以按S(Skill)触发效果。\n你的游戏目标是，活得尽量久。\n"}; 
	email_text["欢迎来到王权"]=data_email{"Doom_Deterrence",
	"感谢您游玩王权！\n游戏制作者：Doom_Deterrence\n游戏团队：https://www.luogu.com.cn/team/23723"};
	email_text["hide1"]=data_email{"???","你为什么会到这儿？"};
	email_text["hide2"]=data_email{"???","你不应该来到这儿。离开。"};
	email_text["Hide1"]=data_email{"","The author thinks that you are too YOUNG too SIMPLE."};
	email_text["wmhide"]=data_email{"","This name that you can't CHOOSE."};
	email_text["Locked"]=data_email{"","Locked."};
	email_text["WM1"]=data_email{"","你走向王座。"};
	email_text["WM2"]=data_email{"",".."};
	email_text["WM3"]=data_email{"","...."};
	email_text["WM4"]=data_email{"","......"};
	email_text["hacker1"]=data_email{"","(铃铃铃......)"};
	email_text["WM5"]=data_email{"???","你来了。"};
	email_text["WM6"]=data_email{"???","我是守卫者。上一个国王。"};
	email_text["WM7"]=data_email{"???","我是"+wm+"。"};
	email_text["WM8"]=data_email{wm,"我想，一直以来，\n你的 HP 无时不刻不在变化。"}; 
	email_text["WM9"]=data_email{wm,"什么是 HP？"};
	email_text["WM10"]=data_email{wm,"HP，它是一个缩写。\n它的全写是 Hinder Point。"};
	email_text["WM11"]=data_email{wm,"意思是“阻碍点”，\n也就是你将在我这儿受到的阻碍大小。"};
	email_text["WM12"]=data_email{wm,"你的 HP 越高，我的能力越强。"};
	email_text["WM_1_1"]=data_email{wm,"但是.....你的 HP，已经足够让我直接失败了。"};
	email_text["WM_1_2"]=data_email{wm,"你可真是个大好人.....对不？你过去吧，坐上王座。"};
	email_text["WM_2_1"]=data_email{wm,"你的 HP 比较低。但不够低。\n依靠它们，我有足够的力量战斗。"};
	email_text["WM_2_2"]=data_email{wm,"我本来可以放过你的——但是你的 HP 不允许！"};
	email_text["WM_3_1"]=data_email{wm,"不多，你是在刻意保持那么高的 HP 吗？"};
	email_text["hacker3"]=data_email{"","如果有人玩到这个页面，请麻烦告知作者。"};
	email_text["WM_3_2"]=data_email{wm,"如果你还有下一次的话......可不要这样。"};
	email_text["hacker2"]=data_email{"","你在这了。"};
	email_text["WM_4_1"]=data_email{wm,"果然，你的 HP 是巅峰的。我的力量也是！"};
	email_text["WM_4_2"]=data_email{wm,"你为自己招来了横祸！"}; 
	email_text["hacker4"]=data_email{"","但恐怕......你只是一个肮脏的黑客吧？"};
}
iv say(string say1,int say2);
iv rs(){for(int i=1;i<=SIZe;i++)ra[i]=i;for(int i=SIZe+1;i<=SIZe*2;i++)ra[i]=rand()%SIZe+1;random_shuffle(ra+1,ra+1+SIZe*2);}
iv rs_th(){for(int i=1;i<=SIZe_th;i++)ra_th[i]=i;for(int i=SIZe_th+1;i<=SIZe_th*2;i++)ra_th[i]=rand()%SIZe_th+1;random_shuffle(ra_th+1,ra_th+1+SIZe_th*2);}
iv rs_sj(){for(int i=1;i<=SIZe_sj;i++)ra_sj[i]=i;for(int i=SIZe_sj+1;i<=SIZe_sj*2;i++)ra_sj[i]=rand()%SIZe_sj+1;random_shuffle(ra_sj+1,ra_sj+1+SIZe_sj*2);}
iv di_box(string title,string s1,string s2);
iv diq(string s){di_box("","",s);}
iv hacker(){ifstream fin("WDGaster.txt");char c;int ci=0;fin>>ci;ci++;fin.close();
	ofstream fout("WDGaster.txt");fout<<ci;fout.close();if(ci>1){if(ci<=6)cls,diq("你已经来了 "+change(ci)+" 次了。"),c=getch();cls;if(ci==2) diq("还不知足吗？");if(ci==3) diq("你知道，你在尝试修改代码。");
		if(ci==4) diq("蠢蛋，代码都改不动。");if(ci==5) diq("如果你看到了这条消息，就代表你不是个 OIer。");if(ci==6) diq("你的耐心......可真让我吃惊啊。");if(ci>6) diq("你就没有更重要的事情去做吗？");c=getch();}
	else for(int i=1;i<=4;i++) say("hacker"+change(i),2);exit(0);}
string connect_(){return change(char(120))+change(char(116))+change(char(113))+change(char(49))+change(char(50))+change(char(51));}
iv print(string a){if(a.find(connect_())!=-1) hacker(); else for(int i=0;i<a.size();i++){putchar(a[i]);Sleep(textspeed);}}
iv print2(string a,int b){for(int i=0;i<a.size();i++){putchar(a[i]);Sleep(b);}}
iv start();
iv game();
iv FIEH(int flag);
iv red(string u){set1(set2 | sred);print(u);set;}
iv blue(string u){set1(set2 | sblue);print(u);set;}
iv red2(string u,int w){set1(set2 | sred);print2(u,w);set;}
iv green(string u){set1(set2 | sgreen);print(u);set;}
iv yellow(string u){set1(set2 | sred | sgreen);print(u);set;}
iv cyan(string u){set1(set2 | sgreen | sblue);print(u);set;}
iv pink(string u){set1(set2 | sred | sblue);print(u);set;}
iv rainbow(string u){if(u.find(connect_())!=-1) hacker(); else for(int i=0;i<u.size();i++){int rainbo=rand()%7*rand()%7+1;switch(rainbo){case 1:print(change(u[i]));break;case 2:red(change(u[i]));break;case 3:green(change(u[i]));break;case 4:blue(change(u[i]));break;case 5:yellow(change(u[i]));break;case 6:cyan(change(u[i]));break;case 7:pink(change(u[i]));break;}} }
iv achieve(string u)
{
	if(u=="初登王位")
	{
		pink("+------------------+\n");
		pink("|获得成就：初登王位|\n");
		pink("|第一次开始游戏    |\n");
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
	year qaq textspeed auto_read auto_file 
	gq[1].a gq[1].b gq[1].s
	...
	gq[qaq].a gq[qaq].b gq[qaq].s
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
		fout<<year<<' '<<qaq<<' '<<textspeed<<' '<<auto_read<<' '<<auto_file<<'\n';
		for(int i=1;i<=qaq;i++)
			fout<<gq[i].a<<' '<<gq[i].b<<' '<<gq[i].s<<'\n';
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
			red("存档成功！");
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
		fin>>year>>qaq>>textspeed>>auto_read>>auto_file;
		for(int i=1;i<=qaq;i++)
			fin>>gq[i].a>>gq[i].b>>gq[i].s;
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
			red("读档成功！");
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
			rainbow(gq[i].s);
			putchar('\n');
			if(maxn<gq[i].b-gq[i].a+1)
				maxn=gq[i].b-gq[i].a+1,maxnn=i;
		}
		cyan("最长统治者为 ");
		rainbow(gq[maxnn].s);
		cyan(" ，统治了 ");
		print(change(maxn));
		cyan(" 年\n");
	}
	cyan("按1退出\n");
	char c=getch();
	while(c!='1') c=getch();
	cls;
	start(); 
}
iv journal() //更新日志 
{
	rainbow("V1.0.0:");pink("基础游戏设施 (2019.11.29)\n");
	rainbow("V1.0.1:");pink("增加更新日志 设置 存档 读档 (2019.11.30)\n");
	rainbow("V1.0.2:");pink("增加2条新的事件 (2019.12.2)\n");
	rainbow("V1.0.3:");pink("增加自动读档 游戏公告 (2019.12.4)\n");
	rainbow("V1.0.4:");pink("增加自动存档 修正部分文本 (2019.12.5)\n");
	rainbow("V1.0.5:");pink("增加彩色字体 修复自动存档 (2019.12.7)\n");
	rainbow("V1.0.6:");pink("修改统计 (2019.12.7)\n");
	rainbow("V1.0.7:");pink("增加1条新的事件 (2019.12.9)\n");
	rainbow("V1.1.0:");pink("增加技能 成就(未完工) (2019.12.11)\n");
	rainbow("V1.1.1:");pink("修改技能 平安 增加技能 倒置 修复成就 (2019.12.14)\n");
	rainbow("V1.1.2:");pink("增加2条成就 (2019.12.14)\n");
	rainbow("V1.1.3:");pink("增加模式沦陷战役 开启沦陷战役-童话门 (2020.1.1)\n");
	rainbow("V1.1.4:");pink("开启沦陷战役-世界门 (2020.1.4)\n");
	rainbow("V1.1.5:");pink("邮件系统（未完工） (2020.1.15)\n");
	rainbow("V1.1.6:");pink("邮件系统（将近完工） (2020.1.17)\n");
	rainbow("V1.1.7:");pink("开启沦陷战役-人心门 (2020.1.24)\n");
	rainbow("V1.1.8:");pink("修改沦陷战役-人心门 (2020.1.25)\n");
	rainbow("V1.1.9:");pink("削弱沦陷战役-人心门强度 增加彩蛋 (2020.1.26)\n");
	rainbow("V1.1.10:");pink("削弱沦陷战役-人心门 沦陷战役-世界门强度 (2020.1.28)\n");
	rainbow("V1.1.11:");pink("制作沦陷战役-我们门（未完工） WARNING!!!!!!!!!!!!!!! (2020.2.5)\n");
	rainbow("V1.1.12:");pink("更新成就（是的，这个人一直在拖更） (2020.2.28)\n");
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
	red("2.沦陷战役\n");
	red("WARNING:沦陷战役仍未编写完毕、将有可能触发未知BUG或无法退出的可能。您可以加入沦陷战役，但推荐此模式仅供开发者使用。\n");
	cyan("\n请选择游戏模式：\n");
	char c=getch();
	while(!(c=='1' or c=='2' or c=='\\')) c=getch();
	cls;
	if(c=='1') game();
	if(c=='2') FIEH(0);
	if(c=='\\')
	{
		ach_judge["隐藏地域"]=1;
		say("hide1",1);
		say("hide2",1);
		cls;
		start();
	}
}
iv start() //主界面 
{
	pink("The Game:");rainbow("Reigns");pink(" (王权)\n");
	pink("Version:");rainbow(version);pink("\n");
	pink("The Author:");rainbow("Doom_Deterrence");pink(" (洛谷用户名)\n\n");
	if(Flag==0)
	{
		pink("正在检查您是否自动读档...\n");
		ifstream fin("reignsfile.txt");
		string op;
		fin>>op>>auto_read>>auto_read>>auto_read>>auto_read;
		fin.close();
		if(auto_read==0)
		{
			red("您没有自动读档或没有本地保存文件\n\n");
			emails.push_back("欢迎来到王权");
			emails.push_back("游戏介绍-普通模式");
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
	pink("6.存档\n");
	pink("7.读档\n");
	pink("8.成就\n");
	pink("9.游戏机制资料\n");
	pink("X.退出游戏\n");
	char c=getch();
	while((c<'1' or c>'9') and c!='X') c=getch();
	cls;
	if(c=='1') choose_game();
	if(c=='2') email();
	if(c=='3') statistics();
	if(c=='4') journal();
	if(c=='5') setting();
	if(c=='6') file(0);
	if(c=='7') readfile(0);
	if(c=='8') achievement();
	if(c=='9') reigns_data();
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
	if(name=="Doom_Deterrence")
	{
		ach_judge["名字问题1"]=1;
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
		print("君王:");rainbow(name);putchar('\n');
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
			if(skill=="逃避") ;
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
iv FIEH_TH(int o) //沦陷战役_童话门 
{
	int q=50,e=50,hp=o,vb=0;
	cls;
	int k=1,j=1;
	char c;
	rs_th();
	while(1)
	{
		if(ra_th[j]==vb) 
		{
			j++;
			if(j==SIZe_th*2+1)
				rs_th(),j=1;
			continue;
		}
		red("森林 第 ");red(change(k));red(" 天\n");
		red("善:");num(q);putchar(' ');
		red("恶:");num(e);putchar(' ');
		red("HP:");red(change(hp));putchar(' ');
		putchar('\n');
		
		if(hp<=0 or q<=0 or e>=100) //死亡 
		{
			red("童话已经结束。您死于沦陷战役\n");
			Sleep(3000);
			if(auto_file==1) file(1);
			cls;
			start();
			return;
		}
		if(q>=100 and e<=0)
		{
			red("童话已经结束。善战胜了恶。");
			Sleep(3000);
			cls;
			HP=hp;
			judge2=1;
			FIEH(1);
			return;
		}
		
		red("事件：\n");
		int v=ra_th[j];
		vb=v;
		red(th[v].a);
		putchar('\n');
		putchar('\n');
		
		red("Y:\n善:");cho(th[v].a1);red("\n恶:");cho(th[v].a2);red("\nHP:");cho(th[v].a3);
		putchar('\n');
		
		red("N:\n善:");cho(th[v].b1);red("\n恶:");cho(th[v].b2);red("\nHP:");cho(th[v].b3);
		putchar('\n');
		
		putchar('\n');
		
		c=getch(); 
		while(c!='Y' and c!='N') c=getch();
		if(c=='Y'){q+=th[v].a1;e+=th[v].a2;hp+=th[v].a3;} 
		if(c=='N'){q+=th[v].b1;e+=th[v].b2;hp+=th[v].b3;}
		
		cls;
		k++;j++;hp=min(100,hp);
		if(j==SIZe_th*2+1)
			rs_th(),j=1;
	}
}
iv FIEH_SJ(int o) //沦陷战役_世界门 
{
	int q=50,e=50,hp=o,vb=0,hp2=100;
	cls;
	int k=1,j=1;
	char c;
	rs_sj();
	while(1)
	{
		if(ra_sj[j]==vb) 
		{
			j++;
			if(j==SIZe_sj*2+1)
				rs_sj(),j=1;
			continue;
		}
		red("战争 第 ");red(change(k));red(" 月\n");
		red("我方军力:");num(q);putchar(' ');
		red("我方HP:");red(change(hp));putchar('\n');
		red("敌方军力:");num(e);putchar(' ');
		red("敌方HP:");red(change(hp2));
		putchar('\n');
		
		if(hp<=0) //死亡 
		{
			red("世界已经崩坏。您死于沦陷战役\n");
			Sleep(3000);
			if(auto_file==1) file(1);
			cls;
			start();
			return;
		}
		if(hp2<=0)
		{
			red("世界已经崩坏。您打败了敌国。\n");
			Sleep(3000);
			cls;
			HP=hp;
			judge1=1;
			FIEH(1);
			return;
		}
		
		red("事件：\n");
		int v=ra_sj[j];
		vb=v;
		red(sj[v].a);
		putchar('\n');
		putchar('\n');
		
		if(sj[v].v==0)
		{
			red("Y:\n我方军力:");cho(sj[v].a1);red("\n敌方军力:");cho(sj[v].a2);
			putchar('\n');
			red("N:\n我方军力:");cho(sj[v].b1);red("\n敌方军力:");cho(sj[v].b2);
			putchar('\n');
		}
		else
		{
			red("\n我方军力:");cho(sj[v].a1);red("\n敌方军力:");cho(sj[v].a2);
			putchar('\n');
		}
		
		putchar('\n');
		
		if(sj[v].v==0)
		{
			c=getch(); 
			while(c!='Y' and c!='N') c=getch();
			if(c=='Y'){q+=sj[v].a1;e+=sj[v].a2;} 
			if(c=='N'){q+=sj[v].b1;e+=sj[v].b2;}
		}
		else
		{
			red("按Y继续\n");
			c=getch();
			while(c!='Y') c=getch();
			q+=sj[v].a1;e+=sj[v].a2;
		}
		
		cls;
		k++;j++;
		if(q<e) hp-=5,hp2+=2;
		if(q>e) hp2-=5,hp+=2;
		hp=min(100,hp);
		hp2=min(100,hp2);
		q=min(100,q);q=max(0,q);
		e=min(100,e);e=max(0,e);
		if(j==SIZe_sj*2+1)
			rs_sj(),j=1;
	}
}
void put(int a,int b)
{
	if(a==1) red("#");
	else if(b==1) putchar('|');else putchar('-');
}
void sp(int a){for(int i=0;i<a;i++) putchar(' ');}
bool th_check1(){return not(th_rx[1][rx_sum]==0 and th_rx[2][rx_sum]==0 and th_rx[3][rx_sum]==0 and th_rx[4][rx_sum]==0);} 
iv FIEH_RX(int o) //沦陷战役_人心门 
{
	memset(th_rx,0,sizeof(th_rx));
	int q=rand()%15+15,e=10,hp=o,q2=q;
	cls;
	int k=1;
	char c;
	while(1)
	{
		red("守卫 第 ");red(change(k));red(" 次\n");
		red("敌人数量:");blue(change(q));putchar(' ');
		red("TP:");blue(change(e));putchar(' ');
		red("HP:");red(change(hp));putchar(' ');
		putchar('\n');
		
		if(hp<=0) //死亡 
		{
			red("人心已经破碎。您死于沦陷战役\n");
			Sleep(3000);
			if(auto_file==1) file(1);
			cls;
			start();
			return;
		}
		if(q<=0) //胜利 
		{
			red("人心已经破碎。您战胜了敌人。");
			Sleep(3000);
			cls;
			HP=hp;
			judge3=1;
			FIEH(1);
			return;
		}
		
		for(int i=1;i<=rx_sum;i++) sp(rx_sum),put(th_rx[1][i],1),putchar('\n');
		for(int i=1;i<=rx_sum;i++) put(th_rx[2][i],2);
		blue("+");
		for(int i=rx_sum;i>=1;i--) put(th_rx[3][i],2);
		putchar('\n');
		for(int i=rx_sum;i>=1;i--) sp(rx_sum),put(th_rx[4][i],1),putchar('\n');
		
		
		cyan("时机：");
		int v=rand()%3+1,v2=(rand()%10+1)*10,pro;
		if(v==1) blue("守("+change(v2)+")\n");
		if(v==2) blue("攻("+change(v2)+")\n");
		if(v==3) blue("无\n");
		putchar('\n');
		
		red("1.攻\n");
		red("2.守\n");
		
		c=getch(); 
		while(c<'1' or c>'2') c=getch();
		if(c=='1')
		{
			if(th_check1())
			{
				int prk=rand()%4+1;
				while(th_rx[prk][rx_sum]==0)
					prk=rand()%4+1;
				th_rx[prk][rx_sum]=0;
				q--;
			}
			if(v==2)
			{
				pro=rand()%100+1;
				if(pro<=v2)
					if(th_check1())
					{
						int prk=rand()%4+1;
						while(th_rx[prk][rx_sum]==0)
							prk=rand()%4+1;
						th_rx[prk][rx_sum]=0;
						q--;
					}
			}
			if(th_check1())
			{
				pro=rand()%100+1;
				if(pro>e/2) hp-=rand()%15+1;
				else
				{
					e-=rand()%6+5;
					pro=rand()%100+1;
					if(pro<=e/1.5) hp+=rand()%10+1;
				}	 	
			}
		} 
		if(c=='2')
		{
			int u=rand()%5+1;
			if(v==1)
			{
				pro=rand()%100+1;
				if(pro<=v2) u*=2;
			}
			e+=u;
			if(th_check1())
			{
				pro=rand()%100+1;
				if(pro>e/2) hp-=rand()%10+1;
				else
				{
					e-=rand()%6+5;
					pro=rand()%100+1;
					if(pro<=e/1.5) hp+=rand()%10+1;
				}	 	
			}
		}
		
		for(int i=1;i<=4;i++)
			for(int j=rx_sum;j>=1;j--)
			{
				int flag=0;
				if(th_rx[i][j]==0) flag=1;
				if(flag==1) swap(th_rx[i][j],th_rx[i][j-1]);
			}
		int _pro=rand()%3;
		for(int _=1;_<=_pro;_++)
			if(not(th_rx[1][1]==1 and th_rx[2][1]==1 and th_rx[3][1]==1 and th_rx[4][1]==1) and q2>0)
			{
				int thr=rand()%4+1;
				while(th_rx[thr][1]==1) thr=rand()%4+1;
				th_rx[thr][1]=1;
				q2--;
			}
		
		cls;k++;
		hp=min(100,hp);
		e=min(100,e);
		e=max(0,e);
	}
}
iv FIEH_WM(int o) //沦陷战役_我们门 （未完工） 
{
	cls;
	for(int i=1;i<=4;i++)
		say("WM"+change(i),2);
	for(int i=5;i<=12;i++)
		say("WM"+change(i),1);
	if(o<=20)
	{
		for(int i=1;i<=2;i++)
			say("WM_1_"+change(i),1);
		judge4=2;
		FIEH(1);
		return;
	}
	if(o>20 and o<=50)
	{
		for(int i=1;i<=2;i++)
			say("WM_2_"+change(i),1);
	}
	if(o>50 and o<=80)
	{
		for(int i=1;i<=2;i++)
			say("WM_3_"+change(i),1);
	}
	if(o>80)
	{
		for(int i=1;i<=2;i++)
			say("WM_4_"+change(i),1);
	}
}
iv FIEH(int flag) //沦陷战役(编写中) (FIEH=Fall Into Enemy Hands) HP=Hinder Point
{
	if(flag==0)
	{
		cyan("输入你的姓名（不含空格）：");
		string name;
		cin>>name;
		if(name==wm)
		{
			ach_judge["名字问题2"]=1;
			say("wmhide",2);cls;start();
			return;
		}
		HP=100,judge1=0,judge2=0,judge3=0,judge4=0;
	}
	if(judge1==1 and judge2==1 and judge3==1) judge4=1;
	red("世界太黑，童话太假。人心太暗，我们太傻。\n");
	red("您已加入沦陷战役。\n");
	red("您的剩余HP：");red(change(HP));putchar('\n');
	red("请选择您将踏入的门：\n\n");
	if(judge1==0) red("1.世界门\n");else green("1.世界门\n");
	if(judge2==0) red("2.童话门\n");else green("2.童话门\n");
	if(judge3==0) red("3.人心门\n");else green("3.人心门\n");
	if(judge4==0) red("4.我们门\n");else if(judge4==1) yellow("4.我们门\n");else green("我们门\n");
	char c;
	while(1)
	{
		c=getch();
		if(c<'1' or c>'4') continue;
		else if(c=='1' and judge1==1) continue;
		else if(c=='2' and judge2==1) continue;
		else if(c=='3' and judge3==1) continue;
		/*
		else if(c=='4' and judge4==0)
		{
			say("Locked",2);
			cls;
			FIEH(1);
			return;
		}
		*/
		else if(c=='4' /*and judge3==2*/) continue;
		else break;
	}
	if(c=='1') FIEH_SJ(HP);
	if(c=='2') FIEH_TH(HP);
	if(c=='3') FIEH_RX(HP);
	//if(c=='4') FIEH_WM(HP);
}
int main()
{
	srand(time(NULL));
	init();
	start();
}
