#include <stdio.h>
#include <stdlib.h>
#define SIZE 20

//Эта программа для различных математических вычислений в Offline режиме!
//Автор ProstoAndreyRU v0.02.
//Вторая функция не доделана.

int main(int argc, char *argv[]) {
	int menuchoise,menu=0;
	int a,b,c,nod,nok,nodsum,menunodnok,nods;
menu:
	printf("Привет! Ты находишься в меню, пожалуйста выбери что хочешь\n");
	printf("1.Выбор программ\n");
	printf("2.Об авторе\n");
	printf("3.Поддержка\n");
	scanf("%d",&menuchoise);
	if(menuchoise==3)
		goto donation;
	if(menuchoise==2) {
		printf("Привет, меня зовут Андрей! Я новичок в программировании");
		printf("и это одна из первых моих программ(по крайней мере работающих)\n");
		printf("Пожалуйста поддержи меня, выбрав пункт меню 3\n");
		scanf("%d",&menu);
		if(menu!=3)
			goto menu;
		if(menu==3) {
donation:
			;
			printf("Спасибо что решил поддержать меня!^_^\n");
			printf("Это можно сделать, отправив какую-то сумму на donationalerts\n");
			printf("Вот ссылка:https://www.donationalerts.com/r/prostoandreyru\n");
			printf("А сейчас возврат в меню!\n");
			printf("Если хочешь выйти набери 1\n");
			printf("Если нет то введи что-то другое\n");
			fflush(stdin);
			scanf("%d",&menu);
			if(menu==1) {
				printf("Пока");
				return 0;
			}
			if(menu!=1)
				goto menu;
		}
	}
	if(menuchoise==1) {
		printf("На данный момент доступна 2 программы\n");
		printf("Программа: Вычисление,сложение,вычитание, умножение и деление дробей\n");
		printf("Программы:Вычисление Нод и Нок суммы\n");
		printf("Что Хотите запустить? Если первую то выберите 1, если 2 то наберите 2\n");
		printf("В противном случаем наберите другую цифру\n");
		scanf("%d",&menu);
		if(menu==1) {
			goto workfactorial;
		}
		if(menu==2) {
			goto nodnok;
		}
elseif:
		goto menu;
	}
workfactorial:
	;
	int chislo1,drob1,drob2,chislo2,drob3,drob4;
	char action;
	int Confradrob1,Confradrob2,test=0,big=0,WholePart,FinalFractionNum=0,FinalFractionDen=0,Fractionint;
	float Fraction;
	printf("Введите дробь, если ничего нет, то 0 например 5 2 3 + 4 3 6\n");
	scanf("%d %d %d %c %d %d %d",&chislo1,&drob1,&drob2,&action,&chislo2,&drob3,&drob4);
	printf("Вы ввели %d %d %d %c %d %d %d\n",chislo1,drob1,drob2,action,chislo2,drob3,drob4);
	printf("Знак операции %d\n",action);
	int gcd(int a, int b) {
		int c;
		while (b) {
			c = a % b;
			a = b;
			b = c;
		}
		return abs(a);
	}
	printf("Перевод смешаных дробей в обыкновенные\n");
	Confradrob1=chislo1*drob2+drob1;
	printf("Первое\n");
	printf("(%d*%d+%d)/%d\n",chislo1,drob2,drob1,drob2);
	Confradrob2=chislo2*drob4+drob3;
	printf("Второе\n");
	printf("(%d*%d+%d)/%d\n",chislo2,drob4,drob3,drob4);
	printf("Первое равно %d/%d\n",Confradrob1,drob2);
	printf("Второе равно %d/%d\n",Confradrob2,drob4);
	if(action!='*'&& action!='/') {
		printf("Приведение к общему знаменателю\n");
		int temps=gcd(drob2,drob4);
		int temp=drob2*drob4/temps;
		printf("НОК равен %d\n",temp);
		printf("(%d*%d)\\(%d*%d)+(%d*%d)\\(%d*%d)\n",Confradrob1,temp/drob2,drob2,temp/drob2,Confradrob2,temp/drob4,drob4,temp/drob4);
		Confradrob1=Confradrob1*(temp/drob2);
		Confradrob2=Confradrob2*(temp/drob4);
		int tempdrob2=drob2*(temp/drob2);
		drob4=drob4*(temp/drob4);
		drob2=tempdrob2;
		printf("Равняется %d\\%d+%d\\%d\n",Confradrob1,drob2,Confradrob2,drob4);
	}
	if(action==43) {
		printf("Сложение\n");
		printf("%d+%d\\%d",Confradrob1,Confradrob2,drob2);
		printf("=%d\\%d\n",Confradrob1+Confradrob2,drob2);
		FinalFractionNum=Confradrob1+Confradrob2;
		FinalFractionDen=drob2;
	}
	if(action==45) {
		printf("Вычитание\n");
		printf("%d-%d\\%d",Confradrob1,Confradrob2,drob2);
		FinalFractionNum=Confradrob1-Confradrob2;
		FinalFractionDen=drob2;
		printf("Равно %d\\%d\n",FinalFractionNum,FinalFractionDen);
	}
	if(action=='*') {
		printf("Умножение\n");
		printf("Умножение числителя первой дроби на числитель второй дроби\n");
		printf("%d*%d",Confradrob1,Confradrob2);
		Confradrob1=Confradrob1*Confradrob2;
		printf("\\%d*%d\n",drob2,drob4);
		drob2=drob2*drob4;
		printf("Равно %d\%d\n",Confradrob1,drob2);
		int temps=gcd(Confradrob1,drob2);
		printf("НОД равен %d\n",temps);
		FinalFractionNum=Confradrob1/temps;
		FinalFractionDen=drob2/temps;
	}
	if(action=='/') {
		printf("Преобразование деления в умножение\n");
		printf("%d/%d*%d/%d=",Confradrob1,drob2,drob4,Confradrob2);
		Confradrob1=Confradrob1*drob4;
		drob2=drob2*Confradrob2;
		printf("Равно %d/%d\n",Confradrob1,Confradrob2);
		int temps=gcd(Confradrob1,drob2);
		if(temps>=1) {
			printf("НОД равен %d\n",temps);
			FinalFractionNum=Confradrob1/temps;
			FinalFractionDen=drob2/temps;
		}
	}
	if(FinalFractionNum>FinalFractionDen) {
		WholePart=FinalFractionNum/FinalFractionDen;
		Fraction=FinalFractionNum%FinalFractionDen;
		Fractionint=Fraction;
		printf("Выделение целой части\n");
		printf("%d/%d=%d\n",FinalFractionNum,FinalFractionDen,WholePart);
		printf("Целая часть равна %d\n",WholePart);
		printf("Остаток равен %d/%d=%g\n",FinalFractionNum,FinalFractionDen,Fraction);
		if(Fractionint==0)
			printf("Итоговый результат %d\n",WholePart);
		if(Fractionint!=0)
			printf("Итоговый результат %d %d\\%d\n",WholePart,Fractionint,FinalFractionDen);
	}
	return 0;
nodnok:
	;
	void removeDuplicates(int arr[], int size) {
		int temp[size];
		int j = 0;
		for (int i = 0; i < size - 1; i++) {
			if (arr[i] != arr[i+1]) {
				temp[j++] = arr[i];
			}
		}
		temp[j++] = arr[size - 1];
		for (int i = 0; i < j; i++) {
			arr[i] = temp[i];
		}
		for (int i = 0; i < j; i++) {
//			printf("%d ", arr[i]);
		}
	}
	void bubbleSortHigh(int* num, int size) {
		// Для всех элементов
		for (int i = 0; i < size - 1; i++) {
			for (int j = (size - 1); j > i; j--) { // для всех элементов после i-ого
				if (num[j - 1] < num[j]) { // если текущий элемент меньше предыдущего
					int temp = num[j - 1]; // меняем их местами
					num[j - 1] = num[j];
					num[j] = temp;
				}
			}
		}
	}
	void bubbleSortLow(int* num, int size) {
		// Для всех элементов
		for (int i = 0; i < size - 1; i++) {
			for (int j = (size - 1); j > i; j--) { // для всех элементов после i-ого
				if (num[j - 1] > num[j]) { // если текущий элемент меньше предыдущего
					int temp = num[j - 1]; // меняем их местами
					num[j - 1] = num[j];
					num[j] = temp;
				}
			}
		}
	}
	int bestsimple(int x,int y,int z) {
//		printf("Number factors: \n");
		int divisor=2;
		int divisor2=2;
		int divisor3=2;
		int arraya[SIZE]= {0};
		int arrayb[SIZE]= {0};
		int arrayc[SIZE]= {0};
		int i=0;
		int i2=0;
		int i3=0;
		int tempx=x;
		int tempy=y;
		int tempz=z;
		while(x!=1) {
			while(x%divisor==0) {
//				printf("%d ",divisor);
				arraya[i]=divisor;
				i++;
				x/=divisor;
			}
			divisor+=1;
		}
		while(y!=1) {
			while(y%divisor2==0) {
//				printf("%d ",divisor2);
				arrayb[i2]=divisor2;
				i2++;
				y/=divisor2;
			}
			divisor2+=1;
		}
		while(z!=1) {
			while(z%divisor3==0) {
//				printf("%d ",divisor3);
				arrayc[i3]=divisor3;
				i3++;
				z/=divisor3;
			}
			divisor3+=1;
		}
//		printf("\n");
		printf("Для числа %d разложение на простые множители дало\n",tempx);
		for(i=0; i<SIZE; ++i) {
			printf("%d ",arraya[i]);
			if(arraya[i]==0)
				break;
		}
		printf("\nДля числа %d разложение на простые множители дало\n",tempy);
		for(i=0; i<SIZE; ++i) {
			printf("%d ",arrayb[i]);
			if(arrayb[i]==0)
				break;
		}
		printf("\nДля числа %d разложение на простые множители дало\n",tempz);
		for(i=0; i<SIZE; ++i) {
			printf("%d ",arrayc[i]);
			if(arrayc[i]==0)
				break;
		}
		printf("\nСортируем! От большего к меньшему! Получается\n");
		bubbleSortHigh(arraya, SIZE);
		bubbleSortHigh(arrayb, SIZE);
		bubbleSortHigh(arrayc, SIZE);
		for(i=0; i<SIZE; ++i) {
			printf("%d ",arraya[i]);
			if(arraya[i]==0)
				break;
		}
		printf("\n");
		for(i=0; i<SIZE; ++i) {
			printf("%d ",arrayb[i]);
			if(arrayb[i]==0)
				break;
		}
		printf("\n");

		for(i=0; i<SIZE; ++i) {
			printf("%d ",arrayc[i]);
			if(arrayc[i]==0)
				break;
		}
		printf("\n");
		int size = sizeof(arraya) / sizeof(arraya[0]);
		printf("Удаляем дубликаты!\n");
		removeDuplicates(arraya, size);
		removeDuplicates(arrayb, size);
		removeDuplicates(arrayc, size);
		printf("Что получилось?\n");
		for(i=0; i<size; ++i) {
			printf("%d ",arraya[i]);
			if(arraya[i]==0)
				break;
		}
		printf("\n");

		for(i=0; i<size; ++i) {
			printf("%d ",arrayb[i]);
			if(arrayb[i]==0)
				break;
		}
		printf("\n");

		for(i=0; i<size; ++i) {
			printf("%d ",arrayc[i]);
			if(arrayc[i]==0)
				break;
		}
	}
		printf("Сколько чисел?\n");
		printf("Выберите 2, 3 или 4 числа\n");
		scanf("%d",&menunodnok);
		switch(menunodnok) {
			case 2 :
				printf("Введите два числа,вычислится НОД И НОК числа\n");
				scanf("%d%d",&a,&b);
				nod=gcd(a,b);
				nok=a*b/nod;
				printf("Нод равняется %d Нок равняется %d\n",nod,nok);
				break;
			case 3:
				printf("Введите три числа,вычислится НОД И НОК чисел\n");
				scanf("%d%d%d",&a,&b,&c);
				bestsimple(a,b,c);
				break;

			case 4:
				printf("В разработке\n");
				break;
			default:
				printf("Ошибка ввода,проверьте данные\n");
				return 0;
				break;
		}
	}
