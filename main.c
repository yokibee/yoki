#include<stdio.h>
#include<string.h>
#include<stdlib.h>


struct Student {                                                     //通过结构体输入学生信息
	long num;
	char name[20];
	float score[3];
	//float aver;
	struct Student *next;
};
int main(void) {                                                     //主函数
	void Window();
	void Choose();
	Window();                                                        //进入首页面 
	Choose();                                                        //程序控制台 
}
void Window() {                                                      //菜单界面
	printf("-学生信息管理系统-\n");
	printf(" ---1、初始化信息---\n");
	printf(" ---2、存入文件---\n");
	printf(" ---3、增加信息---\n");
	printf(" ---4、改动信息---\n");
	printf(" ---5、删除信息---\n");
	printf(" ---6、查询信息---\n");
	printf(" ---7、显示信息---\n");
	printf(" ---0、退出系统---\n");
	printf("-非常感谢您的使用-\n");
	return;
}
void Choose() {
	struct Student *creat();
	void reserve(struct Student *head);
	void print(struct Student *head);
	void Add(struct Student *head);
	void Change(struct Student *head);
	void Find(struct Student *head);
	struct Student *Del(struct Student *head);
	struct Student *head, *head1;
	int button;
	printf("请选择您要进行的操作：\n");
	scanf("%d", &button);
	while (button) {
		if (button == 1) {
			head = creat();                                         //录入学生信息 
		}
		else if (button == 2) {
			reserve(head);                                        //将学生成绩以二进制的形式存放到文件中 
		}
		else if (button == 3) {
			Add(head);                                            //增加新的学生信息 
		}
		else if (button == 4) {
			Change(head);                                         //改动某个学生的信息 
		}
		else if (button == 5) {
			head = (Del(head));                                     //删除某个学生的信息 
			reserve(head);
		}
		else if (button == 6) {
			Find(head);                                           //查找某个学生的信息 
		}
		else if (button == 7) {
			print(head);                                          //显示文件中的学生信息 
		}
		else if (button == 0) {
			break;                                                //退出系统 
		}
		printf("请选择您要进行的操作：\n");
		scanf("%d", &button);
	}

}

struct Student *creat()
{                                                 //录入学生信息
	struct Student *head, *p1, *p2;
	int n = 1;
	printf("请输入学生的信息(输入5个信息为0时信息结束):\n");
	p2 = (struct Student *)(malloc(sizeof(struct Student)));
	p1 = p2;
	scanf("%ld%s%f%f%f", &p1->num, p1->name, &p1->score[0], &p1->score[1], &p1->score[2]);
	while(p1 -> num != 0 )
	{
		if(n==1)	// 赋初值
		{
			head = p1;
			n=0;
		} 
		else 
		{
			p2->next = p1;
		}
		p2 = p1;
		p1 = (struct Student *)(malloc(sizeof(struct Student)));
		scanf("%ld%s%f%f%f",&p1->num,p1->name,&p1->score[0],&p1->score[1],&p1->score[2]);
	}
	p2->next=NULL;

	printf("录入信息已完成！\n");
	return head;
}

// 存入文件
void reserve(struct Student *head) 
{                                    //将学生信息以二进制的方式写到文件中
	FILE *fp;
	struct Student *p, *p1, stu[3];
	if ((fp = fopen("stud.txt", "wb")) == NULL) {
		printf("文件读写错误！");
		exit(0);
	}
	p = head;
	while (p != NULL) {
		if (fwrite(p, sizeof(sizeof(struct Student)), 1, fp) != 1) {			                  //往文件中写内容和读取内容都必须要写这一步
		}
		p = p->next;
	}
	fclose(fp);
	printf("学生信息已读入文件！\n");
	return;
}

// 增加信息
void Add(struct Student *head) 
{
	void reserve(struct Student *head); ;
	struct Student *p1, *p2 = NULL, *pNew;
	long num;
	printf("请输入要插入的位置（前一个学生的学号）:");
	scanf("%ld", &num);
	p1 = head;
	while (p1 != NULL)
	{
		if (p1->num == num) {
			p2 = p1->next;
			pNew = (struct Student *)(malloc(sizeof(struct Student)));
			printf("学号:");
			scanf("%ld", &pNew->num);
			printf("姓名:");
			scanf("%s", pNew->name);
			printf("成绩:");
			scanf("%f%f%f", &pNew->score[0], &pNew->score[1], &pNew->score[2]);

			p1->next = pNew;
			pNew->next = p2;
			break;
		}
		p1 = p1->next;
	}
	reserve(head);
	printf("增加学生信息成功！\n");
	return;
}

// 删除信息
struct Student *Del(struct Student *head) 
{
	struct Student *p, *p1;
	long num;
	printf("请输入要删除学生的学号:");
	scanf("%ld", &num);
	p = head;
	while (p != NULL) {
		if (head->num == num) {
			head = head->next;                                   //先看第一个是否是要删除的成绩
			free(p);
			break;
		}
		else {
			p1 = p;
			p1 = p->next;
			if (p1->num == num) 
			{
				p->next = p1->next;
				p = p1;
				free(p1);
				break;
			}
			p = p->next;
		}
	}
	printf("删除学生信息成功！\n");
	return head;
}

// 改变信息
void Change(struct Student *head) {                               //改动学生的成绩
	void reserve(struct Student *head);
	struct Student *p, newMessage;
	long Name;
	long num;
	char nam[20];
	printf("请输入要修改的学生学号:");
	scanf("%ld", &Name);
	p = head;
	while (p != NULL) {
		if (p->num == Name) {
			break;                                              //为什么会提示无效的数组，字符串之间能用==进行赋值吗？？大傻瓜
		}
		p = p->next;
	}
	if (p == NULL) {
		printf("未找到该学生信息!\n");
		return;
	}
	printf("\n请输入新的信息:");
	printf("学号:");
	scanf("%ld", &num);
	printf("姓名:");
	scanf("%s", nam);
	p = head;
	while (p != NULL) {
		if (p->num == Name) {
			p->num = num;
			strcpy(p->name, nam);                                  //为什么会提示无效的数组，字符串之间能用==进行赋值吗？？大傻瓜
		}
		p = p->next;
	}
	reserve(head);
	printf("修改学生信息成功！\n");
	return;                                                      //重新保存到文件中
}

// 查找信息
void Find(struct Student *head) 
{                                    //查找学生信息
	struct Student *p;
	float num;
	p = head;
	printf("请输入你要查找的学生的学号信息:");
	scanf("%f", &num);
	while (p != NULL) {
		if (p->num == num) {
			printf("学号:%ld  姓名:%s  成绩:%.2f %.2f %.2f ", p->num, p->name, p->score[0], p->score[1], p->score[2]);
			break;
		}
		p = p->next;
	}
	if (p == NULL) {
		printf("未找到该学生信息!\n");
	}
	printf("查找学生信息结束！\n");
	return;
}


// 显示信息
void print(struct Student *head) {                                   //从文件输出各个学生的信息
	printf("----------------学生信息----------------\n");
	printf(" 学号     姓名    语文    数学   英语\n");
	struct Student *p1;
	FILE *fp;
	fp = fopen("stud.txt", "rb");
	p1 = head;
	while (p1 != NULL) {
		if (fread(p1, sizeof(sizeof(struct Student)), 1, fp) != 0) {                        //将文件中的内容以二进制的方式读取并且显示到屏幕上
			printf(" %3ld%10s %6.2f   %5.2f   %5.2f\n", p1->num, p1->name, p1->score[0], p1->score[1], p1->score[2]);
		}
		p1 = p1->next;
	}
	fclose(fp);
	return;
}

