#include <windows.h>
#include <iostream>
#include<stdio.h>
#include<stdbool.h>
#include<conio.h>
#include<windows.h>
#include<time.h>
#include<ctype.h>
#define COMMON_X 16
#define COMMON_Y 16
#define COMMON_M 40
#define CLICK 0
#define SIGN 1
#define MINE '*'
#define SPACE ' '
#define UNKNOWN '#'
#define FLAG '@'
#define WRONG 'x'
#define RED FOREGROUND_RED
#define GREEN FOREGROUND_GREEN
#define BLUE FOREGROUND_BLUE
#define B_BLUE BACKGROUND_BLUE
#define B_RED BACKGROUND_RED
#define B_GREEN BACKGROUND_GREEN
#define color(X,Y) SetConsoleTextAttribute(X,Y)


struct 
{
	int x;
	int y;
	int mine;
}parameter;

struct 
{
	char appearance;
	int count;
}arr[24][30];

struct 
{
	int x;
	int y;
}cursor=
{
	5,
	5,
};

bool win =false;
bool game_over =false;
int mine;
 
void initialization(void);
int get_choice(void);
void print_game(void);
void print_all(void );
int get_next(void);
void move(int next);
void show_n_char(int n,char ch);


int main()
{
	int choice;
	int next;
	bool first_time=true;
	
	srand(time(0));
	while(choice=get_choice()!=2)
	{
		if(first_time == true)
		{
			system("cls");
			printf("上移光标: ↑      下移光标: ↓\n");
			printf("左移光标: ←      右移光标: →\n");
			printf("标记    ：z          挖      ：x\n\n");
			system("pause"); 
			
		}
		initialization();
		while(!game_over && !win)
		{
			print_game();
			if(!game_over && !win)
			{
				printf("还剩%d个雷",mine); 
			}
			next=get_next();
			move(next);
			
		}
		print_game();//all
		if(win == true)
		{
			print_game();
			printf("You win!\n");
			
		}
		else
		{
			printf("You lose!\n");
		}
		Sleep(1000);
		system("pause");
		cursor.x = cursor.y = 5;
		game_over = false;
		win = false;
		 
	}
	return 0;
	
}


int get_choice(void )
{
	int answer;
	system("color 7");
	system("cls");
	printf("1) 开始游戏\n2) 退出");
	while((answer = getch()) != '1' && answer != '2') continue;
	parameter.x = COMMON_X;
	parameter.y = COMMON_Y;
	parameter.mine = mine = COMMON_M;		
	if(answer == '1')
	{
		system("cls");
		printf("Ready ? Go!\n");
	}
	return (answer-48);
	
}

void show_n_char(int n,char ch)
{
	while(n--)
	{
		putchar(ch);
	}
}

void print_game(void )
{
	int x,y;
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	
	system("cls");
	color(out , B_RED|B_BLUE|B_GREEN);
	show_n_char (4+2*parameter.y,' ');
	putchar('\n');
	for(x=0;x<parameter.x;x++)
	{
		show_n_char(2, ' ');
		color(out,RED|BLUE|GREEN);
		for(y=0;y<parameter.y;y++)
		{
			if(x == cursor.x && y == cursor.y)	color(out,B_GREEN);
			else if (arr[x][y].appearance == MINE)	color(out,B_RED);
			else if (arr[x][y].appearance == WRONG)	color(out,B_RED);
			putchar(arr[x][y].appearance);
			//cout<<arr[x][y].appearance;
			putchar(' ');
			if((x==cursor.x && y==cursor.y && !game_over) || arr[x][y].appearance == MINE || arr[x][y].appearance==WRONG)
				color(out,RED|BLUE|GREEN);
		}
		color(out , B_RED|B_BLUE|B_GREEN);
		show_n_char(2, ' ');
		putchar('\n');
		
	}
	show_n_char(4+2*parameter.y,' ');
	putchar('\n');
	color(out,RED|BLUE|GREEN);
	
}

void initialization(void)
{
	int x;
	int y;
	int count=0;
	int temp;
	
	for(x=0;x<parameter.x;x++) 
	{
		for(y=0;y<parameter.y;y++)
		{
			arr[x][y].appearance = UNKNOWN; 
			arr[x][y].count =0;
		}
	}
	while(count < parameter.mine && count <parameter.x*parameter.y)
	{
		x= rand() % parameter.x;
		y= rand() % parameter.y;
		if(arr[x][y].count != -1)
		{
			arr[x][y].count = -1;
			count++;//生成的地雷数目 
		}
	}
	for(x = 0,temp = 0;x<parameter.x;x++)
	{
		for(y=0;y<parameter.y;y++,temp=0)
		{
			if(x>0)
				if(arr[x-1][y].count == -1)	temp++;
			if(y>0)
				if(arr[x][y-1].count == -1)	temp++;
			if(x<(parameter.x-1))
				if(arr[x+1][y].count == -1)	temp++;
			if(y<(parameter.y-1))
				if(arr[x][y+1].count == -1)	temp++;
			if((x>0) && (y>0))
				if(arr[x-1][y-1].count == -1)	temp++;
			if(x<(parameter.x-1) && y<(parameter.y-1))
				if(arr[x+1][y+1].count == -1)	temp++;
			if( x<(parameter.x-1) && (y>0))
				if(arr[x+1][y-1].count == -1) 	temp++;
			if(y<(parameter.y-1) && (x>0))
				if(arr[x-1][y+1].count ==-1) temp++;
			if(arr[x][y].count != -1)	 arr[x][y].count = temp;//判断八个面的地雷数目 
				
				
		}
	}
	
}
int get_next(void)//下一步判定 
{
		int answer;
		
		if((answer = tolower(getch()))==224)
			answer = getch();
		else
		{
			while(answer != 'z' && answer != 'x')
				answer = tolower(getch());
		}
		return answer;
		
}
	
void move(int next)
{
	int x,y;
	int count;
	int temp;
	
	if (next == 'z'||next == 'x')
	{
		if (next == 'z')
		{
			if (arr[cursor.x][cursor.y].appearance == FLAG)
			{
				arr[cursor.x][cursor.y].appearance = UNKNOWN;
				mine++;	
			}
			else if (arr[cursor.x][cursor.y].appearance == UNKNOWN)
			{
				arr[cursor.x][cursor.y].appearance = FLAG;
				mine--;
			}
		}
		else if (arr[cursor.x][cursor.y].appearance != FLAG)
		{
			if (next == 'x'&&arr[cursor.x][cursor.y].count == -1)
			{
				game_over = 1;
				for (x = 0;x < parameter.x;x++)
				{
					for (y = 0;y < parameter.y;y++)
					{
						if (arr[x][y].count == -1&&arr[x][y].appearance != FLAG)
							arr[x][y].appearance = MINE;
						if (arr[x][y].count != -1&&arr[x][y].appearance ==  FLAG)
							arr[x][y].appearance = WRONG;
						if(arr[x][y].count != -1 && arr[x][y].appearance != FLAG && arr[x][y].count != 0)
							arr[x][y].appearance=arr[x][y].count+'0';
						if(arr[x][y].count != -1 && arr[x][y].appearance != FLAG && arr[x][y].count == 0)
							arr[x][y].appearance = SPACE;
					}
				}
			}
			else if (next == 'x')
			{
				arr[cursor.x][cursor.y].appearance = arr[cursor.x][cursor.y].count + 48;
				if (arr[cursor.x][cursor.y].appearance == '0')
				{
					arr[cursor.x][cursor.y].appearance  = SPACE;
					temp = 1;
					while (temp == 1)
					{
						temp = 0;
						for (x = 0;x < parameter.x ;x++)
						{
							for (y = 0;y < parameter.y;y++,count = 0)
							{
								if (arr[x][y].appearance  == UNKNOWN)
								{
								if (x != 0)
									if (arr[x-1][y].appearance  == SPACE)
										count = 1;
								if (y != 0)
									if (arr[x][y-1].appearance == SPACE)
										count = 1;
								if (x != (parameter.x-1))
									if (arr[x+1][y].appearance == SPACE)
										count = 1;
								if (y != (parameter.y-1))
									if (arr[x][y+1].appearance == SPACE)
										count = 1;
								if ((x != 0)&&(y != 0))
									if (arr[x-1][y-1].appearance == SPACE)
										count = 1;
								if ((x != (parameter.x-1))&&(y != (parameter.y-1)))
									if (arr[x+1][y+1].appearance == SPACE)
										count = 1;
								if ((x != (parameter.x-1))&&(y != 0))
									if (arr[x+1][y-1].appearance == SPACE)
										count = 1;
								if ((y != (parameter.y-1))&&(x != 0))
									if (arr[x-1][y+1].appearance == SPACE)
										count = 1;
								if (count == 1&&arr[x][y].count != -1)
								{
									arr[x][y].appearance = arr[x][y].count+48;
									temp = 1;
								}
								if (arr[x][y].appearance == '0')
								{
									arr[x][y].appearance = SPACE;
									
								}
								}
											
							} 

						}	
					}
				}
			}
			if (!game_over)
			{
				for (x = 0,count = 0;x < parameter.x;x++)
				{
					for (y = 0;y < parameter.y;y++)
					{
						if (arr[x][y].appearance  != UNKNOWN&&arr[x][y].appearance != FLAG)
							count++;
					}
				}
				if (count == parameter.x*parameter.y - parameter.mine)
				{ 
					win = true;
					for (x = 0,count = 0;x < parameter.x;x++)
					{
						for (y = 0;y < parameter.y;y++)
						{
							if (arr[x][y].count == -1)
								arr[x][y].appearance  = FLAG;
						}
					}
				} 
			}
		}
	}
	else
	{
		if (next == 72)
			cursor.x = (cursor.x == 0)?cursor.x:cursor.x-1;
		else if (next == 80)
			cursor.x = (cursor.x == parameter.x-1)?cursor.x:cursor.x+1;
		else if (next == 75)
			cursor.y = (cursor.y == 0)?cursor.y:cursor.y-1;
		else
			cursor.y = (cursor.y == parameter.y-1)?cursor.y:cursor.y+1;
	}
}















