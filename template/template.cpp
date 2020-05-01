#define init_size 100
#define listincrement 10
#define error 0
#define OK 1
typedef  bool Status;
typedef struct
{
	char no[8];
	char name[20];
	double score;
}Student;
typedef Student ElemType;
typedef struct
{
	ElemType *elem;
	int length;
	int listsize;
}Sqlist;
ElemType a;
//建立表
Status InitList(Sqlist &stu, int num)
{
	
}
//输入元素
void input_stu()
{
	
}
//在第i个元素前插入元素
Status listinsert(Sqlist &stu, int i, ElemType a)
{
	
}
//表初始化
Status Initinlist(int num, Sqlist &stu)
{
	
}
//通过名字查找
Status searchByName(char *name, Sqlist &stu) {
	
}
//通过位置查找
Status searchByPos(int i, Sqlist &stu) {
	
}
//按照元素位置删除
Status deleteByPos(int i, Sqlist &stu) {
	
}
//计算元素个数
void StuCount(Sqlist &stu) 
{
	
}
//通过信息删除
Status deleteByStu(ElemType _delStu, Sqlist &stu) 
{
	
}
//删除重复
void deleteDuplicate(Sqlist &stu) {
	
}
//遍历输出
void show_all(Sqlist &stu)
{
	
}
