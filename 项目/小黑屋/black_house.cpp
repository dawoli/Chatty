#include &lt;stdio.h&gt;

#include &lt;stdlib.h&gt;

#include &lt;time.h&gt;



//应在增加Sleep等待代码，在每回合结束之后，可以有效防止随机函数应为安的太快一直出现一个值（因为用了时间种子）



//#define shiyan 2;   宏定义不能进行自增自建

//shiyan++;



int cai;//田地里是否存在蔬菜的判定

int cai1 = 0;//蔬菜属性升级变量

int tili = 3;

int sj;//cai di sheng ji



int suiji()

{
	
	int a, b;
	
	srand((unsigned)time(NULL));
	
	a = rand();
	
	a = rand();
	
	a = rand();
	
	a = rand();
	
	a = rand() % 3 + 1;
	
	/* printf(&#34;%d\n&#34;, a);*/
	
	return a;
	
}

//生成随机数的子函数



int suijicai()

{
	
	int a, b;
	
	srand((unsigned)time(NULL));
	
	/*for (int c = 0; c &lt;= 19; c++)
	
	{*/
	
	a = rand();
	
	a = rand();
	
	a = rand();
	
	a = rand();
	
	a = rand() % 5 + 1;
	
	/* printf(&#34;%d\n&#34;, a);*/
	
	return a;
	
	/* }*/
	
}



int main() 

{
	
	int x;//决策方案
	
	
	
	int q, q1, q2;//随机数所使用的代体
	
	int food=10, water=10, wood=0,health=25;
	
	printf(&#34;你被人扔进荒岛，他告诉你会在两年后的某一天来看你，你开始了你的求生之路 &#34;);
	
	printf(&#34;\n&#34;);
	
	printf(&#34;\n&#34;);
	
	//printf(&#34;                                                                                                         食物：%d\n&#34;, food);
	
	//printf(&#34;                                                                                                         水  ：%d\n&#34;, water);
	
	//printf(&#34;                                                                                                         木材：%d\n&#34;, wood);
	
	//printf(&#34;                                                                                                         健康：%d\n&#34;, health);
	
	
	
	for (int t1 = 1; t1 &lt;= 25; t1++)
		
	{
		
		printf(&#34;                                                        |第%d个月|\n&#34;,t1);
		
		printf(&#34;\n&#34;);
		
		printf(&#34;\n&#34;);
		
		cai1 = suijicai();//菜地每个月有五分之一的几率损坏
		
		if (cai1 == 1)
			
		{
			
			printf(&#34;*你的菜地损坏了，请及时修缮*\n&#34;);
			
			printf(&#34;\n&#34;);
			
		}
		
		
		
		if (t1 == 10)
			
		{
			
			printf(&#34;你有一次升级体力的机会，是否花费15木头进行升级（仅此一次）\n&#34;);
			
			printf(&#34;1：同意   2：拒绝\n&#34;);
			
			scanf_s(&#34;请输入：%d&#34;, &amp;sj);
			
			if (sj == 1)
				
			{
				
				tili = 4;
				
				printf(&#34;升级完成\n&#34;);
				
			}
			
			else printf(&#34;已拒绝\n&#34;);
			
		}
		
		else;
		
		
		
		for (int t =tili; t &gt;= 1; t--)//回合数用可循环数来代替
			
		{
			
			printf(&#34; 1:狩猎  2:种田  3:打水  4:伐木\n&#34;);
			
			printf(&#34;\n&#34;);
			
			printf(&#34;\n&#34;);
			
			printf(&#34;                                                                                                         食物：%d\n&#34;, food);
			
			printf(&#34;                                                                                                         水  ：%d\n&#34;, water);
			
			printf(&#34;                                                                                                         木材：%d\n&#34;, wood);
			
			printf(&#34;                                                                                                         健康：%d\n&#34;, health);
			
			printf(&#34;\n&#34;);
			
			printf(&#34;\n&#34;);
			
			printf(&#34;当前总体力:%d\n&#34;,tili);
			
			scanf_s(&#34;%d&#34;, &amp;x);
			
			switch (x)
			
			{
				
				
				
			case 1:
				
				{
					
					printf(&#34;你进行了狩猎\n&#34;);
					
					switch (q = suiji())
					
					{
						
					case 1:
						
						{
							
							printf(&#34;你遇到了一只小狼，展开了战斗\n&#34;);
							
							switch (q = suiji())
							
							{
								
								case 1: 
								
								{
									
									printf(&#34;你尽管受了一些小伤，但最终你是胜利者\n&#34;); 
									
									food += 2; water += 1; health -= 2;
									
									printf(&#34;食物+1,水+1,健康-2\n&#34;);
									
									break;
									
								}
								
								default: 
								
								{
									
									printf(&#34;进行了有惊无险的战斗，最终你是胜利者\n&#34;);
									
									food += 2; water += 1; health -= 1;
									
									printf(&#34;食物+1,水+1,健康-1\n&#34;);
									
								}
								
							}
							
							break;
							
						}
						
						
						
						case 2: 
						
						{
							
							printf(&#34;你遇到了一只小坤，你的嘴角留下了不争气的泪水\n&#34;);
							
							food += 3; water += 2;
							
							printf(&#34;食物+2,水+2\n&#34;);
							
							break;
							
						}
						
						
						
					case 3:
						
						{
							
							printf(&#34;你遇到了一只老狼，展开了战斗\n&#34;);
							
							switch (q = suiji())
							
							{
								
							case 1:
								
								{
									
									printf(&#34;看到老狼身旁遍地的鲜血，你放下了紧绷的神情，最终你是胜利者\n&#34;);
									
									food += 5; water += 2; health -= 5;
									
									printf(&#34;食物+5,水+2,健康-5\n&#34;);
									
									break;
									
								}
								
							default:
								
								{
									
									printf(&#34;经过激烈的战斗，最终你是胜利者\n&#34;);
									
									food += 5; water += 2; health -= 2;
									
									printf(&#34;食物+5,水+2,健康-2\n&#34;);
									
								}
								
							}
							
							
							
						}
						
					}
					
					
					
					/*printf(&#34;\n&#34;);
					
					printf(&#34;\n&#34;);
					
					printf(&#34;                                                                                                         食物：%d\n&#34;, food);
					
					printf(&#34;                                                                                                         水  ：%d\n&#34;, water);
					
					printf(&#34;                                                                                                         木材：%d\n&#34;, wood);
					
					printf(&#34;                                                                                                         健康：%d\n&#34;, health);*/
					
					
					
					break;
					
				}
				
				
				
				//狩猎嵌套switch
				
				
				
				case 2: 
				
				{
					
					if (cai1 == 1)
						
					{
						
						printf(&#34;菜地损坏了，按5修复田地\n&#34;);
						
					}
					
					
					
					else
						
					{
						
						if (t1 &lt;= 20)
							
						{
							
							if (cai == 0)
								
							{
								
								cai = 1;
								
								printf(&#34;你种下了生菜,这种蔬菜会在下次行动成熟\n&#34;);
								
							}
							
							else if (cai == 1)
								
							{
								
								printf(&#34;你收获了生菜,并把它们藏到了肚子里\n&#34;);
								
								food += 1; water += 2; health += 2;
								
								cai = 0;
								
								printf(&#34;食物+2,水+2,健康+2\n&#34;);
								
							}
							
						}
						
						else printf(&#34;来了一场暴风雨摧毁了你的菜地并带走了你的种子,你无法种田了\n&#34;);
						
					}
					
					break;
					
				}
				
				
				
				case 3: 
				
				{
					
					printf(&#34;你喝了一大口水\n&#34;);
					
					water += 4;
					
					printf(&#34;水+4\n&#34;);
					
					break;
					
				}
				
			case 4:
				
				{
					
					printf(&#34;你进行了伐木\n&#34;); 
					
					wood += 5;
					
					break;
					
				}
				
				
				
				case 5: 
				
				{
					
					printf(&#34;修缮了菜地\n&#34;);
					
					cai1 = 0;
					
					break;
					
				}
				
				
				
			}
			
			
			
			if (food &lt;= 0 || water &lt;= 0 || health &lt;= 0)
				
			{
				
				printf(&#34;\n&#34;);
				
				printf(&#34;\n&#34;);
				
				printf(&#34;你闭上了劳累的双眼，终于不用再担惊受怕了\n&#34;);
				
				goto A;
				
			}
			
		}
		
		food -= 3; water -= 4; health += 1;//每月的自然消耗
		
	}
	
	printf(&#34;\n&#34;);
	
	printf(&#34;\n&#34;);
	
	printf(&#34;你终于等来了救援，不用再担惊受怕了。。。\n&#34;);
	
	printf(&#34;游戏胜利\n&#34;);
	
	A:  printf(&#34;\n&#34;);
	
	printf(&#34;\n&#34;);
	
	printf(&#34;game over\n&#34;);
	
	_getch();
	
}


