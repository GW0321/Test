//��Ȱ���� IT ���� 
//�Ѽ����б� 2371389 �̱Կ�
//Ŀ�� ���Ǳ� ���α׷�

#include<stdio.h>
int get_money(int money);
void menu(int m);
int buy(int m);
int more(void);

int main(void)
{
	int money = 0;																	//���Աݾ��� �����ϴ� ����

	printf("*******************\n");												//���۽� �޴� �� ���� ȭ���� ����
	printf("�ͽ�Ŀ��   : 1000��\n\n�Ƹ޸�ī�� : 3000��\n\nī���   : 4000��\n");
	printf("*******************\n\n");

start:																				//����ڰ� ���ϴ� ��ŭ �̰����� �ݺ�
	do {																			//���ʷ� ���� ���Թް�, �ݾ��� 1000�� �̻����� �ɶ� ���� �ݺ�
		money = get_money(money);
	} while (money < 1000);
	
	menu(money);
	int left = buy(money);
	money = left;
	int choice=more();

	if (choice == 1)
		goto start;
	else
		goto end;
	
end:
	printf("����ƽ��ϴ�. ��ȯ��: %d\n\n", left);									//�������� ����.
	return 0; 
	
}
int get_money(int money)		 													//���Ե� ���� ����ϴ� �Լ�
{
	int add;
	printf("�ݾ��� ����(1000,5000,10000): ");
	scanf("%d", &add);
	printf("����ݾ�: %d\n", money + add);
	return money + add;
}
void menu(int m)  
{
	if (m < 3000&& m >= 1000)				  		 											//���Ե� �ݾ׿� ���� �ֹ� ������ �޴����� ������
		printf("\n\n(1)�ͽ�Ŀ�� �ֹ� ����. ����(0)\n\n");
	else if (m < 4000)
		printf("\n\n(1)�ͽ�Ŀ��, (2)�Ƹ޸�ī�� �ֹ� ����. ����(0)\n\n");
	else 
		printf("\n\n(1)�ͽ�Ŀ��, (2)�Ƹ޸�ī��, (3)ī��� �ֹ� ����. ����(0)\n\n");
}
int buy(int m)
{
	int num;																		//���� ��ȣ�� �޾Ƽ� ���Ե� �ݾ׿��� ����
	printf("�ֹ��� �޴� �Է�(��ȣ): ");
	scanf("%d", &num);
	printf("\n\n");

	switch (num) {																	//���� ������ ���� �ش�ݾ��� ���Ե� �ݾ׿��� ����
	case 0:
		printf("�Ž����� %d���� ��ȯ�ƽ��ϴ�.\n\n",m);
		m = 0; 
		break;
	case 1:
		m -= 1000;
		printf("�ͽ�Ŀ�ǰ� ���Խ��ϴ�.\n");
		printf("��밡�ɱݾ�: %d\n\n", m);
		break;
	case 2:
		m -= 3000;
		printf("�Ƹ޸�ī�밡 ���Խ��ϴ�.\n");
		printf("��밡�ɱݾ�: %d\n\n", m);
		break;
	case 3:
		m -= 4000;
		printf("ī��󶼰� ���Խ��ϴ�.\n");
		printf("��밡�ɱݾ�: %d\n\n", m);
		break;
	default: 
		break;
	}
	return m;
}

int more(void)																		//������� ���ÿ� ���� ������ �ݺ�
{
	int cho;
	printf("�߰�(1),����(2): ");
	scanf("%d", &cho);
	printf("\n\n");
	return cho;

}