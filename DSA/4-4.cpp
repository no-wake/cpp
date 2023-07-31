#include<iostream>
#include<stack>
#include <time.h>
using namespace std;

typedef enum {AVAILABLE,ROUTE,BACKTRACKED,WALL} Status;
typedef enum {UNKNOWN,EAST,SOUTH,WEST,NORTH,NO_WAY} ESWN;

inline ESWN nextESWN(ESWN eswn){return ESWN(eswn+1);}
static int ncheck, nback, length;
struct Cell
{
    int x,y;
    Status status;

    ESWN incoming,outgoing;
};

#define Laby_max 24

Cell laby[Laby_max][Laby_max];

//邻格查询
inline Cell* neighbor(Cell *cell){
    switch (cell->outgoing)
    {
    case EAST:return cell+Laby_max;
    case WEST:return cell-Laby_max;
    case SOUTH:return cell+1;
    case NORTH:return cell-1;
    default:exit(-1);
    }
}

//邻格转入
inline Cell* advance(Cell *cell){
    Cell* next;
    switch(cell->outgoing){
        case EAST:next=cell+Laby_max;next->incoming=WEST;next->x = cell->x + 1; break;
        case SOUTH:next=cell+1;next->incoming=NORTH;next->y = cell->y + 1; break;
        case WEST:next=cell-Laby_max;next->incoming=EAST;next->x = cell->x - 1; break;
        case NORTH:next=cell-1;next->incoming=SOUTH;next->y = cell->y - 1; break;
        default:exit(-1);
    }
    return next;
}

bool labyrinth(Cell Laby[Laby_max][Laby_max],Cell* s,Cell* t){
    if((AVAILABLE!=s->status)||(AVAILABLE!=t->status)) return false;
    stack<Cell*> path;
    s->incoming=UNKNOWN;
    s->status=ROUTE;
    path.push(s);


    /*do{
        Cell* c=path.top();
        if(c==t)return true;
        while(NO_WAY>(c->outgoing=nextESWN(c->outgoing)))
        {
           
            if(AVAILABLE==neighbor(c)->status)break;
        
        }
        if(NO_WAY<=c->outgoing)
        {
            c->status=BACKTRACKED;
            c=path.pop();
        }
        else{
            path.push(c);
            c=advance(c);
            c->outgoing=UNKNOWN;
            c->status=ROUTE;
        }
        }while(!path.empty());
        return false;
        */

       do
	{
		Cell *c = path.top();  //c是指向栈顶元素的指针，用于处理当前栈顶的节点数据
		if (c == t)
		{
			length = path.size();
			return true;  //迷宫的最终条件，找到终点
		}
		while (NO_WAY > (c->outgoing = nextESWN(c->outgoing)))  //将c的出方向改为nextESWN枚举中的下个元素（未知，东南西北，无路）
			if (AVAILABLE == neighbor(c)->status) break;		//遍历c的各个邻居（东南西北方向），一旦有可行的就跳出，不然就循环
																//注意上面的循环终止条件，要么是邻居可走就跳出，要么就是走到了NO_WAY，也就是无路可走，所以跳出
																//同时注意，这里是while循环，回溯之后的cell过此段代码时，会先nextESWN到下一个方向，不会出现一个方向无限循环的情况
																//这里有个很有意思的想法，既然在检查方向，其肯定会检查到其incoming的方向，但是前面可以看到，只要走过的路都会标成ROUTE，所以不会干涉
		if (NO_WAY <= c->outgoing)  //说穿了，就是无路可走了，如同字面意思
		{
			c->status = BACKTRACKED;  //将当前的节点c，即对应的栈顶元素标记为BACKTRACKED，即已经走过但是试探全部失败回溯的点，类似于忒休斯的标志
			path.pop();  //栈顶元素出栈，但是cell c本质上还是存在的，没有删除。从实质上实现回溯
			nback++;
		}
		else
		{
			path.push(c = advance(c));   //将c根据前面试探可行的方向移动之后，将移动后的c入栈（此时的C已经是一个新的cell指针了，没有指向之前的栈顶元素了
			c->outgoing = UNKNOWN;  //新的c的出方向必然为未知
			c->status = ROUTE; //新的栈顶元素的标志改为ROUTE，表示进入路径试探了
			ncheck++;
		}
	} while (!path.empty());  //直到存储路径的path为空
	length = path.size();
	return false; 
}



static void printLabyCell(Cell* elem)
{
	printf("%d -> (%d, %d) -> %d\n",
		((Cell*)elem)->incoming,
		((Cell*)elem)->x,
		((Cell*)elem)->y,
		((Cell*)elem)->outgoing);
}

static int labySize;  //此处借用dascpp中邓公的随机迷宫生成程序
static Cell* startCell;
static Cell* goalCell;
static void randLaby()
{
	labySize = Laby_max / 2 + rand() % (Laby_max / 2); //生成一个随机size的迷宫
	/*DSA*/printf("Using a laby of size %d ...\n", labySize);
	for (int i = 0; i < labySize; i++)
		for (int j = 0; j < labySize; j++)
		{
			laby[i][j].x = i;
			laby[i][j].y = j;
			laby[i][j].incoming =
				laby[i][j].outgoing = UNKNOWN;
			laby[i][j].status = WALL; //边界格点必须是墙
		}
	for (int i = 1; i < labySize - 1; i++)
		for (int j = 1; j < labySize - 1; j++)
			if (rand() % 4) laby[i][j].status = AVAILABLE; //75%的格点为空可用
	startCell = &laby[rand() % (labySize - 2) + 1][rand() % (labySize - 2) + 1];
	goalCell = &laby[rand() % (labySize - 2) + 1][rand() % (labySize - 2) + 1];
	startCell->status = goalCell->status = AVAILABLE; //起始格点必须可用
}

//这里同样借用的是邓公的迷宫显示代码
/******************************************************************************************
* 显示迷宫
******************************************************************************************/
static void displayLaby() { //┘└┐┌│─
	static const char*   pattern[5][5] =
	{
		"┼", "┼", "┼", "┼", "┼",
		"┼", " ", "┌", "─", "└",
		"┼", "┌", " ", "┐", "│",
		"┼", "─", "┐", " ", "┘",
		"┼", "└", "│", "┘", " "
	};
	//system("cls");
	printf("  ");
	for (int j = 0; j < labySize; j++)
		(j < 10) ? printf("%2X", j) : printf(" %c", 'A' - 10 + j);
	printf("\n");
	for (int j = 0; j < labySize; j++)
	{
		(j < 10) ? printf("%2X", j) : printf(" %c", 'A' - 10 + j);
		for (int i = 0; i < labySize; i++)
			if (goalCell == &laby[i][j])
				printf("﹩");
			else
				switch (laby[i][j].status)
				{
				case WALL:  printf("██");   break;
				case BACKTRACKED: printf("○ ");   break;
				case AVAILABLE: printf("  ");   break;
				default: printf("%s ", pattern[laby[i][j].outgoing][laby[i][j].incoming]);  break;  

				}
		printf("\n");
	}
}

int main()
{
	srand(int(time(0)));  //根据系统时间确定随机种子，保证每次执行都不同
	randLaby();
	if (labyrinth(laby, startCell, goalCell))
		cout << "true" << endl;
	else
		cout << "false" << endl;
	displayLaby();
	cout << "start: " << "(" << startCell->x << "," << startCell->y << ")"
		<< "  " << "终点: " << "(" << goalCell->x << "," << goalCell->y << ")" << endl;
	cout << "check times: " << ncheck << " back times: " << nback << endl;
	cout << "length of path is " << length << endl;
	return 0;
}
