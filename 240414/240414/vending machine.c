//생활속의 IT 과제 
//한성대학교 2371389 이규원
//커피 자판기 프로그램

#include<stdio.h>
int get_money(int money);
void menu(int m);
int buy(int m);
int more(void);

int main(void)
{
	int money = 0;																	//투입금액을 저장하는 변수

	printf("*******************\n");												//시작시 메뉴 및 가격 화면을 구성
	printf("믹스커피   : 1000원\n\n아메리카노 : 3000원\n\n카페라떼   : 4000원\n");
	printf("*******************\n\n");

start:																				//사용자가 원하는 만큼 이과정을 반복
	do {																			//최초로 돈을 투입받고, 금액이 1000원 이상으로 될때 까지 반복
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
	printf("종료됐습니다. 반환액: %d\n\n", left);									//모든과정을 종료.
	return 0; 
	
}
int get_money(int money)		 													//투입된 돈을 계산하는 함수
{
	int add;
	printf("금액을 투입(1000,5000,10000): ");
	scanf("%d", &add);
	printf("현재금액: %d\n", money + add);
	return money + add;
}
void menu(int m)  
{
	if (m < 3000&& m >= 1000)				  		 											//투입된 금액에 따라 주문 가능한 메뉴들을 구별함
		printf("\n\n(1)믹스커피 주문 가능. 종료(0)\n\n");
	else if (m < 4000)
		printf("\n\n(1)믹스커피, (2)아메리카노 주문 가능. 종료(0)\n\n");
	else 
		printf("\n\n(1)믹스커피, (2)아메리카노, (3)카페라떼 주문 가능. 종료(0)\n\n");
}
int buy(int m)
{
	int num;																		//음료 번호를 받아서 투입된 금액에서 차감
	printf("주문할 메뉴 입력(번호): ");
	scanf("%d", &num);
	printf("\n\n");

	switch (num) {																	//음료 종류에 따라 해당금액을 투입된 금액에서 차감
	case 0:
		printf("거스름돈 %d원이 반환됐습니다.\n\n",m);
		m = 0; 
		break;
	case 1:
		m -= 1000;
		printf("믹스커피가 나왔습니다.\n");
		printf("사용가능금액: %d\n\n", m);
		break;
	case 2:
		m -= 3000;
		printf("아메리카노가 나왔습니다.\n");
		printf("사용가능금액: %d\n\n", m);
		break;
	case 3:
		m -= 4000;
		printf("카페라떼가 나왔습니다.\n");
		printf("사용가능금액: %d\n\n", m);
		break;
	default: 
		break;
	}
	return m;
}

int more(void)																		//사용자의 선택에 따라 과정을 반복
{
	int cho;
	printf("추가(1),종료(2): ");
	scanf("%d", &cho);
	printf("\n\n");
	return cho;

}