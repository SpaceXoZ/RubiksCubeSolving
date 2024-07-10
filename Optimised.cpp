#include <time.h>
#include <stdlib.h>
#include "windows.h" 
#include <stdio.h>
#include "glut.h"
#include <cstring>
#define CUBE_SIZE 15
#define TIMER 15

int timeron = 0;
unsigned int c[9] = { 0xFFFFFF, 0xFFFF00, 0x0000FF, 0x00FF00, 0xFF0000, 0xFF4500 }; //верх(белый), низ(желтый), спереди(синий), сзади(зеленый), слева(красный), справа(оранжевый).

GLfloat lightPos[] = { 0, 100, 200, 0 };
int xRot = -60, yRot = 0, zRot = 0;
double translateZ = -30.0;
extern int timerOn = 0;
clock_t start_time;
clock_t end_time;
struct Small_Cube
{
	unsigned int color[6];
	double size;

	Small_Cube()
	{
		memset(color, 0, sizeof(color));
		size = 0.0;
	}

	// U, D'
	void rotateZoX()
	{
		unsigned int tmp = color[5];
		color[5] = color[3];
		color[3] = color[4];
		color[4] = color[2];
		color[2] = tmp;
	}

	// R, L'
	void rotateZoY()
	{
		unsigned int tmp = color[2];
		color[2] = color[1];
		color[1] = color[3];
		color[3] = color[0];
		color[0] = tmp;
	}

	// F, B'
	void rotateXoY()
	{
		unsigned int tmp = color[0];
		color[0] = color[4];
		color[4] = color[1];
		color[1] = color[5];
		color[5] = tmp;
	}
	// U', D
	void rotateZoX1()
	{
		unsigned int tmp = color[4];
		color[4] = color[3];
		color[3] = color[5];
		color[5] = color[2];
		color[2] = tmp;
	}

	// R', L
	void rotateZoY1()
	{
		unsigned int tmp = color[2];
		color[2] = color[0];
		color[0] = color[3];
		color[3] = color[1];
		color[1] = tmp;
	}

	// F', B
	void rotateXoY1()
	{
		unsigned int tmp = color[0];
		color[0] = color[5];
		color[5] = color[1];
		color[1] = color[4];
		color[4] = tmp;
	}

	void setColor(int i, int color)
	{
		this->color[i] = color;
	}

	unsigned char* at(int i)//преобразует цвет в 16 системе в формат 3 параметров для цвета (RGB)
	{

		_color[0] = color[i] >> 16;
		_color[1] = color[i] >> 8;
		_color[2] = color[i];
		return _color;
	}


	void draw()
	{
		glPushMatrix();
		glBegin(GL_QUADS);

		glColor3ubv(at(0)); //цвет в RGB
		glNormal3f(0, 0, 1);/*Компоненты нормали на плоскость должны быть нормированы и иметь длину равную 1, потому что нормаль используется для определения ориентации поверхности и расчета освещения.
		Если нормаль не будет нормализована, то ее длина будет влиять на интенсивность освещения, что может привести к искажениям визуальной информации.
		Кроме того, если нормаль имеет длину, отличную от 1, то при ее умножении на матрицу преобразования может произойти изменение длины, что повлияет на правильность расчета освещения.
		Поэтому нормаль должна быть нормализована.*/
		glVertex3f(size, size, size);//правый верхний дальний угол
		glVertex3f(0, size, size);//правый верхний ближний угол
		glVertex3f(0, 0, size);//правый нижний ближний угол
		glVertex3f(size, 0, size);//правый нижний дальний угол
		//фронтальная
		glColor3ubv(at(1));
		glNormal3f(0, 0, -1);
		glVertex3f(size, 0, 0);//левый нижний дальний угол
		glVertex3f(0, 0, 0);//левый нижний ближний угол
		glVertex3f(0, size, 0);//левый верхний ближний угол
		glVertex3f(size, size, 0);//левый верхний дальний угол
		//задняя
		glColor3ubv(at(2));
		glNormal3f(0, -1, 0);
		glVertex3f(size, 0, size);//правый нижний дальний угол
		glVertex3f(0, 0, size);//правый нижний ближний угол
		glVertex3f(0, 0, 0);//левый нижний ближний угол
		glVertex3f(size, 0, 0);//левый нижний дальний угол
		//нижняя грань
		glColor3ubv(at(3));
		glNormal3f(0, 1, 0);
		glVertex3f(size, size, 0);//левый верхний дальний угол
		glVertex3f(0, size, 0);//левый верхний ближний угол
		glVertex3f(0, size, size);//правый верхний ближний угол
		glVertex3f(size, size, size);//правый верхний дальний угол
		//верхняя
		glColor3ubv(at(4));
		glNormal3f(-1, 0, 0);
		glVertex3f(0, size, size);//правый верхний ближний угол
		glVertex3f(0, size, 0);//левый верхний ближний угол
		glVertex3f(0, 0, 0);//левый нижний ближний угол
		glVertex3f(0, 0, size);//правый нижний ближний угол
		//левая
		glColor3ubv(at(5));
		glNormal3f(1, 0, 0);
		glVertex3f(size, size, 0);//левый верхний дальний угол
		glVertex3f(size, size, size);//правый верхний дальний угол
		glVertex3f(size, 0, size);//правый нижний дальний угол
		glVertex3f(size, 0, 0);//левый нижний дальний угол
		//правая
		glEnd();
		glPopMatrix();
	}

	void draw(double x, double y, double z)
	{
		glPushMatrix();
		glTranslated(x, y, z);
		draw();
		glPopMatrix();
	}

private:
	unsigned char _color[4];
};
//Cube cube;
enum colour {
	white = 16777215, yellow = 16776960, blue = 255, green = 65280, red = 16711680, orange = 16729344
};
int num_of_comb = 0;
int start = 0;
int wrong = 0;
class Cube
{
	double size;
	unsigned int color[6];

public:

	int up; 
	int rg;
	int rb;
	int og;
	int ob;
	int lup;
	int ldown;
	int rup;
	int rdown;
	int combination;
	int current; //номер грани: 1 - верхняя(белая), 2 - передняя(синяя), 3 - задняя (зеленая), 4 - левая(красная), 5 - правая(оранжевая), 6 - нижняя(желтая).
	int rotate[6];
	Small_Cube a[3][3][3];
	Cube()
	{
	}

	Cube(double size, unsigned int* color)
	{
		clear(size, color);
	}

	void clear(double size, unsigned int* color)
	{
		memset(rotate, 0, sizeof(rotate));
		this->size = size;
		current = -1;

		int i, j, k;
		for (i = 0; i < 6; i++)
			this->color[i] = color[i];

		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
				a[i][j][2].setColor(0, color[0]);// белый цвет для верхней грани (3 координата - ось z - на нас)  

		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
				a[i][j][0].setColor(1, color[1]);

		for (k = 0; k < 3; k++)
			for (j = 0; j < 3; j++)
				a[j][0][k].setColor(2, color[2]);//синий цвет для передней грани (2 координата - ось игрик - вверх)

		for (k = 0; k < 3; k++)
			for (j = 0; j < 3; j++)
				a[j][2][k].setColor(3, color[3]);

		for (i = 0; i < 3; i++)
			for (k = 0; k < 3; k++)
				a[0][k][i].setColor(4, color[4]);//красный цвет для левой грани (1 координата - x - вправо)

		for (i = 0; i < 3; i++)
			for (k = 0; k < 3; k++)
				a[2][k][i].setColor(5, color[5]);


		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
				for (k = 0; k < 3; k++)
					a[i][j][k].size = (size / 3.0) * 0.97;
		//a[2][2][2].color[2] = 90; обращение к задней грани правого ближнего верхнего кубика  
	}

	void draw()
	{
		const double K = 0.55;
		glPushMatrix();
		glColor3f(0, 0, 0);
		glTranslatef(((1.0 - K) / 2) * size + K * size / 2, ((1.0 - K) / 2) * size + K * size / 2, ((1.0 - K) / 2) * size + K * size / 2);//7.5, 7.5, 7.5
		glutSolidCube(size * K);//функция строит куб с центром в начале координат
		glPopMatrix();

		memset(ok, true, sizeof(ok));
		if (current != -1)
		{
			glPushMatrix();
			int i, j, k;

			if (current == 0 || current == 1) //
			{
				k = (current & 1) * 2;
				for (i = 0; i < 3; i++)
					for (j = 0; j < 3; j++)
						ok[i][j][k] = false;


				glTranslated(size / 2, size / 2, 0); //сдвигаемся к центру 
				glRotatef(rotate[current], 0, 0, 1);   //крутим грань с номером на угол
				glTranslated(-size / 2, -size / 2, 0); //сдвигаемся обратно
				for (i = 0; i < 3; i++)
					for (j = 0; j < 3; j++)
						a[i][j][k].draw(size / 3 * i, size / 3 * j, size / 3 * k); //отрисовка маленького кубика после поворота 
			}
			else if (current == 2 || current == 3)
			{
				j = (current & 1) * 2;
				for (i = 0; i < 3; i++)
					for (k = 0; k < 3; k++)
						ok[i][j][k] = false;

				glTranslated(size / 2, 0, size / 2);
				glRotatef(rotate[current], 0, 1, 0);
				glTranslated(-size / 2, 0, -size / 2);
				for (i = 0; i < 3; i++)
					for (k = 0; k < 3; k++)
						a[i][j][k].draw(size / 3 * i, size / 3 * j, size / 3 * k);
			}
			else if (current == 4 || current == 5)
			{
				i = (current & 1) * 2;
				for (j = 0; j < 3; j++)
					for (k = 0; k < 3; k++)
						ok[i][j][k] = false;

				glTranslated(0, size / 2, size / 2);
				glRotatef(rotate[current], 1, 0, 0);
				glTranslated(0, -size / 2, -size / 2);
				for (j = 0; j < 3; j++)
					for (k = 0; k < 3; k++)
						a[i][j][k].draw(size / 3 * i, size / 3 * j, size / 3 * k);
			}
			glPopMatrix();
		}

		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				for (int k = 0; k < 3; k++)
					if (ok[i][j][k])
						a[i][j][k].draw(size / 3 * i, size / 3 * j, size / 3 * k);
	}

public:
	void rot90(int idx, int sign)
	{
		int i, j, k;
		if (sign == -1)
			sign = 3;
		while (sign--)
		{
			if (idx == 0 || idx == 1)
			{
				k = (idx & 1) * 2;
				for (i = 0; i < 3; i++)
					for (j = 0; j < 3; j++)
						tmp[j][2 - i] = a[i][j][k];
				for (i = 0; i < 3; i++)
					for (j = 0; j < 3; j++)
						tmp[i][j].rotateZoX(), a[i][j][k] = tmp[i][j];
			}
			else if (idx == 2 || idx == 3)
			{
				j = (idx & 1) * 2;
				for (i = 0; i < 3; i++)
					for (k = 0; k < 3; k++)
						tmp[k][2 - i] = a[i][j][k];
				for (i = 0; i < 3; i++)
					for (k = 0; k < 3; k++)
						tmp[i][k].rotateXoY(), a[i][j][k] = tmp[i][k];
			}
			else if (idx == 4 || idx == 5)
			{
				i = (idx & 1) * 2;
				for (j = 0; j < 3; j++)
					for (k = 0; k < 3; k++)
						tmp[k][2 - j] = a[i][j][k];
				for (j = 0; j < 3; j++)
					for (k = 0; k < 3; k++)
						tmp[j][k].rotateZoY(), a[i][j][k] = tmp[j][k];
			}
		}
	}

	void Rotate(int idx, int angle)
	{
		if (current == -1 || current == idx)
		{
			rotate[idx] += angle;

			if (rotate[idx] % 90 != 0)
			{
				current = idx;
			}
			else
			{
				if ((rotate[idx] < 0) ^ (current == 2 || current == 3))
					rot90(idx, 1);
				else
					rot90(idx, -1);
				rotate[idx] = 0;
				current = -1;
				num_of_comb++;
			}
		}
	}
	int pif_paf(int idx) {
		
		if (idx == 3 || idx == 5) {
			if (num_of_comb == 0) {
				Rotate(idx, -3);
				return 0;
			}
			else if (num_of_comb == 1) {
				Rotate(0, 3);
				return 0;
			}
			else if (num_of_comb == 2) {
				Rotate(idx, 3);
				return 0;
			}
			else if (num_of_comb == 3) {
				Rotate(0, -3);
				return 0;
			}
			else if (num_of_comb == 4) {
				num_of_comb = 0;
				return 1;
			}
		}
		else {
			if (num_of_comb == 0) {
				Rotate(idx, 3);
				return 0;
			}
			else if (num_of_comb == 1) {
				Rotate(0, 3);
				return 0;
			}
			else if (num_of_comb == 2) {
				Rotate(idx, -3);
				return 0;
			}
			else if (num_of_comb == 3) {
				Rotate(0, -3);
				return 0;
			}
			else if (num_of_comb == 4) {
				num_of_comb = 0;
				return 1;
			}
		}
	}
	void Auto() {
		//1) если на верхней грани 4  белых грани
		if (a[0][1][2].color[0] == white && a[0][1][2].color[4] == red && a[1][2][2].color[0] == white && a[1][2][2].color[3] == green && a[2][1][2].color[0] == white && a[2][1][2].color[5] == orange && a[1][0][2].color[0] == white && a[1][0][2].color[2] == blue) {
			timeron = 1;
			num_of_comb = 0;
		}
		if (timeron == 0) {
			if (a[0][1][2].color[0] == white && a[1][0][2].color[0] == white && a[2][1][2].color[0] == white && a[1][2][2].color[0] == white) {
				if (a[0][1][2].color[4] == blue && a[1][0][2].color[2] == green && a[2][1][2].color[5] == orange && a[1][2][2].color[3] == red) {//если стоит правильно только оранжевое ребро снизу зеленое а сверху красное
					Rotate(1, 3); //поворот синей грани с зеленым цветом для лаьнейшей постановки на место
				}
				if (a[0][1][2].color[4] == blue && a[1][0][2].color[2] == red && a[2][1][2].color[5] == orange && a[1][2][2].color[3] == green) {
					Rotate(2, 3);
				}
				if (a[0][1][2].color[4] == blue && a[1][0][2].color[2] == orange && a[2][1][2].color[5] == red && a[1][2][2].color[3] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[4] == green && a[1][0][2].color[2] == blue && a[2][1][2].color[5] == orange && a[1][2][2].color[3] == red) {
					Rotate(3, -3);
				}
				if (a[0][1][2].color[4] == red && a[1][0][2].color[2] == blue && a[2][1][2].color[5] == green && a[1][2][2].color[3] == orange) {
					Rotate(3, 3);
				}
				if (a[0][1][2].color[4] == red && a[1][0][2].color[2] == green && a[2][1][2].color[5] == orange && a[1][2][2].color[3] == blue) {
					Rotate(2, 3);
				}
				if (a[0][1][2].color[4] == green && a[1][0][2].color[2] == red && a[2][1][2].color[5] == blue && a[1][2][2].color[3] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[4] == green && a[1][0][2].color[2] == orange && a[2][1][2].color[5] == blue && a[1][2][2].color[3] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[4] == orange && a[1][0][2].color[2] == red && a[2][1][2].color[5] == blue && a[1][2][2].color[3] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[4] == green && a[1][0][2].color[2] == orange && a[2][1][2].color[5] == red && a[1][2][2].color[3] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[4] == orange && a[1][0][2].color[2] == green && a[2][1][2].color[5] == blue && a[1][2][2].color[3] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[4] == red && a[1][0][2].color[2] == orange && a[2][1][2].color[5] == green && a[1][2][2].color[3] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[4] == blue && a[1][0][2].color[2] == orange && a[2][1][2].color[5] == green && a[1][2][2].color[3] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[4] == red && a[1][0][2].color[2] == orange && a[2][1][2].color[5] == blue && a[1][2][2].color[3] == green) {
					Rotate(2, -3);
				}
				if (a[0][1][2].color[4] == green && a[1][0][2].color[2] == red && a[2][1][2].color[5] == orange && a[1][2][2].color[3] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[4] == blue && a[1][0][2].color[2] == green && a[2][1][2].color[5] == red && a[1][2][2].color[3] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[4] == orange && a[1][0][2].color[2] == blue && a[2][1][2].color[5] == green && a[1][2][2].color[3] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[4] == blue && a[1][0][2].color[2] == red && a[2][1][2].color[5] == green && a[1][2][2].color[3] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[4] == green && a[1][0][2].color[2] == blue && a[2][1][2].color[5] == red && a[1][2][2].color[3] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[4] == red && a[1][0][2].color[2] == green && a[2][1][2].color[5] == blue && a[1][2][2].color[3] == orange) {
					Rotate(3, 3);
				}
				if (a[0][1][2].color[4] == orange && a[1][0][2].color[2] == blue && a[2][1][2].color[5] == red && a[1][2][2].color[3] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[4] == orange && a[1][0][2].color[2] == green && a[2][1][2].color[5] == red && a[1][2][2].color[3] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[4] == orange && a[1][0][2].color[2] == red && a[2][1][2].color[5] == green && a[1][2][2].color[3] == blue) {
					Rotate(1, 3);
				}
			}


			//если 3 грани белых (кроме нижней)
			if (a[0][1][2].color[0] == white && a[1][0][2].color[0] != white && a[2][1][2].color[0] == white && a[1][2][2].color[0] == white) {
				if (a[0][1][2].color[4] == red && a[1][2][2].color[3] == blue && a[2][1][2].color[5] == orange) {
					if (a[2][0][1].color[5] == white && a[2][0][1].color[2] == green) {//если синяя грань повенула зеленый цвет
						Rotate(1, 3); //поворот зеленой грани, чтобы не потерять красный цвет 
					}
					if (a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) {
						Rotate(1, 3);
					}
				}
				if (a[0][1][2].color[4] == blue && a[1][2][2].color[3] == green && a[2][1][2].color[5] == orange) {
					if (a[2][0][1].color[5] == white && a[2][0][1].color[2] == red) {
						Rotate(1, 3);
					}
					if (a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) {
						Rotate(1, -3);
					}
				}
				if (a[0][1][2].color[4] == red && a[1][2][2].color[3] == green && a[2][1][2].color[5] == orange) {
					if (a[0][0][1].color[2] == blue && a[0][0][1].color[4] == white) {
						Rotate(2, 3);
					}
					if (a[2][0][1].color[2] == white && a[2][0][1].color[5] == blue) {
						Rotate(1, 3);
					}
					/*if (a[2][0][1].color[2] == blue && a[2][0][1].color[5] == white) {
						Rotate(2, -3);
					}*/
					//когда синий кубик перевернут синим вверх
					if (a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) {
						Rotate(2, 3);
					}
				}
				if (a[0][1][2].color[4] == orange && a[1][2][2].color[3] == green && a[2][1][2].color[5] == red) {
					if (a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) {
						Rotate(2, 3);
					}
					if (a[2][0][1].color[2] == white && a[2][0][1].color[5] == blue) {
						Rotate(1, 3);
					}
				}
				if (a[0][1][2].color[4] == green && a[1][2][2].color[3] == red && a[2][1][2].color[5] == orange) {
					if (a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) {
						Rotate(2, 3);
					}
					if (a[2][0][1].color[2] == white && a[2][0][1].color[5] == blue) {
						Rotate(1, 3);
					}
				}
				if (a[0][1][2].color[4] == red && a[1][2][2].color[3] == orange && a[2][1][2].color[5] == green) {
					if (a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) {
						Rotate(2, 3);
					}
					if (a[2][0][1].color[2] == white && a[2][0][1].color[5] == blue) {
						Rotate(1, 3);
					}
				}
				if (a[0][1][2].color[4] == orange && a[1][2][2].color[3] == red && a[2][1][2].color[5] == green) {
					if (a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) {
						Rotate(2, 3);
					}
					if (a[2][0][1].color[2] == white && a[2][0][1].color[5] == blue) {
						Rotate(1, 3);
					}
				}
				if (a[0][1][2].color[4] == green && a[1][2][2].color[3] == orange && a[2][1][2].color[5] == red) {
					if (a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) {
						Rotate(2, 3);
					}
					if (a[2][0][1].color[2] == white && a[2][0][1].color[5] == blue) {
						Rotate(1, 3);
					}
				}
				if (a[0][1][2].color[4] == blue && a[1][2][2].color[3] == red && a[2][1][2].color[5] == green) {
					if (a[2][0][1].color[2] == orange && a[2][0][1].color[5] == white) {
						Rotate(2, -3);
					}
					if (a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) {
						Rotate(1, 3);
					}
				}
				if (a[0][1][2].color[4] == green && a[1][2][2].color[3] == red && a[2][1][2].color[5] == blue) {
					if (a[2][0][1].color[2] == white && a[2][0][1].color[5] == orange) {
						Rotate(1, 3);
					}
					if (a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) {
						Rotate(1, 3);
					}
					if (a[2][0][1].color[2] == orange && a[2][0][1].color[5] == white) {
						Rotate(2, -3);
					}
				}
				if (a[0][1][2].color[4] == blue && a[1][2][2].color[3] == green && a[2][1][2].color[5] == red) {
					if (a[2][0][1].color[2] == orange && a[2][0][1].color[5] == white) {
						Rotate(2, -3);
					}
					if (a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) {
						Rotate(1, 3);
					}
				}
				if (a[0][1][2].color[4] == red && a[1][2][2].color[3] == blue && a[2][1][2].color[5] == green) {
					if (a[2][0][1].color[2] == orange && a[2][0][1].color[5] == white) {
						Rotate(2, -3);
					}
					if (a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) {
						Rotate(1, 3);
					}
				}
				if (a[0][1][2].color[4] == red && a[1][2][2].color[3] == green && a[2][1][2].color[5] == blue) {
					if (a[2][0][1].color[2] == orange && a[2][0][1].color[5] == white) {
						Rotate(2, -3);
					}
					if (a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) {
						Rotate(1, 3);
					}
					if (a[0][0][1].color[2] == orange && a[0][0][1].color[4] == white) {
						Rotate(1, -3);
					}
				}
				if (a[0][1][2].color[4] == green && a[1][2][2].color[3] == blue && a[2][1][2].color[5] == red) {
					if (a[2][0][1].color[2] == orange && a[2][0][1].color[5] == white) {
						Rotate(2, -3);
					}
					if (a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) {
						Rotate(1, 3);
					}
				}
				if (a[0][1][2].color[4] == orange && a[1][2][2].color[3] == blue && a[2][1][2].color[5] == red) {
					if (a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) {
						Rotate(1, 3);
					}
				}
				if (a[0][1][2].color[4] == blue && a[1][2][2].color[3] == orange && a[2][1][2].color[5] == red) {
					if (a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) {
						Rotate(1, -3);
					}
				}
				if (a[0][1][2].color[4] == orange && a[1][2][2].color[3] == red && a[2][1][2].color[5] == blue) {
					if (a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) {
						Rotate(1, 3);
					}
				}
				if (a[0][1][2].color[4] == red && a[1][2][2].color[3] == orange && a[2][1][2].color[5] == blue) {
					if (a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) {
						Rotate(1, 3);
					}
				}
				if (a[0][1][2].color[4] == blue && a[1][2][2].color[3] == red && a[2][1][2].color[5] == orange) {
					if (a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) {
						Rotate(1, -3);
					}
				}
				//Red
				if (a[0][1][2].color[4] == green && a[1][2][2].color[3] == orange && a[2][1][2].color[5] == blue) {
					if (a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) {
						Rotate(1, -3);
					}
				}
				if (a[0][1][2].color[4] == orange && a[1][2][2].color[3] == green && a[2][1][2].color[5] == blue) {
					if (a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) {
						Rotate(1, -3);
					}
				}
				if (a[0][1][2].color[4] == green && a[1][2][2].color[3] == blue && a[2][1][2].color[5] == orange) {
					if (a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) {
						Rotate(1, -3);
					}
				}
				if (a[0][1][2].color[4] == blue && a[1][2][2].color[3] == orange && a[2][1][2].color[5] == green) {
					if (a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) {
						Rotate(1, -3);
					}
				}
				if (a[0][1][2].color[4] == orange && a[1][2][2].color[3] == blue && a[2][1][2].color[5] == green) {
					if (a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) {
						Rotate(1, -3);
					}
				}
			}
			//три белых (кроме правой)
			if (a[0][1][2].color[0] == white && a[1][0][2].color[0] == white && a[2][1][2].color[0] != white && a[1][2][2].color[0] == white) {
				if (a[0][1][2].color[4] == blue && a[1][0][2].color[2] == red && a[1][2][2].color[3] == orange) {
					if (a[2][0][1].color[5] == white && a[2][0][1].color[2] == green) {
						Rotate(1, 3);
					}
					if (a[2][2][1].color[5] == green && a[2][2][1].color[3] == white) {
						Rotate(3, 3);
					}
					if (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white) {
						Rotate(1, 3);
					}
				}
				if (a[0][1][2].color[4] == green && a[1][0][2].color[2] == blue && a[1][2][2].color[3] == orange) {
					if (a[2][0][1].color[5] == white && a[2][0][1].color[2] == red) {
						Rotate(2, -3);
					}
					if (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white) {
						Rotate(5, 3);
					}
					if (a[2][0][1].color[2] == white && a[2][0][1].color[5] == orange) {
						Rotate(1, -3);
					}
					if (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white) {
						Rotate(1, 3);
					}
				}
				if (a[0][1][2].color[4] == green && a[1][0][2].color[2] == red && a[1][2][2].color[3] == orange) {
					if (a[0][0][1].color[4] == white && a[0][0][1].color[2] == blue) {
						Rotate(1, -3);
					}
					if (a[2][0][1].color[2] == white && a[2][0][1].color[5] == blue) {
						Rotate(5, -3);
					}
					if (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white) {
						Rotate(1, -3);
					}
					if (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white) {
						Rotate(5, 3);
					}
					if (a[2][0][1].color[2] == orange && a[2][0][1].color[5] == white) {
						Rotate(1, -3);
					}
				}
				if (a[0][1][2].color[4] == blue && a[1][0][2].color[2] == orange && a[1][2][2].color[3] == green) {
					if (a[0][2][1].color[4] == white && a[0][2][1].color[3] == red) {
						Rotate(3, 3);
					}
					if (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white) {
						Rotate(1, 3);
					}
				}
				if (a[0][1][2].color[4] == blue && a[1][0][2].color[2] == orange && a[1][2][2].color[3] == red) {
					if (a[2][2][1].color[5] == white && a[2][2][1].color[3] == green) {
						Rotate(1, 3);
					}
					if (a[2][2][1].color[5] == green && a[2][2][1].color[3] == white) {
						Rotate(5, 3);
					}
					if (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white) {
						Rotate(1, 3);
					}
				}
				if (a[0][1][2].color[4] == green && a[1][0][2].color[2] == orange && a[1][2][2].color[3] == red) {
					if (a[2][0][1].color[2] == white && a[2][0][1].color[5] == blue) {
						Rotate(5, -3);
					}
					if (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white) {
						Rotate(1, -3);
					}
				}

				if (a[0][1][2].color[4] == red && a[1][0][2].color[2] == green && a[1][2][2].color[3] == orange) {
					if (a[2][0][1].color[2] == white && a[2][0][1].color[5] == blue) {
						Rotate(5, -3);
					}
					if (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white) {
						Rotate(1, -3);
					}
				}
				if (a[0][1][2].color[4] == orange && a[1][0][2].color[2] == red && a[1][2][2].color[3] == green) {
					if (a[2][0][1].color[2] == white && a[2][0][1].color[5] == blue) {
						Rotate(5, -3);
					}
					if (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white) {
						Rotate(1, -3);
					}
				}
				if (a[0][1][2].color[4] == orange && a[1][0][2].color[2] == green && a[1][2][2].color[3] == red) {
					if (a[2][0][1].color[2] == white && a[2][0][1].color[5] == blue) {
						Rotate(5, -3);
					}
					if (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white) {
						Rotate(1, -3);
					}
				}
				if (a[0][1][2].color[4] == red && a[1][0][2].color[2] == orange && a[1][2][2].color[3] == green) {
					if (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white) {
						Rotate(1, -3);
					}
					if (a[2][0][1].color[2] == white && a[2][0][1].color[5] == blue) {
						Rotate(5, -3);
					}
				}
				if (a[0][1][2].color[4] == red && a[1][0][2].color[2] == blue && a[1][2][2].color[3] == green) {
					if (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white) {
						Rotate(5, 3);
					}
					/*if (a[2][0][1].color[2] == white && a[2][0][1].color[5] == orange) {
						Rotate(1, -3);
					}*/
					if (a[2][0][1].color[2] == orange && a[2][0][1].color[5] == white) {
						Rotate(1, -3);
					}
				}
				if (a[0][1][2].color[4] == red && a[1][0][2].color[2] == green && a[1][2][2].color[3] == blue) {
					if (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white) {
						Rotate(5, 3);
					}
					if (a[2][0][1].color[2] == white && a[2][0][1].color[5] == orange) {
						Rotate(1, -3);
					}
					if (a[2][0][1].color[2] == orange && a[2][0][1].color[5] == white) {
						Rotate(1, -3);
					}
				}
				if (a[0][1][2].color[4] == blue && a[1][0][2].color[2] == red && a[1][2][2].color[3] == green) {
					if (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white) {
						Rotate(5, 3);
					}
					if (a[2][0][1].color[2] == white && a[2][0][1].color[5] == orange) {
						Rotate(1, -3);
					}
					if (a[2][0][1].color[2] == orange && a[2][0][1].color[5] == white) {
						Rotate(1, -3);
					}
				}
				if (a[0][1][2].color[4] == green && a[1][0][2].color[2] == red && a[1][2][2].color[3] == blue) {
					if (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white) {
						Rotate(5, 3);
					}
					if (a[2][0][1].color[2] == white && a[2][0][1].color[5] == orange) {
						Rotate(1, -3);
					}
					if (a[2][0][1].color[2] == orange && a[2][0][1].color[5] == white) {
						Rotate(1, -3);
					}
				}
				if (a[0][1][2].color[4] == blue && a[1][0][2].color[2] == green && a[1][2][2].color[3] == red) {
					if (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white) {
						Rotate(5, 3);
					}
					if (a[2][0][1].color[2] == white && a[2][0][1].color[5] == orange) {
						Rotate(1, -3);
					}
					if (a[2][0][1].color[2] == orange && a[2][0][1].color[5] == white) {
						Rotate(1, -3);
					}
				}
				if (a[0][1][2].color[4] == green && a[1][0][2].color[2] == blue && a[1][2][2].color[3] == red) {
					if (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white) {
						Rotate(5, 3);
					}
					if (a[2][0][1].color[2] == orange && a[2][0][1].color[5] == white) {
						Rotate(1, -3);
					}
					if (a[2][0][1].color[2] == white && a[2][0][1].color[5] == orange) {
						Rotate(5, -3);
					}
				}
				if (a[0][1][2].color[4] == orange && a[1][0][2].color[2] == blue && a[1][2][2].color[3] == red) {
					if (a[2][2][1].color[5] == green && a[2][2][1].color[3] == white) {
						Rotate(5, 3);
					}
					if (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white) {
						Rotate(1, 3);
					}
				}
				if (a[0][1][2].color[4] == red && a[1][0][2].color[2] == orange && a[1][2][2].color[3] == blue) {
					if (a[2][2][1].color[5] == green && a[2][2][1].color[3] == white) {
						Rotate(5, 3);
					}
					if (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white) {
						Rotate(1, 3);
					}
				}
				if (a[0][1][2].color[4] == orange && a[1][0][2].color[2] == red && a[1][2][2].color[3] == blue) {
					if (a[2][2][1].color[5] == green && a[2][2][1].color[3] == white) {
						Rotate(5, 3);
					}
					if (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white) {
						Rotate(1, 3);
					}
				}
				if (a[0][1][2].color[4] == red && a[1][0][2].color[2] == blue && a[1][2][2].color[3] == orange) {
					if (a[2][2][1].color[5] == green && a[2][2][1].color[3] == white) {
						Rotate(5, 3);
					}
					if (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white) {
						Rotate(1, 3);
					}
				}
				//Red
				if (a[0][1][2].color[4] == orange && a[1][0][2].color[2] == green && a[1][2][2].color[3] == blue) {
					if (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white) {
						Rotate(1, 3);
					}
				}
				if (a[0][1][2].color[4] == green && a[1][0][2].color[2] == orange && a[1][2][2].color[3] == blue) {
					if (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white) {
						Rotate(1, 3);
					}
				}
				if (a[0][1][2].color[4] == blue && a[1][0][2].color[2] == green && a[1][2][2].color[3] == orange) {
					if (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white) {
						Rotate(1, 3);
					}
				}
				if (a[0][1][2].color[4] == orange && a[1][0][2].color[2] == blue && a[1][2][2].color[3] == green) {
					if (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white) {
						Rotate(1, 3);
					}
				}
			}
			//три белых (кроме верхней)
			if (a[0][1][2].color[0] == white && a[1][0][2].color[0] == white && a[2][1][2].color[0] == white && a[1][2][2].color[0] != white) {
				if (a[0][1][2].color[4] == orange && a[1][0][2].color[2] == blue && a[2][1][2].color[5] == red) {
					if (a[2][0][1].color[5] == white && a[2][0][1].color[2] == green) {
						Rotate(2, -3);
					}
					if (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white) {
						Rotate(3, 3);
					}
					if (a[2][2][1].color[5] == green && a[2][2][1].color[3] == white) {
						Rotate(1, -3);
					}
				}
				if (a[0][1][2].color[4] == orange && a[1][0][2].color[2] == green && a[2][1][2].color[5] == red) {
					if (a[0][0][1].color[2] == blue && a[0][0][1].color[4] == white) {
						Rotate(1, 3);
					}
					if (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white) {
						Rotate(1, -3);
					}
				}
				if (a[0][1][2].color[4] == green && a[1][0][2].color[2] == blue && a[2][1][2].color[5] == orange) {
					if (a[0][2][1].color[4] == white && a[0][2][1].color[3] == red) {
						Rotate(1, -3);
					}
					if (a[0][2][1].color[3] == red && a[0][2][1].color[4] == white) {
						Rotate(3, 3);
					}
				}
				if (a[0][1][2].color[4] == red && a[1][0][2].color[2] == blue && a[2][1][2].color[5] == orange) {
					if (a[2][2][1].color[5] == white && a[2][2][1].color[3] == green) {
						Rotate(3, -3);
					}
					//if (a[0][2][1].color[4] == white && a[0][2][1].color[3] == green && (a[0][2][0].color[1] != white || a[0][2][0].color[4] != white || a[0][2][0].color[3] != white) && (a[0][2][0].color[1] != white || a[0][2][0].color[1] != white || a[0][2][0].color[1] != white)) {
						//Rotate(3, 3);
					//}
					if (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white) {
						Rotate(3, 3);
					}
					if (a[2][2][1].color[5] == green && a[2][2][1].color[3] == white) {
						Rotate(1, -3);
					}
				}
				if (a[0][1][2].color[4] == red && a[1][0][2].color[2] == blue && a[2][1][2].color[5] == green) {
					if (a[2][2][1].color[5] == white && a[2][2][1].color[3] == orange) {
						Rotate(1, 3);
					}
					if (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white) {
						Rotate(1, 3);
					}
				}
				if (a[0][1][2].color[4] == red && a[1][0][2].color[2] == green && a[2][1][2].color[5] == orange) {
					if (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white) {
						Rotate(1, -3);
					}
					if (a[0][2][1].color[3] == blue && a[0][2][1].color[4] == white) {
						Rotate(3, 3);
					}
				}
				if (a[0][1][2].color[4] == green && a[1][0][2].color[2] == orange && a[2][1][2].color[5] == red) {
					if (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white) {
						Rotate(1, -3);
					}
				}
				if (a[0][1][2].color[4] == orange && a[1][0][2].color[2] == red && a[2][1][2].color[5] == green) {
					if (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white) {
						Rotate(1, -3);
					}
				}
				if (a[0][1][2].color[4] == green && a[1][0][2].color[2] == red && a[2][1][2].color[5] == orange) {
					if (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white) {
						Rotate(1, -3);
					}
				}
				if (a[0][1][2].color[4] == red && a[1][0][2].color[2] == orange && a[2][1][2].color[5] == green) {
					if (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white) {
						Rotate(1, -3);
					}
				}
				if (a[0][1][2].color[4] == green && a[1][0][2].color[2] == red && a[2][1][2].color[5] == blue) {
					if (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white) {
						Rotate(1, -3);
					}
				}
				if (a[0][1][2].color[4] == blue && a[1][0][2].color[2] == red && a[2][1][2].color[5] == green) {
					if (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white) {
						Rotate(1, -3);
					}
				}
				if (a[0][1][2].color[4] == red && a[1][0][2].color[2] == green && a[2][1][2].color[5] == blue) {
					if (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white) {
						Rotate(1, -3);
					}
					if (a[2][2][1].color[3] == orange && a[2][2][1].color[5] == white) {
						Rotate(1, 3);
					}

				}
				if (a[0][1][2].color[4] == green && a[1][0][2].color[2] == blue && a[2][1][2].color[5] == red) {
					if (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white) {
						Rotate(1, -3);
					}
				}
				if (a[0][1][2].color[4] == blue && a[1][0][2].color[2] == green && a[2][1][2].color[5] == red) {
					if (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white) {
						Rotate(1, -3);
					}
				}
				if (a[0][1][2].color[4] == red && a[1][0][2].color[2] == orange && a[2][1][2].color[5] == blue) {
					if (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white) {
						Rotate(3, 3);
					}
					if (a[2][2][1].color[5] == green && a[2][2][1].color[3] == white) {
						Rotate(1, -3);
					}
				}
				if (a[0][1][2].color[4] == blue && a[1][0][2].color[2] == red && a[2][1][2].color[5] == orange) {
					if (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white) {
						Rotate(3, 3);
					}
					if (a[2][2][1].color[5] == green && a[2][2][1].color[3] == white) {
						Rotate(1, -3);
					}
				}
				if (a[0][1][2].color[4] == blue && a[1][0][2].color[2] == orange && a[2][1][2].color[5] == red) {
					if (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white) {
						Rotate(3, 3);
					}
					if (a[2][2][1].color[5] == green && a[2][2][1].color[3] == white) {
						Rotate(1, -3);
					}
				}
				if (a[0][1][2].color[4] == orange && a[1][0][2].color[2] == red && a[2][1][2].color[5] == blue) {
					if (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white) {
						Rotate(3, 3);
					}
					if (a[2][2][1].color[5] == green && a[2][2][1].color[3] == white) {
						Rotate(1, -3);
					}
				}
				//Red
				if (a[0][1][2].color[4] == blue && a[1][0][2].color[2] == orange && a[2][1][2].color[5] == green) {
					if (a[0][2][1].color[3] == red && a[0][2][1].color[4] == white) {
						Rotate(3, 3);
					}
					if (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white) {
						Rotate(1, 3);
					}
				}
				if (a[0][1][2].color[4] == blue && a[1][0][2].color[2] == green && a[2][1][2].color[5] == orange) {
					if (a[0][2][1].color[3] == red && a[0][2][1].color[4] == white) {
						Rotate(3, 3);
					}
					if (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white) {
						Rotate(1, 3);
					}
				}
				if (a[0][1][2].color[4] == orange && a[1][0][2].color[2] == blue && a[2][1][2].color[5] == green) {
					if (a[0][2][1].color[3] == red && a[0][2][1].color[4] == white) {
						Rotate(3, 3);
					}
					if (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white) {
						Rotate(1, 3);
					}
				}
				if (a[0][1][2].color[4] == green && a[1][0][2].color[2] == orange && a[2][1][2].color[5] == blue) {
					if (a[0][2][1].color[3] == red && a[0][2][1].color[4] == white) {
						Rotate(3, 3);
					}
					if (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white) {
						Rotate(1, 3);
					}
				}
				if (a[0][1][2].color[4] == orange && a[1][0][2].color[2] == green && a[2][1][2].color[5] == blue) {
					if (a[0][2][1].color[3] == red && a[0][2][1].color[4] == white) {
						Rotate(3, 3);
					}
					if (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white) {
						Rotate(1, 3);
					}
				}
			}
			//три белых (кроме левой)
			if (a[0][1][2].color[0] != white && a[1][0][2].color[0] == white && a[2][1][2].color[0] == white && a[1][2][2].color[0] == white) {
				if (a[1][0][2].color[2] == orange && a[2][1][2].color[5] == green && a[1][2][2].color[3] == red) {
					if (a[0][0][1].color[2] == blue && a[0][0][1].color[4] == white) {
						Rotate(1, 3);
					}
					if (a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) {
						Rotate(1, 3);
					}
					if (a[2][0][1].color[2] == blue && a[2][0][1].color[5] == white) {
						Rotate(1, 3);
					}
				}
				if (a[1][0][2].color[2] == red && a[2][1][2].color[5] == blue && a[1][2][2].color[3] == green) {
					if (a[2][2][1].color[5] == white && a[2][2][1].color[3] == orange) {
						Rotate(3, -3);
					}
					if (a[0][1][2].color[4] == white && a[0][1][2].color[0] == orange) {
						Rotate(1, 3);
					}
				}
				if (a[1][0][2].color[2] == red && a[2][1][2].color[5] == blue && a[1][2][2].color[3] == orange) {
					if (a[0][2][1].color[4] == white && a[0][2][1].color[3] == green) {
						Rotate(1, -3);
					}
					if (a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) {
						Rotate(1, 3);
					}
				}
				if (a[1][0][2].color[2] == red && a[2][1][2].color[5] == green && a[1][2][2].color[3] == orange) {
					if (a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) {
						Rotate(1, 3);
					}
					if (a[0][2][1].color[3] == blue && a[0][2][1].color[4] == white) {
						Rotate(1, -3);
					}
				}if (a[1][0][2].color[2] == green && a[2][1][2].color[5] == orange && a[1][2][2].color[3] == red) {
					if (a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) {
						Rotate(1, 3);
					}
				}
				if (a[1][0][2].color[2] == orange && a[2][1][2].color[5] == red && a[1][2][2].color[3] == green) {
					if (a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) {
						Rotate(1, 3);
					}
				}
				if (a[1][0][2].color[2] == red && a[2][1][2].color[5] == orange && a[1][2][2].color[3] == green) {
					if (a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) {
						Rotate(1, 3);
					}
				}
				if (a[1][0][2].color[2] == green && a[2][1][2].color[5] == red && a[1][2][2].color[3] == orange) {
					if (a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) {
						Rotate(1, 3);
					}
				}
				if (a[1][0][2].color[2] == green && a[2][1][2].color[5] == red && a[1][2][2].color[3] == blue) {
					if (a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) {
						Rotate(1, 3);
					}
				}
				if (a[1][0][2].color[2] == blue && a[2][1][2].color[5] == red && a[1][2][2].color[3] == green) {
					if (a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) {
						Rotate(1, 3);
					}
				}
				if (a[1][0][2].color[2] == red && a[2][1][2].color[5] == green && a[1][2][2].color[3] == blue) {
					if (a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) {
						Rotate(1, 3);
					}
					if (a[2][2][1].color[3] == orange && a[2][2][1].color[5] == white) {
						Rotate(3, -3);
					}
				}
				if (a[1][0][2].color[2] == green && a[2][1][2].color[5] == blue && a[1][2][2].color[3] == red) {
					if (a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) {
						Rotate(1, 3);
					}
				}
				if (a[1][0][2].color[2] == blue && a[2][1][2].color[5] == green && a[1][2][2].color[3] == red) {
					if (a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) {
						Rotate(1, 3);
					}
					if (a[0][0][1].color[2] == orange && a[0][0][1].color[4] == white) {
						Rotate(2, 3);
					}
				}
				if (a[1][0][2].color[2] == orange && a[2][1][2].color[5] == blue && a[1][2][2].color[3] == red) {
					if (a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) {
						Rotate(1, -3);
					}
				}
				if (a[1][0][2].color[2] == red && a[2][1][2].color[5] == orange && a[1][2][2].color[3] == blue) {
					if (a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) {
						Rotate(1, -3);
					}
				}
				if (a[1][0][2].color[2] == blue && a[2][1][2].color[5] == red && a[1][2][2].color[3] == orange) {
					if (a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) {
						Rotate(1, -3);
					}
				}
				if (a[1][0][2].color[2] == blue && a[2][1][2].color[5] == orange && a[1][2][2].color[3] == red) {
					if (a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) {
						Rotate(1, -3);
					}
				}
				if (a[1][0][2].color[2] == orange && a[2][1][2].color[5] == red && a[1][2][2].color[3] == blue) {
					if (a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) {
						Rotate(1, -3);
					}
				}
				// Red
				if (a[1][0][2].color[2] == blue && a[2][1][2].color[5] == orange && a[1][2][2].color[3] == green) {
					if (a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) {
						Rotate(4, -3);
					}
					if (a[0][2][1].color[3] == red && a[0][2][1].color[4] == white) {
						Rotate(1, -3);
					}
				}
				if (a[1][0][2].color[2] == blue && a[2][1][2].color[5] == green && a[1][2][2].color[3] == orange) {
					if (a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) {
						Rotate(4, -3);
					}
					if (a[0][2][1].color[3] == red && a[0][2][1].color[4] == white) {
						Rotate(1, -3);
					}
				}
				if (a[1][0][2].color[2] == orange && a[2][1][2].color[5] == blue && a[1][2][2].color[3] == green) {
					if (a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) {
						Rotate(4, -3);
					}
					if (a[0][2][1].color[3] == red && a[0][2][1].color[4] == white) {
						Rotate(1, -3);
					}
				}
				if (a[1][0][2].color[2] == green && a[2][1][2].color[5] == orange && a[1][2][2].color[3] == blue) {
					if (a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) {
						Rotate(4, -3);
					}
					if (a[0][2][1].color[3] == red && a[0][2][1].color[4] == white) {
						Rotate(1, -3);
					}
				}
				if (a[1][0][2].color[2] == green && a[2][1][2].color[5] == blue && a[1][2][2].color[3] == orange) {
					if (a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) {
						Rotate(4, -3);
					}
					if (a[0][2][1].color[3] == red && a[0][2][1].color[4] == white) {
						Rotate(1, -3);
					}
				}
				if (a[1][0][2].color[2] == orange && a[2][1][2].color[5] == green && a[1][2][2].color[3] == blue) {
					if (a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) {
						Rotate(4, -3);
					}
					if (a[0][2][1].color[3] == red && a[0][2][1].color[4] == white) {
						Rotate(1, -3);
					}
				}
			}
			//если 2 боковых грани белые
			if (a[0][1][2].color[0] == white && a[1][0][2].color[0] != white && a[2][1][2].color[0] == white && a[1][2][2].color[0] != white) {
				/*if (a[0][1][2].color[4] == blue && a[2][1][2].color[5] == orange) {
					if (a[2][2][1].color[5] == white && a[2][2][1].color[3] == red) {
						Rotate(1, 3);
					}
				}
				if (a[0][1][2].color[4] == orange && a[2][1][2].color[5] == blue) {
					if (a[2][0][1].color[2] == green && a[2][0][1].color[5] == white) {
						Rotate(2, -3);
					}
				}*/
				if (a[0][1][2].color[4] == red && a[2][1][2].color[5] == orange) {
					if ((a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
						Rotate(2, 3);
					}
					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == blue) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
						Rotate(1, 3);
					}
					if ((a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
						Rotate(2, 3);
					}
					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == green) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
						Rotate(1, 3);
					}
				}
				if (a[0][1][2].color[4] == red && a[2][1][2].color[5] == blue) {
					if ((a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
						Rotate(2, 3);
					}
					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == orange) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
						Rotate(1, 3);
					}
					if ((a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
						Rotate(2, 3);
					}
					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == green) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
						Rotate(1, 3);
					}
				}
				if (a[0][1][2].color[4] == red && a[2][1][2].color[5] == green) {
					if ((a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
						Rotate(2, 3);
					}
					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == orange) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
						Rotate(1, 3);
					}
					if ((a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
						Rotate(2, 3);
					}
					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == blue) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
						Rotate(1, 3);
					}
				}
				if (a[0][1][2].color[4] == orange && a[2][1][2].color[5] == red) {
					if ((a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
						Rotate(2, 3);
					}
					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == blue) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
						Rotate(1, 3);
					}
					if ((a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
						Rotate(2, 3);
					}
					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == green) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
						Rotate(1, 3);
					}
				}
				if (a[0][1][2].color[4] == orange && a[2][1][2].color[5] == green) {
					if ((a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
						Rotate(2, 3);
					}
					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == blue) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
						Rotate(1, 3);
					}
					if ((a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
						Rotate(2, 3);
					}
					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == red) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
						Rotate(1, 3);
					}
				}
				if (a[0][1][2].color[4] == orange && a[2][1][2].color[5] == blue) {
					if ((a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
						Rotate(2, 3);
					}
					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == green) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
						Rotate(1, 3);
					}
					if ((a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
						Rotate(2, 3);
					}
					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == red) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
						Rotate(1, 3);
					}
				}
				if (a[0][1][2].color[4] == green && a[2][1][2].color[5] == blue) {
					if ((a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
						Rotate(2, 3);
					}
					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == orange) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
						Rotate(1, 3);
					}
					if ((a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
						Rotate(2, 3);
					}
					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == red) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
						Rotate(1, 3);
					}
				}
				if (a[0][1][2].color[4] == green && a[2][1][2].color[5] == orange) {
					if ((a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
						Rotate(2, 3);
					}
					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == blue) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
						Rotate(1, 3);
					}
					if ((a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
						Rotate(2, 3);
					}
					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == red) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
						Rotate(1, 3);
					}
				}
				if (a[0][1][2].color[4] == green && a[2][1][2].color[5] == red) {
					if ((a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
						Rotate(2, 3);
					}
					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == blue) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
						Rotate(1, 3);
					}
					if ((a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
						Rotate(2, 3);
					}
					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == orange) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
						Rotate(1, 3);
					}
				}
				if (a[0][1][2].color[4] == blue && a[2][1][2].color[5] == green) {
					if ((a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
						Rotate(2, 3);
					}
					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == orange) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
						Rotate(1, 3);
					}
					if ((a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
						Rotate(2, 3);
					}
					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == red) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
						Rotate(1, 3);
					}
				}
				if (a[0][1][2].color[4] == blue && a[2][1][2].color[5] == red) {
					if ((a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
						Rotate(2, 3);
					}
					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == orange) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
						Rotate(1, 3);
					}
					if ((a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
						Rotate(2, 3);
					}
					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == green) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
						Rotate(1, 3);
					}
				}
				if (a[0][1][2].color[4] == blue && a[2][1][2].color[5] == orange) {
					if ((a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
						Rotate(2, 3);
					}
					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == red) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
						Rotate(1, 3);
					}
					if ((a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
						Rotate(2, 3);
					}
					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == green) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
						Rotate(1, 3);
					}
				}
			}//если верхняя и нижняя грани белые
			if (a[0][1][2].color[0] != white && a[1][0][2].color[0] == white && a[2][1][2].color[0] != white && a[1][2][2].color[0] == white) {
				/*if (a[1][0][2].color[2] == blue && a[1][2][2].color[3] == orange) {
					if (a[2][0][1].color[5] == white && a[2][0][1].color[2] == green && a[2][2][1].color[5] == white && a[2][2][1].color[3] == red) {
						Rotate(1, 3);
					}
				}*/
				if (a[1][0][2].color[2] == red && a[1][2][2].color[3] == orange) {
					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == blue)) {
						Rotate(5, -3);
					}
					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == green)) {
						Rotate(5, -3);
					}
					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
				}
				if (a[1][0][2].color[2] == red && a[1][2][2].color[3] == blue) {
					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == orange)) {
						Rotate(5, -3);
					}
					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == green)) {
						Rotate(5, -3);
					}
					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
				}
				if (a[1][0][2].color[2] == red && a[1][2][2].color[3] == green) {
					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == orange)) {
						Rotate(5, -3);
					}
					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == blue)) {
						Rotate(5, -3);
					}
					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
				}
				if (a[1][0][2].color[2] == green && a[1][2][2].color[3] == blue) {
					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == orange)) {
						Rotate(5, -3);
					}
					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == red)) {
						Rotate(5, -3);
					}
					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
				}
				if (a[1][0][2].color[2] == green && a[1][2][2].color[3] == orange) {
					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == blue)) {
						Rotate(5, -3);
					}
					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == red)) {
						Rotate(5, -3);
					}
					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
				}
				if (a[1][0][2].color[2] == green && a[1][2][2].color[3] == red) {
					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == blue)) {
						Rotate(5, -3);
					}
					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == orange)) {
						Rotate(5, -3);
					}
					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
				}
				if (a[1][0][2].color[2] == blue && a[1][2][2].color[3] == green) {
					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == orange)) {
						Rotate(5, -3);
					}
					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == red)) {
						Rotate(5, -3);
					}
					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
				}
				if (a[1][0][2].color[2] == blue && a[1][2][2].color[3] == red) {
					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == orange)) {
						Rotate(5, -3);
					}
					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == green)) {
						Rotate(5, -3);
					}
					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
				}
				if (a[1][0][2].color[2] == blue && a[1][2][2].color[3] == orange) {
					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == red)) {
						Rotate(5, -3);
					}
					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == green)) {
						Rotate(5, -3);
					}
					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
				}
				if (a[1][0][2].color[2] == orange && a[1][2][2].color[3] == red) {
					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == blue)) {
						Rotate(5, -3);
					}
					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == green)) {
						Rotate(5, -3);
					}
					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
				}
				if (a[1][0][2].color[2] == orange && a[1][2][2].color[3] == blue) {
					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == red)) {
						Rotate(5, -3);
					}
					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == green)) {
						Rotate(5, -3);
					}
					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
				}
				if (a[1][0][2].color[2] == orange && a[1][2][2].color[3] == green) {
					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == blue)) {
						Rotate(5, -3);
					}
					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == red)) {
						Rotate(5, -3);
					}
					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
				}
			}
			//два белых (лево-ценнтр-верх)
			if (a[0][1][2].color[0] == white && a[1][0][2].color[0] != white && a[1][2][2].color[0] == white && a[2][1][2].color[0] != white) {
				if (a[0][1][2].color[4] == red && a[1][2][2].color[3] == green) {
					if ((a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white)) {
						Rotate(2, 3);
					}
					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == orange) && (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white)) {
						Rotate(1, 3);
					}
					if ((a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white)) {
						Rotate(2, 3);
					}
					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == blue) && (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white)) {
						Rotate(1, 3);
					}
				}
				if (a[0][1][2].color[4] == red && a[1][2][2].color[3] == orange) {
					if ((a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white)) {
						Rotate(2, 3);
					}
					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == green) && (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white)) {
						Rotate(1, 3);
					}
					if ((a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white)) {
						Rotate(2, 3);
					}
					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == blue) && (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white)) {
						Rotate(1, 3);
					}
				}
				if (a[0][1][2].color[4] == red && a[1][2][2].color[3] == blue) {
					if ((a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white)) {
						Rotate(2, 3);
					}
					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == orange) && (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white)) {
						Rotate(1, 3);
					}
					if ((a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white)) {
						Rotate(2, 3);
					}
					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == green) && (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white)) {
						Rotate(1, 3);
					}
				}
				if (a[0][1][2].color[4] == green && a[1][2][2].color[3] == red) {
					if ((a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white)) {
						Rotate(2, 3);
					}
					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == orange) && (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white)) {
						Rotate(1, 3);
					}
					if ((a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white)) {
						Rotate(2, 3);
					}
					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == blue) && (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white)) {
						Rotate(1, 3);
					}
				}
				if (a[0][1][2].color[4] == green && a[1][2][2].color[3] == blue) {
					if ((a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white)) {
						Rotate(2, 3);
					}
					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == orange) && (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white)) {
						Rotate(1, 3);
					}
					if ((a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white)) {
						Rotate(2, 3);
					}
					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == red) && (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white)) {
						Rotate(1, 3);
					}
				}
				if (a[0][1][2].color[4] == green && a[1][2][2].color[3] == orange) {
					if ((a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white)) {
						Rotate(2, 3);
					}
					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == blue) && (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white)) {
						Rotate(1, 3);
					}
					if ((a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white)) {
						Rotate(2, 3);
					}
					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == red) && (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white)) {
						Rotate(1, 3);
					}
				}
				if (a[0][1][2].color[4] == blue && a[1][2][2].color[3] == red) {
					if ((a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white)) {
						Rotate(2, 3);
					}
					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == orange) && (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white)) {
						Rotate(1, 3);
					}
					if ((a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white)) {
						Rotate(2, 3);
					}
					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == green) && (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white)) {
						Rotate(1, 3);
					}
				}
				if (a[0][1][2].color[4] == blue && a[1][2][2].color[3] == green) {
					if ((a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white)) {
						Rotate(2, 3);
					}
					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == orange) && (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white)) {
						Rotate(1, 3);
					}
					if ((a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white)) {
						Rotate(2, 3);
					}
					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == red) && (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white)) {
						Rotate(1, 3);
					}
				}
				if (a[0][1][2].color[4] == blue && a[1][2][2].color[3] == orange) {
					if ((a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white)) {
						Rotate(2, 3);
					}
					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == green) && (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white)) {
						Rotate(1, 3);
					}
					if ((a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white)) {
						Rotate(2, 3);
					}
					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == red) && (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white)) {
						Rotate(1, 3);
					}
				}
				if (a[0][1][2].color[4] == orange && a[1][2][2].color[3] == red) {
					if ((a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white)) {
						Rotate(2, 3);
					}
					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == green) && (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white)) {
						Rotate(1, 3);
					}
					if ((a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white)) {
						Rotate(2, 3);
					}
					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == blue) && (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white)) {
						Rotate(1, 3);
					}
				}
				if (a[0][1][2].color[4] == orange && a[1][2][2].color[3] == green) {
					if ((a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white)) {
						Rotate(2, 3);
					}
					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == blue) && (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white)) {
						Rotate(1, 3);
					}
					if ((a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white)) {
						Rotate(2, 3);
					}
					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == red) && (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white)) {
						Rotate(1, 3);
					}
				}
				if (a[0][1][2].color[4] == orange && a[1][2][2].color[3] == blue) {
					if ((a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white)) {
						Rotate(2, 3);
					}
					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == green) && (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white)) {
						Rotate(1, 3);
					}
					if ((a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white)) {
						Rotate(2, 3);
					}
					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == red) && (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white)) {
						Rotate(1, 3);
					}
				}
			}
			// два белых (лeво-центр-низ)
			if (a[0][1][2].color[0] == white && a[1][0][2].color[0] == white && a[1][2][2].color[0] != white && a[2][1][2].color[0] != white) {
				if (a[0][1][2].color[4] == green && a[1][0][2].color[2] == red) {
					if ((a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == blue)) {
						Rotate(5, -3);
					}
					if ((a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == orange)) {
						Rotate(5, -3);
					}
					if ((a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
					if ((a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
				}
				if (a[0][1][2].color[4] == green && a[1][0][2].color[2] == blue) {
					if ((a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == red)) {
						Rotate(5, -3);
					}
					if ((a[1][2][2].color[0] == red && a[1][2][2].color[3] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == orange)) {
						Rotate(5, -3);
					}
					if ((a[1][2][2].color[0] == red && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
					if ((a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
				}
				if (a[0][1][2].color[4] == green && a[1][0][2].color[2] == orange) {
					if ((a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == red)) {
						Rotate(5, -3);
					}
					if ((a[1][2][2].color[0] == red && a[1][2][2].color[3] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == blue)) {
						Rotate(5, -3);
					}
					if ((a[1][2][2].color[0] == red && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
					if ((a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
				}
				if (a[0][1][2].color[4] == red && a[1][0][2].color[2] == green) {
					if ((a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == blue)) {
						Rotate(5, -3);
					}
					if ((a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == orange)) {
						Rotate(5, -3);
					}
					if ((a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
					if ((a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
				}
				if (a[0][1][2].color[4] == red && a[1][0][2].color[2] == orange) {
					if ((a[1][2][2].color[0] == green && a[1][2][2].color[3] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == blue)) {
						Rotate(5, -3);
					}
					if ((a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == green)) {
						Rotate(5, -3);
					}
					if ((a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
					if ((a[1][2][2].color[0] == green && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
				}
				if (a[0][1][2].color[4] == red && a[1][0][2].color[2] == blue) {
					if ((a[1][2][2].color[0] == green && a[1][2][2].color[3] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == orange)) {
						Rotate(5, -3);
					}
					if ((a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == green)) {
						Rotate(5, -3);
					}
					if ((a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
					if ((a[1][2][2].color[0] == green && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
				}
				if (a[0][1][2].color[4] == blue && a[1][0][2].color[2] == red) {
					if ((a[1][2][2].color[0] == green && a[1][2][2].color[3] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == orange)) {
						Rotate(5, -3);
					}
					if ((a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == green)) {
						Rotate(5, -3);
					}
					if ((a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
					if ((a[1][2][2].color[0] == green && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
				}
				if (a[0][1][2].color[4] == blue && a[1][0][2].color[2] == green) {
					if ((a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == red)) {
						Rotate(5, -3);
					}
					if ((a[1][2][2].color[0] == red && a[1][2][2].color[3] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == orange)) {
						Rotate(5, -3);
					}
					if ((a[1][2][2].color[0] == red && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
					if ((a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
				}
				if (a[0][1][2].color[4] == blue && a[1][0][2].color[2] == orange) {
					if ((a[1][2][2].color[0] == green && a[1][2][2].color[3] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == red)) {
						Rotate(5, -3);
					}
					if ((a[1][2][2].color[0] == red && a[1][2][2].color[3] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == green)) {
						Rotate(5, -3);
					}
					if ((a[1][2][2].color[0] == red && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
					if ((a[1][2][2].color[0] == green && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
				}
				if (a[0][1][2].color[4] == orange && a[1][0][2].color[2] == red) {
					if ((a[1][2][2].color[0] == green && a[1][2][2].color[3] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == blue)) {
						Rotate(5, -3);
					}
					if ((a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == green)) {
						Rotate(5, -3);
					}
					if ((a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
					if ((a[1][2][2].color[0] == green && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
				}
				if (a[0][1][2].color[4] == orange && a[1][0][2].color[2] == green) {
					if ((a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == red)) {
						Rotate(5, -3);
					}
					if ((a[1][2][2].color[0] == red && a[1][2][2].color[3] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == blue)) {
						Rotate(5, -3);
					}
					if ((a[1][2][2].color[0] == red && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
					if ((a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
				}
				if (a[0][1][2].color[4] == orange && a[1][0][2].color[2] == blue) {
					if ((a[1][2][2].color[0] == green && a[1][2][2].color[3] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == red)) {
						Rotate(5, -3);
					}
					if ((a[1][2][2].color[0] == red && a[1][2][2].color[3] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == green)) {
						Rotate(5, -3);
					}
					if ((a[1][2][2].color[0] == red && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
					if ((a[1][2][2].color[0] == green && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
				}
			}
			//2 белые (низ-центр-право)
			if (a[0][1][2].color[0] != white && a[1][0][2].color[0] == white && a[1][2][2].color[0] != white && a[2][1][2].color[0] == white) {
				if (a[1][0][2].color[2] == red && a[2][1][2].color[5] == green) {
					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
						Rotate(3, -3);
					}
					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == blue)) {
						Rotate(1, 3);
					}
					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
						Rotate(3, -3);
					}
					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == orange)) {
						Rotate(1, 3);
					}
				}
				if (a[1][0][2].color[2] == red && a[2][1][2].color[5] == orange) {
					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
						Rotate(3, -3);
					}
					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == blue)) {
						Rotate(1, 3);
					}
					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
						Rotate(3, -3);
					}
					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == green)) {
						Rotate(1, 3);
					}
				}
				if (a[1][0][2].color[2] == red && a[2][1][2].color[5] == blue) {
					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
						Rotate(3, -3);
					}
					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == orange)) {
						Rotate(1, 3);
					}
					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
						Rotate(3, -3);
					}
					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == green)) {
						Rotate(1, 3);
					}
				}
				if (a[1][0][2].color[2] == green && a[2][1][2].color[5] == red) {
					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
						Rotate(3, -3);
					}
					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == blue)) {
						Rotate(1, 3);
					}
					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
						Rotate(3, -3);
					}
					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == orange)) {
						Rotate(1, 3);
					}
				}
				if (a[1][0][2].color[2] == green && a[2][1][2].color[5] == blue) {
					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
						Rotate(3, -3);
					}
					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == red)) {
						Rotate(1, 3);
					}
					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
						Rotate(3, -3);
					}
					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == orange)) {
						Rotate(1, 3);
					}
				}
				if (a[1][0][2].color[2] == green && a[2][1][2].color[5] == orange) {
					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
						Rotate(3, -3);
					}
					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == red)) {
						Rotate(1, 3);
					}
					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
						Rotate(3, -3);
					}
					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == blue)) {
						Rotate(1, 3);
					}
				}
				if (a[1][0][2].color[2] == orange && a[2][1][2].color[5] == red) {
					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
						Rotate(3, -3);
					}
					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == blue)) {
						Rotate(1, 3);
					}
					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
						Rotate(3, -3);
					}
					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == green)) {
						Rotate(1, 3);
					}
				}
				if (a[1][0][2].color[2] == orange && a[2][1][2].color[5] == green) {
					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
						Rotate(3, -3);
					}
					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == red)) {
						Rotate(1, 3);
					}
					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
						Rotate(3, -3);
					}
					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == blue)) {
						Rotate(1, 3);
					}
				}
				if (a[1][0][2].color[2] == orange && a[2][1][2].color[5] == blue) {
					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
						Rotate(3, -3);
					}
					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == red)) {
						Rotate(1, 3);
					}
					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
						Rotate(3, -3);
					}
					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == green)) {
						Rotate(1, 3);
					}
				}
				if (a[1][0][2].color[2] == blue && a[2][1][2].color[5] == red) {
					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
						Rotate(3, -3);
					}
					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == orange)) {
						Rotate(1, 3);
					}
					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
						Rotate(3, -3);
					}
					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == green)) {
						Rotate(1, 3);
					}
				}
				if (a[1][0][2].color[2] == blue && a[2][1][2].color[5] == green) {
					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
						Rotate(3, -3);
					}
					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == red)) {
						Rotate(1, 3);
					}
					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
						Rotate(3, -3);
					}
					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == orange)) {
						Rotate(1, 3);
					}
				}
				if (a[1][0][2].color[2] == blue && a[2][1][2].color[5] == orange) {
					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
						Rotate(3, -3);
					}
					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == red)) {
						Rotate(1, 3);
					}
					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
						Rotate(3, -3);
					}
					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == green)) {
						Rotate(1, 3);
					}
				}
			}
			//2 белые (право-центр-верх)
			if (a[0][1][2].color[0] != white && a[1][0][2].color[0] != white && a[1][2][2].color[0] == white && a[2][1][2].color[0] == white) {
				if (a[1][2][2].color[3] == green && a[2][1][2].color[5] == red) {
					if ((a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == blue)) {
						Rotate(4, 3);
					}
					if ((a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == orange)) {
						Rotate(4, 3);
					}
					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white)) {
						Rotate(1, -3);
					}
					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white)) {
						Rotate(1, -3);
					}
				}
				if (a[1][2][2].color[3] == green && a[2][1][2].color[5] == blue) {
					if ((a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == red)) {
						Rotate(4, 3);
					}
					if ((a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == orange)) {
						Rotate(4, 3);
					}
					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white)) {
						Rotate(1, -3);
					}
					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == red && a[1][0][2].color[2] == white)) {
						Rotate(1, -3);
					}
				}
				if (a[1][2][2].color[3] == green && a[2][1][2].color[5] == orange) {
					if ((a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == red)) {
						Rotate(4, 3);
					}
					if ((a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == blue)) {
						Rotate(4, 3);
					}
					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white)) {
						Rotate(1, -3);
					}
					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == red && a[1][0][2].color[2] == white)) {
						Rotate(1, -3);
					}
				}
				if (a[1][2][2].color[3] == red && a[2][1][2].color[5] == green) {
					if ((a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == blue)) {
						Rotate(4, 3);
					}
					if ((a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == orange)) {
						Rotate(4, 3);
					}
					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white)) {
						Rotate(1, -3);
					}
					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white)) {
						Rotate(1, -3);
					}
				}
				if (a[1][2][2].color[3] == red && a[2][1][2].color[5] == orange) {
					if ((a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == blue)) {
						Rotate(4, 3);
					}
					if ((a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == green)) {
						Rotate(4, 3);
					}
					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == green && a[1][0][2].color[2] == white)) {
						Rotate(1, -3);
					}
					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white)) {
						Rotate(1, -3);
					}
				}
				if (a[1][2][2].color[3] == red && a[2][1][2].color[5] == blue) {
					if ((a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == orange)) {
						Rotate(4, 3);
					}
					if ((a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == green)) {
						Rotate(4, 3);
					}
					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == green && a[1][0][2].color[2] == white)) {
						Rotate(1, -3);
					}
					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white)) {
						Rotate(1, -3);
					}
				}
				if (a[1][2][2].color[3] == orange && a[2][1][2].color[5] == red) {
					if ((a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == blue)) {
						Rotate(4, 3);
					}
					if ((a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == green)) {
						Rotate(4, 3);
					}
					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == green && a[1][0][2].color[2] == white)) {
						Rotate(1, -3);
					}
					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white)) {
						Rotate(1, -3);
					}
				}
				if (a[1][2][2].color[3] == orange && a[2][1][2].color[5] == green) {
					if ((a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == red)) {
						Rotate(4, 3);
					}
					if ((a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == blue)) {
						Rotate(4, 3);
					}
					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white)) {
						Rotate(1, -3);
					}
					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == red && a[1][0][2].color[2] == white)) {
						Rotate(1, -3);
					}
				}
				if (a[1][2][2].color[3] == orange && a[2][1][2].color[5] == blue) {
					if ((a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == red)) {
						Rotate(4, 3);
					}
					if ((a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == green)) {
						Rotate(4, 3);
					}
					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == green && a[1][0][2].color[2] == white)) {
						Rotate(1, -3);
					}
					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == red && a[1][0][2].color[2] == white)) {
						Rotate(1, -3);
					}
				}
				if (a[1][2][2].color[3] == blue && a[2][1][2].color[5] == red) {
					if ((a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == orange)) {
						Rotate(4, 3);
					}
					if ((a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == green)) {
						Rotate(4, 3);
					}
					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == green && a[1][0][2].color[2] == white)) {
						Rotate(1, -3);
					}
					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white)) {
						Rotate(1, -3);
					}
				}
				if (a[1][2][2].color[3] == blue && a[2][1][2].color[5] == green) {
					if ((a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == red)) {
						Rotate(4, 3);
					}
					if ((a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == orange)) {
						Rotate(4, 3);
					}
					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white)) {
						Rotate(1, -3);
					}
					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == red && a[1][0][2].color[2] == white)) {
						Rotate(1, -3);
					}
				}
				if (a[1][2][2].color[3] == blue && a[2][1][2].color[5] == orange) {
					if ((a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == red)) {
						Rotate(4, 3);
					}
					if ((a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == green)) {
						Rotate(4, 3);
					}
					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == green && a[1][0][2].color[2] == white)) {
						Rotate(1, -3);
					}
					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == red && a[1][0][2].color[2] == white)) {
						Rotate(1, -3);
					}
				}
			}
			//1 белая правая  
			if (a[0][1][2].color[0] != white && a[1][0][2].color[0] != white && a[2][1][2].color[0] == white && a[1][2][2].color[0] != white) {
				if (a[2][1][2].color[0] == white && a[2][1][2].color[5] == orange) {
					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
						Rotate(2, 3);
					}
					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[2][0][1].color[5] == blue && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
						Rotate(1, 3);
					}
					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
						Rotate(2, 3);
					}
					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[2][0][1].color[5] == green && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
						Rotate(1, 3);
					}
					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
						Rotate(2, 3);
					}
					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[2][0][1].color[5] == blue && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
						Rotate(1, 3);
					}
					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
						Rotate(2, 3);
					}
					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[2][0][1].color[5] == red && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
						Rotate(1, 3);
					}
					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
						Rotate(2, 3);
					}
					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[2][0][1].color[5] == red && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
						Rotate(1, 3);
					}
					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
						Rotate(2, 3);
					}
					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[2][0][1].color[5] == green && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
						Rotate(1, 3);
					}
				}
				if (a[2][1][2].color[0] == white && a[2][1][2].color[5] == blue) {
					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
						Rotate(2, 3);
					}
					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[2][0][1].color[5] == orange && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
						Rotate(1, 3);
					}
					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
						Rotate(2, 3);
					}
					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[2][0][1].color[5] == green && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
						Rotate(1, 3);
					}
					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
						Rotate(2, 3);
					}
					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[2][0][1].color[5] == orange && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
						Rotate(1, 3);
					}
					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
						Rotate(2, 3);
					}
					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[2][0][1].color[5] == red && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
						Rotate(1, 3);
					}
					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
						Rotate(2, 3);
					}
					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[2][0][1].color[5] == red && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
						Rotate(1, 3);
					}
					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
						Rotate(2, 3);
					}
					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[2][0][1].color[5] == green && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
						Rotate(1, 3);
					}
				}
				if (a[2][1][2].color[0] == white && a[2][1][2].color[5] == green) {
					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
						Rotate(2, 3);
					}
					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[2][0][1].color[5] == orange && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
						Rotate(1, 3);
					}
					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
						Rotate(2, 3);
					}
					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[2][0][1].color[5] == blue && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
						Rotate(1, 3);
					}
					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
						Rotate(2, 3);
					}
					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[2][0][1].color[5] == orange && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
						Rotate(1, 3);
					}
					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
						Rotate(2, 3);
					}
					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[2][0][1].color[5] == red && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
						Rotate(1, 3);
					}
					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
						Rotate(2, 3);
					}
					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[2][0][1].color[5] == red && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
						Rotate(1, 3);
					}
					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
						Rotate(2, 3);
					}
					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[2][0][1].color[5] == blue && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
						Rotate(1, 3);
					}
				}
				if (a[2][1][2].color[0] == white && a[2][1][2].color[5] == red) {
					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
						Rotate(2, 3);
					}
					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[2][0][1].color[5] == orange && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
						Rotate(1, 3);
					}
					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
						Rotate(2, 3);
					}
					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[2][0][1].color[5] == blue && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
						Rotate(1, 3);
					}
					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
						Rotate(2, 3);
					}
					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[2][0][1].color[5] == orange && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
						Rotate(1, 3);
					}
					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
						Rotate(2, 3);
					}
					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[2][0][1].color[5] == green && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
						Rotate(1, 3);
					}
					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
						Rotate(2, 3);
					}
					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[2][0][1].color[5] == green && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
						Rotate(1, 3);
					}
					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
						Rotate(2, 3);
					}
					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[2][0][1].color[5] == blue && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
						Rotate(1, 3);
					}
				}
			}
			//1 белая верхняя
			if (a[0][1][2].color[0] != white && a[1][0][2].color[0] != white && a[2][1][2].color[0] != white && a[1][2][2].color[0] == white) {
				if (a[1][2][2].color[0] == white && a[1][2][2].color[3] == orange) {
					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[2][0][1].color[5] == blue && a[2][0][1].color[2] == white)) {
						Rotate(5, -3);
					}
					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[2][0][1].color[5] == red && a[2][0][1].color[2] == white)) {
						Rotate(5, -3);
					}
					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[2][0][1].color[5] == green && a[2][0][1].color[2] == white)) {
						Rotate(5, -3);
					}
					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[2][0][1].color[5] == red && a[2][0][1].color[2] == white)) {
						Rotate(5, -3);
					}
					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[2][0][1].color[5] == blue && a[2][0][1].color[2] == white)) {
						Rotate(5, -3);
					}
					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[2][0][1].color[5] == green && a[2][0][1].color[2] == white)) {
						Rotate(5, -3);
					}
					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
				}
				if (a[1][2][2].color[0] == white && a[1][2][2].color[3] == blue) {
					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[2][0][1].color[5] == orange && a[2][0][1].color[2] == white)) {
						Rotate(5, -3);
					}
					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[2][0][1].color[5] == red && a[2][0][1].color[2] == white)) {
						Rotate(5, -3);
					}
					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[2][0][1].color[5] == green && a[2][0][1].color[2] == white)) {
						Rotate(5, -3);
					}
					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[2][0][1].color[5] == red && a[2][0][1].color[2] == white)) {
						Rotate(5, -3);
					}
					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[2][0][1].color[5] == orange && a[2][0][1].color[2] == white)) {
						Rotate(5, -3);
					}
					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[2][0][1].color[5] == green && a[2][0][1].color[2] == white)) {
						Rotate(5, -3);
					}
					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
				}
				if (a[1][2][2].color[0] == white && a[1][2][2].color[3] == green) {
					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[2][0][1].color[5] == orange && a[2][0][1].color[2] == white)) {
						Rotate(5, -3);
					}
					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[2][0][1].color[5] == red && a[2][0][1].color[2] == white)) {
						Rotate(5, -3);
					}
					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[2][0][1].color[5] == blue && a[2][0][1].color[2] == white)) {
						Rotate(5, -3);
					}
					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[2][0][1].color[5] == red && a[2][0][1].color[2] == white)) {
						Rotate(5, -3);
					}
					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[2][0][1].color[5] == orange && a[2][0][1].color[2] == white)) {
						Rotate(5, -3);
					}
					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[2][0][1].color[5] == blue && a[2][0][1].color[2] == white)) {
						Rotate(5, -3);
					}
					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
				}
				if (a[1][2][2].color[0] == white && a[1][2][2].color[3] == red) {
					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[2][0][1].color[5] == orange && a[2][0][1].color[2] == white)) {
						Rotate(5, -3);
					}
					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[2][0][1].color[5] == green && a[2][0][1].color[2] == white)) {
						Rotate(5, -3);
					}
					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[2][0][1].color[5] == blue && a[2][0][1].color[2] == white)) {
						Rotate(5, -3);
					}
					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[2][0][1].color[5] == green && a[2][0][1].color[2] == white)) {
						Rotate(5, -3);
					}
					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[2][0][1].color[5] == orange && a[2][0][1].color[2] == white)) {
						Rotate(5, -3);
					}
					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[2][0][1].color[5] == blue && a[2][0][1].color[2] == white)) {
						Rotate(5, -3);
					}
					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
				}
			}
			//белая левая
			if (a[0][1][2].color[0] == white && a[1][0][2].color[0] != white && a[2][1][2].color[0] != white && a[1][2][2].color[0] != white) {
				if (a[0][1][2].color[0] == white && a[0][1][2].color[4] == orange) {
					if ((a[2][1][2].color[0] == red && a[2][1][2].color[5] == white) && (a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
						Rotate(2, 3);
					}
					if ((a[2][1][2].color[0] == red && a[2][1][2].color[5] == white) && (a[2][0][1].color[5] == blue && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
						Rotate(1, 3);
					}
					if ((a[2][1][2].color[0] == red && a[2][1][2].color[5] == white) && (a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
						Rotate(2, 3);
					}
					if ((a[2][1][2].color[0] == red && a[2][1][2].color[5] == white) && (a[2][0][1].color[5] == green && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
						Rotate(1, 3);
					}
					if ((a[2][1][2].color[0] == green && a[2][1][2].color[5] == white) && (a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
						Rotate(2, 3);
					}
					if ((a[2][1][2].color[0] == green && a[2][1][2].color[5] == white) && (a[2][0][1].color[5] == blue && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
						Rotate(1, 3);
					}
					if ((a[2][1][2].color[0] == green && a[2][1][2].color[5] == white) && (a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
						Rotate(2, 3);
					}
					if ((a[2][1][2].color[0] == green && a[2][1][2].color[5] == white) && (a[2][0][1].color[5] == red && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
						Rotate(1, 3);
					}
					if ((a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white) && (a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
						Rotate(2, 3);
					}
					if ((a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white) && (a[2][0][1].color[5] == red && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
						Rotate(1, 3);
					}
					if ((a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white) && (a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
						Rotate(2, 3);
					}
					if ((a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white) && (a[2][0][1].color[5] == green && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
						Rotate(1, 3);
					}
				}
				if (a[0][1][2].color[0] == white && a[0][1][2].color[4] == blue) {
					if ((a[2][1][2].color[0] == red && a[2][1][2].color[5] == white) && (a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
						Rotate(2, 3);
					}
					if ((a[2][1][2].color[0] == red && a[2][1][2].color[5] == white) && (a[2][0][1].color[5] == orange && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
						Rotate(1, 3);
					}
					if ((a[2][1][2].color[0] == red && a[2][1][2].color[5] == white) && (a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
						Rotate(2, 3);
					}
					if ((a[2][1][2].color[0] == red && a[2][1][2].color[5] == white) && (a[2][0][1].color[5] == green && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
						Rotate(1, 3);
					}
					if ((a[2][1][2].color[0] == green && a[2][1][2].color[5] == white) && (a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
						Rotate(2, 3);
					}
					if ((a[2][1][2].color[0] == green && a[2][1][2].color[5] == white) && (a[2][0][1].color[5] == orange && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
						Rotate(1, 3);
					}
					if ((a[2][1][2].color[0] == green && a[2][1][2].color[5] == white) && (a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
						Rotate(2, 3);
					}
					if ((a[2][1][2].color[0] == green && a[2][1][2].color[5] == white) && (a[2][0][1].color[5] == red && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
						Rotate(1, 3);
					}
					if ((a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white) && (a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
						Rotate(2, 3);
					}
					if ((a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white) && (a[2][0][1].color[5] == red && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
						Rotate(1, 3);
					}
					if ((a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white) && (a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
						Rotate(2, 3);
					}
					if ((a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white) && (a[2][0][1].color[5] == green && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
						Rotate(1, 3);
					}
				}
				if (a[0][1][2].color[0] == white && a[0][1][2].color[4] == green) {
					if ((a[2][1][2].color[0] == red && a[2][1][2].color[5] == white) && (a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
						Rotate(2, 3);
					}
					if ((a[2][1][2].color[0] == red && a[2][1][2].color[5] == white) && (a[2][0][1].color[5] == orange && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
						Rotate(1, 3);
					}
					if ((a[2][1][2].color[0] == red && a[2][1][2].color[5] == white) && (a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
						Rotate(2, 3);
					}
					if ((a[2][1][2].color[0] == red && a[2][1][2].color[5] == white) && (a[2][0][1].color[5] == blue && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
						Rotate(1, 3);
					}
					if ((a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white) && (a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
						Rotate(2, 3);
					}
					if ((a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white) && (a[2][0][1].color[5] == orange && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
						Rotate(1, 3);
					}
					if ((a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white) && (a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
						Rotate(2, 3);
					}
					if ((a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white) && (a[2][0][1].color[5] == red && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
						Rotate(1, 3);
					}
					if ((a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white) && (a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
						Rotate(2, 3);
					}
					if ((a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white) && (a[2][0][1].color[5] == red && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
						Rotate(1, 3);
					}
					if ((a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white) && (a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
						Rotate(2, 3);
					}
					if ((a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white) && (a[2][0][1].color[5] == blue && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
						Rotate(1, 3);
					}
				}
				if (a[0][1][2].color[0] == white && a[0][1][2].color[4] == red) {
					if ((a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white) && (a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
						Rotate(2, 3);
					}
					if ((a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white) && (a[2][0][1].color[5] == orange && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
						Rotate(1, 3);
					}
					if ((a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white) && (a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
						Rotate(2, 3);
					}
					if ((a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white) && (a[2][0][1].color[5] == green && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
						Rotate(1, 3);
					}
					if ((a[2][1][2].color[0] == green && a[2][1][2].color[5] == white) && (a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
						Rotate(2, 3);
					}
					if ((a[2][1][2].color[0] == green && a[2][1][2].color[5] == white) && (a[2][0][1].color[5] == orange && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
						Rotate(1, 3);
					}
					if ((a[2][1][2].color[0] == green && a[2][1][2].color[5] == white) && (a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
						Rotate(2, 3);
					}
					if ((a[2][1][2].color[0] == green && a[2][1][2].color[5] == white) && (a[2][0][1].color[5] == blue && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
						Rotate(1, 3);
					}
					if ((a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white) && (a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
						Rotate(2, 3);
					}
					if ((a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white) && (a[2][0][1].color[5] == blue && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
						Rotate(1, 3);
					}
					if ((a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white) && (a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
						Rotate(2, 3);
					}
					if ((a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white) && (a[2][0][1].color[5] == green && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
						Rotate(1, 3);
					}
				}
			}
			//белая нижняя
			if (a[0][1][2].color[0] != white && a[1][0][2].color[0] == white && a[2][1][2].color[0] != white && a[1][2][2].color[0] != white) {
				if (a[1][0][2].color[0] == white && a[1][0][2].color[2] == orange) {
					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white) && (a[2][0][1].color[5] == blue && a[2][0][1].color[2] == white)) {
						Rotate(5, -3);
					}
					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white) && (a[2][0][1].color[5] == red && a[2][0][1].color[2] == white)) {
						Rotate(5, -3);
					}
					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white) && (a[2][0][1].color[5] == green && a[2][0][1].color[2] == white)) {
						Rotate(5, -3);
					}
					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white) && (a[2][0][1].color[5] == red && a[2][0][1].color[2] == white)) {
						Rotate(5, -3);
					}
					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white) && (a[2][0][1].color[5] == blue && a[2][0][1].color[2] == white)) {
						Rotate(5, -3);
					}
					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white) && (a[2][0][1].color[5] == green && a[2][0][1].color[2] == white)) {
						Rotate(5, -3);
					}
					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
				}
				if (a[1][0][2].color[0] == white && a[1][0][2].color[2] == blue) {
					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white) && (a[2][0][1].color[5] == orange && a[2][0][1].color[2] == white)) {
						Rotate(5, -3);
					}
					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white) && (a[2][0][1].color[5] == red && a[2][0][1].color[2] == white)) {
						Rotate(5, -3);
					}
					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white) && (a[2][0][1].color[5] == green && a[2][0][1].color[2] == white)) {
						Rotate(5, -3);
					}
					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white) && (a[2][0][1].color[5] == red && a[2][0][1].color[2] == white)) {
						Rotate(5, -3);
					}
					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white) && (a[2][0][1].color[5] == orange && a[2][0][1].color[2] == white)) {
						Rotate(5, -3);
					}
					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white) && (a[2][0][1].color[5] == green && a[2][0][1].color[2] == white)) {
						Rotate(5, -3);
					}
					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
				}
				if (a[1][0][2].color[0] == white && a[1][0][2].color[2] == green) {
					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white) && (a[2][0][1].color[5] == orange && a[2][0][1].color[2] == white)) {
						Rotate(5, -3);
					}
					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white) && (a[2][0][1].color[5] == red && a[2][0][1].color[2] == white)) {
						Rotate(5, -3);
					}
					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white) && (a[2][0][1].color[5] == blue && a[2][0][1].color[2] == white)) {
						Rotate(5, -3);
					}
					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white) && (a[2][0][1].color[5] == red && a[2][0][1].color[2] == white)) {
						Rotate(5, -3);
					}
					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white) && (a[2][0][1].color[5] == orange && a[2][0][1].color[2] == white)) {
						Rotate(5, -3);
					}
					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white) && (a[2][0][1].color[5] == blue && a[2][0][1].color[2] == white)) {
						Rotate(5, -3);
					}
					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
				}
				if (a[1][0][2].color[0] == white && a[1][0][2].color[2] == red) {
					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white) && (a[2][0][1].color[5] == orange && a[2][0][1].color[2] == white)) {
						Rotate(5, -3);
					}
					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white) && (a[2][0][1].color[5] == green && a[2][0][1].color[2] == white)) {
						Rotate(5, -3);
					}
					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white) && (a[2][0][1].color[5] == blue && a[2][0][1].color[2] == white)) {
						Rotate(5, -3);
					}
					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white) && (a[2][0][1].color[5] == green && a[2][0][1].color[2] == white)) {
						Rotate(5, -3);
					}
					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white) && (a[2][0][1].color[5] == orange && a[2][0][1].color[2] == white)) {
						Rotate(5, -3);
					}
					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white) && (a[2][0][1].color[5] == blue && a[2][0][1].color[2] == white)) {
						Rotate(5, -3);
					}
					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white)) {
						Rotate(1, -3);
					}
				}
			}
			//собрано 0 наверху, но есть 4 белых
			if (a[0][1][2].color[4] == white && a[1][0][2].color[2] == white && a[2][1][2].color[5] == white && a[1][2][2].color[3] == white) {
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[2][1][2].color[0] == orange && a[1][2][2].color[0] == green) {
					Rotate(2, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[2][1][2].color[0] == blue && a[1][2][2].color[0] == green) {
					Rotate(2, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[2][1][2].color[0] == orange && a[1][2][2].color[0] == blue) {
					Rotate(2, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[2][1][2].color[0] == green && a[1][2][2].color[0] == blue) {
					Rotate(2, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[2][1][2].color[0] == green && a[1][2][2].color[0] == orange) {
					Rotate(2, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[2][1][2].color[0] == blue && a[1][2][2].color[0] == orange) {
					Rotate(2, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[2][1][2].color[0] == orange && a[1][2][2].color[0] == green) {
					Rotate(2, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[2][1][2].color[0] == red && a[1][2][2].color[0] == green) {
					Rotate(2, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[2][1][2].color[0] == orange && a[1][2][2].color[0] == red) {
					Rotate(2, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[2][1][2].color[0] == green && a[1][2][2].color[0] == red) {
					Rotate(2, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[2][1][2].color[0] == green && a[1][2][2].color[0] == orange) {
					Rotate(2, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[2][1][2].color[0] == red && a[1][2][2].color[0] == orange) {
					Rotate(2, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[2][1][2].color[0] == orange && a[1][2][2].color[0] == red) {
					Rotate(2, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[2][1][2].color[0] == blue && a[1][2][2].color[0] == red) {
					Rotate(2, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[2][1][2].color[0] == orange && a[1][2][2].color[0] == blue) {
					Rotate(2, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[2][1][2].color[0] == red && a[1][2][2].color[0] == blue) {
					Rotate(2, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[2][1][2].color[0] == red && a[1][2][2].color[0] == orange) {
					Rotate(2, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[2][1][2].color[0] == blue && a[1][2][2].color[0] == orange) {
					Rotate(2, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[2][1][2].color[0] == red && a[1][2][2].color[0] == green) {
					Rotate(2, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[2][1][2].color[0] == blue && a[1][2][2].color[0] == green) {
					Rotate(2, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[2][1][2].color[0] == red && a[1][2][2].color[0] == blue) {
					Rotate(2, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[2][1][2].color[0] == green && a[1][2][2].color[0] == blue) {
					Rotate(2, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[2][1][2].color[0] == green && a[1][2][2].color[0] == red) {
					Rotate(2, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[2][1][2].color[0] == blue && a[1][2][2].color[0] == red) {
					Rotate(2, 3);
				}
			}
			//собрано 0 наверху, но есть 3 белых кроме нижнего
			if (a[0][1][2].color[4] == white && a[2][1][2].color[5] == white && a[2][0][1].color[2] == white && a[1][2][2].color[3] == white) {
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == green && a[2][1][2].color[0] == orange && a[2][0][1].color[5] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == green && a[2][0][1].color[5] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == red && a[2][1][2].color[0] == orange && a[2][0][1].color[5] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == red && a[2][0][1].color[5] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == green && a[2][1][2].color[0] == red && a[2][0][1].color[5] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == red && a[2][1][2].color[0] == green && a[2][0][1].color[5] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == green && a[2][1][2].color[0] == blue && a[2][0][1].color[5] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == green && a[2][0][1].color[5] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == red && a[2][1][2].color[0] == blue && a[2][0][1].color[5] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == red && a[2][0][1].color[5] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == green && a[2][1][2].color[0] == red && a[2][0][1].color[5] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == red && a[2][1][2].color[0] == green && a[2][0][1].color[5] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == orange && a[2][0][1].color[5] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == blue && a[2][0][1].color[5] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == red && a[2][1][2].color[0] == orange && a[2][0][1].color[5] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == red && a[2][0][1].color[5] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == red && a[2][0][1].color[5] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == red && a[2][1][2].color[0] == blue && a[2][0][1].color[5] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == green && a[2][1][2].color[0] == orange && a[2][0][1].color[5] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == green && a[2][0][1].color[5] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == orange && a[2][0][1].color[5] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == blue && a[2][0][1].color[5] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == green && a[2][1][2].color[0] == blue && a[2][0][1].color[5] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == green && a[2][0][1].color[5] == red) {
					Rotate(1, 3);
				}
			}
			if (a[0][1][2].color[4] == white && a[2][1][2].color[5] == white && a[2][0][1].color[5] == white && a[1][2][2].color[3] == white) {
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == green && a[2][1][2].color[0] == orange && a[2][0][1].color[2] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == green && a[2][0][1].color[2] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == red && a[2][1][2].color[0] == orange && a[2][0][1].color[2] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == red && a[2][0][1].color[2] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == green && a[2][1][2].color[0] == red && a[2][0][1].color[2] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == red && a[2][1][2].color[0] == green && a[2][0][1].color[2] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == green && a[2][1][2].color[0] == blue && a[2][0][1].color[2] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == green && a[2][0][1].color[2] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == red && a[2][1][2].color[0] == blue && a[2][0][1].color[2] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == red && a[2][0][1].color[2] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == green && a[2][1][2].color[0] == red && a[2][0][1].color[2] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == red && a[2][1][2].color[0] == green && a[2][0][1].color[2] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == orange && a[2][0][1].color[2] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == blue && a[2][0][1].color[2] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == red && a[2][1][2].color[0] == orange && a[2][0][1].color[2] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == red && a[2][0][1].color[2] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == red && a[2][0][1].color[2] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == red && a[2][1][2].color[0] == blue && a[2][0][1].color[2] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == green && a[2][1][2].color[0] == orange && a[2][0][1].color[2] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == green && a[2][0][1].color[2] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == orange && a[2][0][1].color[2] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == blue && a[2][0][1].color[2] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == green && a[2][1][2].color[0] == blue && a[2][0][1].color[2] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == green && a[2][0][1].color[2] == red) {
					Rotate(1, 3);
				}
			}
			if (a[0][1][2].color[4] == white && a[2][1][2].color[5] == white && a[1][0][0].color[2] == white && a[1][2][2].color[3] == white) {
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == green && a[2][1][2].color[0] == orange && a[1][0][0].color[1] == blue) {
					Rotate(2, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == green && a[1][0][0].color[1] == blue) {
					Rotate(2, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == red && a[2][1][2].color[0] == orange && a[1][0][0].color[1] == blue) {
					Rotate(2, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == red && a[1][0][0].color[1] == blue) {
					Rotate(2, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == green && a[2][1][2].color[0] == red && a[1][0][0].color[1] == blue) {
					Rotate(2, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == red && a[2][1][2].color[0] == green && a[1][0][0].color[1] == blue) {
					Rotate(2, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == green && a[2][1][2].color[0] == blue && a[1][0][0].color[1] == orange) {
					Rotate(2, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == green && a[1][0][0].color[1] == orange) {
					Rotate(2, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == red && a[2][1][2].color[0] == blue && a[1][0][0].color[1] == orange) {
					Rotate(2, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == red && a[1][0][0].color[1] == orange) {
					Rotate(2, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == green && a[2][1][2].color[0] == red && a[1][0][0].color[1] == orange) {
					Rotate(2, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == red && a[2][1][2].color[0] == green && a[1][0][0].color[1] == orange) {
					Rotate(2, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == orange && a[1][0][0].color[1] == green) {
					Rotate(2, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == blue && a[1][0][0].color[1] == green) {
					Rotate(2, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == red && a[2][1][2].color[0] == orange && a[1][0][0].color[1] == green) {
					Rotate(2, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == red && a[1][0][0].color[1] == green) {
					Rotate(2, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == red && a[1][0][0].color[1] == green) {
					Rotate(2, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == red && a[2][1][2].color[0] == blue && a[1][0][0].color[1] == green) {
					Rotate(2, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == green && a[2][1][2].color[0] == orange && a[1][0][0].color[1] == red) {
					Rotate(2, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == green && a[1][0][0].color[1] == red) {
					Rotate(2, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == orange && a[1][0][0].color[1] == red) {
					Rotate(2, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == blue && a[1][0][0].color[1] == red) {
					Rotate(2, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == green && a[2][1][2].color[0] == blue && a[1][0][0].color[1] == red) {
					Rotate(2, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == green && a[1][0][0].color[1] == red) {
					Rotate(2, 3);
				}
			}
			if (a[0][1][2].color[4] == white && a[2][1][2].color[5] == white && a[1][0][0].color[1] == white && a[1][2][2].color[3] == white) {
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == green && a[2][1][2].color[0] == orange && a[1][0][0].color[2] == blue) {
					Rotate(2, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == green && a[1][0][0].color[2] == blue) {
					Rotate(2, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == red && a[2][1][2].color[0] == orange && a[1][0][0].color[2] == blue) {
					Rotate(2, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == red && a[1][0][0].color[2] == blue) {
					Rotate(2, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == green && a[2][1][2].color[0] == red && a[1][0][0].color[2] == blue) {
					Rotate(2, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == red && a[2][1][2].color[0] == green && a[1][0][0].color[2] == blue) {
					Rotate(2, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == green && a[2][1][2].color[0] == blue && a[1][0][0].color[2] == orange) {
					Rotate(2, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == green && a[1][0][0].color[2] == orange) {
					Rotate(2, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == red && a[2][1][2].color[0] == blue && a[1][0][0].color[2] == orange) {
					Rotate(2, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == red && a[1][0][0].color[2] == orange) {
					Rotate(2, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == green && a[2][1][2].color[0] == red && a[1][0][0].color[2] == orange) {
					Rotate(2, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == red && a[2][1][2].color[0] == green && a[1][0][0].color[2] == orange) {
					Rotate(2, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == orange && a[1][0][0].color[2] == green) {
					Rotate(2, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == blue && a[1][0][0].color[2] == green) {
					Rotate(2, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == red && a[2][1][2].color[0] == orange && a[1][0][0].color[2] == green) {
					Rotate(2, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == red && a[1][0][0].color[2] == green) {
					Rotate(2, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == red && a[1][0][0].color[2] == green) {
					Rotate(2, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == red && a[2][1][2].color[0] == blue && a[1][0][0].color[2] == green) {
					Rotate(2, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == green && a[2][1][2].color[0] == orange && a[1][0][0].color[2] == red) {
					Rotate(2, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == green && a[1][0][0].color[2] == red) {
					Rotate(2, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == orange && a[1][0][0].color[2] == red) {
					Rotate(2, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == blue && a[1][0][0].color[2] == red) {
					Rotate(2, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == green && a[2][1][2].color[0] == blue && a[1][0][0].color[2] == red) {
					Rotate(2, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == green && a[1][0][0].color[2] == red) {
					Rotate(2, 3);
				}
			}
			if (a[0][1][2].color[4] == white && a[2][1][2].color[5] == white && a[0][0][1].color[2] == white && a[1][2][2].color[3] == white) {
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == green && a[2][1][2].color[0] == orange && a[0][0][1].color[4] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == green && a[0][0][1].color[4] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == red && a[2][1][2].color[0] == orange && a[0][0][1].color[4] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == red && a[0][0][1].color[4] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == green && a[2][1][2].color[0] == red && a[0][0][1].color[4] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == red && a[2][1][2].color[0] == green && a[0][0][1].color[4] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == green && a[2][1][2].color[0] == blue && a[0][0][1].color[4] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == green && a[0][0][1].color[4] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == red && a[2][1][2].color[0] == blue && a[0][0][1].color[4] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == red && a[0][0][1].color[4] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == green && a[2][1][2].color[0] == red && a[0][0][1].color[4] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == red && a[2][1][2].color[0] == green && a[0][0][1].color[4] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == orange && a[0][0][1].color[4] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == blue && a[0][0][1].color[4] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == red && a[2][1][2].color[0] == orange && a[0][0][1].color[4] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == red && a[0][0][1].color[4] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == red && a[0][0][1].color[4] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == red && a[2][1][2].color[0] == blue && a[0][0][1].color[4] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == green && a[2][1][2].color[0] == orange && a[0][0][1].color[4] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == green && a[0][0][1].color[4] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == orange && a[0][0][1].color[4] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == blue && a[0][0][1].color[4] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == green && a[2][1][2].color[0] == blue && a[0][0][1].color[4] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == green && a[0][0][1].color[4] == red) {
					Rotate(1, -3);
				}
			}
			if (a[0][1][2].color[4] == white && a[2][1][2].color[5] == white && a[0][0][1].color[4] == white && a[1][2][2].color[3] == white) {
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == green && a[2][1][2].color[0] == orange && a[0][0][1].color[2] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == green && a[0][0][1].color[2] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == red && a[2][1][2].color[0] == orange && a[0][0][1].color[2] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == red && a[0][0][1].color[2] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == green && a[2][1][2].color[0] == red && a[0][0][1].color[2] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == red && a[2][1][2].color[0] == green && a[0][0][1].color[2] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == green && a[2][1][2].color[0] == blue && a[0][0][1].color[2] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == green && a[0][0][1].color[2] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == red && a[2][1][2].color[0] == blue && a[0][0][1].color[2] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == red && a[0][0][1].color[2] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == green && a[2][1][2].color[0] == red && a[0][0][1].color[2] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == red && a[2][1][2].color[0] == green && a[0][0][1].color[2] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == orange && a[0][0][1].color[2] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == blue && a[0][0][1].color[2] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == red && a[2][1][2].color[0] == orange && a[0][0][1].color[2] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == red && a[0][0][1].color[2] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == red && a[0][0][1].color[2] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == red && a[2][1][2].color[0] == blue && a[0][0][1].color[2] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == green && a[2][1][2].color[0] == orange && a[0][0][1].color[2] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == green && a[0][0][1].color[2] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == orange && a[0][0][1].color[2] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == blue && a[0][0][1].color[2] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == green && a[2][1][2].color[0] == blue && a[0][0][1].color[2] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == green && a[0][0][1].color[2] == red) {
					Rotate(1, -3);
				}
			}
			if (a[0][1][2].color[4] == white && a[2][1][2].color[5] == white && a[2][2][1].color[3] == white && a[1][2][2].color[3] == white) {
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == green && a[2][1][2].color[0] == orange && a[2][2][1].color[5] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == green && a[2][2][1].color[5] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == red && a[2][1][2].color[0] == orange && a[2][2][1].color[5] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == red && a[2][2][1].color[5] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == green && a[2][1][2].color[0] == red && a[2][2][1].color[5] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == red && a[2][1][2].color[0] == green && a[2][2][1].color[5] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == green && a[2][1][2].color[0] == blue && a[2][2][1].color[5] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == green && a[2][2][1].color[5] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == red && a[2][1][2].color[0] == blue && a[2][2][1].color[5] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == red && a[2][2][1].color[5] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == green && a[2][1][2].color[0] == red && a[2][2][1].color[5] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == red && a[2][1][2].color[0] == green && a[2][2][1].color[5] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == orange && a[2][2][1].color[5] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == blue && a[2][2][1].color[5] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == red && a[2][1][2].color[0] == orange && a[2][2][1].color[5] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == red && a[2][2][1].color[5] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == red && a[2][2][1].color[5] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == red && a[2][1][2].color[0] == blue && a[2][2][1].color[5] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == green && a[2][1][2].color[0] == orange && a[2][2][1].color[5] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == green && a[2][2][1].color[5] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == orange && a[2][2][1].color[5] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == blue && a[2][2][1].color[5] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == green && a[2][1][2].color[0] == blue && a[2][2][1].color[5] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == green && a[2][2][1].color[5] == red) {
					Rotate(1, 3);
				}
			}
			if (a[0][1][2].color[4] == white && a[2][1][2].color[5] == white && a[2][2][1].color[5] == white && a[1][2][2].color[3] == white) {
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == green && a[2][1][2].color[0] == orange && a[2][2][1].color[3] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == green && a[2][2][1].color[3] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == red && a[2][1][2].color[0] == orange && a[2][2][1].color[3] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == red && a[2][2][1].color[3] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == green && a[2][1][2].color[0] == red && a[2][2][1].color[3] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == red && a[2][1][2].color[0] == green && a[2][2][1].color[3] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == green && a[2][1][2].color[0] == blue && a[2][2][1].color[3] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == green && a[2][2][1].color[3] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == red && a[2][1][2].color[0] == blue && a[2][2][1].color[3] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == red && a[2][2][1].color[3] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == green && a[2][1][2].color[0] == red && a[2][2][1].color[3] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == red && a[2][1][2].color[0] == green && a[2][2][1].color[3] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == orange && a[2][2][1].color[3] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == blue && a[2][2][1].color[3] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == red && a[2][1][2].color[0] == orange && a[2][2][1].color[3] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == red && a[2][2][1].color[3] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == red && a[2][2][1].color[3] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == red && a[2][1][2].color[0] == blue && a[2][2][1].color[3] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == green && a[2][1][2].color[0] == orange && a[2][2][1].color[3] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == green && a[2][2][1].color[3] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == orange && a[2][2][1].color[3] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == blue && a[2][2][1].color[3] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == green && a[2][1][2].color[0] == blue && a[2][2][1].color[3] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == green && a[2][2][1].color[3] == red) {
					Rotate(1, 3);
				}
			}
			if (a[0][1][2].color[4] == white && a[2][1][2].color[5] == white && a[1][2][0].color[3] == white && a[1][2][2].color[3] == white) {
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == green && a[2][1][2].color[0] == orange && a[1][2][0].color[1] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == green && a[1][2][0].color[1] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == red && a[2][1][2].color[0] == orange && a[1][2][0].color[1] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == red && a[1][2][0].color[1] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == green && a[2][1][2].color[0] == red && a[1][2][0].color[1] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == red && a[2][1][2].color[0] == green && a[1][2][0].color[1] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == green && a[2][1][2].color[0] == blue && a[1][2][0].color[1] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == green && a[1][2][0].color[1] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == red && a[2][1][2].color[0] == blue && a[1][2][0].color[1] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == red && a[1][2][0].color[1] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == green && a[2][1][2].color[0] == red && a[1][2][0].color[1] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == red && a[2][1][2].color[0] == green && a[1][2][0].color[1] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == orange && a[1][2][0].color[1] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == blue && a[1][2][0].color[1] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == red && a[2][1][2].color[0] == orange && a[1][2][0].color[1] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == red && a[1][2][0].color[1] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == red && a[1][2][0].color[1] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == red && a[2][1][2].color[0] == blue && a[1][2][0].color[1] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == green && a[2][1][2].color[0] == orange && a[1][2][0].color[1] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == green && a[1][2][0].color[1] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == orange && a[1][2][0].color[1] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == blue && a[1][2][0].color[1] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == green && a[2][1][2].color[0] == blue && a[1][2][0].color[1] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == green && a[1][2][0].color[1] == red) {
					Rotate(1, 3);
				}
			}
			if (a[0][1][2].color[4] == white && a[2][1][2].color[5] == white && a[1][2][0].color[1] == white && a[1][2][2].color[3] == white) {
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == green && a[2][1][2].color[0] == orange && a[1][2][0].color[3] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == green && a[1][2][0].color[3] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == red && a[2][1][2].color[0] == orange && a[1][2][0].color[3] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == red && a[1][2][0].color[3] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == green && a[2][1][2].color[0] == red && a[1][2][0].color[3] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == red && a[2][1][2].color[0] == green && a[1][2][0].color[3] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == green && a[2][1][2].color[0] == blue && a[1][2][0].color[3] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == green && a[1][2][0].color[3] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == red && a[2][1][2].color[0] == blue && a[1][2][0].color[3] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == red && a[1][2][0].color[3] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == green && a[2][1][2].color[0] == red && a[1][2][0].color[3] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == red && a[2][1][2].color[0] == green && a[1][2][0].color[3] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == orange && a[1][2][0].color[3] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == blue && a[1][2][0].color[3] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == red && a[2][1][2].color[0] == orange && a[1][2][0].color[3] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == red && a[1][2][0].color[3] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == red && a[1][2][0].color[3] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == red && a[2][1][2].color[0] == blue && a[1][2][0].color[3] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == green && a[2][1][2].color[0] == orange && a[1][2][0].color[3] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == green && a[1][2][0].color[3] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == orange && a[1][2][0].color[3] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == blue && a[1][2][0].color[3] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == green && a[2][1][2].color[0] == blue && a[1][2][0].color[3] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == green && a[1][2][0].color[3] == red) {
					Rotate(1, 3);
				}
			}
			if (a[0][1][2].color[4] == white && a[2][1][2].color[5] == white && a[0][2][1].color[3] == white && a[1][2][2].color[3] == white) {
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == green && a[2][1][2].color[0] == orange && a[0][2][1].color[4] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == green && a[0][2][1].color[4] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == red && a[2][1][2].color[0] == orange && a[0][2][1].color[4] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == red && a[0][2][1].color[4] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == green && a[2][1][2].color[0] == red && a[0][2][1].color[4] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == red && a[2][1][2].color[0] == green && a[0][2][1].color[4] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == green && a[2][1][2].color[0] == blue && a[0][2][1].color[4] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == green && a[0][2][1].color[4] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == red && a[2][1][2].color[0] == blue && a[0][2][1].color[4] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == red && a[0][2][1].color[4] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == green && a[2][1][2].color[0] == red && a[0][2][1].color[4] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == red && a[2][1][2].color[0] == green && a[0][2][1].color[4] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == orange && a[0][2][1].color[4] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == blue && a[0][2][1].color[4] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == red && a[2][1][2].color[0] == orange && a[0][2][1].color[4] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == red && a[0][2][1].color[4] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == red && a[0][2][1].color[4] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == red && a[2][1][2].color[0] == blue && a[0][2][1].color[4] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == green && a[2][1][2].color[0] == orange && a[0][2][1].color[4] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == green && a[0][2][1].color[4] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == orange && a[0][2][1].color[4] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == blue && a[0][2][1].color[4] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == green && a[2][1][2].color[0] == blue && a[0][2][1].color[4] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == green && a[0][2][1].color[4] == red) {
					Rotate(1, -3);
				}
			}
			if (a[0][1][2].color[4] == white && a[2][1][2].color[5] == white && a[0][2][1].color[4] == white && a[1][2][2].color[3] == white) {
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == green && a[2][1][2].color[0] == orange && a[0][2][1].color[3] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == green && a[0][2][1].color[3] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == red && a[2][1][2].color[0] == orange && a[0][2][1].color[3] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == red && a[0][2][1].color[3] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == green && a[2][1][2].color[0] == red && a[0][2][1].color[3] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == red && a[2][1][2].color[0] == green && a[0][2][1].color[3] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == green && a[2][1][2].color[0] == blue && a[0][2][1].color[3] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == green && a[0][2][1].color[3] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == red && a[2][1][2].color[0] == blue && a[0][2][1].color[3] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == red && a[0][2][1].color[3] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == green && a[2][1][2].color[0] == red && a[0][2][1].color[3] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == red && a[2][1][2].color[0] == green && a[0][2][1].color[3] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == orange && a[0][2][1].color[3] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == blue && a[0][2][1].color[3] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == red && a[2][1][2].color[0] == orange && a[0][2][1].color[3] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == red && a[0][2][1].color[3] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == red && a[0][2][1].color[3] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == red && a[2][1][2].color[0] == blue && a[0][2][1].color[3] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == green && a[2][1][2].color[0] == orange && a[0][2][1].color[3] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == green && a[0][2][1].color[3] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == orange && a[0][2][1].color[3] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == blue && a[0][2][1].color[3] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == green && a[2][1][2].color[0] == blue && a[0][2][1].color[3] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == green && a[0][2][1].color[3] == red) {
					Rotate(1, -3);
				}
			}
			if (a[0][1][2].color[4] == white && a[2][1][2].color[5] == white && a[0][1][0].color[4] == white && a[1][2][2].color[3] == white) {
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == green && a[2][1][2].color[0] == orange && a[0][1][0].color[1] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == green && a[0][1][0].color[1] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == red && a[2][1][2].color[0] == orange && a[0][1][0].color[1] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == red && a[0][1][0].color[1] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == green && a[2][1][2].color[0] == red && a[0][1][0].color[1] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == red && a[2][1][2].color[0] == green && a[0][1][0].color[1] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == green && a[2][1][2].color[0] == blue && a[0][1][0].color[1] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == green && a[0][1][0].color[1] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == red && a[2][1][2].color[0] == blue && a[0][1][0].color[1] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == red && a[0][1][0].color[1] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == green && a[2][1][2].color[0] == red && a[0][1][0].color[1] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == red && a[2][1][2].color[0] == green && a[0][1][0].color[1] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == orange && a[0][1][0].color[1] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == blue && a[0][1][0].color[1] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == red && a[2][1][2].color[0] == orange && a[0][1][0].color[1] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == red && a[0][1][0].color[1] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == red && a[0][1][0].color[1] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == red && a[2][1][2].color[0] == blue && a[0][1][0].color[1] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == green && a[2][1][2].color[0] == orange && a[0][1][0].color[1] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == green && a[0][1][0].color[1] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == orange && a[0][1][0].color[1] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == blue && a[0][1][0].color[1] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == green && a[2][1][2].color[0] == blue && a[0][1][0].color[1] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == green && a[0][1][0].color[1] == red) {
					Rotate(1, -3);
				}
			}
			if (a[0][1][2].color[4] == white && a[2][1][2].color[5] == white && a[0][1][0].color[1] == white && a[1][2][2].color[3] == white) {
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == green && a[2][1][2].color[0] == orange && a[0][1][0].color[4] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == green && a[0][1][0].color[4] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == red && a[2][1][2].color[0] == orange && a[0][1][0].color[4] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == red && a[0][1][0].color[4] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == green && a[2][1][2].color[0] == red && a[0][1][0].color[4] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == red && a[2][1][2].color[0] == green && a[0][1][0].color[4] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == green && a[2][1][2].color[0] == blue && a[0][1][0].color[4] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == green && a[0][1][0].color[4] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == red && a[2][1][2].color[0] == blue && a[0][1][0].color[4] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == red && a[0][1][0].color[4] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == green && a[2][1][2].color[0] == red && a[0][1][0].color[4] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == red && a[2][1][2].color[0] == green && a[0][1][0].color[4] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == orange && a[0][1][0].color[4] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == blue && a[0][1][0].color[4] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == red && a[2][1][2].color[0] == orange && a[0][1][0].color[4] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == red && a[0][1][0].color[4] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == red && a[0][1][0].color[4] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == red && a[2][1][2].color[0] == blue && a[0][1][0].color[4] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == green && a[2][1][2].color[0] == orange && a[0][1][0].color[4] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == green && a[0][1][0].color[4] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == orange && a[0][1][0].color[4] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == blue && a[0][1][0].color[4] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == green && a[2][1][2].color[0] == blue && a[0][1][0].color[4] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == green && a[0][1][0].color[4] == red) {
					Rotate(1, -3);
				}
			}
			if (a[0][1][2].color[4] == white && a[2][1][2].color[5] == white && a[2][1][0].color[5] == white && a[1][2][2].color[3] == white) {
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == green && a[2][1][2].color[0] == orange && a[2][1][0].color[1] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == green && a[2][1][0].color[1] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == red && a[2][1][2].color[0] == orange && a[2][1][0].color[1] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == red && a[2][1][0].color[1] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == green && a[2][1][2].color[0] == red && a[2][1][0].color[1] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == red && a[2][1][2].color[0] == green && a[2][1][0].color[1] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == green && a[2][1][2].color[0] == blue && a[2][1][0].color[1] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == green && a[2][1][0].color[1] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == red && a[2][1][2].color[0] == blue && a[2][1][0].color[1] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == red && a[2][1][0].color[1] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == green && a[2][1][2].color[0] == red && a[2][1][0].color[1] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == red && a[2][1][2].color[0] == green && a[2][1][0].color[1] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == orange && a[2][1][0].color[1] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == blue && a[2][1][0].color[1] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == red && a[2][1][2].color[0] == orange && a[2][1][0].color[1] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == red && a[2][1][0].color[1] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == red && a[2][1][0].color[1] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == red && a[2][1][2].color[0] == blue && a[2][1][0].color[1] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == green && a[2][1][2].color[0] == orange && a[2][1][0].color[1] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == green && a[2][1][0].color[1] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == orange && a[2][1][0].color[1] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == blue && a[2][1][0].color[1] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == green && a[2][1][2].color[0] == blue && a[2][1][0].color[1] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == green && a[2][1][0].color[1] == red) {
					Rotate(1, 3);
				}
			}
			if (a[0][1][2].color[4] == white && a[2][1][2].color[5] == white && a[2][1][0].color[1] == white && a[1][2][2].color[3] == white) {
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == green && a[2][1][2].color[0] == orange && a[2][1][0].color[5] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == green && a[2][1][0].color[5] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == red && a[2][1][2].color[0] == orange && a[2][1][0].color[5] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == red && a[2][1][0].color[5] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == green && a[2][1][2].color[0] == red && a[2][1][0].color[5] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == red && a[2][1][2].color[0] == green && a[2][1][0].color[5] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == green && a[2][1][2].color[0] == blue && a[2][1][0].color[5] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == green && a[2][1][0].color[5] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == red && a[2][1][2].color[0] == blue && a[2][1][0].color[5] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == red && a[2][1][0].color[5] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == green && a[2][1][2].color[0] == red && a[2][1][0].color[5] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == red && a[2][1][2].color[0] == green && a[2][1][0].color[5] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == orange && a[2][1][0].color[5] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == blue && a[2][1][0].color[5] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == red && a[2][1][2].color[0] == orange && a[2][1][0].color[5] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == red && a[2][1][0].color[5] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == red && a[2][1][0].color[5] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == red && a[2][1][2].color[0] == blue && a[2][1][0].color[5] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == green && a[2][1][2].color[0] == orange && a[2][1][0].color[5] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == green && a[2][1][0].color[5] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == orange && a[2][1][0].color[5] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == blue && a[2][1][0].color[5] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == green && a[2][1][2].color[0] == blue && a[2][1][0].color[5] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == green && a[2][1][0].color[5] == red) {
					Rotate(1, 3);
				}
			}
			//собрано 0 наверху, но есть 3 белых кроме правого 
			if (a[0][1][2].color[4] == white && a[1][0][2].color[2] == white && a[2][0][1].color[2] == white && a[1][2][2].color[3] == white) {
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[2][0][1].color[5] == blue && a[1][2][2].color[0] == orange) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[2][0][1].color[5] == blue && a[1][2][2].color[0] == red) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[2][0][1].color[5] == blue && a[1][2][2].color[0] == green) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[2][0][1].color[5] == blue && a[1][2][2].color[0] == red) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[2][0][1].color[5] == blue && a[1][2][2].color[0] == orange) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[2][0][1].color[5] == blue && a[1][2][2].color[0] == green) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[2][0][1].color[5] == red && a[1][2][2].color[0] == orange) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[2][0][1].color[5] == red && a[1][2][2].color[0] == blue) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[2][0][1].color[5] == red && a[1][2][2].color[0] == green) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[2][0][1].color[5] == red && a[1][2][2].color[0] == blue) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[2][0][1].color[5] == red && a[1][2][2].color[0] == orange) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[2][0][1].color[5] == red && a[1][2][2].color[0] == green) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[2][0][1].color[5] == orange && a[1][2][2].color[0] == red) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[2][0][1].color[5] == orange && a[1][2][2].color[0] == blue) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[2][0][1].color[5] == orange && a[1][2][2].color[0] == green) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[2][0][1].color[5] == orange && a[1][2][2].color[0] == blue) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[2][0][1].color[5] == orange && a[1][2][2].color[0] == red) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[2][0][1].color[5] == orange && a[1][2][2].color[0] == green) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[2][0][1].color[5] == green && a[1][2][2].color[0] == orange) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[2][0][1].color[5] == green && a[1][2][2].color[0] == blue) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[2][0][1].color[5] == green && a[1][2][2].color[0] == red) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[2][0][1].color[5] == green && a[1][2][2].color[0] == blue) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[2][0][1].color[5] == green && a[1][2][2].color[0] == orange) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[2][0][1].color[5] == green && a[1][2][2].color[0] == red) {
					Rotate(5, -3);
				}
			}
			if (a[0][1][2].color[4] == white && a[1][0][2].color[2] == white && a[2][0][1].color[5] == white && a[1][2][2].color[3] == white) {
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[2][0][1].color[2] == blue && a[1][2][2].color[0] == orange) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[2][0][1].color[2] == blue && a[1][2][2].color[0] == red) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[2][0][1].color[2] == blue && a[1][2][2].color[0] == green) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[2][0][1].color[2] == blue && a[1][2][2].color[0] == red) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[2][0][1].color[2] == blue && a[1][2][2].color[0] == orange) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[2][0][1].color[2] == blue && a[1][2][2].color[0] == green) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[2][0][1].color[2] == red && a[1][2][2].color[0] == orange) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[2][0][1].color[2] == red && a[1][2][2].color[0] == blue) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[2][0][1].color[2] == red && a[1][2][2].color[0] == green) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[2][0][1].color[2] == red && a[1][2][2].color[0] == blue) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[2][0][1].color[2] == red && a[1][2][2].color[0] == orange) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[2][0][1].color[2] == red && a[1][2][2].color[0] == green) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[2][0][1].color[2] == orange && a[1][2][2].color[0] == red) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[2][0][1].color[2] == orange && a[1][2][2].color[0] == blue) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[2][0][1].color[2] == orange && a[1][2][2].color[0] == green) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[2][0][1].color[2] == orange && a[1][2][2].color[0] == blue) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[2][0][1].color[2] == orange && a[1][2][2].color[0] == red) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[2][0][1].color[2] == orange && a[1][2][2].color[0] == green) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[2][0][1].color[2] == green && a[1][2][2].color[0] == orange) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[2][0][1].color[2] == green && a[1][2][2].color[0] == blue) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[2][0][1].color[2] == green && a[1][2][2].color[0] == red) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[2][0][1].color[2] == green && a[1][2][2].color[0] == blue) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[2][0][1].color[2] == green && a[1][2][2].color[0] == orange) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[2][0][1].color[2] == green && a[1][2][2].color[0] == red) {
					Rotate(5, -3);
				}
			}
			if (a[0][1][2].color[4] == white && a[1][0][2].color[2] == white && a[1][0][0].color[2] == white && a[1][2][2].color[3] == white) {
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[1][0][0].color[1] == blue && a[1][2][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[1][0][0].color[1] == blue && a[1][2][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[1][0][0].color[1] == blue && a[1][2][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[1][0][0].color[1] == blue && a[1][2][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[1][0][0].color[1] == blue && a[1][2][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[1][0][0].color[1] == blue && a[1][2][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[1][0][0].color[1] == red && a[1][2][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[1][0][0].color[1] == red && a[1][2][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[1][0][0].color[1] == red && a[1][2][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[1][0][0].color[1] == red && a[1][2][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[1][0][0].color[1] == red && a[1][2][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[1][0][0].color[1] == red && a[1][2][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[1][0][0].color[1] == orange && a[1][2][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[1][0][0].color[1] == orange && a[1][2][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[1][0][0].color[1] == orange && a[1][2][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[1][0][0].color[1] == orange && a[1][2][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[1][0][0].color[1] == orange && a[1][2][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[1][0][0].color[1] == orange && a[1][2][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[1][0][0].color[1] == green && a[1][2][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[1][0][0].color[1] == green && a[1][2][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[1][0][0].color[1] == green && a[1][2][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[1][0][0].color[1] == green && a[1][2][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[1][0][0].color[1] == green && a[1][2][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[1][0][0].color[1] == green && a[1][2][2].color[0] == red) {
					Rotate(1, -3);
				}
			}
			if (a[0][1][2].color[4] == white && a[1][0][2].color[2] == white && a[1][0][0].color[1] == white && a[1][2][2].color[3] == white) {
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[1][0][0].color[2] == blue && a[1][2][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[1][0][0].color[2] == blue && a[1][2][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[1][0][0].color[2] == blue && a[1][2][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[1][0][0].color[2] == blue && a[1][2][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[1][0][0].color[2] == blue && a[1][2][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[1][0][0].color[2] == blue && a[1][2][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[1][0][0].color[2] == red && a[1][2][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[1][0][0].color[2] == red && a[1][2][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[1][0][0].color[2] == red && a[1][2][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[1][0][0].color[2] == red && a[1][2][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[1][0][0].color[2] == red && a[1][2][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[1][0][0].color[2] == red && a[1][2][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[1][0][0].color[2] == orange && a[1][2][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[1][0][0].color[2] == orange && a[1][2][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[1][0][0].color[2] == orange && a[1][2][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[1][0][0].color[2] == orange && a[1][2][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[1][0][0].color[2] == orange && a[1][2][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[1][0][0].color[2] == orange && a[1][2][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[1][0][0].color[2] == green && a[1][2][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[1][0][0].color[2] == green && a[1][2][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[1][0][0].color[2] == green && a[1][2][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[1][0][0].color[2] == green && a[1][2][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[1][0][0].color[2] == green && a[1][2][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[1][0][0].color[2] == green && a[1][2][2].color[0] == red) {
					Rotate(1, -3);
				}
			}
			if (a[0][1][2].color[4] == white && a[1][0][2].color[2] == white && a[0][0][1].color[2] == white && a[1][2][2].color[3] == white) {
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[0][0][1].color[4] == blue && a[1][2][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[0][0][1].color[4] == blue && a[1][2][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[0][0][1].color[4] == blue && a[1][2][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[0][0][1].color[4] == blue && a[1][2][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[0][0][1].color[4] == blue && a[1][2][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[0][0][1].color[4] == blue && a[1][2][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[0][0][1].color[4] == red && a[1][2][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[0][0][1].color[4] == red && a[1][2][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[0][0][1].color[4] == red && a[1][2][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[0][0][1].color[4] == red && a[1][2][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[0][0][1].color[4] == red && a[1][2][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[0][0][1].color[4] == red && a[1][2][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[0][0][1].color[4] == orange && a[1][2][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[0][0][1].color[4] == orange && a[1][2][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[0][0][1].color[4] == orange && a[1][2][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[0][0][1].color[4] == orange && a[1][2][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[0][0][1].color[4] == orange && a[1][2][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[0][0][1].color[4] == orange && a[1][2][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[0][0][1].color[4] == green && a[1][2][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[0][0][1].color[4] == green && a[1][2][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[0][0][1].color[4] == green && a[1][2][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[0][0][1].color[4] == green && a[1][2][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[0][0][1].color[4] == green && a[1][2][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[0][0][1].color[4] == green && a[1][2][2].color[0] == red) {
					Rotate(1, -3);
				}
			}
			if (a[0][1][2].color[4] == white && a[1][0][2].color[2] == white && a[0][0][1].color[4] == white && a[1][2][2].color[3] == white) {
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[0][0][1].color[2] == blue && a[1][2][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[0][0][1].color[2] == blue && a[1][2][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[0][0][1].color[2] == blue && a[1][2][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[0][0][1].color[2] == blue && a[1][2][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[0][0][1].color[2] == blue && a[1][2][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[0][0][1].color[2] == blue && a[1][2][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[0][0][1].color[2] == red && a[1][2][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[0][0][1].color[2] == red && a[1][2][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[0][0][1].color[2] == red && a[1][2][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[0][0][1].color[2] == red && a[1][2][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[0][0][1].color[2] == red && a[1][2][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[0][0][1].color[2] == red && a[1][2][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[0][0][1].color[2] == orange && a[1][2][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[0][0][1].color[2] == orange && a[1][2][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[0][0][1].color[2] == orange && a[1][2][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[0][0][1].color[2] == orange && a[1][2][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[0][0][1].color[2] == orange && a[1][2][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[0][0][1].color[2] == orange && a[1][2][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[0][0][1].color[2] == green && a[1][2][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[0][0][1].color[2] == green && a[1][2][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[0][0][1].color[2] == green && a[1][2][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[0][0][1].color[2] == green && a[1][2][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[0][0][1].color[2] == green && a[1][2][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[0][0][1].color[2] == green && a[1][2][2].color[0] == red) {
					Rotate(1, -3);
				}
			}
			if (a[0][1][2].color[4] == white && a[1][0][2].color[2] == white && a[2][2][1].color[3] == white && a[1][2][2].color[3] == white) {
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[2][2][1].color[5] == blue && a[1][2][2].color[0] == orange) {
					Rotate(5, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[2][2][1].color[5] == blue && a[1][2][2].color[0] == red) {
					Rotate(5, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[2][2][1].color[5] == blue && a[1][2][2].color[0] == green) {
					Rotate(5, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[2][2][1].color[5] == blue && a[1][2][2].color[0] == red) {
					Rotate(5, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[2][2][1].color[5] == blue && a[1][2][2].color[0] == orange) {
					Rotate(5, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[2][2][1].color[5] == blue && a[1][2][2].color[0] == green) {
					Rotate(5, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[2][2][1].color[5] == red && a[1][2][2].color[0] == orange) {
					Rotate(5, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[2][2][1].color[5] == red && a[1][2][2].color[0] == blue) {
					Rotate(5, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[2][2][1].color[5] == red && a[1][2][2].color[0] == green) {
					Rotate(5, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[2][2][1].color[5] == red && a[1][2][2].color[0] == blue) {
					Rotate(5, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[2][2][1].color[5] == red && a[1][2][2].color[0] == orange) {
					Rotate(5, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[2][2][1].color[5] == red && a[1][2][2].color[0] == green) {
					Rotate(5, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[2][2][1].color[5] == orange && a[1][2][2].color[0] == red) {
					Rotate(5, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[2][2][1].color[5] == orange && a[1][2][2].color[0] == blue) {
					Rotate(5, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[2][2][1].color[5] == orange && a[1][2][2].color[0] == green) {
					Rotate(5, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[2][2][1].color[5] == orange && a[1][2][2].color[0] == blue) {
					Rotate(5, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[2][2][1].color[5] == orange && a[1][2][2].color[0] == red) {
					Rotate(5, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[2][2][1].color[5] == orange && a[1][2][2].color[0] == green) {
					Rotate(5, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[2][2][1].color[5] == green && a[1][2][2].color[0] == orange) {
					Rotate(5, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[2][2][1].color[5] == green && a[1][2][2].color[0] == blue) {
					Rotate(5, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[2][2][1].color[5] == green && a[1][2][2].color[0] == red) {
					Rotate(5, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[2][2][1].color[5] == green && a[1][2][2].color[0] == blue) {
					Rotate(5, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[2][2][1].color[5] == green && a[1][2][2].color[0] == orange) {
					Rotate(5, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[2][2][1].color[5] == green && a[1][2][2].color[0] == red) {
					Rotate(5, 3);
				}
			}
			if (a[0][1][2].color[4] == white && a[1][0][2].color[2] == white && a[2][2][1].color[5] == white && a[1][2][2].color[3] == white) {
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[2][2][1].color[3] == blue && a[1][2][2].color[0] == orange) {
					Rotate(5, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[2][2][1].color[3] == blue && a[1][2][2].color[0] == red) {
					Rotate(5, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[2][2][1].color[3] == blue && a[1][2][2].color[0] == green) {
					Rotate(5, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[2][2][1].color[3] == blue && a[1][2][2].color[0] == red) {
					Rotate(5, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[2][2][1].color[3] == blue && a[1][2][2].color[0] == orange) {
					Rotate(5, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[2][2][1].color[3] == blue && a[1][2][2].color[0] == green) {
					Rotate(5, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[2][2][1].color[3] == red && a[1][2][2].color[0] == orange) {
					Rotate(5, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[2][2][1].color[3] == red && a[1][2][2].color[0] == blue) {
					Rotate(5, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[2][2][1].color[3] == red && a[1][2][2].color[0] == green) {
					Rotate(5, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[2][2][1].color[3] == red && a[1][2][2].color[0] == blue) {
					Rotate(5, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[2][2][1].color[3] == red && a[1][2][2].color[0] == orange) {
					Rotate(5, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[2][2][1].color[3] == red && a[1][2][2].color[0] == green) {
					Rotate(5, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[2][2][1].color[3] == orange && a[1][2][2].color[0] == red) {
					Rotate(5, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[2][2][1].color[3] == orange && a[1][2][2].color[0] == blue) {
					Rotate(5, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[2][2][1].color[3] == orange && a[1][2][2].color[0] == green) {
					Rotate(5, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[2][2][1].color[3] == orange && a[1][2][2].color[0] == blue) {
					Rotate(5, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[2][2][1].color[3] == orange && a[1][2][2].color[0] == red) {
					Rotate(5, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[2][2][1].color[3] == orange && a[1][2][2].color[0] == green) {
					Rotate(5, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[2][2][1].color[3] == green && a[1][2][2].color[0] == orange) {
					Rotate(5, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[2][2][1].color[3] == green && a[1][2][2].color[0] == blue) {
					Rotate(5, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[2][2][1].color[3] == green && a[1][2][2].color[0] == red) {
					Rotate(5, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[2][2][1].color[3] == green && a[1][2][2].color[0] == blue) {
					Rotate(5, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[2][2][1].color[3] == green && a[1][2][2].color[0] == orange) {
					Rotate(5, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[2][2][1].color[3] == green && a[1][2][2].color[0] == red) {
					Rotate(5, 3);
				}
			}
			if (a[0][1][2].color[4] == white && a[1][0][2].color[2] == white && a[1][2][0].color[3] == white && a[1][2][2].color[3] == white) {
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[1][2][0].color[1] == blue && a[1][2][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[1][2][0].color[1] == blue && a[1][2][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[1][2][0].color[1] == blue && a[1][2][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[1][2][0].color[1] == blue && a[1][2][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[1][2][0].color[1] == blue && a[1][2][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[1][2][0].color[1] == blue && a[1][2][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[1][2][0].color[1] == red && a[1][2][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[1][2][0].color[1] == red && a[1][2][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[1][2][0].color[1] == red && a[1][2][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[1][2][0].color[1] == red && a[1][2][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[1][2][0].color[1] == red && a[1][2][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[1][2][0].color[1] == red && a[1][2][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[1][2][0].color[1] == orange && a[1][2][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[1][2][0].color[1] == orange && a[1][2][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[1][2][0].color[1] == orange && a[1][2][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[1][2][0].color[1] == orange && a[1][2][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[1][2][0].color[1] == orange && a[1][2][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[1][2][0].color[1] == orange && a[1][2][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[1][2][0].color[1] == green && a[1][2][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[1][2][0].color[1] == green && a[1][2][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[1][2][0].color[1] == green && a[1][2][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[1][2][0].color[1] == green && a[1][2][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[1][2][0].color[1] == green && a[1][2][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[1][2][0].color[1] == green && a[1][2][2].color[0] == red) {
					Rotate(1, 3);
				}
			}
			if (a[0][1][2].color[4] == white && a[1][0][2].color[2] == white && a[1][2][0].color[1] == white && a[1][2][2].color[3] == white) {
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[1][2][0].color[3] == blue && a[1][2][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[1][2][0].color[3] == blue && a[1][2][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[1][2][0].color[3] == blue && a[1][2][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[1][2][0].color[3] == blue && a[1][2][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[1][2][0].color[3] == blue && a[1][2][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[1][2][0].color[3] == blue && a[1][2][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[1][2][0].color[3] == red && a[1][2][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[1][2][0].color[3] == red && a[1][2][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[1][2][0].color[3] == red && a[1][2][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[1][2][0].color[3] == red && a[1][2][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[1][2][0].color[3] == red && a[1][2][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[1][2][0].color[3] == red && a[1][2][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[1][2][0].color[3] == orange && a[1][2][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[1][2][0].color[3] == orange && a[1][2][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[1][2][0].color[3] == orange && a[1][2][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[1][2][0].color[3] == orange && a[1][2][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[1][2][0].color[3] == orange && a[1][2][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[1][2][0].color[3] == orange && a[1][2][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[1][2][0].color[3] == green && a[1][2][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[1][2][0].color[3] == green && a[1][2][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[1][2][0].color[3] == green && a[1][2][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[1][2][0].color[3] == green && a[1][2][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[1][2][0].color[3] == green && a[1][2][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[1][2][0].color[3] == green && a[1][2][2].color[0] == red) {
					Rotate(1, 3);
				}
			}
			if (a[0][1][2].color[4] == white && a[1][0][2].color[2] == white && a[0][2][1].color[3] == white && a[1][2][2].color[3] == white) {
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[0][2][1].color[4] == blue && a[1][2][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[0][2][1].color[4] == blue && a[1][2][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[0][2][1].color[4] == blue && a[1][2][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[0][2][1].color[4] == blue && a[1][2][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[0][2][1].color[4] == blue && a[1][2][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[0][2][1].color[4] == blue && a[1][2][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[0][2][1].color[4] == red && a[1][2][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[0][2][1].color[4] == red && a[1][2][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[0][2][1].color[4] == red && a[1][2][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[0][2][1].color[4] == red && a[1][2][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[0][2][1].color[4] == red && a[1][2][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[0][2][1].color[4] == red && a[1][2][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[0][2][1].color[4] == orange && a[1][2][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[0][2][1].color[4] == orange && a[1][2][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[0][2][1].color[4] == orange && a[1][2][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[0][2][1].color[4] == orange && a[1][2][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[0][2][1].color[4] == orange && a[1][2][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[0][2][1].color[4] == orange && a[1][2][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[0][2][1].color[4] == green && a[1][2][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[0][2][1].color[4] == green && a[1][2][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[0][2][1].color[4] == green && a[1][2][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[0][2][1].color[4] == green && a[1][2][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[0][2][1].color[4] == green && a[1][2][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[0][2][1].color[4] == green && a[1][2][2].color[0] == red) {
					Rotate(1, -3);
				}
			}
			if (a[0][1][2].color[4] == white && a[1][0][2].color[2] == white && a[0][2][1].color[4] == white && a[1][2][2].color[3] == white) {
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[0][2][1].color[3] == blue && a[1][2][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[0][2][1].color[3] == blue && a[1][2][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[0][2][1].color[3] == blue && a[1][2][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[0][2][1].color[3] == blue && a[1][2][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[0][2][1].color[3] == blue && a[1][2][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[0][2][1].color[3] == blue && a[1][2][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[0][2][1].color[3] == red && a[1][2][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[0][2][1].color[3] == red && a[1][2][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[0][2][1].color[3] == red && a[1][2][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[0][2][1].color[3] == red && a[1][2][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[0][2][1].color[3] == red && a[1][2][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[0][2][1].color[3] == red && a[1][2][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[0][2][1].color[3] == orange && a[1][2][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[0][2][1].color[3] == orange && a[1][2][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[0][2][1].color[3] == orange && a[1][2][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[0][2][1].color[3] == orange && a[1][2][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[0][2][1].color[3] == orange && a[1][2][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[0][2][1].color[3] == orange && a[1][2][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[0][2][1].color[3] == green && a[1][2][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[0][2][1].color[3] == green && a[1][2][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[0][2][1].color[3] == green && a[1][2][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[0][2][1].color[3] == green && a[1][2][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[0][2][1].color[3] == green && a[1][2][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[0][2][1].color[3] == green && a[1][2][2].color[0] == red) {
					Rotate(1, -3);
				}
			}
			if (a[0][1][2].color[4] == white && a[1][0][2].color[2] == white && a[0][1][0].color[1] == white && a[1][2][2].color[3] == white) {
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[0][1][0].color[4] == blue && a[1][2][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[0][1][0].color[4] == blue && a[1][2][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[0][1][0].color[4] == blue && a[1][2][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[0][1][0].color[4] == blue && a[1][2][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[0][1][0].color[4] == blue && a[1][2][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[0][1][0].color[4] == blue && a[1][2][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[0][1][0].color[4] == red && a[1][2][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[0][1][0].color[4] == red && a[1][2][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[0][1][0].color[4] == red && a[1][2][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[0][1][0].color[4] == red && a[1][2][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[0][1][0].color[4] == red && a[1][2][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[0][1][0].color[4] == red && a[1][2][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[0][1][0].color[4] == orange && a[1][2][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[0][1][0].color[4] == orange && a[1][2][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[0][1][0].color[4] == orange && a[1][2][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[0][1][0].color[4] == orange && a[1][2][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[0][1][0].color[4] == orange && a[1][2][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[0][1][0].color[4] == orange && a[1][2][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[0][1][0].color[4] == green && a[1][2][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[0][1][0].color[4] == green && a[1][2][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[0][1][0].color[4] == green && a[1][2][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[0][1][0].color[4] == green && a[1][2][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[0][1][0].color[4] == green && a[1][2][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[0][1][0].color[4] == green && a[1][2][2].color[0] == red) {
					Rotate(1, -3);
				}
			}
			if (a[0][1][2].color[4] == white && a[1][0][2].color[2] == white && a[0][1][0].color[4] == white && a[1][2][2].color[3] == white) {
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[0][1][0].color[1] == blue && a[1][2][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[0][1][0].color[1] == blue && a[1][2][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[0][1][0].color[1] == blue && a[1][2][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[0][1][0].color[1] == blue && a[1][2][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[0][1][0].color[1] == blue && a[1][2][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[0][1][0].color[1] == blue && a[1][2][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[0][1][0].color[1] == red && a[1][2][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[0][1][0].color[1] == red && a[1][2][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[0][1][0].color[1] == red && a[1][2][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[0][1][0].color[1] == red && a[1][2][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[0][1][0].color[1] == red && a[1][2][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[0][1][0].color[1] == red && a[1][2][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[0][1][0].color[1] == orange && a[1][2][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[0][1][0].color[1] == orange && a[1][2][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[0][1][0].color[1] == orange && a[1][2][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[0][1][0].color[1] == orange && a[1][2][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[0][1][0].color[1] == orange && a[1][2][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[0][1][0].color[1] == orange && a[1][2][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[0][1][0].color[1] == green && a[1][2][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[0][1][0].color[1] == green && a[1][2][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[0][1][0].color[1] == green && a[1][2][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[0][1][0].color[1] == green && a[1][2][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[0][1][0].color[1] == green && a[1][2][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[0][1][0].color[1] == green && a[1][2][2].color[0] == red) {
					Rotate(1, -3);
				}
			}
			if (a[0][1][2].color[4] == white && a[1][0][2].color[2] == white && a[2][1][0].color[1] == white && a[1][2][2].color[3] == white) {
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[2][1][0].color[5] == blue && a[1][2][2].color[0] == orange) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[2][1][0].color[5] == blue && a[1][2][2].color[0] == red) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[2][1][0].color[5] == blue && a[1][2][2].color[0] == green) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[2][1][0].color[5] == blue && a[1][2][2].color[0] == red) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[2][1][0].color[5] == blue && a[1][2][2].color[0] == orange) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[2][1][0].color[5] == blue && a[1][2][2].color[0] == green) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[2][1][0].color[5] == red && a[1][2][2].color[0] == orange) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[2][1][0].color[5] == red && a[1][2][2].color[0] == blue) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[2][1][0].color[5] == red && a[1][2][2].color[0] == green) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[2][1][0].color[5] == red && a[1][2][2].color[0] == blue) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[2][1][0].color[5] == red && a[1][2][2].color[0] == orange) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[2][1][0].color[5] == red && a[1][2][2].color[0] == green) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[2][1][0].color[5] == orange && a[1][2][2].color[0] == red) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[2][1][0].color[5] == orange && a[1][2][2].color[0] == blue) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[2][1][0].color[5] == orange && a[1][2][2].color[0] == green) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[2][1][0].color[5] == orange && a[1][2][2].color[0] == blue) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[2][1][0].color[5] == orange && a[1][2][2].color[0] == red) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[2][1][0].color[5] == orange && a[1][2][2].color[0] == green) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[2][1][0].color[5] == green && a[1][2][2].color[0] == orange) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[2][1][0].color[5] == green && a[1][2][2].color[0] == blue) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[2][1][0].color[5] == green && a[1][2][2].color[0] == red) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[2][1][0].color[5] == green && a[1][2][2].color[0] == blue) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[2][1][0].color[5] == green && a[1][2][2].color[0] == orange) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[2][1][0].color[5] == green && a[1][2][2].color[0] == red) {
					Rotate(5, -3);
				}
			}
			if (a[0][1][2].color[4] == white && a[1][0][2].color[2] == white && a[2][1][0].color[5] == white && a[1][2][2].color[3] == white) {
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[2][1][0].color[1] == blue && a[1][2][2].color[0] == orange) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[2][1][0].color[1] == blue && a[1][2][2].color[0] == red) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[2][1][0].color[1] == blue && a[1][2][2].color[0] == green) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[2][1][0].color[1] == blue && a[1][2][2].color[0] == red) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[2][1][0].color[1] == blue && a[1][2][2].color[0] == orange) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[2][1][0].color[1] == blue && a[1][2][2].color[0] == green) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[2][1][0].color[1] == red && a[1][2][2].color[0] == orange) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[2][1][0].color[1] == red && a[1][2][2].color[0] == blue) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[2][1][0].color[1] == red && a[1][2][2].color[0] == green) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[2][1][0].color[1] == red && a[1][2][2].color[0] == blue) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[2][1][0].color[1] == red && a[1][2][2].color[0] == orange) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[2][1][0].color[1] == red && a[1][2][2].color[0] == green) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[2][1][0].color[1] == orange && a[1][2][2].color[0] == red) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[2][1][0].color[1] == orange && a[1][2][2].color[0] == blue) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[2][1][0].color[1] == orange && a[1][2][2].color[0] == green) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[2][1][0].color[1] == orange && a[1][2][2].color[0] == blue) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[2][1][0].color[1] == orange && a[1][2][2].color[0] == red) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[2][1][0].color[1] == orange && a[1][2][2].color[0] == green) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[2][1][0].color[1] == green && a[1][2][2].color[0] == orange) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[2][1][0].color[1] == green && a[1][2][2].color[0] == blue) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[2][1][0].color[1] == green && a[1][2][2].color[0] == red) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[2][1][0].color[1] == green && a[1][2][2].color[0] == blue) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[2][1][0].color[1] == green && a[1][2][2].color[0] == orange) {
					Rotate(5, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[2][1][0].color[1] == green && a[1][2][2].color[0] == red) {
					Rotate(5, -3);
				}
			}
			//собрано 0 наверху, но есть 3 белых кроме левого 
			if (a[2][1][2].color[5] == white && a[1][0][2].color[2] == white && a[2][0][1].color[2] == white && a[1][2][2].color[3] == white) {
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == red && a[2][0][1].color[5] == blue && a[1][2][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[2][0][1].color[5] == blue && a[1][2][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[2][0][1].color[5] == blue && a[1][2][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[2][0][1].color[5] == blue && a[1][2][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == green && a[2][0][1].color[5] == blue && a[1][2][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[2][0][1].color[5] == blue && a[1][2][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[2][0][1].color[5] == red && a[1][2][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[2][0][1].color[5] == red && a[1][2][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[2][0][1].color[5] == red && a[1][2][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[2][0][1].color[5] == red && a[1][2][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[2][0][1].color[5] == red && a[1][2][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[2][0][1].color[5] == red && a[1][2][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[2][0][1].color[5] == orange && a[1][2][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == red && a[2][0][1].color[5] == orange && a[1][2][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[2][0][1].color[5] == orange && a[1][2][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == green && a[2][0][1].color[5] == orange && a[1][2][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[2][0][1].color[5] == orange && a[1][2][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[2][0][1].color[5] == orange && a[1][2][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[2][0][1].color[5] == green && a[1][2][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[2][0][1].color[5] == green && a[1][2][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[2][0][1].color[5] == green && a[1][2][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[2][0][1].color[5] == green && a[1][2][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[2][0][1].color[5] == green && a[1][2][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[2][0][1].color[5] == green && a[1][2][2].color[0] == red) {
					Rotate(1, 3);
				}
			}
			if (a[2][1][2].color[5] == white && a[1][0][2].color[2] == white && a[2][0][1].color[5] == white && a[1][2][2].color[3] == white) {
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == red && a[2][0][1].color[2] == blue && a[1][2][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[2][0][1].color[2] == blue && a[1][2][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[2][0][1].color[2] == blue && a[1][2][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[2][0][1].color[2] == blue && a[1][2][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == green && a[2][0][1].color[2] == blue && a[1][2][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[2][0][1].color[2] == blue && a[1][2][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[2][0][1].color[2] == red && a[1][2][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[2][0][1].color[2] == red && a[1][2][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[2][0][1].color[2] == red && a[1][2][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[2][0][1].color[2] == red && a[1][2][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[2][0][1].color[2] == red && a[1][2][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[2][0][1].color[2] == red && a[1][2][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[2][0][1].color[2] == orange && a[1][2][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == red && a[2][0][1].color[2] == orange && a[1][2][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[2][0][1].color[2] == orange && a[1][2][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == green && a[2][0][1].color[2] == orange && a[1][2][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[2][0][1].color[2] == orange && a[1][2][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[2][0][1].color[2] == orange && a[1][2][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[2][0][1].color[2] == green && a[1][2][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[2][0][1].color[2] == green && a[1][2][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[2][0][1].color[2] == green && a[1][2][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[2][0][1].color[2] == green && a[1][2][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[2][0][1].color[2] == green && a[1][2][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[2][0][1].color[2] == green && a[1][2][2].color[0] == red) {
					Rotate(1, 3);
				}
			}
			if (a[2][1][2].color[5] == white && a[1][0][2].color[2] == white && a[1][0][0].color[2] == white && a[1][2][2].color[3] == white) {
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == red && a[1][0][0].color[1] == blue && a[1][2][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[1][0][0].color[1] == blue && a[1][2][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[1][0][0].color[1] == blue && a[1][2][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[1][0][0].color[1] == blue && a[1][2][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == green && a[1][0][0].color[1] == blue && a[1][2][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[1][0][0].color[1] == blue && a[1][2][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[1][0][0].color[1] == red && a[1][2][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[1][0][0].color[1] == red && a[1][2][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[1][0][0].color[1] == red && a[1][2][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[1][0][0].color[1] == red && a[1][2][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[1][0][0].color[1] == red && a[1][2][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[1][0][0].color[1] == red && a[1][2][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[1][0][0].color[1] == orange && a[1][2][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == red && a[1][0][0].color[1] == orange && a[1][2][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[1][0][0].color[1] == orange && a[1][2][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == green && a[1][0][0].color[1] == orange && a[1][2][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[1][0][0].color[1] == orange && a[1][2][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[1][0][0].color[1] == orange && a[1][2][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[1][0][0].color[1] == green && a[1][2][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[1][0][0].color[1] == green && a[1][2][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[1][0][0].color[1] == green && a[1][2][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[1][0][0].color[1] == green && a[1][2][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[1][0][0].color[1] == green && a[1][2][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[1][0][0].color[1] == green && a[1][2][2].color[0] == red) {
					Rotate(1, 3);
				}
			}
			if (a[2][1][2].color[5] == white && a[1][0][2].color[2] == white && a[1][0][0].color[1] == white && a[1][2][2].color[3] == white) {
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == red && a[1][0][0].color[2] == blue && a[1][2][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[1][0][0].color[2] == blue && a[1][2][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[1][0][0].color[2] == blue && a[1][2][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[1][0][0].color[2] == blue && a[1][2][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == green && a[1][0][0].color[2] == blue && a[1][2][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[1][0][0].color[2] == blue && a[1][2][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[1][0][0].color[2] == red && a[1][2][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[1][0][0].color[2] == red && a[1][2][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[1][0][0].color[2] == red && a[1][2][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[1][0][0].color[2] == red && a[1][2][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[1][0][0].color[2] == red && a[1][2][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[1][0][0].color[2] == red && a[1][2][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[1][0][0].color[2] == orange && a[1][2][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == red && a[1][0][0].color[2] == orange && a[1][2][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[1][0][0].color[2] == orange && a[1][2][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == green && a[1][0][0].color[2] == orange && a[1][2][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[1][0][0].color[2] == orange && a[1][2][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[1][0][0].color[2] == orange && a[1][2][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[1][0][0].color[2] == green && a[1][2][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[1][0][0].color[2] == green && a[1][2][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[1][0][0].color[2] == green && a[1][2][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[1][0][0].color[2] == green && a[1][2][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[1][0][0].color[2] == green && a[1][2][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[1][0][0].color[2] == green && a[1][2][2].color[0] == red) {
					Rotate(1, 3);
				}
			}
			if (a[2][1][2].color[5] == white && a[1][0][2].color[2] == white && a[0][0][1].color[2] == white && a[1][2][2].color[3] == white) {
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == red && a[0][0][1].color[4] == blue && a[1][2][2].color[0] == orange) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[0][0][1].color[4] == blue && a[1][2][2].color[0] == red) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[0][0][1].color[4] == blue && a[1][2][2].color[0] == green) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[0][0][1].color[4] == blue && a[1][2][2].color[0] == red) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == green && a[0][0][1].color[4] == blue && a[1][2][2].color[0] == orange) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[0][0][1].color[4] == blue && a[1][2][2].color[0] == green) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[0][0][1].color[4] == red && a[1][2][2].color[0] == orange) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[0][0][1].color[4] == red && a[1][2][2].color[0] == blue) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[0][0][1].color[4] == red && a[1][2][2].color[0] == green) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[0][0][1].color[4] == red && a[1][2][2].color[0] == blue) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[0][0][1].color[4] == red && a[1][2][2].color[0] == orange) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[0][0][1].color[4] == red && a[1][2][2].color[0] == green) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[0][0][1].color[4] == orange && a[1][2][2].color[0] == red) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == red && a[0][0][1].color[4] == orange && a[1][2][2].color[0] == blue) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[0][0][1].color[4] == orange && a[1][2][2].color[0] == green) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == green && a[0][0][1].color[4] == orange && a[1][2][2].color[0] == blue) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[0][0][1].color[4] == orange && a[1][2][2].color[0] == red) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[0][0][1].color[4] == orange && a[1][2][2].color[0] == green) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[0][0][1].color[4] == green && a[1][2][2].color[0] == orange) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[0][0][1].color[4] == green && a[1][2][2].color[0] == blue) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[0][0][1].color[4] == green && a[1][2][2].color[0] == red) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[0][0][1].color[4] == green && a[1][2][2].color[0] == blue) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[0][0][1].color[4] == green && a[1][2][2].color[0] == orange) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[0][0][1].color[4] == green && a[1][2][2].color[0] == red) {
					Rotate(4, -3);
				}
			}
			if (a[2][1][2].color[5] == white && a[1][0][2].color[2] == white && a[0][0][1].color[4] == white && a[1][2][2].color[3] == white) {
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == red && a[0][0][1].color[2] == blue && a[1][2][2].color[0] == orange) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[0][0][1].color[2] == blue && a[1][2][2].color[0] == red) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[0][0][1].color[2] == blue && a[1][2][2].color[0] == green) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[0][0][1].color[2] == blue && a[1][2][2].color[0] == red) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == green && a[0][0][1].color[2] == blue && a[1][2][2].color[0] == orange) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[0][0][1].color[2] == blue && a[1][2][2].color[0] == green) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[0][0][1].color[2] == red && a[1][2][2].color[0] == orange) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[0][0][1].color[2] == red && a[1][2][2].color[0] == blue) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[0][0][1].color[2] == red && a[1][2][2].color[0] == green) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[0][0][1].color[2] == red && a[1][2][2].color[0] == blue) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[0][0][1].color[2] == red && a[1][2][2].color[0] == orange) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[0][0][1].color[2] == red && a[1][2][2].color[0] == green) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[0][0][1].color[2] == orange && a[1][2][2].color[0] == red) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == red && a[0][0][1].color[2] == orange && a[1][2][2].color[0] == blue) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[0][0][1].color[2] == orange && a[1][2][2].color[0] == green) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == green && a[0][0][1].color[2] == orange && a[1][2][2].color[0] == blue) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[0][0][1].color[2] == orange && a[1][2][2].color[0] == red) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[0][0][1].color[2] == orange && a[1][2][2].color[0] == green) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[0][0][1].color[2] == green && a[1][2][2].color[0] == orange) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[0][0][1].color[2] == green && a[1][2][2].color[0] == blue) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[0][0][1].color[2] == green && a[1][2][2].color[0] == red) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[0][0][1].color[2] == green && a[1][2][2].color[0] == blue) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[0][0][1].color[2] == green && a[1][2][2].color[0] == orange) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[0][0][1].color[2] == green && a[1][2][2].color[0] == red) {
					Rotate(4, -3);
				}
			}
			if (a[2][1][2].color[5] == white && a[1][0][2].color[2] == white && a[2][2][1].color[3] == white && a[1][2][2].color[3] == white) {
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == red && a[2][2][1].color[5] == blue && a[1][2][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[2][2][1].color[5] == blue && a[1][2][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[2][2][1].color[5] == blue && a[1][2][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[2][2][1].color[5] == blue && a[1][2][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == green && a[2][2][1].color[5] == blue && a[1][2][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[2][2][1].color[5] == blue && a[1][2][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[2][2][1].color[5] == red && a[1][2][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[2][2][1].color[5] == red && a[1][2][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[2][2][1].color[5] == red && a[1][2][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[2][2][1].color[5] == red && a[1][2][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[2][2][1].color[5] == red && a[1][2][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[2][2][1].color[5] == red && a[1][2][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[2][2][1].color[5] == orange && a[1][2][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == red && a[2][2][1].color[5] == orange && a[1][2][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[2][2][1].color[5] == orange && a[1][2][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == green && a[2][2][1].color[5] == orange && a[1][2][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[2][2][1].color[5] == orange && a[1][2][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[2][2][1].color[5] == orange && a[1][2][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[2][2][1].color[5] == green && a[1][2][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[2][2][1].color[5] == green && a[1][2][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[2][2][1].color[5] == green && a[1][2][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[2][2][1].color[5] == green && a[1][2][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[2][2][1].color[5] == green && a[1][2][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[2][2][1].color[5] == green && a[1][2][2].color[0] == red) {
					Rotate(1, 3);
				}
			}
			if (a[2][1][2].color[5] == white && a[1][0][2].color[2] == white && a[2][2][1].color[5] == white && a[1][2][2].color[3] == white) {
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == red && a[2][2][1].color[3] == blue && a[1][2][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[2][2][1].color[3] == blue && a[1][2][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[2][2][1].color[3] == blue && a[1][2][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[2][2][1].color[3] == blue && a[1][2][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == green && a[2][2][1].color[3] == blue && a[1][2][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[2][2][1].color[3] == blue && a[1][2][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[2][2][1].color[3] == red && a[1][2][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[2][2][1].color[3] == red && a[1][2][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[2][2][1].color[3] == red && a[1][2][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[2][2][1].color[3] == red && a[1][2][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[2][2][1].color[3] == red && a[1][2][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[2][2][1].color[3] == red && a[1][2][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[2][2][1].color[3] == orange && a[1][2][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == red && a[2][2][1].color[3] == orange && a[1][2][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[2][2][1].color[3] == orange && a[1][2][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == green && a[2][2][1].color[3] == orange && a[1][2][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[2][2][1].color[3] == orange && a[1][2][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[2][2][1].color[3] == orange && a[1][2][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[2][2][1].color[3] == green && a[1][2][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[2][2][1].color[3] == green && a[1][2][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[2][2][1].color[3] == green && a[1][2][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[2][2][1].color[3] == green && a[1][2][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[2][2][1].color[3] == green && a[1][2][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[2][2][1].color[3] == green && a[1][2][2].color[0] == red) {
					Rotate(1, 3);
				}
			}
			if (a[2][1][2].color[5] == white && a[1][0][2].color[2] == white && a[1][2][0].color[3] == white && a[1][2][2].color[3] == white) {
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == red && a[1][2][0].color[1] == blue && a[1][2][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[1][2][0].color[1] == blue && a[1][2][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[1][2][0].color[1] == blue && a[1][2][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[1][2][0].color[1] == blue && a[1][2][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == green && a[1][2][0].color[1] == blue && a[1][2][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[1][2][0].color[1] == blue && a[1][2][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[1][2][0].color[1] == red && a[1][2][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[1][2][0].color[1] == red && a[1][2][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[1][2][0].color[1] == red && a[1][2][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[1][2][0].color[1] == red && a[1][2][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[1][2][0].color[1] == red && a[1][2][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[1][2][0].color[1] == red && a[1][2][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[1][2][0].color[1] == orange && a[1][2][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == red && a[1][2][0].color[1] == orange && a[1][2][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[1][2][0].color[1] == orange && a[1][2][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == green && a[1][2][0].color[1] == orange && a[1][2][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[1][2][0].color[1] == orange && a[1][2][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[1][2][0].color[1] == orange && a[1][2][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[1][2][0].color[1] == green && a[1][2][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[1][2][0].color[1] == green && a[1][2][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[1][2][0].color[1] == green && a[1][2][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[1][2][0].color[1] == green && a[1][2][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[1][2][0].color[1] == green && a[1][2][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[1][2][0].color[1] == green && a[1][2][2].color[0] == red) {
					Rotate(1, -3);
				}
			}
			if (a[2][1][2].color[5] == white && a[1][0][2].color[2] == white && a[1][2][0].color[1] == white && a[1][2][2].color[3] == white) {
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == red && a[1][2][0].color[3] == blue && a[1][2][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[1][2][0].color[3] == blue && a[1][2][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[1][2][0].color[3] == blue && a[1][2][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[1][2][0].color[3] == blue && a[1][2][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == green && a[1][2][0].color[3] == blue && a[1][2][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[1][2][0].color[3] == blue && a[1][2][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[1][2][0].color[3] == red && a[1][2][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[1][2][0].color[3] == red && a[1][2][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[1][2][0].color[3] == red && a[1][2][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[1][2][0].color[3] == red && a[1][2][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[1][2][0].color[3] == red && a[1][2][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[1][2][0].color[3] == red && a[1][2][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[1][2][0].color[3] == orange && a[1][2][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == red && a[1][2][0].color[3] == orange && a[1][2][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[1][2][0].color[3] == orange && a[1][2][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == green && a[1][2][0].color[3] == orange && a[1][2][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[1][2][0].color[3] == orange && a[1][2][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[1][2][0].color[3] == orange && a[1][2][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[1][2][0].color[3] == green && a[1][2][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[1][2][0].color[3] == green && a[1][2][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[1][2][0].color[3] == green && a[1][2][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[1][2][0].color[3] == green && a[1][2][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[1][2][0].color[3] == green && a[1][2][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[1][2][0].color[3] == green && a[1][2][2].color[0] == red) {
					Rotate(1, -3);
				}
			}
			if (a[2][1][2].color[5] == white && a[1][0][2].color[2] == white && a[0][2][1].color[3] == white && a[1][2][2].color[3] == white) {
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == red && a[0][2][1].color[4] == blue && a[1][2][2].color[0] == orange) {
					Rotate(4, 3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[0][2][1].color[4] == blue && a[1][2][2].color[0] == red) {
					Rotate(4, 3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[0][2][1].color[4] == blue && a[1][2][2].color[0] == green) {
					Rotate(4, 3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[0][2][1].color[4] == blue && a[1][2][2].color[0] == red) {
					Rotate(4, 3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == green && a[0][2][1].color[4] == blue && a[1][2][2].color[0] == orange) {
					Rotate(4, 3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[0][2][1].color[4] == blue && a[1][2][2].color[0] == green) {
					Rotate(4, 3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[0][2][1].color[4] == red && a[1][2][2].color[0] == orange) {
					Rotate(4, 3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[0][2][1].color[4] == red && a[1][2][2].color[0] == blue) {
					Rotate(4, 3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[0][2][1].color[4] == red && a[1][2][2].color[0] == green) {
					Rotate(4, 3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[0][2][1].color[4] == red && a[1][2][2].color[0] == blue) {
					Rotate(4, 3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[0][2][1].color[4] == red && a[1][2][2].color[0] == orange) {
					Rotate(4, 3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[0][2][1].color[4] == red && a[1][2][2].color[0] == green) {
					Rotate(4, 3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[0][2][1].color[4] == orange && a[1][2][2].color[0] == red) {
					Rotate(4, 3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == red && a[0][2][1].color[4] == orange && a[1][2][2].color[0] == blue) {
					Rotate(4, 3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[0][2][1].color[4] == orange && a[1][2][2].color[0] == green) {
					Rotate(4, 3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == green && a[0][2][1].color[4] == orange && a[1][2][2].color[0] == blue) {
					Rotate(4, 3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[0][2][1].color[4] == orange && a[1][2][2].color[0] == red) {
					Rotate(4, 3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[0][2][1].color[4] == orange && a[1][2][2].color[0] == green) {
					Rotate(4, 3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[0][2][1].color[4] == green && a[1][2][2].color[0] == orange) {
					Rotate(4, 3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[0][2][1].color[4] == green && a[1][2][2].color[0] == blue) {
					Rotate(4, 3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[0][2][1].color[4] == green && a[1][2][2].color[0] == red) {
					Rotate(4, 3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[0][2][1].color[4] == green && a[1][2][2].color[0] == blue) {
					Rotate(4, 3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[0][2][1].color[4] == green && a[1][2][2].color[0] == orange) {
					Rotate(4, 3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[0][2][1].color[4] == green && a[1][2][2].color[0] == red) {
					Rotate(4, 3);
				}
			}
			if (a[2][1][2].color[5] == white && a[1][0][2].color[2] == white && a[0][2][1].color[4] == white && a[1][2][2].color[3] == white) {
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == red && a[0][2][1].color[3] == blue && a[1][2][2].color[0] == orange) {
					Rotate(4, 3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[0][2][1].color[3] == blue && a[1][2][2].color[0] == red) {
					Rotate(4, 3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[0][2][1].color[3] == blue && a[1][2][2].color[0] == green) {
					Rotate(4, 3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[0][2][1].color[3] == blue && a[1][2][2].color[0] == red) {
					Rotate(4, 3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == green && a[0][2][1].color[3] == blue && a[1][2][2].color[0] == orange) {
					Rotate(4, 3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[0][2][1].color[3] == blue && a[1][2][2].color[0] == green) {
					Rotate(4, 3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[0][2][1].color[3] == red && a[1][2][2].color[0] == orange) {
					Rotate(4, 3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[0][2][1].color[3] == red && a[1][2][2].color[0] == blue) {
					Rotate(4, 3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[0][2][1].color[3] == red && a[1][2][2].color[0] == green) {
					Rotate(4, 3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[0][2][1].color[3] == red && a[1][2][2].color[0] == blue) {
					Rotate(4, 3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[0][2][1].color[3] == red && a[1][2][2].color[0] == orange) {
					Rotate(4, 3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[0][2][1].color[3] == red && a[1][2][2].color[0] == green) {
					Rotate(4, 3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[0][2][1].color[3] == orange && a[1][2][2].color[0] == red) {
					Rotate(4, 3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == red && a[0][2][1].color[3] == orange && a[1][2][2].color[0] == blue) {
					Rotate(4, 3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[0][2][1].color[3] == orange && a[1][2][2].color[0] == green) {
					Rotate(4, 3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == green && a[0][2][1].color[3] == orange && a[1][2][2].color[0] == blue) {
					Rotate(4, 3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[0][2][1].color[3] == orange && a[1][2][2].color[0] == red) {
					Rotate(4, 3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[0][2][1].color[3] == orange && a[1][2][2].color[0] == green) {
					Rotate(4, 3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[0][2][1].color[3] == green && a[1][2][2].color[0] == orange) {
					Rotate(4, 3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[0][2][1].color[3] == green && a[1][2][2].color[0] == blue) {
					Rotate(4, 3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[0][2][1].color[3] == green && a[1][2][2].color[0] == red) {
					Rotate(4, 3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[0][2][1].color[3] == green && a[1][2][2].color[0] == blue) {
					Rotate(4, 3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[0][2][1].color[3] == green && a[1][2][2].color[0] == orange) {
					Rotate(4, 3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[0][2][1].color[3] == green && a[1][2][2].color[0] == red) {
					Rotate(4, 3);
				}
			}
			if (a[2][1][2].color[5] == white && a[1][0][2].color[2] == white && a[0][1][0].color[1] == white && a[1][2][2].color[3] == white) {
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == red && a[0][1][0].color[4] == blue && a[1][2][2].color[0] == orange) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[0][1][0].color[4] == blue && a[1][2][2].color[0] == red) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[0][1][0].color[4] == blue && a[1][2][2].color[0] == green) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[0][1][0].color[4] == blue && a[1][2][2].color[0] == red) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == green && a[0][1][0].color[4] == blue && a[1][2][2].color[0] == orange) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[0][1][0].color[4] == blue && a[1][2][2].color[0] == green) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[0][1][0].color[4] == red && a[1][2][2].color[0] == orange) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[0][1][0].color[4] == red && a[1][2][2].color[0] == blue) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[0][1][0].color[4] == red && a[1][2][2].color[0] == green) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[0][1][0].color[4] == red && a[1][2][2].color[0] == blue) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[0][1][0].color[4] == red && a[1][2][2].color[0] == orange) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[0][1][0].color[4] == red && a[1][2][2].color[0] == green) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[0][1][0].color[4] == orange && a[1][2][2].color[0] == red) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == red && a[0][1][0].color[4] == orange && a[1][2][2].color[0] == blue) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[0][1][0].color[4] == orange && a[1][2][2].color[0] == green) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == green && a[0][1][0].color[4] == orange && a[1][2][2].color[0] == blue) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[0][1][0].color[4] == orange && a[1][2][2].color[0] == red) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[0][1][0].color[4] == orange && a[1][2][2].color[0] == green) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[0][1][0].color[4] == green && a[1][2][2].color[0] == orange) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[0][1][0].color[4] == green && a[1][2][2].color[0] == blue) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[0][1][0].color[4] == green && a[1][2][2].color[0] == red) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[0][1][0].color[4] == green && a[1][2][2].color[0] == blue) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[0][1][0].color[4] == green && a[1][2][2].color[0] == orange) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[0][1][0].color[4] == green && a[1][2][2].color[0] == red) {
					Rotate(4, -3);
				}
			}
			if (a[2][1][2].color[5] == white && a[1][0][2].color[2] == white && a[0][1][0].color[4] == white && a[1][2][2].color[3] == white) {
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == red && a[0][1][0].color[1] == blue && a[1][2][2].color[0] == orange) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[0][1][0].color[1] == blue && a[1][2][2].color[0] == red) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[0][1][0].color[1] == blue && a[1][2][2].color[0] == green) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[0][1][0].color[1] == blue && a[1][2][2].color[0] == red) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == green && a[0][1][0].color[1] == blue && a[1][2][2].color[0] == orange) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[0][1][0].color[1] == blue && a[1][2][2].color[0] == green) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[0][1][0].color[1] == red && a[1][2][2].color[0] == orange) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[0][1][0].color[1] == red && a[1][2][2].color[0] == blue) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[0][1][0].color[1] == red && a[1][2][2].color[0] == green) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[0][1][0].color[1] == red && a[1][2][2].color[0] == blue) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[0][1][0].color[1] == red && a[1][2][2].color[0] == orange) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[0][1][0].color[1] == red && a[1][2][2].color[0] == green) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[0][1][0].color[1] == orange && a[1][2][2].color[0] == red) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == red && a[0][1][0].color[1] == orange && a[1][2][2].color[0] == blue) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[0][1][0].color[1] == orange && a[1][2][2].color[0] == green) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == green && a[0][1][0].color[1] == orange && a[1][2][2].color[0] == blue) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[0][1][0].color[1] == orange && a[1][2][2].color[0] == red) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[0][1][0].color[1] == orange && a[1][2][2].color[0] == green) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[0][1][0].color[1] == green && a[1][2][2].color[0] == orange) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[0][1][0].color[1] == green && a[1][2][2].color[0] == blue) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[0][1][0].color[1] == green && a[1][2][2].color[0] == red) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[0][1][0].color[1] == green && a[1][2][2].color[0] == blue) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[0][1][0].color[1] == green && a[1][2][2].color[0] == orange) {
					Rotate(4, -3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[0][1][0].color[1] == green && a[1][2][2].color[0] == red) {
					Rotate(4, -3);
				}
			}
			if (a[2][1][2].color[5] == white && a[1][0][2].color[2] == white && a[2][1][0].color[1] == white && a[1][2][2].color[3] == white) {
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == red && a[2][1][0].color[5] == blue && a[1][2][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[2][1][0].color[5] == blue && a[1][2][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[2][1][0].color[5] == blue && a[1][2][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[2][1][0].color[5] == blue && a[1][2][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == green && a[2][1][0].color[5] == blue && a[1][2][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[2][1][0].color[5] == blue && a[1][2][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[2][1][0].color[5] == red && a[1][2][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[2][1][0].color[5] == red && a[1][2][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[2][1][0].color[5] == red && a[1][2][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[2][1][0].color[5] == red && a[1][2][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[2][1][0].color[5] == red && a[1][2][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[2][1][0].color[5] == red && a[1][2][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[2][1][0].color[5] == orange && a[1][2][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == red && a[2][1][0].color[5] == orange && a[1][2][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[2][1][0].color[5] == orange && a[1][2][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == green && a[2][1][0].color[5] == orange && a[1][2][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[2][1][0].color[5] == orange && a[1][2][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[2][1][0].color[5] == orange && a[1][2][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[2][1][0].color[5] == green && a[1][2][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[2][1][0].color[5] == green && a[1][2][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[2][1][0].color[5] == green && a[1][2][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[2][1][0].color[5] == green && a[1][2][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[2][1][0].color[5] == green && a[1][2][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[2][1][0].color[5] == green && a[1][2][2].color[0] == red) {
					Rotate(1, 3);
				}
			}
			if (a[2][1][2].color[5] == white && a[1][0][2].color[2] == white && a[2][1][0].color[5] == white && a[1][2][2].color[3] == white) {
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == red && a[2][1][0].color[1] == blue && a[1][2][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[2][1][0].color[1] == blue && a[1][2][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[2][1][0].color[1] == blue && a[1][2][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[2][1][0].color[1] == blue && a[1][2][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == green && a[2][1][0].color[1] == blue && a[1][2][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[2][1][0].color[1] == blue && a[1][2][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[2][1][0].color[1] == red && a[1][2][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[2][1][0].color[1] == red && a[1][2][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[2][1][0].color[1] == red && a[1][2][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[2][1][0].color[1] == red && a[1][2][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[2][1][0].color[1] == red && a[1][2][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[2][1][0].color[1] == red && a[1][2][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[2][1][0].color[1] == orange && a[1][2][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == red && a[2][1][0].color[1] == orange && a[1][2][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[2][1][0].color[1] == orange && a[1][2][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == green && a[2][1][0].color[1] == orange && a[1][2][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[2][1][0].color[1] == orange && a[1][2][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[2][1][0].color[1] == orange && a[1][2][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[2][1][0].color[1] == green && a[1][2][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[2][1][0].color[1] == green && a[1][2][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[2][1][0].color[1] == green && a[1][2][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[2][1][0].color[1] == green && a[1][2][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[2][1][0].color[1] == green && a[1][2][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[2][1][0].color[1] == green && a[1][2][2].color[0] == red) {
					Rotate(1, 3);
				}
			}
			//собрано 0 наверху, но есть 3 белых кроме верхнего 
			if (a[0][1][2].color[4] == white && a[1][0][2].color[2] == white && a[2][0][1].color[2] == white && a[2][1][2].color[5] == white) {
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[2][0][1].color[5] == blue && a[2][1][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[2][0][1].color[5] == blue && a[2][1][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[2][0][1].color[5] == blue && a[2][1][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[2][0][1].color[5] == blue && a[2][1][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[2][0][1].color[5] == blue && a[2][1][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[2][0][1].color[5] == blue && a[2][1][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[2][0][1].color[5] == red && a[2][1][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[2][0][1].color[5] == red && a[2][1][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[2][0][1].color[5] == red && a[2][1][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[2][0][1].color[5] == red && a[2][1][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[2][0][1].color[5] == red && a[2][1][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[2][0][1].color[5] == red && a[2][1][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[2][0][1].color[5] == orange && a[2][1][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[2][0][1].color[5] == orange && a[2][1][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[2][0][1].color[5] == orange && a[2][1][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[2][0][1].color[5] == orange && a[2][1][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[2][0][1].color[5] == orange && a[2][1][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[2][0][1].color[5] == orange && a[2][1][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[2][0][1].color[5] == green && a[2][1][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[2][0][1].color[5] == green && a[2][1][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[2][0][1].color[5] == green && a[2][1][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[2][0][1].color[5] == green && a[2][1][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[2][0][1].color[5] == green && a[2][1][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[2][0][1].color[5] == green && a[2][1][2].color[0] == red) {
					Rotate(1, -3);
				}
			}
			if (a[0][1][2].color[4] == white && a[1][0][2].color[2] == white && a[2][0][1].color[5] == white && a[2][1][2].color[5] == white) {
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[2][0][1].color[2] == blue && a[2][1][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[2][0][1].color[2] == blue && a[2][1][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[2][0][1].color[2] == blue && a[2][1][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[2][0][1].color[2] == blue && a[2][1][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[2][0][1].color[2] == blue && a[2][1][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[2][0][1].color[2] == blue && a[2][1][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[2][0][1].color[2] == red && a[2][1][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[2][0][1].color[2] == red && a[2][1][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[2][0][1].color[2] == red && a[2][1][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[2][0][1].color[2] == red && a[2][1][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[2][0][1].color[2] == red && a[2][1][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[2][0][1].color[2] == red && a[2][1][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[2][0][1].color[2] == orange && a[2][1][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[2][0][1].color[2] == orange && a[2][1][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[2][0][1].color[2] == orange && a[2][1][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[2][0][1].color[2] == orange && a[2][1][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[2][0][1].color[2] == orange && a[2][1][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[2][0][1].color[2] == orange && a[2][1][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[2][0][1].color[2] == green && a[2][1][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[2][0][1].color[2] == green && a[2][1][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[2][0][1].color[2] == green && a[2][1][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[2][0][1].color[2] == green && a[2][1][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[2][0][1].color[2] == green && a[2][1][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[2][0][1].color[2] == green && a[2][1][2].color[0] == red) {
					Rotate(1, -3);
				}
			}
			if (a[0][1][2].color[4] == white && a[1][0][2].color[2] == white && a[1][0][0].color[2] == white && a[2][1][2].color[5] == white) {
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[1][0][0].color[1] == blue && a[2][1][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[1][0][0].color[1] == blue && a[2][1][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[1][0][0].color[1] == blue && a[2][1][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[1][0][0].color[1] == blue && a[2][1][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[1][0][0].color[1] == blue && a[2][1][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[1][0][0].color[1] == blue && a[2][1][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[1][0][0].color[1] == red && a[2][1][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[1][0][0].color[1] == red && a[2][1][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[1][0][0].color[1] == red && a[2][1][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[1][0][0].color[1] == red && a[2][1][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[1][0][0].color[1] == red && a[2][1][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[1][0][0].color[1] == red && a[2][1][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[1][0][0].color[1] == orange && a[2][1][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[1][0][0].color[1] == orange && a[2][1][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[1][0][0].color[1] == orange && a[2][1][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[1][0][0].color[1] == orange && a[2][1][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[1][0][0].color[1] == orange && a[2][1][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[1][0][0].color[1] == orange && a[2][1][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[1][0][0].color[1] == green && a[2][1][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[1][0][0].color[1] == green && a[2][1][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[1][0][0].color[1] == green && a[2][1][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[1][0][0].color[1] == green && a[2][1][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[1][0][0].color[1] == green && a[2][1][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[1][0][0].color[1] == green && a[2][1][2].color[0] == red) {
					Rotate(1, -3);
				}
			}
			if (a[0][1][2].color[4] == white && a[1][0][2].color[2] == white && a[1][0][0].color[1] == white && a[2][1][2].color[5] == white) {
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[1][0][0].color[2] == blue && a[2][1][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[1][0][0].color[2] == blue && a[2][1][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[1][0][0].color[2] == blue && a[2][1][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[1][0][0].color[2] == blue && a[2][1][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[1][0][0].color[2] == blue && a[2][1][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[1][0][0].color[2] == blue && a[2][1][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[1][0][0].color[2] == red && a[2][1][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[1][0][0].color[2] == red && a[2][1][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[1][0][0].color[2] == red && a[2][1][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[1][0][0].color[2] == red && a[2][1][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[1][0][0].color[2] == red && a[2][1][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[1][0][0].color[2] == red && a[2][1][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[1][0][0].color[2] == orange && a[2][1][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[1][0][0].color[2] == orange && a[2][1][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[1][0][0].color[2] == orange && a[2][1][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[1][0][0].color[2] == orange && a[2][1][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[1][0][0].color[2] == orange && a[2][1][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[1][0][0].color[2] == orange && a[2][1][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[1][0][0].color[2] == green && a[2][1][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[1][0][0].color[2] == green && a[2][1][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[1][0][0].color[2] == green && a[2][1][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[1][0][0].color[2] == green && a[2][1][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[1][0][0].color[2] == green && a[2][1][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[1][0][0].color[2] == green && a[2][1][2].color[0] == red) {
					Rotate(1, -3);
				}
			}
			if (a[0][1][2].color[4] == white && a[1][0][2].color[2] == white && a[0][0][1].color[2] == white && a[2][1][2].color[5] == white) {
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[0][0][1].color[4] == blue && a[2][1][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[0][0][1].color[4] == blue && a[2][1][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[0][0][1].color[4] == blue && a[2][1][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[0][0][1].color[4] == blue && a[2][1][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[0][0][1].color[4] == blue && a[2][1][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[0][0][1].color[4] == blue && a[2][1][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[0][0][1].color[4] == red && a[2][1][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[0][0][1].color[4] == red && a[2][1][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[0][0][1].color[4] == red && a[2][1][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[0][0][1].color[4] == red && a[2][1][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[0][0][1].color[4] == red && a[2][1][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[0][0][1].color[4] == red && a[2][1][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[0][0][1].color[4] == orange && a[2][1][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[0][0][1].color[4] == orange && a[2][1][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[0][0][1].color[4] == orange && a[2][1][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[0][0][1].color[4] == orange && a[2][1][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[0][0][1].color[4] == orange && a[2][1][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[0][0][1].color[4] == orange && a[2][1][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[0][0][1].color[4] == green && a[2][1][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[0][0][1].color[4] == green && a[2][1][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[0][0][1].color[4] == green && a[2][1][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[0][0][1].color[4] == green && a[2][1][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[0][0][1].color[4] == green && a[2][1][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[0][0][1].color[4] == green && a[2][1][2].color[0] == red) {
					Rotate(1, 3);
				}
			}
			if (a[0][1][2].color[4] == white && a[1][0][2].color[2] == white && a[0][0][1].color[4] == white && a[2][1][2].color[5] == white) {
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[0][0][1].color[2] == blue && a[2][1][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[0][0][1].color[2] == blue && a[2][1][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[0][0][1].color[2] == blue && a[2][1][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[0][0][1].color[2] == blue && a[2][1][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[0][0][1].color[2] == blue && a[2][1][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[0][0][1].color[2] == blue && a[2][1][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[0][0][1].color[2] == red && a[2][1][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[0][0][1].color[2] == red && a[2][1][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[0][0][1].color[2] == red && a[2][1][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[0][0][1].color[2] == red && a[2][1][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[0][0][1].color[2] == red && a[2][1][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[0][0][1].color[2] == red && a[2][1][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[0][0][1].color[2] == orange && a[2][1][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[0][0][1].color[2] == orange && a[2][1][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[0][0][1].color[2] == orange && a[2][1][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[0][0][1].color[2] == orange && a[2][1][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[0][0][1].color[2] == orange && a[2][1][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[0][0][1].color[2] == orange && a[2][1][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[0][0][1].color[2] == green && a[2][1][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[0][0][1].color[2] == green && a[2][1][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[0][0][1].color[2] == green && a[2][1][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[0][0][1].color[2] == green && a[2][1][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[0][0][1].color[2] == green && a[2][1][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[0][0][1].color[2] == green && a[2][1][2].color[0] == red) {
					Rotate(1, 3);
				}
			}
			if (a[0][1][2].color[4] == white && a[1][0][2].color[2] == white && a[2][2][1].color[3] == white && a[2][1][2].color[5] == white) {
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[2][2][1].color[5] == blue && a[2][1][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[2][2][1].color[5] == blue && a[2][1][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[2][2][1].color[5] == blue && a[2][1][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[2][2][1].color[5] == blue && a[2][1][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[2][2][1].color[5] == blue && a[2][1][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[2][2][1].color[5] == blue && a[2][1][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[2][2][1].color[5] == red && a[2][1][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[2][2][1].color[5] == red && a[2][1][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[2][2][1].color[5] == red && a[2][1][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[2][2][1].color[5] == red && a[2][1][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[2][2][1].color[5] == red && a[2][1][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[2][2][1].color[5] == red && a[2][1][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[2][2][1].color[5] == orange && a[2][1][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[2][2][1].color[5] == orange && a[2][1][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[2][2][1].color[5] == orange && a[2][1][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[2][2][1].color[5] == orange && a[2][1][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[2][2][1].color[5] == orange && a[2][1][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[2][2][1].color[5] == orange && a[2][1][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[2][2][1].color[5] == green && a[2][1][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[2][2][1].color[5] == green && a[2][1][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[2][2][1].color[5] == green && a[2][1][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[2][2][1].color[5] == green && a[2][1][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[2][2][1].color[5] == green && a[2][1][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[2][2][1].color[5] == green && a[2][1][2].color[0] == red) {
					Rotate(1, -3);
				}
			}
			if (a[0][1][2].color[4] == white && a[1][0][2].color[2] == white && a[2][2][1].color[5] == white && a[2][1][2].color[5] == white) {
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[2][2][1].color[3] == blue && a[2][1][2].color[0] == orange) {
					Rotate(3, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[2][2][1].color[3] == blue && a[2][1][2].color[0] == red) {
					Rotate(3, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[2][2][1].color[3] == blue && a[2][1][2].color[0] == green) {
					Rotate(3, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[2][2][1].color[3] == blue && a[2][1][2].color[0] == red) {
					Rotate(3, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[2][2][1].color[3] == blue && a[2][1][2].color[0] == orange) {
					Rotate(3, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[2][2][1].color[3] == blue && a[2][1][2].color[0] == green) {
					Rotate(3, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[2][2][1].color[3] == red && a[2][1][2].color[0] == orange) {
					Rotate(3, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[2][2][1].color[3] == red && a[2][1][2].color[0] == blue) {
					Rotate(3, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[2][2][1].color[3] == red && a[2][1][2].color[0] == green) {
					Rotate(3, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[2][2][1].color[3] == red && a[2][1][2].color[0] == blue) {
					Rotate(3, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[2][2][1].color[3] == red && a[2][1][2].color[0] == orange) {
					Rotate(3, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[2][2][1].color[3] == red && a[2][1][2].color[0] == green) {
					Rotate(3, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[2][2][1].color[3] == orange && a[2][1][2].color[0] == red) {
					Rotate(3, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[2][2][1].color[3] == orange && a[2][1][2].color[0] == blue) {
					Rotate(3, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[2][2][1].color[3] == orange && a[2][1][2].color[0] == green) {
					Rotate(3, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[2][2][1].color[3] == orange && a[2][1][2].color[0] == blue) {
					Rotate(3, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[2][2][1].color[3] == orange && a[2][1][2].color[0] == red) {
					Rotate(3, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[2][2][1].color[3] == orange && a[2][1][2].color[0] == green) {
					Rotate(3, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[2][2][1].color[3] == green && a[2][1][2].color[0] == orange) {
					Rotate(3, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[2][2][1].color[3] == green && a[2][1][2].color[0] == blue) {
					Rotate(3, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[2][2][1].color[3] == green && a[2][1][2].color[0] == red) {
					Rotate(3, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[2][2][1].color[3] == green && a[2][1][2].color[0] == blue) {
					Rotate(3, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[2][2][1].color[3] == green && a[2][1][2].color[0] == orange) {
					Rotate(3, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[2][2][1].color[3] == green && a[2][1][2].color[0] == red) {
					Rotate(3, -3);
				}
			}
			if (a[0][1][2].color[4] == white && a[1][0][2].color[2] == white && a[1][2][0].color[3] == white && a[2][1][2].color[5] == white) {
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[1][2][0].color[1] == blue && a[2][1][2].color[0] == orange) {
					Rotate(3, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[1][2][0].color[1] == blue && a[2][1][2].color[0] == red) {
					Rotate(3, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[1][2][0].color[1] == blue && a[2][1][2].color[0] == green) {
					Rotate(3, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[1][2][0].color[1] == blue && a[2][1][2].color[0] == red) {
					Rotate(3, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[1][2][0].color[1] == blue && a[2][1][2].color[0] == orange) {
					Rotate(3, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[1][2][0].color[1] == blue && a[2][1][2].color[0] == green) {
					Rotate(3, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[1][2][0].color[1] == red && a[2][1][2].color[0] == orange) {
					Rotate(3, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[1][2][0].color[1] == red && a[2][1][2].color[0] == blue) {
					Rotate(3, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[1][2][0].color[1] == red && a[2][1][2].color[0] == green) {
					Rotate(3, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[1][2][0].color[1] == red && a[2][1][2].color[0] == blue) {
					Rotate(3, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[1][2][0].color[1] == red && a[2][1][2].color[0] == orange) {
					Rotate(3, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[1][2][0].color[1] == red && a[2][1][2].color[0] == green) {
					Rotate(3, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[1][2][0].color[1] == orange && a[2][1][2].color[0] == red) {
					Rotate(3, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[1][2][0].color[1] == orange && a[2][1][2].color[0] == blue) {
					Rotate(3, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[1][2][0].color[1] == orange && a[2][1][2].color[0] == green) {
					Rotate(3, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[1][2][0].color[1] == orange && a[2][1][2].color[0] == blue) {
					Rotate(3, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[1][2][0].color[1] == orange && a[2][1][2].color[0] == red) {
					Rotate(3, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[1][2][0].color[1] == orange && a[2][1][2].color[0] == green) {
					Rotate(3, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[1][2][0].color[1] == green && a[2][1][2].color[0] == orange) {
					Rotate(3, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[1][2][0].color[1] == green && a[2][1][2].color[0] == blue) {
					Rotate(3, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[1][2][0].color[1] == green && a[2][1][2].color[0] == red) {
					Rotate(3, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[1][2][0].color[1] == green && a[2][1][2].color[0] == blue) {
					Rotate(3, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[1][2][0].color[1] == green && a[2][1][2].color[0] == orange) {
					Rotate(3, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[1][2][0].color[1] == green && a[2][1][2].color[0] == red) {
					Rotate(3, -3);
				}
			}
			if (a[0][1][2].color[4] == white && a[1][0][2].color[2] == white && a[1][2][0].color[1] == white && a[2][1][2].color[5] == white) {
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[1][2][0].color[3] == blue && a[2][1][2].color[0] == orange) {
					Rotate(3, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[1][2][0].color[3] == blue && a[2][1][2].color[0] == red) {
					Rotate(3, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[1][2][0].color[3] == blue && a[2][1][2].color[0] == green) {
					Rotate(3, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[1][2][0].color[3] == blue && a[2][1][2].color[0] == red) {
					Rotate(3, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[1][2][0].color[3] == blue && a[2][1][2].color[0] == orange) {
					Rotate(3, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[1][2][0].color[3] == blue && a[2][1][2].color[0] == green) {
					Rotate(3, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[1][2][0].color[3] == red && a[2][1][2].color[0] == orange) {
					Rotate(3, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[1][2][0].color[3] == red && a[2][1][2].color[0] == blue) {
					Rotate(3, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[1][2][0].color[3] == red && a[2][1][2].color[0] == green) {
					Rotate(3, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[1][2][0].color[3] == red && a[2][1][2].color[0] == blue) {
					Rotate(3, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[1][2][0].color[3] == red && a[2][1][2].color[0] == orange) {
					Rotate(3, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[1][2][0].color[3] == red && a[2][1][2].color[0] == green) {
					Rotate(3, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[1][2][0].color[3] == orange && a[2][1][2].color[0] == red) {
					Rotate(3, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[1][2][0].color[3] == orange && a[2][1][2].color[0] == blue) {
					Rotate(3, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[1][2][0].color[3] == orange && a[2][1][2].color[0] == green) {
					Rotate(3, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[1][2][0].color[3] == orange && a[2][1][2].color[0] == blue) {
					Rotate(3, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[1][2][0].color[3] == orange && a[2][1][2].color[0] == red) {
					Rotate(3, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[1][2][0].color[3] == orange && a[2][1][2].color[0] == green) {
					Rotate(3, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[1][2][0].color[3] == green && a[2][1][2].color[0] == orange) {
					Rotate(3, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[1][2][0].color[3] == green && a[2][1][2].color[0] == blue) {
					Rotate(3, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[1][2][0].color[3] == green && a[2][1][2].color[0] == red) {
					Rotate(3, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[1][2][0].color[3] == green && a[2][1][2].color[0] == blue) {
					Rotate(3, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[1][2][0].color[3] == green && a[2][1][2].color[0] == orange) {
					Rotate(3, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[1][2][0].color[3] == green && a[2][1][2].color[0] == red) {
					Rotate(3, -3);
				}
			}
			if (a[0][1][2].color[4] == white && a[1][0][2].color[2] == white && a[0][2][1].color[3] == white && a[2][1][2].color[5] == white) {
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[0][2][1].color[4] == blue && a[2][1][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[0][2][1].color[4] == blue && a[2][1][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[0][2][1].color[4] == blue && a[2][1][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[0][2][1].color[4] == blue && a[2][1][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[0][2][1].color[4] == blue && a[2][1][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[0][2][1].color[4] == blue && a[2][1][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[0][2][1].color[4] == red && a[2][1][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[0][2][1].color[4] == red && a[2][1][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[0][2][1].color[4] == red && a[2][1][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[0][2][1].color[4] == red && a[2][1][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[0][2][1].color[4] == red && a[2][1][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[0][2][1].color[4] == red && a[2][1][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[0][2][1].color[4] == orange && a[2][1][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[0][2][1].color[4] == orange && a[2][1][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[0][2][1].color[4] == orange && a[2][1][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[0][2][1].color[4] == orange && a[2][1][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[0][2][1].color[4] == orange && a[2][1][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[0][2][1].color[4] == orange && a[2][1][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[0][2][1].color[4] == green && a[2][1][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[0][2][1].color[4] == green && a[2][1][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[0][2][1].color[4] == green && a[2][1][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[0][2][1].color[4] == green && a[2][1][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[0][2][1].color[4] == green && a[2][1][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[0][2][1].color[4] == green && a[2][1][2].color[0] == red) {
					Rotate(1, 3);
				}
			}
			if (a[0][1][2].color[4] == white && a[1][0][2].color[2] == white && a[0][2][1].color[4] == white && a[2][1][2].color[5] == white) {
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[0][2][1].color[3] == blue && a[2][1][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[0][2][1].color[3] == blue && a[2][1][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[0][2][1].color[3] == blue && a[2][1][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[0][2][1].color[3] == blue && a[2][1][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[0][2][1].color[3] == blue && a[2][1][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[0][2][1].color[3] == blue && a[2][1][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[0][2][1].color[3] == red && a[2][1][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[0][2][1].color[3] == red && a[2][1][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[0][2][1].color[3] == red && a[2][1][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[0][2][1].color[3] == red && a[2][1][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[0][2][1].color[3] == red && a[2][1][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[0][2][1].color[3] == red && a[2][1][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[0][2][1].color[3] == orange && a[2][1][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[0][2][1].color[3] == orange && a[2][1][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[0][2][1].color[3] == orange && a[2][1][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[0][2][1].color[3] == orange && a[2][1][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[0][2][1].color[3] == orange && a[2][1][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[0][2][1].color[3] == orange && a[2][1][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[0][2][1].color[3] == green && a[2][1][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[0][2][1].color[3] == green && a[2][1][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[0][2][1].color[3] == green && a[2][1][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[0][2][1].color[3] == green && a[2][1][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[0][2][1].color[3] == green && a[2][1][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[0][2][1].color[3] == green && a[2][1][2].color[0] == red) {
					Rotate(1, 3);
				}
			}
			if (a[0][1][2].color[4] == white && a[1][0][2].color[2] == white && a[0][1][0].color[4] == white && a[2][1][2].color[5] == white) {
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[0][1][0].color[1] == blue && a[2][1][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[0][1][0].color[1] == blue && a[2][1][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[0][1][0].color[1] == blue && a[2][1][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[0][1][0].color[1] == blue && a[2][1][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[0][1][0].color[1] == blue && a[2][1][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[0][1][0].color[1] == blue && a[2][1][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[0][1][0].color[1] == red && a[2][1][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[0][1][0].color[1] == red && a[2][1][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[0][1][0].color[1] == red && a[2][1][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[0][1][0].color[1] == red && a[2][1][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[0][1][0].color[1] == red && a[2][1][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[0][1][0].color[1] == red && a[2][1][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[0][1][0].color[1] == orange && a[2][1][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[0][1][0].color[1] == orange && a[2][1][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[0][1][0].color[1] == orange && a[2][1][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[0][1][0].color[1] == orange && a[2][1][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[0][1][0].color[1] == orange && a[2][1][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[0][1][0].color[1] == orange && a[2][1][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[0][1][0].color[1] == green && a[2][1][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[0][1][0].color[1] == green && a[2][1][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[0][1][0].color[1] == green && a[2][1][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[0][1][0].color[1] == green && a[2][1][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[0][1][0].color[1] == green && a[2][1][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[0][1][0].color[1] == green && a[2][1][2].color[0] == red) {
					Rotate(1, 3);
				}
			}
			if (a[0][1][2].color[4] == white && a[1][0][2].color[2] == white && a[0][1][0].color[1] == white && a[2][1][2].color[5] == white) {
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[0][1][0].color[4] == blue && a[2][1][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[0][1][0].color[4] == blue && a[2][1][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[0][1][0].color[4] == blue && a[2][1][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[0][1][0].color[4] == blue && a[2][1][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[0][1][0].color[4] == blue && a[2][1][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[0][1][0].color[4] == blue && a[2][1][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[0][1][0].color[4] == red && a[2][1][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[0][1][0].color[4] == red && a[2][1][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[0][1][0].color[4] == red && a[2][1][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[0][1][0].color[4] == red && a[2][1][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[0][1][0].color[4] == red && a[2][1][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[0][1][0].color[4] == red && a[2][1][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[0][1][0].color[4] == orange && a[2][1][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[0][1][0].color[4] == orange && a[2][1][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[0][1][0].color[4] == orange && a[2][1][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[0][1][0].color[4] == orange && a[2][1][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[0][1][0].color[4] == orange && a[2][1][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[0][1][0].color[4] == orange && a[2][1][2].color[0] == green) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[0][1][0].color[4] == green && a[2][1][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[0][1][0].color[4] == green && a[2][1][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[0][1][0].color[4] == green && a[2][1][2].color[0] == red) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[0][1][0].color[4] == green && a[2][1][2].color[0] == blue) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[0][1][0].color[4] == green && a[2][1][2].color[0] == orange) {
					Rotate(1, 3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[0][1][0].color[4] == green && a[2][1][2].color[0] == red) {
					Rotate(1, 3);
				}
			}
			if (a[0][1][2].color[4] == white && a[1][0][2].color[2] == white && a[2][1][0].color[5] == white && a[2][1][2].color[5] == white) {
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[2][1][0].color[1] == blue && a[2][1][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[2][1][0].color[1] == blue && a[2][1][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[2][1][0].color[1] == blue && a[2][1][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[2][1][0].color[1] == blue && a[2][1][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[2][1][0].color[1] == blue && a[2][1][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[2][1][0].color[1] == blue && a[2][1][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[2][1][0].color[1] == red && a[2][1][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[2][1][0].color[1] == red && a[2][1][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[2][1][0].color[1] == red && a[2][1][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[2][1][0].color[1] == red && a[2][1][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[2][1][0].color[1] == red && a[2][1][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[2][1][0].color[1] == red && a[2][1][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[2][1][0].color[1] == orange && a[2][1][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[2][1][0].color[1] == orange && a[2][1][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[2][1][0].color[1] == orange && a[2][1][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[2][1][0].color[1] == orange && a[2][1][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[2][1][0].color[1] == orange && a[2][1][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[2][1][0].color[1] == orange && a[2][1][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[2][1][0].color[1] == green && a[2][1][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[2][1][0].color[1] == green && a[2][1][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[2][1][0].color[1] == green && a[2][1][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[2][1][0].color[1] == green && a[2][1][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[2][1][0].color[1] == green && a[2][1][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[2][1][0].color[1] == green && a[2][1][2].color[0] == red) {
					Rotate(1, -3);
				}
			}
			if (a[0][1][2].color[4] == white && a[1][0][2].color[2] == white && a[2][1][0].color[1] == white && a[2][1][2].color[5] == white) {
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[2][1][0].color[5] == blue && a[2][1][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[2][1][0].color[5] == blue && a[2][1][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[2][1][0].color[5] == blue && a[2][1][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[2][1][0].color[5] == blue && a[2][1][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[2][1][0].color[5] == blue && a[2][1][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[2][1][0].color[5] == blue && a[2][1][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[2][1][0].color[5] == red && a[2][1][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[2][1][0].color[5] == red && a[2][1][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[2][1][0].color[5] == red && a[2][1][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[2][1][0].color[5] == red && a[2][1][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[2][1][0].color[5] == red && a[2][1][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[2][1][0].color[5] == red && a[2][1][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[2][1][0].color[5] == orange && a[2][1][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[2][1][0].color[5] == orange && a[2][1][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[2][1][0].color[5] == orange && a[2][1][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[2][1][0].color[5] == orange && a[2][1][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[2][1][0].color[5] == orange && a[2][1][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[2][1][0].color[5] == orange && a[2][1][2].color[0] == green) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[2][1][0].color[5] == green && a[2][1][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[2][1][0].color[5] == green && a[2][1][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[2][1][0].color[5] == green && a[2][1][2].color[0] == red) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[2][1][0].color[5] == green && a[2][1][2].color[0] == blue) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[2][1][0].color[5] == green && a[2][1][2].color[0] == orange) {
					Rotate(1, -3);
				}
				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[2][1][0].color[5] == green && a[2][1][2].color[0] == red) {
					Rotate(1, -3);
				}
			}
			//собрано 0 наверху, но есть 2 белых вертикально
			if (a[1][0][2].color[2] == white && a[1][2][2].color[3] == white && (a[0][1][2].color[0] != white && a[0][1][2].color[4] != white) && (a[2][1][2].color[0] != white && a[2][1][2].color[5] != white)) {
				//для синей грани
				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
					Rotate(1, -3);
				}
				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
					Rotate(1, -3);
				}
				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
					Rotate(1, -3);
				}
				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
					Rotate(1, -3);
				}
				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
					Rotate(1, -3);
				}
				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
					Rotate(1, -3);
				}
				//для зеленой грани
				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
					Rotate(1, -3);
				}
				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
					Rotate(1, -3);
				}
				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
					Rotate(1, -3);
				}
				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
					Rotate(1, -3);
				}
				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
					Rotate(1, -3);
				}
				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
					Rotate(1, -3);
				}
				//для красной
				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
					Rotate(4, -3);
				}
				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
					Rotate(4, -3);
				}
				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
					Rotate(4, -3);
				}
				if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
					Rotate(4, -3);
				}
				if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
					Rotate(4, -3);
				}
				if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
					Rotate(4, -3);
				}
				//для оранжевой
				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
					Rotate(5, -3);
				}
				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
					Rotate(5, -3);
				}
				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
					Rotate(5, -3);
				}
				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
					Rotate(5, -3);
				}
				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
					Rotate(5, -3);
				}
				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
					Rotate(5, -3);
				}
			}
			//собрано 0 наверху, но есть 2 белых горизонтально
			if (a[0][1][2].color[4] == white && a[2][1][2].color[5] == white && (a[1][0][2].color[0] != white && a[1][0][2].color[2] != white) && (a[1][2][2].color[0] != white && a[1][2][2].color[3] != white)) {
				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
					Rotate(2, -3);
				}
				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
					Rotate(2, -3);
				}
				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
					Rotate(2, -3);
				}
				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
					Rotate(2, -3);
				}
				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
					Rotate(2, -3);
				}
				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
					Rotate(2, -3);
				}
				//для зеленой грани
				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
					Rotate(3, -3);
				}
				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
					Rotate(3, -3);
				}
				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
					Rotate(3, -3);
				}
				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
					Rotate(3, -3);
				}
				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
					Rotate(3, -3);
				}
				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
					Rotate(3, -3);
				}
				//для красной
				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
					Rotate(1, -3);
				}
				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
					Rotate(1, -3);
				}
				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
					Rotate(1, -3);
				}
				if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
					Rotate(1, -3);
				}
				if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
					Rotate(1, -3);
				}
				if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
					Rotate(1, -3);
				}
				//для оранжевой
				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
					Rotate(1, -3);
				}
				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
					Rotate(1, -3);
				}
				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
					Rotate(1, -3);
				}
				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
					Rotate(1, -3);
				}
				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
					Rotate(1, -3);
				}
				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
					Rotate(1, -3);
				}
			}

			//2 белых левыи нижним уголком 
			if (((a[0][1][2].color[4] == white && a[1][0][2].color[2] == white) || (a[0][1][2].color[0] == white && a[1][0][2].color[0] == white) || (a[0][1][2].color[4] == white && a[1][0][2].color[0] == white) || (a[0][1][2].color[0] == white && a[1][0][2].color[2] == white)) && (a[2][1][2].color[0] != white && a[2][1][2].color[5] != white) && (a[1][2][2].color[0] != white && a[1][2][2].color[3] != white)) {
				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
					if (a[0][1][0].color[4] || a[0][1][0].color[1] == white) {
						Rotate(1, -3);
					}
				}
				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
					Rotate(1, -3);
				}
				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
					Rotate(1, -3);
				}
				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
					Rotate(1, -3);
				}
				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
					if (a[0][1][0].color[4] || a[0][1][0].color[1] == white) {
						Rotate(1, -3);
					}
				}
				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
					if (a[0][1][0].color[4] || a[0][1][0].color[1] == white) {
						Rotate(1, -3);
					}
				}
				//для зеленой грани
				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
					Rotate(3, -3);
				}
				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
					Rotate(3, -3);
				}
				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
					Rotate(3, -3);
				}
				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
					Rotate(3, -3);
				}
				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
					Rotate(3, -3);
				}
				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
					Rotate(3, -3);
				}
				//для красной
				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
					Rotate(1, 3);
				}
				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
					Rotate(1, 3);
				}
				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
					Rotate(1, 3);
				}
				if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
					Rotate(1, 3);
				}
				if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
					Rotate(1, 3);
				}
				/*if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
					Rotate(1, 3);
				}*/
				//для оранжевой
				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
					Rotate(5, -3);
				}
				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
					Rotate(5, -3);
				}
				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
					Rotate(5, -3);
				}
				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
					Rotate(5, -3);
				}
				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
					Rotate(5, -3);
				}
				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
					Rotate(5, -3);
				}
			}
			//2 белых правым нижним уголком 
			if (((a[2][1][2].color[5] == white && a[1][0][2].color[2] == white) || (a[2][1][2].color[0] == white && a[1][0][2].color[0] == white) || (a[2][1][2].color[5] == white && a[1][0][2].color[0] == white) || (a[2][1][2].color[0] == white && a[1][0][2].color[2] == white)) && (a[0][1][2].color[0] != white && a[0][1][2].color[4] != white) && (a[1][2][2].color[0] != white && a[1][2][2].color[3] != white)) {
				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
					if (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white) {
						Rotate(1, 3);
					}
				}
				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
					Rotate(1, 3);
				}
				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
					Rotate(1, 3);
				}
				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
					Rotate(1, 3);
				}
				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
					if (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white) {
						Rotate(1, 3);
					}
				}
				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
					if (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white) {
						Rotate(1, 3);
					}
				}
				//для зеленой грани
				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
					Rotate(3, -3);
				}
				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
					Rotate(3, -3);
				}
				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
					Rotate(3, -3);
				}
				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
					Rotate(3, -3);
				}
				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
					Rotate(3, -3);
				}
				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
					Rotate(3, -3);
				}
				//для красной
				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
					Rotate(4, -3);
				}
				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
					Rotate(4, -3);
				}
				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
					Rotate(4, -3);
				}
				if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
					Rotate(4, -3);
				}
				if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
					Rotate(4, -3);
				}
				if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
					Rotate(4, -3);
				}
				//для оранжевой
				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
					Rotate(1, -3);
				}
				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
					Rotate(1, -3);
				}
				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
					Rotate(1, -3);
				}
				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
					Rotate(1, -3);
				}
				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
					Rotate(1, -3);
				}
				/*if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
					Rotate(1, -3);
				}*/
			}
			//2 белых правым верхним уголком 
			if (((a[2][1][2].color[5] == white && a[1][2][2].color[3] == white) || (a[2][1][2].color[0] == white && a[1][2][2].color[0] == white) || (a[2][1][2].color[0] == white && a[1][2][2].color[3] == white) || (a[2][1][2].color[5] == white && a[1][2][2].color[0] == white)) && (a[0][1][2].color[0] != white && a[0][1][2].color[4] != white) && (a[1][0][2].color[0] != white && a[1][0][2].color[2] != white)) {
				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
					Rotate(2, -3);
				}
				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
					Rotate(2, -3);
				}
				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
					Rotate(2, -3);
				}
				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
					Rotate(2, -3);
				}
				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
					Rotate(2, -3);
				}
				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
					Rotate(2, -3);
				}
				//для зеленой грани
				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
					if (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white) {
						Rotate(1, -3);
					}
				}
				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
					Rotate(1, -3);
				}
				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
					Rotate(1, -3);
				}
				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
					Rotate(1, -3);
				}
				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
					if (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white) {
						Rotate(1, -3);
					}
				}
				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
					if (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white) {
						Rotate(1, -3);
					}
				}
				//для красной
				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
					Rotate(4, -3);
				}
				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
					Rotate(4, -3);
				}
				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
					Rotate(4, -3);
				}
				if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
					Rotate(4, -3);
				}
				if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
					Rotate(4, -3);
				}
				if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
					Rotate(4, -3);
				}
				//для оранжевой
				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
					Rotate(1, 3);
				}
				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
					Rotate(1, 3);
				}
				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
					Rotate(1, 3);
				}
				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
					Rotate(1, 3);
				}
				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
					Rotate(1, 3);
				}
				/*if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
					Rotate(1, 3);
				}*/
			}
			//2 белых левым верхним уголком 
			if (((a[0][1][2].color[4] == white && a[1][2][2].color[3] == white) || (a[0][1][2].color[0] == white && a[1][2][2].color[0] == white) || (a[0][1][2].color[4] == white && a[1][2][2].color[0] == white) || (a[0][1][2].color[0] == white && a[1][2][2].color[3] == white)) && (a[2][1][2].color[0] != white && a[2][1][2].color[5] != white) && (a[1][0][2].color[0] != white && a[1][0][2].color[2] != white)) {
				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
					Rotate(2, -3);
				}
				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
					Rotate(2, -3);
				}
				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
					Rotate(2, -3);
				}
				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
					Rotate(2, -3);
				}
				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
					Rotate(2, -3);
				}
				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
					Rotate(2, -3);
				}
				//для зеленой грани
				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
					if (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white) {
						Rotate(1, 3);
					}
				}
				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
					Rotate(1, 3);
				}
				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
					Rotate(1, 3);
				}
				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
					Rotate(1, 3);
				}
				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
					if (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white) {
						Rotate(1, 3);
					}
				}
				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
					if (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white) {
						Rotate(1, 3);
					}
				}
				//для красной
				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
					Rotate(1, -3);
				}
				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
					Rotate(1, -3);
				}
				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
					Rotate(1, -3);
				}
				if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
					Rotate(1, -3);
				}
				if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
					Rotate(1, -3);
				}
				/*if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
					Rotate(1, -3);
				}*/
				//для оранжевой
				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
					Rotate(5, -3);
				}
				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
					Rotate(5, -3);
				}
				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
					Rotate(5, -3);
				}
				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
					Rotate(5, -3);
				}
				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
					Rotate(5, -3);
				}
				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
					Rotate(5, -3);
				}
			}
			//1 нижний правильно 2 неправильно горизонтально кроме верхней 
			if (a[1][0][2].color[0] == white && a[0][1][2].color[4] == white && a[2][1][2].color[5] == white && (a[1][2][2].color[0] != white && a[1][2][2].color[3] != white)) {
				if (a[2][0][1].color[2] == white || a[2][0][1].color[5] == white) {
					Rotate(1, -3);
				}
				if (a[0][0][1].color[2] == white || a[0][0][1].color[4] == white) {
					Rotate(1, 3);
				}
				if (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white) {
					Rotate(1, -3);
				}
				if (a[2][2][1].color[3] == white || a[2][2][1].color[5] == white) {
					Rotate(3, -3);
				}
				if (a[0][2][1].color[3] == white || a[0][2][1].color[4] == white) {
					Rotate(3, 3);
				}
				if (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white) {
					Rotate(3, -3);
				}
				if (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white) {
					Rotate(1, 3);
				}
				if (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white) {
					Rotate(1, -3);
				}
			}
			//1 нижний правильно 2 неправильно левым уголком кроме правой 
			if (a[1][0][2].color[0] == white && a[0][1][2].color[4] == white && a[1][2][2].color[3] == white && (a[2][1][2].color[0] != white && a[2][1][2].color[5] != white)) {
				if (a[2][0][1].color[2] == white || a[2][0][1].color[5] == white) {
					Rotate(1, -3);
				}
				if (a[0][0][1].color[2] == white || a[0][0][1].color[4] == white) {
					Rotate(1, -3);
				}
				if (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white) {
					Rotate(1, -3);
				}
				if (a[2][2][1].color[3] == white || a[2][2][1].color[5] == white) {
					Rotate(1, 3);
				}
				if (a[0][2][1].color[3] == white || a[0][2][1].color[4] == white) {
					Rotate(1, 3);
				}
				if (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white) {
					Rotate(1, 3);
				}
				if (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white) {
					Rotate(1, 3);
				}
				if (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white) {
					Rotate(5, -3);
				}
			}
			//1 нижний правильно 2 неправильно правым уголком кроме левой 
			if (a[1][0][2].color[0] == white && a[2][1][2].color[5] == white && a[1][2][2].color[3] == white && (a[0][1][2].color[0] != white && a[0][1][2].color[4] != white)) {
				if (a[2][0][1].color[2] == white || a[2][0][1].color[5] == white) {
					Rotate(1, 3);
				}
				if (a[0][0][1].color[2] == white || a[0][0][1].color[4] == white) {
					Rotate(1, 3);
				}
				if (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white) {
					Rotate(1, 3);
				}
				if (a[2][2][1].color[3] == white || a[2][2][1].color[5] == white) {
					Rotate(1, -3);
				}
				if (a[0][2][1].color[3] == white || a[0][2][1].color[4] == white) {
					Rotate(1, -3);
				}
				if (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white) {
					Rotate(1, -3);
				}
				if (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white) {
					Rotate(4, -3);
				}
				if (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white) {
					Rotate(1, -3);
				}
			}
			//1 левый правильно 2 неправильно вертикально кроме правой 
			if (a[0][1][2].color[0] == white && a[1][2][2].color[3] == white && a[1][0][2].color[2] == white && (a[2][1][2].color[0] != white && a[2][1][2].color[5] != white)) {
				if (a[2][0][1].color[2] == white || a[2][0][1].color[5] == white) {
					Rotate(1, -3);
				}
				if (a[0][0][1].color[2] == white || a[0][0][1].color[4] == white) {
					Rotate(1, -3);
				}
				if (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white) {
					Rotate(1, -3);
				}
				if (a[2][2][1].color[3] == white || a[2][2][1].color[5] == white) {
					Rotate(1, 3);
				}
				if (a[0][2][1].color[3] == white || a[0][2][1].color[4] == white) {
					Rotate(1, 3);
				}
				if (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white) {
					Rotate(1, 3);
				}
				if (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white) {
					Rotate(1, 3);
				}
				if (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white) {
					Rotate(5, 3);
				}
			}
			//1 левый правильно 2 неправильно правый верхний уголок кроме нижней 
			if (a[0][1][2].color[0] == white && a[1][2][2].color[3] == white && a[2][1][2].color[5] == white && (a[1][0][2].color[0] != white && a[1][0][2].color[2] != white)) {
				if (a[2][0][1].color[2] == white || a[2][0][1].color[5] == white) {
					Rotate(2, -3);
				}
				if (a[0][0][1].color[2] == white || a[0][0][1].color[4] == white) {
					Rotate(2, -3);
				}
				if (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white) {
					Rotate(2, -3);
				}
				if (a[2][2][1].color[3] == white || a[2][2][1].color[5] == white) {
					Rotate(1, 3);
				}
				if (a[0][2][1].color[3] == white || a[0][2][1].color[4] == white) {
					Rotate(1, 3);
				}
				if (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white) {
					Rotate(1, 3);
				}
				if (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white) {
					Rotate(1, -3);
				}
				if (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white) {
					Rotate(1, 3);
				}
			}
			//1 левый правильно 2 неправильно правый нижний уголок кроме верхней 
			if (a[0][1][2].color[0] == white && a[2][1][2].color[5] == white && a[1][0][2].color[2] == white && (a[1][2][2].color[0] != white && a[1][2][2].color[3] != white)) {
				if (a[2][0][1].color[2] == white || a[2][0][1].color[5] == white) {
					Rotate(1, -3);
				}
				if (a[0][0][1].color[2] == white || a[0][0][1].color[4] == white) {
					Rotate(1, -3);
				}
				if (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white) {
					Rotate(1, -3);
				}
				if (a[2][2][1].color[3] == white || a[2][2][1].color[5] == white) {
					Rotate(3, -3);
				}
				if (a[0][2][1].color[3] == white || a[0][2][1].color[4] == white) {
					Rotate(3, -3);
				}
				if (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white) {
					Rotate(3, -3);
				}
				if (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white) {
					Rotate(1, 3);
				}
				if (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white) {
					Rotate(1, -3);
				}
			}
			//1 верхний правильно 2 неправильно горизонтально кроме нижней
			if (a[0][1][2].color[4] == white && a[1][2][2].color[0] == white && a[2][1][2].color[5] == white && (a[1][0][2].color[0] != white && a[1][0][2].color[2] != white)) {
				if (a[2][0][1].color[2] == white || a[2][0][1].color[5] == white) {
					Rotate(2, -3);
				}
				if (a[0][0][1].color[2] == white || a[0][0][1].color[4] == white) {
					Rotate(2, 3);
				}
				if (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white) {
					Rotate(2, -3);
				}
				if (a[2][2][1].color[3] == white || a[2][2][1].color[5] == white) {
					Rotate(1, -3);
				}
				if (a[0][2][1].color[3] == white || a[0][2][1].color[4] == white) {
					Rotate(1, -3);
				}
				if (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white) {
					Rotate(1, -3);
				}
				if (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white) {
					Rotate(1, -3);
				}
				if (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white) {
					Rotate(1, 3);
				}
			}
			//1 верхний правильно 2 неправильно правый нижний угол кроме левой
			if (a[2][1][2].color[5] == white && a[1][2][2].color[0] == white && a[1][0][2].color[2] == white && (a[0][1][2].color[0] != white && a[0][1][2].color[4] != white)) {
				if (a[2][0][1].color[2] == white || a[2][0][1].color[5] == white) {
					Rotate(1, 3);
				}
				if (a[0][0][1].color[2] == white || a[0][0][1].color[4] == white) {
					Rotate(1, 3);
				}
				if (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white) {
					Rotate(1, 3);
				}
				if (a[2][2][1].color[3] == white || a[2][2][1].color[5] == white) {
					Rotate(1, -3);
				}
				if (a[0][2][1].color[3] == white || a[0][2][1].color[4] == white) {
					Rotate(1, -3);
				}
				if (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white) {
					Rotate(1, -3);
				}
				if (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white) {
					Rotate(4, -3);
				}
				if (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white) {
					Rotate(1, 3);
				}
			}
			//1 верхний правильно 2 неправильно левый нижний угол кроме правой
			if (a[0][1][2].color[4] == white && a[1][2][2].color[0] == white && a[1][0][2].color[2] == white && (a[2][1][2].color[0] != white && a[2][1][2].color[5] != white)) {
				if (a[2][0][1].color[2] == white || a[2][0][1].color[5] == white) {
					Rotate(1, -3);
				}
				if (a[0][0][1].color[2] == white || a[0][0][1].color[4] == white) {
					Rotate(1, -3);
				}
				if (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white) {
					Rotate(1, -3);
				}
				if (a[2][2][1].color[3] == white || a[2][2][1].color[5] == white) {
					Rotate(1, 3);
				}
				if (a[0][2][1].color[3] == white || a[0][2][1].color[4] == white) {
					Rotate(1, 3);
				}
				if (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white) {
					Rotate(1, 3);
				}
				if (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white) {
					Rotate(1, 3);
				}
				if (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white) {
					Rotate(5, -3);
				}
			}
			//1 правый правильно 2 неправильно вертикально кроме левой
			if (a[1][0][2].color[2] == white && a[1][2][2].color[3] == white && a[2][1][2].color[0] == white && (a[0][1][2].color[0] != white && a[0][1][2].color[4] != white)) {
				if (a[2][0][1].color[2] == white || a[2][0][1].color[5] == white) {
					Rotate(1, 3);
				}
				if (a[0][0][1].color[2] == white || a[0][0][1].color[4] == white) {
					Rotate(1, 3);
				}
				if (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white) {
					Rotate(1, 3);
				}
				if (a[2][2][1].color[3] == white || a[2][2][1].color[5] == white) {
					Rotate(1, -3);
				}
				if (a[0][2][1].color[3] == white || a[0][2][1].color[4] == white) {
					Rotate(1, -3);
				}
				if (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white) {
					Rotate(1, -3);
				}
				if (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white) {
					Rotate(4, 3);
				}
				if (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white) {
					Rotate(1, 3);
				}
			}
			//1 правый правильно 2 неправильно левый нижний уголок кроме верхней
			if (a[1][0][2].color[2] == white && a[0][1][2].color[4] == white && a[2][1][2].color[0] == white && (a[1][2][2].color[0] != white && a[1][2][2].color[3] != white)) {
				if (a[2][0][1].color[2] == white || a[2][0][1].color[5] == white) {
					Rotate(1, 3);
				}
				if (a[0][0][1].color[2] == white || a[0][0][1].color[4] == white) {
					Rotate(1, 3);
				}
				if (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white) {
					Rotate(1, 3);
				}
				if (a[2][2][1].color[3] == white || a[2][2][1].color[5] == white) {
					Rotate(3, -3);
				}
				if (a[0][2][1].color[3] == white || a[0][2][1].color[4] == white) {
					Rotate(3, -3);
				}
				if (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white) {
					Rotate(3, -3);
				}
				if (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white) {
					Rotate(1, 3);
				}
				if (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white) {
					Rotate(1, -3);
				}
			}
			//1 правый правильно 2 неправильно левый верхний уголок кроме нижней
			if (a[1][2][2].color[3] == white && a[0][1][2].color[4] == white && a[2][1][2].color[0] == white && (a[1][0][2].color[0] != white && a[1][0][2].color[2] != white)) {
				if (a[2][0][1].color[2] == white || a[2][0][1].color[5] == white) {
					Rotate(2, -3);
				}
				if (a[0][0][1].color[2] == white || a[0][0][1].color[4] == white) {
					Rotate(2, 3);
				}
				if (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white) {
					Rotate(2, -3);
				}
				if (a[2][2][1].color[3] == white || a[2][2][1].color[5] == white) {
					Rotate(1, 3);
				}
				if (a[0][2][1].color[3] == white || a[0][2][1].color[4] == white) {
					Rotate(1, 3);
				}
				if (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white) {
					Rotate(1, 3);
				}
				if (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white) {
					Rotate(1, -3);
				}
				if (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white) {
					Rotate(1, 3);
				}
			}
			//собрано только 2 наверху вертикаль
			if (((a[1][0][2].color[0] == white && a[1][2][2].color[0] == white) || (a[1][0][2].color[2] == white && a[1][2][2].color[0] == white) || (a[1][0][2].color[0] == white && a[1][2][2].color[3] == white)) && (a[0][1][2].color[0] != white && a[0][1][2].color[4] != white) && (a[2][1][2].color[0] != white && a[2][1][2].color[5] != white)) {
				//для синей грани
				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
					Rotate(1, -3);
				}
				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
					Rotate(1, -3);
				}
				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
					Rotate(1, -3);
				}
				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
					Rotate(1, -3);
				}
				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
					Rotate(1, -3);
				}
				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
					Rotate(1, -3);
				}
				//для зеленой грани
				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
					Rotate(1, -3);
				}
				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
					Rotate(1, -3);
				}
				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
					Rotate(1, -3);
				}
				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
					Rotate(1, -3);
				}
				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
					Rotate(1, -3);
				}
				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
					Rotate(1, -3);
				}
				//для красной
				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
					Rotate(4, -3);
				}
				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
					Rotate(4, -3);
				}
				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
					Rotate(4, -3);
				}
				if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
					Rotate(4, -3);
				}
				if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
					Rotate(4, -3);
				}
				if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
					Rotate(4, -3);
				}
				//для оранжевой
				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
					Rotate(5, -3);
				}
				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
					Rotate(5, -3);
				}
				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
					Rotate(5, -3);
				}
				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
					Rotate(5, -3);
				}
				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
					Rotate(5, -3);
				}
				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
					Rotate(5, -3);
				}
			}
			//собрано только 2 наверху горизонт
			if (((a[0][1][2].color[0] == white && a[2][1][2].color[0] == white) || (a[0][1][2].color[4] == white && a[2][1][2].color[0] == white) || (a[0][1][2].color[0] == white && a[2][1][2].color[5] == white)) && (a[1][0][2].color[0] != white && a[1][0][2].color[2] != white) && (a[1][2][2].color[0] != white && a[1][2][2].color[3] != white)) {
				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
					Rotate(2, -3);
				}
				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
					Rotate(2, -3);
				}
				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
					Rotate(2, -3);
				}
				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
					Rotate(2, -3);
				}
				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
					Rotate(2, -3);
				}
				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
					Rotate(2, -3);
				}
				//для зеленой грани
				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
					Rotate(3, -3);
				}
				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
					Rotate(3, -3);
				}
				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
					Rotate(3, -3);
				}
				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
					Rotate(3, -3);
				}
				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
					Rotate(3, -3);
				}
				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
					Rotate(3, -3);
				}
				//для красной
				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
					Rotate(1, -3);
				}
				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
					Rotate(1, -3);
				}
				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
					Rotate(1, -3);
				}
				if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
					Rotate(1, -3);
				}
				if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
					Rotate(1, -3);
				}
				if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
					Rotate(1, -3);
				}
				//для оранжевой
				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
					Rotate(1, -3);
				}
				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
					Rotate(1, -3);
				}
				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
					Rotate(1, -3);
				}
				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
					Rotate(1, -3);
				}
				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
					Rotate(1, -3);
				}
				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
					Rotate(1, -3);
				}
			}
			//1 нижний неправильно 2 правильно горизонтально кроме верхней 
			if (a[1][0][2].color[2] == white && a[0][1][2].color[0] == white && a[2][1][2].color[0] == white && (a[1][2][2].color[0] != white && a[1][2][2].color[3] != white)) {
				if (a[2][0][1].color[2] == white || a[2][0][1].color[5] == white) {
					Rotate(1, -3);
				}
				if (a[0][0][1].color[2] == white || a[0][0][1].color[4] == white) {
					Rotate(1, 3);
				}
				if (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white) {
					Rotate(1, -3);
				}
				if (a[2][2][1].color[3] == white || a[2][2][1].color[5] == white) {
					Rotate(3, -3);
				}
				if (a[0][2][1].color[3] == white || a[0][2][1].color[4] == white) {
					Rotate(3, 3);
				}
				if (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white) {
					Rotate(3, -3);
				}
				if (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white) {
					Rotate(1, 3);
				}
				if (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white) {
					Rotate(1, -3);
				}
			}
			//1 нижний правильно 2 неправильно левым уголком кроме правой 
			if (a[1][0][2].color[2] == white && a[0][1][2].color[0] == white && a[1][2][2].color[0] == white && (a[2][1][2].color[0] != white && a[2][1][2].color[5] != white)) {
				if (a[2][0][1].color[2] == white || a[2][0][1].color[5] == white) {
					Rotate(1, -3);
				}
				if (a[0][0][1].color[2] == white || a[0][0][1].color[4] == white) {
					Rotate(1, -3);
				}
				if (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white) {
					Rotate(1, -3);
				}
				if (a[2][2][1].color[3] == white || a[2][2][1].color[5] == white) {
					Rotate(1, 3);
				}
				if (a[0][2][1].color[3] == white || a[0][2][1].color[4] == white) {
					Rotate(1, 3);
				}
				if (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white) {
					Rotate(1, 3);
				}
				if (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white) {
					Rotate(1, 3);
				}
				if (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white) {
					Rotate(5, -3);
				}
			}
			//1 нижний правильно 2 неправильно правым уголком кроме левой 
			if (a[1][0][2].color[2] == white && a[2][1][2].color[0] == white && a[1][2][2].color[0] == white && (a[0][1][2].color[0] != white && a[0][1][2].color[4] != white)) {
				if (a[2][0][1].color[2] == white || a[2][0][1].color[5] == white) {
					Rotate(1, 3);
				}
				if (a[0][0][1].color[2] == white || a[0][0][1].color[4] == white) {
					Rotate(1, 3);
				}
				if (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white) {
					Rotate(1, 3);
				}
				if (a[2][2][1].color[3] == white || a[2][2][1].color[5] == white) {
					Rotate(1, -3);
				}
				if (a[0][2][1].color[3] == white || a[0][2][1].color[4] == white) {
					Rotate(1, -3);
				}
				if (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white) {
					Rotate(1, -3);
				}
				if (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white) {
					Rotate(4, -3);
				}
				if (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white) {
					Rotate(1, -3);
				}
			}
			//1 левый неправильно 2 правильно вертикально кроме правой 
			if (a[0][1][2].color[4] == white && a[1][2][2].color[0] == white && a[1][0][2].color[0] == white && (a[2][1][2].color[0] != white && a[2][1][2].color[5] != white)) {
				if (a[2][0][1].color[2] == white || a[2][0][1].color[5] == white) {
					Rotate(1, -3);
				}
				if (a[0][0][1].color[2] == white || a[0][0][1].color[4] == white) {
					Rotate(1, -3);
				}
				if (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white) {
					Rotate(1, -3);
				}
				if (a[2][2][1].color[3] == white || a[2][2][1].color[5] == white) {
					Rotate(1, 3);
				}
				if (a[0][2][1].color[3] == white || a[0][2][1].color[4] == white) {
					Rotate(1, 3);
				}
				if (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white) {
					Rotate(1, 3);
				}
				if (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white) {
					Rotate(1, 3);
				}
				if (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white) {
					Rotate(5, 3);
				}
			}
			//1 левый правильно 2 неправильно правый верхний уголок кроме нижней 
			if (a[0][1][2].color[4] == white && a[1][2][2].color[0] == white && a[2][1][2].color[0] == white && (a[1][0][2].color[0] != white && a[1][0][2].color[2] != white)) {
				if (a[2][0][1].color[2] == white || a[2][0][1].color[5] == white) {
					Rotate(2, -3);
				}
				if (a[0][0][1].color[2] == white || a[0][0][1].color[4] == white) {
					Rotate(2, -3);
				}
				if (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white) {
					Rotate(2, -3);
				}
				if (a[2][2][1].color[3] == white || a[2][2][1].color[5] == white) {
					Rotate(1, 3);
				}
				if (a[0][2][1].color[3] == white || a[0][2][1].color[4] == white) {
					Rotate(1, 3);
				}
				if (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white) {
					Rotate(1, 3);
				}
				if (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white) {
					Rotate(1, -3);
				}
				if (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white) {
					Rotate(1, 3);
				}
			}
			//1 левый правильно 2 неправильно правый нижний уголок кроме верхней 
			if (a[0][1][2].color[4] == white && a[2][1][2].color[0] == white && a[1][0][2].color[0] == white && (a[1][2][2].color[0] != white && a[1][2][2].color[3] != white)) {
				if (a[2][0][1].color[2] == white || a[2][0][1].color[5] == white) {
					Rotate(1, -3);
				}
				if (a[0][0][1].color[2] == white || a[0][0][1].color[4] == white) {
					Rotate(1, -3);
				}
				if (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white) {
					Rotate(1, -3);
				}
				if (a[2][2][1].color[3] == white || a[2][2][1].color[5] == white) {
					Rotate(3, -3);
				}
				if (a[0][2][1].color[3] == white || a[0][2][1].color[4] == white) {
					Rotate(3, -3);
				}
				if (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white) {
					Rotate(3, -3);
				}
				if (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white) {
					Rotate(1, 3);
				}
				if (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white) {
					Rotate(1, -3);
				}
			}
			//1 верхний правильно 2 неправильно горизонтально кроме нижней
			if (a[0][1][2].color[0] == white && a[1][2][2].color[3] == white && a[2][1][2].color[0] == white && (a[1][0][2].color[0] != white && a[1][0][2].color[2] != white)) {
				if (a[2][0][1].color[2] == white || a[2][0][1].color[5] == white) {
					Rotate(2, -3);
				}
				if (a[0][0][1].color[2] == white || a[0][0][1].color[4] == white) {
					Rotate(2, 3);
				}
				if (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white) {
					Rotate(2, -3);
				}
				if (a[2][2][1].color[3] == white || a[2][2][1].color[5] == white) {
					Rotate(1, -3);
				}
				if (a[0][2][1].color[3] == white || a[0][2][1].color[4] == white) {
					Rotate(1, -3);
				}
				if (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white) {
					Rotate(1, -3);
				}
				if (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white) {
					Rotate(1, -3);
				}
				if (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white) {
					Rotate(1, 3);
				}
			}
			//1 верхний правильно 2 неправильно правый нижний угол кроме левой
			if (a[2][1][2].color[0] == white && a[1][2][2].color[3] == white && a[1][0][2].color[0] == white && (a[0][1][2].color[0] != white && a[0][1][2].color[4] != white)) {
				if (a[2][0][1].color[2] == white || a[2][0][1].color[5] == white) {
					Rotate(1, 3);
				}
				if (a[0][0][1].color[2] == white || a[0][0][1].color[4] == white) {
					Rotate(1, 3);
				}
				if (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white) {
					Rotate(1, 3);
				}
				if (a[2][2][1].color[3] == white || a[2][2][1].color[5] == white) {
					Rotate(1, -3);
				}
				if (a[0][2][1].color[3] == white || a[0][2][1].color[4] == white) {
					Rotate(1, -3);
				}
				if (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white) {
					Rotate(1, -3);
				}
				if (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white) {
					Rotate(4, -3);
				}
				if (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white) {
					Rotate(1, 3);
				}
			}
			//1 верхний правильно 2 неправильно левый нижний угол кроме правой
			if (a[0][1][2].color[0] == white && a[1][2][2].color[3] == white && a[1][0][2].color[0] == white && (a[2][1][2].color[0] != white && a[2][1][2].color[5] != white)) {
				if (a[2][0][1].color[2] == white || a[2][0][1].color[5] == white) {
					Rotate(1, -3);
				}
				if (a[0][0][1].color[2] == white || a[0][0][1].color[4] == white) {
					Rotate(1, -3);
				}
				if (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white) {
					Rotate(1, -3);
				}
				if (a[2][2][1].color[3] == white || a[2][2][1].color[5] == white) {
					Rotate(1, 3);
				}
				if (a[0][2][1].color[3] == white || a[0][2][1].color[4] == white) {
					Rotate(1, 3);
				}
				if (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white) {
					Rotate(1, 3);
				}
				if (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white) {
					Rotate(1, 3);
				}
				if (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white) {
					Rotate(5, -3);
				}
			}
			//1 правый правильно 2 неправильно вертикально кроме левой
			if (a[1][0][2].color[0] == white && a[1][2][2].color[0] == white && a[2][1][2].color[5] == white && (a[0][1][2].color[0] != white && a[0][1][2].color[4] != white)) {
				if (a[2][0][1].color[2] == white || a[2][0][1].color[5] == white) {
					Rotate(1, 3);
				}
				if (a[0][0][1].color[2] == white || a[0][0][1].color[4] == white) {
					Rotate(1, 3);
				}
				if (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white) {
					Rotate(1, 3);
				}
				if (a[2][2][1].color[3] == white || a[2][2][1].color[5] == white) {
					Rotate(1, -3);
				}
				if (a[0][2][1].color[3] == white || a[0][2][1].color[4] == white) {
					Rotate(1, -3);
				}
				if (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white) {
					Rotate(1, -3);
				}
				if (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white) {
					Rotate(4, 3);
				}
				if (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white) {
					Rotate(1, 3);
				}
			}
			//1 правый правильно 2 неправильно левый нижний уголок кроме верхней
			if (a[1][0][2].color[0] == white && a[0][1][2].color[0] == white && a[2][1][2].color[5] == white && (a[1][2][2].color[0] != white && a[1][2][2].color[3] != white)) {
				if (a[2][0][1].color[2] == white || a[2][0][1].color[5] == white) {
					Rotate(1, 3);
				}
				if (a[0][0][1].color[2] == white || a[0][0][1].color[4] == white) {
					Rotate(1, 3);
				}
				if (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white) {
					Rotate(1, 3);
				}
				if (a[2][2][1].color[3] == white || a[2][2][1].color[5] == white) {
					Rotate(3, -3);
				}
				if (a[0][2][1].color[3] == white || a[0][2][1].color[4] == white) {
					Rotate(3, -3);
				}
				if (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white) {
					Rotate(3, -3);
				}
				if (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white) {
					Rotate(1, 3);
				}
				if (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white) {
					Rotate(1, -3);
				}
			}
			//1 правый правильно 2 неправильно левый верхний уголок кроме нижней
			if (a[1][2][2].color[0] == white && a[0][1][2].color[0] == white && a[2][1][2].color[5] == white && (a[1][0][2].color[0] != white && a[1][0][2].color[2] != white)) {
				if (a[2][0][1].color[2] == white || a[2][0][1].color[5] == white) {
					Rotate(2, -3);
				}
				if (a[0][0][1].color[2] == white || a[0][0][1].color[4] == white) {
					Rotate(2, 3);
				}
				if (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white) {
					Rotate(2, -3);
				}
				if (a[2][2][1].color[3] == white || a[2][2][1].color[5] == white) {
					Rotate(1, 3);
				}
				if (a[0][2][1].color[3] == white || a[0][2][1].color[4] == white) {
					Rotate(1, 3);
				}
				if (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white) {
					Rotate(1, 3);
				}
				if (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white) {
					Rotate(1, -3);
				}
				if (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white) {
					Rotate(1, 3);
				}
			}
			//3 белых правильно и все (лево низ верх по часовой) кроме верха
			if (a[0][1][2].color[0] == white && a[1][0][2].color[0] == white && a[2][1][2].color[0] == white && (a[1][2][2].color[0] != white && a[1][2][2].color[3] != white)) {
				/*if (a[2][0][1].color[2] == white || a[2][0][1].color[5] == white) {
					Rotate(1, -3);
				}*/
				/*if (a[0][0][1].color[2] == white || a[0][0][1].color[4] == white) {
					Rotate(1, 3);
				}*/
				if (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white) {
					Rotate(1, -3);
				}
				if (a[2][2][1].color[3] == white || a[2][2][1].color[5] == white) {
					Rotate(3, -3);
				}
				if (a[0][2][1].color[3] == white && a[0][2][1].color[4] != white) {
					Rotate(1, 3);
				}
				if (a[0][2][1].color[3] != white && a[0][2][1].color[4] == white) {
					if (a[0][2][1].color[3] == green) {
						if (a[0][2][0].color[1] == white) {
							if (a[0][2][0].color[4] == red && a[0][2][0].color[3] == blue) {
								Rotate(0, 3);
							}
							if (a[0][2][0].color[4] == blue && a[0][2][0].color[3] == orange) {
								Rotate(0, 3);
							}
							if (a[0][2][0].color[4] == orange && a[0][2][0].color[3] == green) {
								Rotate(0, 3);
							}
							if (a[0][2][0].color[4] == green && a[0][2][0].color[3] == red) {
								Rotate(0, 3);
							}
						}

						if (a[0][2][0].color[4] == white) {
							if (a[0][2][0].color[3] == red && a[0][2][0].color[1] == blue) {
								Rotate(0, 3);
							}
							if (a[0][2][0].color[3] == blue && a[0][2][0].color[1] == orange) {
								Rotate(0, 3);
							}
							if (a[0][2][0].color[3] == orange && a[0][2][0].color[1] == green) {
								Rotate(0, 3);
							}
							if (a[0][2][0].color[3] == green && a[0][2][0].color[1] == red) {
								Rotate(3, 3);
							}
						}
						if (a[0][0][0].color[1] == white) {
							if (a[0][0][0].color[4] == blue && a[0][0][0].color[2] == red) {
								Rotate(3, 3);
							}
							if (a[0][0][0].color[4] == orange && a[0][0][0].color[2] == blue) {
								Rotate(3, 3);
							}
							if (a[0][0][0].color[4] == green && a[0][0][0].color[2] == orange) {
								Rotate(3, 3);
							}
							if (a[0][0][0].color[4] == red && a[0][0][0].color[2] == green) {
								Rotate(3, 3);
							}
						}
						if (a[0][2][0].color[3] == white) {
							if (a[0][2][0].color[4] == blue && a[0][2][0].color[1] == red) {
								Rotate(0, 3);
							}
							if (a[0][2][0].color[4] == orange && a[0][2][0].color[1] == blue) {
								Rotate(0, 3);
							}
							if (a[0][2][0].color[4] == green && a[0][2][0].color[1] == orange) {
								Rotate(0, 3);
							}
							if (a[0][2][0].color[4] == red && a[0][2][0].color[1] == green) {
								Rotate(0, 3);
							}
						}
						if (a[0][0][0].color[4] == white) {
							if (a[0][0][0].color[2] == blue && a[0][0][0].color[1] == red) {
								Rotate(3, 3);
							}
							if (a[0][0][0].color[2] == orange && a[0][0][0].color[1] == blue) {
								Rotate(3, 3);
							}
							if (a[0][0][0].color[2] == green && a[0][0][0].color[1] == orange) {
								Rotate(3, 3);
							}
							if (a[0][0][0].color[2] == red && a[0][0][0].color[1] == green) {
								Rotate(3, 3);
							}
						}
						if (a[0][0][0].color[2] == white) {
							if (a[0][0][0].color[4] == red && a[0][0][0].color[1] == blue) {
								Rotate(3, 3);
							}
							if (a[0][0][0].color[4] == blue && a[0][0][0].color[1] == orange) {
								Rotate(3, 3);
							}
							if (a[0][0][0].color[4] == orange && a[0][0][0].color[1] == green) {
								Rotate(3, 3);
							}
							if (a[0][0][0].color[4] == green && a[0][0][0].color[1] == red) {
								Rotate(0, -3);
							}
						}
						if (a[2][2][0].color[5] == white) {
							if (a[2][2][0].color[3] == red && a[2][2][0].color[1] == green) {
								Rotate(0, 3);
							}
							if (a[2][2][0].color[3] == blue && a[2][2][0].color[1] == red) {
								Rotate(3, 3);
							}

						}
						if (a[2][2][0].color[3] == white) {
							if (a[2][2][0].color[1] == red && a[2][2][0].color[5] == green) {
								Rotate(0, 3);
							}
							if (a[2][2][0].color[1] == blue && a[2][2][0].color[5] == red) {
								Rotate(3, 3);
							}
						}
						if (a[2][2][0].color[1] == white) {
							if (a[2][2][0].color[5] == blue && a[2][2][0].color[3] == red) {
								Rotate(3, 3);
							}
						}
						if (a[2][0][0].color[1] == white) {
							if (a[2][0][0].color[5] == red && a[2][0][0].color[2] == blue) {
								Rotate(3, 3);
							}
							if (a[2][0][0].color[5] == green && a[2][0][0].color[2] == red) {
								Rotate(0, 3);
							}
						}
						if (a[2][0][0].color[2] == white) {
							if (a[2][0][0].color[1] == red && a[2][0][0].color[5] == blue) {
								Rotate(3, 3);
							}
							if (a[2][0][0].color[1] == green && a[2][0][0].color[5] == red) {
								Rotate(0, 3);
							}
						}
						if (a[2][0][0].color[5] == white) {
							if (a[2][0][0].color[2] == red && a[2][0][0].color[1] == blue) {
								Rotate(3, 3);
							}
							if (a[2][0][0].color[2] == green && a[2][0][0].color[1] == red) {
								Rotate(0, 3);
							}
						}
					}
					if (a[0][2][1].color[3] == blue) {
						Rotate(3, 3);
					}
				}
				if (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white) {
					Rotate(3, -3);
				}
				if (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white) {
					Rotate(1, 3);
				}
				if (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white) {
					Rotate(1, -3);
				}
			}
			//кроме права
			if (a[0][1][2].color[0] == white && a[1][2][2].color[0] == white && a[1][0][2].color[0] == white && (a[2][1][2].color[0] != white && a[2][1][2].color[5] != white)) {
				/*if (a[2][0][1].color[2] == white || a[2][0][1].color[5] == white) {
					Rotate(1, -3);
				}*/
				if (a[2][0][1].color[2] == white && a[2][0][1].color[5] != white) {
					if (a[2][0][1].color[5] == orange) {
						if (a[2][0][0].color[2] == white) {
							if (a[2][0][0].color[1] == red && a[2][0][0].color[5] == blue) {
								Rotate(0, 3);
							}
						}
						if (a[2][0][0].color[5] == white) {
							if (a[2][0][0].color[2] == red && a[2][0][0].color[1] == blue) {
								Rotate(0, 3);
							}
						}
						if (a[2][0][0].color[1] == white) {
							if (a[2][0][0].color[5] == red && a[2][0][0].color[2] == blue) {
								Rotate(0, 3);
							}
						}
						if (a[2][0][0].color[2] != white) {
							if (a[2][0][0].color[1] != red && a[2][0][0].color[5] != blue) {
								Rotate(5, -3);
							}
						}
						if (a[2][0][0].color[5] != white) {
							if (a[2][0][0].color[2] != red && a[2][0][0].color[1] != blue) {
								Rotate(5, -3);
							}
						}
						if (a[2][0][0].color[1] != white) {
							if (a[2][0][0].color[5] != red && a[2][0][0].color[2] != blue) {
								Rotate(5, -3);
							}
						}
					}
				}
				if (a[0][0][1].color[2] == white || a[0][0][1].color[4] == white) {
					Rotate(1, -3);
				}
				if (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white) {
					Rotate(1, -3);
				}
				if (a[2][2][1].color[3] != white && a[2][2][1].color[5] == white) {
					Rotate(1, 3);
				}
				if (a[2][2][1].color[3] == white && a[2][2][1].color[5] != white) {
					if (a[2][2][1].color[5] == orange) {
						if (a[2][2][0].color[1] == white)
						{
							if (a[2][2][0].color[3] == red && a[2][2][0].color[5] == blue) {
								Rotate(0, 3);
							}
							if (a[2][2][0].color[3] == blue && a[2][2][0].color[5] == orange) {
								Rotate(0, 3);
							}
							if (a[2][2][0].color[3] == orange && a[2][2][0].color[5] == green) {
								Rotate(0, 3);
							}
						}
						if (a[0][2][0].color[1] == white) {
							if (a[0][2][0].color[4] == red && a[0][2][0].color[3] == blue) {
								Rotate(5, 3);
							}
							if (a[0][2][0].color[4] == blue && a[0][2][0].color[3] == orange) {
								Rotate(5, 3);
							}
							if (a[0][2][0].color[4] == orange && a[0][2][0].color[3] == green) {
								Rotate(5, 3);
							}
							if (a[0][2][0].color[4] == green && a[0][2][0].color[3] == red && (a[2][2][0].color[1] != white && a[2][2][0].color[3] != blue && a[2][2][0].color[5] != orange) && (a[2][2][0].color[5] != white && a[2][2][0].color[1] != blue && a[2][2][0].color[3] != orange) && (a[2][2][0].color[3] != white && a[2][2][0].color[5] != blue && a[2][2][0].color[1] != orange)) {
								Rotate(5, 3);
							}
						}
						if (a[2][2][0].color[5] == white)
						{
							if (a[2][2][0].color[1] == red && a[2][2][0].color[3] == blue) {
								Rotate(0, 3);
							}
							if (a[2][2][0].color[1] == blue && a[2][2][0].color[3] == orange) {
								Rotate(0, 3);
							}
							if (a[2][2][0].color[1] == orange && a[2][2][0].color[3] == green) {
								Rotate(0, 3);
							}
						}
						if (a[0][2][0].color[3] == white) {
							if (a[0][2][0].color[4] == blue && a[0][2][0].color[1] == red) {
								Rotate(5, 3);
							}
							if (a[0][2][0].color[4] == orange && a[0][2][0].color[1] == blue) {
								Rotate(5, 3);
							}
							if (a[0][2][0].color[1] == orange && a[0][2][0].color[4] == green) {
								Rotate(5, 3);
							}
							if (a[0][2][0].color[1] == green && a[0][2][0].color[4] == red && (a[2][2][0].color[1] != white && a[2][2][0].color[3] != blue && a[2][2][0].color[5] != orange) && (a[2][2][0].color[5] != white && a[2][2][0].color[1] != blue && a[2][2][0].color[3] != orange) && (a[2][2][0].color[3] != white && a[2][2][0].color[5] != blue && a[2][2][0].color[1] != orange)) {
								Rotate(5, 3);
							}
						}
						if (a[2][2][0].color[3] == white)
						{
							if (a[2][2][0].color[5] == red && a[2][2][0].color[1] == blue) {
								Rotate(0, 3);
							}
							if (a[2][2][0].color[1] == orange && a[2][2][0].color[5] == blue) {
								Rotate(0, 3);
							}
							if (a[2][2][0].color[5] == orange && a[2][2][0].color[1] == green) {
								Rotate(5, 3);
							}

						}
						if (a[0][2][0].color[4] == white) {
							if (a[0][2][0].color[3] == red && a[0][2][0].color[1] == blue) {
								Rotate(5, 3);
							}
							if (a[0][2][0].color[3] == blue && a[0][2][0].color[1] == orange) {
								Rotate(5, 3);
							}
							if (a[0][2][0].color[3] == orange && a[0][2][0].color[1] == green) {
								Rotate(0, -3);
							}
							if (a[0][2][0].color[1] == red && a[0][2][0].color[3] == green && (a[2][2][0].color[1] != white && a[2][2][0].color[3] != blue && a[2][2][0].color[5] != orange) && (a[2][2][0].color[5] != white && a[2][2][0].color[1] != blue && a[2][2][0].color[3] != orange) && (a[2][2][0].color[3] != white && a[2][2][0].color[5] != blue && a[2][2][0].color[1] != orange)) {
								Rotate(5, 3);
							}
						}
						if (a[2][0][0].color[2] == white) {
							if (a[2][0][0].color[1] == orange && a[2][0][0].color[5] == green) {
								Rotate(0, 3);
							}
						}
						if (a[2][0][0].color[5] == white) {
							if (a[2][0][0].color[2] == orange && a[2][0][0].color[1] == green) {
								Rotate(0, 3);
							}
						}
						if (a[2][0][0].color[1] == white) {
							if (a[2][0][0].color[5] == orange && a[2][0][0].color[2] == green) {
								Rotate(0, 3);
							}
						}
					}
				}
				if (a[0][2][1].color[3] == white && a[0][2][1].color[4] != white) {
					Rotate(1, 3);
				}
				/*if (a[0][2][1].color[3] != white && a[0][2][1].color[4] == white) {
					if (a[0][2][1].color[3] == green) {
						if (a[0][2][0].color[1] == white) {
							if (a[0][2][0].color[4] == red && a[0][2][0].color[3] == blue) {
								Rotate(0, 3);

							}
						}
						if (a[0][0][0].color[1] == white) {
							if (a[0][0][0].color[4] == blue && a[0][0][0].color[2] == red) {
								Rotate(3, 3);
							}
						}
						if (a[0][2][0].color[3] == white) {
							if (a[0][2][0].color[4] == blue && a[0][2][0].color[1] == red) {
								Rotate(0, 3);

							}
						}
						if (a[0][0][0].color[4] == white) {
							if (a[0][0][0].color[2] == blue && a[0][0][0].color[1] == red) {
								Rotate(3, 3);
							}
						}
						if (a[0][2][0].color[4] == white) {
							if (a[0][2][0].color[3] == red && a[0][2][0].color[1] == blue) {
								Rotate(0, 3);

							}
						}
						if (a[0][0][0].color[2] == white) {
							if (a[0][0][0].color[4] == red && a[0][0][0].color[1] == blue) {
								Rotate(3, 3);
							}
						}
					}
				}*/
				if (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white) {
					Rotate(1, 3);
				}
				if (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white) {
					Rotate(1, 3);
				}
				if (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white) {
					Rotate(5, 3);
				}
			}
			//кроме низа
			if (a[0][1][2].color[0] == white && a[1][2][2].color[0] == white && a[2][1][2].color[0] == white && (a[1][0][2].color[0] != white && a[1][0][2].color[2] != white)) {
				if (a[2][0][1].color[2] == white && a[2][0][1].color[5] != white) {
					Rotate(2, -3);
				}
				//синий угол правильный
				if (a[2][0][1].color[2] != white && a[2][0][1].color[5] == white) {
					if (a[2][0][1].color[2] == blue && a[2][0][2].color[5] == white && a[2][0][2].color[0] == red && a[2][0][2].color[2] == blue) {
						if (a[0][0][0].color[4] == white) {
							if (a[0][0][0].color[2] == orange && a[0][0][0].color[1] == blue) {
								Rotate(0, 3);

							}
						}
						if (a[2][0][0].color[2] == white) {
							if (a[2][0][0].color[1] == blue && a[2][0][0].color[5] == orange) {
								Rotate(0, 3);

							}
						}
						if (a[2][0][0].color[5] == white) {
							if (a[2][0][0].color[2] == blue && a[2][0][0].color[1] == orange) {
								Rotate(2, -3);

							}
						}
						if (a[0][0][0].color[2] == white) {
							if (a[0][0][0].color[1] == orange && a[0][0][0].color[4] == blue) {
								Rotate(0, 3);

							}
						}
						if (a[0][0][0].color[1] == white) {
							if (a[0][0][0].color[4] == orange && a[0][0][0].color[2] == blue) {
								Rotate(0, 3);

							}
						}
						if (a[2][2][0].color[3] == white) {
							if (a[2][2][0].color[5] == blue && a[2][2][0].color[1] == orange) {
								Rotate(0, -3);
							}
							if (a[2][2][0].color[5] == orange && a[2][2][0].color[1] == green) {
								Rotate(2, -3);
							}
						}
						if (a[2][0][0].color[1] == white) {
							if (a[2][0][0].color[5] == blue && a[2][0][0].color[2] == orange) {
								Rotate(0, 3);

							}
						}
						if (a[2][2][0].color[1] == white) {
							if (a[2][2][0].color[3] == blue && a[2][2][0].color[5] == orange) {
								Rotate(2, -3);
							}
							if (a[2][2][0].color[3] == orange && a[2][2][0].color[5] == green) {
								Rotate(2, -3);
							}
						}
						if (a[2][2][0].color[5] == white) {
							if (a[2][2][0].color[1] == blue && a[2][2][0].color[3] == orange) {
								Rotate(2, -3);
							}
							if (a[2][2][0].color[1] == orange && a[2][2][0].color[3] == green) {
								Rotate(2, -3);
							}
						}
					}
					else {
						Rotate(2, -3);
					}
				}
				/*if (a[0][0][1].color[2] == white || a[0][0][1].color[4] == white) {
					Rotate(2, 3);
				}*/
				if (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white) {
					Rotate(2, -3);
				}
				if (a[2][2][1].color[3] == white || a[2][2][1].color[5] == white) {
					Rotate(1, -3);
				}
				if (a[0][2][1].color[3] == white || a[0][2][1].color[4] == white) {
					Rotate(1, -3);
				}
				if (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white) {
					Rotate(1, -3);
				}
				if (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white) {
					Rotate(1, -3);
				}
				if (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white) {
					Rotate(1, 3);
				}
			}
			//кроме лева
			if (a[1][0][2].color[0] == white && a[1][2][2].color[0] == white && a[2][1][2].color[0] == white && (a[0][1][2].color[0] != white && a[0][1][2].color[4] != white)) {
				if (a[2][0][1].color[2] == white && a[2][0][1].color[5] != white) {
					Rotate(1, 3);
				}
				if (a[2][0][1].color[2] != white && a[2][0][1].color[5] == white) {
					Rotate(1, 3);
				}
				//1 пиф паф левый нижний угол
				if (a[0][0][1].color[2] == white && a[0][0][1].color[4] != white) {
					if (a[0][0][1].color[4] == red) {
						if (a[0][0][0].color[4] == white) {
							if ((a[0][0][0].color[2] == blue && a[0][0][0].color[1] == red) || (a[0][0][0].color[2] == red && a[0][0][0].color[1] == blue)) {
								Rotate(0, 3);
							}
						}
						if (a[2][0][0].color[2] == white) {
							if ((a[2][0][0].color[5] == blue && a[2][0][0].color[1] == red) || (a[2][0][0].color[5] == red && a[2][0][0].color[1] == blue)) {
								Rotate(4, -3);
							}
						}
						if (a[0][2][0].color[4] == white) {
							if ((a[0][2][0].color[3] == blue && a[0][2][0].color[1] == red) || (a[0][2][0].color[3] == red && a[0][2][0].color[1] == blue)) {
								Rotate(0, 3);
							}
						}
						if (a[0][0][0].color[2] == white) {
							if ((a[0][0][0].color[4] == blue && a[0][0][0].color[1] == red) || (a[0][0][0].color[4] == red && a[0][0][0].color[1] == blue)) {
								Rotate(4, -3);
							}
						}
						if (a[0][0][0].color[1] == white) {
							if ((a[0][0][0].color[4] == blue && a[0][0][0].color[2] == red) || (a[0][0][0].color[4] == red && a[0][0][0].color[2] == blue)) {
								Rotate(0, 3);
							}
						}
						if (a[2][0][0].color[1] == white) {
							if ((a[2][0][0].color[2] == red && a[2][0][0].color[5] == blue) || (a[2][0][0].color[2] == blue && a[2][0][0].color[5] == red)) {
								Rotate(4, -3);
							}
						}
						if (a[0][2][0].color[3] == white) {
							if ((a[0][2][0].color[4] == blue && a[0][2][0].color[1] == red) || (a[0][2][0].color[4] == red && a[0][2][0].color[1] == blue)) {
								Rotate(0, 3);
							}
						}
						if (a[2][0][0].color[5] == white) {
							if ((a[2][0][0].color[2] == red && a[2][0][0].color[1] == blue) || (a[2][0][0].color[2] == blue && a[2][0][0].color[1] == red)) {
								Rotate(0, -3);
							}
						}
					}
				}
				/*if (a[0][0][1].color[2] != white && a[0][0][1].color[4] == white) {
					Rotate(1, 3);
				}*/
				if (a[1][0][0].color[2] == white && a[1][0][0].color[1] != white) {
					Rotate(1, 3);
				}
				if (a[1][0][0].color[2] != white && a[1][0][0].color[1] == white) {
					Rotate(1, 3);
				}
				if (a[2][2][1].color[3] == white && a[2][2][1].color[5] != white) {
					Rotate(1, -3);
				}
				if (a[2][2][1].color[3] != white && a[2][2][1].color[5] == white) {
					Rotate(1, -3);
				}
				if (a[0][2][1].color[3] == white && a[0][2][1].color[4] != white) {
					Rotate(1, -3);
				}
				if (a[0][2][1].color[3] != white && a[0][2][1].color[4] == white) {
					Rotate(1, -3);
				}
				if (a[1][2][0].color[3] == white && a[1][2][0].color[1] != white) {
					Rotate(1, -3);
				}
				if (a[1][2][0].color[3] != white && a[1][2][0].color[1] == white) {
					Rotate(1, -3);
				}
				if (a[0][1][0].color[4] == white && a[0][1][0].color[1] != white) {
					Rotate(4, 3);
				}
				if (a[0][1][0].color[4] != white && a[0][1][0].color[1] == white) {
					Rotate(4, 3);
				}
				if (a[2][1][0].color[5] == white && a[2][1][0].color[1] != white) {
					Rotate(1, 3);
				}
				if (a[2][1][0].color[5] != white && a[2][1][0].color[1] == white) {
					Rotate(1, 3);
				}
			}
			//1 снизу (оба варианта)
			if ((a[1][0][2].color[0] == white || a[1][0][2].color[2] == white) && (a[0][1][2].color[4] != white && a[0][1][2].color[0] != white) && (a[2][1][2].color[0] != white && a[2][1][2].color[5] != white) && (a[1][2][2].color[0] != white && a[1][2][2].color[3] != white)) {
				//для синей грани
				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
					Rotate(1, -3);
				}
				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
					Rotate(1, -3);
				}
				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
					Rotate(1, -3);
				}
				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
					Rotate(1, -3);
				}
				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
					Rotate(1, -3);
				}
				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
					Rotate(1, -3);
				}
				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
					Rotate(1, -3);
				}
				//для зеленой грани
				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
					Rotate(3, -3);
				}
				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
					Rotate(3, -3);
				}
				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
					Rotate(3, -3);
				}
				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
					Rotate(3, -3);
				}
				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
					Rotate(3, -3);
				}
				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
					Rotate(3, -3);
				}
				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
					Rotate(3, -3);
				}
				//для красной
				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
					Rotate(4, 3);
				}
				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
					Rotate(4, -3);
				}
				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
					Rotate(4, 3);
				}
				if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
					Rotate(4, -3);
				}
				if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
					Rotate(4, -3);
				}
				if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
					Rotate(4, -3);
				}
				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
					Rotate(4, -3);
				}
				//для оранжевой
				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
					Rotate(5, 3);
				}
				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
					Rotate(5, -3);
				}
				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
					Rotate(5, 3);
				}
				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
					Rotate(5, -3);
				}
				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
					Rotate(5, -3);
				}
				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
					Rotate(5, -3);
				}
				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
					Rotate(5, -3);
				}
			}
			//слева
			if ((a[0][1][2].color[0] == white || a[0][1][2].color[4] == white) && (a[1][0][2].color[0] != white && a[1][0][2].color[2] != white) && (a[2][1][2].color[0] != white && a[2][1][2].color[5] != white) && (a[1][2][2].color[0] != white && a[1][2][2].color[3] != white)) {
				//для синей грани
				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
					Rotate(2, -3);
				}
				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
					Rotate(2, -3);
				}
				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
					Rotate(2, -3);
				}
				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
					Rotate(2, 3);
				}
				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
					Rotate(2, 3);
				}
				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
					Rotate(2, -3);
				}
				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
					Rotate(2, -3);
				}
				//для зеленой грани
				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
					Rotate(3, -3);
				}
				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
					Rotate(3, -3);
				}
				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
					Rotate(3, -3);
				}
				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
					Rotate(3, 3);
				}
				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
					Rotate(3, 3);
				}
				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
					Rotate(3, -3);
				}
				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
					Rotate(3, -3);
				}
				//для красной
				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
					Rotate(1, -3);
				}
				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
					Rotate(1, -3);
				}
				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
					Rotate(1, -3);
				}
				if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
					Rotate(1, -3);
				}
				if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
					Rotate(1, -3);
				}
				if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
					Rotate(1, -3);
				}
				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
					Rotate(1, -3);
				}
				//для оранжевой
				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
					Rotate(5, 3);
				}
				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
					Rotate(5, -3);
				}
				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
					Rotate(5, 3);
				}
				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
					Rotate(5, -3);
				}
				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
					Rotate(5, -3);
				}
				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
					Rotate(5, -3);
				}
				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
					Rotate(5, -3);
				}
			}

			//сверху
			if ((a[1][2][2].color[0] == white || a[1][2][2].color[3] == white) && (a[0][1][2].color[4] != white && a[0][1][2].color[0] != white) && (a[2][1][2].color[0] != white && a[2][1][2].color[5] != white) && (a[1][0][2].color[0] != white && a[1][0][2].color[2] != white)) {
				//для синей грани
				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
					Rotate(2, -3);
				}
				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
					Rotate(2, -3);
				}
				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
					Rotate(2, -3);
				}
				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
					Rotate(2, 3);
				}
				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
					Rotate(2, 3);
				}
				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
					Rotate(2, -3);
				}
				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
					Rotate(2, -3);
				}
				//для зеленой грани
				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
					Rotate(1, -3);
				}
				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
					Rotate(1, -3);
				}
				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
					Rotate(1, -3);
				}
				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
					Rotate(1, -3);
				}
				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
					Rotate(1, -3);
				}
				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
					Rotate(1, -3);
				}
				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
					Rotate(1, -3);
				}
				//для красной
				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
					Rotate(4, 3);
				}
				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
					Rotate(4, -3);
				}
				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
					Rotate(4, 3);
				}
				if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
					Rotate(4, -3);
				}
				if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
					Rotate(4, -3);
				}
				if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
					Rotate(4, -3);
				}
				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
					Rotate(4, -3);
				}
				//для оранжевой
				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
					Rotate(5, 3);
				}
				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
					Rotate(5, -3);
				}
				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
					Rotate(5, 3);
				}
				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
					Rotate(5, -3);
				}
				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
					Rotate(5, -3);
				}
				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
					Rotate(5, -3);
				}
				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
					Rotate(5, -3);
				}
			}
			//справа
			if ((a[2][1][2].color[0] == white || a[2][1][2].color[5] == white) && (a[0][1][2].color[4] != white && a[0][1][2].color[0] != white) && (a[1][0][2].color[0] != white && a[1][0][2].color[2] != white) && (a[1][2][2].color[0] != white && a[1][2][2].color[3] != white)) {
				//для синей грани
				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
					Rotate(2, -3);
				}
				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
					Rotate(2, -3);
				}
				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
					Rotate(2, -3);
				}
				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
					Rotate(2, 3);
				}
				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
					Rotate(2, 3);
				}
				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
					Rotate(2, -3);
				}
				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
					Rotate(2, -3);
				}
				//для зеленой грани
				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
					Rotate(3, -3);
				}
				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
					Rotate(3, -3);
				}
				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
					Rotate(3, -3);
				}
				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
					Rotate(3, 3);
				}
				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
					Rotate(3, 3);
				}
				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
					Rotate(3, -3);
				}
				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
					Rotate(3, -3);
				}
				//для красной
				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
					Rotate(4, 3);
				}
				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
					Rotate(4, -3);
				}
				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
					Rotate(4, 3);
				}
				if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
					Rotate(4, -3);
				}
				if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
					Rotate(4, -3);
				}
				if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
					Rotate(4, -3);
				}
				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
					Rotate(4, -3);
				}
				//для оранжевой
				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
					Rotate(1, -3);
				}
				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
					Rotate(1, -3);
				}
				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
					Rotate(1, -3);
				}
				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
					Rotate(1, -3);
				}
				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
					Rotate(1, -3);
				}
				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
					Rotate(1, -3);
				}
				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
					Rotate(1, -3);
				}
			}
			//0 правильных 
			if (a[0][1][2].color[0] != white && a[0][1][2].color[4] != white && a[1][0][2].color[0] != white && a[1][0][2].color[2] != white && a[1][2][2].color[0] != white && a[1][2][2].color[3] != white && a[2][1][2].color[0] != white && a[2][1][2].color[5] != white) {
				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
					Rotate(2, -3);
				}
				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
					Rotate(2, -3);
				}
				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
					Rotate(2, -3);
				}
				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
					Rotate(2, 3);
				}
				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
					Rotate(2, 3);
				}
				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
					Rotate(2, -3);
				}
				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
					Rotate(2, -3);
				}
				//для зеленой грани
				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
					Rotate(3, -3);
				}
				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
					Rotate(3, -3);
				}
				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
					Rotate(3, -3);
				}
				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
					Rotate(3, 3);
				}
				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
					Rotate(3, 3);
				}
				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
					Rotate(3, -3);
				}
				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
					Rotate(3, -3);
				}
				//для красной
				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
					Rotate(4, 3);
				}
				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
					Rotate(4, -3);
				}
				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
					Rotate(4, 3);
				}
				if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
					Rotate(4, -3);
				}
				if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
					Rotate(4, -3);
				}
				if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
					Rotate(4, -3);
				}
				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
					Rotate(4, -3);
				}
				//для оранжевой
				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
					Rotate(5, -3);
				}
				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
					Rotate(5, -3);
				}
				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
					Rotate(5, -3);
				}
				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
					Rotate(5, -3);
				}
				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
					Rotate(5, -3);
				}
				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
					Rotate(5, -3);
				}
				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
					Rotate(5, -3);
				}
			}
		}
	}
	void F2L() {
		//setting combination flags
		//wrong corners that should be upped
		if (a[0][0][2].color[0] == white && a[0][0][2].color[4] == red && a[0][0][2].color[2] == blue && a[0][0][1].color[4] == red && a[0][0][1].color[2] == blue && a[2][0][2].color[0] == white && a[2][0][2].color[5] == orange && a[2][0][2].color[2] == blue && a[2][0][1].color[5] == orange && a[2][0][1].color[2] == blue && a[0][2][2].color[0] == white && a[0][2][2].color[4] == red && a[0][2][2].color[3] == green && a[0][2][1].color[4] == red && a[0][2][1].color[3] == green && a[2][2][2].color[0] == white && a[2][2][2].color[5] == orange && a[2][2][2].color[3] == green && a[2][2][1].color[5] == orange && a[2][2][1].color[3] == green) {
			timeron = 2;
			return;
		}
		if (start == 0) {
			if (wrong == 0) {
				if (lup == 0 && (rup == 0 && ldown == 0 && rdown == 0) && up == 0) {
					//printf("L:     %d", lup);
					if (!((a[0][2][2].color[4] == red && a[0][2][2].color[3] == green) || (a[0][2][2].color[4] == green && a[0][2][2].color[3] == red) ||  (a[0][2][2].color[0] == red && a[0][2][2].color[4] == green) || (a[0][2][2].color[4] == red && a[0][2][2].color[0] == green )|| (a[0][2][2].color[0] == green && a[0][2][2].color[3] == red) || (a[0][2][2].color[3] == green && a[0][2][2].color[0] == red)) && (a[0][2][2].color[0] == white || a[0][2][2].color[4] == white || a[0][2][2].color[3] == white)) {
						//if (!(a[0][2][0].color[4] == white || a[0][2][0].color[1] == white || a[0][2][0].color[3] == white)) {//если (не)два угла один над другим
						    //нижние углы 
							if (((a[0][2][2].color[4] == orange && a[0][2][2].color[3] == green) || (a[0][2][2].color[3] == orange && a[0][2][2].color[4] == green) || (a[0][2][2].color[0] == orange && a[0][2][2].color[4] == green) || (a[0][2][2].color[4] == orange && a[0][2][2].color[0] == green) ||(a[0][2][2].color[0] == orange && a[0][2][2].color[3] == green) || (a[0][2][2].color[3] == orange && a[0][2][2].color[0] == green)) && !((a[2][1][0].color[1] == orange && a[2][1][0].color[5] == green) || (a[2][1][0].color[1] == green && a[2][1][0].color[5] == orange) || (a[0][0][1].color[4] == orange && a[0][0][1].color[2] == green) || (a[0][0][1].color[2] == orange && a[0][0][1].color[4] == green) || (a[2][0][1].color[5] == orange && a[2][0][1].color[2] == green) || (a[2][0][1].color[2] == orange && a[2][0][1].color[5] == green))) {
								og = 1;
								wrong = 1;
								lup = 1;
								start = 1;
							}
							else if (((a[0][2][2].color[4] == orange && a[0][2][2].color[3] == blue) || (a[0][2][2].color[3] == orange && a[0][2][2].color[0] == blue) || (a[0][2][2].color[0] == orange && a[0][2][2].color[4] == blue) || (a[0][2][2].color[3] == orange && a[0][2][2].color[4] == blue) || (a[0][2][2].color[0] == orange && a[0][2][2].color[3] == blue) || (a[0][2][2].color[4] == orange && a[0][2][2].color[0] == blue)) && !((a[2][1][0].color[1] == orange && a[2][1][0].color[5] == blue) || (a[2][1][0].color[1] == blue && a[2][1][0].color[5] == orange) || (a[0][0][1].color[4] == orange && a[0][0][1].color[2] == blue) || (a[0][0][1].color[2] == orange && a[0][0][1].color[4] == blue) || (a[2][2][1].color[5] == orange && a[2][2][1].color[3] == blue) || (a[2][2][1].color[3] == orange && a[2][2][1].color[5] == blue))) {
								ob = 1;
								wrong = 1;
								lup = 1;
								start = 1;
							}
							else if (((a[0][2][2].color[4] == red && a[0][2][2].color[3] == blue) || (a[0][2][2].color[3] == red && a[0][2][2].color[0] == blue) || (a[0][2][2].color[0] == red && a[0][2][2].color[4] == blue) || (a[0][2][2].color[3] == red && a[0][2][2].color[4] == blue) || (a[0][2][2].color[0] == red && a[0][2][2].color[3] == blue) || (a[0][2][2].color[4] == red && a[0][2][2].color[0] == blue)) && !((a[2][1][0].color[1] == red && a[2][1][0].color[5] == blue) || (a[2][1][0].color[1] == blue && a[2][1][0].color[5] == red) || (a[2][0][1].color[5] == red && a[2][0][1].color[2] == blue) || (a[2][0][1].color[2] == red && a[2][0][1].color[5] == blue) || (a[2][2][1].color[5] == red && a[2][2][1].color[3] == blue) || (a[2][2][1].color[3] == red && a[2][2][1].color[5] == blue))) {
								rb = 1;
								wrong = 1;
								lup = 1;
								start = 1;
							}//верхние углы
							else if ((a[0][2][0].color[4] == orange && a[0][2][0].color[3] == green) || (a[0][2][0].color[3] == orange && a[0][2][0].color[4] == green) || (a[0][2][0].color[1] == orange && a[0][2][0].color[4] == green) || (a[0][2][0].color[4] == orange && a[0][2][0].color[1] == green) || (a[0][2][0].color[1] == orange && a[0][2][0].color[3] == green) || (a[0][2][0].color[3] == orange && a[0][2][0].color[1] == green) && (a[0][2][0].color[1] == white || a[0][2][0].color[3] == white || a[0][2][0].color[4] == white) && !((a[0][2][1].color[4] == orange && a[0][2][1].color[3] == green) || (a[0][2][1].color[3] == orange && a[0][2][1].color[5] == green) || (a[0][0][1].color[4] == orange && a[0][0][1].color[2] == green) || (a[0][0][1].color[2] == orange && a[0][0][1].color[4] == green) || (a[2][0][1].color[5] == orange && a[2][0][1].color[2] == green) || (a[2][0][1].color[2] == orange && a[2][0][1].color[5] == green))) {
								og = 1;
								wrong = 2;
								lup = 1;
								start = 1;
							}
							else if ((a[0][2][0].color[4] == orange && a[0][2][0].color[3] == blue) || (a[0][2][0].color[3] == orange && a[0][2][0].color[1] == blue) || (a[0][2][0].color[1] == orange && a[0][2][0].color[4] == blue) || (a[0][2][0].color[3] == orange && a[0][2][0].color[4] == blue) || (a[0][2][0].color[1] == orange && a[0][2][0].color[3] == blue) || (a[0][2][0].color[4] == orange && a[0][2][0].color[1] == blue) && (a[0][2][0].color[1] == white || a[0][2][0].color[3] == white || a[0][2][0].color[4] == white) && !((a[0][2][1].color[4] == orange && a[0][2][1].color[3] == blue) || (a[0][2][1].color[3] == orange && a[0][2][1].color[5] == blue) || (a[0][0][1].color[4] == orange && a[0][0][1].color[2] == blue) || (a[0][0][1].color[2] == orange && a[0][0][1].color[4] == blue) || (a[2][2][1].color[5] == orange && a[2][2][1].color[3] == blue) || (a[2][2][1].color[3] == orange && a[2][2][1].color[5] == blue))) {
								ob = 1;
								wrong = 2;
								lup = 1;
								start = 1;
							}
							else if ((a[0][2][0].color[4] == red && a[0][2][0].color[3] == blue) || (a[0][2][0].color[3] == red && a[0][2][0].color[1] == blue) || (a[0][2][0].color[1] == red && a[0][2][0].color[4] == blue) || (a[0][2][0].color[3] == red && a[0][2][0].color[4] == blue) || (a[0][2][0].color[1] == red && a[0][2][0].color[3] == blue) || (a[0][2][0].color[4] == red && a[0][2][0].color[1] == blue) && (a[0][2][0].color[1] == white || a[0][2][0].color[3] == white || a[0][2][0].color[4] == white) && !((a[0][2][1].color[4] == red && a[0][2][1].color[3] == blue) || (a[0][2][1].color[3] == red && a[0][2][1].color[5] == blue) || (a[2][0][1].color[5] == red && a[2][0][1].color[2] == blue) || (a[2][0][1].color[2] == red && a[2][0][1].color[5] == blue) || (a[2][2][1].color[5] == red && a[2][2][1].color[3] == blue) || (a[2][2][1].color[3] == red && a[2][2][1].color[5] == blue))) {
								rb = 1;
								wrong = 2;
								lup = 1;
								start = 1;
							}
					}//если правильный (но не идеально) цвет снизу
					else if (((a[0][2][2].color[0] == red && a[0][2][2].color[4] == green) || (a[0][2][2].color[4] == red && a[0][2][2].color[0] == green) || (a[0][2][2].color[0] == green && a[0][2][2].color[3] == red) || (a[0][2][2].color[3] == green && a[0][2][2].color[0] == red) || (a[0][2][2].color[3] == red && a[0][2][2].color[4] == green)) && (a[0][2][2].color[0] == white || a[0][2][2].color[4] == white || a[0][2][2].color[3] == white)) {
						//только если нужное ребро наверху или там где надо, но не правильно
						if ((a[0][1][0].color[4] == red && a[0][1][0].color[1] == green) || (a[1][2][0].color[1] == red && a[1][2][0].color[3] == green) || (a[0][2][1].color[4] == red && a[0][2][1].color[3] == green) || (a[0][2][1].color[3] == red && a[0][2][1].color[4] == green)) {
							rg = 1;
							wrong = 6;
							lup = 1;
							start = 1;
						}
						else if (a[1][0][0].color[1] == green && a[1][0][0].color[2] == red) {
							rg = 2;
							wrong = 4;
							up = 1; //требуется 1 поворот
							start = 1;
						}
						else if (a[1][0][0].color[2] == green && a[1][0][0].color[1] == red) {
							rg = 1;
							wrong = 4;
							up = 2; //требуется 2 поворота
							start = 1;
						}
						else if (a[2][1][0].color[1] == green && a[2][1][0].color[5] == red) {
							rg = 2;
							wrong = 4;
							up = 2; //требуется два поворота
							start = 1;
						}
						else if (a[2][1][0].color[5] == green && a[2][1][0].color[1] == red) {
							rg = 1;
							wrong = 4;
							up = 1; //требуется 1 поворот
							start = 1;
						}
					}
					else if (a[0][2][2].color[4] == red && a[0][2][2].color[3] == green && a[0][2][2].color[0] == white) {
						if ((a[0][1][0].color[4] == red && a[0][1][0].color[1] == green) || (a[1][2][0].color[1] == red && a[1][2][0].color[3] == green) || (a[0][2][1].color[3] == red && a[0][2][1].color[4] == green)) {
							rg = 1;
							wrong = 6;
							lup = 1;
							start = 1;
						}
						else if (a[0][2][1].color[3] == green && a[0][2][1].color[4] == red) {
							if (((a[0][2][0].color[4] == orange && a[0][2][0].color[3] == green) || (a[0][2][0].color[3] == orange && a[0][2][0].color[4] == green) || (a[0][2][0].color[1] == orange && a[0][2][0].color[4] == green) || (a[0][2][0].color[4] == orange && a[0][2][0].color[1] == green) || (a[0][2][0].color[1] == orange && a[0][2][0].color[3] == green) || (a[0][2][0].color[3] == orange && a[0][2][0].color[1] == green)) && (a[0][2][0].color[1] == white || a[0][2][0].color[3] == white || a[0][2][0].color[4] == white)) {
								og = 1;
								wrong = 2;
								lup = 1;
								start = 1;
							}
							else if (((a[0][2][0].color[4] == orange && a[0][2][0].color[3] == blue) || (a[0][2][0].color[3] == orange && a[0][2][0].color[1] == blue) || (a[0][2][0].color[1] == orange && a[0][2][0].color[4] == blue) || (a[0][2][0].color[3] == orange && a[0][2][0].color[4] == blue) || (a[0][2][0].color[1] == orange && a[0][2][0].color[3] == blue) || (a[0][2][0].color[4] == orange && a[0][2][0].color[1] == blue)) && (a[0][2][0].color[1] == white || a[0][2][0].color[3] == white || a[0][2][0].color[4] == white)) {
								ob = 1;
								wrong = 2;
								lup = 1;
								start = 1;
							}
							else if (((a[0][2][0].color[4] == red && a[0][2][0].color[3] == blue) || (a[0][2][0].color[3] == red && a[0][2][0].color[1] == blue) || (a[0][2][0].color[1] == red && a[0][2][0].color[4] == blue) || (a[0][2][0].color[3] == red && a[0][2][0].color[4] == blue) || (a[0][2][0].color[1] == red && a[0][2][0].color[3] == blue) || (a[0][2][0].color[4] == red && a[0][2][0].color[1] == blue)) && (a[0][2][0].color[1] == white || a[0][2][0].color[3] == white || a[0][2][0].color[4] == white)) {
								rb = 1;
								wrong = 2;
								lup = 1;
								start = 1;
							}
						}
						else if (a[1][0][0].color[1] == green && a[1][0][0].color[2] == red) {
							rg = 2;
							wrong = 4;
							up = 1; //требуется 1 поворот
							start = 1;
						}
						else if (a[1][0][0].color[2] == green && a[1][0][0].color[1] == red) {
							rg = 1;
							wrong = 4;
							up = 2; //требуется 2 поворота
							start = 1;
						}
						else if (a[2][1][0].color[1] == green && a[2][1][0].color[5] == red) {
							rg = 2;
							wrong = 4;
							up = 2; //требуется два поворота
							start = 1;
						}
						else if (a[2][1][0].color[5] == green && a[2][1][0].color[1] == red) {
							rg = 1;
							wrong = 4;
							up = 1; //требуется 1 поворот
							start = 1;
						}
					}
					else if (((a[0][2][0].color[1] == red && a[0][2][0].color[4] == green) || (a[0][2][0].color[4] == red && a[0][2][0].color[1] == green) || (a[0][2][0].color[1] == green && a[0][2][0].color[3] == red) || (a[0][2][0].color[3] == green && a[0][2][0].color[1] == red) || (a[0][2][0].color[4] == green && a[0][2][0].color[3] == red)) && (a[0][2][0].color[1] == white || a[0][2][0].color[4] == white || a[0][2][0].color[3] == white) && !((a[0][0][1].color[4] == red && a[0][0][1].color[2] == green) || (a[0][0][1].color[2] == red && a[0][0][1].color[4] == green) || (a[2][0][1].color[5] == red && a[2][0][1].color[2] == green) || (a[2][0][1].color[2] == red && a[2][0][1].color[5] == green) || (a[2][2][1].color[3] == red && a[2][2][1].color[5] == green) || (a[2][2][1].color[5] == red && a[2][2][1].color[3] == green))) {
						wrong = 3;
						rg = 1;
						lup = 1;
						start = 1;
					}
					else if (((a[0][2][0].color[4] == orange && a[0][2][0].color[3] == green) || (a[0][2][0].color[3] == orange && a[0][2][0].color[4] == green) || (a[0][2][0].color[1] == orange && a[0][2][0].color[4] == green) || (a[0][2][0].color[4] == orange && a[0][2][0].color[1] == green) || (a[0][2][0].color[1] == orange && a[0][2][0].color[3] == green) || (a[0][2][0].color[3] == orange && a[0][2][0].color[1] == green)) && (a[0][2][0].color[1] == white || a[0][2][0].color[3] == white || a[0][2][0].color[4] == white) && !((a[0][2][1].color[4] == orange && a[0][2][1].color[3] == green) || (a[0][2][1].color[3] == orange && a[0][2][1].color[5] == green) || (a[0][0][1].color[4] == orange && a[0][0][1].color[2] == green) || (a[0][0][1].color[2] == orange && a[0][0][1].color[4] == green) || (a[2][0][1].color[5] == orange && a[2][0][1].color[2] == green) || (a[2][0][1].color[2] == orange && a[2][0][1].color[5] == green))) {
						og = 1;
						wrong = 2;
						lup = 1;
						start = 1;
							}
					else if (((a[0][2][0].color[4] == orange && a[0][2][0].color[3] == blue) || (a[0][2][0].color[3] == orange && a[0][2][0].color[1] == blue) || (a[0][2][0].color[1] == orange && a[0][2][0].color[4] == blue) || (a[0][2][0].color[3] == orange && a[0][2][0].color[4] == blue) || (a[0][2][0].color[1] == orange && a[0][2][0].color[3] == blue) || (a[0][2][0].color[4] == orange && a[0][2][0].color[1] == blue)) && (a[0][2][0].color[1] == white || a[0][2][0].color[3] == white || a[0][2][0].color[4] == white) && !((a[0][2][1].color[4] == orange && a[0][2][1].color[3] == blue) || (a[0][2][1].color[3] == orange && a[0][2][1].color[4] == blue) || (a[0][0][1].color[4] == orange && a[0][0][1].color[2] == blue) || (a[0][0][1].color[2] == orange && a[0][0][1].color[4] == blue) || (a[2][2][1].color[5] == orange && a[2][2][1].color[3] == blue) || (a[2][2][1].color[3] == orange && a[2][2][1].color[5] == blue))) {
						ob = 1;
						wrong = 2;
						lup = 1;
						start = 1;
						}
					else if (((a[0][2][0].color[4] == red && a[0][2][0].color[3] == blue) || (a[0][2][0].color[3] == red && a[0][2][0].color[1] == blue) || (a[0][2][0].color[1] == red && a[0][2][0].color[4] == blue) || (a[0][2][0].color[3] == red && a[0][2][0].color[4] == blue) || (a[0][2][0].color[1] == red && a[0][2][0].color[3] == blue) || (a[0][2][0].color[4] == red && a[0][2][0].color[1] == blue)) && (a[0][2][0].color[1] == white || a[0][2][0].color[3] == white || a[0][2][0].color[4] == white) && !((a[0][2][1].color[4] == red && a[0][2][1].color[3] == blue) || (a[0][2][1].color[3] == red && a[0][2][1].color[4] == blue) || (a[2][0][1].color[5] == red && a[2][0][1].color[2] == blue) || (a[2][0][1].color[2] == red && a[2][0][1].color[5] == blue) || (a[2][2][1].color[5] == red && a[2][2][1].color[3] == blue) || (a[2][2][1].color[3] == red && a[2][2][1].color[5] == blue))) {
						rb = 1;
						wrong = 2;
						lup = 1;
						start = 1;
					}
				}
				if (rup == 0 && lup == 0 && ldown == 0 && rdown == 0 && up == 0) {
					//printf("R: % d", rup);
					if (!((a[2][2][2].color[5] == orange && a[2][2][2].color[3] == green) || (a[2][2][2].color[3] == orange && a[2][2][2].color[5] == green) || (a[2][2][2].color[0] == orange && a[2][2][2].color[5] == green) || (a[2][2][2].color[5] == orange && a[2][2][2].color[0] == green) || (a[2][2][2].color[0] == green && a[2][2][2].color[3] == orange) || (a[2][2][2].color[3] == green && a[2][2][2].color[0] == orange)) && (a[2][2][2].color[0] == white || a[2][2][2].color[3] == white || a[2][2][2].color[5] == white)) {
						//if (!(a[2][2][0].color[5] == white || a[2][2][0].color[1] == white || a[2][2][0].color[3] == white)) {//если (не)два угла один над другим
							if (((a[2][2][2].color[5] == red && a[2][2][2].color[3] == green) || (a[2][2][2].color[0] == red && a[2][2][2].color[5] == green) || (a[2][2][2].color[0] == green && a[2][2][2].color[3] == red) || (a[2][2][2].color[3] == red && a[2][2][2].color[5] == green) || (a[2][2][2].color[5] == red && a[2][2][2].color[0] == green) || (a[2][2][2].color[3] == green && a[2][2][2].color[0] == red)) && !((a[1][0][0].color[1] == red && a[1][0][0].color[2] == green) || (a[1][0][0].color[1] == green && a[1][0][0].color[2] == red) || (a[0][0][1].color[4] == red && a[0][0][1].color[2] == green) || (a[0][0][1].color[2] == red && a[0][0][1].color[4] == green) || (a[2][0][1].color[5] == red && a[2][0][1].color[2] == green) || (a[2][0][1].color[2] == red && a[2][0][1].color[5] == green))) {
									rg = 1;
									wrong = 1;
									start = 1;
									rup = 1;
							}
							else if (((a[2][2][2].color[5] == red && a[2][2][2].color[3] == blue) || (a[2][2][2].color[0] == red && a[2][2][2].color[5] == blue) || (a[2][2][2].color[0] == blue && a[2][2][2].color[3] == red) || (a[2][2][2].color[3] == red && a[2][2][2].color[5] == blue) || (a[2][2][2].color[5] == red && a[2][2][2].color[0] == blue) || (a[2][2][2].color[3] == blue && a[2][2][2].color[0] == red)) && !((a[1][0][0].color[1] == red && a[1][0][0].color[2] == blue) || (a[1][0][0].color[1] == blue && a[1][0][0].color[2] == red) || (a[0][2][1].color[4] == red && a[0][2][1].color[3] == blue) || (a[0][2][1].color[3] == red && a[0][2][1].color[4] == blue) || (a[2][0][1].color[5] == red && a[2][0][1].color[2] == blue) || (a[2][0][1].color[2] == red && a[2][0][1].color[5] == blue))) {
									rb = 1;
									wrong = 1;
									start = 1;
									rup = 1;
							}
							else if (((a[2][2][2].color[5] == orange && a[2][2][2].color[3] == blue) || (a[2][2][2].color[0] == orange && a[2][2][2].color[5] == blue) || (a[2][2][2].color[0] == blue && a[2][2][2].color[3] == orange) || (a[2][2][2].color[3] == orange && a[2][2][2].color[5] == blue) || (a[2][2][2].color[5] == orange && a[2][2][2].color[0] == blue) || (a[2][2][2].color[3] == blue && a[2][2][2].color[0] == orange)) && !((a[1][0][0].color[1] == orange && a[1][0][0].color[2] == blue) || (a[1][0][0].color[1] == blue && a[1][0][0].color[2] == orange) || (a[0][0][1].color[4] == orange && a[0][0][1].color[2] == blue) || (a[0][0][1].color[2] == orange && a[0][0][1].color[4] == blue) || (a[0][2][1].color[4] == orange && a[0][2][1].color[3] == blue) || (a[0][2][1].color[3] == orange && a[0][2][1].color[4] == blue))) {
									ob = 1;
									wrong = 1;
									start = 1;
									rup = 1;
							}
							else if (((a[2][2][0].color[5] == red && a[2][2][0].color[3] == green) || (a[2][2][0].color[1] == red && a[2][2][0].color[5] == green) || (a[2][2][0].color[1] == green && a[2][2][0].color[3] == red) || (a[2][2][0].color[3] == red && a[2][2][0].color[5] == green) || (a[2][2][0].color[5] == red && a[2][2][0].color[1] == green) || (a[2][2][0].color[3] == green && a[2][2][0].color[1] == red)) && (a[2][2][0].color[1] == white || a[2][2][0].color[3] == white || a[2][2][0].color[5] == white) && !((a[2][2][1].color[5] == red && a[2][2][1].color[3] == green) || (a[2][2][1].color[3] == red && a[2][2][1].color[5] == green) || (a[0][0][1].color[4] == red && a[0][0][1].color[2] == green) || (a[0][0][1].color[2] == red && a[0][0][1].color[4] == green) || (a[2][0][1].color[5] == red && a[2][0][1].color[2] == green) || (a[2][0][1].color[2] == red && a[2][0][1].color[5] == green))) {
								rg = 1;
								wrong = 2;
								start = 1;
								rup = 1;
							}
							else if (((a[2][2][0].color[5] == red && a[2][2][0].color[3] == blue) || (a[2][2][0].color[1] == red && a[2][2][0].color[5] == blue) || (a[2][2][0].color[1] == blue && a[2][2][0].color[3] == red) || (a[2][2][0].color[3] == red && a[2][2][0].color[5] == blue) || (a[2][2][0].color[5] == red && a[2][2][0].color[1] == blue) || (a[2][2][0].color[3] == blue && a[2][2][0].color[1] == red)) && (a[2][2][0].color[1] == white || a[2][2][0].color[3] == white || a[2][2][0].color[5] == white) && !((a[0][2][1].color[4] == red && a[0][2][1].color[3] == blue) || (a[0][2][1].color[3] == red && a[0][2][1].color[4] == blue) || (a[2][2][1].color[5] == red && a[2][2][1].color[3] == blue) || (a[2][2][1].color[3] == red && a[2][2][1].color[5] == blue) || (a[2][0][1].color[5] == red && a[2][0][1].color[2] == blue) || (a[2][0][1].color[2] == red && a[2][0][1].color[5] == blue))) {
								rb = 1;
								wrong = 2;
								start = 1;
								rup = 1;
							}
							else if (((a[2][2][0].color[5] == orange && a[2][2][0].color[3] == blue) || (a[2][2][0].color[1] == orange && a[2][2][0].color[5] == blue) || (a[2][2][0].color[1] == blue && a[2][2][0].color[3] == orange) || (a[2][2][0].color[3] == orange && a[2][2][0].color[5] == blue) || (a[2][2][0].color[5] == orange && a[2][2][0].color[1] == blue) || (a[2][2][0].color[3] == blue && a[2][2][0].color[1] == orange)) && (a[2][2][0].color[1] == white || a[2][2][0].color[3] == white || a[2][2][0].color[5] == white) && !((a[0][2][1].color[4] == orange && a[0][2][1].color[3] == blue) || (a[0][2][1].color[3] == orange && a[0][2][1].color[4] == blue) || (a[0][0][1].color[4] == orange && a[0][0][1].color[2] == blue) || (a[0][0][1].color[2] == orange && a[0][0][1].color[4] == blue) || (a[2][2][1].color[5] == orange && a[2][2][1].color[3] == blue) || (a[2][2][1].color[3] == orange && a[2][2][1].color[5] == blue))) {
								ob = 1;
								wrong = 2;
								start = 1;
								rup = 1;
							}
						//}
						/*else {
							if ((a[2][2][0].color[5] == red && a[2][2][0].color[3] == green) || (a[2][2][0].color[1] == red && a[2][2][0].color[5] == green) || (a[2][2][0].color[1] == green && a[2][2][0].color[3] == red) || (a[2][2][0].color[3] == red && a[2][2][0].color[5] == green) || (a[2][2][0].color[5] == red && a[2][2][0].color[1] == green) || (a[2][2][0].color[3] == green && a[2][2][0].color[1] == red)) {
								rg = 1;
								wrong = 2;
								start = 1;
								rup = 2;
							}
							else if ((a[2][2][0].color[5] == red && a[2][2][0].color[3] == blue) || (a[2][2][0].color[1] == red && a[2][2][0].color[5] == blue) || (a[2][2][0].color[1] == blue && a[2][2][0].color[3] == red) || (a[2][2][0].color[3] == red && a[2][2][0].color[5] == blue) || (a[2][2][0].color[5] == red && a[2][2][0].color[1] == blue) || (a[2][2][0].color[3] == blue && a[2][2][0].color[1] == red)) {
								rb = 1;
								wrong = 2;
								start = 1;
								rup = 2;
							}
							else if ((a[2][2][0].color[5] == orange && a[2][2][0].color[3] == blue) || (a[2][2][0].color[1] == orange && a[2][2][0].color[5] == blue) || (a[2][2][0].color[1] == blue && a[2][2][0].color[3] == orange) || (a[2][2][0].color[3] == orange && a[2][2][0].color[5] == blue) || (a[2][2][0].color[5] == orange && a[2][2][0].color[1] == blue) || (a[2][2][0].color[3] == blue && a[2][2][0].color[1] == orange)) {
								ob = 1;
								wrong = 2;
								start = 1;
								rup = 2;
							}
						}*/
					}
					else if (((a[2][2][2].color[0] == orange && a[2][2][2].color[5] == green) || (a[2][2][2].color[0] == green && a[2][2][2].color[3] == orange) || (a[2][2][2].color[5] == orange && a[2][2][2].color[0] == green) || (a[2][2][2].color[3] == green && a[2][2][2].color[0] == orange) || (a[2][2][2].color[3] == orange && a[2][2][2].color[5] == green)) && (a[2][2][2].color[0] == white || a[2][2][2].color[5] == white || a[2][2][2].color[3] == white)) {
						if ((a[2][1][0].color[5] == orange && a[2][1][0].color[1] == green) || (a[1][2][0].color[1] == orange && a[1][2][0].color[3] == green) || (a[2][2][1].color[5] == orange && a[2][2][1].color[3] == green) || (a[2][2][1].color[3] == orange && a[2][2][1].color[5] == green)) {
							og = 1;
							wrong = 6;
							rup = 1;
							start = 1;
						}
						else if (a[1][0][0].color[1] == green && a[1][0][0].color[2] == orange) {
							og = 2;
							wrong = 4;
							up = 1; //требуется 1 поворот
							start = 1;
						}
						else if (a[1][0][0].color[2] == green && a[1][0][0].color[1] == orange) {
							og = 1;
							wrong = 4;
							up = 2; //требуется 2 поворота
							start = 1;
						}
						else if (a[0][1][0].color[1] == green && a[0][1][0].color[4] == orange) {
							og = 2;
							wrong = 4;
							up = 2; //требуется два поворота
							start = 1;
						}
						else if (a[0][1][0].color[4] == green && a[0][1][0].color[1] == orange) {
							og = 1;
							wrong = 4;
							up = 1; //требуется 1 поворот
							start = 1;
						}
					}
					else if (a[2][2][2].color[3] == green && a[2][2][2].color[5] == orange && a[2][2][2].color[0] == white) {
						if ((a[2][1][0].color[5] == orange && a[2][1][0].color[1] == green) || (a[1][2][0].color[1] == orange && a[1][2][0].color[3] == green) || (a[2][2][1].color[3] == orange && a[2][2][1].color[5] == green)) {
							og = 1;
							wrong = 6;
							rup = 1;
							start = 1;
						}
						else if (a[2][2][1].color[5] == orange && a[2][2][1].color[3] == green) {
							if (((a[2][2][0].color[5] == red && a[2][2][0].color[3] == green) || (a[2][2][0].color[1] == red && a[2][2][0].color[5] == green) || (a[2][2][0].color[1] == green && a[2][2][0].color[3] == red) || (a[2][2][0].color[3] == red && a[2][2][0].color[5] == green) || (a[2][2][0].color[5] == red && a[2][2][0].color[1] == green) || (a[2][2][0].color[3] == green && a[2][2][0].color[1] == red)) && (a[2][2][0].color[1] == white || a[2][2][0].color[3] == white || a[2][2][0].color[5] == white)) {
								rg = 1;
								wrong = 2;
								start = 1;
								rup = 1;
							}
							else if (((a[2][2][0].color[5] == red && a[2][2][0].color[3] == blue) || (a[2][2][0].color[1] == red && a[2][2][0].color[5] == blue) || (a[2][2][0].color[1] == blue && a[2][2][0].color[3] == red) || (a[2][2][0].color[3] == red && a[2][2][0].color[5] == blue) || (a[2][2][0].color[5] == red && a[2][2][0].color[1] == blue) || (a[2][2][0].color[3] == blue && a[2][2][0].color[1] == red)) && (a[2][2][0].color[1] == white || a[2][2][0].color[3] == white || a[2][2][0].color[5] == white)) {
								rb = 1;
								wrong = 2;
								start = 1;
								rup = 1;
							}
							else if (((a[2][2][0].color[5] == orange && a[2][2][0].color[3] == blue) || (a[2][2][0].color[1] == orange && a[2][2][0].color[5] == blue) || (a[2][2][0].color[1] == blue && a[2][2][0].color[3] == orange) || (a[2][2][0].color[3] == orange && a[2][2][0].color[5] == blue) || (a[2][2][0].color[5] == orange && a[2][2][0].color[1] == blue) || (a[2][2][0].color[3] == blue && a[2][2][0].color[1] == orange)) && (a[2][2][0].color[1] == white || a[2][2][0].color[3] == white || a[2][2][0].color[5] == white)) {
								ob = 1;
								wrong = 2;
								start = 1;
								rup = 1;
							}
						}
						else if (a[1][0][0].color[1] == green && a[1][0][0].color[2] == orange) {
							og = 2;
							wrong = 4;
							up = 1; //требуется 1 поворот
							start = 1;
						}
						else if (a[1][0][0].color[2] == green && a[1][0][0].color[1] == orange) {
							og = 1;
							wrong = 4;
							up = 2; //требуется 2 поворота
							start = 1;
						}
						else if (a[0][1][0].color[1] == green && a[0][1][0].color[4] == orange) {
							og = 2;
							wrong = 4;
							up = 2; //требуется два поворота
							start = 1;
						}
						else if (a[0][1][0].color[4] == green && a[0][1][0].color[1] == orange) {
							og = 1;
							wrong = 4;
							up = 1; //требуется 1 поворот
							start = 1;
						}
					}
					else if (((a[2][2][0].color[5] == green && a[2][2][0].color[3] == orange) || (a[2][2][0].color[3] == green && a[2][2][0].color[1] == orange) || (a[2][2][0].color[1] == green && a[2][2][0].color[3] == orange) || (a[2][2][0].color[1] == green && a[2][2][0].color[5] == orange) || (a[2][2][0].color[5] == green && a[2][2][0].color[1] == orange)) && (a[2][2][0].color[1] == white || a[2][2][0].color[3] == white && a[2][2][0].color[5] == white) && !((a[0][2][1].color[4] == orange && a[0][2][1].color[3] == green) || (a[0][2][1].color[3] == orange && a[0][2][1].color[4] == green) || (a[0][0][1].color[4] == orange && a[0][0][1].color[2] == green) || (a[0][0][1].color[2] == orange && a[0][0][1].color[4] == green) || (a[2][0][1].color[5] == orange && a[2][0][1].color[2] == green) || (a[2][0][1].color[2] == orange && a[2][0][1].color[5] == green))) {
						og = 1;
						wrong = 3;
						rup = 1;
						start = 1;
					}
					else if (((a[2][2][0].color[5] == red && a[2][2][0].color[3] == green) || (a[2][2][0].color[1] == red && a[2][2][0].color[5] == green) || (a[2][2][0].color[1] == green && a[2][2][0].color[3] == red) || (a[2][2][0].color[3] == red && a[2][2][0].color[5] == green) || (a[2][2][0].color[5] == red && a[2][2][0].color[1] == green) || (a[2][2][0].color[3] == green && a[2][2][0].color[1] == red)) && (a[2][2][0].color[1] == white || a[2][2][0].color[3] == white || a[2][2][0].color[5] == white) && !((a[2][2][1].color[5] == red && a[2][2][1].color[3] == green) || (a[2][2][1].color[3] == red && a[2][2][1].color[5] == green) || (a[0][0][1].color[4] == red && a[0][0][1].color[2] == green) || (a[0][0][1].color[2] == red && a[0][0][1].color[4] == green) || (a[2][0][1].color[5] == red && a[2][0][1].color[2] == green) || (a[2][0][1].color[2] == red && a[2][0][1].color[5] == green))) {
						rg = 1;
						wrong = 2;
						start = 1;
						rup = 1;
					}
					else if (((a[2][2][0].color[5] == red && a[2][2][0].color[3] == blue) || (a[2][2][0].color[1] == red && a[2][2][0].color[5] == blue) || (a[2][2][0].color[1] == blue && a[2][2][0].color[3] == red) || (a[2][2][0].color[3] == red && a[2][2][0].color[5] == blue) || (a[2][2][0].color[5] == red && a[2][2][0].color[1] == blue) || (a[2][2][0].color[3] == blue && a[2][2][0].color[1] == red)) && (a[2][2][0].color[1] == white || a[2][2][0].color[3] == white || a[2][2][0].color[5] == white) && !((a[0][2][1].color[4] == red && a[0][2][1].color[3] == blue) || (a[0][2][1].color[3] == red && a[0][2][1].color[4] == blue) || (a[2][2][1].color[5] == red && a[2][2][1].color[3] == blue) || (a[2][2][1].color[3] == red && a[2][2][1].color[5] == blue) || (a[2][0][1].color[5] == red && a[2][0][1].color[2] == blue) || (a[2][0][1].color[2] == red && a[2][0][1].color[5] == blue))) {
						rb = 1;
						wrong = 2;
						start = 1;
						rup = 1;
					}
					else if (((a[2][2][0].color[5] == orange && a[2][2][0].color[3] == blue) || (a[2][2][0].color[1] == orange && a[2][2][0].color[5] == blue) || (a[2][2][0].color[1] == blue && a[2][2][0].color[3] == orange) || (a[2][2][0].color[3] == orange && a[2][2][0].color[5] == blue) || (a[2][2][0].color[5] == orange && a[2][2][0].color[1] == blue) || (a[2][2][0].color[3] == blue && a[2][2][0].color[1] == orange)) && (a[2][2][0].color[1] == white || a[2][2][0].color[3] == white || a[2][2][0].color[5] == white) && !((a[0][2][1].color[4] == orange && a[0][2][1].color[3] == blue) || (a[0][2][1].color[3] == orange && a[0][2][1].color[4] == blue) || (a[0][0][1].color[4] == orange && a[0][0][1].color[2] == blue) || (a[0][0][1].color[2] == orange && a[0][0][1].color[4] == blue) || (a[2][2][1].color[5] == orange && a[2][2][1].color[3] == blue) || (a[2][2][1].color[3] == orange && a[2][2][1].color[5] == blue))) {
						ob = 1;
						wrong = 2;
						start = 1;
						rup = 1;
					}
				}
				if (ldown == 0 && lup == 0 && rup == 0 && rdown == 0 && up == 0) {
					//printf("LD:     %d", ldown);
					if (!((a[0][0][2].color[4] == red && a[0][0][2].color[2] == blue) || (a[0][0][2].color[0] == red && a[0][0][2].color[4] == blue) || (a[0][0][2].color[0] == blue && a[0][0][2].color[2] == red)  || (a[0][0][2].color[2] == red && a[0][0][2].color[4] == blue) || (a[0][0][2].color[4] == red && a[0][0][2].color[0] == blue) || (a[0][0][2].color[2] == blue && a[0][0][2].color[0] == red)) && (a[0][0][2].color[0] == white || a[0][0][2].color[4] == white || a[0][0][2].color[2] == white)) {
						//if (!(a[0][0][0].color[4] == white || a[0][0][0].color[1] == white || a[0][0][0].color[2] == white)) {//если (не)два угла один над другим
							if (((a[0][0][2].color[4] == red && a[0][0][2].color[2] == green) || (a[0][0][2].color[0] == red && a[0][0][2].color[4] == green) || (a[0][0][2].color[0] == green && a[0][0][2].color[2] == red) || (a[0][0][2].color[2] == red && a[0][0][2].color[4] == green) || (a[0][0][2].color[4] == red && a[0][0][2].color[0] == green) || (a[0][0][2].color[2] == green && a[0][0][2].color[0] == red)) && !((a[1][2][0].color[1] == red && a[1][2][0].color[3] == green) || (a[1][2][0].color[1] == green && a[1][2][0].color[3] == red) || (a[2][0][1].color[5] == red && a[2][0][1].color[2] == green) || (a[2][0][1].color[2] == red && a[2][0][1].color[5] == green) || (a[2][2][1].color[5] == red && a[2][2][1].color[3] == green) || (a[2][2][1].color[3] == red && a[2][2][1].color[5] == green))) {
								rg = 1;
								wrong = 1;
								start = 1;
								ldown = 1;
							}
							else if (((a[0][0][2].color[4] == orange && a[0][0][2].color[2] == green) || (a[0][0][2].color[0] == orange && a[0][0][2].color[4] == green) || (a[0][0][2].color[0] == green && a[0][0][2].color[2] == orange) || (a[0][0][2].color[2] == orange && a[0][0][2].color[4] == green) || (a[0][0][2].color[4] == orange && a[0][0][2].color[0] == green) || (a[0][0][2].color[2] == green && a[0][0][2].color[0] == orange)) && !((a[1][2][0].color[1] == orange && a[1][2][0].color[3] == green) || (a[1][2][0].color[1] == green && a[1][2][0].color[3] == orange) || (a[2][0][1].color[5] == orange && a[2][0][1].color[2] == green) || (a[2][0][1].color[2] == orange && a[2][0][1].color[5] == green) || (a[0][2][1].color[4] == orange && a[0][2][1].color[3] == green) || (a[0][2][1].color[3] == orange && a[0][2][1].color[4] == green))) {
								og = 1;
								wrong = 1;
								start = 1;
								ldown = 1;
							}
							else if (((a[0][0][2].color[4] == orange && a[0][0][2].color[2] == blue) || (a[0][0][2].color[0] == orange && a[0][0][2].color[4] == blue) || (a[0][0][2].color[0] == blue && a[0][0][2].color[2] == orange) || (a[0][0][2].color[2] == orange && a[0][0][2].color[4] == blue) || (a[0][0][2].color[4] == orange && a[0][0][2].color[0] == blue) || (a[0][0][2].color[2] == blue && a[0][0][2].color[0] == orange)) && !((a[1][2][0].color[1] == orange && a[1][2][0].color[3] == blue) || (a[1][2][0].color[1] == blue && a[1][2][0].color[3] == orange) || (a[2][2][1].color[5] == orange && a[2][2][1].color[3] == blue) || (a[2][2][1].color[3] == orange && a[2][2][1].color[5] == blue) || (a[0][2][1].color[4] == orange && a[0][2][1].color[3] == blue) || (a[0][2][1].color[3] == orange && a[0][2][1].color[4] == blue))) {
								ob = 1;
								wrong = 1;
								start = 1;
								ldown = 1;
							}
							else if (((a[0][0][0].color[4] == red && a[0][0][0].color[2] == green) || (a[0][0][0].color[1] == red && a[0][0][0].color[4] == green) || (a[0][0][0].color[1] == green && a[0][0][0].color[2] == red) || (a[0][0][0].color[2] == red && a[0][0][0].color[4] == green) || (a[0][0][0].color[4] == red && a[0][0][0].color[1] == green) || (a[0][0][0].color[2] == green && a[0][0][0].color[1] == red)) && (a[0][0][0].color[1] == white || a[0][0][0].color[2] == white || a[0][0][0].color[4] == white) && !((a[0][0][1].color[2] == red && a[0][0][1].color[4] == green) || (a[0][0][1].color[2] == green && a[0][0][1].color[4] == red) || (a[2][0][1].color[5] == red && a[2][0][1].color[2] == green) || (a[2][0][1].color[2] == red && a[2][0][1].color[5] == green) || (a[2][2][1].color[5] == red && a[2][2][1].color[3] == green) || (a[2][2][1].color[3] == red && a[2][2][1].color[5] == green))) {
								rg = 1;
								wrong = 2;
								start = 1;
								ldown = 1;
							}
							else if (((a[0][0][0].color[4] == orange && a[0][0][0].color[2] == green) || (a[0][0][0].color[1] == orange && a[0][0][0].color[4] == green) || (a[0][0][0].color[1] == green && a[0][0][0].color[2] == orange) || (a[0][0][0].color[2] == orange && a[0][0][0].color[4] == green) || (a[0][0][0].color[4] == orange && a[0][0][0].color[1] == green) || (a[0][0][0].color[2] == green && a[0][0][0].color[1] == orange)) && (a[0][0][0].color[1] == white || a[0][0][0].color[2] == white || a[0][0][0].color[4] == white) && !((a[0][0][1].color[2] == orange && a[0][0][1].color[4] == green) || (a[0][0][1].color[2] == green && a[0][0][1].color[4] == orange) || (a[2][0][1].color[5] == orange && a[2][0][1].color[2] == green) || (a[2][0][1].color[2] == orange && a[2][0][1].color[5] == green) || (a[0][2][1].color[4] == orange && a[0][2][1].color[3] == green) || (a[0][2][1].color[3] == orange && a[0][2][1].color[4] == green))) {
								og = 1;
								wrong = 2;
								start = 1;
								ldown = 1;
							}
							else if (((a[0][0][0].color[4] == orange && a[0][0][0].color[2] == blue) || (a[0][0][0].color[1] == orange && a[0][0][0].color[4] == blue) || (a[0][0][0].color[1] == blue && a[0][0][0].color[2] == orange) || (a[0][0][0].color[2] == orange && a[0][0][0].color[4] == blue) || (a[0][0][0].color[4] == orange && a[0][0][0].color[1] == blue) || (a[0][0][0].color[2] == blue && a[0][0][0].color[1] == orange)) && (a[0][0][0].color[1] == white || a[0][0][0].color[2] == white || a[0][0][0].color[4] == white) && !((a[0][0][1].color[2] == orange && a[0][0][1].color[4] == blue) || (a[0][0][1].color[2] == blue && a[0][0][1].color[4] == orange) || (a[2][2][1].color[5] == orange && a[2][2][1].color[3] == blue) || (a[2][2][1].color[3] == orange && a[2][2][1].color[5] == blue) || (a[0][2][1].color[4] == orange && a[0][2][1].color[3] == blue) || (a[0][2][1].color[3] == orange && a[0][2][1].color[4] == blue))) {
								ob = 1;
								wrong = 2;
								start = 1;
								ldown = 1;
							}
						//}
						/*else {
							if ((a[0][0][0].color[4] == red && a[0][0][0].color[2] == green) || (a[0][0][0].color[1] == red && a[0][0][0].color[4] == green) || (a[0][0][0].color[1] == green && a[0][0][0].color[2] == red) || (a[0][0][0].color[2] == red && a[0][0][0].color[4] == green) || (a[0][0][0].color[4] == red && a[0][0][0].color[1] == green) || (a[0][0][0].color[2] == green && a[0][0][0].color[1] == red)) {
								rg = 1;
								wrong = 2;
								start = 1;
								ldown = 2;
							}
							else if ((a[0][0][0].color[4] == orange && a[0][0][0].color[2] == green) || (a[0][0][0].color[1] == orange && a[0][0][0].color[4] == green) || (a[0][0][0].color[1] == green && a[0][0][0].color[2] == orange) || (a[0][0][0].color[2] == orange && a[0][0][0].color[4] == green) || (a[0][0][0].color[4] == orange && a[0][0][0].color[1] == green) || (a[0][0][0].color[2] == green && a[0][0][0].color[1] == orange)) {
								og = 1;
								wrong = 2;
								start = 1;
								ldown = 2;
							}
							else if ((a[0][0][0].color[4] == orange && a[0][0][0].color[2] == blue) || (a[0][0][0].color[1] == orange && a[0][0][0].color[4] == blue) || (a[0][0][0].color[1] == blue && a[0][0][0].color[2] == orange) || (a[0][0][0].color[2] == orange && a[0][0][0].color[4] == blue) || (a[0][0][0].color[4] == orange && a[0][0][0].color[1] == blue) || (a[0][0][0].color[2] == blue && a[0][0][0].color[1] == orange)) {
								ob = 1;
								wrong = 2;
								start = 1;
								ldown = 2;
							}
						}*/
					}
					else if (((a[0][0][2].color[0] == red && a[0][0][2].color[4] == blue) || (a[0][0][2].color[4] == red && a[0][0][2].color[0] == blue) || (a[0][0][2].color[0] == blue && a[0][0][2].color[2] == red) || (a[0][0][2].color[2] == blue && a[0][0][2].color[0] == red) || (a[0][0][2].color[4] == blue && a[0][0][2].color[2] == red)) && (a[0][0][2].color[0] == white || a[0][0][2].color[4] == white || a[0][0][2].color[2] == white)) {
						if ((a[0][1][0].color[4] == red && a[0][1][0].color[1] == blue) || (a[1][0][0].color[1] == red && a[1][0][0].color[2] == blue) || (a[0][0][1].color[4] == red && a[0][0][1].color[2] == blue) || (a[0][0][1].color[2] == red && a[0][0][1].color[4] == blue)) {
							rb = 1;
							wrong = 6;
							ldown = 1;
							start = 1;
						}
						else if (a[1][2][0].color[1] == blue && a[1][2][0].color[3] == red) {
							rb = 2;
							wrong = 4;
							up = 1; //требуется 1 поворот
							start = 1;
						}
						else if (a[1][2][0].color[3] == blue && a[1][2][0].color[1] == red) {
							rb = 1;
							wrong = 4;
							up = 2; //требуется 2 поворота
							start = 1;
						}
						else if (a[2][1][0].color[1] == blue && a[2][1][0].color[5] == red) {
							rb = 2;
							wrong = 4;
							up = 2; //требуется два поворота
							start = 1;
						}
						else if (a[2][1][0].color[5] == blue && a[2][1][0].color[1] == red) {
							rb = 1;
							wrong = 4;
							up = 1; //требуется 1 поворот
							start = 1;
						}
					}
					else if (a[0][0][2].color[4] == red && a[0][0][2].color[2] == blue && a[0][0][2].color[0] == white) {
						if ((a[0][1][0].color[4] == red && a[0][1][0].color[1] == blue) || (a[1][0][0].color[1] == red && a[1][0][0].color[2] == blue) || (a[0][0][1].color[2] == red && a[0][0][1].color[4] == blue)) {
							rb = 1;
							wrong = 6;
							ldown = 1;
							start = 1;
						}
						else if (a[0][0][1].color[4] == red && a[0][0][1].color[2] == blue) {
							if (((a[0][0][0].color[4] == red && a[0][0][0].color[2] == green) || (a[0][0][0].color[1] == red && a[0][0][0].color[4] == green) || (a[0][0][0].color[1] == green && a[0][0][0].color[2] == red) || (a[0][0][0].color[2] == red && a[0][0][0].color[4] == green) || (a[0][0][0].color[4] == red && a[0][0][0].color[1] == green) || (a[0][0][0].color[2] == green && a[0][0][0].color[1] == red)) && (a[0][0][0].color[1] == white || a[0][0][0].color[2] == white || a[0][0][0].color[4] == white)) {
								rg = 1;
								wrong = 2;
								start = 1;
								ldown = 1;
							}
							else if (((a[0][0][0].color[4] == orange && a[0][0][0].color[2] == green) || (a[0][0][0].color[1] == orange && a[0][0][0].color[4] == green) || (a[0][0][0].color[1] == green && a[0][0][0].color[2] == orange) || (a[0][0][0].color[2] == orange && a[0][0][0].color[4] == green) || (a[0][0][0].color[4] == orange && a[0][0][0].color[1] == green) || (a[0][0][0].color[2] == green && a[0][0][0].color[1] == orange)) && (a[0][0][0].color[1] == white || a[0][0][0].color[2] == white || a[0][0][0].color[4] == white)) {
								og = 1;
								wrong = 2;
								start = 1;
								ldown = 1;
							}
							else if (((a[0][0][0].color[4] == orange && a[0][0][0].color[2] == blue) || (a[0][0][0].color[1] == orange && a[0][0][0].color[4] == blue) || (a[0][0][0].color[1] == blue && a[0][0][0].color[2] == orange) || (a[0][0][0].color[2] == orange && a[0][0][0].color[4] == blue) || (a[0][0][0].color[4] == orange && a[0][0][0].color[1] == blue) || (a[0][0][0].color[2] == blue && a[0][0][0].color[1] == orange)) && (a[0][0][0].color[1] == white || a[0][0][0].color[2] == white || a[0][0][0].color[4] == white)) {
								ob = 1;
								wrong = 2;
								start = 1;
								ldown = 1;
							}
						}
						else if (a[1][2][0].color[1] == blue && a[1][2][0].color[3] == red) {
							rb = 2;
							wrong = 4;
							up = 1; //требуется 1 поворот
							start = 1;
						}
						else if (a[1][2][0].color[3] == blue && a[1][2][0].color[1] == red) {
							rb = 1;
							wrong = 4;
							up = 2; //требуется 2 поворота
							start = 1;
						}
						else if (a[2][1][0].color[1] == blue && a[2][1][0].color[5] == red) {
							rb = 2;
							wrong = 4;
							up = 2; //требуется два поворота
							start = 1;
						}
						else if (a[2][1][0].color[5] == blue && a[2][1][0].color[1] == red) {
							rb = 1;
							wrong = 4;
							up = 1; //требуется 1 поворот
							start = 1;
						}
					}
					else if (((a[0][0][0].color[2] == red && a[0][0][0].color[4] == blue) || (a[0][0][0].color[4] == red && a[0][0][0].color[1] == blue) || (a[0][0][0].color[1] == red && a[0][0][0].color[4] == blue) || (a[0][0][0].color[1] == red && a[0][0][0].color[2] == blue) || (a[0][0][0].color[2] == red && a[0][0][0].color[1] == blue)) && (a[0][0][0].color[2] == white || a[0][0][0].color[4] == white || a[0][0][0].color[1] == white) && !((a[2][1][0].color[2] == blue && a[2][1][0].color[5] == red) || (a[2][1][0].color[5] == blue && a[2][1][0].color[2] == red) || (a[2][2][1].color[3] == blue && a[2][2][1].color[5] == red) || (a[2][2][1].color[5] == blue && a[2][2][1].color[3] == red) || (a[0][2][1].color[3] == blue && a[0][2][1].color[4] == red) || (a[0][2][1].color[4] == blue && a[0][2][1].color[3] == red))) {
						rb = 1;
						wrong = 3;
						ldown = 1;
						start = 1;
					}
					else if (((a[0][0][0].color[4] == red && a[0][0][0].color[2] == green) || (a[0][0][0].color[1] == red && a[0][0][0].color[4] == green) || (a[0][0][0].color[1] == green && a[0][0][0].color[2] == red) || (a[0][0][0].color[2] == red && a[0][0][0].color[4] == green) || (a[0][0][0].color[4] == red && a[0][0][0].color[1] == green) || (a[0][0][0].color[2] == green && a[0][0][0].color[1] == red)) && (a[0][0][0].color[1] == white || a[0][0][0].color[2] == white || a[0][0][0].color[4] == white) && !((a[0][0][1].color[2] == red && a[0][0][1].color[4] == green) || (a[0][0][1].color[2] == green && a[0][0][1].color[4] == red) || (a[2][0][1].color[5] == red && a[2][0][1].color[2] == green) || (a[2][0][1].color[2] == red && a[2][0][1].color[5] == green) || (a[2][2][1].color[5] == red && a[2][2][1].color[3] == green) || (a[2][2][1].color[3] == red && a[2][2][1].color[5] == green))) {
						rg = 1;
						wrong = 2;
						start = 1;
						ldown = 1;
					}
					else if (((a[0][0][0].color[4] == orange && a[0][0][0].color[2] == green) || (a[0][0][0].color[1] == orange && a[0][0][0].color[4] == green) || (a[0][0][0].color[1] == green && a[0][0][0].color[2] == orange) || (a[0][0][0].color[2] == orange && a[0][0][0].color[4] == green) || (a[0][0][0].color[4] == orange && a[0][0][0].color[1] == green) || (a[0][0][0].color[2] == green && a[0][0][0].color[1] == orange)) && (a[0][0][0].color[1] == white || a[0][0][0].color[2] == white || a[0][0][0].color[4] == white) && !((a[0][0][1].color[2] == orange && a[0][0][1].color[4] == green) || (a[0][0][1].color[2] == green && a[0][0][1].color[4] == orange) || (a[2][0][1].color[5] == orange && a[2][0][1].color[2] == green) || (a[2][0][1].color[2] == orange && a[2][0][1].color[5] == green) || (a[0][2][1].color[4] == orange && a[0][2][1].color[3] == green) || (a[0][2][1].color[3] == orange && a[0][2][1].color[4] == green))) {
						og = 1;
						wrong = 2;
						start = 1;
						ldown = 1;
					}
					else if (((a[0][0][0].color[4] == orange && a[0][0][0].color[2] == blue) || (a[0][0][0].color[1] == orange && a[0][0][0].color[4] == blue) || (a[0][0][0].color[1] == blue && a[0][0][0].color[2] == orange) || (a[0][0][0].color[2] == orange && a[0][0][0].color[4] == blue) || (a[0][0][0].color[4] == orange && a[0][0][0].color[1] == blue) || (a[0][0][0].color[2] == blue && a[0][0][0].color[1] == orange)) && (a[0][0][0].color[1] == white || a[0][0][0].color[2] == white || a[0][0][0].color[4] == white) && !((a[0][0][1].color[2] == orange && a[0][0][1].color[4] == blue) || (a[0][0][1].color[2] == blue && a[0][0][1].color[4] == orange) || (a[2][2][1].color[5] == orange && a[2][2][1].color[3] == blue) || (a[2][2][1].color[3] == orange && a[2][2][1].color[5] == blue) || (a[0][2][1].color[4] == orange && a[0][2][1].color[3] == blue) || (a[0][2][1].color[3] == orange && a[0][2][1].color[4] == blue))) {
						ob = 1;
						wrong = 2;
						start = 1;
						ldown = 1;
					}
				}
				if (rdown == 0 && ldown == 0 && lup == 0 && rup == 0 && up == 0) {
					//printf("RD:     %d", rdown);
					if (!((a[2][0][2].color[5] == orange && a[2][0][2].color[2] == blue) || (a[2][0][2].color[0] == orange && a[2][0][2].color[5] == blue) || (a[2][0][2].color[0] == blue && a[2][0][2].color[2] == orange) || (a[2][0][2].color[2] == orange && a[2][0][2].color[5] == blue) || (a[2][0][2].color[5] == orange && a[2][0][2].color[0] == blue) || (a[2][0][2].color[2] == blue && a[2][0][2].color[0] == orange)) && (a[2][0][2].color[0] == white || a[2][0][2].color[5] == white || a[2][0][2].color[2] == white)) {
						//if (!(a[2][0][0].color[5] == white || a[2][0][0].color[1] == white || a[2][0][0].color[2] == white)) {//если (не)два угла один над другим
							if (((a[2][0][2].color[5] == orange && a[2][0][2].color[2] == green) || (a[2][0][2].color[0] == orange && a[2][0][2].color[5] == green) || (a[2][0][2].color[0] == green && a[2][0][2].color[2] == orange) || (a[2][0][2].color[2] == orange && a[2][0][2].color[5] == green) || (a[2][0][2].color[5] == orange && a[2][0][2].color[0] == green) || (a[2][0][2].color[2] == green && a[2][0][2].color[0] == orange)) && !((a[0][1][0].color[1] == orange && a[0][1][0].color[4] == green) || (a[0][1][0].color[1] == green && a[0][1][0].color[4] == orange) || (a[0][0][1].color[4] == orange && a[0][0][1].color[2] == green) || (a[0][0][1].color[2] == orange && a[0][0][1].color[4] == green) || (a[0][2][1].color[4] == orange && a[0][2][1].color[3] == green) || (a[0][2][1].color[3] == orange && a[0][2][1].color[4] == green))) {
								og = 1;
								wrong = 1;
								start = 1;
								rdown = 1;
							}
							else if (((a[2][0][2].color[5] == red && a[2][0][2].color[2] == green) || (a[2][0][2].color[0] == red && a[2][0][2].color[5] == green) || (a[2][0][2].color[0] == green && a[2][0][2].color[2] == red) || (a[2][0][2].color[2] == red && a[2][0][2].color[5] == green) || (a[2][0][2].color[5] == red && a[2][0][2].color[0] == green) || (a[2][0][2].color[2] == green && a[2][0][2].color[0] == red)) && !((a[0][1][0].color[1] == red && a[0][1][0].color[4] == green) || (a[0][1][0].color[1] == green && a[0][1][0].color[4] == red) || (a[0][0][1].color[4] == red && a[0][0][1].color[2] == green) || (a[0][0][1].color[2] == red && a[0][0][1].color[4] == green) || (a[2][2][1].color[5] == red && a[2][2][1].color[3] == green) || (a[2][2][1].color[3] == red && a[2][2][1].color[5] == green))){
								rg = 1;
								wrong = 1;
								start = 1;
								rdown = 1;
							}
							else if (((a[2][0][2].color[5] == red && a[2][0][2].color[2] == blue) || (a[2][0][2].color[0] == red && a[2][0][2].color[5] == blue) || (a[2][0][2].color[0] == blue && a[2][0][2].color[2] == red) || (a[2][0][2].color[2] == red && a[2][0][2].color[5] == blue) || (a[2][0][2].color[5] == red && a[2][0][2].color[0] == blue) || (a[2][0][2].color[2] == blue && a[2][0][2].color[0] == red)) && !((a[0][1][0].color[1] == red && a[0][1][0].color[4] == blue) || (a[0][1][0].color[1] == blue && a[0][1][0].color[4] == red) || (a[0][2][1].color[4] == red && a[0][2][1].color[3] == blue) || (a[0][2][1].color[3] == red && a[0][2][1].color[4] == blue) || (a[2][2][1].color[5] == red && a[2][2][1].color[3] == blue) || (a[2][2][1].color[3] == red && a[2][2][1].color[5] == blue))){
								rb = 1;
								wrong = 1;
								start = 1;
								rdown = 1;
							}
							else if ((a[2][0][0].color[5] == orange && a[2][0][0].color[2] == green) || (a[2][0][0].color[1] == orange && a[2][0][0].color[5] == green) || (a[2][0][0].color[1] == green && a[2][0][0].color[2] == orange) || (a[2][0][0].color[2] == orange && a[2][0][0].color[5] == green) || (a[2][0][0].color[5] == orange && a[2][0][0].color[1] == green) || (a[2][0][0].color[2] == green && a[2][0][0].color[1] == orange) && (a[2][0][0].color[1] == white || a[2][0][0].color[2] == white || a[2][0][0].color[5] == white) && !((a[2][0][1].color[1] == orange && a[2][0][1].color[5] == green) || (a[2][0][1].color[1] == green && a[2][0][1].color[5] == orange) || (a[0][0][1].color[4] == orange && a[0][0][1].color[2] == green) || (a[0][0][1].color[2] == orange && a[0][0][1].color[4] == green) || (a[0][2][1].color[4] == orange && a[0][2][1].color[3] == green) || (a[0][2][1].color[3] == orange && a[0][2][1].color[4] == green))) {
								og = 1;
								wrong = 2;
								start = 1;
								rdown = 1;
							}
							else if ((a[2][0][0].color[5] == red && a[2][0][0].color[2] == green) || (a[2][0][0].color[1] == red && a[2][0][0].color[5] == green) || (a[2][0][0].color[1] == green && a[2][0][0].color[2] == red) || (a[2][0][0].color[2] == red && a[2][0][0].color[5] == green) || (a[2][0][0].color[5] == red && a[2][0][0].color[1] == green) || (a[2][0][0].color[2] == green && a[2][0][0].color[1] == red) && (a[2][0][0].color[1] == white || a[2][0][0].color[2] == white || a[2][0][0].color[5] == white) && !((a[2][0][1].color[2] == red && a[2][0][1].color[5] == green) || (a[2][0][1].color[2] == green && a[2][0][1].color[5] == red) || (a[0][0][1].color[4] == red && a[0][0][1].color[2] == green) || (a[0][0][1].color[2] == red && a[0][0][1].color[4] == green) || (a[2][2][1].color[5] == red && a[2][2][1].color[3] == green) || (a[2][2][1].color[3] == red && a[2][2][1].color[5] == green))) {
								rg = 1;
								wrong = 2;
								start = 1;
								rdown = 1;
							}
							else if ((a[2][0][0].color[5] == red && a[2][0][0].color[2] == blue) || (a[2][0][0].color[1] == red && a[2][0][0].color[5] == blue) || (a[2][0][0].color[1] == blue && a[2][0][0].color[2] == red) || (a[2][0][0].color[2] == red && a[2][0][0].color[5] == blue) || (a[2][0][0].color[5] == red && a[2][0][0].color[1] == blue) || (a[2][0][0].color[2] == blue && a[2][0][0].color[1] == red) && (a[2][0][0].color[1] == white || a[2][0][0].color[2] == white || a[2][0][0].color[5] == white) && !((a[2][0][1].color[2] == red && a[2][0][1].color[5] == blue) || (a[2][0][1].color[2] == blue && a[2][0][1].color[5] == red) || (a[0][2][1].color[4] == red && a[0][2][1].color[3] == blue) || (a[0][2][1].color[3] == red && a[0][2][1].color[4] == blue) || (a[2][2][1].color[5] == red && a[2][2][1].color[3] == blue) || (a[2][2][1].color[3] == red && a[2][2][1].color[5] == blue))) {
								rb = 1;
								wrong = 2;
								start = 1;
								rdown = 1;
							}
							//}
							/*else {
								if ((a[2][0][0].color[5] == orange && a[2][0][0].color[2] == green) || (a[2][0][0].color[1] == orange && a[2][0][0].color[5] == green) || (a[2][0][0].color[1] == green && a[2][0][0].color[2] == orange) || (a[2][0][0].color[2] == orange && a[2][0][0].color[5] == green) || (a[2][0][0].color[5] == orange && a[2][0][0].color[1] == green) || (a[2][0][0].color[2] == green && a[2][0][0].color[1] == orange)) {
									og = 1;
									wrong = 2;
									start = 1;
									rdown = 2;
								}
								else if ((a[2][0][0].color[5] == red && a[2][0][0].color[2] == green) || (a[2][0][0].color[1] == red && a[2][0][0].color[5] == green) || (a[2][0][0].color[1] == green && a[2][0][0].color[2] == red) || (a[2][0][0].color[2] == red && a[2][0][0].color[5] == green) || (a[2][0][0].color[5] == red && a[2][0][0].color[1] == green) || (a[2][0][0].color[2] == green && a[2][0][0].color[1] == red)) {
									rg = 1;
									wrong = 2;
									start = 1;
									rdown = 2;
								}
								else if ((a[2][0][0].color[5] == red && a[2][0][0].color[2] == blue) || (a[2][0][0].color[1] == red && a[2][0][0].color[5] == blue) || (a[2][0][0].color[1] == blue && a[2][0][0].color[2] == red) || (a[2][0][0].color[2] == red && a[2][0][0].color[5] == blue) || (a[2][0][0].color[5] == red && a[2][0][0].color[1] == blue) || (a[2][0][0].color[2] == blue && a[2][0][0].color[1] == red)) {
									rb = 1;
									wrong = 2;
									start = 1;
									rdown = 2;
								}
							}*/
					}
					else if (((a[2][0][2].color[0] == orange && a[2][0][2].color[5] == blue) || (a[2][0][2].color[5] == orange && a[2][0][2].color[0] == blue) || (a[2][0][2].color[0] == blue && a[2][0][2].color[2] == orange) || (a[2][0][2].color[2] == blue && a[2][0][2].color[0] == orange) || (a[2][0][2].color[5] == blue && a[2][0][2].color[2] == orange)) && (a[2][0][2].color[0] == white || a[2][0][2].color[5] == white || a[2][0][2].color[2] == white)) {
						if ((a[2][1][0].color[5] == orange && a[2][1][0].color[1] == blue) || (a[1][0][0].color[1] == orange && a[1][0][0].color[2] == blue) || (a[2][0][1].color[5] == orange && a[2][0][1].color[2] == blue) || (a[2][0][1].color[2] == orange && a[2][0][1].color[5] == blue)) {
							ob = 1;
							wrong = 6;
							rdown = 1;
							start = 1;
						}
						else if (a[1][2][0].color[1] == blue && a[1][2][0].color[3] == orange) {
							ob = 2;
							wrong = 4;
							up = 1; //требуется 1 поворот
							start = 1;
						}
						else if (a[1][2][0].color[3] == blue && a[1][2][0].color[1] == orange) {
							ob = 1;
							wrong = 4;
							up = 2; //требуется 2 поворота
							start = 1;
						}
						else if (a[0][1][0].color[1] == blue && a[0][1][0].color[4] == orange) {
							ob = 2;
							wrong = 4;
							up = 2; //требуется два поворота
							start = 1;
						}
						else if (a[0][1][0].color[4] == blue && a[0][1][0].color[1] == orange) {
							ob = 1;
							wrong = 4;
							up = 1; //требуется 1 поворот
							start = 1;
						}
					}
					else if (a[2][0][2].color[0] == white && a[2][0][2].color[5] == orange && a[2][0][2].color[2] == blue) {
						if ((a[2][1][0].color[5] == orange && a[2][1][0].color[1] == blue) || (a[1][0][0].color[1] == orange && a[1][0][0].color[2] == blue) || (a[2][0][1].color[2] == orange && a[2][0][1].color[5] == blue)) {
							ob = 1;
							wrong = 6;
							rdown = 1;
							start = 1;
						}
						else if (a[2][0][1].color[2] == blue && a[2][0][1].color[5] == orange) {
							if (((a[2][0][0].color[5] == orange && a[2][0][0].color[2] == green) || (a[2][0][0].color[1] == orange && a[2][0][0].color[5] == green) || (a[2][0][0].color[1] == green && a[2][0][0].color[2] == orange) || (a[2][0][0].color[2] == orange && a[2][0][0].color[5] == green) || (a[2][0][0].color[5] == orange && a[2][0][0].color[1] == green) || (a[2][0][0].color[2] == green && a[2][0][0].color[1] == orange)) && (a[2][0][0].color[1] == white || a[2][0][0].color[2] == white || a[2][0][0].color[5] == white)) {
								og = 1;
								wrong = 2;
								start = 1;
								rdown = 1;
							}
							else if (((a[2][0][0].color[5] == red && a[2][0][0].color[2] == green) || (a[2][0][0].color[1] == red && a[2][0][0].color[5] == green) || (a[2][0][0].color[1] == green && a[2][0][0].color[2] == red) || (a[2][0][0].color[2] == red && a[2][0][0].color[5] == green) || (a[2][0][0].color[5] == red && a[2][0][0].color[1] == green) || (a[2][0][0].color[2] == green && a[2][0][0].color[1] == red)) && (a[2][0][0].color[1] == white || a[2][0][0].color[2] == white || a[2][0][0].color[5] == white)) {
								rg = 1;
								wrong = 2;
								start = 1;
								rdown = 1;
							}
							else if (((a[2][0][0].color[5] == red && a[2][0][0].color[2] == blue) || (a[2][0][0].color[1] == red && a[2][0][0].color[5] == blue) || (a[2][0][0].color[1] == blue && a[2][0][0].color[2] == red) || (a[2][0][0].color[2] == red && a[2][0][0].color[5] == blue) || (a[2][0][0].color[5] == red && a[2][0][0].color[1] == blue) || (a[2][0][0].color[2] == blue && a[2][0][0].color[1] == red)) && (a[2][0][0].color[1] == white || a[2][0][0].color[2] == white || a[2][0][0].color[5] == white)) {
								rb = 1;
								wrong = 2;
								start = 1;
								rdown = 1;
							}
						}
						else if (a[1][2][0].color[1] == blue && a[1][2][0].color[3] == orange) {
							ob = 2;
							wrong = 4;
							up = 1; //требуется 1 поворот
							start = 1;
						}
						else if (a[1][2][0].color[3] == blue && a[1][2][0].color[1] == orange) {
							ob = 1;
							wrong = 4;
							up = 2; //требуется 2 поворота
							start = 1;
						}
						else if (a[0][1][0].color[1] == blue && a[0][1][0].color[4] == orange) {
							ob = 2;
							wrong = 4;
							up = 2; //требуется два поворота
							start = 1;
						}
						else if (a[0][1][0].color[4] == blue && a[0][1][0].color[1] == orange) {
							ob = 1;
							wrong = 4;
							up = 1; //требуется 1 поворот
							start = 1;
						}
					}
					else if (((a[2][0][0].color[5] == blue && a[2][0][0].color[2] == orange) || (a[2][0][0].color[5] == orange && a[2][0][0].color[1] == blue) || (a[2][0][0].color[5] == blue && a[2][0][0].color[1] == orange) || (a[2][0][0].color[2] == blue && a[2][0][0].color[1] == orange) || (a[2][0][0].color[2] == orange && a[2][0][0].color[1] == blue)) && (a[2][0][0].color[1] == white || a[2][0][0].color[2] == white || a[2][0][0].color[5] == white) && !((a[2][2][1].color[3] == orange && a[2][2][1].color[5] == blue) || (a[2][2][1].color[5] == orange && a[2][2][1].color[3] == blue) || (a[0][2][1].color[3] == orange && a[0][2][1].color[4] == blue) || (a[0][2][1].color[4] == orange && a[0][2][1].color[3] == blue) || (a[0][0][1].color[2] == orange && a[0][0][1].color[4] == blue) || (a[0][0][1].color[4] == orange && a[0][0][1].color[2] == blue))) {
						ob = 1;
						wrong = 3;
						rdown = 1;
						start = 1;
					}
					else if (((a[2][0][0].color[5] == orange && a[2][0][0].color[2] == green) || (a[2][0][0].color[1] == orange && a[2][0][0].color[5] == green) || (a[2][0][0].color[1] == green && a[2][0][0].color[2] == orange) || (a[2][0][0].color[2] == orange && a[2][0][0].color[5] == green) || (a[2][0][0].color[5] == orange && a[2][0][0].color[1] == green) || (a[2][0][0].color[2] == green && a[2][0][0].color[1] == orange)) && (a[2][0][0].color[1] == white || a[2][0][0].color[2] == white || a[2][0][0].color[5] == white) && !((a[2][0][1].color[1] == orange && a[2][0][1].color[5] == green) || (a[2][0][1].color[1] == green && a[2][0][1].color[5] == orange) || (a[0][0][1].color[4] == orange && a[0][0][1].color[2] == green) || (a[0][0][1].color[2] == orange && a[0][0][1].color[4] == green) || (a[0][2][1].color[4] == orange && a[0][2][1].color[3] == green) || (a[0][2][1].color[3] == orange && a[0][2][1].color[4] == green))) {
						og = 1;
						wrong = 2;
						start = 1;
						rdown = 1;
				    }
					else if (((a[2][0][0].color[5] == red && a[2][0][0].color[2] == green) || (a[2][0][0].color[1] == red && a[2][0][0].color[5] == green) || (a[2][0][0].color[1] == green && a[2][0][0].color[2] == red) || (a[2][0][0].color[2] == red && a[2][0][0].color[5] == green) || (a[2][0][0].color[5] == red && a[2][0][0].color[1] == green) || (a[2][0][0].color[2] == green && a[2][0][0].color[1] == red)) && (a[2][0][0].color[1] == white || a[2][0][0].color[2] == white || a[2][0][0].color[5] == white) && !((a[2][0][1].color[2] == red && a[2][0][1].color[5] == green) || (a[2][0][1].color[2] == green && a[2][0][1].color[5] == red) || (a[0][0][1].color[4] == red && a[0][0][1].color[2] == green) || (a[0][0][1].color[2] == red && a[0][0][1].color[4] == green) || (a[2][2][1].color[5] == red && a[2][2][1].color[3] == green) || (a[2][2][1].color[3] == red && a[2][2][1].color[5] == green))) {
						rg = 1;
						wrong = 2;
						start = 1;
						rdown = 1;
					}
					else if (((a[2][0][0].color[5] == red && a[2][0][0].color[2] == blue) || (a[2][0][0].color[1] == red && a[2][0][0].color[5] == blue) || (a[2][0][0].color[1] == blue && a[2][0][0].color[2] == red) || (a[2][0][0].color[2] == red && a[2][0][0].color[5] == blue) || (a[2][0][0].color[5] == red && a[2][0][0].color[1] == blue) || (a[2][0][0].color[2] == blue && a[2][0][0].color[1] == red)) && (a[2][0][0].color[1] == white || a[2][0][0].color[2] == white || a[2][0][0].color[5] == white) && !((a[2][0][1].color[2] == red && a[2][0][1].color[5] == blue) || (a[2][0][1].color[2] == blue && a[2][0][1].color[5] == red) || (a[0][2][1].color[4] == red && a[0][2][1].color[3] == blue) || (a[0][2][1].color[3] == red && a[0][2][1].color[4] == blue) || (a[2][2][1].color[5] == red && a[2][2][1].color[3] == blue) || (a[2][2][1].color[3] == red && a[2][2][1].color[5] == blue))) {
						rb = 1;
						wrong = 2;
						start = 1;
						rdown = 1;
					}
				}
			}
			if (wrong == 3) {
				if (a[0][2][0].color[4] == white && a[0][2][0].color[1] == red && a[0][2][0].color[3] == green && a[1][2][0].color[1] == red && a[1][2][0].color[3] == green) {
					rg = 1;
					combination = 3;
					start = 1;

				}
				else if (a[2][2][0].color[1] == green && a[2][2][0].color[5] == orange && a[2][2][0].color[3] == white && a[2][1][0].color[5] == orange && a[2][1][0].color[1] == green) {
					og = 1;
					combination = 3;
					start = 1;

				}
				else if (a[2][0][0].color[1] == orange && a[2][0][0].color[5] == white && a[2][0][0].color[2] == blue && a[1][0][0].color[1] == orange && a[1][0][0].color[2] == blue) {
					ob = 1;
					combination = 3;
					start = 1;

				}
				else if (a[0][0][0].color[1] == blue && a[0][0][0].color[4] == red && a[0][0][0].color[2] == white && a[0][1][0].color[1] == blue && a[0][1][0].color[4] == red) {
					rb = 1;
					combination = 3;
					start = 1;
				}
				
				else if (a[0][2][0].color[4] == red && a[0][2][0].color[1] == green && a[0][2][0].color[3] == white && a[0][1][0].color[1] == green && a[0][1][0].color[4] == red) {
					rg = 1;
					combination = 4;
					start = 1;

				}
				else if (a[2][2][0].color[1] == orange && a[2][2][0].color[5] == white && a[2][2][0].color[3] == green && a[1][2][0].color[3] == green && a[1][2][0].color[1] == orange) {
					og = 1;
					combination = 4;
					start = 1;

				}
				else if (a[2][0][0].color[1] == blue && a[2][0][0].color[5] == orange && a[2][0][0].color[2] == white && a[2][1][0].color[1] == blue && a[2][1][0].color[5] == orange) {
					ob = 1;
					combination = 4;
					start = 1;

				}
				else if (a[0][0][0].color[1] == red && a[0][0][0].color[4] == white && a[0][0][0].color[2] == blue && a[1][0][0].color[2] == blue && a[1][0][0].color[1] == red) {
					rb = 1;
					combination = 4;
					start = 1;
				}
				else if (a[0][2][0].color[4] == red && a[0][2][0].color[1] == green && a[0][2][0].color[3] == white && a[2][1][0].color[5] == green && a[2][1][0].color[1] == red) {
					rg = 1;
					combination = 5;
					start = 1;

				}
				else if (a[2][2][0].color[1] == orange && a[2][2][0].color[5] == white && a[2][2][0].color[3] == green && a[1][0][0].color[1] == green && a[1][0][0].color[2] == orange) {
					og = 1;
					combination = 5;
					start = 1;

				}
				else if (a[2][0][0].color[1] == blue && a[2][0][0].color[5] == orange && a[2][0][0].color[2] == white && a[0][1][0].color[4] == blue && a[0][1][0].color[1] == orange) {
					ob = 1;
					combination = 5;
					start = 1;

				}
				else if (a[0][0][0].color[1] == red && a[0][0][0].color[4] == white && a[0][0][0].color[2] == blue && a[1][2][0].color[1] == blue && a[1][2][0].color[3] == red) {
					rb = 1;
					combination = 5;
					start = 1;
				}
				else if (a[0][2][0].color[1] == red && a[0][2][0].color[3] == green && a[0][2][0].color[4] == white && a[1][0][0].color[1] == green && a[1][0][0].color[2] == red) {
					rg = 1;
					combination = 6;
					start = 1;

				}
				else if (a[2][2][0].color[5] == orange && a[2][2][0].color[3] == white && a[2][2][0].color[1] == green && a[0][1][0].color[4] == green && a[0][1][0].color[1] == orange) {
					og = 1;
					combination = 6;
					start = 1;

				}
				else if (a[2][0][0].color[2] == blue && a[2][0][0].color[1] == orange && a[2][0][0].color[5] == white && a[1][2][0].color[1] == blue && a[1][2][0].color[3] == orange) {
					ob = 1;
					combination = 6;
					start = 1;

				}
				else if (a[0][0][0].color[4] == red && a[0][0][0].color[2] == white && a[0][0][0].color[1] == blue && a[2][1][0].color[5] == blue && a[2][1][0].color[1] == red) {
					rb = 1;
					combination = 6;
					start = 1;
				}
				else if (a[0][2][0].color[1] == red && a[0][2][0].color[3] == green && a[0][2][0].color[4] == white && a[1][0][0].color[2] == green && a[1][0][0].color[1] == red) {
					rg = 1;
					combination = 7;
					start = 1;

				}
				else if (a[2][2][0].color[5] == orange && a[2][2][0].color[3] == white && a[2][2][0].color[1] == green && a[0][1][0].color[1] == green && a[0][1][0].color[4] == orange) {
					og = 1;
					combination = 7;
					start = 1;

				}
				else if (a[2][0][0].color[2] == blue && a[2][0][0].color[1] == orange && a[2][0][0].color[5] == white && a[1][2][0].color[3] == blue && a[1][2][0].color[1] == orange) {
					ob = 1;
					combination = 7;
					start = 1;

				}
				else if (a[0][0][0].color[4] == red && a[0][0][0].color[2] == white && a[0][0][0].color[1] == blue && a[2][1][0].color[1] == blue && a[2][1][0].color[5] == red) {
					rb = 1;
					combination = 7;
					start = 1;
				}
				else if (a[0][2][0].color[4] == red && a[0][2][0].color[1] == green && a[0][2][0].color[3] == white && a[1][0][0].color[1] == green && a[1][0][0].color[2] == red) {
					rg = 1;
					combination = 8;
					start = 1;

				}
				else if (a[2][2][0].color[1] == orange && a[2][2][0].color[5] == white && a[2][2][0].color[3] == green && a[0][1][0].color[4] == green && a[0][1][0].color[1] == orange) {
					og = 1;
					combination = 8;
					start = 1;

				}
				else if (a[2][0][0].color[1] == blue && a[2][0][0].color[5] == orange && a[2][0][0].color[2] == white && a[1][2][0].color[1] == blue && a[1][2][0].color[3] == orange) {
					ob = 1;
					combination = 8;
					start = 1;

				}
				else if (a[0][0][0].color[1] == red && a[0][0][0].color[4] == white && a[0][0][0].color[2] == blue && a[2][1][0].color[5] == blue && a[2][1][0].color[1] == red) {
					rb = 1;
					combination = 8;
					start = 1;
				}
				else if (a[0][2][0].color[1] == red && a[0][2][0].color[3] == green && a[0][2][0].color[4] == white && a[2][1][0].color[5] == green && a[2][1][0].color[1] == red) {
					rg = 1;
					combination = 9;
					start = 1;

				}
				else if (a[2][2][0].color[5] == orange && a[2][2][0].color[3] == white && a[2][2][0].color[1] == green && a[1][0][0].color[1] == green && a[1][0][0].color[2] == orange) {
					og = 1;
					combination = 9;
					start = 1;

				}
				else if (a[2][0][0].color[2] == blue && a[2][0][0].color[1] == orange && a[2][0][0].color[5] == white && a[0][1][0].color[4] == blue && a[0][1][0].color[1] == orange) {
					ob = 1;
					combination = 9;
					start = 1;

				}
				else if (a[0][0][0].color[4] == red && a[0][0][0].color[2] == white && a[0][0][0].color[1] == blue && a[1][2][0].color[1] == blue && a[1][2][0].color[3] == red) {
					rb = 1;
					combination = 9;
					start = 1;
				}
				else if (a[0][2][0].color[4] == red && a[0][2][0].color[1] == green && a[0][2][0].color[3] == white && a[2][1][0].color[1] == green && a[2][1][0].color[5] == red) {
					rg = 1;
					combination = 10;
					start = 1;

				}
				else if (a[2][2][0].color[1] == orange && a[2][2][0].color[5] == white && a[2][2][0].color[3] == green && a[1][0][0].color[2] == green && a[1][0][0].color[1] == orange) {
					og = 1;
					combination = 10;
					start = 1;
				}
				else if (a[2][0][0].color[1] == blue && a[2][0][0].color[5] == orange && a[2][0][0].color[2] == white && a[0][1][0].color[1] == blue && a[0][1][0].color[4] == orange) {
					ob = 1;
					combination = 10;
					start = 1;

				}
				else if (a[0][0][0].color[1] == red && a[0][0][0].color[4] == white && a[0][0][0].color[2] == blue && a[1][2][0].color[3] == blue && a[1][2][0].color[1] == red) {
					rb = 1;
					combination = 10;
					start = 1;
				}
				else if (a[0][2][0].color[1] == red && a[0][2][0].color[3] == green && a[0][2][0].color[4] == white && a[2][1][0].color[1] == green && a[2][1][0].color[5] == red) {
					rg = 1;
					combination = 11;
					start = 1;

				}
				else if (a[2][2][0].color[5] == orange && a[2][2][0].color[3] == white && a[2][2][0].color[1] == green && a[1][0][0].color[2] == green && a[1][0][0].color[1] == orange) {
					og = 1;
					combination = 11;
					start = 1;

				}
				else if (a[2][0][0].color[2] == blue && a[2][0][0].color[1] == orange && a[2][0][0].color[5] == white && a[0][1][0].color[1] == blue && a[0][1][0].color[4] == orange) {
					ob = 1;
					combination = 11;
					start = 1;

				}
				else if (a[0][0][0].color[4] == red && a[0][0][0].color[2] == white && a[0][0][0].color[1] == blue && a[1][2][0].color[3] == blue && a[1][2][0].color[1] == red) {
					rb = 1;
					combination = 11;
					start = 1;
				}
				else if (a[0][2][0].color[4] == red && a[0][2][0].color[1] == green && a[0][2][0].color[3] == white && a[1][0][0].color[2] == green && a[1][0][0].color[1] == red) {
					rg = 1;
					combination = 12;
					start = 1;

				}
				else if (a[2][2][0].color[1] == orange && a[2][2][0].color[5] == white && a[2][2][0].color[3] == green && a[0][1][0].color[1] == green && a[0][1][0].color[4] == orange) {
					og = 1;
					combination = 12;
					start = 1;

				}
				else if (a[2][0][0].color[1] == blue && a[2][0][0].color[5] == orange && a[2][0][0].color[2] == white && a[1][2][0].color[3] == blue && a[1][2][0].color[1] == orange) {
					ob = 1;
					combination = 12;
					start = 1;

				}
				else if (a[0][0][0].color[1] == red && a[0][0][0].color[4] == white && a[0][0][0].color[2] == blue && a[2][1][0].color[1] == blue && a[2][1][0].color[5] == red) {
					rb = 1;
					combination = 12;
					start = 1;
				}
				else if (a[0][2][0].color[1] == red && a[0][2][0].color[3] == green && a[0][2][0].color[4] == white && a[0][1][0].color[1] == green && a[0][1][0].color[4] == red) {
					rg = 1;
					combination = 13;
					start = 1;

				}
				else if (a[2][2][0].color[5] == orange && a[2][2][0].color[3] == white && a[2][2][0].color[1] == green && a[1][2][0].color[3] == green && a[1][2][0].color[1] == orange) {
					og = 1;
					combination = 13;
					start = 1;

				}
				else if (a[2][0][0].color[2] == blue && a[2][0][0].color[1] == orange && a[2][0][0].color[5] == white && a[2][1][0].color[1] == blue && a[2][1][0].color[5] == orange) {
					ob = 1;
					combination = 13;
					start = 1;

				}
				else if (a[0][0][0].color[4] == red && a[0][0][0].color[2] == white && a[0][0][0].color[1] == blue && a[1][0][0].color[2] == blue && a[1][0][0].color[1] == red) {
					rb = 1;
					combination = 13;
					start = 1;
				}
				else if (a[0][2][0].color[4] == red && a[0][2][0].color[1] == green && a[0][2][0].color[3] == white && a[0][1][0].color[4] == green && a[0][1][0].color[1] == red) {
					rg = 1;
					combination = 14;
					start = 1;

				}
				else if (a[2][2][0].color[1] == orange && a[2][2][0].color[5] == white && a[2][2][0].color[3] == green && a[1][2][0].color[1] == green && a[1][2][0].color[3] == orange) {
					og = 1;
					combination = 14;
					start = 1;

				}
				else if (a[2][0][0].color[1] == blue && a[2][0][0].color[5] == orange && a[2][0][0].color[2] == white && a[2][1][0].color[5] == blue && a[2][1][0].color[1] == orange) {
					ob = 1;
					combination = 14;
					start = 1;

				}
				else if (a[0][0][0].color[1] == red && a[0][0][0].color[4] == white && a[0][0][0].color[2] == blue && a[1][0][0].color[1] == blue && a[1][0][0].color[2] == red) {
					rb = 1;
					combination = 14;
					start = 1;
				}
				else if (a[0][2][0].color[1] == red && a[0][2][0].color[3] == green && a[0][2][0].color[4] == white && a[1][2][0].color[1] == green && a[1][2][0].color[3] == red) {
					rg = 1;
					combination = 15;
					start = 1;

				}
				else if (a[2][2][0].color[5] == orange && a[2][2][0].color[3] == white && a[2][2][0].color[1] == green && a[2][1][0].color[5] == green && a[2][1][0].color[1] == orange) {
					og = 1;
					combination = 15;
					start = 1;

				}
				else if (a[2][0][0].color[2] == blue && a[2][0][0].color[1] == orange && a[2][0][0].color[5] == white && a[1][0][0].color[1] == blue && a[1][0][0].color[2] == orange) {
					ob = 1;
					combination = 15;
					start = 1;

				}
				else if (a[0][0][0].color[4] == red && a[0][0][0].color[2] == white && a[0][0][0].color[1] == blue && a[0][1][0].color[4] == blue && a[0][1][0].color[1] == red) {
					rb = 1;
					combination = 15;
					start = 1;
				}
				else if (a[0][2][0].color[4] == red && a[0][2][0].color[1] == green && a[0][2][0].color[3] == white && a[1][2][0].color[3] == green && a[1][2][0].color[1] == red) {
					rg = 1;
					combination = 16;
					start = 1;

				}
				else if (a[2][2][0].color[1] == orange && a[2][2][0].color[5] == white && a[2][2][0].color[3] == green && a[2][1][0].color[1] == green && a[2][1][0].color[5] == orange) {
					og = 1;
					combination = 16;
					start = 1;

				}
				else if (a[2][0][0].color[1] == blue && a[2][0][0].color[5] == orange && a[2][0][0].color[2] == white && a[1][0][0].color[2] == blue && a[1][0][0].color[1] == orange) {
					ob = 1;
					combination = 16;
					start = 1;

				}
				else if (a[0][0][0].color[1] == red && a[0][0][0].color[4] == white && a[0][0][0].color[2] == blue && a[0][1][0].color[1] == blue && a[0][1][0].color[4] == red) {
					rb = 1;
					combination = 16;
					start = 1;
				}
				else if (a[0][2][0].color[1] == red && a[0][2][0].color[3] == green && a[0][2][0].color[4] == white && a[0][1][0].color[4] == green && a[0][1][0].color[1] == red) {
					rg = 1;
					combination = 17;
					start = 1;

				}
				else if (a[2][2][0].color[5] == orange && a[2][2][0].color[3] == white && a[2][2][0].color[1] == green && a[1][2][0].color[1] == green && a[1][2][0].color[3] == orange) {
					og = 1;
					combination = 17;
					start = 1;

				}
				else if (a[2][0][0].color[2] == blue && a[2][0][0].color[1] == orange && a[2][0][0].color[5] == white && a[2][1][0].color[5] == blue && a[2][1][0].color[1] == orange) {
					ob = 1;
					combination = 17;
					start = 1;

				}
				else if (a[0][0][0].color[4] == red && a[0][0][0].color[2] == white && a[0][0][0].color[1] == blue && a[1][0][0].color[1] == blue && a[1][0][0].color[2] == red) {
					rb = 1;
					combination = 17;
					start = 1;
				}
				else if (a[0][2][0].color[4] == red && a[0][2][0].color[1] == green && a[0][2][0].color[3] == white && a[1][2][0].color[1] == green && a[1][2][0].color[3] == red) {
					rg = 1;
					combination = 18;
					start = 1;

				}
				else if (a[2][2][0].color[1] == orange && a[2][2][0].color[5] == white && a[2][2][0].color[3] == green && a[2][1][0].color[5] == green && a[2][1][0].color[1] == orange) {
					og = 1;
					combination = 18;
					start = 1;

				}
				else if (a[2][0][0].color[1] == blue && a[2][0][0].color[5] == orange && a[2][0][0].color[2] == white && a[1][0][0].color[1] == blue && a[1][0][0].color[2] == orange) {
					ob = 1;
					combination = 18;
					start = 1;

				}
				else if (a[0][0][0].color[1] == red && a[0][0][0].color[4] == white && a[0][0][0].color[2] == blue && a[0][1][0].color[4] == blue && a[0][1][0].color[1] == red) {
					rb = 1;
					combination = 18;
					start = 1;
				}
				else if (a[0][2][0].color[3] == red && a[0][2][0].color[1] == green && a[0][2][0].color[4] == white && a[1][2][0].color[3] == green && a[1][2][0].color[1] == red) {
					rg = 1;
					combination = 19;
					start = 1;

				}
				else if (a[2][2][0].color[1] == orange && a[2][2][0].color[3] == white && a[2][2][0].color[5] == green && a[2][1][0].color[1] == green && a[2][1][0].color[5] == orange) {
					og = 1;
					combination = 19;
					start = 1;

				}
				else if (a[2][0][0].color[1] == blue && a[2][0][0].color[2] == orange && a[2][0][0].color[5] == white && a[1][0][0].color[2] == blue && a[1][0][0].color[1] == orange) {
					ob = 1;
					combination = 19;
					start = 1;

				}
				else if (a[0][0][0].color[1] == red && a[0][0][0].color[2] == white && a[0][0][0].color[4] == blue && a[0][1][0].color[1] == blue && a[0][1][0].color[4] == red) {
					rb = 1;
					combination = 19;
					start = 1;
				}
				else if (a[0][2][0].color[3] == red && a[0][2][0].color[4] == green && a[0][2][0].color[1] == white && a[0][1][0].color[1] == green && a[0][1][0].color[4] == red) {
					rg = 1;
					combination = 20;
					start = 1;

				}
				else if (a[2][2][0].color[3] == orange && a[2][2][0].color[1] == white && a[2][2][0].color[5] == green && a[1][2][0].color[3] == green && a[1][2][0].color[1] == orange) {
					og = 1;
					combination = 20;
					start = 1;

				}
				else if (a[2][0][0].color[5] == blue && a[2][0][0].color[2] == orange && a[2][0][0].color[1] == white && a[2][1][0].color[1] == blue && a[2][1][0].color[5] == orange) {
					ob = 1;
					combination = 20;
					start = 1;

				}
				else if (a[0][0][0].color[2] == red && a[0][0][0].color[1] == white && a[0][0][0].color[4] == blue && a[1][0][0].color[2] == blue && a[1][0][0].color[1] == red) {
					rb = 1;
					combination = 20;
					start = 1;
				}
				else if (a[0][2][0].color[3] == red && a[0][2][0].color[4] == green && a[0][2][0].color[1] == white && a[2][1][0].color[5] == green && a[2][1][0].color[1] == red) {
					rg = 1;
					combination = 21;
					start = 1;

				}
				else if (a[2][2][0].color[3] == orange && a[2][2][0].color[1] == white && a[2][2][0].color[5] == green && a[1][0][0].color[1] == green && a[1][0][0].color[2] == orange) {
					og = 1;
					combination = 21;
					start = 1;

				}
				else if (a[2][0][0].color[5] == blue && a[2][0][0].color[2] == orange && a[2][0][0].color[1] == white && a[0][1][0].color[4] == blue && a[0][1][0].color[1] == orange) {
					ob = 1;
					combination = 21;
					start = 1;

				}
				else if (a[0][0][0].color[2] == red && a[0][0][0].color[1] == white && a[0][0][0].color[4] == blue && a[1][2][0].color[1] == blue && a[1][2][0].color[3] == red) {
					rb = 1;
					combination = 21;
					start = 1;
				}
				else if (a[0][2][0].color[3] == red && a[0][2][0].color[4] == green && a[0][2][0].color[1] == white && a[1][0][0].color[2] == green && a[1][0][0].color[1] == red) {
					rg = 1;
					combination = 22;
					start = 1;

				}
				else if (a[2][2][0].color[3] == orange && a[2][2][0].color[1] == white && a[2][2][0].color[5] == green && a[0][1][0].color[1] == green && a[0][1][0].color[4] == orange) {
					og = 1;
					combination = 22;
					start = 1;

				}
				else if (a[2][0][0].color[5] == blue && a[2][0][0].color[2] == orange && a[2][0][0].color[1] == white && a[1][2][0].color[3] == blue && a[1][2][0].color[1] == orange) {
					ob = 1;
					combination = 22;
					start = 1;

				}
				else if (a[0][0][0].color[2] == red && a[0][0][0].color[1] == white && a[0][0][0].color[4] == blue && a[2][1][0].color[1] == blue && a[2][1][0].color[5] == red) {
					rb = 1;
					combination = 22;
					start = 1;
				}
				else if (a[0][2][0].color[3] == red && a[0][2][0].color[4] == green && a[0][2][0].color[1] == white && a[1][0][0].color[1] == green && a[1][0][0].color[2] == red) {
					rg = 1;
					combination = 23;
					start = 1;

				}
				else if (a[2][2][0].color[3] == orange && a[2][2][0].color[1] == white && a[2][2][0].color[5] == green && a[0][1][0].color[4] == green && a[0][1][0].color[1] == orange) {
					og = 1;
					combination = 23;
					start = 1;

				}
				else if (a[2][0][0].color[5] == blue && a[2][0][0].color[2] == orange && a[2][0][0].color[1] == white && a[1][2][0].color[1] == blue && a[1][2][0].color[3] == orange) {
					ob = 1;
					combination = 23;
					start = 1;

				}
				else if (a[0][0][0].color[2] == red && a[0][0][0].color[1] == white && a[0][0][0].color[4] == blue && a[2][1][0].color[5] == blue && a[2][1][0].color[1] == red) {
					rb = 1;
					combination = 23;
					start = 1;
				}
				else if (a[0][2][0].color[3] == red && a[0][2][0].color[4] == green && a[0][2][0].color[1] == white && a[2][1][0].color[1] == green && a[2][1][0].color[5] == red) {
					rg = 1;
					combination = 24;
					start = 1;

				}
				else if (a[2][2][0].color[3] == orange && a[2][2][0].color[1] == white && a[2][2][0].color[5] == green && a[1][0][0].color[2] == green && a[1][0][0].color[1] == orange) {
					og = 1;
					combination = 24;
					start = 1;

				}
				else if (a[2][0][0].color[5] == blue && a[2][0][0].color[2] == orange && a[2][0][0].color[1] == white && a[0][1][0].color[1] == blue && a[0][1][0].color[4] == orange) {
					ob = 1;
					combination = 24;
					start = 1;

				}
				else if (a[0][0][0].color[2] == red && a[0][0][0].color[1] == white && a[0][0][0].color[4] == blue && a[1][2][0].color[3] == blue && a[1][2][0].color[1] == red) {
					rb = 1;
					combination = 24;
					start = 1;
				}
				else if (a[0][2][0].color[3] == red && a[0][2][0].color[4] == green && a[0][2][0].color[1] == white && a[0][1][0].color[4] == green && a[0][1][0].color[1] == red) {
					rg = 1;
					combination = 25;
					start = 1;

				}
				else if (a[2][2][0].color[3] == orange && a[2][2][0].color[1] == white && a[2][2][0].color[5] == green && a[1][2][0].color[1] == green && a[1][2][0].color[3] == orange) {
					og = 1;
					combination = 25;
					start = 1;

				}
				else if (a[2][0][0].color[5] == blue && a[2][0][0].color[2] == orange && a[2][0][0].color[1] == white && a[2][1][0].color[5] == blue && a[2][1][0].color[1] == orange) {
					ob = 1;
					combination = 25;
					start = 1;

				}
				else if (a[0][0][0].color[2] == red && a[0][0][0].color[1] == white && a[0][0][0].color[4] == blue && a[1][0][0].color[1] == blue && a[1][0][0].color[2] == red) {
					rb = 1;
					combination = 25;
					start = 1;
				}
				else if (a[0][2][0].color[3] == red && a[0][2][0].color[4] == green && a[0][2][0].color[1] == white && a[1][2][0].color[1] == green && a[1][2][0].color[3] == red) {
					rg = 1;
					combination = 26;
					start = 1;

				}
				else if (a[2][2][0].color[3] == orange && a[2][2][0].color[1] == white && a[2][2][0].color[5] == green && a[2][1][0].color[5] == green && a[2][1][0].color[1] == orange) {
					og = 1;
					combination = 26;
					start = 1;

				}
				else if (a[2][0][0].color[5] == blue && a[2][0][0].color[2] == orange && a[2][0][0].color[1] == white && a[1][0][0].color[1] == blue && a[1][0][0].color[2] == orange) {
					ob = 1;
					combination = 26;
					start = 1;

				}
				else if (a[0][0][0].color[2] == red && a[0][0][0].color[1] == white && a[0][0][0].color[4] == blue && a[0][1][0].color[4] == blue && a[0][1][0].color[1] == red) {
					rb = 1;
					combination = 26;
					start = 1;
				}
				else if (a[0][2][0].color[3] == red && a[0][2][0].color[4] == green && a[0][2][0].color[1] == white && a[0][2][1].color[4] == green && a[0][2][1].color[3] == red) {
					rg = 1;
					combination = 31;
					start = 1;

				}
				else if (a[2][2][0].color[3] == orange && a[2][2][0].color[1] == white && a[2][2][0].color[5] == green && a[2][2][1].color[5] == green && a[2][2][1].color[3] == orange) {
					og = 1;
					combination = 31;
					start = 1;

				}
				else if (a[2][0][0].color[5] == blue && a[2][0][0].color[2] == orange && a[2][0][0].color[1] == white && a[2][0][1].color[5] == blue && a[2][0][1].color[2] == orange) {
					ob = 1;
					combination = 31;
					start = 1;

				}
				else if (a[0][0][0].color[2] == red && a[0][0][0].color[1] == white && a[0][0][0].color[4] == blue && a[0][0][1].color[4] == blue && a[0][0][1].color[2] == red) {
					rb = 1;
					combination = 31;
					start = 1;
				}
				else if (a[0][2][0].color[1] == red && a[0][2][0].color[3] == green && a[0][2][0].color[4] == white && a[0][2][1].color[4] == green && a[0][2][1].color[3] == red) {
					rg = 1;
					combination = 32;
					start = 1;

				}
				else if (a[2][2][0].color[5] == orange && a[2][2][0].color[3] == white && a[2][2][0].color[1] == green && a[2][2][1].color[5] == green && a[2][2][1].color[3] == orange) {
					og = 1;
					combination = 32;
					start = 1;

				}
				else if (a[2][0][0].color[2] == blue && a[2][0][0].color[1] == orange && a[2][0][0].color[5] == white && a[2][0][1].color[5] == blue && a[2][0][1].color[2] == orange) {
					ob = 1;
					combination = 32;
					start = 1;

				}
				else if (a[0][0][0].color[4] == red && a[0][0][0].color[2] == white && a[0][0][0].color[1] == blue && a[0][0][1].color[4] == blue && a[0][0][1].color[2] == red) {
					rb = 1;
					combination = 32;
					start = 1;
				}
				else if (a[0][2][0].color[3] == red && a[0][2][0].color[4] == green && a[0][2][0].color[1] == white && a[0][2][1].color[3] == green && a[0][2][1].color[4] == red) {
					rg = 1;
					combination = 33;
					start = 1;

				}
				else if (a[2][2][0].color[3] == orange && a[2][2][0].color[1] == white && a[2][2][0].color[5] == green && a[2][2][1].color[3] == green && a[2][2][1].color[5] == orange) {
					og = 1;
					combination = 33;
					start = 1;

				}
				else if (a[2][0][0].color[5] == blue && a[2][0][0].color[2] == orange && a[2][0][0].color[1] == white && a[2][0][1].color[2] == blue && a[2][0][1].color[5] == orange) {
					ob = 1;
					combination = 33;
					start = 1;

				}
				else if (a[0][0][0].color[2] == red && a[0][0][0].color[1] == white && a[0][0][0].color[4] == blue && a[0][0][1].color[2] == blue && a[0][0][1].color[4] == red) {
					rb = 1;
					combination = 33;
					start = 1;
				}
				else if (a[0][2][0].color[4] == red && a[0][2][0].color[1] == green && a[0][2][0].color[3] == white && a[0][2][1].color[4] == green && a[0][2][1].color[3] == red) {
					rg = 1;
					combination = 34;
					start = 1;

				}
				else if (a[2][2][0].color[1] == orange && a[2][2][0].color[5] == white && a[2][2][0].color[3] == green && a[2][2][1].color[5] == green && a[2][2][1].color[3] == orange) {
					og = 1;
					combination = 34;
					start = 1;

				}
				else if (a[2][0][0].color[1] == blue && a[2][0][0].color[5] == orange && a[2][0][0].color[2] == white && a[2][0][1].color[5] == blue && a[2][0][1].color[2] == orange) {
					ob = 1;
					combination = 34;
					start = 1;

				}
				else if (a[0][0][0].color[1] == red && a[0][0][0].color[4] == white && a[0][0][0].color[2] == blue && a[0][0][1].color[4] == blue && a[0][0][1].color[2] == red) {
					rb = 1;
					combination = 34;
					start = 1;
				}
				else if (a[0][2][0].color[3] == red && a[0][2][0].color[1] == green && a[0][2][0].color[4] == white && a[0][2][1].color[3] == green && a[0][2][1].color[4] == red) {
					rg = 1;
					combination = 35;
					start = 1;

				}
				else if (a[2][2][0].color[1] == orange && a[2][2][0].color[3] == white && a[2][2][0].color[5] == green && a[2][2][1].color[3] == green && a[2][2][1].color[5] == orange) {
					og = 1;
					combination = 35;
					start = 1;

				}
				else if (a[2][0][0].color[1] == blue && a[2][0][0].color[2] == orange && a[2][0][0].color[5] == white && a[2][0][1].color[2] == blue && a[2][0][1].color[5] == orange) {
					ob = 1;
					combination = 35;
					start = 1;

				}
				else if (a[0][0][0].color[1] == red && a[0][0][0].color[2] == white && a[0][0][0].color[4] == blue && a[0][0][1].color[2] == blue && a[0][0][1].color[4] == red) {
					rb = 1;
					combination = 35;
					start = 1;
				}
				else if (a[0][2][0].color[4] == red && a[0][2][0].color[1] == green && a[0][2][0].color[3] == white && a[0][2][1].color[3] == green && a[0][2][1].color[4] == red) {
					rg = 1;
					combination = 36;
					start = 1;

				}
				else if (a[2][2][0].color[1] == orange && a[2][2][0].color[5] == white && a[2][2][0].color[3] == green && a[2][2][1].color[3] == green && a[2][2][1].color[5] == orange) {
					og = 1;
					combination = 36;
					start = 1;

				}
				else if (a[2][0][0].color[1] == blue && a[2][0][0].color[5] == orange && a[2][0][0].color[2] == white && a[2][0][1].color[2] == blue && a[2][0][1].color[5] == orange) {
					ob = 1;
					combination = 36;
					start = 1;

				}
				/*else if (a[0][0][0].color[1] == red && a[0][0][0].color[4] == white && a[0][0][0].color[2] == blue && a[0][0][1].color[2] == blue && a[0][0][1].color[4] == red) {
					rb = 1;
					combination = 36;
					start = 1;
				}*/
			}
			if (wrong == 6) {
				if (a[0][2][2].color[0] == white && a[0][2][2].color[4] == red && a[0][2][2].color[3] == green && a[0][1][0].color[1] == green && a[0][1][0].color[4] == red) {
					rg = 1;
					combination = 1;
					start = 1;
				}
				else if (a[2][2][2].color[0] == white && a[2][2][2].color[5] == orange && a[2][2][2].color[3] == green && a[1][2][0].color[1] == orange && a[1][2][0].color[3] == green) {
					og = 1;
					combination = 1;
					start = 1;
				}
				else if (a[2][0][2].color[0] == white && a[2][0][2].color[5] == orange && a[2][0][2].color[2] == blue && a[2][1][0].color[1] == blue && a[2][1][0].color[5] == orange) {
					ob = 1;
					combination = 1;
					start = 1;
				}
				else if (a[0][0][2].color[0] == white && a[0][0][2].color[4] == red && a[0][0][2].color[2] == blue && a[1][0][0].color[1] == red && a[1][0][0].color[2] == blue) {
					rb = 1;
					combination = 1;
					start = 1;
				}
				else if (a[0][2][2].color[0] == white && a[0][2][2].color[4] == red && a[0][2][2].color[3] == green && a[1][2][0].color[1] == red && a[1][2][0].color[3] == green) {
					rg = 1;
					combination = 2;
					start = 1;
				}
				else if (a[2][2][2].color[0] == white && a[2][2][2].color[5] == orange && a[2][2][2].color[3] == green && a[2][1][0].color[5] == orange && a[2][1][0].color[1] == green) {
					og = 1;
					combination = 2;
					start = 1;
				}
				else if (a[2][0][2].color[0] == white && a[2][0][2].color[5] == orange && a[2][0][2].color[2] == blue && a[1][0][0].color[1] == orange && a[1][0][0].color[2] == blue) {
					ob = 1;
					combination = 2;
					start = 1;

				}
				else if (a[0][0][2].color[0] == white && a[0][0][2].color[4] == red && a[0][0][2].color[2] == blue && a[0][1][0].color[1] == blue && a[0][1][0].color[4] == red) {
					rb = 1;
					combination = 2;
					start = 1;
				}
				else if (a[0][2][2].color[3] == red && a[0][2][2].color[0] == green && a[0][2][2].color[4] == white && a[0][1][0].color[1] == green && a[0][1][0].color[4] == red) {
					rg = 1;
					combination = 27;
					start = 1;

				}
				else if (a[2][2][2].color[0] == orange && a[2][2][2].color[3] == white && a[2][2][2].color[5] == green && a[1][2][0].color[3] == green && a[1][2][0].color[1] == orange) {
					og = 1;
					combination = 27;
					start = 1;

				}
				else if (a[2][0][2].color[0] == blue && a[2][0][2].color[2] == orange && a[2][0][2].color[5] == white && a[2][1][0].color[1] == blue && a[2][1][0].color[5] == orange) {
					ob = 1;
					combination = 27;
					start = 1;

				}
				else if (a[0][0][2].color[0] == red && a[0][0][2].color[2] == white && a[0][0][2].color[4] == blue && a[1][0][0].color[2] == blue && a[1][0][0].color[1] == red) {
					rb = 1;
					combination = 27;
					start = 1;
				}
				else if (a[0][2][2].color[3] == red && a[0][2][2].color[0] == green && a[0][2][2].color[4] == white && a[1][2][0].color[3] == green && a[1][2][0].color[1] == red) {
					rg = 1;
					combination = 28;
					start = 1;

				}
				else if (a[2][2][2].color[0] == orange && a[2][2][2].color[3] == white && a[2][2][2].color[5] == green && a[2][1][0].color[1] == green && a[2][1][0].color[5] == orange) {
					og = 1;
					combination = 28;
					start = 1;

				}
				else if (a[2][0][2].color[0] == blue && a[2][0][2].color[2] == orange && a[2][0][2].color[5] == white && a[1][0][0].color[2] == blue && a[1][0][0].color[1] == orange) {
					ob = 1;
					combination = 28;
					start = 1;

				}
				else if (a[0][0][2].color[0] == red && a[0][0][2].color[2] == white && a[0][0][2].color[4] == blue && a[0][1][0].color[1] == blue && a[0][1][0].color[4] == red) {
					rb = 1;
					combination = 28;
					start = 1;
				}
				else if (a[0][2][2].color[0] == red && a[0][2][2].color[4] == green && a[0][2][2].color[3] == white && a[0][1][0].color[1] == green && a[0][1][0].color[4] == red) {
					rg = 1;
					combination = 29;
					start = 1;

				}
				else if (a[2][2][2].color[3] == orange && a[2][2][2].color[5] == white && a[2][2][2].color[0] == green && a[1][2][0].color[3] == green && a[1][2][0].color[1] == orange) {
					og = 1;
					combination = 29;
					start = 1;

				}
				else if (a[2][0][2].color[5] == blue && a[2][0][2].color[0] == orange && a[2][0][2].color[2] == white && a[2][1][0].color[1] == blue && a[2][1][0].color[5] == orange) {
					ob = 1;
					combination = 29;
					start = 1;

				}
				else if (a[0][0][2].color[2] == red && a[0][0][2].color[4] == white && a[0][0][2].color[0] == blue && a[1][0][0].color[2] == blue && a[1][0][0].color[1] == red) {
					rb = 1;
					combination = 29;
					start = 1;
				}
				else if (a[0][2][2].color[0] == red && a[0][2][2].color[4] == green && a[0][2][2].color[3] == white && a[1][2][0].color[3] == green && a[1][2][0].color[1] == red) {
					rg = 1;
					combination = 30;
					start = 1;

				}
				else if (a[2][2][2].color[3] == orange && a[2][2][2].color[5] == white && a[2][2][2].color[0] == green && a[2][1][0].color[1] == green && a[2][1][0].color[5] == orange) {
					og = 1;
					combination = 30;
					start = 1;

				}
				else if (a[2][0][2].color[5] == blue && a[2][0][2].color[0] == orange && a[2][0][2].color[2] == white && a[1][0][0].color[2] == blue && a[1][0][0].color[1] == orange) {
					ob = 1;
					combination = 30;
					start = 1;
				}
				else if (a[0][0][2].color[2] == red && a[0][0][2].color[4] == white && a[0][0][2].color[0] == blue && a[0][1][0].color[1] == blue && a[0][1][0].color[4] == red) {
					rb = 1;
					combination = 30;
					start = 1;
				}
				else if (a[0][2][2].color[4] == red && a[0][2][2].color[3] == green && a[0][2][2].color[0] == white && a[0][2][1].color[4] == green && a[0][2][1].color[3] == red) {
					rg = 1;
					combination = 37;
					start = 1;

				}
				else if (a[2][2][2].color[5] == orange && a[2][2][2].color[0] == white && a[2][2][2].color[3] == green && a[2][2][1].color[5] == green && a[2][2][1].color[3] == orange) {
					og = 1;
					combination = 37;
					start = 1;

				}
				else if (a[2][0][2].color[2] == blue && a[2][0][2].color[5] == orange && a[2][0][2].color[0] == white && a[2][0][1].color[5] == blue && a[2][0][1].color[2] == orange) {
					ob = 1;
					combination = 37;
					start = 1;

				}
				else if (a[0][0][2].color[4] == red && a[0][0][2].color[0] == white && a[0][0][2].color[2] == blue && a[0][0][1].color[4] == blue && a[0][0][1].color[2] == red) {
					rb = 1;
					combination = 37;
					start = 1;
				}
				else if (a[0][2][2].color[0] == red && a[0][2][2].color[4] == green && a[0][2][2].color[3] == white && a[0][2][1].color[4] == green && a[0][2][1].color[3] == red) {
					rg = 1;
					combination = 38;
					start = 1;

				}
				else if (a[2][2][2].color[3] == orange && a[2][2][2].color[5] == white && a[2][2][2].color[0] == green && a[2][2][1].color[5] == green && a[2][2][1].color[3] == orange) {
					og = 1;
					combination = 38;
					start = 1;

				}
				else if (a[2][0][2].color[5] == blue && a[2][0][2].color[0] == orange && a[2][0][2].color[2] == white && a[2][0][1].color[5] == blue && a[2][0][1].color[2] == orange) {
					ob = 1;
					combination = 38;
					start = 1;

				}
				else if (a[0][0][2].color[2] == red && a[0][0][2].color[4] == white && a[0][0][2].color[0] == blue && a[0][0][1].color[4] == blue && a[0][0][1].color[2] == red) {
					rb = 1;
					combination = 38;
					start = 1;
				}
				else if (a[0][2][2].color[3] == red && a[0][2][2].color[0] == green && a[0][2][2].color[4] == white && a[0][2][1].color[4] == green && a[0][2][1].color[3] == red) {
					rg = 1;
					combination = 39;
					start = 1;

				}
				else if (a[2][2][2].color[0] == orange && a[2][2][2].color[3] == white && a[2][2][2].color[5] == green && a[2][2][1].color[5] == green && a[2][2][1].color[3] == orange) {
					og = 1;
					combination = 39;
					start = 1;

				}
				else if (a[2][0][2].color[0] == blue && a[2][0][2].color[2] == orange && a[2][0][2].color[5] == white && a[2][0][1].color[5] == blue && a[2][0][1].color[2] == orange) {
					ob = 1;
					combination = 39;
					start = 1;

				}
				else if (a[0][0][2].color[0] == red && a[0][0][2].color[2] == white && a[0][0][2].color[4] == blue && a[0][0][1].color[4] == blue && a[0][0][1].color[2] == red) {
					rb = 1;
					combination = 39;
					start = 1;
				}
				else if (a[0][2][2].color[0] == red && a[0][2][2].color[4] == green && a[0][2][2].color[3] == white && a[0][2][1].color[3] == green && a[0][2][1].color[4] == red) {
					rg = 1;
					combination = 40;
					start = 1;

				}
				else if (a[2][2][2].color[3] == orange && a[2][2][2].color[5] == white && a[2][2][2].color[0] == green && a[2][2][1].color[3] == green && a[2][2][1].color[5] == orange) {
					og = 1;
					combination = 40;
					start = 1;

				}
				else if (a[2][0][2].color[5] == blue && a[2][0][2].color[0] == orange && a[2][0][2].color[2] == white && a[2][0][1].color[2] == blue && a[2][0][1].color[5] == orange) {
					ob = 1;
					combination = 40;
					start = 1;

				}
				else if (a[0][0][2].color[2] == red && a[0][0][2].color[4] == white && a[0][0][2].color[0] == blue && a[0][0][1].color[2] == blue && a[0][0][1].color[4] == red) {
					rb = 1;
					combination = 40;
					start = 1;
				}
				else if (a[0][2][2].color[3] == red && a[0][2][2].color[0] == green && a[0][2][2].color[4] == white && a[0][2][1].color[3] == green && a[0][2][1].color[4] == red) {
					rg = 1;
					combination = 41;
					start = 1;

				}
				else if (a[2][2][2].color[0] == orange && a[2][2][2].color[3] == white && a[2][2][2].color[5] == green && a[2][2][1].color[3] == green && a[2][2][1].color[5] == orange) {
					og = 1;
					combination = 41;
					start = 1;

				}
				else if (a[2][0][2].color[0] == blue && a[2][0][2].color[2] == orange && a[2][0][2].color[5] == white && a[2][0][1].color[2] == blue && a[2][0][1].color[5] == orange) {
					ob = 1;
					combination = 41;
					start = 1;

				}
				else if (a[0][0][2].color[0] == red && a[0][0][2].color[2] == white && a[0][0][2].color[4] == blue && a[0][0][1].color[2] == blue && a[0][0][1].color[4] == red) {
					rb = 1;
					combination = 41;
					start = 1;
				}
			}
		}
		
		//угол неправильный снизу
		if (wrong == 1) {
			if (lup == 1) {
				if (og == 1) {
					if (pif_paf(3)) {
						wrong = 2;
						
					}
				}
				else if (ob == 1) {
					if (pif_paf(3)) {
						wrong = 2;
						

					}
				}
				else if (rb == 1) {
					if (pif_paf(3)) {
						wrong = 2;
					
					}
				}
			}
			else if (rup == 1) {
				if (rg == 1) {
					if (pif_paf(5)) {
						wrong = 2;
												
					}
				}
				else if (ob == 1) {
					if (pif_paf(5)) {
						wrong = 2;
												
					}
				}
				else if (rb == 1) {
					if (pif_paf(5)) {
						wrong = 2;
												
					}
				}
			}
			else if (ldown == 1) {
				if (ob == 1){
					if (pif_paf(4)) {
						wrong = 2;
					}
				}
				else if (og == 1) {
					if (pif_paf(4)) {
						wrong = 2;
					}
				}
				else if (rg == 1) {
					if (pif_paf(4)) {
						wrong = 2;
					}
				}
			 }
			else if (rdown == 1) {
				if (og == 1) {
					if (pif_paf(2)) {
						wrong = 2;
					
					}
				}
				else if (rg == 1) {
					if (pif_paf(2)) {
						wrong = 2;
					
					}
				}
				else if (rb == 1) {
					if (pif_paf(2)) {
						wrong = 2;
					
					}
				}
			}
		}
		if (wrong == 2) {
			if (lup == 1) {
				if (og == 1) {
					if (num_of_comb == 0) Rotate(0, -3);
					if (num_of_comb == 1) {
						start = 0;
						wrong = 3;
						og = 0;
						num_of_comb = 0;
						lup = 0;
					}
				}
				else if (ob == 1) {
					if (num_of_comb == 0) Rotate(0, -3);
					if (num_of_comb == 1) Rotate(0, -3);
					if (num_of_comb == 2) {
						start = 0;
						wrong = 3;
						ob = 0;
						num_of_comb = 0;
						lup = 0;
					}
				}
				else if (rb == 1) {
					if (num_of_comb == 0) Rotate(0, 3);
					if (num_of_comb == 1) {
						start = 0;
						wrong = 3;
						rb = 0;
						num_of_comb = 0;
						lup = 0;
					}
				}
			}
			else if (rup == 1) {
				if (rg == 1) {
					if (num_of_comb == 0) Rotate(0, 3);
					if (num_of_comb == 1) {
						start = 0;
						wrong = 3;
						rg = 0;
						num_of_comb = 0;
						rup = 0;
					}
				}
				else if (rb == 1) {
					if (num_of_comb == 0) Rotate(0, -3);
					if (num_of_comb == 1) Rotate(0, -3);
					if (num_of_comb == 2) {
						start = 0;
						wrong = 3;
						rb = 0;
						num_of_comb = 0;
						rup = 0;
					}
				}
				else if (ob == 1) {
					if (num_of_comb == 0) Rotate(0, -3);
					if (num_of_comb == 1) {
						start = 0;
						wrong = 3;
						ob = 0;
						num_of_comb = 0;
						rup = 0;
					}
				}
			}
			else if (ldown == 1) {
				if (ob == 1) {
					if (num_of_comb == 0) Rotate(0, 3);
					if (num_of_comb == 1) {
						start = 0;
						wrong = 3;
						ob = 0;
						num_of_comb = 0;
						ldown = 0;
					}
				}
				else if (og == 1) {
					if (num_of_comb == 0) Rotate(0, -3);
					if (num_of_comb == 1) Rotate(0, -3);
					if (num_of_comb == 2) {
						start = 0;
						wrong = 3;
						og = 0;
						num_of_comb = 0;
						ldown = 0;
					}
				}
				else if (rg == 1) {
					if (num_of_comb == 0) Rotate(0, -3);
					if (num_of_comb == 1) {
						start = 0;
						wrong = 3;
						rg = 0;
						num_of_comb = 0;
						ldown = 0;
					}
				}
			}
			else if (rdown == 1) {
				if (rb == 1) {
					if (num_of_comb == 0) Rotate(0, -3);
					if (num_of_comb == 1) {
						start = 0;
						wrong = 3;
						rb = 0;
						num_of_comb = 0;
						rdown = 0;
					}
				}
				else if (rg == 1) {
					if (num_of_comb == 0) Rotate(0, -3);
					if (num_of_comb == 1) Rotate(0, -3);
					if (num_of_comb == 2) {
						start = 0;
						wrong = 3;
						rg = 0;
						num_of_comb = 0;
						rdown = 0;
					}
				}
				else if (og == 1) {
					if (num_of_comb == 0) Rotate(0, 3);
					if (num_of_comb == 1) {
						start = 0;
						wrong = 3;
						og = 0;
						num_of_comb = 0;
						rdown = 0;
					}
				}
			}
		}
		else if (wrong == 3) {
			if (combination == 3) {
				if (rg == 1) {
					if (num_of_comb == 0) Rotate(0, 3);
					if (num_of_comb == 1) Rotate(3, -3);
					if (num_of_comb == 2) Rotate(0, -3);
					if (num_of_comb == 3) Rotate(3, 3);
					if (num_of_comb == 4) {
						start = 0;
						num_of_comb = 0;
						rg = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (og == 1) {
					if (num_of_comb == 0) Rotate(0, 3);
					if (num_of_comb == 1) Rotate(5, -3);
					if (num_of_comb == 2) Rotate(0, -3);
					if (num_of_comb == 3) Rotate(5, 3);
					if (num_of_comb == 4) {
						start = 0;
						num_of_comb = 0;
						og = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (ob == 1) {
					if (num_of_comb == 0) Rotate(0, 3);
					if (num_of_comb == 1) Rotate(2, 3);
					if (num_of_comb == 2) Rotate(0, -3);
					if (num_of_comb == 3) Rotate(2, -3);
					if (num_of_comb == 4) {
						start = 0;
						num_of_comb = 0;
						ob = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (rb == 1) {
					if (num_of_comb == 0) Rotate(0, 3);
					if (num_of_comb == 1) Rotate(4, 3);
					if (num_of_comb == 2) Rotate(0, -3);
					if (num_of_comb == 3) Rotate(4, -3);
					if (num_of_comb == 4) {
						start = 0;
						num_of_comb = 0;
						rb = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
			}
			else if (combination == 4) {
				if (rg == 1) {
					if (num_of_comb == 0) Rotate(4, 3);
					if (num_of_comb == 1) Rotate(3, 3);
					if (num_of_comb == 2) Rotate(4, -3);
					if (num_of_comb == 3) Rotate(3, -3);
					if (num_of_comb == 4) {
						start = 0;
						num_of_comb = 0;
						rg = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (og == 1) {
					if (num_of_comb == 0) Rotate(3, -3);
					if (num_of_comb == 1) Rotate(5, 3);
					if (num_of_comb == 2) Rotate(3, 3);
					if (num_of_comb == 3) Rotate(5, -3);
					if (num_of_comb == 4) {
						start = 0;
						num_of_comb = 0;
						og = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (ob == 1) {
					if (num_of_comb == 0) Rotate(5, -3);
					if (num_of_comb == 1) Rotate(2, -3);
					if (num_of_comb == 2) Rotate(5, 3);
					if (num_of_comb == 3) Rotate(2, 3);
					if (num_of_comb == 4) {
						start = 0;
						num_of_comb = 0;
						ob = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (rb == 1) {
					if (num_of_comb == 0) Rotate(2, 3);
					if (num_of_comb == 1) Rotate(4, -3);
					if (num_of_comb == 2) Rotate(2, -3);
					if (num_of_comb == 3) Rotate(4, 3);
					if (num_of_comb == 4) {
						start = 0;
						num_of_comb = 0;
						rb = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
			}
			else if (combination == 5) {
				if (rg == 1) {
					if (num_of_comb == 0) Rotate(3, -3);
					if (num_of_comb == 1) Rotate(0, 3);
					if (num_of_comb == 2) Rotate(3, 3);
					if (num_of_comb == 3) {
						start = 0;
						num_of_comb = 0;
						rg = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (og == 1) {
					if (num_of_comb == 0) Rotate(5, -3);
					if (num_of_comb == 1) Rotate(0, 3);
					if (num_of_comb == 2) Rotate(5, 3);
					if (num_of_comb == 3) {
						start = 0;
						num_of_comb = 0;
						og = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (ob == 1) {
					if (num_of_comb == 0) Rotate(2, 3);
					if (num_of_comb == 1) Rotate(0, 3);
					if (num_of_comb == 2) Rotate(2, -3);
					if (num_of_comb == 3) {
						start = 0;
						num_of_comb = 0;
						ob = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (rb == 1) {
					if (num_of_comb == 0) Rotate(4, 3);
					if (num_of_comb == 1) Rotate(0, 3);
					if (num_of_comb == 2) Rotate(4, -3);
					if (num_of_comb == 3) {
						start = 0;
						num_of_comb = 0;
						rb = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
			}
			else if (combination == 6) {
				if (rg == 1) {
					if (num_of_comb == 0) Rotate(4, -3);
					if (num_of_comb == 1) Rotate(0, -3);
					if (num_of_comb == 2) Rotate(4, 3);
					if (num_of_comb == 3) {
						start = 0;
						num_of_comb = 0;
						rg = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (og == 1) {
					if (num_of_comb == 0) Rotate(3, 3);
					if (num_of_comb == 1) Rotate(0, -3);
					if (num_of_comb == 2) Rotate(3, -3);
					if (num_of_comb == 3) {
						start = 0;
						num_of_comb = 0;
						og = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (ob == 1) {
					if (num_of_comb == 0) Rotate(5, 3);
					if (num_of_comb == 1) Rotate(0, -3);
					if (num_of_comb == 2) Rotate(5, -3);
					if (num_of_comb == 3) {
						start = 0;
						num_of_comb = 0;
						ob = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (rb == 1) {
					if (num_of_comb == 0) Rotate(2, -3);
					if (num_of_comb == 1) Rotate(0, -3);
					if (num_of_comb == 2) Rotate(2, 3);
					if (num_of_comb == 3) {
						start = 0;
						num_of_comb = 0;
						rb = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
			}
			else if (combination == 7) {
				if (rg == 1) {
					if (num_of_comb == 0) Rotate(0, -3);
					if (num_of_comb == 1) Rotate(3, -3);
					if (num_of_comb == 2) Rotate(0, 3);
					if (num_of_comb == 3) Rotate(0, 3);
					if (num_of_comb == 4) Rotate(3, 3);
					if (num_of_comb == 5) Rotate(0, 3);
					if (num_of_comb == 6) Rotate(3, 3);
					if (num_of_comb == 7) Rotate(4, 3);
					if (num_of_comb == 8) Rotate(3, -3);
					if (num_of_comb == 9) Rotate(4, -3);
					if (num_of_comb == 10) {
						start = 0;
						num_of_comb = 0;
						rg = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (og == 1) {
					if (num_of_comb == 0) Rotate(0, -3);
					if (num_of_comb == 1) Rotate(5, -3);
					if (num_of_comb == 2) Rotate(0, 3);
					if (num_of_comb == 3) Rotate(0, 3);
					if (num_of_comb == 4) Rotate(5, 3);
					if (num_of_comb == 5) Rotate(0, 3);
					if (num_of_comb == 6) Rotate(5, 3);
					if (num_of_comb == 7) Rotate(3, -3);
					if (num_of_comb == 8) Rotate(5, -3);
					if (num_of_comb == 9) Rotate(3, 3);
					if (num_of_comb == 10) {
						start = 0;
						num_of_comb = 0;
						og = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (ob == 1) {
					if (num_of_comb == 0) Rotate(0, -3);
					if (num_of_comb == 1) Rotate(2, 3);
					if (num_of_comb == 2) Rotate(0, 3);
					if (num_of_comb == 3) Rotate(0, 3);
					if (num_of_comb == 4) Rotate(2, -3);
					if (num_of_comb == 5) Rotate(0, 3);
					if (num_of_comb == 6) Rotate(2, -3);
					if (num_of_comb == 7) Rotate(5, -3);
					if (num_of_comb == 8) Rotate(2, 3);
					if (num_of_comb == 9) Rotate(5, 3);
					if (num_of_comb == 10) {
						start = 0;
						num_of_comb = 0;
						ob = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (rb == 1) {
					if (num_of_comb == 0) Rotate(0, -3);
					if (num_of_comb == 1) Rotate(4, 3);
					if (num_of_comb == 2) Rotate(0, 3);
					if (num_of_comb == 3) Rotate(0, 3);
					if (num_of_comb == 4) Rotate(4, -3);
					if (num_of_comb == 5) Rotate(0, 3);
					if (num_of_comb == 6) Rotate(4, -3);
					if (num_of_comb == 7) Rotate(2, 3);
					if (num_of_comb == 8) Rotate(4, 3);
					if (num_of_comb == 9) Rotate(2, -3);
					if (num_of_comb == 10) {
						start = 0;
						num_of_comb = 0;
						rb = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
			}
			else if (combination == 8) {
				if (rg == 1) {
					if (num_of_comb == 0) Rotate(0, 3);
					if (num_of_comb == 1) Rotate(4, -3);
					if (num_of_comb == 2) Rotate(0, -3);
					if (num_of_comb == 3) Rotate(4, 3);
					if (num_of_comb == 4) Rotate(0, 3);
					if (num_of_comb == 5) Rotate(0, 3);
					if (num_of_comb == 6) Rotate(4, -3);
					if (num_of_comb == 7) Rotate(0, 3);
					if (num_of_comb == 8) Rotate(4, 3);
					if (num_of_comb == 9) {
						start = 0;
						num_of_comb = 0;
						rg = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (og == 1) {
					if (num_of_comb == 0) Rotate(0, 3);
					if (num_of_comb == 1) Rotate(3, 3);
					if (num_of_comb == 2) Rotate(0, -3);
					if (num_of_comb == 3) Rotate(3, -3);
					if (num_of_comb == 4) Rotate(0, 3);
					if (num_of_comb == 5) Rotate(0, 3);
					if (num_of_comb == 6) Rotate(3, 3);
					if (num_of_comb == 7) Rotate(0, 3);
					if (num_of_comb == 8) Rotate(3, -3);
					if (num_of_comb == 9) {
						start = 0;
						num_of_comb = 0;
						og = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (ob == 1) {
					if (num_of_comb == 0) Rotate(0, 3);
					if (num_of_comb == 1) Rotate(5, 3);
					if (num_of_comb == 2) Rotate(0, -3);
					if (num_of_comb == 3) Rotate(5, -3);
					if (num_of_comb == 4) Rotate(0, 3);
					if (num_of_comb == 5) Rotate(0, 3);
					if (num_of_comb == 6) Rotate(5, 3);
					if (num_of_comb == 7) Rotate(0, 3);
					if (num_of_comb == 8) Rotate(5, -3);
					if (num_of_comb == 9) {
						start = 0;
						num_of_comb = 0;
						ob = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (rb == 1) {
					if (num_of_comb == 0) Rotate(0, 3);
					if (num_of_comb == 1) Rotate(2, -3);
					if (num_of_comb == 2) Rotate(0, -3);
					if (num_of_comb == 3) Rotate(2, 3);
					if (num_of_comb == 4) Rotate(0, 3);
					if (num_of_comb == 5) Rotate(0, 3);
					if (num_of_comb == 6) Rotate(2, -3);
					if (num_of_comb == 7) Rotate(0, 3);
					if (num_of_comb == 8) Rotate(2, 3);
					if (num_of_comb == 9) {
						start = 0;
						num_of_comb = 0;
						rb = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
			}
			else if (combination == 9) {
				if (rg == 1) {
					if (num_of_comb == 0) Rotate(0, -3);
					if (num_of_comb == 1) Rotate(3, -3);
					if (num_of_comb == 2) Rotate(0, 3);
					if (num_of_comb == 3) Rotate(3, 3);
					if (num_of_comb == 4) Rotate(0, 3);
					if (num_of_comb == 5) Rotate(0, 3);
					if (num_of_comb == 6) Rotate(3, -3);
					if (num_of_comb == 7) Rotate(0, -3);
					if (num_of_comb == 8) Rotate(3, 3);
					if (num_of_comb == 9) {
						start = 0;
						num_of_comb = 0;
						rg = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (og == 1) {
					if (num_of_comb == 0) Rotate(0, -3);
					if (num_of_comb == 1) Rotate(5, -3);
					if (num_of_comb == 2) Rotate(0, 3);
					if (num_of_comb == 3) Rotate(5, 3);
					if (num_of_comb == 4) Rotate(0, 3);
					if (num_of_comb == 5) Rotate(0, 3);
					if (num_of_comb == 6) Rotate(5, -3);
					if (num_of_comb == 7) Rotate(0, -3);
					if (num_of_comb == 8) Rotate(5, 3);
					if (num_of_comb == 9) {
						start = 0;
						num_of_comb = 0;
						og = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (ob == 1) {
					if (num_of_comb == 0) Rotate(0, -3);
					if (num_of_comb == 1) Rotate(2, 3);
					if (num_of_comb == 2) Rotate(0, 3);
					if (num_of_comb == 3) Rotate(2, -3);
					if (num_of_comb == 4) Rotate(0, 3);
					if (num_of_comb == 5) Rotate(0, 3);
					if (num_of_comb == 6) Rotate(2, 3);
					if (num_of_comb == 7) Rotate(0, -3);
					if (num_of_comb == 8) Rotate(2, -3);
					if (num_of_comb == 9) {
						start = 0;
						num_of_comb = 0;
						ob = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (rb == 1) {
					if (num_of_comb == 0) Rotate(0, -3);
					if (num_of_comb == 1) Rotate(4, 3);
					if (num_of_comb == 2) Rotate(0, 3);
					if (num_of_comb == 3) Rotate(4, -3);
					if (num_of_comb == 4) Rotate(0, 3);
					if (num_of_comb == 5) Rotate(0, 3);
					if (num_of_comb == 6) Rotate(4, 3);
					if (num_of_comb == 7) Rotate(0, -3);
					if (num_of_comb == 8) Rotate(4, -3);
					if (num_of_comb == 9) {
						start = 0;
						num_of_comb = 0;
						rb = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
			}
			else if (combination == 10){
				if (rg == 1) {
					if (num_of_comb == 0) Rotate(0, 3);
					if (num_of_comb == 1) Rotate(4, -3);
					if (num_of_comb == 2) Rotate(0, 3);
					if (num_of_comb == 3) Rotate(0, 3);
					if (num_of_comb == 4) Rotate(4, 3);
					if (num_of_comb == 5) Rotate(0, 3);
					if (num_of_comb == 6) Rotate(0, 3);
					if (num_of_comb == 7) Rotate(4, -3);
					if (num_of_comb == 8) Rotate(0, 3);
					if (num_of_comb == 9) Rotate(4, 3);
					if (num_of_comb == 10) {
						start = 0;
						num_of_comb = 0;
						rg = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (og == 1) {
					if (num_of_comb == 0) Rotate(0, 3);
					if (num_of_comb == 1) Rotate(3, 3);
					if (num_of_comb == 2) Rotate(0, 3);
					if (num_of_comb == 3) Rotate(0, 3);
					if (num_of_comb == 4) Rotate(3, -3);
					if (num_of_comb == 5) Rotate(0, 3);
					if (num_of_comb == 6) Rotate(0, 3);
					if (num_of_comb == 7) Rotate(3, 3);
					if (num_of_comb == 8) Rotate(0, 3);
					if (num_of_comb == 9) Rotate(3, -3);
					if (num_of_comb == 10) {
						start = 0;
						num_of_comb = 0;
						og = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (ob == 1) {
					if (num_of_comb == 0) Rotate(0, 3);
					if (num_of_comb == 1) Rotate(5, 3);
					if (num_of_comb == 2) Rotate(0, 3);
					if (num_of_comb == 3) Rotate(0, 3);
					if (num_of_comb == 4) Rotate(5, -3);
					if (num_of_comb == 5) Rotate(0, 3);
					if (num_of_comb == 6) Rotate(0, 3);
					if (num_of_comb == 7) Rotate(5, 3);
					if (num_of_comb == 8) Rotate(0, 3);
					if (num_of_comb == 9) Rotate(5, -3);
					if (num_of_comb == 10) {
						start = 0;
						num_of_comb = 0;
						ob = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (rb == 1) {
					if (num_of_comb == 0) Rotate(0, 3);
					if (num_of_comb == 1) Rotate(2, -3);
					if (num_of_comb == 2) Rotate(0, 3);
					if (num_of_comb == 3) Rotate(0, 3);
					if (num_of_comb == 4) Rotate(2, 3);
					if (num_of_comb == 5) Rotate(0, 3);
					if (num_of_comb == 6) Rotate(0, 3);
					if (num_of_comb == 7) Rotate(2, -3);
					if (num_of_comb == 8) Rotate(0, 3);
					if (num_of_comb == 9) Rotate(2, 3);
					if (num_of_comb == 10) {
						start = 0;
						num_of_comb = 0;
						rb = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
			}
			else if (combination == 11) {
				if (rg == 1) {
					if (num_of_comb == 0) Rotate(0, -3);
					if (num_of_comb == 1) Rotate(3, -3);
					if (num_of_comb == 2) Rotate(0, -3);
					if (num_of_comb == 3) Rotate(3, 3);
					if (num_of_comb == 4) Rotate(0, 3);
					if (num_of_comb == 5) Rotate(4, -3);
					if (num_of_comb == 6) Rotate(0, -3);
					if (num_of_comb == 7) Rotate(4, 3);
					if (num_of_comb == 8) {
						start = 0;
						num_of_comb = 0;
						rg = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (og == 1) {
					if (num_of_comb == 0) Rotate(0, -3);
					if (num_of_comb == 1) Rotate(5, -3);
					if (num_of_comb == 2) Rotate(0, -3);
					if (num_of_comb == 3) Rotate(5, 3);
					if (num_of_comb == 4) Rotate(0, 3);
					if (num_of_comb == 5) Rotate(3, 3);
					if (num_of_comb == 6) Rotate(0, -3);
					if (num_of_comb == 7) Rotate(3, -3);
					if (num_of_comb == 8) {
						start = 0;
						num_of_comb = 0;
						og = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (ob == 1) {
					if (num_of_comb == 0) Rotate(0, -3);
					if (num_of_comb == 1) Rotate(2, 3);
					if (num_of_comb == 2) Rotate(0, -3);
					if (num_of_comb == 3) Rotate(2, -3);
					if (num_of_comb == 4) Rotate(0, 3);
					if (num_of_comb == 5) Rotate(5, 3);
					if (num_of_comb == 6) Rotate(0, -3);
					if (num_of_comb == 7) Rotate(5, -3);
					if (num_of_comb == 8) {
						start = 0;
						num_of_comb = 0;
						ob = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (rb == 1) {
					if (num_of_comb == 0) Rotate(0, -3);
					if (num_of_comb == 1) Rotate(4, 3);
					if (num_of_comb == 2) Rotate(0, -3);
					if (num_of_comb == 3) Rotate(4, -3);
					if (num_of_comb == 4) Rotate(0, 3);
					if (num_of_comb == 5) Rotate(2, -3);
					if (num_of_comb == 6) Rotate(0, -3);
					if (num_of_comb == 7) Rotate(2, 3);
					if (num_of_comb == 8) {
						start = 0;
						num_of_comb = 0;
						rb = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
			}
			else if (combination == 12) {
				if (rg == 1) {
					if (num_of_comb == 0) Rotate(0, -3);
					if (num_of_comb == 1) Rotate(3, -3);
					if (num_of_comb == 2) Rotate(0, 3);
					if (num_of_comb == 3) Rotate(3, 3);
					if (num_of_comb == 4) Rotate(0, 3);
					if (num_of_comb == 5) Rotate(3, -3);
					if (num_of_comb == 6) Rotate(0, 3);
					if (num_of_comb == 7) Rotate(3, 3);
					if (num_of_comb == 8) {
						start = 0;
						num_of_comb = 0;
						rg = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (og == 1) {
					if (num_of_comb == 0) Rotate(0, -3);
					if (num_of_comb == 1) Rotate(5, -3);
					if (num_of_comb == 2) Rotate(0, 3);
					if (num_of_comb == 3) Rotate(5, 3);
					if (num_of_comb == 4) Rotate(0, 3);
					if (num_of_comb == 5) Rotate(5, -3);
					if (num_of_comb == 6) Rotate(0, 3);
					if (num_of_comb == 7) Rotate(5, 3);
					if (num_of_comb == 8) {
						start = 0;
						num_of_comb = 0;
						og = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (ob == 1) {
					if (num_of_comb == 0) Rotate(0, -3);
					if (num_of_comb == 1) Rotate(2, 3);
					if (num_of_comb == 2) Rotate(0, 3);
					if (num_of_comb == 3) Rotate(2, -3);
					if (num_of_comb == 4) Rotate(0, 3);
					if (num_of_comb == 5) Rotate(2, 3);
					if (num_of_comb == 6) Rotate(0, 3);
					if (num_of_comb == 7) Rotate(2, -3);
					if (num_of_comb == 8) {
						start = 0;
						num_of_comb = 0;
						ob = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (rb == 1) {
					if (num_of_comb == 0) Rotate(0, -3);
					if (num_of_comb == 1) Rotate(4, 3);
					if (num_of_comb == 2) Rotate(0, 3);
					if (num_of_comb == 3) Rotate(4, -3);
					if (num_of_comb == 4) Rotate(0, 3);
					if (num_of_comb == 5) Rotate(4, 3);
					if (num_of_comb == 6) Rotate(0, 3);
					if (num_of_comb == 7) Rotate(4, -3);
					if (num_of_comb == 8) {
						start = 0;
						num_of_comb = 0;
						rb = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
			}
			else if (combination == 13) {
				if (rg == 1) {
					if (num_of_comb == 0) Rotate(0, 3);
					if (num_of_comb == 1) Rotate(4, -3);
					if (num_of_comb == 2) Rotate(0, 3);
					if (num_of_comb == 3) Rotate(4, 3);
					if (num_of_comb == 4) Rotate(0, -3);
					if (num_of_comb == 5) Rotate(4, -3);
					if (num_of_comb == 6) Rotate(0, -3);
					if (num_of_comb == 7) Rotate(4, 3);
					if (num_of_comb == 8) {
						start = 0;
						num_of_comb = 0;
						rg = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (og == 1) {
					if (num_of_comb == 0) Rotate(0, 3);
					if (num_of_comb == 1) Rotate(3, 3);
					if (num_of_comb == 2) Rotate(0, 3);
					if (num_of_comb == 3) Rotate(3, -3);
					if (num_of_comb == 4) Rotate(0, -3);
					if (num_of_comb == 5) Rotate(3, 3);
					if (num_of_comb == 6) Rotate(0, -3);
					if (num_of_comb == 7) Rotate(3, -3);
					if (num_of_comb == 8) {
						start = 0;
						num_of_comb = 0;
						og = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (ob == 1) {
					if (num_of_comb == 0) Rotate(0, 3);
					if (num_of_comb == 1) Rotate(5, 3);
					if (num_of_comb == 2) Rotate(0, 3);
					if (num_of_comb == 3) Rotate(5, -3);
					if (num_of_comb == 4) Rotate(0, -3);
					if (num_of_comb == 5) Rotate(5, 3);
					if (num_of_comb == 6) Rotate(0, -3);
					if (num_of_comb == 7) Rotate(5, -3);
					if (num_of_comb == 8) {
						start = 0;
						num_of_comb = 0;
						ob = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (rb == 1) {
					if (num_of_comb == 0) Rotate(0, 3);
					if (num_of_comb == 1) Rotate(2, -3);
					if (num_of_comb == 2) Rotate(0, 3);
					if (num_of_comb == 3) Rotate(2, 3);
					if (num_of_comb == 4) Rotate(0, -3);
					if (num_of_comb == 5) Rotate(2, -3);
					if (num_of_comb == 6) Rotate(0, -3);
					if (num_of_comb == 7) Rotate(2, 3);
					if (num_of_comb == 8) {
						start = 0;
						num_of_comb = 0;
						rb = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
			}
			else if (combination == 14) {
				if (rg == 1) {
					if (num_of_comb == 0) Rotate(0, 3);
					if (num_of_comb == 1) Rotate(4, -3);
					if (num_of_comb == 2) Rotate(0, 3);
					if (num_of_comb == 3) Rotate(0, 3);
					if (num_of_comb == 4) Rotate(4, 3);
					if (num_of_comb == 5) Rotate(0, -3);
					if (num_of_comb == 6) Rotate(3, -3);
					if (num_of_comb == 7) Rotate(0, 3);
					if (num_of_comb == 8) Rotate(3, 3);
					if (num_of_comb == 9) {
						start = 0;
						num_of_comb = 0;
						rg = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (og == 1) {
					if (num_of_comb == 0) Rotate(0, 3);
					if (num_of_comb == 1) Rotate(3, 3);
					if (num_of_comb == 2) Rotate(0, 3);
					if (num_of_comb == 3) Rotate(0, 3);
					if (num_of_comb == 4) Rotate(3, -3);
					if (num_of_comb == 5) Rotate(0, -3);
					if (num_of_comb == 6) Rotate(5, -3);
					if (num_of_comb == 7) Rotate(0, 3);
					if (num_of_comb == 8) Rotate(5, 3);
					if (num_of_comb == 9) {
						start = 0;
						num_of_comb = 0;
						og = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (ob == 1) {
					if (num_of_comb == 0) Rotate(0, 3);
					if (num_of_comb == 1) Rotate(5, 3);
					if (num_of_comb == 2) Rotate(0, 3);
					if (num_of_comb == 3) Rotate(0, 3);
					if (num_of_comb == 4) Rotate(5, -3);
					if (num_of_comb == 5) Rotate(0, -3);
					if (num_of_comb == 6) Rotate(2, 3);
					if (num_of_comb == 7) Rotate(0, 3);
					if (num_of_comb == 8) Rotate(2, -3);
					if (num_of_comb == 9) {
						start = 0;
						num_of_comb = 0;
						ob = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (rb == 1) {
					if (num_of_comb == 0) Rotate(0, 3);
					if (num_of_comb == 1) Rotate(2, -3);
					if (num_of_comb == 2) Rotate(0, 3);
					if (num_of_comb == 3) Rotate(0, 3);
					if (num_of_comb == 4) Rotate(2, 3);
					if (num_of_comb == 5) Rotate(0, -3);
					if (num_of_comb == 6) Rotate(4, 3);
					if (num_of_comb == 7) Rotate(0, 3);
					if (num_of_comb == 8) Rotate(4, -3);
					if (num_of_comb == 9) {
						start = 0;
						num_of_comb = 0;
						rb = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
			}
			else if (combination == 15) {
				if (rg == 1) {
					if (num_of_comb == 0) Rotate(0, -3);
					if (num_of_comb == 1) Rotate(3, -3);
					if (num_of_comb == 2) Rotate(0, 3);
					if (num_of_comb == 3) Rotate(0, 3);
					if (num_of_comb == 4) Rotate(3, 3);
					if (num_of_comb == 5) Rotate(0, 3);
					if (num_of_comb == 6) Rotate(4, -3);
					if (num_of_comb == 7) Rotate(0, -3);
					if (num_of_comb == 8) Rotate(4, 3);
					if (num_of_comb == 9) {
						start = 0;
						num_of_comb = 0;
						rg = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (og == 1) {
					if (num_of_comb == 0) Rotate(0, -3);
					if (num_of_comb == 1) Rotate(5, -3);
					if (num_of_comb == 2) Rotate(0, 3);
					if (num_of_comb == 3) Rotate(0, 3);
					if (num_of_comb == 4) Rotate(5, 3);
					if (num_of_comb == 5) Rotate(0, 3);
					if (num_of_comb == 6) Rotate(3, 3);
					if (num_of_comb == 7) Rotate(0, -3);
					if (num_of_comb == 8) Rotate(3, -3);
					if (num_of_comb == 9) {
						start = 0;
						num_of_comb = 0;
						og = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (ob == 1) {
					if (num_of_comb == 0) Rotate(0, -3);
					if (num_of_comb == 1) Rotate(2, 3);
					if (num_of_comb == 2) Rotate(0, 3);
					if (num_of_comb == 3) Rotate(0, 3);
					if (num_of_comb == 4) Rotate(2, -3);
					if (num_of_comb == 5) Rotate(0, 3);
					if (num_of_comb == 6) Rotate(5, 3);
					if (num_of_comb == 7) Rotate(0, -3);
					if (num_of_comb == 8) Rotate(5, -3);
					if (num_of_comb == 9) {
						start = 0;
						num_of_comb = 0;
						ob = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (rb == 1) {
					if (num_of_comb == 0) Rotate(0, -3);
					if (num_of_comb == 1) Rotate(4, 3);
					if (num_of_comb == 2) Rotate(0, 3);
					if (num_of_comb == 3) Rotate(0, 3);
					if (num_of_comb == 4) Rotate(4, -3);
					if (num_of_comb == 5) Rotate(0, 3);
					if (num_of_comb == 6) Rotate(2, -3);
					if (num_of_comb == 7) Rotate(0, -3);
					if (num_of_comb == 8) Rotate(2, 3);
					if (num_of_comb == 9) {
						start = 0;
						num_of_comb = 0;
						rb = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
			}
			else if (combination == 16) {
				if (rg == 1) {
					if (num_of_comb == 0) Rotate(0, -3);
					if (num_of_comb == 1) Rotate(3, -3);
					if (num_of_comb == 2) Rotate(0, -3);
					if (num_of_comb == 3) Rotate(3, 3);
					if (num_of_comb == 4) Rotate(0, 3);
					if (num_of_comb == 5) Rotate(3, -3);
					if (num_of_comb == 6) Rotate(0, 3);
					if (num_of_comb == 7) Rotate(3, 3);
					if (num_of_comb == 8) {
						start = 0;
						num_of_comb = 0;
						rg = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (og == 1) {
					if (num_of_comb == 0) Rotate(0, -3);
					if (num_of_comb == 1) Rotate(5, -3);
					if (num_of_comb == 2) Rotate(0, -3);
					if (num_of_comb == 3) Rotate(5, 3);
					if (num_of_comb == 4) Rotate(0, 3);
					if (num_of_comb == 5) Rotate(5, -3);
					if (num_of_comb == 6) Rotate(0, 3);
					if (num_of_comb == 7) Rotate(5, 3);
					if (num_of_comb == 8) {
						start = 0;
						num_of_comb = 0;
						og = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (ob == 1) {
					if (num_of_comb == 0) Rotate(0, -3);
					if (num_of_comb == 1) Rotate(2, 3);
					if (num_of_comb == 2) Rotate(0, -3);
					if (num_of_comb == 3) Rotate(2, -3);
					if (num_of_comb == 4) Rotate(0, 3);
					if (num_of_comb == 5) Rotate(2, 3);
					if (num_of_comb == 6) Rotate(0, 3);
					if (num_of_comb == 7) Rotate(2, -3);
					if (num_of_comb == 8) {
						start = 0;
						num_of_comb = 0;
						ob = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (rb == 1) {
					if (num_of_comb == 0) Rotate(0, -3);
					if (num_of_comb == 1) Rotate(4, 3);
					if (num_of_comb == 2) Rotate(0, -3);
					if (num_of_comb == 3) Rotate(4, -3);
					if (num_of_comb == 4) Rotate(0, 3);
					if (num_of_comb == 5) Rotate(4, 3);
					if (num_of_comb == 6) Rotate(0, 3);
					if (num_of_comb == 7) Rotate(4, -3);
					if (num_of_comb == 8) {
						start = 0;
						num_of_comb = 0;
						rb = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
			}
			else if (combination == 17) {
				if (rg == 1) {
					if (num_of_comb == 0) Rotate(4, -3);
					if (num_of_comb == 1) Rotate(0, 3);
					if (num_of_comb == 2) Rotate(4, 3);
					if (num_of_comb == 3) Rotate(0, 3);
					if (num_of_comb == 4) Rotate(0, 3);
					if (num_of_comb == 5) Rotate(3, -3);
					if (num_of_comb == 6) Rotate(0, 3);
					if (num_of_comb == 7) Rotate(3, 3);
					if (num_of_comb == 8) {
						start = 0;
						num_of_comb = 0;
						rg = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (og == 1) {
					if (num_of_comb == 0) Rotate(3, 3);
					if (num_of_comb == 1) Rotate(0, 3);
					if (num_of_comb == 2) Rotate(3, -3);
					if (num_of_comb == 3) Rotate(0, 3);
					if (num_of_comb == 4) Rotate(0, 3);
					if (num_of_comb == 5) Rotate(5, -3);
					if (num_of_comb == 6) Rotate(0, 3);
					if (num_of_comb == 7) Rotate(5, 3);
					if (num_of_comb == 8) {
						start = 0;
						num_of_comb = 0;
						og = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (ob == 1) {
					if (num_of_comb == 0) Rotate(5, 3);
					if (num_of_comb == 1) Rotate(0, 3);
					if (num_of_comb == 2) Rotate(5, -3);
					if (num_of_comb == 3) Rotate(0, 3);
					if (num_of_comb == 4) Rotate(0, 3);
					if (num_of_comb == 5) Rotate(2, 3);
					if (num_of_comb == 6) Rotate(0, 3);
					if (num_of_comb == 7) Rotate(2, -3);
					if (num_of_comb == 8) {
						start = 0;
						num_of_comb = 0;
						ob = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (rb == 1) {
					if (num_of_comb == 0) Rotate(2, -3);
					if (num_of_comb == 1) Rotate(0, 3);
					if (num_of_comb == 2) Rotate(2, 3);
					if (num_of_comb == 3) Rotate(0, 3);
					if (num_of_comb == 4) Rotate(0, 3);
					if (num_of_comb == 5) Rotate(4, 3);
					if (num_of_comb == 6) Rotate(0, 3);
					if (num_of_comb == 7) Rotate(4, -3);
					if (num_of_comb == 8) {
						start = 0;
						num_of_comb = 0;
						rb = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
			}
			else if (combination == 18) {
				if (rg == 1) {
					if (num_of_comb == 0) Rotate(3, -3);
					if (num_of_comb == 1) Rotate(0, -3);
					if (num_of_comb == 2) Rotate(3, 3);
					if (num_of_comb == 3) Rotate(0, 3);
					if (num_of_comb == 4) Rotate(0, 3);
					if (num_of_comb == 5) Rotate(4, -3);
					if (num_of_comb == 6) Rotate(0, -3);
					if (num_of_comb == 7) Rotate(4, 3);
					if (num_of_comb == 8) {
						start = 0;
						num_of_comb = 0;
						rg = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (og == 1) {
					if (num_of_comb == 0) Rotate(5, -3);
					if (num_of_comb == 1) Rotate(0, -3);
					if (num_of_comb == 2) Rotate(5, 3);
					if (num_of_comb == 3) Rotate(0, 3);
					if (num_of_comb == 4) Rotate(0, 3);
					if (num_of_comb == 5) Rotate(3, 3);
					if (num_of_comb == 6) Rotate(0, -3);
					if (num_of_comb == 7) Rotate(3, -3);
					if (num_of_comb == 8) {
						start = 0;
						num_of_comb = 0;
						og = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (ob == 1) {
					if (num_of_comb == 0) Rotate(2, 3);
					if (num_of_comb == 1) Rotate(0, -3);
					if (num_of_comb == 2) Rotate(2, -3);
					if (num_of_comb == 3) Rotate(0, 3);
					if (num_of_comb == 4) Rotate(0, 3);
					if (num_of_comb == 5) Rotate(5, 3);
					if (num_of_comb == 6) Rotate(0, -3);
					if (num_of_comb == 7) Rotate(5, -3);
					if (num_of_comb == 8) {
						start = 0;
						num_of_comb = 0;
						ob = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (rb == 1) {
					if (num_of_comb == 0) Rotate(4, 3);
					if (num_of_comb == 1) Rotate(0, -3);
					if (num_of_comb == 2) Rotate(4, -3);
					if (num_of_comb == 3) Rotate(0, 3);
					if (num_of_comb == 4) Rotate(0, 3);
					if (num_of_comb == 5) Rotate(2, -3);
					if (num_of_comb == 6) Rotate(0, -3);
					if (num_of_comb == 7) Rotate(2, 3);
					if (num_of_comb == 8) {
						start = 0;
						num_of_comb = 0;
						rb = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
			}
			else if (combination == 19) {
				if (rg == 1) {
					if (num_of_comb == 0) Rotate(3, -3);
					if (num_of_comb == 1) Rotate(0, 3);
					if (num_of_comb == 2) Rotate(0, 3);
					if (num_of_comb == 3) Rotate(3, 3);
					if (num_of_comb == 4) Rotate(0, -3);
					if (num_of_comb == 5) Rotate(3, -3);
					if (num_of_comb == 6) Rotate(0, 3);
					if (num_of_comb == 7) Rotate(3, 3);
					if (num_of_comb == 8) {
						start = 0;
						num_of_comb = 0;
						rg = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (og == 1) {
					if (num_of_comb == 0) Rotate(5, -3);
					if (num_of_comb == 1) Rotate(0, 3);
					if (num_of_comb == 2) Rotate(0, 3);
					if (num_of_comb == 3) Rotate(5, 3);
					if (num_of_comb == 4) Rotate(0, -3);
					if (num_of_comb == 5) Rotate(5, -3);
					if (num_of_comb == 6) Rotate(0, 3);
					if (num_of_comb == 7) Rotate(5, 3);
					if (num_of_comb == 8) {
						start = 0;
						num_of_comb = 0;
						og = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (ob == 1) {
					if (num_of_comb == 0) Rotate(2, 3);
					if (num_of_comb == 1) Rotate(0, 3);
					if (num_of_comb == 2) Rotate(0, 3);
					if (num_of_comb == 3) Rotate(2, -3);
					if (num_of_comb == 4) Rotate(0, -3);
					if (num_of_comb == 5) Rotate(2, 3);
					if (num_of_comb == 6) Rotate(0, 3);
					if (num_of_comb == 7) Rotate(2, -3);
					if (num_of_comb == 8) {
						start = 0;
						num_of_comb = 0;
						ob = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (rb == 1) {
					if (num_of_comb == 0) Rotate(4, 3);
					if (num_of_comb == 1) Rotate(0, 3);
					if (num_of_comb == 2) Rotate(0, 3);
					if (num_of_comb == 3) Rotate(4, -3);
					if (num_of_comb == 4) Rotate(0, -3);
					if (num_of_comb == 5) Rotate(4, 3);
					if (num_of_comb == 6) Rotate(0, 3);
					if (num_of_comb == 7) Rotate(4, -3);
					if (num_of_comb == 8) {
						start = 0;
						num_of_comb = 0;
						rb = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
			}
			else if (combination == 20) {
				if (rg == 1) {
					if (num_of_comb == 0) Rotate(4, -3);
					if (num_of_comb == 1) Rotate(0, 3);
					if (num_of_comb == 2) Rotate(0, 3);
					if (num_of_comb == 3) Rotate(4, 3);
					if (num_of_comb == 4) Rotate(0, 3);
					if (num_of_comb == 5) Rotate(4, -3);
					if (num_of_comb == 6) Rotate(0, -3);
					if (num_of_comb == 7) Rotate(4, 3);
					if (num_of_comb == 8) {
						start = 0;
						num_of_comb = 0;
						rg = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (og == 1) {
					if (num_of_comb == 0) Rotate(3, 3);
					if (num_of_comb == 1) Rotate(0, 3);
					if (num_of_comb == 2) Rotate(0, 3);
					if (num_of_comb == 3) Rotate(3, -3);
					if (num_of_comb == 4) Rotate(0, 3);
					if (num_of_comb == 5) Rotate(3, 3);
					if (num_of_comb == 6) Rotate(0, -3);
					if (num_of_comb == 7) Rotate(3, -3);
					if (num_of_comb == 8) {
						start = 0;
						num_of_comb = 0;
						og = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (ob == 1) {
					if (num_of_comb == 0) Rotate(5, 3);
					if (num_of_comb == 1) Rotate(0, 3);
					if (num_of_comb == 2) Rotate(0, 3);
					if (num_of_comb == 3) Rotate(5, -3);
					if (num_of_comb == 4) Rotate(0, 3);
					if (num_of_comb == 5) Rotate(5, 3);
					if (num_of_comb == 6) Rotate(0, -3);
					if (num_of_comb == 7) Rotate(5, -3);
					if (num_of_comb == 8) {
						start = 0;
						num_of_comb = 0;
						ob = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (rb == 1) {
					if (num_of_comb == 0) Rotate(2, -3);
					if (num_of_comb == 1) Rotate(0, 3);
					if (num_of_comb == 2) Rotate(0, 3);
					if (num_of_comb == 3) Rotate(2, 3);
					if (num_of_comb == 4) Rotate(0, 3);
					if (num_of_comb == 5) Rotate(2, -3);
					if (num_of_comb == 6) Rotate(0, -3);
					if (num_of_comb == 7) Rotate(2, 3);
					if (num_of_comb == 8) {
						start = 0;
						num_of_comb = 0;
						rb = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
			}
			else if (combination == 21) {
				if (rg == 1) {
					if (num_of_comb == 0) Rotate(0, 3);
					if (num_of_comb == 1) Rotate(3, -3);
					if (num_of_comb == 2) Rotate(0, 3);
					if (num_of_comb == 3) Rotate(0, 3);
					if (num_of_comb == 4) Rotate(3, 3);
					if (num_of_comb == 5) Rotate(0, 3);
					if (num_of_comb == 6) Rotate(3, -3);
					if (num_of_comb == 7) Rotate(0, -3);
					if (num_of_comb == 8) Rotate(3, 3);
					if (num_of_comb == 9) {
						start = 0;
						num_of_comb = 0;
						rg = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (og == 1) {
					if (num_of_comb == 0) Rotate(0, 3);
					if (num_of_comb == 1) Rotate(5, -3);
					if (num_of_comb == 2) Rotate(0, 3);
					if (num_of_comb == 3) Rotate(0, 3);
					if (num_of_comb == 4) Rotate(5, 3);
					if (num_of_comb == 5) Rotate(0, 3);
					if (num_of_comb == 6) Rotate(5, -3);
					if (num_of_comb == 7) Rotate(0, -3);
					if (num_of_comb == 8) Rotate(5, 3);
					if (num_of_comb == 9) {
						start = 0;
						num_of_comb = 0;
						og = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (ob == 1) {
					if (num_of_comb == 0) Rotate(0, 3);
					if (num_of_comb == 1) Rotate(2, 3);
					if (num_of_comb == 2) Rotate(0, 3);
					if (num_of_comb == 3) Rotate(0, 3);
					if (num_of_comb == 4) Rotate(2, -3);
					if (num_of_comb == 5) Rotate(0, 3);
					if (num_of_comb == 6) Rotate(2, 3);
					if (num_of_comb == 7) Rotate(0, -3);
					if (num_of_comb == 8) Rotate(2, -3);
					if (num_of_comb == 9) {
						start = 0;
						num_of_comb = 0;
						ob = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (rb == 1) {
					if (num_of_comb == 0) Rotate(0, 3);
					if (num_of_comb == 1) Rotate(4, 3);
					if (num_of_comb == 2) Rotate(0, 3);
					if (num_of_comb == 3) Rotate(0, 3);
					if (num_of_comb == 4) Rotate(4, -3);
					if (num_of_comb == 5) Rotate(0, 3);
					if (num_of_comb == 6) Rotate(4, 3);
					if (num_of_comb == 7) Rotate(0, -3);
					if (num_of_comb == 8) Rotate(4, -3);
					if (num_of_comb == 9) {
						start = 0;
						num_of_comb = 0;
						rb = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
			}
			else if (combination == 22) {
				if (rg == 1) {
					if (num_of_comb == 0) Rotate(3, -3);
					if (num_of_comb == 1) Rotate(5, -3);
					if (num_of_comb == 2) Rotate(0, 3);
					if (num_of_comb == 3) Rotate(0, 3);
					if (num_of_comb == 4) Rotate(5, 3);
					if (num_of_comb == 5) Rotate(3, 3);
					if (num_of_comb == 6) {
						start = 0;
						num_of_comb = 0;
						rg = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (og == 1) {
					if (num_of_comb == 0) Rotate(5, -3);
					if (num_of_comb == 1) Rotate(2, 3);
					if (num_of_comb == 2) Rotate(0, 3);
					if (num_of_comb == 3) Rotate(0, 3);
					if (num_of_comb == 4) Rotate(2, -3);
					if (num_of_comb == 5) Rotate(5, 3);
					if (num_of_comb == 6) {
						start = 0;
						num_of_comb = 0;
						og = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (ob == 1) {
					if (num_of_comb == 0) Rotate(2, 3);
					if (num_of_comb == 1) Rotate(4, 3);
					if (num_of_comb == 2) Rotate(0, 3);
					if (num_of_comb == 3) Rotate(0, 3);
					if (num_of_comb == 4) Rotate(4, -3);
					if (num_of_comb == 5) Rotate(2, -3);
					if (num_of_comb == 6) {
						start = 0;
						num_of_comb = 0;
						ob = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (rb == 1) {
					if (num_of_comb == 0) Rotate(4, 3);
					if (num_of_comb == 1) Rotate(3, -3);
					if (num_of_comb == 2) Rotate(0, 3);
					if (num_of_comb == 3) Rotate(0, 3);
					if (num_of_comb == 4) Rotate(3, 3);
					if (num_of_comb == 5) Rotate(4, -3);
					if (num_of_comb == 6) {
						start = 0;
						num_of_comb = 0;
						rb = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
			}
			else if (combination == 23) {
				if (rg == 1) {
					if (num_of_comb == 0) Rotate(0, -3);
					if (num_of_comb == 1) Rotate(4, -3);
					if (num_of_comb == 2) Rotate(0, 3);
					if (num_of_comb == 3) Rotate(0, 3);
					if (num_of_comb == 4) Rotate(4, 3);
					if (num_of_comb == 5) Rotate(0, -3);
					if (num_of_comb == 6) Rotate(4, -3);
					if (num_of_comb == 7) Rotate(0, 3);
					if (num_of_comb == 8) Rotate(4, 3);
					if (num_of_comb == 9) {
						start = 0;
						num_of_comb = 0;
						rg = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (og == 1) {
					if (num_of_comb == 0) Rotate(0, -3);
					if (num_of_comb == 1) Rotate(3, 3);
					if (num_of_comb == 2) Rotate(0, 3);
					if (num_of_comb == 3) Rotate(0, 3);
					if (num_of_comb == 4) Rotate(3, -3);
					if (num_of_comb == 5) Rotate(0, -3);
					if (num_of_comb == 6) Rotate(3, 3);
					if (num_of_comb == 7) Rotate(0, 3);
					if (num_of_comb == 8) Rotate(3, -3);
					if (num_of_comb == 9) {
						start = 0;
						num_of_comb = 0;
						og = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (ob == 1) {
					if (num_of_comb == 0) Rotate(0, -3);
					if (num_of_comb == 1) Rotate(5, 3);
					if (num_of_comb == 2) Rotate(0, 3);
					if (num_of_comb == 3) Rotate(0, 3);
					if (num_of_comb == 4) Rotate(5, -3);
					if (num_of_comb == 5) Rotate(0, -3);
					if (num_of_comb == 6) Rotate(5, 3);
					if (num_of_comb == 7) Rotate(0, 3);
					if (num_of_comb == 8) Rotate(5, -3);
					if (num_of_comb == 9) {
						start = 0;
						num_of_comb = 0;
						ob = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (rb == 1) {
					if (num_of_comb == 0) Rotate(0, -3);
					if (num_of_comb == 1) Rotate(2, -3);
					if (num_of_comb == 2) Rotate(0, 3);
					if (num_of_comb == 3) Rotate(0, 3);
					if (num_of_comb == 4) Rotate(2, 3);
					if (num_of_comb == 5) Rotate(0, -3);
					if (num_of_comb == 6) Rotate(2, -3);
					if (num_of_comb == 7) Rotate(0, 3);
					if (num_of_comb == 8) Rotate(2, 3);
					if (num_of_comb == 9) {
						start = 0;
						num_of_comb = 0;
						rb = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
			}
			else if (combination == 24) {
				if (rg == 1) {
					if (num_of_comb == 0) Rotate(4, -3);
					if (num_of_comb == 1) Rotate(2, -3);
					if (num_of_comb == 2) Rotate(0, 3);
					if (num_of_comb == 3) Rotate(0, 3);
					if (num_of_comb == 4) Rotate(2, 3);
					if (num_of_comb == 5) Rotate(4, 3);
					if (num_of_comb == 6) {
						start = 0;
						num_of_comb = 0;
						rg = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (og == 1) {
					if (num_of_comb == 0) Rotate(3, 3);
					if (num_of_comb == 1) Rotate(4, -3);
					if (num_of_comb == 2) Rotate(0, 3);
					if (num_of_comb == 3) Rotate(0, 3);
					if (num_of_comb == 4) Rotate(4, 3);
					if (num_of_comb == 5) Rotate(3, -3);
					if (num_of_comb == 6) {
						start = 0;
						num_of_comb = 0;
						og = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (ob == 1) {
					if (num_of_comb == 0) Rotate(5, 3);
					if (num_of_comb == 1) Rotate(3, 3);
					if (num_of_comb == 2) Rotate(0, 3);
					if (num_of_comb == 3) Rotate(0, 3);
					if (num_of_comb == 4) Rotate(3, -3);
					if (num_of_comb == 5) Rotate(5, -3);
					if (num_of_comb == 6) {
						start = 0;
						num_of_comb = 0;
						ob = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (rb == 1) {
					if (num_of_comb == 0) Rotate(2, -3);
					if (num_of_comb == 1) Rotate(5, 3);
					if (num_of_comb == 2) Rotate(0, 3);
					if (num_of_comb == 3) Rotate(0, 3);
					if (num_of_comb == 4) Rotate(5, -3);
					if (num_of_comb == 5) Rotate(2, 3);
					if (num_of_comb == 6) {
						start = 0;
						num_of_comb = 0;
						rb = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
			}
			else if (combination == 25) {
				if (rg == 1) {
					if (num_of_comb == 0) Rotate(3, -3);
					if (num_of_comb == 1) Rotate(0, 3);
					if (num_of_comb == 2) Rotate(3, 3);
					if (num_of_comb == 3) Rotate(0, 3);
					if (num_of_comb == 4) Rotate(0, 3);
					if (num_of_comb == 5) Rotate(3, -3);
					if (num_of_comb == 6) Rotate(0, 3);
					if (num_of_comb == 7) Rotate(3, 3);
					if (num_of_comb == 8) Rotate(0, -3);
					if (num_of_comb == 9) Rotate(3, -3);
					if (num_of_comb == 10) Rotate(0, 3);
					if (num_of_comb == 11) Rotate(3, 3);
					if (num_of_comb == 12) {
						start = 0;
						num_of_comb = 0;
						rg = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (og == 1) {
					if (num_of_comb == 0) Rotate(5, -3);
					if (num_of_comb == 1) Rotate(0, 3);
					if (num_of_comb == 2) Rotate(5, 3);
					if (num_of_comb == 3) Rotate(0, 3);
					if (num_of_comb == 4) Rotate(0, 3);
					if (num_of_comb == 5) Rotate(5, -3);
					if (num_of_comb == 6) Rotate(0, 3);
					if (num_of_comb == 7) Rotate(5, 3);
					if (num_of_comb == 8) Rotate(0, -3);
					if (num_of_comb == 9) Rotate(5, -3);
					if (num_of_comb == 10) Rotate(0, 3);
					if (num_of_comb == 11) Rotate(5, 3);
					if (num_of_comb == 12) {
						start = 0;
						num_of_comb = 0;
						og = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (ob == 1) {
					if (num_of_comb == 0) Rotate(2, 3);
					if (num_of_comb == 1) Rotate(0, 3);
					if (num_of_comb == 2) Rotate(2, -3);
					if (num_of_comb == 3) Rotate(0, 3);
					if (num_of_comb == 4) Rotate(0, 3);
					if (num_of_comb == 5) Rotate(2, 3);
					if (num_of_comb == 6) Rotate(0, 3);
					if (num_of_comb == 7) Rotate(2, -3);
					if (num_of_comb == 8) Rotate(0, -3);
					if (num_of_comb == 9) Rotate(2, 3);
					if (num_of_comb == 10) Rotate(0, 3);
					if (num_of_comb == 11) Rotate(2, -3);
					if (num_of_comb == 12) {
						start = 0;
						num_of_comb = 0;
						ob = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (rb == 1) {
					if (num_of_comb == 0) Rotate(4, 3);
					if (num_of_comb == 1) Rotate(0, 3);
					if (num_of_comb == 2) Rotate(4, -3);
					if (num_of_comb == 3) Rotate(0, 3);
					if (num_of_comb == 4) Rotate(0, 3);
					if (num_of_comb == 5) Rotate(4, 3);
					if (num_of_comb == 6) Rotate(0, 3);
					if (num_of_comb == 7) Rotate(4, -3);
					if (num_of_comb == 8) Rotate(0, -3);
					if (num_of_comb == 9) Rotate(4, 3);
					if (num_of_comb == 10) Rotate(0, 3);
					if (num_of_comb == 11) Rotate(4, -3);
					if (num_of_comb == 12) {
						start = 0;
						num_of_comb = 0;
						rb = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
			}
			else if (combination == 26) {
				if (rg == 1) {
					if (num_of_comb == 0) Rotate(4, 3);
					if (num_of_comb == 1) Rotate(0, 3);
					if (num_of_comb == 2) Rotate(3, -3);
					if (num_of_comb == 3) Rotate(0, -3);
					if (num_of_comb == 4) Rotate(3, 3);
					if (num_of_comb == 5) Rotate(4, -3);
					if (num_of_comb == 6) Rotate(3, -3);
					if (num_of_comb == 7) Rotate(0, -3);
					if (num_of_comb == 8) Rotate(3, 3);
					if (num_of_comb == 9) {
						start = 0;
						num_of_comb = 0;
						rg = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (og == 1) {
					if (num_of_comb == 0) Rotate(3, -3);
					if (num_of_comb == 1) Rotate(0, 3);
					if (num_of_comb == 2) Rotate(5, -3);
					if (num_of_comb == 3) Rotate(0, -3);
					if (num_of_comb == 4) Rotate(5, 3);
					if (num_of_comb == 5) Rotate(3, 3);
					if (num_of_comb == 6) Rotate(5, -3);
					if (num_of_comb == 7) Rotate(0, -3);
					if (num_of_comb == 8) Rotate(5, 3);
					if (num_of_comb == 9) {
						start = 0;
						num_of_comb = 0;
						og = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (ob == 1) {
					if (num_of_comb == 0) Rotate(5, -3);
					if (num_of_comb == 1) Rotate(0, 3);
					if (num_of_comb == 2) Rotate(2, 3);
					if (num_of_comb == 3) Rotate(0, -3);
					if (num_of_comb == 4) Rotate(2, -3);
					if (num_of_comb == 5) Rotate(5, 3);
					if (num_of_comb == 6) Rotate(2, 3);
					if (num_of_comb == 7) Rotate(0, -3);
					if (num_of_comb == 8) Rotate(2, -3);
					if (num_of_comb == 9) {
						start = 0;
						num_of_comb = 0;
						ob = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (rb == 1) {
					if (num_of_comb == 0) Rotate(2, 3);
					if (num_of_comb == 1) Rotate(0, 3);
					if (num_of_comb == 2) Rotate(4, 3);
					if (num_of_comb == 3) Rotate(0, -3);
					if (num_of_comb == 4) Rotate(4, -3);
					if (num_of_comb == 5) Rotate(2, -3);
					if (num_of_comb == 6) Rotate(4, 3);
					if (num_of_comb == 7) Rotate(0, -3);
					if (num_of_comb == 8) Rotate(4, -3);
					if (num_of_comb == 9) {
						start = 0;
						num_of_comb = 0;
						rb = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
			}
			else if (combination == 31) {
				if (rg == 1) {
					if (num_of_comb == 0) Rotate(3, -3);
					if (num_of_comb == 1) Rotate(0, -3);
					if (num_of_comb == 2) Rotate(3, 3);
					if (num_of_comb == 3) Rotate(4, -3);
					if (num_of_comb == 4) Rotate(0, 3);
					if (num_of_comb == 5) Rotate(0, 3);
					if (num_of_comb == 6) Rotate(4, 3);
					if (num_of_comb == 7) {
						start = 0;
						num_of_comb = 0;
						rg = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (og == 1) {
					if (num_of_comb == 0) Rotate(5, -3);
					if (num_of_comb == 1) Rotate(0, -3);
					if (num_of_comb == 2) Rotate(5, 3);
					if (num_of_comb == 3) Rotate(3, 3);
					if (num_of_comb == 4) Rotate(0, 3);
					if (num_of_comb == 5) Rotate(0, 3);
					if (num_of_comb == 6) Rotate(3, -3);
					if (num_of_comb == 7) {
						start = 0;
						num_of_comb = 0;
						og = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (ob == 1) {
					if (num_of_comb == 0) Rotate(2, 3);
					if (num_of_comb == 1) Rotate(0, -3);
					if (num_of_comb == 2) Rotate(2, -3);
					if (num_of_comb == 3) Rotate(5, 3);
					if (num_of_comb == 4) Rotate(0, 3);
					if (num_of_comb == 5) Rotate(0, 3);
					if (num_of_comb == 6) Rotate(5, -3);
					if (num_of_comb == 7) {
						start = 0;
						num_of_comb = 0;
						ob = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (rb == 1) {
					if (num_of_comb == 0) Rotate(4, 3);
					if (num_of_comb == 1) Rotate(0, -3);
					if (num_of_comb == 2) Rotate(4, -3);
					if (num_of_comb == 3) Rotate(2, -3);
					if (num_of_comb == 4) Rotate(0, 3);
					if (num_of_comb == 5) Rotate(0, 3);
					if (num_of_comb == 6) Rotate(2, 3);
					if (num_of_comb == 7) {
						start = 0;
						num_of_comb = 0;
						rb = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
			}
			else if (combination == 32) {
				if (rg == 1) {
					if (num_of_comb == 0) Rotate(0, -3);
					if (num_of_comb == 1) Rotate(3, -3);
					if (num_of_comb == 2) Rotate(0, 3);
					if (num_of_comb == 3) Rotate(3, 3);
					if (num_of_comb == 4) Rotate(0, 3);
					if (num_of_comb == 5) Rotate(4, -3);
					if (num_of_comb == 6) Rotate(0, -3);
					if (num_of_comb == 7) Rotate(4, 3);
					if (num_of_comb == 8) {
						start = 0;
						num_of_comb = 0;
						rg = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (og == 1) {
					if (num_of_comb == 0) Rotate(0, -3);
					if (num_of_comb == 1) Rotate(5, -3);
					if (num_of_comb == 2) Rotate(0, 3);
					if (num_of_comb == 3) Rotate(5, 3);
					if (num_of_comb == 4) Rotate(0, 3);
					if (num_of_comb == 5) Rotate(3, 3);
					if (num_of_comb == 6) Rotate(0, -3);
					if (num_of_comb == 7) Rotate(3, -3);
					if (num_of_comb == 8) {
						start = 0;
						num_of_comb = 0;
						og = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (ob == 1) {
					if (num_of_comb == 0) Rotate(0, -3);
					if (num_of_comb == 1) Rotate(2, 3);
					if (num_of_comb == 2) Rotate(0, 3);
					if (num_of_comb == 3) Rotate(2, -3);
					if (num_of_comb == 4) Rotate(0, 3);
					if (num_of_comb == 5) Rotate(5, 3);
					if (num_of_comb == 6) Rotate(0, -3);
					if (num_of_comb == 7) Rotate(5, -3);
					if (num_of_comb == 8) {
						start = 0;
						num_of_comb = 0;
						ob = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (rb == 1) {
					if (num_of_comb == 0) Rotate(0, -3);
					if (num_of_comb == 1) Rotate(4, 3);
					if (num_of_comb == 2) Rotate(0, 3);
					if (num_of_comb == 3) Rotate(4, -3);
					if (num_of_comb == 4) Rotate(0, 3);
					if (num_of_comb == 5) Rotate(2, -3);
					if (num_of_comb == 6) Rotate(0, -3);
					if (num_of_comb == 7) Rotate(2, 3);
					if (num_of_comb == 8) {
						start = 0;
						num_of_comb = 0;
						rb = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
			}
			else if (combination == 33) {
				if (rg == 1) {
					if (num_of_comb == 0) Rotate(3, -3);
					if (num_of_comb == 1) Rotate(0, 3);
					if (num_of_comb == 2) Rotate(3, 3);
					if (num_of_comb == 3) Rotate(0, -3);
					if (num_of_comb == 4) Rotate(3, -3);
					if (num_of_comb == 5) Rotate(0, 3);
					if (num_of_comb == 6) Rotate(3, 3);
					if (num_of_comb == 7) Rotate(0, -3);
					if (num_of_comb == 8) Rotate(3, -3);
					if (num_of_comb == 9) Rotate(0, 3);
					if (num_of_comb == 10) Rotate(3, 3);
					if (num_of_comb == 11) {
						start = 0;
						num_of_comb = 0;
						rg = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (og == 1) {
					if (num_of_comb == 0) Rotate(5, -3);
					if (num_of_comb == 1) Rotate(0, 3);
					if (num_of_comb == 2) Rotate(5, 3);
					if (num_of_comb == 3) Rotate(0, -3);
					if (num_of_comb == 4) Rotate(5, -3);
					if (num_of_comb == 5) Rotate(0, 3);
					if (num_of_comb == 6) Rotate(5, 3);
					if (num_of_comb == 7) Rotate(0, -3);
					if (num_of_comb == 8) Rotate(5, -3);
					if (num_of_comb == 9) Rotate(0, 3);
					if (num_of_comb == 10) Rotate(5, 3);
					if (num_of_comb == 11) {
						start = 0;
						num_of_comb = 0;
						og = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (ob == 1) {
					if (num_of_comb == 0) Rotate(2, 3);
					if (num_of_comb == 1) Rotate(0, 3);
					if (num_of_comb == 2) Rotate(2, -3);
					if (num_of_comb == 3) Rotate(0, -3);
					if (num_of_comb == 4) Rotate(2, 3);
					if (num_of_comb == 5) Rotate(0, 3);
					if (num_of_comb == 6) Rotate(2, -3);
					if (num_of_comb == 7) Rotate(0, -3);
					if (num_of_comb == 8) Rotate(2, 3);
					if (num_of_comb == 9) Rotate(0, 3);
					if (num_of_comb == 10) Rotate(2, -3);
					if (num_of_comb == 11) {
						start = 0;
						num_of_comb = 0;
						ob = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (rb == 1) {
					if (num_of_comb == 0) Rotate(4, 3);
					if (num_of_comb == 1) Rotate(0, 3);
					if (num_of_comb == 2) Rotate(4, -3);
					if (num_of_comb == 3) Rotate(0, -3);
					if (num_of_comb == 4) Rotate(4, 3);
					if (num_of_comb == 5) Rotate(0, 3);
					if (num_of_comb == 6) Rotate(4, -3);
					if (num_of_comb == 7) Rotate(0, -3);
					if (num_of_comb == 8) Rotate(4, 3);
					if (num_of_comb == 9) Rotate(0, 3);
					if (num_of_comb == 10) Rotate(4, -3);
					if (num_of_comb == 11) {
						start = 0;
						num_of_comb = 0;
						rb = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
			}
			else if (combination == 34) {
				if (rg == 1) {
					if (num_of_comb == 0) Rotate(0, 3);
					if (num_of_comb == 1) Rotate(4, -3);
					if (num_of_comb == 2) Rotate(0, -3);
					if (num_of_comb == 3) Rotate(4, 3);
					if (num_of_comb == 4) Rotate(0, -3);
					if (num_of_comb == 5) Rotate(3, -3);
					if (num_of_comb == 6) Rotate(0, 3);
					if (num_of_comb == 7) Rotate(3, 3);
					if (num_of_comb == 8) {
						start = 0;
						num_of_comb = 0;
						rg = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (og == 1) {
					if (num_of_comb == 0) Rotate(0, 3);
					if (num_of_comb == 1) Rotate(3, 3);
					if (num_of_comb == 2) Rotate(0, -3);
					if (num_of_comb == 3) Rotate(3, -3);
					if (num_of_comb == 4) Rotate(0, -3);
					if (num_of_comb == 5) Rotate(5, -3);
					if (num_of_comb == 6) Rotate(0, 3);
					if (num_of_comb == 7) Rotate(5, 3);
					if (num_of_comb == 8) {
						start = 0;
						num_of_comb = 0;
						og = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (ob == 1) {
					if (num_of_comb == 0) Rotate(0, 3);
					if (num_of_comb == 1) Rotate(5, 3);
					if (num_of_comb == 2) Rotate(0, -3);
					if (num_of_comb == 3) Rotate(5, -3);
					if (num_of_comb == 4) Rotate(0, -3);
					if (num_of_comb == 5) Rotate(2, 3);
					if (num_of_comb == 6) Rotate(0, 3);
					if (num_of_comb == 7) Rotate(2, -3);
					if (num_of_comb == 8) {
						start = 0;
						num_of_comb = 0;
						ob = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (rb == 1) {
					if (num_of_comb == 0) Rotate(0, 3);
					if (num_of_comb == 1) Rotate(2, -3);
					if (num_of_comb == 2) Rotate(0, -3);
					if (num_of_comb == 3) Rotate(2, 3);
					if (num_of_comb == 4) Rotate(0, -3);
					if (num_of_comb == 5) Rotate(4, 3);
					if (num_of_comb == 6) Rotate(0, 3);
					if (num_of_comb == 7) Rotate(4, -3);
					if (num_of_comb == 8) {
						start = 0;
						num_of_comb = 0;
						rb = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
			}
			else if (combination == 35) {
				if (rg == 1) {
					if (num_of_comb == 0) Rotate(0, -3);
					if (num_of_comb == 1) Rotate(3, -3);
					if (num_of_comb == 2) Rotate(0, -3);
					if (num_of_comb == 3) Rotate(3, 3);
					if (num_of_comb == 4) Rotate(0, 3);
					if (num_of_comb == 5) Rotate(0, 3);
					if (num_of_comb == 6) Rotate(3, -3);
					if (num_of_comb == 7) Rotate(0, -3);
					if (num_of_comb == 8) Rotate(3, 3);
					if (num_of_comb == 9) {
						start = 0;
						num_of_comb = 0;
						rg = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (og == 1) {
					if (num_of_comb == 0) Rotate(0, -3);
					if (num_of_comb == 1) Rotate(5, -3);
					if (num_of_comb == 2) Rotate(0, -3);
					if (num_of_comb == 3) Rotate(5, 3);
					if (num_of_comb == 4) Rotate(0, 3);
					if (num_of_comb == 5) Rotate(0, 3);
					if (num_of_comb == 6) Rotate(5, -3);
					if (num_of_comb == 7) Rotate(0, -3);
					if (num_of_comb == 8) Rotate(5, 3);
					if (num_of_comb == 9) {
						start = 0;
						num_of_comb = 0;
						og = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (ob == 1) {
					if (num_of_comb == 0) Rotate(0, -3);
					if (num_of_comb == 1) Rotate(2, 3);
					if (num_of_comb == 2) Rotate(0, -3);
					if (num_of_comb == 3) Rotate(2, -3);
					if (num_of_comb == 4) Rotate(0, 3);
					if (num_of_comb == 5) Rotate(0, 3);
					if (num_of_comb == 6) Rotate(2, 3);
					if (num_of_comb == 7) Rotate(0, -3);
					if (num_of_comb == 8) Rotate(2, -3);
					if (num_of_comb == 9) {
						start = 0;
						num_of_comb = 0;
						ob = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (rb == 1) {
					if (num_of_comb == 0) Rotate(0, -3);
					if (num_of_comb == 1) Rotate(4, 3);
					if (num_of_comb == 2) Rotate(0, -3);
					if (num_of_comb == 3) Rotate(4, -3);
					if (num_of_comb == 4) Rotate(0, 3);
					if (num_of_comb == 5) Rotate(0, 3);
					if (num_of_comb == 6) Rotate(4, 3);
					if (num_of_comb == 7) Rotate(0, -3);
					if (num_of_comb == 8) Rotate(4, -3);
					if (num_of_comb == 9) {
						start = 0;
						num_of_comb = 0;
						rb = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
			}
			else if (combination == 36) {
				if (rg == 1) {
					if (num_of_comb == 0) Rotate(0, 3);
					if (num_of_comb == 1) Rotate(3, -3);
					if (num_of_comb == 2) Rotate(0, 3);
					if (num_of_comb == 3) Rotate(3, 3);
					if (num_of_comb == 4) Rotate(0, 3);
					if (num_of_comb == 5) Rotate(0, 3);
					if (num_of_comb == 6) Rotate(3, -3);
					if (num_of_comb == 7) Rotate(0, 3);
					if (num_of_comb == 8) Rotate(3, 3);
					if (num_of_comb == 9) {
						start = 0;
						num_of_comb = 0;
						rg = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (og == 1) {
					if (num_of_comb == 0) Rotate(0, 3);
					if (num_of_comb == 1) Rotate(5, -3);
					if (num_of_comb == 2) Rotate(0, 3);
					if (num_of_comb == 3) Rotate(5, 3);
					if (num_of_comb == 4) Rotate(0, 3);
					if (num_of_comb == 5) Rotate(0, 3);
					if (num_of_comb == 6) Rotate(5, -3);
					if (num_of_comb == 7) Rotate(0, 3);
					if (num_of_comb == 8) Rotate(5, 3);
					if (num_of_comb == 9) {
						start = 0;
						num_of_comb = 0;
						og = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (ob == 1) {
					if (num_of_comb == 0) Rotate(0, 3);
					if (num_of_comb == 1) Rotate(2, 3);
					if (num_of_comb == 2) Rotate(0, 3);
					if (num_of_comb == 3) Rotate(2, -3);
					if (num_of_comb == 4) Rotate(0, 3);
					if (num_of_comb == 5) Rotate(0, 3);
					if (num_of_comb == 6) Rotate(2, 3);
					if (num_of_comb == 7) Rotate(0, 3);
					if (num_of_comb == 8) Rotate(2, -3);
					if (num_of_comb == 9) {
						start = 0;
						num_of_comb = 0;
						ob = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (rb == 1) {
					if (num_of_comb == 0) Rotate(0, 3);
					if (num_of_comb == 1) Rotate(4, 3);
					if (num_of_comb == 2) Rotate(0, 3);
					if (num_of_comb == 3) Rotate(4, -3);
					if (num_of_comb == 4) Rotate(0, 3);
					if (num_of_comb == 5) Rotate(0, 3);
					if (num_of_comb == 6) Rotate(4, 3);
					if (num_of_comb == 7) Rotate(0, 3);
					if (num_of_comb == 8) Rotate(4, -3);
					if (num_of_comb == 9) {
						start = 0;
						num_of_comb = 0;
						rb = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
			}
			lup = 0;
			rup = 0;
			ldown = 0;
			rdown = 0;
		}
		else if (wrong == 6) {
			if (combination == 1) {
				if (rg == 1) {
					if (num_of_comb == 0) {
						Rotate(3, -3);
					}
					if (num_of_comb == 1) {
						Rotate(0, 3);
					}
					if (num_of_comb == 2) {
						Rotate(3, 3);
					}
					if (num_of_comb == 3) {
						Rotate(0, -3);
					}
					if (num_of_comb == 4) {
						Rotate(4, -3);
					}
					if (num_of_comb == 5) {
						Rotate(0, -3);
					}
					if (num_of_comb == 6) {
						Rotate(4, 3);
					}
					if (num_of_comb == 7) {
						start = 0;
						num_of_comb = 0;
						rg = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (og == 1) {
					if (num_of_comb == 0) {
						Rotate(5, -3);
					}
					if (num_of_comb == 1) {
						Rotate(0, 3);
					}
					if (num_of_comb == 2) {
						Rotate(5, 3);
					}
					if (num_of_comb == 3) {
						Rotate(0, -3);
					}
					if (num_of_comb == 4) {
						Rotate(3, 3);
					}
					if (num_of_comb == 5) {
						Rotate(0, -3);
					}
					if (num_of_comb == 6) {
						Rotate(3, -3);
					}
					if (num_of_comb == 7) {
						start = 0;
						num_of_comb = 0;
						og = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (ob == 1) {
					if (num_of_comb == 0) {
						Rotate(2, 3);
					}
					if (num_of_comb == 1) {
						Rotate(0, 3);
					}
					if (num_of_comb == 2) {
						Rotate(2, -3);
					}
					if (num_of_comb == 3) {
						Rotate(0, -3);
					}
					if (num_of_comb == 4) {
						Rotate(5, 3);
					}
					if (num_of_comb == 5) {
						Rotate(0, -3);
					}
					if (num_of_comb == 6) {
						Rotate(5, -3);
					}
					if (num_of_comb == 7) {
						start = 0;
						num_of_comb = 0;
						ob = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (rb == 1) {
					if (num_of_comb == 0) {
						Rotate(4, 3);
					}
					if (num_of_comb == 1) {
						Rotate(0, 3);
					}
					if (num_of_comb == 2) {
						Rotate(4, -3);
					}
					if (num_of_comb == 3) {
						Rotate(0, -3);
					}
					if (num_of_comb == 4) {
						Rotate(2, -3);
					}
					if (num_of_comb == 5) {
						Rotate(0, -3);
					}
					if (num_of_comb == 6) {
						Rotate(2, 3);
					}
					if (num_of_comb == 7) {
						start = 0;
						num_of_comb = 0;
						rb = 0;
						wrong = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
			}
			else if (combination == 2) {
				if (rg == 1) {
					if (num_of_comb == 0) Rotate(0, -3);
					if (num_of_comb == 1) Rotate(4, -3);
					if (num_of_comb == 2) Rotate(0, 3);
					if (num_of_comb == 3) Rotate(4, 3);
					if (num_of_comb == 4) Rotate(0, 3);
					if (num_of_comb == 5) Rotate(3, -3);
					if (num_of_comb == 6) Rotate(0, -3);
					if (num_of_comb == 7) Rotate(3, 3);
					if (num_of_comb == 8) {
						start = 0;
						num_of_comb = 0;
						rg = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (og == 1) {
					if (num_of_comb == 0) Rotate(0, -3);
					if (num_of_comb == 1) Rotate(3, 3);
					if (num_of_comb == 2) Rotate(0, 3);
					if (num_of_comb == 3) Rotate(3, -3);
					if (num_of_comb == 4) Rotate(0, 3);
					if (num_of_comb == 5) Rotate(5, -3);
					if (num_of_comb == 6) Rotate(0, -3);
					if (num_of_comb == 7) Rotate(5, 3);
					if (num_of_comb == 8) {
						start = 0;
						num_of_comb = 0;
						og = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (ob == 1) {
					if (num_of_comb == 0) Rotate(0, -3);
					if (num_of_comb == 1) Rotate(5, 3);
					if (num_of_comb == 2) Rotate(0, 3);
					if (num_of_comb == 3) Rotate(5, -3);
					if (num_of_comb == 4) Rotate(0, 3);
					if (num_of_comb == 5) Rotate(2, 3);
					if (num_of_comb == 6) Rotate(0, -3);
					if (num_of_comb == 7) Rotate(2, -3);
					if (num_of_comb == 8) {
						start = 0;
						num_of_comb = 0;
						ob = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (rb == 1) {
					if (num_of_comb == 0) Rotate(0, -3);
					if (num_of_comb == 1) Rotate(2, -3);
					if (num_of_comb == 2) Rotate(0, 3);
					if (num_of_comb == 3) Rotate(2, 3);
					if (num_of_comb == 4) Rotate(0, 3);
					if (num_of_comb == 5) Rotate(4, 3);
					if (num_of_comb == 6) Rotate(0, -3);
					if (num_of_comb == 7) Rotate(4, -3);
					if (num_of_comb == 8) {
						start = 0;
						num_of_comb = 0;
						rb = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
			}
			else if (combination == 27) {
				if (rg == 1) {
					if (num_of_comb == 0) Rotate(4, -3);
					if (num_of_comb == 1) Rotate(0, -3);
					if (num_of_comb == 2) Rotate(4, 3);
					if (num_of_comb == 3) Rotate(0, 3);
					if (num_of_comb == 4) Rotate(4, -3);
					if (num_of_comb == 5) Rotate(0, -3);
					if (num_of_comb == 6) Rotate(4, 3);
					if (num_of_comb == 7) {
						start = 0;
						num_of_comb = 0;
						rg = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (og == 1) {
					if (num_of_comb == 0) Rotate(3, 3);
					if (num_of_comb == 1) Rotate(0, -3);
					if (num_of_comb == 2) Rotate(3, -3);
					if (num_of_comb == 3) Rotate(0, 3);
					if (num_of_comb == 4) Rotate(3, 3);
					if (num_of_comb == 5) Rotate(0, -3);
					if (num_of_comb == 6) Rotate(3, -3);
					if (num_of_comb == 7) {
						start = 0;
						num_of_comb = 0;
						og = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (ob == 1) {
					if (num_of_comb == 0) Rotate(5, 3);
					if (num_of_comb == 1) Rotate(0, -3);
					if (num_of_comb == 2) Rotate(5, -3);
					if (num_of_comb == 3) Rotate(0, 3);
					if (num_of_comb == 4) Rotate(5, 3);
					if (num_of_comb == 5) Rotate(0, -3);
					if (num_of_comb == 6) Rotate(5, -3);
					if (num_of_comb == 7) {
						start = 0;
						num_of_comb = 0;
						ob = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (rb == 1) {
					if (num_of_comb == 0) Rotate(2, -3);
					if (num_of_comb == 1) Rotate(0, -3);
					if (num_of_comb == 2) Rotate(2, 3);
					if (num_of_comb == 3) Rotate(0, 3);
					if (num_of_comb == 4) Rotate(2, -3);
					if (num_of_comb == 5) Rotate(0, -3);
					if (num_of_comb == 6) Rotate(2, 3);
					if (num_of_comb == 7) {
						start = 0;
						num_of_comb = 0;
						rb = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
			}
			else if (combination == 28) {
					if (rg == 1) {
						if (num_of_comb == 0) Rotate(3, -3);
						if (num_of_comb == 1) Rotate(0, -3);
						if (num_of_comb == 2) Rotate(3, 3);
						if (num_of_comb == 3) Rotate(0, 3);
						if (num_of_comb == 4) Rotate(3, -3);
						if (num_of_comb == 5) Rotate(0, -3);
						if (num_of_comb == 6) Rotate(3, 3);
						if (num_of_comb == 7) {
							start = 0;
							num_of_comb = 0;
							rg = 0;
							lup = 0;
							rup = 0;
							ldown = 0;
							rdown = 0;
							wrong = 0;
						}
					}
					else if (og == 1) {
						if (num_of_comb == 0) Rotate(5, -3);
						if (num_of_comb == 1) Rotate(0, -3);
						if (num_of_comb == 2) Rotate(5, 3);
						if (num_of_comb == 3) Rotate(0, 3);
						if (num_of_comb == 4) Rotate(5, -3);
						if (num_of_comb == 5) Rotate(0, -3);
						if (num_of_comb == 6) Rotate(5, 3);
						if (num_of_comb == 7) {
							start = 0;
							num_of_comb = 0;
							og = 0;
							lup = 0;
							rup = 0;
							ldown = 0;
							rdown = 0;
							wrong = 0;
						}
					}
					else if (ob == 1) {
						if (num_of_comb == 0) Rotate(2, 3);
						if (num_of_comb == 1) Rotate(0, -3);
						if (num_of_comb == 2) Rotate(2, -3);
						if (num_of_comb == 3) Rotate(0, 3);
						if (num_of_comb == 4) Rotate(2, 3);
						if (num_of_comb == 5) Rotate(0, -3);
						if (num_of_comb == 6) Rotate(2, -3);
						if (num_of_comb == 7) {
							start = 0;
							num_of_comb = 0;
							ob = 0;
							lup = 0;
							rup = 0;
							ldown = 0;
							rdown = 0;
							wrong = 0;
						}
					}
					else if (rb == 1) {
						if (num_of_comb == 0) Rotate(4, 3);
						if (num_of_comb == 1) Rotate(0, -3);
						if (num_of_comb == 2) Rotate(4, -3);
						if (num_of_comb == 3) Rotate(0, 3);
						if (num_of_comb == 4) Rotate(4, 3);
						if (num_of_comb == 5) Rotate(0, -3);
						if (num_of_comb == 6) Rotate(4, -3);
						if (num_of_comb == 7) {
							start = 0;
							num_of_comb = 0;
							rb = 0;
							lup = 0;
							rup = 0;
							ldown = 0;
							rdown = 0;
							wrong = 0;
						}
					}
					}
			else if (combination == 29) {
				if (rg == 1) {
					if (num_of_comb == 0) Rotate(4, -3);
					if (num_of_comb == 1) Rotate(0, 3);
					if (num_of_comb == 2) Rotate(4, 3);
					if (num_of_comb == 3) Rotate(0, -3);
					if (num_of_comb == 4) Rotate(4, -3);
					if (num_of_comb == 5) Rotate(0, 3);
					if (num_of_comb == 6) Rotate(4, 3);
					if (num_of_comb == 7) {
						start = 0;
						num_of_comb = 0;
						rg = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (og == 1) {
					if (num_of_comb == 0) Rotate(3, 3);
					if (num_of_comb == 1) Rotate(0, 3);
					if (num_of_comb == 2) Rotate(3, -3);
					if (num_of_comb == 3) Rotate(0, -3);
					if (num_of_comb == 4) Rotate(3, 3);
					if (num_of_comb == 5) Rotate(0, 3);
					if (num_of_comb == 6) Rotate(3, -3);
					if (num_of_comb == 7) {
						start = 0;
						num_of_comb = 0;
						og = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (ob == 1) {
					if (num_of_comb == 0) Rotate(5, 3);
					if (num_of_comb == 1) Rotate(0, 3);
					if (num_of_comb == 2) Rotate(5, -3);
					if (num_of_comb == 3) Rotate(0, -3);
					if (num_of_comb == 4) Rotate(5, 3);
					if (num_of_comb == 5) Rotate(0, 3);
					if (num_of_comb == 6) Rotate(5, -3);
					if (num_of_comb == 7) {
						start = 0;
						num_of_comb = 0;
						ob = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (rb == 1) {
					if (num_of_comb == 0) Rotate(2, -3);
					if (num_of_comb == 1) Rotate(0, 3);
					if (num_of_comb == 2) Rotate(2, 3);
					if (num_of_comb == 3) Rotate(0, -3);
					if (num_of_comb == 4) Rotate(2, -3);
					if (num_of_comb == 5) Rotate(0, 3);
					if (num_of_comb == 6) Rotate(2, 3);
					if (num_of_comb == 7) {
						start = 0;
						num_of_comb = 0;
						rb = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
			}
			else if (combination == 30) {
				if (rg == 1) {
					if (num_of_comb == 0) Rotate(4, 3);
					if (num_of_comb == 1) Rotate(3, 3);
					if (num_of_comb == 2) Rotate(4, -3);
					if (num_of_comb == 3) Rotate(3, -3);
					if (num_of_comb == 4) Rotate(4, 3);
					if (num_of_comb == 5) Rotate(3, 3);
					if (num_of_comb == 6) Rotate(4, -3);
					if (num_of_comb == 7) Rotate(3, -3);
					if (num_of_comb == 8) {
						start = 0;
						num_of_comb = 0;
						rg = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (og == 1) {
					if (num_of_comb == 0) Rotate(3, -3);
					if (num_of_comb == 1) Rotate(5, 3);
					if (num_of_comb == 2) Rotate(3, 3);
					if (num_of_comb == 3) Rotate(5, -3);
					if (num_of_comb == 4) Rotate(3, -3);
					if (num_of_comb == 5) Rotate(5, 3);
					if (num_of_comb == 6) Rotate(3, 3);
					if (num_of_comb == 7) Rotate(5, -3);
					if (num_of_comb == 8) {
						start = 0;
						num_of_comb = 0;
						og = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (ob == 1) {
					if (num_of_comb == 0) Rotate(5, -3);
					if (num_of_comb == 1) Rotate(2, -3);
					if (num_of_comb == 2) Rotate(5, 3);
					if (num_of_comb == 3) Rotate(2, 3);
					if (num_of_comb == 4) Rotate(5, -3);
					if (num_of_comb == 5) Rotate(2, -3);
					if (num_of_comb == 6) Rotate(5, 3);
					if (num_of_comb == 7) Rotate(2, 3);
					if (num_of_comb == 8) {
						start = 0;
						num_of_comb = 0;
						ob = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (rb == 1) {
					if (num_of_comb == 0) Rotate(2, 3);
					if (num_of_comb == 1) Rotate(4, -3);
					if (num_of_comb == 2) Rotate(2, -3);
					if (num_of_comb == 3) Rotate(4, 3);
					if (num_of_comb == 4) Rotate(2, 3);
					if (num_of_comb == 5) Rotate(4, -3);
					if (num_of_comb == 6) Rotate(2, -3);
					if (num_of_comb == 7) Rotate(4, 3);
					if (num_of_comb == 8) {
						start = 0;
						num_of_comb = 0;
						rb = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
			}
			else if (combination == 37) {
				if (rg == 1) {
					if (num_of_comb == 0) Rotate(3, -3);
					if (num_of_comb == 1) Rotate(4, -3);
					if (num_of_comb == 2) Rotate(3, -3);
					if (num_of_comb == 3) Rotate(0, -3);
					if (num_of_comb == 4) Rotate(3, 3);
					if (num_of_comb == 5) Rotate(0, 3);
					if (num_of_comb == 6) Rotate(3, -3);
					if (num_of_comb == 7) Rotate(0, -3);
					if (num_of_comb == 8) Rotate(3, 3);
					if (num_of_comb == 9) Rotate(0, 3);
					if (num_of_comb == 10) Rotate(0, 3);
					if (num_of_comb == 11) Rotate(3, -3);
					if (num_of_comb == 12) Rotate(0, -3);
					if (num_of_comb == 13) Rotate(3, 3);
					if (num_of_comb == 14) {
						start = 0;
						num_of_comb = 0;
						rg = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (og == 1) {
					if (num_of_comb == 0) Rotate(5, -3);
					if (num_of_comb == 1) Rotate(3, 3);
					if (num_of_comb == 2) Rotate(5, -3);
					if (num_of_comb == 3) Rotate(0, -3);
					if (num_of_comb == 4) Rotate(5, 3);
					if (num_of_comb == 5) Rotate(0, 3);
					if (num_of_comb == 6) Rotate(5, -3);
					if (num_of_comb == 7) Rotate(0, -3);
					if (num_of_comb == 8) Rotate(5, 3);
					if (num_of_comb == 9) Rotate(0, 3);
					if (num_of_comb == 10) Rotate(0, 3);
					if (num_of_comb == 11) Rotate(5, -3);
					if (num_of_comb == 12) Rotate(0, -3);
					if (num_of_comb == 13) Rotate(5, 3);
					if (num_of_comb == 14){
						start = 0;
						num_of_comb = 0;
						og = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (ob == 1) {
					if (num_of_comb == 0) Rotate(2, 3);
					if (num_of_comb == 1) Rotate(5, 3);
					if (num_of_comb == 2) Rotate(2, 3);
					if (num_of_comb == 3) Rotate(0, -3);
					if (num_of_comb == 4) Rotate(2, -3);
					if (num_of_comb == 5) Rotate(0, 3);
					if (num_of_comb == 6) Rotate(2, 3);
					if (num_of_comb == 7) Rotate(0, -3);
					if (num_of_comb == 8) Rotate(2, -3);
					if (num_of_comb == 9) Rotate(0, 3);
					if (num_of_comb == 10) Rotate(0, 3);
					if (num_of_comb == 11) Rotate(2, 3);
					if (num_of_comb == 12) Rotate(0, -3);
					if (num_of_comb == 13) Rotate(2, -3);
					if (num_of_comb == 14) {
						start = 0;
						num_of_comb = 0;
						ob = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (rb == 1) {
					if (num_of_comb == 0) Rotate(4, 3);
					if (num_of_comb == 1) Rotate(2, -3);
					if (num_of_comb == 2) Rotate(4, 3);
					if (num_of_comb == 3) Rotate(0, -3);
					if (num_of_comb == 4) Rotate(4, -3);
					if (num_of_comb == 5) Rotate(0, 3);
					if (num_of_comb == 6) Rotate(4, 3);
					if (num_of_comb == 7) Rotate(0, -3);
					if (num_of_comb == 8) Rotate(4, -3);
					if (num_of_comb == 9) Rotate(0, 3);
					if (num_of_comb == 10) Rotate(0, 3);
					if (num_of_comb == 11) Rotate(4, 3);
					if (num_of_comb == 12) Rotate(0, -3);
					if (num_of_comb == 13) Rotate(4, -3);
					if (num_of_comb == 14) {
						start = 0;
						num_of_comb = 0;
						rb = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
			}
			else if (combination == 38) {
				if (rg == 1) {
					if (num_of_comb == 0) Rotate(3, -3);
					if (num_of_comb == 1) Rotate(0, 3);
					if (num_of_comb == 2) Rotate(4, 3);
					if (num_of_comb == 3) Rotate(3, -3);
					if (num_of_comb == 4) Rotate(0, 3);
					if (num_of_comb == 5) Rotate(3, 3);
					if (num_of_comb == 6) Rotate(0, -3);
					if (num_of_comb == 7) Rotate(4, -3);
					if (num_of_comb == 8) Rotate(3, 3);
					if (num_of_comb == 9) {
						start = 0;
						num_of_comb = 0;
						rg = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (og == 1) {
					if (num_of_comb == 0) Rotate(5, -3);
					if (num_of_comb == 1) Rotate(0, 3);
					if (num_of_comb == 2) Rotate(3, -3);
					if (num_of_comb == 3) Rotate(5, -3);
					if (num_of_comb == 4) Rotate(0, 3);
					if (num_of_comb == 5) Rotate(5, 3);
					if (num_of_comb == 6) Rotate(0, -3);
					if (num_of_comb == 7) Rotate(3, 3);
					if (num_of_comb == 8) Rotate(5, 3);
					if (num_of_comb == 9) {
						start = 0;
						num_of_comb = 0;
						og = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (ob == 1) {
					if (num_of_comb == 0) Rotate(2, 3);
					if (num_of_comb == 1) Rotate(0, 3);
					if (num_of_comb == 2) Rotate(5, -3);
					if (num_of_comb == 3) Rotate(2, 3);
					if (num_of_comb == 4) Rotate(0, 3);
					if (num_of_comb == 5) Rotate(2, -3);
					if (num_of_comb == 6) Rotate(0, -3);
					if (num_of_comb == 7) Rotate(5, 3);
					if (num_of_comb == 8) Rotate(2, -3);
					if (num_of_comb == 9) {
						start = 0;
						num_of_comb = 0;
						ob = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (rb == 1) {
					if (num_of_comb == 0) Rotate(4, 3);
					if (num_of_comb == 1) Rotate(0, 3);
					if (num_of_comb == 2) Rotate(2, 3);
					if (num_of_comb == 3) Rotate(4, 3);
					if (num_of_comb == 4) Rotate(0, 3);
					if (num_of_comb == 5) Rotate(4, -3);
					if (num_of_comb == 6) Rotate(0, -3);
					if (num_of_comb == 7) Rotate(2, -3);
					if (num_of_comb == 8) Rotate(4, -3);
					if (num_of_comb == 9) {
						start = 0;
						num_of_comb = 0;
						rb = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
			}
			else if (combination == 39) {
				if (rg == 1) {
					if (num_of_comb == 0) Rotate(3, -3);
					if (num_of_comb == 1) Rotate(4, 3);
					if (num_of_comb == 2) Rotate(0, 3);
					if (num_of_comb == 3) Rotate(3, -3);
					if (num_of_comb == 4) Rotate(0, -3);
					if (num_of_comb == 5) Rotate(3, 3);
					if (num_of_comb == 6) Rotate(4, -3);
					if (num_of_comb == 7) Rotate(0, -3);
					if (num_of_comb == 8) Rotate(3, 3);
					if (num_of_comb == 9) {
						start = 0;
						num_of_comb = 0;
						rg = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (og == 1) {
					if (num_of_comb == 0) Rotate(5, -3);
					if (num_of_comb == 1) Rotate(3, -3);
					if (num_of_comb == 2) Rotate(0, 3);
					if (num_of_comb == 3) Rotate(5, -3);
					if (num_of_comb == 4) Rotate(0, -3);
					if (num_of_comb == 5) Rotate(5, 3);
					if (num_of_comb == 6) Rotate(3, 3);
					if (num_of_comb == 7) Rotate(0, -3);
					if (num_of_comb == 8) Rotate(5, 3);
					if (num_of_comb == 9) {
						start = 0;
						num_of_comb = 0;
						og = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (ob == 1) {
					if (num_of_comb == 0) Rotate(2, 3);
					if (num_of_comb == 1) Rotate(5, -3);
					if (num_of_comb == 2) Rotate(0, 3);
					if (num_of_comb == 3) Rotate(2, 3);
					if (num_of_comb == 4) Rotate(0, -3);
					if (num_of_comb == 5) Rotate(2, -3);
					if (num_of_comb == 6) Rotate(5, 3);
					if (num_of_comb == 7) Rotate(0, -3);
					if (num_of_comb == 8) Rotate(2, -3);
					if (num_of_comb == 9) {
						start = 0;
						num_of_comb = 0;
						ob = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (rb == 1) {
					if (num_of_comb == 0) Rotate(4, 3);
					if (num_of_comb == 1) Rotate(2, 3);
					if (num_of_comb == 2) Rotate(0, 3);
					if (num_of_comb == 3) Rotate(4, 3);
					if (num_of_comb == 4) Rotate(0, -3);
					if (num_of_comb == 5) Rotate(4, -3);
					if (num_of_comb == 6) Rotate(2, -3);
					if (num_of_comb == 7) Rotate(0, -3);
					if (num_of_comb == 8) Rotate(4, -3);
					if (num_of_comb == 9) {
						start = 0;
						num_of_comb = 0;
						rb = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
			}
			else if (combination == 40) {
				if (rg == 1) {
					if (num_of_comb == 0) Rotate(3, -3);
					if (num_of_comb == 1) Rotate(0, 3);
					if (num_of_comb == 2) Rotate(3, 3);
					if (num_of_comb == 3) Rotate(0, 3);
					if (num_of_comb == 4) Rotate(0, 3);
					if (num_of_comb == 5) Rotate(3, -3);
					if (num_of_comb == 6) Rotate(0, -3);
					if (num_of_comb == 7) Rotate(3, 3);
					if (num_of_comb == 8) Rotate(0, 3);
					if (num_of_comb == 9) Rotate(3, -3);
					if (num_of_comb == 10) Rotate(0, 3);
					if (num_of_comb == 11) Rotate(3, 3);
					if (num_of_comb == 12) {
						start = 0;
						num_of_comb = 0;
						rg = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (og == 1) {
					if (num_of_comb == 0) Rotate(5, -3);
					if (num_of_comb == 1) Rotate(0, 3);
					if (num_of_comb == 2) Rotate(5, 3);
					if (num_of_comb == 3) Rotate(0, 3);
					if (num_of_comb == 4) Rotate(0, 3);
					if (num_of_comb == 5) Rotate(5, -3);
					if (num_of_comb == 6) Rotate(0, -3);
					if (num_of_comb == 7) Rotate(5, 3);
					if (num_of_comb == 8) Rotate(0, 3);
					if (num_of_comb == 9) Rotate(5, -3);
					if (num_of_comb == 10) Rotate(0, 3);
					if (num_of_comb == 11) Rotate(5, 3);
					if (num_of_comb == 12) {
						start = 0;
						num_of_comb = 0;
						og = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (ob == 1) {
					if (num_of_comb == 0) Rotate(2, 3);
					if (num_of_comb == 1) Rotate(0, 3);
					if (num_of_comb == 2) Rotate(2, -3);
					if (num_of_comb == 3) Rotate(0, 3);
					if (num_of_comb == 4) Rotate(0, 3);
					if (num_of_comb == 5) Rotate(2, 3);
					if (num_of_comb == 6) Rotate(0, -3);
					if (num_of_comb == 7) Rotate(2, -3);
					if (num_of_comb == 8) Rotate(0, 3);
					if (num_of_comb == 9) Rotate(2, 3);
					if (num_of_comb == 10) Rotate(0, 3);
					if (num_of_comb == 11) Rotate(2, -3);
					if (num_of_comb == 12) {
						start = 0;
						num_of_comb = 0;
						ob = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (rb == 1) {
					if (num_of_comb == 0) Rotate(4, 3);
					if (num_of_comb == 1) Rotate(0, 3);
					if (num_of_comb == 2) Rotate(4, -3);
					if (num_of_comb == 3) Rotate(0, 3);
					if (num_of_comb == 4) Rotate(0, 3);
					if (num_of_comb == 5) Rotate(4, 3);
					if (num_of_comb == 6) Rotate(0, -3);
					if (num_of_comb == 7) Rotate(4, -3);
					if (num_of_comb == 8) Rotate(0, 3);
					if (num_of_comb == 9) Rotate(4, 3);
					if (num_of_comb == 10) Rotate(0, 3);
					if (num_of_comb == 11) Rotate(4, -3);
					if (num_of_comb == 12) {
						start = 0;
						num_of_comb = 0;
						rb = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
			}
			else if (combination == 41) {
				if (rg == 1) {
					if (num_of_comb == 0) Rotate(3, -3);
					if (num_of_comb == 1) Rotate(0, 3);
					if (num_of_comb == 2) Rotate(3, 3);
					if (num_of_comb == 3) Rotate(0, -3);
					if (num_of_comb == 4) Rotate(3, -3);
					if (num_of_comb == 5) Rotate(0, 3);
					if (num_of_comb == 6) Rotate(0, 3);
					if (num_of_comb == 7) Rotate(3, 3);
					if (num_of_comb == 8) Rotate(0, -3);
					if (num_of_comb == 9) Rotate(3, -3);
					if (num_of_comb == 10) Rotate(0, 3);
					if (num_of_comb == 11) Rotate(3, 3);
					if (num_of_comb == 12) {
						start = 0;
						num_of_comb = 0;
						rg = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (og == 1) {
					if (num_of_comb == 0) Rotate(5, -3);
					if (num_of_comb == 1) Rotate(0, 3);
					if (num_of_comb == 2) Rotate(5, 3);
					if (num_of_comb == 3) Rotate(0, -3);
					if (num_of_comb == 4) Rotate(5, -3);
					if (num_of_comb == 5) Rotate(0, 3);
					if (num_of_comb == 6) Rotate(0, 3);
					if (num_of_comb == 7) Rotate(5, 3);
					if (num_of_comb == 8) Rotate(0, -3);
					if (num_of_comb == 9) Rotate(5, -3);
					if (num_of_comb == 10) Rotate(0, 3);
					if (num_of_comb == 11) Rotate(5, 3);
					if (num_of_comb == 12) {
						start = 0;
						num_of_comb = 0;
						og = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (ob == 1) {
					if (num_of_comb == 0) Rotate(2, 3);
					if (num_of_comb == 1) Rotate(0, 3);
					if (num_of_comb == 2) Rotate(2, -3);
					if (num_of_comb == 3) Rotate(0, -3);
					if (num_of_comb == 4) Rotate(2, 3);
					if (num_of_comb == 5) Rotate(0, 3);
					if (num_of_comb == 6) Rotate(0, 3);
					if (num_of_comb == 7) Rotate(2, -3);
					if (num_of_comb == 8) Rotate(0, -3);
					if (num_of_comb == 9) Rotate(2, 3);
					if (num_of_comb == 10) Rotate(0, 3);
					if (num_of_comb == 11) Rotate(2, -3);
					if (num_of_comb == 12) {
						start = 0;
						num_of_comb = 0;
						ob = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
				else if (rb == 1) {
					if (num_of_comb == 0) Rotate(4, 3);
					if (num_of_comb == 1) Rotate(0, 3);
					if (num_of_comb == 2) Rotate(4, -3);
					if (num_of_comb == 3) Rotate(0, -3);
					if (num_of_comb == 4) Rotate(4, 3);
					if (num_of_comb == 5) Rotate(0, 3);
					if (num_of_comb == 6) Rotate(0, 3);
					if (num_of_comb == 7) Rotate(4, -3);
					if (num_of_comb == 8) Rotate(0, -3);
					if (num_of_comb == 9) Rotate(4, 3);
					if (num_of_comb == 10) Rotate(0, 3);
					if (num_of_comb == 11) Rotate(4, -3);
					if (num_of_comb == 12) {
						start = 0;
						num_of_comb = 0;
						rb = 0;
						lup = 0;
						rup = 0;
						ldown = 0;
						rdown = 0;
						wrong = 0;
					}
				}
			}
			lup = 0;
			rup = 0;
			ldown = 0;
			rdown = 0;
		}
		//постановка ребер
		else if (wrong == 4) {
			if (rg == 1) {
				if (up == 1) {
					if (num_of_comb == 0) {
						Rotate(0, 3);
					}
					if (num_of_comb == 1) {
						num_of_comb = 0;
						up = 0;
						wrong = 6;
						start = 0;
					}
				}
				else if (up == 2) {
					if (num_of_comb == 0) {
						Rotate(0, -3);
					}
					if (num_of_comb == 1) {
						Rotate(0, -3);
					}
					if (num_of_comb == 2) {
						num_of_comb = 0;
						up = 0;
						wrong = 6;
						start = 0;
					}
				}
			}
			else if (rg == 2) {
				if (up == 1){
					if (num_of_comb == 0){
						Rotate(0, -3);
					}
					if (num_of_comb == 1){
						num_of_comb = 0;
						up = 0;
						wrong = 6;
						start = 0;
					}
				}
				else if (up == 2){
					if (num_of_comb == 0) {
						Rotate(0, 3);
					}
					if (num_of_comb == 1) {
						Rotate(0, 3);
					}
					if (num_of_comb == 2) {
						num_of_comb = 0;
						up = 0;
						wrong = 6;
						start = 0;
					}
				}
			}
			else if (og == 1) {
				if (up == 1){
					if (num_of_comb == 0){
						Rotate(0, -3);
					}
					if (num_of_comb == 1){
						num_of_comb = 0;
						up = 0;
						wrong = 6;
						start = 0;
					}
				}
				else if (up == 2){
					if (num_of_comb == 0) {
						Rotate(0, 3);
					}
					if (num_of_comb == 1) {
						Rotate(0, 3);
					}
					if (num_of_comb == 2) {
						num_of_comb = 0;
						up = 0;
						wrong = 6;
						start = 0;
					}
				}
			}
			else if (og == 2) {
				if (up == 1){
					if (num_of_comb == 0){
						Rotate(0, 3);
					}
					if (num_of_comb == 1){
						num_of_comb = 0;
						up = 0;
						wrong = 6;
						start = 0;
					}
				}
				else if (up == 2){
					if (num_of_comb == 0) {
						Rotate(0, 3);
					}
					if (num_of_comb == 1) {
						Rotate(0, 3);
					}
					if (num_of_comb == 2) {
						num_of_comb = 0;
						up = 0;
						wrong = 6;
						start = 0;
					}
				}
			}
			else if (rb == 1) {
				if (up == 1){
					if (num_of_comb == 0){
						Rotate(0, -3);
					}
					if (num_of_comb == 1){
						num_of_comb = 0;
						up = 0;
						wrong = 6;
						start = 0;
					}
				}
				else if (up == 2){
					if (num_of_comb == 0) {
						Rotate(0, 3);
					}
					if (num_of_comb == 1) {
						Rotate(0, 3);
					}
					if (num_of_comb == 2) {
						num_of_comb = 0;
						up = 0;
						wrong = 6;
						start = 0;
					}
				}
			}
			else if (rb == 2) {
				if (up == 1){
					if (num_of_comb == 0){
						Rotate(0, 3);
					}
					if (num_of_comb == 1){
						num_of_comb = 0;
						up = 0;
						wrong = 6;
						start = 0;
					}
				}
				else if (up == 2){
					if (num_of_comb == 0) {
						Rotate(0, 3);
					}
					if (num_of_comb == 1) {
						Rotate(0, 3);
					}
					if (num_of_comb == 2) {
						num_of_comb = 0;
						up = 0;
						wrong = 6;
						start = 0;
					}
				}
			}
			else if (ob == 1) {
				if (up == 1){
					if (num_of_comb == 0){
						Rotate(0, 3);
					}
					if (num_of_comb == 1){
						num_of_comb = 0;
						up = 0;
						wrong = 6;
						start = 0;
					}
				}
				else if (up == 2){
					if (num_of_comb == 0) {
						Rotate(0, 3);
					}
					if (num_of_comb == 1) {
						Rotate(0, 3);
					}
					if (num_of_comb == 2) {
						num_of_comb = 0;
						up = 0;
						wrong = 6;
						start = 0;
					}
				}
			}
			else if (ob == 2) {
				if (up == 1){
					if (num_of_comb == 0){
						Rotate(0, -3);
					}
					if (num_of_comb == 1){
						num_of_comb = 0;
						up = 0;
						wrong = 6;
						start = 0;
					}
				}
				else if (up == 2){
					if (num_of_comb == 0) {
						Rotate(0, 3);
					}
					if (num_of_comb == 1) {
						Rotate(0, 3);
					}
					if (num_of_comb == 2) {
						num_of_comb = 0;
						up = 0;
						wrong = 6;
						start = 0;
					}
				}
			}
		}
	}
private:
	int _angle[4];
	bool ok[4][4][4];
	Small_Cube tmp[4][4];
};
Cube cube;
void display()
{
	glPushMatrix();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //
	glColor3f(1, 0, 0);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
	glTranslatef(0, 0, translateZ);
	glRotatef(xRot, 1, 0, 0);
	glRotatef(yRot, 0, 1, 0);
	glRotatef(zRot, 0, 0, 1);
	glTranslatef(CUBE_SIZE / -2, CUBE_SIZE / -2, CUBE_SIZE / -2);
	cube.draw();
	glPopMatrix();
	glutSwapBuffers();
}

void reshape(int w, int h)
{
	glViewport(0, 0, w, h); //размеры видового окна(окна в окне)
	// настройка прямоугольника отсечения
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	GLfloat aspect = (GLfloat)w / (GLfloat)h;
	gluPerspective(70, aspect, 1, 1000.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void initiate()
{
	glClearColor(0, 0, 0, 0); //цвет чистого экрана. чтобы установить цвет очистки буфера кадра (буфера, в котором собирается изображение для вывода на экран). Каждый раз, когда вызывается функция glClear() для очистки буфера кадра, он будет очищен до черного цвета с полной непрозрачностью.


	srand(time(0));


	float mat_specular[] = { 0.3, 0.3, 0.3, 0 }; //светло серый (прозрачный)
	float diffuseLight[] = { 0.2, 0.2, 0.2, 1 }; // темно серый
	float ambientLight[] = { 0.9, 0.9, 0.9, 1 }; // светло серый с полной непрозрачностью
	glShadeModel(GL_SMOOTH);


	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);

	glMateriali(GL_FRONT, GL_SHININESS, 128);

	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	cube.clear(CUBE_SIZE, c);

}

void specialKeys(int key, int, int)
{
	if (key == GLUT_KEY_DOWN)
	{
		xRot += 9;
		if (xRot >= 360)
			xRot -= 360;
		glutPostRedisplay();//перерисовка
	}

	if (key == GLUT_KEY_UP)
	{
		xRot -= 9;
		if (xRot <= 360)
			xRot += 360;
		glutPostRedisplay();
	}
	if (key == GLUT_KEY_LEFT) {
		zRot -= 9;
		if (zRot <= 360) {
			zRot += 360;
		}
		glutPostRedisplay();
	}
	if (key == GLUT_KEY_RIGHT) {
		zRot += 9;
		if (zRot >= 360) {
			zRot -= 360;
		}
		glutPostRedisplay();
	}

	if (key == GLUT_KEY_F4)
	{
		yRot += 9;
		if (yRot >= 360)
			yRot -= 360;
		glutPostRedisplay();
	}

	if (key == GLUT_KEY_F5)
	{
		yRot -= 9;
		if (yRot < 0)
			yRot += 360;
		glutPostRedisplay();
	}

	if (key == GLUT_KEY_HOME)
	{
		translateZ += 5;
		glutPostRedisplay();
	}

	if (key == GLUT_KEY_END)
	{
		translateZ -= 5;
		glutPostRedisplay();
	}

	if (key == GLUT_KEY_F1)
	{
		cube.clear(CUBE_SIZE, c); //cube reset
		glutPostRedisplay();
	}
}

void keys(unsigned char key, int, int)
{
	if (cube.current == -1 && key >= '0' && key < '6')
	{
		cube.Rotate(key - '0', 3); //side rotation 
		display();
	}

	if (key == 54)
	{
		timerOn = 1 - timerOn;
		if (timerOn == 1) {
			start_time = clock();
		}
	}

}



void timer(int)
{
	glutTimerFunc(TIMER, timer, 0);
	if (timerOn == 0)
	{
		if (cube.current == -1)
			keys(rand() % 6 + '0', 0, 0);
		else
			cube.Rotate(cube.current, 3);
	}
	if (timerOn == 1 && timeron == 0) {
		if (cube.current == -1) {

			cube.Auto();
			display();
		}
		else {
			if (cube.current != -1 && cube.rotate[cube.current] < 0) {
				cube.Rotate(cube.current, -3);
			}
			else if (cube.current != -1 && cube.rotate[cube.current] > 0) {
				cube.Rotate(cube.current, 3);
			}
		}
	}
	if (timerOn == 1 && timeron == 1) {
		if (cube.current == -1) {
			cube.F2L();
			display();
		}
		else {
			if (cube.current != -1 && cube.rotate[cube.current] < 0) {
				cube.Rotate(cube.current, -3);
			}
			else if (cube.current != -1 && cube.rotate[cube.current] > 0) {
				cube.Rotate(cube.current, 3);
			}
		}
	}
	if (timerOn == 1 && timeron == 2) {
		end_time = clock();
		printf("timer: %f  seconds", (float)(end_time - start_time) / CLOCKS_PER_SEC);
		exit(0);
	}

	display();
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); //двойная буферизация, буфер глубины и цвета
	glutInitWindowSize(800, 700); //размер окна
	glutInitWindowPosition(1, 1); //положение окна
	glutCreateWindow("ABC"); //создание окна по заданным параметрам
	initiate();
	glutDisplayFunc(display); //задает функцию рисования изображения
	glutReshapeFunc(reshape); //задает функцию обработки изменения размеров окна
	glutKeyboardFunc(keys); //задает функцию обработки нажатия клавиш клавиатуры (только тех, что генерируют ascii-символы)
	//glutMouseFunc(mouse); //задает функцию, обрабатывающую команды мыши
	glutTimerFunc(TIMER, timer, 0);
	//glutTimerFunc(TIMER, autosolve, 0);
	//задает функцию, вызываемую по таймеру
	glutSpecialFunc(specialKeys); //задает функцию обработки нажатия клавиш клавиатуры (тех, что не генерируют ascii-символы)
	glutMainLoop();

	return 0;
}

