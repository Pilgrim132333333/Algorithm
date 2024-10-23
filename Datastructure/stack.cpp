#include<iostream>
//堆相当于一个完全二叉树
//将无序数列整理为一个堆，可以利用分治思想
//直接找到一个数字应该处于的位置是困难的，所以我们牺牲空间复杂度
//创建一个新的中间数组，使每次在中间数组插入一个元素，都将其整理为一个堆

class Stack
{
    private:
    int* init;
    int size;
    int* sorted;

    //下滤法，将堆顶部元素正确插入到堆中，并按大根堆排序
    void xia_lv_Solution(int input[],int size)
    {
        int i=0;
        int left_leaf=2*i+1;
        int right_leaf=2*i+2;
        int middle;
        while(left_leaf<size)
        {
            if(right_leaf<size)
            {
                middle=input[left_leaf]>input[right_leaf] ? left_leaf : right_leaf;
            }
            else{
                middle=left_leaf;
            }
          

            if(input[middle]>input[i])
            {
                std::swap(input[i],input[middle]);
                i=middle;
            }
            else{
                break;
            }
            left_leaf=2*i+1;
            right_leaf=2*i+2;
        }
    }
    //这个方法用不了，数组都是在末尾插入元素，所以应该用上滤法，别看了
    //实际上也能用但很麻烦

    //上滤法：在堆底部插入一个数据，比父节点大便交换，这样可以插入正确位置
    void shang_lv_Solution(int input[],int size)
    {
        int i=size-1;
        while(i>0) //i相当于插入元素现在所处位置
        {
            if(input[i]>input[i/2])  //判断插入元素是否大于其父节点
            {
                std::swap(input[i],input[i/2]);
            }
            else{
                break;
            }
            i=i/2;
        }

    }

    public:
    //构造函数
    //需要在创建实例时输入初始数组，和数组大小
    Stack(int* init,int size,char type):init(init),size(size) {
        sorted=new int[size]; //声明sorted变量，用于储存排序好的数组

        if(type=='m')
        {
            stack_struct_maxroot(); //调用构造大根堆的函数，将排序好的数组复制给sorted变量
        }
    };

    //析构函数
    ~Stack(){
        delete[] sorted;
    }

    //大根型排序
    void stack_struct_maxroot()
    {
        int* input = new int[this->size]; // 创建一个新的动态数组
        std::copy(init, init + size, input); //数组不能直接用等于号赋值
        int* result=new int[size];
        int count=0; //此变量用于在每次插入元素后，记录result数组中一共有几个元素
        for(int i=0;i<size;i++)
        {
            if(i==0)
            {
                result[0]=input[0]; //初始化
                count++; //相当于传输shanglv_Solution的size
            }
            else{
                result[i]=input[i]; //插入新元素
                count++; //size of result[] +1
                shang_lv_Solution(result,count); //将新元素插入到合适位置
            }
        }

        std::copy(result, result + size, sorted); //将result[]复制到sorted中
        
        delete[] input;
        delete[] result;
    }

    //打印sorted数组
    void print()
    {
        for(int i=0;i<size;i++)
        {
            printf("%d\n",sorted[i]);
        }
    }


};



//test
int main()
{
    int input[]={1,6,5,8,7,2,5,7,9,7};
    int n=sizeof(input)/sizeof(input[0]);
    Stack test(input,n,'m');
    test.print();
    

}
