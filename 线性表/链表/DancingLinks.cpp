struct DLX_Node
{
    DLX_Node* up;
    DLX_Node* down;
    DLX_Node* left;
    DLX_Node* right;
    int row;
    int col;
    int count;
    int ele;

    //默认初始化函数
    DLX_Node(){
        up=nullptr;
        down=nullptr;
        left=nullptr;
        right=nullptr;
        col=-1;
        row=-1;
        ele=-1;
        count=0;
    }
};

struct DLX_Node table[N][N];
void init()
{
    //对第一列进行初始化
    for(int i=0;i<n;i++)
    {
        table[i][0].down=&table[i+1][0];
        table[i+1][0].up=&table[i][0];
        table[0][i].row=i;
        table[i][0].col=0;
        table[i+1][0].row=i+1;
        table[i+1][0].col=0;
    }
     
    //对第一行进行初始化
    for(int i=0;i<m;i++)
    {
        table[0][i].right=&table[0][i+1];
        table[0][i+1].left=&table[0][i];
        table[0][i].row=0;
        table[0][i+1].row=0;
        table[0][i].col=i;
        table[0][i+1].col=i+1;
    }
}

void addNode(int num,int x,int y)
{
    table[x][y]

}
