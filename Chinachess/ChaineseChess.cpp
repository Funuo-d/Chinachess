#include<stdio.h>
#include<Windows.h>


int QiPan[10][9],winer=0;  //���̵��к���
int player = 1;    //�췽���Ǻڷ�
HANDLE hOut;

enum chess   //ö��ÿһ�����ӣ������������ܶ��Է������ӣ���ֻ�ֿܷ�ö��
{
	Shuxian, Hengxian, Jinghao, Jiahao, Bing, Pao, Che, Ma, Xiang, Shi, Shuai, Army, Battery, Tank, House, Elephant, Guard, King
};

/******************************************************
 *�˵�����ʼ��Ϸ�����ѡ��ڴ�                      *
 ******************************************************/
void Help()           //����ѡ��
{
	printf("\n********************************\n��������ڲ��Խ׶Ρ�\n********************************\n\n");
}
void About()            //����ѡ��
{
	printf("\n*********************\n�汾�ţ�0.1.0\n���ߣ�NULL\n����ʱ�䣺NULL\n*********************\n\n");
}

//��Ϸ����
void GameConfig(int *p)
{
	int a = *p;
	if (*p = 1)
	{
		printf("����ǰϵͳʶ������ΪWindows\n");
	}
	else
	{
		printf("����ǰϵͳʶ������ΪLinux\n");
	}
	printf("ϵͳ�޸�Ϊ����0.Linux   1.Windows����");
	scanf("%d", p);
	if (*p > 1 || *p < 0)
	{
		printf("ֵ����Χ���޸�ʧ�ܣ�\n");
		*p = a;
	}
	else
	{
		printf("�޸ĳɹ���\n");
	}

}
 //�˵���ʽ��ѡ��
int Homepage()  
{
	int a;
	printf("1.��ʼ��Ϸ\n2.��    ��\n3.��    ��\n4.��    ��\n5.��    ��\n������ѡ�");
	for (int i = 0; i < 2;)
	{
		scanf("%d", &a);
		if (a > 5 || a < 1)
		{
			printf("�����ֵ��Ч������������:");
		}
		else
		{
			i = 3;
		}
	}
	return a;
} 


/***********************************************************
��ʼ����Ϸ�ĺ���
*************************************************************/
//��ʼ������
void ChuShiHuaQiPan()
{
	//��һ������
	QiPan[0][0] = Tank; QiPan[0][1] = House; QiPan[0][2] = Elephant; QiPan[0][3] = Guard; QiPan[0][4] = King; QiPan[0][5] = Guard; QiPan[0][6] = Elephant; QiPan[0][7] = House; QiPan[0][8] = Tank;

	//�ڶ�������
	QiPan[1][0] = Shuxian; QiPan[1][8] = Shuxian;
	for (int a = 1; a < 8; a++)
	{
		QiPan[1][a] = Jiahao;
	}
	for (int a = 3; a < 6; a++)
	{
		QiPan[1][a] = Jinghao;
	}
	//����������
	QiPan[2][0] = QiPan[2][8] = Shuxian; QiPan[2][1] = QiPan[2][7] = Battery; QiPan[2][2] = QiPan[2][6] = Jiahao;
	QiPan[2][3] = QiPan[2][4] = QiPan[2][5] = Jinghao;
	//����������
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
	//����������
	for (int a = 0; a < 9; a++)
	{
		QiPan[4][a] = Hengxian;
	}
	//����������
	for (int a = 0; a < 9; a++)
	{
		QiPan[5][a] = Hengxian;
	}
	//����������
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
	//�ڰ�������
	QiPan[7][0] = QiPan[7][8] = Shuxian; QiPan[7][1] = QiPan[7][7] = Pao; QiPan[7][2] = QiPan[7][6] = Jiahao;
	QiPan[7][3] = QiPan[7][4] = QiPan[7][5] = Jinghao;
	//�ھ�������
	QiPan[8][0] = Shuxian; QiPan[8][8] = Shuxian;
	for (int a = 1; a < 8; a++)
	{
		QiPan[8][a] = Jiahao;
	}
	for (int a = 3; a < 6; a++)
	{
		QiPan[8][a] = Jinghao;
	}

	//��ʮ������
	QiPan[9][0] = QiPan[9][8] = Che; QiPan[9][1] = QiPan[9][7] = Ma; QiPan[9][2] = QiPan[9][6] = Xiang; QiPan[9][3] = QiPan[9][5] = Shi; QiPan[9][4] = Shuai;

}



/************************************************************
��Ҫ���ܺ���
*************************************************************/

//���ӵ���ʾ(windows)
void ShowChessWindows(int p)
{
	switch (p)
	{
	case 0:
		printf("| "); break;
	case 1:
		printf("��"); break;
	case 2:
		printf("��"); break;
	case 3:
		printf("+ "); break;
	case 4:
		SetConsoleTextAttribute(hOut, FOREGROUND_RED);
		printf("��");
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		break;
	case 5:
		SetConsoleTextAttribute(hOut, FOREGROUND_RED);
		printf("�h"); 
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		break;
	case 6:
		SetConsoleTextAttribute(hOut, FOREGROUND_RED);
		printf("܇"); 
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		break;
	case 7:
		SetConsoleTextAttribute(hOut, FOREGROUND_RED);
		printf("�R"); 
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		break;
	case 8:
		SetConsoleTextAttribute(hOut, FOREGROUND_RED);
		printf("��"); 
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		break;
	case 9:
		SetConsoleTextAttribute(hOut, FOREGROUND_RED);
		printf("��"); 
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		break;
	case 10:
		SetConsoleTextAttribute(hOut, FOREGROUND_RED);
		printf("˧"); 
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		break;
	case 11:
		printf("��"); break;
	case 12:
		printf("��"); break;
	case 13:
		printf("��"); break;
	case 14:
		printf("��"); break;
	case 15:
		printf("��"); break;
	case 16:
		printf("ʿ"); break;
	case 17:
		printf("��"); break;
	default:
		break;
	}
}

//���ӵ���ʾ(linux)
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
		printf("\033[31;m��\033[0m"); break;
	case 5:
		printf("\033[31;m�h\033[0m"); break;
	case 6:
		printf("\033[31;m܇\033[0m"); break;
	case 7:
		printf("\033[31;m��\033[0m"); break;
	case 8:
		printf("\033[31;m��\033[0m"); break;
	case 9:
		printf("\033[31;m��\033[0m"); break;
	case 10:
		printf("\033[31;m˧\033[0m"); break;
	case 11:
		printf("��"); break;
	case 12:
		printf("��"); break;
	case 13:
		printf("��"); break;
	case 14:
		printf("��"); break;
	case 15:
		printf("��"); break;
	case 16:
		printf("ʿ"); break;
	case 17:
		printf("��"); break;
	default:
		break;
	}
}


//��ӡ����
void ShowQipan(int wl)
{
	int a, b,c;
	if (wl == 1)           //ϵͳ�ж�
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


//�����ƶ�
void Chessmove(int a,int b,int c,int d)
{
	if (QiPan[c][d] == Shuai)  winer = 2;       //�жϽ��Ƿ�����
	if (QiPan[c][d] == King) winer = 1;
	QiPan[c][d] = QiPan[a][b];              //�ƶ�����
	if ((b == 0 || b == 8) && (a < 4 || a>5))            //�����ƶ���ԭ����λ�ûָ�����
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
�������ƶ�����
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
		//�ж��ֽ���
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
�췽���ӵ��ƶ���������˧��
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
	printf("�췽����ָ�");
	for (int i = 0; i < 1;)
	{
		fflush(stdin);
		scanf("%d%d", &line, &column);
		line = line - 11;
		column = column - 11;
		a = line/10; b = line % 10; c = column/10; d = column % 10;
		if (a > 9 ||  a< 0 || b > 8 || b < 0 || c>9 ||c < 0 ||d >8 || d <0 < 0||line==column||(QiPan[c][d]>3&&QiPan[c][d]<11))
		{
			printf("����ָ���������������룺");
		}
		else
		{
			exist = QiPan[a][b];
			if (exist > 10 || exist < 4)
			{
				printf("\n��λ��û�����ӻ����Ӳ��ɶ�������������ָ�");
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
						printf("Υ��������Чָ������䣺");
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
						printf("Υ��������Чָ������䣺");
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
						printf("Υ��������Чָ������䣺");
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
						printf("Υ��������Чָ������䣺");
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
						printf("Υ��������Чָ������䣺");
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
						printf("Υ��������Чָ������䣺");
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
						printf("Υ��������Чָ������䣺");
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
�ڷ��ƶ����ӣ�������˧��
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
	printf("�ڷ�����ָ�");
	for (int i = 0; i < 1;)
	{
		fflush(stdin);
		scanf("%d%d", &line, &column);
		line = line - 11;
		column = column - 11;
		a = line / 10; b = line % 10; c = column / 10; d = column % 10;
		if (a > 9 || a< 0 || b > 8 || b < 0 || c>9 || c < 0 || d >8 || d <0 < 0 || line == column || (QiPan[c][d]>10 && QiPan[c][d]<=17))
		{
			printf("����ָ���������������룺");
		}
		else
		{
			exist = QiPan[a][b];
			if (exist < 11)
			{
				printf("\n��λ��û�����ӻ����Ӳ��ɶ�������������ָ�");
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
						printf("Υ��������Чָ������䣺");
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
						printf("Υ��������Чָ������䣺");
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
						printf("Υ��������Чָ������䣺");
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
						printf("Υ��������Чָ������䣺");
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
						printf("Υ��������Чָ������䣺");
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
						printf("Υ��������Чָ������䣺");
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
						printf("Υ��������Чָ������䣺");
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
	for (int t = 0; t < 1;)     //�˵�
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
	if(wl==1)	hOut = GetStdHandle(STD_OUTPUT_HANDLE);   //������ɫ�ľ��
	ChuShiHuaQiPan();   //���̳�ʼ��


	while (1)
	{
		if (player == 1)
		{
			ShowQipan(wl);      //�������
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
				printf("\n\n�췽��ʤ��\n\n"); break;
			}
			else
			{
				ShowQipan(wl);
				printf("\n\n�ڷ���ʤ��\n\n"); break;
			}
		}
		else
		{
			player = (-1)*player;
		}

	}

	return 0;
}