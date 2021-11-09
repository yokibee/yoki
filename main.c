#include<stdio.h>
#include<string.h>
#include<stdlib.h>


struct Student {                                                     //ͨ���ṹ������ѧ����Ϣ
	long num;
	char name[20];
	float score[3];
	//float aver;
	struct Student *next;
};
int main(void) {                                                     //������
	void Window();
	void Choose();
	Window();                                                        //������ҳ�� 
	Choose();                                                        //�������̨ 
}
void Window() {                                                      //�˵�����
	printf("-ѧ����Ϣ����ϵͳ-\n");
	printf(" ---1����ʼ����Ϣ---\n");
	printf(" ---2�������ļ�---\n");
	printf(" ---3��������Ϣ---\n");
	printf(" ---4���Ķ���Ϣ---\n");
	printf(" ---5��ɾ����Ϣ---\n");
	printf(" ---6����ѯ��Ϣ---\n");
	printf(" ---7����ʾ��Ϣ---\n");
	printf(" ---0���˳�ϵͳ---\n");
	printf("-�ǳ���л����ʹ��-\n");
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
	printf("��ѡ����Ҫ���еĲ�����\n");
	scanf("%d", &button);
	while (button) {
		if (button == 1) {
			head = creat();                                         //¼��ѧ����Ϣ 
		}
		else if (button == 2) {
			reserve(head);                                        //��ѧ���ɼ��Զ����Ƶ���ʽ��ŵ��ļ��� 
		}
		else if (button == 3) {
			Add(head);                                            //�����µ�ѧ����Ϣ 
		}
		else if (button == 4) {
			Change(head);                                         //�Ķ�ĳ��ѧ������Ϣ 
		}
		else if (button == 5) {
			head = (Del(head));                                     //ɾ��ĳ��ѧ������Ϣ 
			reserve(head);
		}
		else if (button == 6) {
			Find(head);                                           //����ĳ��ѧ������Ϣ 
		}
		else if (button == 7) {
			print(head);                                          //��ʾ�ļ��е�ѧ����Ϣ 
		}
		else if (button == 0) {
			break;                                                //�˳�ϵͳ 
		}
		printf("��ѡ����Ҫ���еĲ�����\n");
		scanf("%d", &button);
	}

}

struct Student *creat()
{                                                 //¼��ѧ����Ϣ
	struct Student *head, *p1, *p2;
	int n = 1;
	printf("������ѧ������Ϣ(����5����ϢΪ0ʱ��Ϣ����):\n");
	p2 = (struct Student *)(malloc(sizeof(struct Student)));
	p1 = p2;
	scanf("%ld%s%f%f%f", &p1->num, p1->name, &p1->score[0], &p1->score[1], &p1->score[2]);
	while(p1 -> num != 0 )
	{
		if(n==1)	// ����ֵ
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

	printf("¼����Ϣ����ɣ�\n");
	return head;
}

// �����ļ�
void reserve(struct Student *head) 
{                                    //��ѧ����Ϣ�Զ����Ƶķ�ʽд���ļ���
	FILE *fp;
	struct Student *p, *p1, stu[3];
	if ((fp = fopen("stud.txt", "wb")) == NULL) {
		printf("�ļ���д����");
		exit(0);
	}
	p = head;
	while (p != NULL) {
		if (fwrite(p, sizeof(sizeof(struct Student)), 1, fp) != 1) {			                  //���ļ���д���ݺͶ�ȡ���ݶ�����Ҫд��һ��
		}
		p = p->next;
	}
	fclose(fp);
	printf("ѧ����Ϣ�Ѷ����ļ���\n");
	return;
}

// ������Ϣ
void Add(struct Student *head) 
{
	void reserve(struct Student *head); ;
	struct Student *p1, *p2 = NULL, *pNew;
	long num;
	printf("������Ҫ�����λ�ã�ǰһ��ѧ����ѧ�ţ�:");
	scanf("%ld", &num);
	p1 = head;
	while (p1 != NULL)
	{
		if (p1->num == num) {
			p2 = p1->next;
			pNew = (struct Student *)(malloc(sizeof(struct Student)));
			printf("ѧ��:");
			scanf("%ld", &pNew->num);
			printf("����:");
			scanf("%s", pNew->name);
			printf("�ɼ�:");
			scanf("%f%f%f", &pNew->score[0], &pNew->score[1], &pNew->score[2]);

			p1->next = pNew;
			pNew->next = p2;
			break;
		}
		p1 = p1->next;
	}
	reserve(head);
	printf("����ѧ����Ϣ�ɹ���\n");
	return;
}

// ɾ����Ϣ
struct Student *Del(struct Student *head) 
{
	struct Student *p, *p1;
	long num;
	printf("������Ҫɾ��ѧ����ѧ��:");
	scanf("%ld", &num);
	p = head;
	while (p != NULL) {
		if (head->num == num) {
			head = head->next;                                   //�ȿ���һ���Ƿ���Ҫɾ���ĳɼ�
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
	printf("ɾ��ѧ����Ϣ�ɹ���\n");
	return head;
}

// �ı���Ϣ
void Change(struct Student *head) {                               //�Ķ�ѧ���ĳɼ�
	void reserve(struct Student *head);
	struct Student *p, newMessage;
	long Name;
	long num;
	char nam[20];
	printf("������Ҫ�޸ĵ�ѧ��ѧ��:");
	scanf("%ld", &Name);
	p = head;
	while (p != NULL) {
		if (p->num == Name) {
			break;                                              //Ϊʲô����ʾ��Ч�����飬�ַ���֮������==���и�ֵ�𣿣���ɵ��
		}
		p = p->next;
	}
	if (p == NULL) {
		printf("δ�ҵ���ѧ����Ϣ!\n");
		return;
	}
	printf("\n�������µ���Ϣ:");
	printf("ѧ��:");
	scanf("%ld", &num);
	printf("����:");
	scanf("%s", nam);
	p = head;
	while (p != NULL) {
		if (p->num == Name) {
			p->num = num;
			strcpy(p->name, nam);                                  //Ϊʲô����ʾ��Ч�����飬�ַ���֮������==���и�ֵ�𣿣���ɵ��
		}
		p = p->next;
	}
	reserve(head);
	printf("�޸�ѧ����Ϣ�ɹ���\n");
	return;                                                      //���±��浽�ļ���
}

// ������Ϣ
void Find(struct Student *head) 
{                                    //����ѧ����Ϣ
	struct Student *p;
	float num;
	p = head;
	printf("��������Ҫ���ҵ�ѧ����ѧ����Ϣ:");
	scanf("%f", &num);
	while (p != NULL) {
		if (p->num == num) {
			printf("ѧ��:%ld  ����:%s  �ɼ�:%.2f %.2f %.2f ", p->num, p->name, p->score[0], p->score[1], p->score[2]);
			break;
		}
		p = p->next;
	}
	if (p == NULL) {
		printf("δ�ҵ���ѧ����Ϣ!\n");
	}
	printf("����ѧ����Ϣ������\n");
	return;
}


// ��ʾ��Ϣ
void print(struct Student *head) {                                   //���ļ��������ѧ������Ϣ
	printf("----------------ѧ����Ϣ----------------\n");
	printf(" ѧ��     ����    ����    ��ѧ   Ӣ��\n");
	struct Student *p1;
	FILE *fp;
	fp = fopen("stud.txt", "rb");
	p1 = head;
	while (p1 != NULL) {
		if (fread(p1, sizeof(sizeof(struct Student)), 1, fp) != 0) {                        //���ļ��е������Զ����Ƶķ�ʽ��ȡ������ʾ����Ļ��
			printf(" %3ld%10s %6.2f   %5.2f   %5.2f\n", p1->num, p1->name, p1->score[0], p1->score[1], p1->score[2]);
		}
		p1 = p1->next;
	}
	fclose(fp);
	return;
}

