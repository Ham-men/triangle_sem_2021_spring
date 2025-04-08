// ConsoleApplication1-triangle.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <conio.h>
#include <time.h>

int right_trg(int xa, int ya, int xb, int yb, int xc, int yc)
{
	int ab, ac, bc;
	ab = sqrt(pow(xb - xa, 2) + pow(yb - ya, 2));
	ac = sqrt(pow(xc - xa, 2) + pow(yc - ya, 2));
	bc = sqrt(pow(xc - xb, 2) + pow(yc - yb, 2));
	//printf("ab=%d ac=%d bc=%d",ab,ac,bc);
	ab *= ab;
	ac *= ac;
	bc *= bc;
	if ((ab == ac + bc) || (ac == ab + bc) || (bc == ac + ab)) //прямоугольный треугольник
		return 1;
	else if (ab == ac && ab == bc && ac == bc) //равносторонний
		return 2;
	else
		return 0;	//другой
}



int main(void) {
	FILE* F1, * F2, * F3, * F4;
	setlocale(LC_ALL, "Rus");
	int xa = 0, xb = 0, xc = 0; //точки
	int ya = 0, yb = 0, yc = 0; //точки
	int count1 = 0, count2 = 0; // кол-во треугольников
	int result;
	int i = 1;
	float a1 = 0.0, b1 = 0.0, c1 = 0.0, p = 0.0, p2 = 0.0, s = 0.0;
	int avtomatic = -1;//заполнить координато точек автоматически

	F1 = fopen("F1.txt", "w");

	while (count1 <= 0)
	{
		printf("\nвведите кол-во треугольников = ");
		scanf("%d", &count1);
	}
	while ((avtomatic < 0) || (avtomatic > 1))
	{
		printf("\nзаполнить координаты точек автоматически? (0-нет, 1-да): ");
		scanf("%d", &avtomatic);
	}
	srand(time(NULL));
	count2 = count1;
	while (i <= count1)
	{
		if (avtomatic == 0)
		{
			printf("\nтреугольник №%d", i);
			printf("\nвведите точки A(x,y):\n");
			scanf("%d %d", &xa, &ya);
			printf("введите точки B(x,y):\n");
			scanf("%d %d", &xb, &yb);
			printf("введите точки C(x,y):\n");
			scanf("%d %d", &xc, &yc);
		}
		if (avtomatic == 1)
		{
			xa = rand() % 10;
			ya = rand() % 10;
			xb = rand() % 10;
			yb = rand() % 10;
			xc = rand() % 10;
			yc = rand() % 10;
		}

		fprintf(F1, "%d %d\n%d %d\n%d %d\n", xa, ya, xb, yb, xc, yc);
		//	count1--;
		i++;
	}
	fclose(F1);
	F1 = fopen("F1.txt", "r");
	F2 = fopen("F2.txt", "w");	//равн
	F3 = fopen("F3.txt", "w");	//прям
	F4 = fopen("F4.txt", "w");	//произв
	while (count2 > 0)
	{
		fscanf(F1, "%d", &xa);
		fscanf(F1, "%d", &ya);
		fscanf(F1, "%d", &xb);
		fscanf(F1, "%d", &yb);
		fscanf(F1, "%d", &xc);
		fscanf(F1, "%d", &yc);
		result = right_trg(xa, ya, xb, yb, xc, yc);
		//периметр и площадь
		a1 = sqrt(pow((xb - xa), 2) + pow((yb - ya), 2));
		b1 = sqrt(pow((xc - xb), 2) + pow((yc - yb), 2));
		c1 = sqrt(pow((xc - xa), 2) + pow((yc - ya), 2));
		p = a1 + b1 + c1;
		p2 = p / 2;
		s = sqrt(p2 * (p2 - a1) * (p2 - b1) * (p2 - c1));
		//периметр и площадь
		if (result == 1)
		{
			fprintf(F3, "%d %d\n%d %d\n%d %d", xa, ya, xb, yb, xc, yc);
			fprintf(F3, "\nS = %.2f P = %.2f", s, p);
			fprintf(F3, "\n-прямоугольный треугольник\n\n");
		}
		if (result == 2)
		{
			fprintf(F2, "%d %d\n%d %d\n%d %d", xa, ya, xb, yb, xc, yc);
			fprintf(F2, "\nS = %.2f P = %.2f", s, p);
			fprintf(F2, "\n-равносторонний треугольник\n\n");
		}
		if (result == 0)
		{
			fprintf(F4, "%d %d\n%d %d\n%d %d", xa, ya, xb, yb, xc, yc);
			fprintf(F4, "\nS = %.2f P = %.2f", s, p);
			fprintf(F4, "\n-произвольный треугольник\n\n");
		}
		count2--;
	}
	//сделать расчет площади и периметра

}


