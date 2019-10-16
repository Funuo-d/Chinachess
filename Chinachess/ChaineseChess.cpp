#include<stdio.h>
#include<Windows.h>


int QiPan[10][9],winer=0;  //棋盘的行和列
int player = 1;    //红方还是黑方
HANDLE hOut;

enum chess   //枚举每一个棋子，由于两方不能动对方的棋子，故只能分开枚举
{
	Shuxian, Hengxian, Jinghao, Jiahao, Bing, Pao, Che, Ma, Xiang, Shi, Shuai, Army, Battery, Tank, House, Elephant, Guard, King
};

/******************************************************
 *菜单除开始游戏以外的选项都在此                      *
 ******************************************************/
void Help()           //帮助选项
{
	printf("\n********************************\n本软件还在测试阶段。\n********************************\n\n");
}
void About()            //关于选项
{
	printf("\n*********************\n版本号：0.1.0\n作者：NULL\n发布时间：NULL\n*********************\n\n");
}

//游戏设置
void GameConfig(int *p)
{
	int a = *p;
	if (*p = 1)
	{
		printf("您当前系统识别设置为Windows\n");
	}
	else
	{
		printf("您当前系统识别设置为Linux\n");
	}
	printf("系统修改为？（0.Linux   1.Windows）：");
	scanf("%d", p);
	if (*p > 1 || *p < 0)
	{
		printf("值超范围，修改失败！\n");
		*p = a;
	}
	else
	{
		printf("修改成功！\n");
	}

}
 //菜单样式及选项
int Homepage()  
{
	int a;
	printf("1.开始游戏\n2.设    置\n3.帮    助\n4.关    于\n5.退    出\n请输入选项：");
	for (int i = 0; i < 2;)
	{
		scanf("%d", &a);
		if (a > 5 || a < 1)
		{
			printf("输入的值无效，请重新输入:");
		}
		else
		{
			i = 3;
		}
	}
	return a;
} 


/***********************************************************
初始化游戏的函数
*************************************************************/
//初始化棋盘
void ChuShiHuaQiPan()
{
	//第一排棋盘
	QiPan[0][0] = Tank; QiPan[0][1] = House; QiPan[0][2] = Elephant; QiPan[0][3] = Guard; QiPan[0][4] = King; QiPan[0][5] = Guard; QiPan[0][6] = Elephant; QiPan[0][7] = House; QiPan[0][8] = Tank;

	//第二排棋盘
	QiPan[1][0] = Shuxian; QiPan[1][8] = Shuxian;
	for (int a = 1; a < 8; a++)
	{
		QiPan[1][a] = Jiahao;
	}
	for (int a = 3; a < 6; a++)
	{
		QiPan[1][a] = Jinghao;
	}
	//第三排棋盘
	QiPan[2][0] = QiPan[2][8] = Shuxian; QiPan[2][1] = QiPan[2][7] = Battery; QiPan[2][2] = QiPan[2][6] = Jiahao;
	QiPan[2][3] = QiPan[2][4] = QiPan[2][5] = Jinghao;
	//第四排棋盘
	for (int a = 0, b = -1; a < 9; a++, b = (-1)*b)
	{
		if (b == -1)
		{
			QiPan[3][a] = Army;
		}
		else
		{
			QiPan[3][a] = Jiahao;
		}
	}
	//第五排棋盘
	for (int a = 0; a < 9; a++)
	{
		QiPan[4][a] = Hengxian;
	}
	//第六排棋盘
	for (int a = 0; a < 9; a++)
	{
		QiPan[5][a] = Hengxian;
	}
	//第七排棋盘
	for (int a = 0, b = -1; a < 9; a++, b = (-1)*b)
	{
		if (b == -1)
		{
			QiPan[6][a] = Bing;
		}
		else
		{
			QiPan[6][a] = Jiahao;
		}
	}
	//第八排棋盘
	QiPan[7][0] = QiPan[7][8] = Shuxian; QiPan[7][1] = QiPan[7][7] = Pao; QiPan[7][2] = QiPan[7][6] = Jiahao;
	QiPan[7][3] = QiPan[7][4] = QiPan[7][5] = Jinghao;
	//第九排棋盘
	QiPan[8][0] = Shuxian; QiPan[8][8] = Shuxian;
	for (int a = 1; a < 8; a++)
	{
		QiPan[8][a] = Jiahao;
	}
	for (int a = 3; a < 6; a++)
	{
		QiPan[8][a] = Jinghao;
	}

	//第十排棋盘
	QiPan[9][0] = QiPan[9][8] = Che; QiPan[9][1] = QiPan[9][7] = Ma; QiPan[9][2] = QiPan[9][6] = Xiang; QiPan[9][3] = QiPan[9][5] = Shi; QiPan[9][4] = Shuai;

}



/************************************************************
重要功能函数
*************************************************************/

//棋子的显示(windows)
void ShowChessWindows(int p)
{
	switch (p)
	{
	case 0:
		printf("| "); break;
	case 1:
		printf("—"); break;
	case 2:
		printf("×"); break;
	case 3:
		printf("+ "); break;
	case 4:
		SetConsoleTextAttribute(hOut, FOREGROUND_RED);
		printf("兵");
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		break;
	case 5:
		SetConsoleTextAttribute(hOut, FOREGROUND_RED);
		printf("砲"); 
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		break;
	case 6:
		SetConsoleTextAttribute(hOut, FOREGROUND_RED);
		printf("車"); 
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		break;
	case 7:
		SetConsoleTextAttribute(hOut, FOREGROUND_RED);
		printf("馬"); 
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		break;
	case 8:
		SetConsoleTextAttribute(hOut, FOREGROUND_RED);
		printf("相"); 
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		break;
	case 9:
		SetConsoleTextAttribute(hOut, FOREGROUND_RED);
		printf("仕"); 
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		break;
	case 10:
		SetConsoleTextAttribute(hOut, FOREGROUND_RED);
		printf("帅"); 
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		break;
	case 11:
		printf("卒"); break;
	case 12:
		printf("炮"); break;
	case 13:
		printf("车"); break;
	case 14:
		printf("马"); break;
	case 15:
		printf("象"); break;
	case 16:
		printf("士"); break;
	case 17:
		printf("将"); break;
	default:
		break;
	}
}

//棋子的显示(linux)
void ShowChessLinux(int p)
{
	switch (p)
	{
	case 0:
		printf("| "); break;
	case 1:
		printf("--"); break;
	case 2:
		printf("# "); break;
	case 3:
		printf("+ "); break;
	case 4:
		printf("\033[31;m兵\033[0m"); break;
	case 5:
		printf("\033[31;m砲\033[0m"); break;
	case 6:
		printf("\033[31;m車\033[0m"); break;
	case 7:
		printf("\033[31;m马\033[0m"); break;
	case 8:
		printf("\033[31;m相\033[0m"); break;
	case 9:
		printf("\033[31;m仕\033[0m"); break;
	case 10:
		printf("\033[31;m帅\033[0m"); break;
	case 11:
		printf("卒"); break;
	case 12:
		printf("炮"); break;
	case 13:
		printf("车"); break;
	case 14:
		printf("马"); break;
	case 15:
		printf("象"); break;
	case 16:
		printf("士"); break;
	case 17:
		printf("将"); break;
	default:
		break;
	}
}


//打印棋盘
void ShowQipan(int wl)
{
	int a, b,c;
	if (wl == 1)           //系统判定
	{
		if (player == 1)
		{
			for (a = 0; a < 10; a++)
			{
				printf("%2d   ", a + 1);
				for (b = 0; b < 9; b++)
				{
					c = QiPan[a][b];
					ShowChessWindows(c);
				}
				printf("\n");
			}
			printf("-------------------------\n");
			printf("     1 2 3 4 5 6 7 8 9 \n");
		}
		else
		{
			for (a = 9; a >= 0; a--)
			{
				printf("%2d   ", a + 1);
				for (b = 8; b >=0; b--)
				{
					c = QiPan[a][b];
					ShowChessWindows(c);
				}
				printf("\n");
			}
			printf("-------------------------\n");
			printf("     9 8 7 6 5 4 3 2 1 \n");
		}
	}
	else
	{
		if (player == 1)
		{
			for (a = 0; a < 10; a++)
			{
				printf("%2d   ", a + 1);
				for (b = 0; b < 9; b++)
				{
					c = QiPan[a][b];
					ShowChessLinux(c);
				}
				printf("\n");
			}
			printf("-------------------------\n");
			printf("     1 2 3 4 5 6 7 8 9 \n");
		}
		else
		{
			for (a = 9; a >= 0; a--)
			{
				printf("%2d   ", a + 1);
				for (b = 8; b >= 0; b--)
				{
					c = QiPan[a][b];
					ShowChessLinux(c);
				}
				printf("\n");
			}
			printf("-------------------------\n");
			printf("     9 8 7 6 5 4 3 2 1 \n");
		}

	}
}


//棋子移动
void Chessmove(int a,int b,int c,int d)
{
	if (QiPan[c][d] == Shuai)  winer = 2;       //判断将是否死亡
	if (QiPan[c][d] == King) winer = 1;
	QiPan[c][d] = QiPan[a][b];              //移动棋子
	if ((b == 0 || b == 8) && (a < 4 || a>5))            //棋子移动后原来的位置恢复棋盘
	{
		QiPan[a][b] = Shuxian;
	}
	else
	{
		if (a == 4 || a == 5)
		{
			QiPan[a][b] = Hengxian;
		}
		else
		{
			if ((a < 3 || a>6 )&&( b >= 3 && b <= 5))
			{
				QiPan[a][b] = Jinghao;
			}
			else
			{
				QiPan[a][b] = Jiahao;
			}
		}
	}
}

/********************************************************
车，马移动规则
*********************************************************/
int Tankmove(int a,int b,int c,int d)
{
	if (a - c == 0 || b - d == 0)
	{	
		if (a - c == 0)
		{
			if (b - d > 0)
			{
				for (; d < b-1; d++)
				{
					if (QiPan[a][d] > 3)
					{
						return 0;
					}
					else
					{
						if(d==b) return 1;
						
					}
				}
			}
			else
			{
				for (d=d-1; d < b+1; d--)
				{
					if (QiPan[a][d] > 3)
					{
						return 0;
					}
					else
					{
						if(d==b)
						return 1;
					}
				}
			}
		}
		//判定分界线
		else
		{
			if (a - c > 0)
			{
				for (c=c+1; c < a; c++)
				{
					if (QiPan[c][b] > 3)
					{
						return 0;
					}
					else
					{
						if(c==a)
						return 1;
					}
				}
			}
			else
			{
				for (a=a+1; a < c-1; a++)
				{
					if (QiPan[a][b] > 3)
					{
						return 0;
					}
					else
					{
						if(c==a)
						return 1;
					}
				}
			}
		}
	}
	else
	{
		return 0;
	}
}

int Housemove(int a,int b,int c,int d)
{
	if (c - a == 2)
	{
		if (QiPan[a + 1][b] >= 4) return 0;
		if (b - d == 1 || d - b == 1)
		return 1;
	}
	if (a - c == 2)
	{
		if (QiPan[a - 1][b] >= 4)
			return 0;	
		if(b-d==1||d-b==1)
		return 1;
	}

	if (b - d == 2)
	{
		if (QiPan[a][d + 1] > 3)
			return 0;
		if (a - c == 1 || c - a == 1)
		return 1;
	}


	if (d - b == 2)
	{
		if (QiPan[a][d - 1] > 3)
			return 0;
		if(a-c==1||c-a==1)
		return 1;
	}


	return 0;


}

int Batterymove(int a, int b, int c, int d)
{
	int k;
	if (a - c == 0 || b - d == 0)
	{
		if (a - c == 0)
		{
			if (b - d > 0)
			{
				for (k = 0, b = b - 1; b >= d; b++)
				{
					if (QiPan[a][b] > 3)  k++;
				}
				if (k == 2 || k == 0) return 1;
				return 0;
			}
			else
			{
				for (k = 0, b = b + 1; b <= d; b++)
				{
					if (QiPan[a][b] > 3)  k++;
				}
				if (k == 2 || k == 0)  return 1;
				return 0;
			}
		}
		else
		{
			if (a - c > 0)
			{
				for (k = 0, a = a - 1; a >= c; a--)
				{
					if (QiPan[a][b] > 3)  k++;
				}
				if (k == 0 || k == 2)  return 1; return 0;
			}
			else
			{
				for (k = 0, a = a + 1; a <= c; a++)
				{
					if (QiPan[a][b] > 3)  k++;
				}
				if (k == 0 || k == 2)    return 1;
				return 0;
			}
		}
	}
	else
	{
		return 0;
	}
}

/*******************************************************
红方棋子的移动（兵象仕帅）
********************************************************/
int Bingmove(int a,int b,int c,int d)
{
	if (a < 5)
	{
		if ((a - c ==1)&&(b - d == 0))
		{
			return 1;
		}
		else 
		{
			if (a - c == 0)
			{
				if (b - d == 1 || d - b == 1) return 1; return 0;
			}
			return 0;
			
		}
	}
	else
	{
		if ((b - d == 0) && (a - c == 1))  return 1;
		return 0;
	}
}


int Xiangmove(int a, int b, int c, int d)
{
	if (c >= 5)
	{
		if ((a - c == 2 || c - a == 2) && (b - d == 2 || d - b == 2))
		{
			if (a - c == 2)
			{
				if (b - d == 2)
				{
					if (QiPan[a - 1][b - 1] > 3)  return 0; return 1;
				}
				else
				{
					if (QiPan[a - 1][d - 1] > 3)  return 0; return 1;
				}
			}
			else
			{
				if (b - d == 2)
				{
					if (QiPan[c - 1][b - 1] > 3)  return 0; return 1;
				}
				else
				{
					if (QiPan[c - 1][d - 1] > 3)  return 0; return 1;
				}
			}
		}
		else
		{
			return 0;	
		}

	}
	else
	{
		return 0;
	}
}


int Shuaimove(int a, int b, int c, int d)
{
	if (QiPan[c][d] == King) return 1;
	if (d <= 5 && d >= 3 && c >= 7 && c <= 9)
	{
		if (a - c == 1 || c - a == 1)
		{
			if (b - d == 0)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			if (b - d == 1 || d - b == 1)
			{
				if (a - c == 0)
				{
					return 1;
				}
				else
				{
					return 0;
				}
			}
			else
			{
				return 0;
			}
		}
	}
	else
	{
		return 0;
	}




}

int Shimove(int a, int b, int c, int d)
{
	if (d <= 5 && d >= 3 && c >= 7 && c <= 9)
	{
		if (a - c == 1 || c - a == 1)
		{
			if(b-d==1||d-b==1)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}


}



void MoveOrder_R()
{
	int a,b,c,d,line, column,exist;
	printf("红方输入指令：");
	for (int i = 0; i < 1;)
	{
		fflush(stdin);
		scanf("%d%d", &line, &column);
		line = line - 11;
		column = column - 11;
		a = line/10; b = line % 10; c = column/10; d = column % 10;
		if (a > 9 ||  a< 0 || b > 8 || b < 0 || c>9 ||c < 0 ||d >8 || d <0 < 0||line==column||(QiPan[c][d]>3&&QiPan[c][d]<11))
		{
			printf("输入指令有误，请重新输入：");
		}
		else
		{
			exist = QiPan[a][b];
			if (exist > 10 || exist < 4)
			{
				printf("\n该位置没有棋子或棋子不可动，请重新输入指令：");
			}
			else
			{
				switch (exist)
				{
				case 4:
					if (Bingmove(a, b, c, d))
					{
						Chessmove(a, b, c, d);
						i = 2; break;
					}
					else
					{
						printf("违反规则，无效指令，请重输：");
						i = 0; break;
					}
				case 5:
					if (Batterymove(a, b, c, d))
					{
						Chessmove(a, b, c, d);
						i = 2; break;
					}
					else
					{
						printf("违反规则，无效指令，请重输：");
						i = 0; break;
					}
				case 6:
					if (Tankmove(a, b, c, d))
					{
						Chessmove(a, b, c, d);
						i = 2; break;
					}
					else
					{
						printf("违反规则，无效指令，请重输：");
						i = 0; break;
					}
				case 7:
					if (Housemove(a, b, c, d))
					{
						Chessmove(a, b, c, d);
						i = 2; break;
					}
					else
					{
						printf("违反规则，无效指令，请重输：");
						i = 0; break;
					}
				case 8:
					if (Xiangmove(a, b, c, d))
					{
						Chessmove(a, b, c, d);
						i = 2; break;
					}
					else
					{
						printf("违反规则，无效指令，请重输：");
						i = 0; break;
					}
				case 9:
					if (Shimove(a, b, c, d))
					{
						Chessmove(a, b, c, d);
						i = 2; break;
					}
					else
					{
						printf("违反规则，无效指令，请重输：");
						i = 0; break;
					}
				case 10:
					if (Shuaimove(a, b, c, d))
					{
						Chessmove(a, b, c, d);
						i = 2; break;
					}
					else
					{
						printf("违反规则，无效指令，请重输：");
						i = 0; break;
					}
				default:
					break;
				}
			}
		}
	}

	
}


/********************************************
黑方移动棋子（兵象仕帅）
*********************************************/
int Armymove(int a, int b, int c, int d)
{
	if (a > 4)
	{
		if ((c - a == 1) && (b - d == 0))
		{
			return 1;
		}
		else
		{
			if (c - a == 0)
			{
				if (b - d == 1 || d - b == 1) return 1; return 0;
			}
			return 0;

		}
	}
	else
	{
		if ((b - d == 0) && (c - a == 1))  return 1;
		return 0;
	}
}

int Elephantmove(int a, int b, int c, int d)
{
	if (c < 5)
	{
		if ((a - c == 2 || c - a == 2) && (b - d == 2 || d - b == 2))
		{
			if (a - c == 2)
			{
				if (b - d == 2)
				{
					if (QiPan[a - 1][b - 1] > 3)  return 0; return 1;
				}
				else
				{
					if (QiPan[a - 1][d - 1] > 3)  return 0; return 1;
				}
			}
			else
			{
				if (b - d == 2)
				{
					if (QiPan[c - 1][b - 1] > 3)  return 0; return 1;
				}
				else
				{
					if (QiPan[c - 1][d - 1] > 3)  return 0; return 1;
				}
			}
		}
		else
		{
			return 0;
		}

	}
	else
	{
		return 0;
	}
}

int Kingmove(int a, int b, int c, int d)
{
	if (QiPan[c][d] == Shuai)  return 1;
	if (d <= 5 && d >= 3 && c <= 2 && c >= 0)
	{
		if (a - c == 1 || c - a == 1)
		{
			if (b - d == 0)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			if (b - d == 1 || d - b == 1)
			{
				if (a - c == 0)
				{
					return 1;
				}
				else
				{
					return 0;
				}
			}
			else
			{
				return 0;
			}
		}
	}
	else
	{
		return 0;
	}




}

int Guardmove(int a, int b, int c, int d)
{
	if (d <= 5 && d >= 3 && c <= 2 && c >= 0)
	{
		if (a - c == 1 || c - a == 1)
		{
			if (b - d == 1 || d - b == 1)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}


}

void MoveOrder_B()
{
	int a, b, c, d, line, column, exist;
	printf("黑方输入指令：");
	for (int i = 0; i < 1;)
	{
		fflush(stdin);
		scanf("%d%d", &line, &column);
		line = line - 11;
		column = column - 11;
		a = line / 10; b = line % 10; c = column / 10; d = column % 10;
		if (a > 9 || a< 0 || b > 8 || b < 0 || c>9 || c < 0 || d >8 || d <0 < 0 || line == column || (QiPan[c][d]>10 && QiPan[c][d]<=17))
		{
			printf("输入指令有误，请重新输入：");
		}
		else
		{
			exist = QiPan[a][b];
			if (exist < 11)
			{
				printf("\n该位置没有棋子或棋子不可动，请重新输入指令：");
			}
			else
			{
				switch (exist)
				{
				case 11:
					if (Armymove(a, b, c, d))
					{
						Chessmove(a, b, c, d);
						i = 2; break;
					}
					else
					{
						printf("违反规则，无效指令，请重输：");
						i = 0; break;
					}
				case 12:
					if (Batterymove(a, b, c, d))
					{
						Chessmove(a, b, c, d);
						i = 2; break;
					}
					else
					{
						printf("违反规则，无效指令，请重输：");
						i = 0; break;
					}
				case 13:
					if (Tankmove(a, b, c, d))
					{
						Chessmove(a, b, c, d);
						i = 2; break;
					}
					else
					{
						printf("违反规则，无效指令，请重输：");
						i = 0; break;
					}
				case 14:
					if (Housemove(a, b, c, d))
					{
						Chessmove(a, b, c, d);
						i = 2; break;
					}
					else
					{
						printf("违反规则，无效指令，请重输：");
						i = 0; break;
					}
				case 15:
					if (Elephantmove(a, b, c, d))
					{
						Chessmove(a, b, c, d);
						i = 2; break;
					}
					else
					{
						printf("违反规则，无效指令，请重输：");
						i = 0; break;
					}
				case 16:
					if (Guardmove(a, b, c, d))
					{
						Chessmove(a, b, c, d);
						i = 2; break;
					}
					else
					{
						printf("违反规则，无效指令，请重输：");
						i = 0; break;
					}
				case 17:
					if (Kingmove(a, b, c, d))
					{
						Chessmove(a, b, c, d);
						i = 2; break;
					}
					else
					{
						printf("违反规则，无效指令，请重输：");
						i = 0; break;
					}
				default:
					break;
				}
			}
		}
	}


}



int main()
{
	int wl=1;
	for (int t = 0; t < 1;)     //菜单
	{
		int a = Homepage();
		switch (a)
		{
		case 1:
			t = 3; break;
		case 2:
			int *system;
			system = &wl;
			GameConfig(system); break;
		case 3:
			Help(); break;
		case 4:
			About(); break;
		default:
			return 0;
		}
	}
	if(wl==1)	hOut = GetStdHandle(STD_OUTPUT_HANDLE);   //棋子颜色的句柄
	ChuShiHuaQiPan();   //棋盘初始化


	while (1)
	{
		if (player == 1)
		{
			ShowQipan(wl);      //输出棋盘
			MoveOrder_R();
		}
		else
		{
			ShowQipan(wl);
			MoveOrder_B();
		}
		if (winer > 0)
		{
			if (winer == 1)
			{
				ShowQipan(wl);
				printf("\n\n红方获胜！\n\n"); break;
			}
			else
			{
				ShowQipan(wl);
				printf("\n\n黑方获胜！\n\n"); break;
			}
		}
		else
		{
			player = (-1)*player;
		}

	}

	return 0;
}