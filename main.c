#include <stdio.h>
#include <stdlib.h>

//Эта программа для вычисления сложения, вычитания, умножения и деления дробей!
//Автор ProstoAndreyRU v0.01

int main(int argc, char *argv[]) {
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
		printf("Итоговый результат %d %d\\%d\n",WholePart,Fractionint,FinalFractionDen);
	}
	return 0;
}