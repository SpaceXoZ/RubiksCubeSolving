//#ifndef OPT
//#define OPT
//#include "OPTDRAW.h"
//
//enum colour {
//	white = 16777215, yellow = 16776960, blue = 255, green = 65280, red = 16711680, orange = 16729344
//};
//int num_of_comb = 0;
//int start = 0;
//class Cube
//{
//	double size;
//	unsigned int color[6];
//
//public:
//
//	int timeron = 0;
//	//int begin = 0;
//	int rg; 
//	int rb;
//	int og;
//	int ob;
//	int combination;
//	int current; //номер грани: 1 - верхняя(белая), 2 - передняя(синяя), 3 - задняя (зеленая), 4 - левая(красная), 5 - правая(оранжевая), 6 - нижняя(желтая).
//	int rotate[6];
//	Small_Cube a[3][3][3];
//	Cube()
//	{
//	}
//
//	Cube(double size, unsigned int* color)
//	{
//		clear(size, color);
//	}
//
//	void clear(double size, unsigned int* color)
//	{
//		memset(rotate, 0, sizeof(rotate));
//		this->size = size;
//		current = -1;
//
//		int i, j, k;
//		for (i = 0; i < 6; i++)
//			this->color[i] = color[i];
//
//		for (i = 0; i < 3; i++)
//			for (j = 0; j < 3; j++)
//				a[i][j][2].setColor(0, color[0]);// белый цвет для верхней грани (3 координата - ось z - на нас)  
//
//		for (i = 0; i < 3; i++)
//			for (j = 0; j < 3; j++)
//				a[i][j][0].setColor(1, color[1]);
//
//		for (k = 0; k < 3; k++)
//			for (j = 0; j < 3; j++)
//				a[j][0][k].setColor(2, color[2]);//синий цвет для передней грани (2 координата - ось игрик - вверх)
//
//		for (k = 0; k < 3; k++)
//			for (j = 0; j < 3; j++)
//				a[j][2][k].setColor(3, color[3]);
//
//		for (i = 0; i < 3; i++)
//			for (k = 0; k < 3; k++)
//				a[0][k][i].setColor(4, color[4]);//красный цвет для левой грани (1 координата - x - вправо)
//
//		for (i = 0; i < 3; i++)
//			for (k = 0; k < 3; k++)
//				a[2][k][i].setColor(5, color[5]);
//
//
//		for (i = 0; i < 3; i++)
//			for (j = 0; j < 3; j++)
//				for (k = 0; k < 3; k++)
//					a[i][j][k].size = (size / 3.0) * 0.97;
//		//a[2][2][2].color[2] = 90; обращение к задней грани правого ближнего верхнего кубика  
//	}
//
//	void draw()
//	{
//		const double K = 0.55;
//		glPushMatrix();
//		glColor3f(0, 0, 0);
//		glTranslatef(((1.0 - K) / 2) * size + K * size / 2, ((1.0 - K) / 2) * size + K * size / 2, ((1.0 - K) / 2) * size + K * size / 2);//7.5, 7.5, 7.5
//		glutSolidCube(size * K);//функция строит куб с центром в начале координат
//		glPopMatrix();
//
//		memset(ok, true, sizeof(ok));
//		if (current != -1)
//		{
//			glPushMatrix();
//			int i, j, k;
//
//			if (current == 0 || current == 1) //
//			{
//				k = (current & 1) * 2;
//				for (i = 0; i < 3; i++)
//					for (j = 0; j < 3; j++)
//						ok[i][j][k] = false;
//
//
//				glTranslated(size / 2, size / 2, 0); //сдвигаемся к центру 
//				glRotatef(rotate[current], 0, 0, 1);   //крутим грань с номером на угол
//				glTranslated(-size / 2, -size / 2, 0); //сдвигаемся обратно
//				for (i = 0; i < 3; i++)
//					for (j = 0; j < 3; j++)
//						a[i][j][k].draw(size / 3 * i, size / 3 * j, size / 3 * k); //отрисовка маленького кубика после поворота 
//			}
//			else if (current == 2 || current == 3)
//			{
//				j = (current & 1) * 2;
//				for (i = 0; i < 3; i++)
//					for (k = 0; k < 3; k++)
//						ok[i][j][k] = false;
//
//				glTranslated(size / 2, 0, size / 2);
//				glRotatef(rotate[current], 0, 1, 0);
//				glTranslated(-size / 2, 0, -size / 2);
//				for (i = 0; i < 3; i++)
//					for (k = 0; k < 3; k++)
//						a[i][j][k].draw(size / 3 * i, size / 3 * j, size / 3 * k);
//			}
//			else if (current == 4 || current == 5)
//			{
//				i = (current & 1) * 2;
//				for (j = 0; j < 3; j++)
//					for (k = 0; k < 3; k++)
//						ok[i][j][k] = false;
//
//				glTranslated(0, size / 2, size / 2);
//				glRotatef(rotate[current], 1, 0, 0);
//				glTranslated(0, -size / 2, -size / 2);
//				for (j = 0; j < 3; j++)
//					for (k = 0; k < 3; k++)
//						a[i][j][k].draw(size / 3 * i, size / 3 * j, size / 3 * k);
//			}
//			glPopMatrix();
//		}
//
//		for (int i = 0; i < 3; i++)
//			for (int j = 0; j < 3; j++)
//				for (int k = 0; k < 3; k++)
//					if (ok[i][j][k])
//						a[i][j][k].draw(size / 3 * i, size / 3 * j, size / 3 * k);
//	}
//
//public:
//	void rot90(int idx, int sign)
//	{
//		int i, j, k;
//		if (sign == -1)
//			sign = 3;
//		while (sign--)
//		{
//			if (idx == 0 || idx == 1)
//			{
//				k = (idx & 1) * 2;
//				for (i = 0; i < 3; i++)
//					for (j = 0; j < 3; j++)
//						tmp[j][2 - i] = a[i][j][k];
//				for (i = 0; i < 3; i++)
//					for (j = 0; j < 3; j++)
//						tmp[i][j].rotateZoX(), a[i][j][k] = tmp[i][j];
//			}
//			else if (idx == 2 || idx == 3)
//			{
//				j = (idx & 1) * 2;
//				for (i = 0; i < 3; i++)
//					for (k = 0; k < 3; k++)
//						tmp[k][2 - i] = a[i][j][k];
//				for (i = 0; i < 3; i++)
//					for (k = 0; k < 3; k++)
//						tmp[i][k].rotateXoY(), a[i][j][k] = tmp[i][k];
//			}
//			else if (idx == 4 || idx == 5)
//			{
//				i = (idx & 1) * 2;
//				for (j = 0; j < 3; j++)
//					for (k = 0; k < 3; k++)
//						tmp[k][2 - j] = a[i][j][k];
//				for (j = 0; j < 3; j++)
//					for (k = 0; k < 3; k++)
//						tmp[j][k].rotateZoY(), a[i][j][k] = tmp[j][k];
//			}
//		}
//	}
//
//	void Rotate(int idx, int angle)
//	{
//		if (current == -1 || current == idx)
//		{
//			rotate[idx] += angle;
//
//			if (rotate[idx] % 90 != 0)
//			{
//				current = idx;
//			}
//			else
//			{
//				if ((rotate[idx] < 0) ^ (current == 2 || current == 3))
//					rot90(idx, 1);
//				else
//					rot90(idx, -1);
//				rotate[idx] = 0;
//				current = -1;
//				num_of_comb++;
//			}
//		}
//	}
//	void Auto() {
//		//1) если на верхней грани 4  белых грани
//		if (a[0][1][2].color[0] == white && a[0][1][2].color[4] == red && a[1][2][2].color[0] == white && a[1][2][2].color[3] == green && a[2][1][2].color[0] == white && a[2][1][2].color[5] == orange && a[1][0][2].color[0] == white && a[1][0][2].color[2] == blue && a[0][2][2].color[3] == green && a[0][2][2].color[0] == white && a[0][2][2].color[4] == red && a[2][2][2].color[0] == white && a[2][2][2].color[3] == green && a[2][2][2].color[5] == orange && a[0][0][2].color[0] == white && a[0][0][2].color[4] == red && a[0][0][2].color[2] == blue && a[2][0][2].color[0] == white && a[2][0][2].color[2] == blue && a[2][0][2].color[5] == orange) {
//			timeron = 1;
//			return;
//		}
//		if (timeron == 0){
//			if (a[0][1][2].color[0] == white && a[1][0][2].color[0] == white && a[2][1][2].color[0] == white && a[1][2][2].color[0] == white) {
//				if (a[0][1][2].color[4] == blue && a[1][0][2].color[2] == green && a[2][1][2].color[5] == orange && a[1][2][2].color[3] == red) {//если стоит правильно только оранжевое ребро снизу зеленое а сверху красное
//					Rotate(1, 3); //поворот синей грани с зеленым цветом для лаьнейшей постановки на место
//				}
//				if (a[0][1][2].color[4] == blue && a[1][0][2].color[2] == red && a[2][1][2].color[5] == orange && a[1][2][2].color[3] == green) {
//					Rotate(2, 3);
//				}
//				if (a[0][1][2].color[4] == blue && a[1][0][2].color[2] == orange && a[2][1][2].color[5] == red && a[1][2][2].color[3] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[4] == green && a[1][0][2].color[2] == blue && a[2][1][2].color[5] == orange && a[1][2][2].color[3] == red) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][2].color[4] == red && a[1][0][2].color[2] == blue && a[2][1][2].color[5] == green && a[1][2][2].color[3] == orange) {
//					Rotate(3, 3);
//				}
//				if (a[0][1][2].color[4] == red && a[1][0][2].color[2] == green && a[2][1][2].color[5] == orange && a[1][2][2].color[3] == blue) {
//					Rotate(2, 3);
//				}
//				if (a[0][1][2].color[4] == green && a[1][0][2].color[2] == red && a[2][1][2].color[5] == blue && a[1][2][2].color[3] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[4] == green && a[1][0][2].color[2] == orange && a[2][1][2].color[5] == blue && a[1][2][2].color[3] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[4] == orange && a[1][0][2].color[2] == red && a[2][1][2].color[5] == blue && a[1][2][2].color[3] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[4] == green && a[1][0][2].color[2] == orange && a[2][1][2].color[5] == red && a[1][2][2].color[3] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[4] == orange && a[1][0][2].color[2] == green && a[2][1][2].color[5] == blue && a[1][2][2].color[3] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[4] == red && a[1][0][2].color[2] == orange && a[2][1][2].color[5] == green && a[1][2][2].color[3] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[4] == blue && a[1][0][2].color[2] == orange && a[2][1][2].color[5] == green && a[1][2][2].color[3] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[4] == red && a[1][0][2].color[2] == orange && a[2][1][2].color[5] == blue && a[1][2][2].color[3] == green) {
//					Rotate(2, -3);
//				}
//				if (a[0][1][2].color[4] == green && a[1][0][2].color[2] == red && a[2][1][2].color[5] == orange && a[1][2][2].color[3] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[4] == blue && a[1][0][2].color[2] == green && a[2][1][2].color[5] == red && a[1][2][2].color[3] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[4] == orange && a[1][0][2].color[2] == blue && a[2][1][2].color[5] == green && a[1][2][2].color[3] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[4] == blue && a[1][0][2].color[2] == red && a[2][1][2].color[5] == green && a[1][2][2].color[3] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[4] == green && a[1][0][2].color[2] == blue && a[2][1][2].color[5] == red && a[1][2][2].color[3] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[4] == red && a[1][0][2].color[2] == green && a[2][1][2].color[5] == blue && a[1][2][2].color[3] == orange) {
//					Rotate(3, 3);
//				}
//				if (a[0][1][2].color[4] == orange && a[1][0][2].color[2] == blue && a[2][1][2].color[5] == red && a[1][2][2].color[3] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[4] == orange && a[1][0][2].color[2] == green && a[2][1][2].color[5] == red && a[1][2][2].color[3] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[4] == orange && a[1][0][2].color[2] == red && a[2][1][2].color[5] == green && a[1][2][2].color[3] == blue) {
//					Rotate(1, 3);
//				}
//			}
//
//
//			//если 3 грани белых (кроме нижней)
//			if (a[0][1][2].color[0] == white && a[1][0][2].color[0] != white && a[2][1][2].color[0] == white && a[1][2][2].color[0] == white) {
//				if (a[0][1][2].color[4] == red && a[1][2][2].color[3] == blue && a[2][1][2].color[5] == orange) {
//					if (a[2][0][1].color[5] == white && a[2][0][1].color[2] == green) {//если синяя грань повенула зеленый цвет
//						Rotate(1, 3); //поворот зеленой грани, чтобы не потерять красный цвет 
//					}
//					if (a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[0][1][2].color[4] == blue && a[1][2][2].color[3] == green && a[2][1][2].color[5] == orange) {
//					if (a[2][0][1].color[5] == white && a[2][0][1].color[2] == red) {
//						Rotate(1, 3);
//					}
//					if (a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[0][1][2].color[4] == red && a[1][2][2].color[3] == green && a[2][1][2].color[5] == orange) {
//					if (a[0][0][1].color[2] == blue && a[0][0][1].color[4] == white) {
//						Rotate(2, 3);
//					}
//					if (a[2][0][1].color[2] == white && a[2][0][1].color[5] == blue) {
//						Rotate(1, 3);
//					}
//					/*if (a[2][0][1].color[2] == blue && a[2][0][1].color[5] == white) {
//						Rotate(2, -3);
//					}*/
//					//когда синий кубик перевернут синим вверх
//					if (a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) {
//						Rotate(2, 3);
//					}
//				}
//				if (a[0][1][2].color[4] == orange && a[1][2][2].color[3] == green && a[2][1][2].color[5] == red) {
//					if (a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) {
//						Rotate(2, 3);
//					}
//					if (a[2][0][1].color[2] == white && a[2][0][1].color[5] == blue) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[0][1][2].color[4] == green && a[1][2][2].color[3] == red && a[2][1][2].color[5] == orange) {
//					if (a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) {
//						Rotate(2, 3);
//					}
//					if (a[2][0][1].color[2] == white && a[2][0][1].color[5] == blue) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[0][1][2].color[4] == red && a[1][2][2].color[3] == orange && a[2][1][2].color[5] == green) {
//					if (a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) {
//						Rotate(2, 3);
//					}
//					if (a[2][0][1].color[2] == white && a[2][0][1].color[5] == blue) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[0][1][2].color[4] == orange && a[1][2][2].color[3] == red && a[2][1][2].color[5] == green) {
//					if (a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) {
//						Rotate(2, 3);
//					}
//					if (a[2][0][1].color[2] == white && a[2][0][1].color[5] == blue) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[0][1][2].color[4] == green && a[1][2][2].color[3] == orange && a[2][1][2].color[5] == red) {
//					if (a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) {
//						Rotate(2, 3);
//					}
//					if (a[2][0][1].color[2] == white && a[2][0][1].color[5] == blue) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[0][1][2].color[4] == blue && a[1][2][2].color[3] == red && a[2][1][2].color[5] == green) {
//					if (a[2][0][1].color[2] == orange && a[2][0][1].color[5] == white) {
//						Rotate(2, -3);
//					}
//					if (a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[0][1][2].color[4] == green && a[1][2][2].color[3] == red && a[2][1][2].color[5] == blue) {
//					if (a[2][0][1].color[2] == white && a[2][0][1].color[5] == orange) {
//						Rotate(1, 3);
//					}
//					if (a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) {
//						Rotate(1, 3);
//					}
//					if (a[2][0][1].color[2] == orange && a[2][0][1].color[5] == white) {
//						Rotate(2, -3);
//					}
//				}
//				if (a[0][1][2].color[4] == blue && a[1][2][2].color[3] == green && a[2][1][2].color[5] == red) {
//					if (a[2][0][1].color[2] == orange && a[2][0][1].color[5] == white) {
//						Rotate(2, -3);
//					}
//					if (a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[0][1][2].color[4] == red && a[1][2][2].color[3] == blue && a[2][1][2].color[5] == green) {
//					if (a[2][0][1].color[2] == orange && a[2][0][1].color[5] == white) {
//						Rotate(2, -3);
//					}
//					if (a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[0][1][2].color[4] == red && a[1][2][2].color[3] == green && a[2][1][2].color[5] == blue) {
//					if (a[2][0][1].color[2] == orange && a[2][0][1].color[5] == white) {
//						Rotate(2, -3);
//					}
//					if (a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) {
//						Rotate(1, 3);
//					}
//					if (a[0][0][1].color[2] == orange && a[0][0][1].color[4] == white) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[0][1][2].color[4] == green && a[1][2][2].color[3] == blue && a[2][1][2].color[5] == red) {
//					if (a[2][0][1].color[2] == orange && a[2][0][1].color[5] == white) {
//						Rotate(2, -3);
//					}
//					if (a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[0][1][2].color[4] == orange && a[1][2][2].color[3] == blue && a[2][1][2].color[5] == red) {
//					if (a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[0][1][2].color[4] == blue && a[1][2][2].color[3] == orange && a[2][1][2].color[5] == red) {
//					if (a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[0][1][2].color[4] == orange && a[1][2][2].color[3] == red && a[2][1][2].color[5] == blue) {
//					if (a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[0][1][2].color[4] == red && a[1][2][2].color[3] == orange && a[2][1][2].color[5] == blue) {
//					if (a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[0][1][2].color[4] == blue && a[1][2][2].color[3] == red && a[2][1][2].color[5] == orange) {
//					if (a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) {
//						Rotate(1, -3);
//					}
//				}
//				//Red
//				if (a[0][1][2].color[4] == green && a[1][2][2].color[3] == orange && a[2][1][2].color[5] == blue) {
//					if (a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[0][1][2].color[4] == orange && a[1][2][2].color[3] == green && a[2][1][2].color[5] == blue) {
//					if (a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[0][1][2].color[4] == green && a[1][2][2].color[3] == blue && a[2][1][2].color[5] == orange) {
//					if (a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[0][1][2].color[4] == blue && a[1][2][2].color[3] == orange && a[2][1][2].color[5] == green) {
//					if (a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[0][1][2].color[4] == orange && a[1][2][2].color[3] == blue && a[2][1][2].color[5] == green) {
//					if (a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) {
//						Rotate(1, -3);
//					}
//				}
//			}
//			//три белых (кроме правой)
//			if (a[0][1][2].color[0] == white && a[1][0][2].color[0] == white && a[2][1][2].color[0] != white && a[1][2][2].color[0] == white) {
//				if (a[0][1][2].color[4] == blue && a[1][0][2].color[2] == red && a[1][2][2].color[3] == orange) {
//					if (a[2][0][1].color[5] == white && a[2][0][1].color[2] == green) {
//						Rotate(1, 3);
//					}
//					if (a[2][2][1].color[5] == green && a[2][2][1].color[3] == white) {
//						Rotate(3, 3);
//					}
//					if (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[0][1][2].color[4] == green && a[1][0][2].color[2] == blue && a[1][2][2].color[3] == orange) {
//					if (a[2][0][1].color[5] == white && a[2][0][1].color[2] == red) {
//						Rotate(2, -3);
//					}
//					if (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white) {
//						Rotate(5, 3);
//					}
//					if (a[2][0][1].color[2] == white && a[2][0][1].color[5] == orange) {
//						Rotate(1, -3);
//					}
//					if (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[0][1][2].color[4] == green && a[1][0][2].color[2] == red && a[1][2][2].color[3] == orange) {
//					if (a[0][0][1].color[4] == white && a[0][0][1].color[2] == blue) {
//						Rotate(1, -3);
//					}
//					if (a[2][0][1].color[2] == white && a[2][0][1].color[5] == blue) {
//						Rotate(5, -3);
//					}
//					if (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white) {
//						Rotate(1, -3);
//					}
//					if (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white) {
//						Rotate(5, 3);
//					}
//					if (a[2][0][1].color[2] == orange && a[2][0][1].color[5] == white) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[0][1][2].color[4] == blue && a[1][0][2].color[2] == orange && a[1][2][2].color[3] == green) {
//					if (a[0][2][1].color[4] == white && a[0][2][1].color[3] == red) {
//						Rotate(3, 3);
//					}
//					if (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[0][1][2].color[4] == blue && a[1][0][2].color[2] == orange && a[1][2][2].color[3] == red) {
//					if (a[2][2][1].color[5] == white && a[2][2][1].color[3] == green) {
//						Rotate(1, 3);
//					}
//					if (a[2][2][1].color[5] == green && a[2][2][1].color[3] == white) {
//						Rotate(5, 3);
//					}
//					if (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[0][1][2].color[4] == green && a[1][0][2].color[2] == orange && a[1][2][2].color[3] == red) {
//					if (a[2][0][1].color[2] == white && a[2][0][1].color[5] == blue) {
//						Rotate(5, -3);
//					}
//					if (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white) {
//						Rotate(1, -3);
//					}
//				}
//
//				if (a[0][1][2].color[4] == red && a[1][0][2].color[2] == green && a[1][2][2].color[3] == orange) {
//					if (a[2][0][1].color[2] == white && a[2][0][1].color[5] == blue) {
//						Rotate(5, -3);
//					}
//					if (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[0][1][2].color[4] == orange && a[1][0][2].color[2] == red && a[1][2][2].color[3] == green) {
//					if (a[2][0][1].color[2] == white && a[2][0][1].color[5] == blue) {
//						Rotate(5, -3);
//					}
//					if (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[0][1][2].color[4] == orange && a[1][0][2].color[2] == green && a[1][2][2].color[3] == red) {
//					if (a[2][0][1].color[2] == white && a[2][0][1].color[5] == blue) {
//						Rotate(5, -3);
//					}
//					if (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[0][1][2].color[4] == red && a[1][0][2].color[2] == orange && a[1][2][2].color[3] == green) {
//					if (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white) {
//						Rotate(1, -3);
//					}
//					if (a[2][0][1].color[2] == white && a[2][0][1].color[5] == blue) {
//						Rotate(5, -3);
//					}
//				}
//				if (a[0][1][2].color[4] == red && a[1][0][2].color[2] == blue && a[1][2][2].color[3] == green) {
//					if (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white) {
//						Rotate(5, 3);
//					}
//					/*if (a[2][0][1].color[2] == white && a[2][0][1].color[5] == orange) {
//						Rotate(1, -3);
//					}*/
//					if (a[2][0][1].color[2] == orange && a[2][0][1].color[5] == white) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[0][1][2].color[4] == red && a[1][0][2].color[2] == green && a[1][2][2].color[3] == blue) {
//					if (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white) {
//						Rotate(5, 3);
//					}
//					if (a[2][0][1].color[2] == white && a[2][0][1].color[5] == orange) {
//						Rotate(1, -3);
//					}
//					if (a[2][0][1].color[2] == orange && a[2][0][1].color[5] == white) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[0][1][2].color[4] == blue && a[1][0][2].color[2] == red && a[1][2][2].color[3] == green) {
//					if (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white) {
//						Rotate(5, 3);
//					}
//					if (a[2][0][1].color[2] == white && a[2][0][1].color[5] == orange) {
//						Rotate(1, -3);
//					}
//					if (a[2][0][1].color[2] == orange && a[2][0][1].color[5] == white) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[0][1][2].color[4] == green && a[1][0][2].color[2] == red && a[1][2][2].color[3] == blue) {
//					if (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white) {
//						Rotate(5, 3);
//					}
//					if (a[2][0][1].color[2] == white && a[2][0][1].color[5] == orange) {
//						Rotate(1, -3);
//					}
//					if (a[2][0][1].color[2] == orange && a[2][0][1].color[5] == white) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[0][1][2].color[4] == blue && a[1][0][2].color[2] == green && a[1][2][2].color[3] == red) {
//					if (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white) {
//						Rotate(5, 3);
//					}
//					if (a[2][0][1].color[2] == white && a[2][0][1].color[5] == orange) {
//						Rotate(1, -3);
//					}
//					if (a[2][0][1].color[2] == orange && a[2][0][1].color[5] == white) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[0][1][2].color[4] == green && a[1][0][2].color[2] == blue && a[1][2][2].color[3] == red) {
//					if (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white) {
//						Rotate(5, 3);
//					}
//					if (a[2][0][1].color[2] == orange && a[2][0][1].color[5] == white) {
//						Rotate(1, -3);
//					}
//					if (a[2][0][1].color[2] == white && a[2][0][1].color[5] == orange) {
//						Rotate(5, -3);
//					}
//				}
//				if (a[0][1][2].color[4] == orange && a[1][0][2].color[2] == blue && a[1][2][2].color[3] == red) {
//					if (a[2][2][1].color[5] == green && a[2][2][1].color[3] == white) {
//						Rotate(5, 3);
//					}
//					if (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[0][1][2].color[4] == red && a[1][0][2].color[2] == orange && a[1][2][2].color[3] == blue) {
//					if (a[2][2][1].color[5] == green && a[2][2][1].color[3] == white) {
//						Rotate(5, 3);
//					}
//					if (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[0][1][2].color[4] == orange && a[1][0][2].color[2] == red && a[1][2][2].color[3] == blue) {
//					if (a[2][2][1].color[5] == green && a[2][2][1].color[3] == white) {
//						Rotate(5, 3);
//					}
//					if (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[0][1][2].color[4] == red && a[1][0][2].color[2] == blue && a[1][2][2].color[3] == orange) {
//					if (a[2][2][1].color[5] == green && a[2][2][1].color[3] == white) {
//						Rotate(5, 3);
//					}
//					if (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white) {
//						Rotate(1, 3);
//					}
//				}
//				//Red
//				if (a[0][1][2].color[4] == orange && a[1][0][2].color[2] == green && a[1][2][2].color[3] == blue) {
//					if (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[0][1][2].color[4] == green && a[1][0][2].color[2] == orange && a[1][2][2].color[3] == blue) {
//					if (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[0][1][2].color[4] == blue && a[1][0][2].color[2] == green && a[1][2][2].color[3] == orange) {
//					if (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[0][1][2].color[4] == orange && a[1][0][2].color[2] == blue && a[1][2][2].color[3] == green) {
//					if (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white) {
//						Rotate(1, 3);
//					}
//				}
//			}
//			//три белых (кроме верхней)
//			if (a[0][1][2].color[0] == white && a[1][0][2].color[0] == white && a[2][1][2].color[0] == white && a[1][2][2].color[0] != white) {
//				if (a[0][1][2].color[4] == orange && a[1][0][2].color[2] == blue && a[2][1][2].color[5] == red) {
//					if (a[2][0][1].color[5] == white && a[2][0][1].color[2] == green) {
//						Rotate(2, -3);
//					}
//					if (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white) {
//						Rotate(3, 3);
//					}
//					if (a[2][2][1].color[5] == green && a[2][2][1].color[3] == white) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[0][1][2].color[4] == orange && a[1][0][2].color[2] == green && a[2][1][2].color[5] == red) {
//					if (a[0][0][1].color[2] == blue && a[0][0][1].color[4] == white) {
//						Rotate(1, 3);
//					}
//					if (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[0][1][2].color[4] == green && a[1][0][2].color[2] == blue && a[2][1][2].color[5] == orange) {
//					if (a[0][2][1].color[4] == white && a[0][2][1].color[3] == red) {
//						Rotate(1, -3);
//					}
//					if (a[0][2][1].color[3] == red && a[0][2][1].color[4] == white) {
//						Rotate(3, 3);
//					}
//				}
//				if (a[0][1][2].color[4] == red && a[1][0][2].color[2] == blue && a[2][1][2].color[5] == orange) {
//					if (a[2][2][1].color[5] == white && a[2][2][1].color[3] == green) {
//						Rotate(3, -3);
//					}
//					//if (a[0][2][1].color[4] == white && a[0][2][1].color[3] == green && (a[0][2][0].color[1] != white || a[0][2][0].color[4] != white || a[0][2][0].color[3] != white) && (a[0][2][0].color[1] != white || a[0][2][0].color[1] != white || a[0][2][0].color[1] != white)) {
//						//Rotate(3, 3);
//					//}
//					if (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white) {
//						Rotate(3, 3);
//					}
//					if (a[2][2][1].color[5] == green && a[2][2][1].color[3] == white) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[0][1][2].color[4] == red && a[1][0][2].color[2] == blue && a[2][1][2].color[5] == green) {
//					if (a[2][2][1].color[5] == white && a[2][2][1].color[3] == orange) {
//						Rotate(1, 3);
//					}
//					if (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[0][1][2].color[4] == red && a[1][0][2].color[2] == green && a[2][1][2].color[5] == orange) {
//					if (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white) {
//						Rotate(1, -3);
//					}
//					if (a[0][2][1].color[3] == blue && a[0][2][1].color[4] == white) {
//						Rotate(3, 3);
//					}
//				}
//				if (a[0][1][2].color[4] == green && a[1][0][2].color[2] == orange && a[2][1][2].color[5] == red) {
//					if (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[0][1][2].color[4] == orange && a[1][0][2].color[2] == red && a[2][1][2].color[5] == green) {
//					if (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[0][1][2].color[4] == green && a[1][0][2].color[2] == red && a[2][1][2].color[5] == orange) {
//					if (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[0][1][2].color[4] == red && a[1][0][2].color[2] == orange && a[2][1][2].color[5] == green) {
//					if (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[0][1][2].color[4] == green && a[1][0][2].color[2] == red && a[2][1][2].color[5] == blue) {
//					if (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[0][1][2].color[4] == blue && a[1][0][2].color[2] == red && a[2][1][2].color[5] == green) {
//					if (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[0][1][2].color[4] == red && a[1][0][2].color[2] == green && a[2][1][2].color[5] == blue) {
//					if (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white) {
//						Rotate(1, -3);
//					}
//					if (a[2][2][1].color[3] == orange && a[2][2][1].color[5] == white) {
//						Rotate(1, 3);
//					}
//
//				}
//				if (a[0][1][2].color[4] == green && a[1][0][2].color[2] == blue && a[2][1][2].color[5] == red) {
//					if (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[0][1][2].color[4] == blue && a[1][0][2].color[2] == green && a[2][1][2].color[5] == red) {
//					if (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[0][1][2].color[4] == red && a[1][0][2].color[2] == orange && a[2][1][2].color[5] == blue) {
//					if (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white) {
//						Rotate(3, 3);
//					}
//					if (a[2][2][1].color[5] == green && a[2][2][1].color[3] == white) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[0][1][2].color[4] == blue && a[1][0][2].color[2] == red && a[2][1][2].color[5] == orange) {
//					if (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white) {
//						Rotate(3, 3);
//					}
//					if (a[2][2][1].color[5] == green && a[2][2][1].color[3] == white) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[0][1][2].color[4] == blue && a[1][0][2].color[2] == orange && a[2][1][2].color[5] == red) {
//					if (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white) {
//						Rotate(3, 3);
//					}
//					if (a[2][2][1].color[5] == green && a[2][2][1].color[3] == white) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[0][1][2].color[4] == orange && a[1][0][2].color[2] == red && a[2][1][2].color[5] == blue) {
//					if (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white) {
//						Rotate(3, 3);
//					}
//					if (a[2][2][1].color[5] == green && a[2][2][1].color[3] == white) {
//						Rotate(1, -3);
//					}
//				}
//				//Red
//				if (a[0][1][2].color[4] == blue && a[1][0][2].color[2] == orange && a[2][1][2].color[5] == green) {
//					if (a[0][2][1].color[3] == red && a[0][2][1].color[4] == white) {
//						Rotate(3, 3);
//					}
//					if (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[0][1][2].color[4] == blue && a[1][0][2].color[2] == green && a[2][1][2].color[5] == orange) {
//					if (a[0][2][1].color[3] == red && a[0][2][1].color[4] == white) {
//						Rotate(3, 3);
//					}
//					if (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[0][1][2].color[4] == orange && a[1][0][2].color[2] == blue && a[2][1][2].color[5] == green) {
//					if (a[0][2][1].color[3] == red && a[0][2][1].color[4] == white) {
//						Rotate(3, 3);
//					}
//					if (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[0][1][2].color[4] == green && a[1][0][2].color[2] == orange && a[2][1][2].color[5] == blue) {
//					if (a[0][2][1].color[3] == red && a[0][2][1].color[4] == white) {
//						Rotate(3, 3);
//					}
//					if (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[0][1][2].color[4] == orange && a[1][0][2].color[2] == green && a[2][1][2].color[5] == blue) {
//					if (a[0][2][1].color[3] == red && a[0][2][1].color[4] == white) {
//						Rotate(3, 3);
//					}
//					if (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white) {
//						Rotate(1, 3);
//					}
//				}
//			}
//			//три белых (кроме левой)
//			if (a[0][1][2].color[0] != white && a[1][0][2].color[0] == white && a[2][1][2].color[0] == white && a[1][2][2].color[0] == white) {
//				if (a[1][0][2].color[2] == orange && a[2][1][2].color[5] == green && a[1][2][2].color[3] == red) {
//					if (a[0][0][1].color[2] == blue && a[0][0][1].color[4] == white) {
//						Rotate(1, 3);
//					}
//					if (a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) {
//						Rotate(1, 3);
//					}
//					if (a[2][0][1].color[2] == blue && a[2][0][1].color[5] == white) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[1][0][2].color[2] == red && a[2][1][2].color[5] == blue && a[1][2][2].color[3] == green) {
//					if (a[2][2][1].color[5] == white && a[2][2][1].color[3] == orange) {
//						Rotate(3, -3);
//					}
//					if (a[0][1][2].color[4] == white && a[0][1][2].color[0] == orange) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[1][0][2].color[2] == red && a[2][1][2].color[5] == blue && a[1][2][2].color[3] == orange) {
//					if (a[0][2][1].color[4] == white && a[0][2][1].color[3] == green) {
//						Rotate(1, -3);
//					}
//					if (a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[1][0][2].color[2] == red && a[2][1][2].color[5] == green && a[1][2][2].color[3] == orange) {
//					if (a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) {
//						Rotate(1, 3);
//					}
//					if (a[0][2][1].color[3] == blue && a[0][2][1].color[4] == white) {
//						Rotate(1, -3);
//					}
//				}if (a[1][0][2].color[2] == green && a[2][1][2].color[5] == orange && a[1][2][2].color[3] == red) {
//					if (a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[1][0][2].color[2] == orange && a[2][1][2].color[5] == red && a[1][2][2].color[3] == green) {
//					if (a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[1][0][2].color[2] == red && a[2][1][2].color[5] == orange && a[1][2][2].color[3] == green) {
//					if (a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[1][0][2].color[2] == green && a[2][1][2].color[5] == red && a[1][2][2].color[3] == orange) {
//					if (a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[1][0][2].color[2] == green && a[2][1][2].color[5] == red && a[1][2][2].color[3] == blue) {
//					if (a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[1][0][2].color[2] == blue && a[2][1][2].color[5] == red && a[1][2][2].color[3] == green) {
//					if (a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[1][0][2].color[2] == red && a[2][1][2].color[5] == green && a[1][2][2].color[3] == blue) {
//					if (a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) {
//						Rotate(1, 3);
//					}
//					if (a[2][2][1].color[3] == orange && a[2][2][1].color[5] == white) {
//						Rotate(3, -3);
//					}
//				}
//				if (a[1][0][2].color[2] == green && a[2][1][2].color[5] == blue && a[1][2][2].color[3] == red) {
//					if (a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[1][0][2].color[2] == blue && a[2][1][2].color[5] == green && a[1][2][2].color[3] == red) {
//					if (a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) {
//						Rotate(1, 3);
//					}
//					if (a[0][0][1].color[2] == orange && a[0][0][1].color[4] == white) {
//						Rotate(2, 3);
//					}
//				}
//				if (a[1][0][2].color[2] == orange && a[2][1][2].color[5] == blue && a[1][2][2].color[3] == red) {
//					if (a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[1][0][2].color[2] == red && a[2][1][2].color[5] == orange && a[1][2][2].color[3] == blue) {
//					if (a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[1][0][2].color[2] == blue && a[2][1][2].color[5] == red && a[1][2][2].color[3] == orange) {
//					if (a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[1][0][2].color[2] == blue && a[2][1][2].color[5] == orange && a[1][2][2].color[3] == red) {
//					if (a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[1][0][2].color[2] == orange && a[2][1][2].color[5] == red && a[1][2][2].color[3] == blue) {
//					if (a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) {
//						Rotate(1, -3);
//					}
//				}
//				// Red
//				if (a[1][0][2].color[2] == blue && a[2][1][2].color[5] == orange && a[1][2][2].color[3] == green) {
//					if (a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) {
//						Rotate(4, -3);
//					}
//					if (a[0][2][1].color[3] == red && a[0][2][1].color[4] == white) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[1][0][2].color[2] == blue && a[2][1][2].color[5] == green && a[1][2][2].color[3] == orange) {
//					if (a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) {
//						Rotate(4, -3);
//					}
//					if (a[0][2][1].color[3] == red && a[0][2][1].color[4] == white) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[1][0][2].color[2] == orange && a[2][1][2].color[5] == blue && a[1][2][2].color[3] == green) {
//					if (a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) {
//						Rotate(4, -3);
//					}
//					if (a[0][2][1].color[3] == red && a[0][2][1].color[4] == white) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[1][0][2].color[2] == green && a[2][1][2].color[5] == orange && a[1][2][2].color[3] == blue) {
//					if (a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) {
//						Rotate(4, -3);
//					}
//					if (a[0][2][1].color[3] == red && a[0][2][1].color[4] == white) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[1][0][2].color[2] == green && a[2][1][2].color[5] == blue && a[1][2][2].color[3] == orange) {
//					if (a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) {
//						Rotate(4, -3);
//					}
//					if (a[0][2][1].color[3] == red && a[0][2][1].color[4] == white) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[1][0][2].color[2] == orange && a[2][1][2].color[5] == green && a[1][2][2].color[3] == blue) {
//					if (a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) {
//						Rotate(4, -3);
//					}
//					if (a[0][2][1].color[3] == red && a[0][2][1].color[4] == white) {
//						Rotate(1, -3);
//					}
//				}
//			}
//			//если 2 боковых грани белые
//			if (a[0][1][2].color[0] == white && a[1][0][2].color[0] != white && a[2][1][2].color[0] == white && a[1][2][2].color[0] != white) {
//				/*if (a[0][1][2].color[4] == blue && a[2][1][2].color[5] == orange) {
//					if (a[2][2][1].color[5] == white && a[2][2][1].color[3] == red) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[0][1][2].color[4] == orange && a[2][1][2].color[5] == blue) {
//					if (a[2][0][1].color[2] == green && a[2][0][1].color[5] == white) {
//						Rotate(2, -3);
//					}
//				}*/
//				if (a[0][1][2].color[4] == red && a[2][1][2].color[5] == orange) {
//					if ((a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == blue) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
//						Rotate(1, 3);
//					}
//					if ((a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == green) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[0][1][2].color[4] == red && a[2][1][2].color[5] == blue) {
//					if ((a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == orange) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
//						Rotate(1, 3);
//					}
//					if ((a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == green) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[0][1][2].color[4] == red && a[2][1][2].color[5] == green) {
//					if ((a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == orange) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
//						Rotate(1, 3);
//					}
//					if ((a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == blue) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[0][1][2].color[4] == orange && a[2][1][2].color[5] == red) {
//					if ((a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == blue) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
//						Rotate(1, 3);
//					}
//					if ((a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == green) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[0][1][2].color[4] == orange && a[2][1][2].color[5] == green) {
//					if ((a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == blue) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
//						Rotate(1, 3);
//					}
//					if ((a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == red) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[0][1][2].color[4] == orange && a[2][1][2].color[5] == blue) {
//					if ((a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == green) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
//						Rotate(1, 3);
//					}
//					if ((a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == red) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[0][1][2].color[4] == green && a[2][1][2].color[5] == blue) {
//					if ((a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == orange) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
//						Rotate(1, 3);
//					}
//					if ((a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == red) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[0][1][2].color[4] == green && a[2][1][2].color[5] == orange) {
//					if ((a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == blue) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
//						Rotate(1, 3);
//					}
//					if ((a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == red) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[0][1][2].color[4] == green && a[2][1][2].color[5] == red) {
//					if ((a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == blue) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
//						Rotate(1, 3);
//					}
//					if ((a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == orange) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[0][1][2].color[4] == blue && a[2][1][2].color[5] == green) {
//					if ((a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == orange) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
//						Rotate(1, 3);
//					}
//					if ((a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == red) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[0][1][2].color[4] == blue && a[2][1][2].color[5] == red) {
//					if ((a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == orange) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
//						Rotate(1, 3);
//					}
//					if ((a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == green) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[0][1][2].color[4] == blue && a[2][1][2].color[5] == orange) {
//					if ((a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == red) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
//						Rotate(1, 3);
//					}
//					if ((a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == green) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
//						Rotate(1, 3);
//					}
//				}
//			}//если верхняя и нижняя грани белые
//			if (a[0][1][2].color[0] != white && a[1][0][2].color[0] == white && a[2][1][2].color[0] != white && a[1][2][2].color[0] == white) {
//				/*if (a[1][0][2].color[2] == blue && a[1][2][2].color[3] == orange) {
//					if (a[2][0][1].color[5] == white && a[2][0][1].color[2] == green && a[2][2][1].color[5] == white && a[2][2][1].color[3] == red) {
//						Rotate(1, 3);
//					}
//				}*/
//				if (a[1][0][2].color[2] == red && a[1][2][2].color[3] == orange) {
//					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == blue)) {
//						Rotate(5, -3);
//					}
//					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == green)) {
//						Rotate(5, -3);
//					}
//					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[1][0][2].color[2] == red && a[1][2][2].color[3] == blue) {
//					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == orange)) {
//						Rotate(5, -3);
//					}
//					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == green)) {
//						Rotate(5, -3);
//					}
//					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[1][0][2].color[2] == red && a[1][2][2].color[3] == green) {
//					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == orange)) {
//						Rotate(5, -3);
//					}
//					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == blue)) {
//						Rotate(5, -3);
//					}
//					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[1][0][2].color[2] == green && a[1][2][2].color[3] == blue) {
//					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == orange)) {
//						Rotate(5, -3);
//					}
//					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == red)) {
//						Rotate(5, -3);
//					}
//					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[1][0][2].color[2] == green && a[1][2][2].color[3] == orange) {
//					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == blue)) {
//						Rotate(5, -3);
//					}
//					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == red)) {
//						Rotate(5, -3);
//					}
//					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[1][0][2].color[2] == green && a[1][2][2].color[3] == red) {
//					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == blue)) {
//						Rotate(5, -3);
//					}
//					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == orange)) {
//						Rotate(5, -3);
//					}
//					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[1][0][2].color[2] == blue && a[1][2][2].color[3] == green) {
//					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == orange)) {
//						Rotate(5, -3);
//					}
//					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == red)) {
//						Rotate(5, -3);
//					}
//					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[1][0][2].color[2] == blue && a[1][2][2].color[3] == red) {
//					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == orange)) {
//						Rotate(5, -3);
//					}
//					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == green)) {
//						Rotate(5, -3);
//					}
//					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[1][0][2].color[2] == blue && a[1][2][2].color[3] == orange) {
//					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == red)) {
//						Rotate(5, -3);
//					}
//					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == green)) {
//						Rotate(5, -3);
//					}
//					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[1][0][2].color[2] == orange && a[1][2][2].color[3] == red) {
//					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == blue)) {
//						Rotate(5, -3);
//					}
//					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == green)) {
//						Rotate(5, -3);
//					}
//					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[1][0][2].color[2] == orange && a[1][2][2].color[3] == blue) {
//					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == red)) {
//						Rotate(5, -3);
//					}
//					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == green)) {
//						Rotate(5, -3);
//					}
//					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[1][0][2].color[2] == orange && a[1][2][2].color[3] == green) {
//					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == blue)) {
//						Rotate(5, -3);
//					}
//					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == red)) {
//						Rotate(5, -3);
//					}
//					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//				}
//			}
//			//два белых (лево-ценнтр-верх)
//			if (a[0][1][2].color[0] == white && a[1][0][2].color[0] != white && a[1][2][2].color[0] == white && a[2][1][2].color[0] != white) {
//				if (a[0][1][2].color[4] == red && a[1][2][2].color[3] == green) {
//					if ((a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == orange) && (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white)) {
//						Rotate(1, 3);
//					}
//					if ((a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == blue) && (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white)) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[0][1][2].color[4] == red && a[1][2][2].color[3] == orange) {
//					if ((a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == green) && (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white)) {
//						Rotate(1, 3);
//					}
//					if ((a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == blue) && (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white)) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[0][1][2].color[4] == red && a[1][2][2].color[3] == blue) {
//					if ((a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == orange) && (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white)) {
//						Rotate(1, 3);
//					}
//					if ((a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == green) && (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white)) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[0][1][2].color[4] == green && a[1][2][2].color[3] == red) {
//					if ((a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == orange) && (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white)) {
//						Rotate(1, 3);
//					}
//					if ((a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == blue) && (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white)) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[0][1][2].color[4] == green && a[1][2][2].color[3] == blue) {
//					if ((a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == orange) && (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white)) {
//						Rotate(1, 3);
//					}
//					if ((a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == red) && (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white)) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[0][1][2].color[4] == green && a[1][2][2].color[3] == orange) {
//					if ((a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == blue) && (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white)) {
//						Rotate(1, 3);
//					}
//					if ((a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == red) && (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white)) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[0][1][2].color[4] == blue && a[1][2][2].color[3] == red) {
//					if ((a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == orange) && (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white)) {
//						Rotate(1, 3);
//					}
//					if ((a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == green) && (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white)) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[0][1][2].color[4] == blue && a[1][2][2].color[3] == green) {
//					if ((a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == orange) && (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white)) {
//						Rotate(1, 3);
//					}
//					if ((a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == red) && (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white)) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[0][1][2].color[4] == blue && a[1][2][2].color[3] == orange) {
//					if ((a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == green) && (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white)) {
//						Rotate(1, 3);
//					}
//					if ((a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == red) && (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white)) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[0][1][2].color[4] == orange && a[1][2][2].color[3] == red) {
//					if ((a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == green) && (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white)) {
//						Rotate(1, 3);
//					}
//					if ((a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == blue) && (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white)) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[0][1][2].color[4] == orange && a[1][2][2].color[3] == green) {
//					if ((a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == blue) && (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white)) {
//						Rotate(1, 3);
//					}
//					if ((a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == red) && (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white)) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[0][1][2].color[4] == orange && a[1][2][2].color[3] == blue) {
//					if ((a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == green) && (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white)) {
//						Rotate(1, 3);
//					}
//					if ((a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[2][0][1].color[2] == white && a[2][0][1].color[5] == red) && (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white)) {
//						Rotate(1, 3);
//					}
//				}
//			}
//			// два белых (лeво-центр-низ)
//			if (a[0][1][2].color[0] == white && a[1][0][2].color[0] == white && a[1][2][2].color[0] != white && a[2][1][2].color[0] != white) {
//				if (a[0][1][2].color[4] == green && a[1][0][2].color[2] == red) {
//					if ((a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == blue)) {
//						Rotate(5, -3);
//					}
//					if ((a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == orange)) {
//						Rotate(5, -3);
//					}
//					if ((a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//					if ((a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[0][1][2].color[4] == green && a[1][0][2].color[2] == blue) {
//					if ((a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == red)) {
//						Rotate(5, -3);
//					}
//					if ((a[1][2][2].color[0] == red && a[1][2][2].color[3] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == orange)) {
//						Rotate(5, -3);
//					}
//					if ((a[1][2][2].color[0] == red && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//					if ((a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[0][1][2].color[4] == green && a[1][0][2].color[2] == orange) {
//					if ((a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == red)) {
//						Rotate(5, -3);
//					}
//					if ((a[1][2][2].color[0] == red && a[1][2][2].color[3] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == blue)) {
//						Rotate(5, -3);
//					}
//					if ((a[1][2][2].color[0] == red && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//					if ((a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[0][1][2].color[4] == red && a[1][0][2].color[2] == green) {
//					if ((a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == blue)) {
//						Rotate(5, -3);
//					}
//					if ((a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == orange)) {
//						Rotate(5, -3);
//					}
//					if ((a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//					if ((a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[0][1][2].color[4] == red && a[1][0][2].color[2] == orange) {
//					if ((a[1][2][2].color[0] == green && a[1][2][2].color[3] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == blue)) {
//						Rotate(5, -3);
//					}
//					if ((a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == green)) {
//						Rotate(5, -3);
//					}
//					if ((a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//					if ((a[1][2][2].color[0] == green && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[0][1][2].color[4] == red && a[1][0][2].color[2] == blue) {
//					if ((a[1][2][2].color[0] == green && a[1][2][2].color[3] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == orange)) {
//						Rotate(5, -3);
//					}
//					if ((a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == green)) {
//						Rotate(5, -3);
//					}
//					if ((a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//					if ((a[1][2][2].color[0] == green && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[0][1][2].color[4] == blue && a[1][0][2].color[2] == red) {
//					if ((a[1][2][2].color[0] == green && a[1][2][2].color[3] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == orange)) {
//						Rotate(5, -3);
//					}
//					if ((a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == green)) {
//						Rotate(5, -3);
//					}
//					if ((a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//					if ((a[1][2][2].color[0] == green && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[0][1][2].color[4] == blue && a[1][0][2].color[2] == green) {
//					if ((a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == red)) {
//						Rotate(5, -3);
//					}
//					if ((a[1][2][2].color[0] == red && a[1][2][2].color[3] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == orange)) {
//						Rotate(5, -3);
//					}
//					if ((a[1][2][2].color[0] == red && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//					if ((a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[0][1][2].color[4] == blue && a[1][0][2].color[2] == orange) {
//					if ((a[1][2][2].color[0] == green && a[1][2][2].color[3] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == red)) {
//						Rotate(5, -3);
//					}
//					if ((a[1][2][2].color[0] == red && a[1][2][2].color[3] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == green)) {
//						Rotate(5, -3);
//					}
//					if ((a[1][2][2].color[0] == red && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//					if ((a[1][2][2].color[0] == green && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[0][1][2].color[4] == orange && a[1][0][2].color[2] == red) {
//					if ((a[1][2][2].color[0] == green && a[1][2][2].color[3] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == blue)) {
//						Rotate(5, -3);
//					}
//					if ((a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == green)) {
//						Rotate(5, -3);
//					}
//					if ((a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//					if ((a[1][2][2].color[0] == green && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[0][1][2].color[4] == orange && a[1][0][2].color[2] == green) {
//					if ((a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == red)) {
//						Rotate(5, -3);
//					}
//					if ((a[1][2][2].color[0] == red && a[1][2][2].color[3] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == blue)) {
//						Rotate(5, -3);
//					}
//					if ((a[1][2][2].color[0] == red && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//					if ((a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[0][1][2].color[4] == orange && a[1][0][2].color[2] == blue) {
//					if ((a[1][2][2].color[0] == green && a[1][2][2].color[3] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == red)) {
//						Rotate(5, -3);
//					}
//					if ((a[1][2][2].color[0] == red && a[1][2][2].color[3] == white) && (a[2][0][1].color[2] == white && a[2][0][1].color[5] == green)) {
//						Rotate(5, -3);
//					}
//					if ((a[1][2][2].color[0] == red && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//					if ((a[1][2][2].color[0] == green && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//				}
//			}
//			//2 белые (низ-центр-право)
//			if (a[0][1][2].color[0] != white && a[1][0][2].color[0] == white && a[1][2][2].color[0] != white && a[2][1][2].color[0] == white) {
//				if (a[1][0][2].color[2] == red && a[2][1][2].color[5] == green) {
//					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
//						Rotate(3, -3);
//					}
//					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == blue)) {
//						Rotate(1, 3);
//					}
//					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
//						Rotate(3, -3);
//					}
//					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == orange)) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[1][0][2].color[2] == red && a[2][1][2].color[5] == orange) {
//					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
//						Rotate(3, -3);
//					}
//					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == blue)) {
//						Rotate(1, 3);
//					}
//					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
//						Rotate(3, -3);
//					}
//					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == green)) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[1][0][2].color[2] == red && a[2][1][2].color[5] == blue) {
//					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
//						Rotate(3, -3);
//					}
//					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == orange)) {
//						Rotate(1, 3);
//					}
//					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
//						Rotate(3, -3);
//					}
//					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == green)) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[1][0][2].color[2] == green && a[2][1][2].color[5] == red) {
//					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
//						Rotate(3, -3);
//					}
//					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == blue)) {
//						Rotate(1, 3);
//					}
//					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
//						Rotate(3, -3);
//					}
//					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == orange)) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[1][0][2].color[2] == green && a[2][1][2].color[5] == blue) {
//					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
//						Rotate(3, -3);
//					}
//					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == red)) {
//						Rotate(1, 3);
//					}
//					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
//						Rotate(3, -3);
//					}
//					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == orange)) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[1][0][2].color[2] == green && a[2][1][2].color[5] == orange) {
//					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
//						Rotate(3, -3);
//					}
//					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == red)) {
//						Rotate(1, 3);
//					}
//					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
//						Rotate(3, -3);
//					}
//					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == blue)) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[1][0][2].color[2] == orange && a[2][1][2].color[5] == red) {
//					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
//						Rotate(3, -3);
//					}
//					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == blue)) {
//						Rotate(1, 3);
//					}
//					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
//						Rotate(3, -3);
//					}
//					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == green)) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[1][0][2].color[2] == orange && a[2][1][2].color[5] == green) {
//					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
//						Rotate(3, -3);
//					}
//					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == red)) {
//						Rotate(1, 3);
//					}
//					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
//						Rotate(3, -3);
//					}
//					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == blue)) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[1][0][2].color[2] == orange && a[2][1][2].color[5] == blue) {
//					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
//						Rotate(3, -3);
//					}
//					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == red)) {
//						Rotate(1, 3);
//					}
//					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
//						Rotate(3, -3);
//					}
//					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == green)) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[1][0][2].color[2] == blue && a[2][1][2].color[5] == red) {
//					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
//						Rotate(3, -3);
//					}
//					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == orange)) {
//						Rotate(1, 3);
//					}
//					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
//						Rotate(3, -3);
//					}
//					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == green)) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[1][0][2].color[2] == blue && a[2][1][2].color[5] == green) {
//					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
//						Rotate(3, -3);
//					}
//					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == red)) {
//						Rotate(1, 3);
//					}
//					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
//						Rotate(3, -3);
//					}
//					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == orange)) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[1][0][2].color[2] == blue && a[2][1][2].color[5] == orange) {
//					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
//						Rotate(3, -3);
//					}
//					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == red)) {
//						Rotate(1, 3);
//					}
//					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
//						Rotate(3, -3);
//					}
//					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == green)) {
//						Rotate(1, 3);
//					}
//				}
//			}
//			//2 белые (право-центр-верх)
//			if (a[0][1][2].color[0] != white && a[1][0][2].color[0] != white && a[1][2][2].color[0] == white && a[2][1][2].color[0] == white) {
//				if (a[1][2][2].color[3] == green && a[2][1][2].color[5] == red) {
//					if ((a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == blue)) {
//						Rotate(4, 3);
//					}
//					if ((a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == orange)) {
//						Rotate(4, 3);
//					}
//					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white)) {
//						Rotate(1, -3);
//					}
//					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white)) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[1][2][2].color[3] == green && a[2][1][2].color[5] == blue) {
//					if ((a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == red)) {
//						Rotate(4, 3);
//					}
//					if ((a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == orange)) {
//						Rotate(4, 3);
//					}
//					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white)) {
//						Rotate(1, -3);
//					}
//					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == red && a[1][0][2].color[2] == white)) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[1][2][2].color[3] == green && a[2][1][2].color[5] == orange) {
//					if ((a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == red)) {
//						Rotate(4, 3);
//					}
//					if ((a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == blue)) {
//						Rotate(4, 3);
//					}
//					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white)) {
//						Rotate(1, -3);
//					}
//					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == red && a[1][0][2].color[2] == white)) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[1][2][2].color[3] == red && a[2][1][2].color[5] == green) {
//					if ((a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == blue)) {
//						Rotate(4, 3);
//					}
//					if ((a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == orange)) {
//						Rotate(4, 3);
//					}
//					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white)) {
//						Rotate(1, -3);
//					}
//					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white)) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[1][2][2].color[3] == red && a[2][1][2].color[5] == orange) {
//					if ((a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == blue)) {
//						Rotate(4, 3);
//					}
//					if ((a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == green)) {
//						Rotate(4, 3);
//					}
//					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == green && a[1][0][2].color[2] == white)) {
//						Rotate(1, -3);
//					}
//					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white)) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[1][2][2].color[3] == red && a[2][1][2].color[5] == blue) {
//					if ((a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == orange)) {
//						Rotate(4, 3);
//					}
//					if ((a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == green)) {
//						Rotate(4, 3);
//					}
//					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == green && a[1][0][2].color[2] == white)) {
//						Rotate(1, -3);
//					}
//					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white)) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[1][2][2].color[3] == orange && a[2][1][2].color[5] == red) {
//					if ((a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == blue)) {
//						Rotate(4, 3);
//					}
//					if ((a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == green)) {
//						Rotate(4, 3);
//					}
//					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == green && a[1][0][2].color[2] == white)) {
//						Rotate(1, -3);
//					}
//					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white)) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[1][2][2].color[3] == orange && a[2][1][2].color[5] == green) {
//					if ((a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == red)) {
//						Rotate(4, 3);
//					}
//					if ((a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == blue)) {
//						Rotate(4, 3);
//					}
//					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white)) {
//						Rotate(1, -3);
//					}
//					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == red && a[1][0][2].color[2] == white)) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[1][2][2].color[3] == orange && a[2][1][2].color[5] == blue) {
//					if ((a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == red)) {
//						Rotate(4, 3);
//					}
//					if ((a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == green)) {
//						Rotate(4, 3);
//					}
//					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == green && a[1][0][2].color[2] == white)) {
//						Rotate(1, -3);
//					}
//					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == red && a[1][0][2].color[2] == white)) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[1][2][2].color[3] == blue && a[2][1][2].color[5] == red) {
//					if ((a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == orange)) {
//						Rotate(4, 3);
//					}
//					if ((a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == green)) {
//						Rotate(4, 3);
//					}
//					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == green && a[1][0][2].color[2] == white)) {
//						Rotate(1, -3);
//					}
//					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white)) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[1][2][2].color[3] == blue && a[2][1][2].color[5] == green) {
//					if ((a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == red)) {
//						Rotate(4, 3);
//					}
//					if ((a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == orange)) {
//						Rotate(4, 3);
//					}
//					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white)) {
//						Rotate(1, -3);
//					}
//					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == red && a[1][0][2].color[2] == white)) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[1][2][2].color[3] == blue && a[2][1][2].color[5] == orange) {
//					if ((a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == red)) {
//						Rotate(4, 3);
//					}
//					if ((a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[0][2][1].color[3] == white && a[0][2][1].color[4] == green)) {
//						Rotate(4, 3);
//					}
//					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == green && a[1][0][2].color[2] == white)) {
//						Rotate(1, -3);
//					}
//					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == red && a[1][0][2].color[2] == white)) {
//						Rotate(1, -3);
//					}
//				}
//			}
//			//1 белая правая  
//			if (a[0][1][2].color[0] != white && a[1][0][2].color[0] != white && a[2][1][2].color[0] == white && a[1][2][2].color[0] != white) {
//				if (a[2][1][2].color[0] == white && a[2][1][2].color[5] == orange) {
//					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[2][0][1].color[5] == blue && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
//						Rotate(1, 3);
//					}
//					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[2][0][1].color[5] == green && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
//						Rotate(1, 3);
//					}
//					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[2][0][1].color[5] == blue && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
//						Rotate(1, 3);
//					}
//					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[2][0][1].color[5] == red && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
//						Rotate(1, 3);
//					}
//					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[2][0][1].color[5] == red && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
//						Rotate(1, 3);
//					}
//					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[2][0][1].color[5] == green && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[2][1][2].color[0] == white && a[2][1][2].color[5] == blue) {
//					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[2][0][1].color[5] == orange && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
//						Rotate(1, 3);
//					}
//					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[2][0][1].color[5] == green && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
//						Rotate(1, 3);
//					}
//					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[2][0][1].color[5] == orange && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
//						Rotate(1, 3);
//					}
//					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[2][0][1].color[5] == red && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
//						Rotate(1, 3);
//					}
//					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[2][0][1].color[5] == red && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
//						Rotate(1, 3);
//					}
//					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[2][0][1].color[5] == green && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[2][1][2].color[0] == white && a[2][1][2].color[5] == green) {
//					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[2][0][1].color[5] == orange && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
//						Rotate(1, 3);
//					}
//					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[2][0][1].color[5] == blue && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
//						Rotate(1, 3);
//					}
//					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[2][0][1].color[5] == orange && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
//						Rotate(1, 3);
//					}
//					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[2][0][1].color[5] == red && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
//						Rotate(1, 3);
//					}
//					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[2][0][1].color[5] == red && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
//						Rotate(1, 3);
//					}
//					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[2][0][1].color[5] == blue && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[2][1][2].color[0] == white && a[2][1][2].color[5] == red) {
//					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[2][0][1].color[5] == orange && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
//						Rotate(1, 3);
//					}
//					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[2][0][1].color[5] == blue && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
//						Rotate(1, 3);
//					}
//					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[2][0][1].color[5] == orange && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
//						Rotate(1, 3);
//					}
//					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[2][0][1].color[5] == green && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
//						Rotate(1, 3);
//					}
//					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[2][0][1].color[5] == green && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
//						Rotate(1, 3);
//					}
//					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[2][0][1].color[5] == blue && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
//						Rotate(1, 3);
//					}
//				}
//			}
//			//1 белая верхняя
//			if (a[0][1][2].color[0] != white && a[1][0][2].color[0] != white && a[2][1][2].color[0] != white && a[1][2][2].color[0] == white) {
//				if (a[1][2][2].color[0] == white && a[1][2][2].color[3] == orange) {
//					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[2][0][1].color[5] == blue && a[2][0][1].color[2] == white)) {
//						Rotate(5, -3);
//					}
//					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[2][0][1].color[5] == red && a[2][0][1].color[2] == white)) {
//						Rotate(5, -3);
//					}
//					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[2][0][1].color[5] == green && a[2][0][1].color[2] == white)) {
//						Rotate(5, -3);
//					}
//					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[2][0][1].color[5] == red && a[2][0][1].color[2] == white)) {
//						Rotate(5, -3);
//					}
//					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[2][0][1].color[5] == blue && a[2][0][1].color[2] == white)) {
//						Rotate(5, -3);
//					}
//					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[2][0][1].color[5] == green && a[2][0][1].color[2] == white)) {
//						Rotate(5, -3);
//					}
//					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[1][2][2].color[0] == white && a[1][2][2].color[3] == blue) {
//					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[2][0][1].color[5] == orange && a[2][0][1].color[2] == white)) {
//						Rotate(5, -3);
//					}
//					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[2][0][1].color[5] == red && a[2][0][1].color[2] == white)) {
//						Rotate(5, -3);
//					}
//					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[2][0][1].color[5] == green && a[2][0][1].color[2] == white)) {
//						Rotate(5, -3);
//					}
//					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[2][0][1].color[5] == red && a[2][0][1].color[2] == white)) {
//						Rotate(5, -3);
//					}
//					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[2][0][1].color[5] == orange && a[2][0][1].color[2] == white)) {
//						Rotate(5, -3);
//					}
//					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[2][0][1].color[5] == green && a[2][0][1].color[2] == white)) {
//						Rotate(5, -3);
//					}
//					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[1][2][2].color[0] == white && a[1][2][2].color[3] == green) {
//					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[2][0][1].color[5] == orange && a[2][0][1].color[2] == white)) {
//						Rotate(5, -3);
//					}
//					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[2][0][1].color[5] == red && a[2][0][1].color[2] == white)) {
//						Rotate(5, -3);
//					}
//					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[2][0][1].color[5] == blue && a[2][0][1].color[2] == white)) {
//						Rotate(5, -3);
//					}
//					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[2][0][1].color[5] == red && a[2][0][1].color[2] == white)) {
//						Rotate(5, -3);
//					}
//					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[2][0][1].color[5] == orange && a[2][0][1].color[2] == white)) {
//						Rotate(5, -3);
//					}
//					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[2][0][1].color[5] == blue && a[2][0][1].color[2] == white)) {
//						Rotate(5, -3);
//					}
//					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[1][2][2].color[0] == white && a[1][2][2].color[3] == red) {
//					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[2][0][1].color[5] == orange && a[2][0][1].color[2] == white)) {
//						Rotate(5, -3);
//					}
//					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[2][0][1].color[5] == green && a[2][0][1].color[2] == white)) {
//						Rotate(5, -3);
//					}
//					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[2][0][1].color[5] == blue && a[2][0][1].color[2] == white)) {
//						Rotate(5, -3);
//					}
//					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[2][0][1].color[5] == green && a[2][0][1].color[2] == white)) {
//						Rotate(5, -3);
//					}
//					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[2][0][1].color[5] == orange && a[2][0][1].color[2] == white)) {
//						Rotate(5, -3);
//					}
//					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[2][0][1].color[5] == blue && a[2][0][1].color[2] == white)) {
//						Rotate(5, -3);
//					}
//					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//				}
//			}
//			//белая левая
//			if (a[0][1][2].color[0] == white && a[1][0][2].color[0] != white && a[2][1][2].color[0] != white && a[1][2][2].color[0] != white) {
//				if (a[0][1][2].color[0] == white && a[0][1][2].color[4] == orange) {
//					if ((a[2][1][2].color[0] == red && a[2][1][2].color[5] == white) && (a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[2][1][2].color[0] == red && a[2][1][2].color[5] == white) && (a[2][0][1].color[5] == blue && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
//						Rotate(1, 3);
//					}
//					if ((a[2][1][2].color[0] == red && a[2][1][2].color[5] == white) && (a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[2][1][2].color[0] == red && a[2][1][2].color[5] == white) && (a[2][0][1].color[5] == green && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
//						Rotate(1, 3);
//					}
//					if ((a[2][1][2].color[0] == green && a[2][1][2].color[5] == white) && (a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[2][1][2].color[0] == green && a[2][1][2].color[5] == white) && (a[2][0][1].color[5] == blue && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
//						Rotate(1, 3);
//					}
//					if ((a[2][1][2].color[0] == green && a[2][1][2].color[5] == white) && (a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[2][1][2].color[0] == green && a[2][1][2].color[5] == white) && (a[2][0][1].color[5] == red && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
//						Rotate(1, 3);
//					}
//					if ((a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white) && (a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white) && (a[2][0][1].color[5] == red && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
//						Rotate(1, 3);
//					}
//					if ((a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white) && (a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white) && (a[2][0][1].color[5] == green && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[0][1][2].color[0] == white && a[0][1][2].color[4] == blue) {
//					if ((a[2][1][2].color[0] == red && a[2][1][2].color[5] == white) && (a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[2][1][2].color[0] == red && a[2][1][2].color[5] == white) && (a[2][0][1].color[5] == orange && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
//						Rotate(1, 3);
//					}
//					if ((a[2][1][2].color[0] == red && a[2][1][2].color[5] == white) && (a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[2][1][2].color[0] == red && a[2][1][2].color[5] == white) && (a[2][0][1].color[5] == green && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
//						Rotate(1, 3);
//					}
//					if ((a[2][1][2].color[0] == green && a[2][1][2].color[5] == white) && (a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[2][1][2].color[0] == green && a[2][1][2].color[5] == white) && (a[2][0][1].color[5] == orange && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
//						Rotate(1, 3);
//					}
//					if ((a[2][1][2].color[0] == green && a[2][1][2].color[5] == white) && (a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[2][1][2].color[0] == green && a[2][1][2].color[5] == white) && (a[2][0][1].color[5] == red && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
//						Rotate(1, 3);
//					}
//					if ((a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white) && (a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white) && (a[2][0][1].color[5] == red && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
//						Rotate(1, 3);
//					}
//					if ((a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white) && (a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white) && (a[2][0][1].color[5] == green && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[0][1][2].color[0] == white && a[0][1][2].color[4] == green) {
//					if ((a[2][1][2].color[0] == red && a[2][1][2].color[5] == white) && (a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[2][1][2].color[0] == red && a[2][1][2].color[5] == white) && (a[2][0][1].color[5] == orange && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
//						Rotate(1, 3);
//					}
//					if ((a[2][1][2].color[0] == red && a[2][1][2].color[5] == white) && (a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[2][1][2].color[0] == red && a[2][1][2].color[5] == white) && (a[2][0][1].color[5] == blue && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
//						Rotate(1, 3);
//					}
//					if ((a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white) && (a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white) && (a[2][0][1].color[5] == orange && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
//						Rotate(1, 3);
//					}
//					if ((a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white) && (a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white) && (a[2][0][1].color[5] == red && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
//						Rotate(1, 3);
//					}
//					if ((a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white) && (a[1][0][2].color[0] == red && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white) && (a[2][0][1].color[5] == red && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
//						Rotate(1, 3);
//					}
//					if ((a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white) && (a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white) && (a[2][0][1].color[5] == blue && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white)) {
//						Rotate(1, 3);
//					}
//				}
//				if (a[0][1][2].color[0] == white && a[0][1][2].color[4] == red) {
//					if ((a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white) && (a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white) && (a[2][0][1].color[5] == orange && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
//						Rotate(1, 3);
//					}
//					if ((a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white) && (a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white) && (a[2][0][1].color[5] == green && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
//						Rotate(1, 3);
//					}
//					if ((a[2][1][2].color[0] == green && a[2][1][2].color[5] == white) && (a[1][0][2].color[0] == orange && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[2][1][2].color[0] == green && a[2][1][2].color[5] == white) && (a[2][0][1].color[5] == orange && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
//						Rotate(1, 3);
//					}
//					if ((a[2][1][2].color[0] == green && a[2][1][2].color[5] == white) && (a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[2][1][2].color[0] == green && a[2][1][2].color[5] == white) && (a[2][0][1].color[5] == blue && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white)) {
//						Rotate(1, 3);
//					}
//					if ((a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white) && (a[1][0][2].color[0] == blue && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white) && (a[2][0][1].color[5] == blue && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white)) {
//						Rotate(1, 3);
//					}
//					if ((a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white) && (a[1][0][2].color[0] == green && a[1][0][2].color[2] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
//						Rotate(2, 3);
//					}
//					if ((a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white) && (a[2][0][1].color[5] == green && a[2][0][1].color[2] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white)) {
//						Rotate(1, 3);
//					}
//				}
//			}
//			//белая нижняя
//			if (a[0][1][2].color[0] != white && a[1][0][2].color[0] == white && a[2][1][2].color[0] != white && a[1][2][2].color[0] != white) {
//				if (a[1][0][2].color[0] == white && a[1][0][2].color[2] == orange) {
//					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white) && (a[2][0][1].color[5] == blue && a[2][0][1].color[2] == white)) {
//						Rotate(5, -3);
//					}
//					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white) && (a[2][0][1].color[5] == red && a[2][0][1].color[2] == white)) {
//						Rotate(5, -3);
//					}
//					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white) && (a[2][0][1].color[5] == green && a[2][0][1].color[2] == white)) {
//						Rotate(5, -3);
//					}
//					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white) && (a[2][0][1].color[5] == red && a[2][0][1].color[2] == white)) {
//						Rotate(5, -3);
//					}
//					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white) && (a[2][0][1].color[5] == blue && a[2][0][1].color[2] == white)) {
//						Rotate(5, -3);
//					}
//					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white) && (a[2][0][1].color[5] == green && a[2][0][1].color[2] == white)) {
//						Rotate(5, -3);
//					}
//					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[1][0][2].color[0] == white && a[1][0][2].color[2] == blue) {
//					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white) && (a[2][0][1].color[5] == orange && a[2][0][1].color[2] == white)) {
//						Rotate(5, -3);
//					}
//					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white) && (a[2][0][1].color[5] == red && a[2][0][1].color[2] == white)) {
//						Rotate(5, -3);
//					}
//					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white) && (a[2][0][1].color[5] == green && a[2][0][1].color[2] == white)) {
//						Rotate(5, -3);
//					}
//					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white) && (a[2][0][1].color[5] == red && a[2][0][1].color[2] == white)) {
//						Rotate(5, -3);
//					}
//					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white) && (a[2][0][1].color[5] == orange && a[2][0][1].color[2] == white)) {
//						Rotate(5, -3);
//					}
//					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white) && (a[2][0][1].color[5] == green && a[2][0][1].color[2] == white)) {
//						Rotate(5, -3);
//					}
//					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[1][0][2].color[0] == white && a[1][0][2].color[2] == green) {
//					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white) && (a[2][0][1].color[5] == orange && a[2][0][1].color[2] == white)) {
//						Rotate(5, -3);
//					}
//					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white) && (a[2][0][1].color[5] == red && a[2][0][1].color[2] == white)) {
//						Rotate(5, -3);
//					}
//					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white) && (a[2][0][1].color[5] == blue && a[2][0][1].color[2] == white)) {
//						Rotate(5, -3);
//					}
//					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == red && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white) && (a[2][0][1].color[5] == red && a[2][0][1].color[2] == white)) {
//						Rotate(5, -3);
//					}
//					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == red && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white) && (a[2][0][1].color[5] == orange && a[2][0][1].color[2] == white)) {
//						Rotate(5, -3);
//					}
//					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white) && (a[2][0][1].color[5] == blue && a[2][0][1].color[2] == white)) {
//						Rotate(5, -3);
//					}
//					if ((a[0][1][2].color[0] == red && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//				}
//				if (a[1][0][2].color[0] == white && a[1][0][2].color[2] == red) {
//					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white) && (a[2][0][1].color[5] == orange && a[2][0][1].color[2] == white)) {
//						Rotate(5, -3);
//					}
//					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white) && (a[2][0][1].color[5] == green && a[2][0][1].color[2] == white)) {
//						Rotate(5, -3);
//					}
//					if ((a[0][1][2].color[0] == blue && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white) && (a[2][0][1].color[5] == blue && a[2][0][1].color[2] == white)) {
//						Rotate(5, -3);
//					}
//					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == green && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white) && (a[2][0][1].color[5] == green && a[2][0][1].color[2] == white)) {
//						Rotate(5, -3);
//					}
//					if ((a[0][1][2].color[0] == orange && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == green && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white) && (a[2][0][1].color[5] == orange && a[2][0][1].color[2] == white)) {
//						Rotate(5, -3);
//					}
//					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == blue && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == orange && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white) && (a[2][0][1].color[5] == blue && a[2][0][1].color[2] == white)) {
//						Rotate(5, -3);
//					}
//					if ((a[0][1][2].color[0] == green && a[0][1][2].color[4] == white) && (a[1][2][2].color[0] == orange && a[1][2][2].color[3] == white) && (a[2][1][2].color[0] == blue && a[2][1][2].color[5] == white)) {
//						Rotate(1, -3);
//					}
//				}
//			}
//			//собрано 0 наверху, но есть 4 белых
//			if (a[0][1][2].color[4] == white && a[1][0][2].color[2] == white && a[2][1][2].color[5] == white && a[1][2][2].color[3] == white) {
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[2][1][2].color[0] == orange && a[1][2][2].color[0] == green) {
//					Rotate(2, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[2][1][2].color[0] == blue && a[1][2][2].color[0] == green) {
//					Rotate(2, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[2][1][2].color[0] == orange && a[1][2][2].color[0] == blue) {
//					Rotate(2, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[2][1][2].color[0] == green && a[1][2][2].color[0] == blue) {
//					Rotate(2, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[2][1][2].color[0] == green && a[1][2][2].color[0] == orange) {
//					Rotate(2, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[2][1][2].color[0] == blue && a[1][2][2].color[0] == orange) {
//					Rotate(2, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[2][1][2].color[0] == orange && a[1][2][2].color[0] == green) {
//					Rotate(2, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[2][1][2].color[0] == red && a[1][2][2].color[0] == green) {
//					Rotate(2, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[2][1][2].color[0] == orange && a[1][2][2].color[0] == red) {
//					Rotate(2, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[2][1][2].color[0] == green && a[1][2][2].color[0] == red) {
//					Rotate(2, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[2][1][2].color[0] == green && a[1][2][2].color[0] == orange) {
//					Rotate(2, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[2][1][2].color[0] == red && a[1][2][2].color[0] == orange) {
//					Rotate(2, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[2][1][2].color[0] == orange && a[1][2][2].color[0] == red) {
//					Rotate(2, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[2][1][2].color[0] == blue && a[1][2][2].color[0] == red) {
//					Rotate(2, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[2][1][2].color[0] == orange && a[1][2][2].color[0] == blue) {
//					Rotate(2, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[2][1][2].color[0] == red && a[1][2][2].color[0] == blue) {
//					Rotate(2, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[2][1][2].color[0] == red && a[1][2][2].color[0] == orange) {
//					Rotate(2, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[2][1][2].color[0] == blue && a[1][2][2].color[0] == orange) {
//					Rotate(2, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[2][1][2].color[0] == red && a[1][2][2].color[0] == green) {
//					Rotate(2, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[2][1][2].color[0] == blue && a[1][2][2].color[0] == green) {
//					Rotate(2, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[2][1][2].color[0] == red && a[1][2][2].color[0] == blue) {
//					Rotate(2, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[2][1][2].color[0] == green && a[1][2][2].color[0] == blue) {
//					Rotate(2, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[2][1][2].color[0] == green && a[1][2][2].color[0] == red) {
//					Rotate(2, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[2][1][2].color[0] == blue && a[1][2][2].color[0] == red) {
//					Rotate(2, 3);
//				}
//			}
//			//собрано 0 наверху, но есть 3 белых кроме нижнего
//			if (a[0][1][2].color[4] == white && a[2][1][2].color[5] == white && a[2][0][1].color[2] == white && a[1][2][2].color[3] == white) {
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == green && a[2][1][2].color[0] == orange && a[2][0][1].color[5] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == green && a[2][0][1].color[5] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == red && a[2][1][2].color[0] == orange && a[2][0][1].color[5] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == red && a[2][0][1].color[5] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == green && a[2][1][2].color[0] == red && a[2][0][1].color[5] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == red && a[2][1][2].color[0] == green && a[2][0][1].color[5] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == green && a[2][1][2].color[0] == blue && a[2][0][1].color[5] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == green && a[2][0][1].color[5] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == red && a[2][1][2].color[0] == blue && a[2][0][1].color[5] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == red && a[2][0][1].color[5] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == green && a[2][1][2].color[0] == red && a[2][0][1].color[5] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == red && a[2][1][2].color[0] == green && a[2][0][1].color[5] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == orange && a[2][0][1].color[5] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == blue && a[2][0][1].color[5] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == red && a[2][1][2].color[0] == orange && a[2][0][1].color[5] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == red && a[2][0][1].color[5] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == red && a[2][0][1].color[5] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == red && a[2][1][2].color[0] == blue && a[2][0][1].color[5] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == green && a[2][1][2].color[0] == orange && a[2][0][1].color[5] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == green && a[2][0][1].color[5] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == orange && a[2][0][1].color[5] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == blue && a[2][0][1].color[5] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == green && a[2][1][2].color[0] == blue && a[2][0][1].color[5] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == green && a[2][0][1].color[5] == red) {
//					Rotate(1, 3);
//				}
//			}
//			if (a[0][1][2].color[4] == white && a[2][1][2].color[5] == white && a[2][0][1].color[5] == white && a[1][2][2].color[3] == white) {
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == green && a[2][1][2].color[0] == orange && a[2][0][1].color[2] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == green && a[2][0][1].color[2] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == red && a[2][1][2].color[0] == orange && a[2][0][1].color[2] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == red && a[2][0][1].color[2] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == green && a[2][1][2].color[0] == red && a[2][0][1].color[2] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == red && a[2][1][2].color[0] == green && a[2][0][1].color[2] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == green && a[2][1][2].color[0] == blue && a[2][0][1].color[2] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == green && a[2][0][1].color[2] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == red && a[2][1][2].color[0] == blue && a[2][0][1].color[2] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == red && a[2][0][1].color[2] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == green && a[2][1][2].color[0] == red && a[2][0][1].color[2] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == red && a[2][1][2].color[0] == green && a[2][0][1].color[2] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == orange && a[2][0][1].color[2] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == blue && a[2][0][1].color[2] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == red && a[2][1][2].color[0] == orange && a[2][0][1].color[2] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == red && a[2][0][1].color[2] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == red && a[2][0][1].color[2] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == red && a[2][1][2].color[0] == blue && a[2][0][1].color[2] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == green && a[2][1][2].color[0] == orange && a[2][0][1].color[2] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == green && a[2][0][1].color[2] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == orange && a[2][0][1].color[2] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == blue && a[2][0][1].color[2] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == green && a[2][1][2].color[0] == blue && a[2][0][1].color[2] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == green && a[2][0][1].color[2] == red) {
//					Rotate(1, 3);
//				}
//			}
//			if (a[0][1][2].color[4] == white && a[2][1][2].color[5] == white && a[1][0][0].color[2] == white && a[1][2][2].color[3] == white) {
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == green && a[2][1][2].color[0] == orange && a[1][0][0].color[1] == blue) {
//					Rotate(2, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == green && a[1][0][0].color[1] == blue) {
//					Rotate(2, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == red && a[2][1][2].color[0] == orange && a[1][0][0].color[1] == blue) {
//					Rotate(2, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == red && a[1][0][0].color[1] == blue) {
//					Rotate(2, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == green && a[2][1][2].color[0] == red && a[1][0][0].color[1] == blue) {
//					Rotate(2, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == red && a[2][1][2].color[0] == green && a[1][0][0].color[1] == blue) {
//					Rotate(2, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == green && a[2][1][2].color[0] == blue && a[1][0][0].color[1] == orange) {
//					Rotate(2, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == green && a[1][0][0].color[1] == orange) {
//					Rotate(2, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == red && a[2][1][2].color[0] == blue && a[1][0][0].color[1] == orange) {
//					Rotate(2, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == red && a[1][0][0].color[1] == orange) {
//					Rotate(2, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == green && a[2][1][2].color[0] == red && a[1][0][0].color[1] == orange) {
//					Rotate(2, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == red && a[2][1][2].color[0] == green && a[1][0][0].color[1] == orange) {
//					Rotate(2, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == orange && a[1][0][0].color[1] == green) {
//					Rotate(2, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == blue && a[1][0][0].color[1] == green) {
//					Rotate(2, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == red && a[2][1][2].color[0] == orange && a[1][0][0].color[1] == green) {
//					Rotate(2, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == red && a[1][0][0].color[1] == green) {
//					Rotate(2, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == red && a[1][0][0].color[1] == green) {
//					Rotate(2, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == red && a[2][1][2].color[0] == blue && a[1][0][0].color[1] == green) {
//					Rotate(2, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == green && a[2][1][2].color[0] == orange && a[1][0][0].color[1] == red) {
//					Rotate(2, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == green && a[1][0][0].color[1] == red) {
//					Rotate(2, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == orange && a[1][0][0].color[1] == red) {
//					Rotate(2, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == blue && a[1][0][0].color[1] == red) {
//					Rotate(2, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == green && a[2][1][2].color[0] == blue && a[1][0][0].color[1] == red) {
//					Rotate(2, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == green && a[1][0][0].color[1] == red) {
//					Rotate(2, 3);
//				}
//			}
//			if (a[0][1][2].color[4] == white && a[2][1][2].color[5] == white && a[1][0][0].color[1] == white && a[1][2][2].color[3] == white) {
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == green && a[2][1][2].color[0] == orange && a[1][0][0].color[2] == blue) {
//					Rotate(2, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == green && a[1][0][0].color[2] == blue) {
//					Rotate(2, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == red && a[2][1][2].color[0] == orange && a[1][0][0].color[2] == blue) {
//					Rotate(2, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == red && a[1][0][0].color[2] == blue) {
//					Rotate(2, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == green && a[2][1][2].color[0] == red && a[1][0][0].color[2] == blue) {
//					Rotate(2, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == red && a[2][1][2].color[0] == green && a[1][0][0].color[2] == blue) {
//					Rotate(2, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == green && a[2][1][2].color[0] == blue && a[1][0][0].color[2] == orange) {
//					Rotate(2, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == green && a[1][0][0].color[2] == orange) {
//					Rotate(2, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == red && a[2][1][2].color[0] == blue && a[1][0][0].color[2] == orange) {
//					Rotate(2, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == red && a[1][0][0].color[2] == orange) {
//					Rotate(2, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == green && a[2][1][2].color[0] == red && a[1][0][0].color[2] == orange) {
//					Rotate(2, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == red && a[2][1][2].color[0] == green && a[1][0][0].color[2] == orange) {
//					Rotate(2, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == orange && a[1][0][0].color[2] == green) {
//					Rotate(2, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == blue && a[1][0][0].color[2] == green) {
//					Rotate(2, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == red && a[2][1][2].color[0] == orange && a[1][0][0].color[2] == green) {
//					Rotate(2, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == red && a[1][0][0].color[2] == green) {
//					Rotate(2, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == red && a[1][0][0].color[2] == green) {
//					Rotate(2, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == red && a[2][1][2].color[0] == blue && a[1][0][0].color[2] == green) {
//					Rotate(2, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == green && a[2][1][2].color[0] == orange && a[1][0][0].color[2] == red) {
//					Rotate(2, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == green && a[1][0][0].color[2] == red) {
//					Rotate(2, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == orange && a[1][0][0].color[2] == red) {
//					Rotate(2, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == blue && a[1][0][0].color[2] == red) {
//					Rotate(2, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == green && a[2][1][2].color[0] == blue && a[1][0][0].color[2] == red) {
//					Rotate(2, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == green && a[1][0][0].color[2] == red) {
//					Rotate(2, 3);
//				}
//			}
//			if (a[0][1][2].color[4] == white && a[2][1][2].color[5] == white && a[0][0][1].color[2] == white && a[1][2][2].color[3] == white) {
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == green && a[2][1][2].color[0] == orange && a[0][0][1].color[4] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == green && a[0][0][1].color[4] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == red && a[2][1][2].color[0] == orange && a[0][0][1].color[4] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == red && a[0][0][1].color[4] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == green && a[2][1][2].color[0] == red && a[0][0][1].color[4] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == red && a[2][1][2].color[0] == green && a[0][0][1].color[4] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == green && a[2][1][2].color[0] == blue && a[0][0][1].color[4] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == green && a[0][0][1].color[4] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == red && a[2][1][2].color[0] == blue && a[0][0][1].color[4] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == red && a[0][0][1].color[4] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == green && a[2][1][2].color[0] == red && a[0][0][1].color[4] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == red && a[2][1][2].color[0] == green && a[0][0][1].color[4] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == orange && a[0][0][1].color[4] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == blue && a[0][0][1].color[4] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == red && a[2][1][2].color[0] == orange && a[0][0][1].color[4] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == red && a[0][0][1].color[4] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == red && a[0][0][1].color[4] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == red && a[2][1][2].color[0] == blue && a[0][0][1].color[4] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == green && a[2][1][2].color[0] == orange && a[0][0][1].color[4] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == green && a[0][0][1].color[4] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == orange && a[0][0][1].color[4] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == blue && a[0][0][1].color[4] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == green && a[2][1][2].color[0] == blue && a[0][0][1].color[4] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == green && a[0][0][1].color[4] == red) {
//					Rotate(1, -3);
//				}
//			}
//			if (a[0][1][2].color[4] == white && a[2][1][2].color[5] == white && a[0][0][1].color[4] == white && a[1][2][2].color[3] == white) {
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == green && a[2][1][2].color[0] == orange && a[0][0][1].color[2] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == green && a[0][0][1].color[2] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == red && a[2][1][2].color[0] == orange && a[0][0][1].color[2] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == red && a[0][0][1].color[2] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == green && a[2][1][2].color[0] == red && a[0][0][1].color[2] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == red && a[2][1][2].color[0] == green && a[0][0][1].color[2] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == green && a[2][1][2].color[0] == blue && a[0][0][1].color[2] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == green && a[0][0][1].color[2] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == red && a[2][1][2].color[0] == blue && a[0][0][1].color[2] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == red && a[0][0][1].color[2] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == green && a[2][1][2].color[0] == red && a[0][0][1].color[2] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == red && a[2][1][2].color[0] == green && a[0][0][1].color[2] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == orange && a[0][0][1].color[2] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == blue && a[0][0][1].color[2] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == red && a[2][1][2].color[0] == orange && a[0][0][1].color[2] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == red && a[0][0][1].color[2] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == red && a[0][0][1].color[2] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == red && a[2][1][2].color[0] == blue && a[0][0][1].color[2] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == green && a[2][1][2].color[0] == orange && a[0][0][1].color[2] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == green && a[0][0][1].color[2] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == orange && a[0][0][1].color[2] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == blue && a[0][0][1].color[2] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == green && a[2][1][2].color[0] == blue && a[0][0][1].color[2] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == green && a[0][0][1].color[2] == red) {
//					Rotate(1, -3);
//				}
//			}
//			if (a[0][1][2].color[4] == white && a[2][1][2].color[5] == white && a[2][2][1].color[3] == white && a[1][2][2].color[3] == white) {
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == green && a[2][1][2].color[0] == orange && a[2][2][1].color[5] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == green && a[2][2][1].color[5] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == red && a[2][1][2].color[0] == orange && a[2][2][1].color[5] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == red && a[2][2][1].color[5] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == green && a[2][1][2].color[0] == red && a[2][2][1].color[5] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == red && a[2][1][2].color[0] == green && a[2][2][1].color[5] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == green && a[2][1][2].color[0] == blue && a[2][2][1].color[5] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == green && a[2][2][1].color[5] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == red && a[2][1][2].color[0] == blue && a[2][2][1].color[5] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == red && a[2][2][1].color[5] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == green && a[2][1][2].color[0] == red && a[2][2][1].color[5] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == red && a[2][1][2].color[0] == green && a[2][2][1].color[5] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == orange && a[2][2][1].color[5] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == blue && a[2][2][1].color[5] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == red && a[2][1][2].color[0] == orange && a[2][2][1].color[5] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == red && a[2][2][1].color[5] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == red && a[2][2][1].color[5] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == red && a[2][1][2].color[0] == blue && a[2][2][1].color[5] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == green && a[2][1][2].color[0] == orange && a[2][2][1].color[5] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == green && a[2][2][1].color[5] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == orange && a[2][2][1].color[5] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == blue && a[2][2][1].color[5] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == green && a[2][1][2].color[0] == blue && a[2][2][1].color[5] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == green && a[2][2][1].color[5] == red) {
//					Rotate(1, 3);
//				}
//			}
//			if (a[0][1][2].color[4] == white && a[2][1][2].color[5] == white && a[2][2][1].color[5] == white && a[1][2][2].color[3] == white) {
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == green && a[2][1][2].color[0] == orange && a[2][2][1].color[3] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == green && a[2][2][1].color[3] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == red && a[2][1][2].color[0] == orange && a[2][2][1].color[3] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == red && a[2][2][1].color[3] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == green && a[2][1][2].color[0] == red && a[2][2][1].color[3] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == red && a[2][1][2].color[0] == green && a[2][2][1].color[3] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == green && a[2][1][2].color[0] == blue && a[2][2][1].color[3] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == green && a[2][2][1].color[3] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == red && a[2][1][2].color[0] == blue && a[2][2][1].color[3] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == red && a[2][2][1].color[3] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == green && a[2][1][2].color[0] == red && a[2][2][1].color[3] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == red && a[2][1][2].color[0] == green && a[2][2][1].color[3] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == orange && a[2][2][1].color[3] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == blue && a[2][2][1].color[3] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == red && a[2][1][2].color[0] == orange && a[2][2][1].color[3] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == red && a[2][2][1].color[3] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == red && a[2][2][1].color[3] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == red && a[2][1][2].color[0] == blue && a[2][2][1].color[3] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == green && a[2][1][2].color[0] == orange && a[2][2][1].color[3] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == green && a[2][2][1].color[3] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == orange && a[2][2][1].color[3] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == blue && a[2][2][1].color[3] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == green && a[2][1][2].color[0] == blue && a[2][2][1].color[3] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == green && a[2][2][1].color[3] == red) {
//					Rotate(1, 3);
//				}
//			}
//			if (a[0][1][2].color[4] == white && a[2][1][2].color[5] == white && a[1][2][0].color[3] == white && a[1][2][2].color[3] == white) {
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == green && a[2][1][2].color[0] == orange && a[1][2][0].color[1] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == green && a[1][2][0].color[1] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == red && a[2][1][2].color[0] == orange && a[1][2][0].color[1] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == red && a[1][2][0].color[1] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == green && a[2][1][2].color[0] == red && a[1][2][0].color[1] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == red && a[2][1][2].color[0] == green && a[1][2][0].color[1] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == green && a[2][1][2].color[0] == blue && a[1][2][0].color[1] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == green && a[1][2][0].color[1] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == red && a[2][1][2].color[0] == blue && a[1][2][0].color[1] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == red && a[1][2][0].color[1] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == green && a[2][1][2].color[0] == red && a[1][2][0].color[1] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == red && a[2][1][2].color[0] == green && a[1][2][0].color[1] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == orange && a[1][2][0].color[1] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == blue && a[1][2][0].color[1] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == red && a[2][1][2].color[0] == orange && a[1][2][0].color[1] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == red && a[1][2][0].color[1] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == red && a[1][2][0].color[1] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == red && a[2][1][2].color[0] == blue && a[1][2][0].color[1] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == green && a[2][1][2].color[0] == orange && a[1][2][0].color[1] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == green && a[1][2][0].color[1] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == orange && a[1][2][0].color[1] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == blue && a[1][2][0].color[1] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == green && a[2][1][2].color[0] == blue && a[1][2][0].color[1] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == green && a[1][2][0].color[1] == red) {
//					Rotate(1, 3);
//				}
//			}
//			if (a[0][1][2].color[4] == white && a[2][1][2].color[5] == white && a[1][2][0].color[1] == white && a[1][2][2].color[3] == white) {
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == green && a[2][1][2].color[0] == orange && a[1][2][0].color[3] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == green && a[1][2][0].color[3] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == red && a[2][1][2].color[0] == orange && a[1][2][0].color[3] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == red && a[1][2][0].color[3] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == green && a[2][1][2].color[0] == red && a[1][2][0].color[3] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == red && a[2][1][2].color[0] == green && a[1][2][0].color[3] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == green && a[2][1][2].color[0] == blue && a[1][2][0].color[3] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == green && a[1][2][0].color[3] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == red && a[2][1][2].color[0] == blue && a[1][2][0].color[3] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == red && a[1][2][0].color[3] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == green && a[2][1][2].color[0] == red && a[1][2][0].color[3] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == red && a[2][1][2].color[0] == green && a[1][2][0].color[3] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == orange && a[1][2][0].color[3] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == blue && a[1][2][0].color[3] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == red && a[2][1][2].color[0] == orange && a[1][2][0].color[3] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == red && a[1][2][0].color[3] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == red && a[1][2][0].color[3] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == red && a[2][1][2].color[0] == blue && a[1][2][0].color[3] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == green && a[2][1][2].color[0] == orange && a[1][2][0].color[3] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == green && a[1][2][0].color[3] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == orange && a[1][2][0].color[3] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == blue && a[1][2][0].color[3] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == green && a[2][1][2].color[0] == blue && a[1][2][0].color[3] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == green && a[1][2][0].color[3] == red) {
//					Rotate(1, 3);
//				}
//			}
//			if (a[0][1][2].color[4] == white && a[2][1][2].color[5] == white && a[0][2][1].color[3] == white && a[1][2][2].color[3] == white) {
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == green && a[2][1][2].color[0] == orange && a[0][2][1].color[4] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == green && a[0][2][1].color[4] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == red && a[2][1][2].color[0] == orange && a[0][2][1].color[4] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == red && a[0][2][1].color[4] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == green && a[2][1][2].color[0] == red && a[0][2][1].color[4] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == red && a[2][1][2].color[0] == green && a[0][2][1].color[4] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == green && a[2][1][2].color[0] == blue && a[0][2][1].color[4] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == green && a[0][2][1].color[4] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == red && a[2][1][2].color[0] == blue && a[0][2][1].color[4] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == red && a[0][2][1].color[4] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == green && a[2][1][2].color[0] == red && a[0][2][1].color[4] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == red && a[2][1][2].color[0] == green && a[0][2][1].color[4] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == orange && a[0][2][1].color[4] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == blue && a[0][2][1].color[4] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == red && a[2][1][2].color[0] == orange && a[0][2][1].color[4] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == red && a[0][2][1].color[4] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == red && a[0][2][1].color[4] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == red && a[2][1][2].color[0] == blue && a[0][2][1].color[4] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == green && a[2][1][2].color[0] == orange && a[0][2][1].color[4] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == green && a[0][2][1].color[4] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == orange && a[0][2][1].color[4] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == blue && a[0][2][1].color[4] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == green && a[2][1][2].color[0] == blue && a[0][2][1].color[4] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == green && a[0][2][1].color[4] == red) {
//					Rotate(1, -3);
//				}
//			}
//			if (a[0][1][2].color[4] == white && a[2][1][2].color[5] == white && a[0][2][1].color[4] == white && a[1][2][2].color[3] == white) {
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == green && a[2][1][2].color[0] == orange && a[0][2][1].color[3] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == green && a[0][2][1].color[3] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == red && a[2][1][2].color[0] == orange && a[0][2][1].color[3] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == red && a[0][2][1].color[3] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == green && a[2][1][2].color[0] == red && a[0][2][1].color[3] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == red && a[2][1][2].color[0] == green && a[0][2][1].color[3] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == green && a[2][1][2].color[0] == blue && a[0][2][1].color[3] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == green && a[0][2][1].color[3] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == red && a[2][1][2].color[0] == blue && a[0][2][1].color[3] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == red && a[0][2][1].color[3] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == green && a[2][1][2].color[0] == red && a[0][2][1].color[3] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == red && a[2][1][2].color[0] == green && a[0][2][1].color[3] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == orange && a[0][2][1].color[3] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == blue && a[0][2][1].color[3] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == red && a[2][1][2].color[0] == orange && a[0][2][1].color[3] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == red && a[0][2][1].color[3] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == red && a[0][2][1].color[3] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == red && a[2][1][2].color[0] == blue && a[0][2][1].color[3] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == green && a[2][1][2].color[0] == orange && a[0][2][1].color[3] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == green && a[0][2][1].color[3] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == orange && a[0][2][1].color[3] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == blue && a[0][2][1].color[3] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == green && a[2][1][2].color[0] == blue && a[0][2][1].color[3] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == green && a[0][2][1].color[3] == red) {
//					Rotate(1, -3);
//				}
//			}
//			if (a[0][1][2].color[4] == white && a[2][1][2].color[5] == white && a[0][1][0].color[4] == white && a[1][2][2].color[3] == white) {
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == green && a[2][1][2].color[0] == orange && a[0][1][0].color[1] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == green && a[0][1][0].color[1] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == red && a[2][1][2].color[0] == orange && a[0][1][0].color[1] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == red && a[0][1][0].color[1] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == green && a[2][1][2].color[0] == red && a[0][1][0].color[1] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == red && a[2][1][2].color[0] == green && a[0][1][0].color[1] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == green && a[2][1][2].color[0] == blue && a[0][1][0].color[1] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == green && a[0][1][0].color[1] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == red && a[2][1][2].color[0] == blue && a[0][1][0].color[1] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == red && a[0][1][0].color[1] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == green && a[2][1][2].color[0] == red && a[0][1][0].color[1] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == red && a[2][1][2].color[0] == green && a[0][1][0].color[1] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == orange && a[0][1][0].color[1] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == blue && a[0][1][0].color[1] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == red && a[2][1][2].color[0] == orange && a[0][1][0].color[1] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == red && a[0][1][0].color[1] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == red && a[0][1][0].color[1] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == red && a[2][1][2].color[0] == blue && a[0][1][0].color[1] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == green && a[2][1][2].color[0] == orange && a[0][1][0].color[1] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == green && a[0][1][0].color[1] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == orange && a[0][1][0].color[1] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == blue && a[0][1][0].color[1] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == green && a[2][1][2].color[0] == blue && a[0][1][0].color[1] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == green && a[0][1][0].color[1] == red) {
//					Rotate(1, -3);
//				}
//			}
//			if (a[0][1][2].color[4] == white && a[2][1][2].color[5] == white && a[0][1][0].color[1] == white && a[1][2][2].color[3] == white) {
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == green && a[2][1][2].color[0] == orange && a[0][1][0].color[4] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == green && a[0][1][0].color[4] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == red && a[2][1][2].color[0] == orange && a[0][1][0].color[4] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == red && a[0][1][0].color[4] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == green && a[2][1][2].color[0] == red && a[0][1][0].color[4] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == red && a[2][1][2].color[0] == green && a[0][1][0].color[4] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == green && a[2][1][2].color[0] == blue && a[0][1][0].color[4] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == green && a[0][1][0].color[4] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == red && a[2][1][2].color[0] == blue && a[0][1][0].color[4] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == red && a[0][1][0].color[4] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == green && a[2][1][2].color[0] == red && a[0][1][0].color[4] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == red && a[2][1][2].color[0] == green && a[0][1][0].color[4] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == orange && a[0][1][0].color[4] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == blue && a[0][1][0].color[4] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == red && a[2][1][2].color[0] == orange && a[0][1][0].color[4] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == red && a[0][1][0].color[4] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == red && a[0][1][0].color[4] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == red && a[2][1][2].color[0] == blue && a[0][1][0].color[4] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == green && a[2][1][2].color[0] == orange && a[0][1][0].color[4] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == green && a[0][1][0].color[4] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == orange && a[0][1][0].color[4] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == blue && a[0][1][0].color[4] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == green && a[2][1][2].color[0] == blue && a[0][1][0].color[4] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == green && a[0][1][0].color[4] == red) {
//					Rotate(1, -3);
//				}
//			}
//			if (a[0][1][2].color[4] == white && a[2][1][2].color[5] == white && a[2][1][0].color[5] == white && a[1][2][2].color[3] == white) {
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == green && a[2][1][2].color[0] == orange && a[2][1][0].color[1] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == green && a[2][1][0].color[1] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == red && a[2][1][2].color[0] == orange && a[2][1][0].color[1] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == red && a[2][1][0].color[1] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == green && a[2][1][2].color[0] == red && a[2][1][0].color[1] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == red && a[2][1][2].color[0] == green && a[2][1][0].color[1] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == green && a[2][1][2].color[0] == blue && a[2][1][0].color[1] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == green && a[2][1][0].color[1] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == red && a[2][1][2].color[0] == blue && a[2][1][0].color[1] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == red && a[2][1][0].color[1] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == green && a[2][1][2].color[0] == red && a[2][1][0].color[1] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == red && a[2][1][2].color[0] == green && a[2][1][0].color[1] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == orange && a[2][1][0].color[1] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == blue && a[2][1][0].color[1] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == red && a[2][1][2].color[0] == orange && a[2][1][0].color[1] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == red && a[2][1][0].color[1] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == red && a[2][1][0].color[1] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == red && a[2][1][2].color[0] == blue && a[2][1][0].color[1] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == green && a[2][1][2].color[0] == orange && a[2][1][0].color[1] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == green && a[2][1][0].color[1] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == orange && a[2][1][0].color[1] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == blue && a[2][1][0].color[1] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == green && a[2][1][2].color[0] == blue && a[2][1][0].color[1] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == green && a[2][1][0].color[1] == red) {
//					Rotate(1, 3);
//				}
//			}
//			if (a[0][1][2].color[4] == white && a[2][1][2].color[5] == white && a[2][1][0].color[1] == white && a[1][2][2].color[3] == white) {
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == green && a[2][1][2].color[0] == orange && a[2][1][0].color[5] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == green && a[2][1][0].color[5] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == red && a[2][1][2].color[0] == orange && a[2][1][0].color[5] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == red && a[2][1][0].color[5] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == green && a[2][1][2].color[0] == red && a[2][1][0].color[5] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == red && a[2][1][2].color[0] == green && a[2][1][0].color[5] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == green && a[2][1][2].color[0] == blue && a[2][1][0].color[5] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == green && a[2][1][0].color[5] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == red && a[2][1][2].color[0] == blue && a[2][1][0].color[5] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == red && a[2][1][0].color[5] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == green && a[2][1][2].color[0] == red && a[2][1][0].color[5] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == red && a[2][1][2].color[0] == green && a[2][1][0].color[5] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == orange && a[2][1][0].color[5] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == blue && a[2][1][0].color[5] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == red && a[2][1][2].color[0] == orange && a[2][1][0].color[5] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == red && a[2][1][0].color[5] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == red && a[2][1][0].color[5] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == red && a[2][1][2].color[0] == blue && a[2][1][0].color[5] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == green && a[2][1][2].color[0] == orange && a[2][1][0].color[5] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == green && a[2][1][0].color[5] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == orange && a[2][1][0].color[5] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][2][2].color[0] == orange && a[2][1][2].color[0] == blue && a[2][1][0].color[5] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == green && a[2][1][2].color[0] == blue && a[2][1][0].color[5] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][2][2].color[0] == blue && a[2][1][2].color[0] == green && a[2][1][0].color[5] == red) {
//					Rotate(1, 3);
//				}
//			}
//			//собрано 0 наверху, но есть 3 белых кроме правого 
//			if (a[0][1][2].color[4] == white && a[1][0][2].color[2] == white && a[2][0][1].color[2] == white && a[1][2][2].color[3] == white) {
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[2][0][1].color[5] == blue && a[1][2][2].color[0] == orange) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[2][0][1].color[5] == blue && a[1][2][2].color[0] == red) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[2][0][1].color[5] == blue && a[1][2][2].color[0] == green) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[2][0][1].color[5] == blue && a[1][2][2].color[0] == red) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[2][0][1].color[5] == blue && a[1][2][2].color[0] == orange) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[2][0][1].color[5] == blue && a[1][2][2].color[0] == green) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[2][0][1].color[5] == red && a[1][2][2].color[0] == orange) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[2][0][1].color[5] == red && a[1][2][2].color[0] == blue) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[2][0][1].color[5] == red && a[1][2][2].color[0] == green) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[2][0][1].color[5] == red && a[1][2][2].color[0] == blue) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[2][0][1].color[5] == red && a[1][2][2].color[0] == orange) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[2][0][1].color[5] == red && a[1][2][2].color[0] == green) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[2][0][1].color[5] == orange && a[1][2][2].color[0] == red) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[2][0][1].color[5] == orange && a[1][2][2].color[0] == blue) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[2][0][1].color[5] == orange && a[1][2][2].color[0] == green) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[2][0][1].color[5] == orange && a[1][2][2].color[0] == blue) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[2][0][1].color[5] == orange && a[1][2][2].color[0] == red) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[2][0][1].color[5] == orange && a[1][2][2].color[0] == green) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[2][0][1].color[5] == green && a[1][2][2].color[0] == orange) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[2][0][1].color[5] == green && a[1][2][2].color[0] == blue) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[2][0][1].color[5] == green && a[1][2][2].color[0] == red) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[2][0][1].color[5] == green && a[1][2][2].color[0] == blue) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[2][0][1].color[5] == green && a[1][2][2].color[0] == orange) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[2][0][1].color[5] == green && a[1][2][2].color[0] == red) {
//					Rotate(5, -3);
//				}
//			}
//			if (a[0][1][2].color[4] == white && a[1][0][2].color[2] == white && a[2][0][1].color[5] == white && a[1][2][2].color[3] == white) {
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[2][0][1].color[2] == blue && a[1][2][2].color[0] == orange) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[2][0][1].color[2] == blue && a[1][2][2].color[0] == red) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[2][0][1].color[2] == blue && a[1][2][2].color[0] == green) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[2][0][1].color[2] == blue && a[1][2][2].color[0] == red) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[2][0][1].color[2] == blue && a[1][2][2].color[0] == orange) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[2][0][1].color[2] == blue && a[1][2][2].color[0] == green) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[2][0][1].color[2] == red && a[1][2][2].color[0] == orange) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[2][0][1].color[2] == red && a[1][2][2].color[0] == blue) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[2][0][1].color[2] == red && a[1][2][2].color[0] == green) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[2][0][1].color[2] == red && a[1][2][2].color[0] == blue) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[2][0][1].color[2] == red && a[1][2][2].color[0] == orange) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[2][0][1].color[2] == red && a[1][2][2].color[0] == green) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[2][0][1].color[2] == orange && a[1][2][2].color[0] == red) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[2][0][1].color[2] == orange && a[1][2][2].color[0] == blue) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[2][0][1].color[2] == orange && a[1][2][2].color[0] == green) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[2][0][1].color[2] == orange && a[1][2][2].color[0] == blue) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[2][0][1].color[2] == orange && a[1][2][2].color[0] == red) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[2][0][1].color[2] == orange && a[1][2][2].color[0] == green) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[2][0][1].color[2] == green && a[1][2][2].color[0] == orange) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[2][0][1].color[2] == green && a[1][2][2].color[0] == blue) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[2][0][1].color[2] == green && a[1][2][2].color[0] == red) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[2][0][1].color[2] == green && a[1][2][2].color[0] == blue) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[2][0][1].color[2] == green && a[1][2][2].color[0] == orange) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[2][0][1].color[2] == green && a[1][2][2].color[0] == red) {
//					Rotate(5, -3);
//				}
//			}
//			if (a[0][1][2].color[4] == white && a[1][0][2].color[2] == white && a[1][0][0].color[2] == white && a[1][2][2].color[3] == white) {
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[1][0][0].color[1] == blue && a[1][2][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[1][0][0].color[1] == blue && a[1][2][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[1][0][0].color[1] == blue && a[1][2][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[1][0][0].color[1] == blue && a[1][2][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[1][0][0].color[1] == blue && a[1][2][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[1][0][0].color[1] == blue && a[1][2][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[1][0][0].color[1] == red && a[1][2][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[1][0][0].color[1] == red && a[1][2][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[1][0][0].color[1] == red && a[1][2][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[1][0][0].color[1] == red && a[1][2][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[1][0][0].color[1] == red && a[1][2][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[1][0][0].color[1] == red && a[1][2][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[1][0][0].color[1] == orange && a[1][2][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[1][0][0].color[1] == orange && a[1][2][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[1][0][0].color[1] == orange && a[1][2][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[1][0][0].color[1] == orange && a[1][2][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[1][0][0].color[1] == orange && a[1][2][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[1][0][0].color[1] == orange && a[1][2][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[1][0][0].color[1] == green && a[1][2][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[1][0][0].color[1] == green && a[1][2][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[1][0][0].color[1] == green && a[1][2][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[1][0][0].color[1] == green && a[1][2][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[1][0][0].color[1] == green && a[1][2][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[1][0][0].color[1] == green && a[1][2][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//			}
//			if (a[0][1][2].color[4] == white && a[1][0][2].color[2] == white && a[1][0][0].color[1] == white && a[1][2][2].color[3] == white) {
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[1][0][0].color[2] == blue && a[1][2][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[1][0][0].color[2] == blue && a[1][2][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[1][0][0].color[2] == blue && a[1][2][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[1][0][0].color[2] == blue && a[1][2][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[1][0][0].color[2] == blue && a[1][2][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[1][0][0].color[2] == blue && a[1][2][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[1][0][0].color[2] == red && a[1][2][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[1][0][0].color[2] == red && a[1][2][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[1][0][0].color[2] == red && a[1][2][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[1][0][0].color[2] == red && a[1][2][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[1][0][0].color[2] == red && a[1][2][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[1][0][0].color[2] == red && a[1][2][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[1][0][0].color[2] == orange && a[1][2][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[1][0][0].color[2] == orange && a[1][2][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[1][0][0].color[2] == orange && a[1][2][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[1][0][0].color[2] == orange && a[1][2][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[1][0][0].color[2] == orange && a[1][2][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[1][0][0].color[2] == orange && a[1][2][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[1][0][0].color[2] == green && a[1][2][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[1][0][0].color[2] == green && a[1][2][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[1][0][0].color[2] == green && a[1][2][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[1][0][0].color[2] == green && a[1][2][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[1][0][0].color[2] == green && a[1][2][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[1][0][0].color[2] == green && a[1][2][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//			}
//			if (a[0][1][2].color[4] == white && a[1][0][2].color[2] == white && a[0][0][1].color[2] == white && a[1][2][2].color[3] == white) {
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[0][0][1].color[4] == blue && a[1][2][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[0][0][1].color[4] == blue && a[1][2][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[0][0][1].color[4] == blue && a[1][2][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[0][0][1].color[4] == blue && a[1][2][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[0][0][1].color[4] == blue && a[1][2][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[0][0][1].color[4] == blue && a[1][2][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[0][0][1].color[4] == red && a[1][2][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[0][0][1].color[4] == red && a[1][2][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[0][0][1].color[4] == red && a[1][2][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[0][0][1].color[4] == red && a[1][2][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[0][0][1].color[4] == red && a[1][2][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[0][0][1].color[4] == red && a[1][2][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[0][0][1].color[4] == orange && a[1][2][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[0][0][1].color[4] == orange && a[1][2][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[0][0][1].color[4] == orange && a[1][2][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[0][0][1].color[4] == orange && a[1][2][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[0][0][1].color[4] == orange && a[1][2][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[0][0][1].color[4] == orange && a[1][2][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[0][0][1].color[4] == green && a[1][2][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[0][0][1].color[4] == green && a[1][2][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[0][0][1].color[4] == green && a[1][2][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[0][0][1].color[4] == green && a[1][2][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[0][0][1].color[4] == green && a[1][2][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[0][0][1].color[4] == green && a[1][2][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//			}
//			if (a[0][1][2].color[4] == white && a[1][0][2].color[2] == white && a[0][0][1].color[4] == white && a[1][2][2].color[3] == white) {
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[0][0][1].color[2] == blue && a[1][2][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[0][0][1].color[2] == blue && a[1][2][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[0][0][1].color[2] == blue && a[1][2][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[0][0][1].color[2] == blue && a[1][2][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[0][0][1].color[2] == blue && a[1][2][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[0][0][1].color[2] == blue && a[1][2][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[0][0][1].color[2] == red && a[1][2][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[0][0][1].color[2] == red && a[1][2][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[0][0][1].color[2] == red && a[1][2][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[0][0][1].color[2] == red && a[1][2][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[0][0][1].color[2] == red && a[1][2][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[0][0][1].color[2] == red && a[1][2][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[0][0][1].color[2] == orange && a[1][2][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[0][0][1].color[2] == orange && a[1][2][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[0][0][1].color[2] == orange && a[1][2][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[0][0][1].color[2] == orange && a[1][2][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[0][0][1].color[2] == orange && a[1][2][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[0][0][1].color[2] == orange && a[1][2][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[0][0][1].color[2] == green && a[1][2][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[0][0][1].color[2] == green && a[1][2][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[0][0][1].color[2] == green && a[1][2][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[0][0][1].color[2] == green && a[1][2][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[0][0][1].color[2] == green && a[1][2][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[0][0][1].color[2] == green && a[1][2][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//			}
//			if (a[0][1][2].color[4] == white && a[1][0][2].color[2] == white && a[2][2][1].color[3] == white && a[1][2][2].color[3] == white) {
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[2][2][1].color[5] == blue && a[1][2][2].color[0] == orange) {
//					Rotate(5, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[2][2][1].color[5] == blue && a[1][2][2].color[0] == red) {
//					Rotate(5, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[2][2][1].color[5] == blue && a[1][2][2].color[0] == green) {
//					Rotate(5, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[2][2][1].color[5] == blue && a[1][2][2].color[0] == red) {
//					Rotate(5, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[2][2][1].color[5] == blue && a[1][2][2].color[0] == orange) {
//					Rotate(5, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[2][2][1].color[5] == blue && a[1][2][2].color[0] == green) {
//					Rotate(5, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[2][2][1].color[5] == red && a[1][2][2].color[0] == orange) {
//					Rotate(5, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[2][2][1].color[5] == red && a[1][2][2].color[0] == blue) {
//					Rotate(5, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[2][2][1].color[5] == red && a[1][2][2].color[0] == green) {
//					Rotate(5, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[2][2][1].color[5] == red && a[1][2][2].color[0] == blue) {
//					Rotate(5, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[2][2][1].color[5] == red && a[1][2][2].color[0] == orange) {
//					Rotate(5, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[2][2][1].color[5] == red && a[1][2][2].color[0] == green) {
//					Rotate(5, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[2][2][1].color[5] == orange && a[1][2][2].color[0] == red) {
//					Rotate(5, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[2][2][1].color[5] == orange && a[1][2][2].color[0] == blue) {
//					Rotate(5, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[2][2][1].color[5] == orange && a[1][2][2].color[0] == green) {
//					Rotate(5, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[2][2][1].color[5] == orange && a[1][2][2].color[0] == blue) {
//					Rotate(5, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[2][2][1].color[5] == orange && a[1][2][2].color[0] == red) {
//					Rotate(5, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[2][2][1].color[5] == orange && a[1][2][2].color[0] == green) {
//					Rotate(5, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[2][2][1].color[5] == green && a[1][2][2].color[0] == orange) {
//					Rotate(5, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[2][2][1].color[5] == green && a[1][2][2].color[0] == blue) {
//					Rotate(5, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[2][2][1].color[5] == green && a[1][2][2].color[0] == red) {
//					Rotate(5, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[2][2][1].color[5] == green && a[1][2][2].color[0] == blue) {
//					Rotate(5, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[2][2][1].color[5] == green && a[1][2][2].color[0] == orange) {
//					Rotate(5, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[2][2][1].color[5] == green && a[1][2][2].color[0] == red) {
//					Rotate(5, 3);
//				}
//			}
//			if (a[0][1][2].color[4] == white && a[1][0][2].color[2] == white && a[2][2][1].color[5] == white && a[1][2][2].color[3] == white) {
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[2][2][1].color[3] == blue && a[1][2][2].color[0] == orange) {
//					Rotate(5, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[2][2][1].color[3] == blue && a[1][2][2].color[0] == red) {
//					Rotate(5, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[2][2][1].color[3] == blue && a[1][2][2].color[0] == green) {
//					Rotate(5, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[2][2][1].color[3] == blue && a[1][2][2].color[0] == red) {
//					Rotate(5, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[2][2][1].color[3] == blue && a[1][2][2].color[0] == orange) {
//					Rotate(5, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[2][2][1].color[3] == blue && a[1][2][2].color[0] == green) {
//					Rotate(5, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[2][2][1].color[3] == red && a[1][2][2].color[0] == orange) {
//					Rotate(5, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[2][2][1].color[3] == red && a[1][2][2].color[0] == blue) {
//					Rotate(5, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[2][2][1].color[3] == red && a[1][2][2].color[0] == green) {
//					Rotate(5, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[2][2][1].color[3] == red && a[1][2][2].color[0] == blue) {
//					Rotate(5, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[2][2][1].color[3] == red && a[1][2][2].color[0] == orange) {
//					Rotate(5, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[2][2][1].color[3] == red && a[1][2][2].color[0] == green) {
//					Rotate(5, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[2][2][1].color[3] == orange && a[1][2][2].color[0] == red) {
//					Rotate(5, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[2][2][1].color[3] == orange && a[1][2][2].color[0] == blue) {
//					Rotate(5, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[2][2][1].color[3] == orange && a[1][2][2].color[0] == green) {
//					Rotate(5, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[2][2][1].color[3] == orange && a[1][2][2].color[0] == blue) {
//					Rotate(5, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[2][2][1].color[3] == orange && a[1][2][2].color[0] == red) {
//					Rotate(5, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[2][2][1].color[3] == orange && a[1][2][2].color[0] == green) {
//					Rotate(5, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[2][2][1].color[3] == green && a[1][2][2].color[0] == orange) {
//					Rotate(5, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[2][2][1].color[3] == green && a[1][2][2].color[0] == blue) {
//					Rotate(5, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[2][2][1].color[3] == green && a[1][2][2].color[0] == red) {
//					Rotate(5, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[2][2][1].color[3] == green && a[1][2][2].color[0] == blue) {
//					Rotate(5, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[2][2][1].color[3] == green && a[1][2][2].color[0] == orange) {
//					Rotate(5, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[2][2][1].color[3] == green && a[1][2][2].color[0] == red) {
//					Rotate(5, 3);
//				}
//			}
//			if (a[0][1][2].color[4] == white && a[1][0][2].color[2] == white && a[1][2][0].color[3] == white && a[1][2][2].color[3] == white) {
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[1][2][0].color[1] == blue && a[1][2][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[1][2][0].color[1] == blue && a[1][2][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[1][2][0].color[1] == blue && a[1][2][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[1][2][0].color[1] == blue && a[1][2][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[1][2][0].color[1] == blue && a[1][2][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[1][2][0].color[1] == blue && a[1][2][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[1][2][0].color[1] == red && a[1][2][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[1][2][0].color[1] == red && a[1][2][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[1][2][0].color[1] == red && a[1][2][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[1][2][0].color[1] == red && a[1][2][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[1][2][0].color[1] == red && a[1][2][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[1][2][0].color[1] == red && a[1][2][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[1][2][0].color[1] == orange && a[1][2][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[1][2][0].color[1] == orange && a[1][2][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[1][2][0].color[1] == orange && a[1][2][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[1][2][0].color[1] == orange && a[1][2][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[1][2][0].color[1] == orange && a[1][2][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[1][2][0].color[1] == orange && a[1][2][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[1][2][0].color[1] == green && a[1][2][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[1][2][0].color[1] == green && a[1][2][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[1][2][0].color[1] == green && a[1][2][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[1][2][0].color[1] == green && a[1][2][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[1][2][0].color[1] == green && a[1][2][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[1][2][0].color[1] == green && a[1][2][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//			}
//			if (a[0][1][2].color[4] == white && a[1][0][2].color[2] == white && a[1][2][0].color[1] == white && a[1][2][2].color[3] == white) {
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[1][2][0].color[3] == blue && a[1][2][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[1][2][0].color[3] == blue && a[1][2][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[1][2][0].color[3] == blue && a[1][2][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[1][2][0].color[3] == blue && a[1][2][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[1][2][0].color[3] == blue && a[1][2][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[1][2][0].color[3] == blue && a[1][2][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[1][2][0].color[3] == red && a[1][2][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[1][2][0].color[3] == red && a[1][2][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[1][2][0].color[3] == red && a[1][2][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[1][2][0].color[3] == red && a[1][2][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[1][2][0].color[3] == red && a[1][2][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[1][2][0].color[3] == red && a[1][2][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[1][2][0].color[3] == orange && a[1][2][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[1][2][0].color[3] == orange && a[1][2][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[1][2][0].color[3] == orange && a[1][2][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[1][2][0].color[3] == orange && a[1][2][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[1][2][0].color[3] == orange && a[1][2][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[1][2][0].color[3] == orange && a[1][2][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[1][2][0].color[3] == green && a[1][2][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[1][2][0].color[3] == green && a[1][2][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[1][2][0].color[3] == green && a[1][2][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[1][2][0].color[3] == green && a[1][2][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[1][2][0].color[3] == green && a[1][2][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[1][2][0].color[3] == green && a[1][2][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//			}
//			if (a[0][1][2].color[4] == white && a[1][0][2].color[2] == white && a[0][2][1].color[3] == white && a[1][2][2].color[3] == white) {
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[0][2][1].color[4] == blue && a[1][2][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[0][2][1].color[4] == blue && a[1][2][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[0][2][1].color[4] == blue && a[1][2][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[0][2][1].color[4] == blue && a[1][2][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[0][2][1].color[4] == blue && a[1][2][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[0][2][1].color[4] == blue && a[1][2][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[0][2][1].color[4] == red && a[1][2][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[0][2][1].color[4] == red && a[1][2][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[0][2][1].color[4] == red && a[1][2][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[0][2][1].color[4] == red && a[1][2][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[0][2][1].color[4] == red && a[1][2][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[0][2][1].color[4] == red && a[1][2][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[0][2][1].color[4] == orange && a[1][2][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[0][2][1].color[4] == orange && a[1][2][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[0][2][1].color[4] == orange && a[1][2][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[0][2][1].color[4] == orange && a[1][2][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[0][2][1].color[4] == orange && a[1][2][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[0][2][1].color[4] == orange && a[1][2][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[0][2][1].color[4] == green && a[1][2][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[0][2][1].color[4] == green && a[1][2][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[0][2][1].color[4] == green && a[1][2][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[0][2][1].color[4] == green && a[1][2][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[0][2][1].color[4] == green && a[1][2][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[0][2][1].color[4] == green && a[1][2][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//			}
//			if (a[0][1][2].color[4] == white && a[1][0][2].color[2] == white && a[0][2][1].color[4] == white && a[1][2][2].color[3] == white) {
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[0][2][1].color[3] == blue && a[1][2][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[0][2][1].color[3] == blue && a[1][2][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[0][2][1].color[3] == blue && a[1][2][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[0][2][1].color[3] == blue && a[1][2][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[0][2][1].color[3] == blue && a[1][2][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[0][2][1].color[3] == blue && a[1][2][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[0][2][1].color[3] == red && a[1][2][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[0][2][1].color[3] == red && a[1][2][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[0][2][1].color[3] == red && a[1][2][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[0][2][1].color[3] == red && a[1][2][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[0][2][1].color[3] == red && a[1][2][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[0][2][1].color[3] == red && a[1][2][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[0][2][1].color[3] == orange && a[1][2][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[0][2][1].color[3] == orange && a[1][2][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[0][2][1].color[3] == orange && a[1][2][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[0][2][1].color[3] == orange && a[1][2][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[0][2][1].color[3] == orange && a[1][2][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[0][2][1].color[3] == orange && a[1][2][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[0][2][1].color[3] == green && a[1][2][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[0][2][1].color[3] == green && a[1][2][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[0][2][1].color[3] == green && a[1][2][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[0][2][1].color[3] == green && a[1][2][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[0][2][1].color[3] == green && a[1][2][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[0][2][1].color[3] == green && a[1][2][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//			}
//			if (a[0][1][2].color[4] == white && a[1][0][2].color[2] == white && a[0][1][0].color[1] == white && a[1][2][2].color[3] == white) {
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[0][1][0].color[4] == blue && a[1][2][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[0][1][0].color[4] == blue && a[1][2][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[0][1][0].color[4] == blue && a[1][2][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[0][1][0].color[4] == blue && a[1][2][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[0][1][0].color[4] == blue && a[1][2][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[0][1][0].color[4] == blue && a[1][2][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[0][1][0].color[4] == red && a[1][2][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[0][1][0].color[4] == red && a[1][2][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[0][1][0].color[4] == red && a[1][2][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[0][1][0].color[4] == red && a[1][2][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[0][1][0].color[4] == red && a[1][2][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[0][1][0].color[4] == red && a[1][2][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[0][1][0].color[4] == orange && a[1][2][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[0][1][0].color[4] == orange && a[1][2][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[0][1][0].color[4] == orange && a[1][2][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[0][1][0].color[4] == orange && a[1][2][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[0][1][0].color[4] == orange && a[1][2][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[0][1][0].color[4] == orange && a[1][2][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[0][1][0].color[4] == green && a[1][2][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[0][1][0].color[4] == green && a[1][2][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[0][1][0].color[4] == green && a[1][2][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[0][1][0].color[4] == green && a[1][2][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[0][1][0].color[4] == green && a[1][2][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[0][1][0].color[4] == green && a[1][2][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//			}
//			if (a[0][1][2].color[4] == white && a[1][0][2].color[2] == white && a[0][1][0].color[4] == white && a[1][2][2].color[3] == white) {
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[0][1][0].color[1] == blue && a[1][2][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[0][1][0].color[1] == blue && a[1][2][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[0][1][0].color[1] == blue && a[1][2][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[0][1][0].color[1] == blue && a[1][2][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[0][1][0].color[1] == blue && a[1][2][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[0][1][0].color[1] == blue && a[1][2][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[0][1][0].color[1] == red && a[1][2][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[0][1][0].color[1] == red && a[1][2][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[0][1][0].color[1] == red && a[1][2][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[0][1][0].color[1] == red && a[1][2][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[0][1][0].color[1] == red && a[1][2][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[0][1][0].color[1] == red && a[1][2][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[0][1][0].color[1] == orange && a[1][2][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[0][1][0].color[1] == orange && a[1][2][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[0][1][0].color[1] == orange && a[1][2][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[0][1][0].color[1] == orange && a[1][2][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[0][1][0].color[1] == orange && a[1][2][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[0][1][0].color[1] == orange && a[1][2][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[0][1][0].color[1] == green && a[1][2][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[0][1][0].color[1] == green && a[1][2][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[0][1][0].color[1] == green && a[1][2][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[0][1][0].color[1] == green && a[1][2][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[0][1][0].color[1] == green && a[1][2][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[0][1][0].color[1] == green && a[1][2][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//			}
//			if (a[0][1][2].color[4] == white && a[1][0][2].color[2] == white && a[2][1][0].color[1] == white && a[1][2][2].color[3] == white) {
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[2][1][0].color[5] == blue && a[1][2][2].color[0] == orange) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[2][1][0].color[5] == blue && a[1][2][2].color[0] == red) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[2][1][0].color[5] == blue && a[1][2][2].color[0] == green) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[2][1][0].color[5] == blue && a[1][2][2].color[0] == red) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[2][1][0].color[5] == blue && a[1][2][2].color[0] == orange) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[2][1][0].color[5] == blue && a[1][2][2].color[0] == green) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[2][1][0].color[5] == red && a[1][2][2].color[0] == orange) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[2][1][0].color[5] == red && a[1][2][2].color[0] == blue) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[2][1][0].color[5] == red && a[1][2][2].color[0] == green) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[2][1][0].color[5] == red && a[1][2][2].color[0] == blue) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[2][1][0].color[5] == red && a[1][2][2].color[0] == orange) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[2][1][0].color[5] == red && a[1][2][2].color[0] == green) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[2][1][0].color[5] == orange && a[1][2][2].color[0] == red) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[2][1][0].color[5] == orange && a[1][2][2].color[0] == blue) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[2][1][0].color[5] == orange && a[1][2][2].color[0] == green) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[2][1][0].color[5] == orange && a[1][2][2].color[0] == blue) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[2][1][0].color[5] == orange && a[1][2][2].color[0] == red) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[2][1][0].color[5] == orange && a[1][2][2].color[0] == green) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[2][1][0].color[5] == green && a[1][2][2].color[0] == orange) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[2][1][0].color[5] == green && a[1][2][2].color[0] == blue) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[2][1][0].color[5] == green && a[1][2][2].color[0] == red) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[2][1][0].color[5] == green && a[1][2][2].color[0] == blue) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[2][1][0].color[5] == green && a[1][2][2].color[0] == orange) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[2][1][0].color[5] == green && a[1][2][2].color[0] == red) {
//					Rotate(5, -3);
//				}
//			}
//			if (a[0][1][2].color[4] == white && a[1][0][2].color[2] == white && a[2][1][0].color[5] == white && a[1][2][2].color[3] == white) {
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[2][1][0].color[1] == blue && a[1][2][2].color[0] == orange) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[2][1][0].color[1] == blue && a[1][2][2].color[0] == red) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[2][1][0].color[1] == blue && a[1][2][2].color[0] == green) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[2][1][0].color[1] == blue && a[1][2][2].color[0] == red) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[2][1][0].color[1] == blue && a[1][2][2].color[0] == orange) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[2][1][0].color[1] == blue && a[1][2][2].color[0] == green) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[2][1][0].color[1] == red && a[1][2][2].color[0] == orange) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[2][1][0].color[1] == red && a[1][2][2].color[0] == blue) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[2][1][0].color[1] == red && a[1][2][2].color[0] == green) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[2][1][0].color[1] == red && a[1][2][2].color[0] == blue) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[2][1][0].color[1] == red && a[1][2][2].color[0] == orange) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[2][1][0].color[1] == red && a[1][2][2].color[0] == green) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[2][1][0].color[1] == orange && a[1][2][2].color[0] == red) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[2][1][0].color[1] == orange && a[1][2][2].color[0] == blue) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[2][1][0].color[1] == orange && a[1][2][2].color[0] == green) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[2][1][0].color[1] == orange && a[1][2][2].color[0] == blue) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[2][1][0].color[1] == orange && a[1][2][2].color[0] == red) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[2][1][0].color[1] == orange && a[1][2][2].color[0] == green) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[2][1][0].color[1] == green && a[1][2][2].color[0] == orange) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[2][1][0].color[1] == green && a[1][2][2].color[0] == blue) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[2][1][0].color[1] == green && a[1][2][2].color[0] == red) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[2][1][0].color[1] == green && a[1][2][2].color[0] == blue) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[2][1][0].color[1] == green && a[1][2][2].color[0] == orange) {
//					Rotate(5, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[2][1][0].color[1] == green && a[1][2][2].color[0] == red) {
//					Rotate(5, -3);
//				}
//			}
//			//собрано 0 наверху, но есть 3 белых кроме левого 
//			if (a[2][1][2].color[5] == white && a[1][0][2].color[2] == white && a[2][0][1].color[2] == white && a[1][2][2].color[3] == white) {
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == red && a[2][0][1].color[5] == blue && a[1][2][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[2][0][1].color[5] == blue && a[1][2][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[2][0][1].color[5] == blue && a[1][2][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[2][0][1].color[5] == blue && a[1][2][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == green && a[2][0][1].color[5] == blue && a[1][2][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[2][0][1].color[5] == blue && a[1][2][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[2][0][1].color[5] == red && a[1][2][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[2][0][1].color[5] == red && a[1][2][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[2][0][1].color[5] == red && a[1][2][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[2][0][1].color[5] == red && a[1][2][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[2][0][1].color[5] == red && a[1][2][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[2][0][1].color[5] == red && a[1][2][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[2][0][1].color[5] == orange && a[1][2][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == red && a[2][0][1].color[5] == orange && a[1][2][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[2][0][1].color[5] == orange && a[1][2][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == green && a[2][0][1].color[5] == orange && a[1][2][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[2][0][1].color[5] == orange && a[1][2][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[2][0][1].color[5] == orange && a[1][2][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[2][0][1].color[5] == green && a[1][2][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[2][0][1].color[5] == green && a[1][2][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[2][0][1].color[5] == green && a[1][2][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[2][0][1].color[5] == green && a[1][2][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[2][0][1].color[5] == green && a[1][2][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[2][0][1].color[5] == green && a[1][2][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//			}
//			if (a[2][1][2].color[5] == white && a[1][0][2].color[2] == white && a[2][0][1].color[5] == white && a[1][2][2].color[3] == white) {
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == red && a[2][0][1].color[2] == blue && a[1][2][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[2][0][1].color[2] == blue && a[1][2][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[2][0][1].color[2] == blue && a[1][2][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[2][0][1].color[2] == blue && a[1][2][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == green && a[2][0][1].color[2] == blue && a[1][2][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[2][0][1].color[2] == blue && a[1][2][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[2][0][1].color[2] == red && a[1][2][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[2][0][1].color[2] == red && a[1][2][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[2][0][1].color[2] == red && a[1][2][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[2][0][1].color[2] == red && a[1][2][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[2][0][1].color[2] == red && a[1][2][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[2][0][1].color[2] == red && a[1][2][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[2][0][1].color[2] == orange && a[1][2][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == red && a[2][0][1].color[2] == orange && a[1][2][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[2][0][1].color[2] == orange && a[1][2][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == green && a[2][0][1].color[2] == orange && a[1][2][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[2][0][1].color[2] == orange && a[1][2][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[2][0][1].color[2] == orange && a[1][2][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[2][0][1].color[2] == green && a[1][2][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[2][0][1].color[2] == green && a[1][2][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[2][0][1].color[2] == green && a[1][2][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[2][0][1].color[2] == green && a[1][2][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[2][0][1].color[2] == green && a[1][2][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[2][0][1].color[2] == green && a[1][2][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//			}
//			if (a[2][1][2].color[5] == white && a[1][0][2].color[2] == white && a[1][0][0].color[2] == white && a[1][2][2].color[3] == white) {
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == red && a[1][0][0].color[1] == blue && a[1][2][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[1][0][0].color[1] == blue && a[1][2][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[1][0][0].color[1] == blue && a[1][2][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[1][0][0].color[1] == blue && a[1][2][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == green && a[1][0][0].color[1] == blue && a[1][2][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[1][0][0].color[1] == blue && a[1][2][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[1][0][0].color[1] == red && a[1][2][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[1][0][0].color[1] == red && a[1][2][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[1][0][0].color[1] == red && a[1][2][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[1][0][0].color[1] == red && a[1][2][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[1][0][0].color[1] == red && a[1][2][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[1][0][0].color[1] == red && a[1][2][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[1][0][0].color[1] == orange && a[1][2][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == red && a[1][0][0].color[1] == orange && a[1][2][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[1][0][0].color[1] == orange && a[1][2][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == green && a[1][0][0].color[1] == orange && a[1][2][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[1][0][0].color[1] == orange && a[1][2][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[1][0][0].color[1] == orange && a[1][2][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[1][0][0].color[1] == green && a[1][2][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[1][0][0].color[1] == green && a[1][2][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[1][0][0].color[1] == green && a[1][2][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[1][0][0].color[1] == green && a[1][2][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[1][0][0].color[1] == green && a[1][2][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[1][0][0].color[1] == green && a[1][2][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//			}
//			if (a[2][1][2].color[5] == white && a[1][0][2].color[2] == white && a[1][0][0].color[1] == white && a[1][2][2].color[3] == white) {
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == red && a[1][0][0].color[2] == blue && a[1][2][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[1][0][0].color[2] == blue && a[1][2][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[1][0][0].color[2] == blue && a[1][2][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[1][0][0].color[2] == blue && a[1][2][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == green && a[1][0][0].color[2] == blue && a[1][2][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[1][0][0].color[2] == blue && a[1][2][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[1][0][0].color[2] == red && a[1][2][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[1][0][0].color[2] == red && a[1][2][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[1][0][0].color[2] == red && a[1][2][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[1][0][0].color[2] == red && a[1][2][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[1][0][0].color[2] == red && a[1][2][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[1][0][0].color[2] == red && a[1][2][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[1][0][0].color[2] == orange && a[1][2][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == red && a[1][0][0].color[2] == orange && a[1][2][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[1][0][0].color[2] == orange && a[1][2][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == green && a[1][0][0].color[2] == orange && a[1][2][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[1][0][0].color[2] == orange && a[1][2][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[1][0][0].color[2] == orange && a[1][2][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[1][0][0].color[2] == green && a[1][2][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[1][0][0].color[2] == green && a[1][2][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[1][0][0].color[2] == green && a[1][2][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[1][0][0].color[2] == green && a[1][2][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[1][0][0].color[2] == green && a[1][2][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[1][0][0].color[2] == green && a[1][2][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//			}
//			if (a[2][1][2].color[5] == white && a[1][0][2].color[2] == white && a[0][0][1].color[2] == white && a[1][2][2].color[3] == white) {
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == red && a[0][0][1].color[4] == blue && a[1][2][2].color[0] == orange) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[0][0][1].color[4] == blue && a[1][2][2].color[0] == red) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[0][0][1].color[4] == blue && a[1][2][2].color[0] == green) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[0][0][1].color[4] == blue && a[1][2][2].color[0] == red) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == green && a[0][0][1].color[4] == blue && a[1][2][2].color[0] == orange) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[0][0][1].color[4] == blue && a[1][2][2].color[0] == green) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[0][0][1].color[4] == red && a[1][2][2].color[0] == orange) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[0][0][1].color[4] == red && a[1][2][2].color[0] == blue) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[0][0][1].color[4] == red && a[1][2][2].color[0] == green) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[0][0][1].color[4] == red && a[1][2][2].color[0] == blue) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[0][0][1].color[4] == red && a[1][2][2].color[0] == orange) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[0][0][1].color[4] == red && a[1][2][2].color[0] == green) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[0][0][1].color[4] == orange && a[1][2][2].color[0] == red) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == red && a[0][0][1].color[4] == orange && a[1][2][2].color[0] == blue) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[0][0][1].color[4] == orange && a[1][2][2].color[0] == green) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == green && a[0][0][1].color[4] == orange && a[1][2][2].color[0] == blue) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[0][0][1].color[4] == orange && a[1][2][2].color[0] == red) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[0][0][1].color[4] == orange && a[1][2][2].color[0] == green) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[0][0][1].color[4] == green && a[1][2][2].color[0] == orange) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[0][0][1].color[4] == green && a[1][2][2].color[0] == blue) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[0][0][1].color[4] == green && a[1][2][2].color[0] == red) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[0][0][1].color[4] == green && a[1][2][2].color[0] == blue) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[0][0][1].color[4] == green && a[1][2][2].color[0] == orange) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[0][0][1].color[4] == green && a[1][2][2].color[0] == red) {
//					Rotate(4, -3);
//				}
//			}
//			if (a[2][1][2].color[5] == white && a[1][0][2].color[2] == white && a[0][0][1].color[4] == white && a[1][2][2].color[3] == white) {
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == red && a[0][0][1].color[2] == blue && a[1][2][2].color[0] == orange) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[0][0][1].color[2] == blue && a[1][2][2].color[0] == red) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[0][0][1].color[2] == blue && a[1][2][2].color[0] == green) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[0][0][1].color[2] == blue && a[1][2][2].color[0] == red) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == green && a[0][0][1].color[2] == blue && a[1][2][2].color[0] == orange) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[0][0][1].color[2] == blue && a[1][2][2].color[0] == green) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[0][0][1].color[2] == red && a[1][2][2].color[0] == orange) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[0][0][1].color[2] == red && a[1][2][2].color[0] == blue) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[0][0][1].color[2] == red && a[1][2][2].color[0] == green) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[0][0][1].color[2] == red && a[1][2][2].color[0] == blue) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[0][0][1].color[2] == red && a[1][2][2].color[0] == orange) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[0][0][1].color[2] == red && a[1][2][2].color[0] == green) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[0][0][1].color[2] == orange && a[1][2][2].color[0] == red) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == red && a[0][0][1].color[2] == orange && a[1][2][2].color[0] == blue) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[0][0][1].color[2] == orange && a[1][2][2].color[0] == green) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == green && a[0][0][1].color[2] == orange && a[1][2][2].color[0] == blue) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[0][0][1].color[2] == orange && a[1][2][2].color[0] == red) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[0][0][1].color[2] == orange && a[1][2][2].color[0] == green) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[0][0][1].color[2] == green && a[1][2][2].color[0] == orange) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[0][0][1].color[2] == green && a[1][2][2].color[0] == blue) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[0][0][1].color[2] == green && a[1][2][2].color[0] == red) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[0][0][1].color[2] == green && a[1][2][2].color[0] == blue) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[0][0][1].color[2] == green && a[1][2][2].color[0] == orange) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[0][0][1].color[2] == green && a[1][2][2].color[0] == red) {
//					Rotate(4, -3);
//				}
//			}
//			if (a[2][1][2].color[5] == white && a[1][0][2].color[2] == white && a[2][2][1].color[3] == white && a[1][2][2].color[3] == white) {
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == red && a[2][2][1].color[5] == blue && a[1][2][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[2][2][1].color[5] == blue && a[1][2][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[2][2][1].color[5] == blue && a[1][2][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[2][2][1].color[5] == blue && a[1][2][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == green && a[2][2][1].color[5] == blue && a[1][2][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[2][2][1].color[5] == blue && a[1][2][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[2][2][1].color[5] == red && a[1][2][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[2][2][1].color[5] == red && a[1][2][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[2][2][1].color[5] == red && a[1][2][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[2][2][1].color[5] == red && a[1][2][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[2][2][1].color[5] == red && a[1][2][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[2][2][1].color[5] == red && a[1][2][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[2][2][1].color[5] == orange && a[1][2][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == red && a[2][2][1].color[5] == orange && a[1][2][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[2][2][1].color[5] == orange && a[1][2][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == green && a[2][2][1].color[5] == orange && a[1][2][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[2][2][1].color[5] == orange && a[1][2][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[2][2][1].color[5] == orange && a[1][2][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[2][2][1].color[5] == green && a[1][2][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[2][2][1].color[5] == green && a[1][2][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[2][2][1].color[5] == green && a[1][2][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[2][2][1].color[5] == green && a[1][2][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[2][2][1].color[5] == green && a[1][2][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[2][2][1].color[5] == green && a[1][2][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//			}
//			if (a[2][1][2].color[5] == white && a[1][0][2].color[2] == white && a[2][2][1].color[5] == white && a[1][2][2].color[3] == white) {
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == red && a[2][2][1].color[3] == blue && a[1][2][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[2][2][1].color[3] == blue && a[1][2][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[2][2][1].color[3] == blue && a[1][2][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[2][2][1].color[3] == blue && a[1][2][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == green && a[2][2][1].color[3] == blue && a[1][2][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[2][2][1].color[3] == blue && a[1][2][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[2][2][1].color[3] == red && a[1][2][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[2][2][1].color[3] == red && a[1][2][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[2][2][1].color[3] == red && a[1][2][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[2][2][1].color[3] == red && a[1][2][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[2][2][1].color[3] == red && a[1][2][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[2][2][1].color[3] == red && a[1][2][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[2][2][1].color[3] == orange && a[1][2][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == red && a[2][2][1].color[3] == orange && a[1][2][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[2][2][1].color[3] == orange && a[1][2][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == green && a[2][2][1].color[3] == orange && a[1][2][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[2][2][1].color[3] == orange && a[1][2][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[2][2][1].color[3] == orange && a[1][2][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[2][2][1].color[3] == green && a[1][2][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[2][2][1].color[3] == green && a[1][2][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[2][2][1].color[3] == green && a[1][2][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[2][2][1].color[3] == green && a[1][2][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[2][2][1].color[3] == green && a[1][2][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[2][2][1].color[3] == green && a[1][2][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//			}
//			if (a[2][1][2].color[5] == white && a[1][0][2].color[2] == white && a[1][2][0].color[3] == white && a[1][2][2].color[3] == white) {
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == red && a[1][2][0].color[1] == blue && a[1][2][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[1][2][0].color[1] == blue && a[1][2][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[1][2][0].color[1] == blue && a[1][2][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[1][2][0].color[1] == blue && a[1][2][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == green && a[1][2][0].color[1] == blue && a[1][2][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[1][2][0].color[1] == blue && a[1][2][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[1][2][0].color[1] == red && a[1][2][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[1][2][0].color[1] == red && a[1][2][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[1][2][0].color[1] == red && a[1][2][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[1][2][0].color[1] == red && a[1][2][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[1][2][0].color[1] == red && a[1][2][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[1][2][0].color[1] == red && a[1][2][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[1][2][0].color[1] == orange && a[1][2][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == red && a[1][2][0].color[1] == orange && a[1][2][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[1][2][0].color[1] == orange && a[1][2][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == green && a[1][2][0].color[1] == orange && a[1][2][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[1][2][0].color[1] == orange && a[1][2][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[1][2][0].color[1] == orange && a[1][2][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[1][2][0].color[1] == green && a[1][2][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[1][2][0].color[1] == green && a[1][2][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[1][2][0].color[1] == green && a[1][2][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[1][2][0].color[1] == green && a[1][2][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[1][2][0].color[1] == green && a[1][2][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[1][2][0].color[1] == green && a[1][2][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//			}
//			if (a[2][1][2].color[5] == white && a[1][0][2].color[2] == white && a[1][2][0].color[1] == white && a[1][2][2].color[3] == white) {
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == red && a[1][2][0].color[3] == blue && a[1][2][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[1][2][0].color[3] == blue && a[1][2][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[1][2][0].color[3] == blue && a[1][2][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[1][2][0].color[3] == blue && a[1][2][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == green && a[1][2][0].color[3] == blue && a[1][2][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[1][2][0].color[3] == blue && a[1][2][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[1][2][0].color[3] == red && a[1][2][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[1][2][0].color[3] == red && a[1][2][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[1][2][0].color[3] == red && a[1][2][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[1][2][0].color[3] == red && a[1][2][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[1][2][0].color[3] == red && a[1][2][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[1][2][0].color[3] == red && a[1][2][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[1][2][0].color[3] == orange && a[1][2][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == red && a[1][2][0].color[3] == orange && a[1][2][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[1][2][0].color[3] == orange && a[1][2][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == green && a[1][2][0].color[3] == orange && a[1][2][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[1][2][0].color[3] == orange && a[1][2][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[1][2][0].color[3] == orange && a[1][2][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[1][2][0].color[3] == green && a[1][2][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[1][2][0].color[3] == green && a[1][2][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[1][2][0].color[3] == green && a[1][2][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[1][2][0].color[3] == green && a[1][2][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[1][2][0].color[3] == green && a[1][2][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[1][2][0].color[3] == green && a[1][2][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//			}
//			if (a[2][1][2].color[5] == white && a[1][0][2].color[2] == white && a[0][2][1].color[3] == white && a[1][2][2].color[3] == white) {
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == red && a[0][2][1].color[4] == blue && a[1][2][2].color[0] == orange) {
//					Rotate(4, 3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[0][2][1].color[4] == blue && a[1][2][2].color[0] == red) {
//					Rotate(4, 3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[0][2][1].color[4] == blue && a[1][2][2].color[0] == green) {
//					Rotate(4, 3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[0][2][1].color[4] == blue && a[1][2][2].color[0] == red) {
//					Rotate(4, 3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == green && a[0][2][1].color[4] == blue && a[1][2][2].color[0] == orange) {
//					Rotate(4, 3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[0][2][1].color[4] == blue && a[1][2][2].color[0] == green) {
//					Rotate(4, 3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[0][2][1].color[4] == red && a[1][2][2].color[0] == orange) {
//					Rotate(4, 3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[0][2][1].color[4] == red && a[1][2][2].color[0] == blue) {
//					Rotate(4, 3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[0][2][1].color[4] == red && a[1][2][2].color[0] == green) {
//					Rotate(4, 3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[0][2][1].color[4] == red && a[1][2][2].color[0] == blue) {
//					Rotate(4, 3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[0][2][1].color[4] == red && a[1][2][2].color[0] == orange) {
//					Rotate(4, 3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[0][2][1].color[4] == red && a[1][2][2].color[0] == green) {
//					Rotate(4, 3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[0][2][1].color[4] == orange && a[1][2][2].color[0] == red) {
//					Rotate(4, 3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == red && a[0][2][1].color[4] == orange && a[1][2][2].color[0] == blue) {
//					Rotate(4, 3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[0][2][1].color[4] == orange && a[1][2][2].color[0] == green) {
//					Rotate(4, 3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == green && a[0][2][1].color[4] == orange && a[1][2][2].color[0] == blue) {
//					Rotate(4, 3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[0][2][1].color[4] == orange && a[1][2][2].color[0] == red) {
//					Rotate(4, 3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[0][2][1].color[4] == orange && a[1][2][2].color[0] == green) {
//					Rotate(4, 3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[0][2][1].color[4] == green && a[1][2][2].color[0] == orange) {
//					Rotate(4, 3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[0][2][1].color[4] == green && a[1][2][2].color[0] == blue) {
//					Rotate(4, 3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[0][2][1].color[4] == green && a[1][2][2].color[0] == red) {
//					Rotate(4, 3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[0][2][1].color[4] == green && a[1][2][2].color[0] == blue) {
//					Rotate(4, 3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[0][2][1].color[4] == green && a[1][2][2].color[0] == orange) {
//					Rotate(4, 3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[0][2][1].color[4] == green && a[1][2][2].color[0] == red) {
//					Rotate(4, 3);
//				}
//			}
//			if (a[2][1][2].color[5] == white && a[1][0][2].color[2] == white && a[0][2][1].color[4] == white && a[1][2][2].color[3] == white) {
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == red && a[0][2][1].color[3] == blue && a[1][2][2].color[0] == orange) {
//					Rotate(4, 3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[0][2][1].color[3] == blue && a[1][2][2].color[0] == red) {
//					Rotate(4, 3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[0][2][1].color[3] == blue && a[1][2][2].color[0] == green) {
//					Rotate(4, 3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[0][2][1].color[3] == blue && a[1][2][2].color[0] == red) {
//					Rotate(4, 3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == green && a[0][2][1].color[3] == blue && a[1][2][2].color[0] == orange) {
//					Rotate(4, 3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[0][2][1].color[3] == blue && a[1][2][2].color[0] == green) {
//					Rotate(4, 3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[0][2][1].color[3] == red && a[1][2][2].color[0] == orange) {
//					Rotate(4, 3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[0][2][1].color[3] == red && a[1][2][2].color[0] == blue) {
//					Rotate(4, 3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[0][2][1].color[3] == red && a[1][2][2].color[0] == green) {
//					Rotate(4, 3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[0][2][1].color[3] == red && a[1][2][2].color[0] == blue) {
//					Rotate(4, 3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[0][2][1].color[3] == red && a[1][2][2].color[0] == orange) {
//					Rotate(4, 3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[0][2][1].color[3] == red && a[1][2][2].color[0] == green) {
//					Rotate(4, 3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[0][2][1].color[3] == orange && a[1][2][2].color[0] == red) {
//					Rotate(4, 3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == red && a[0][2][1].color[3] == orange && a[1][2][2].color[0] == blue) {
//					Rotate(4, 3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[0][2][1].color[3] == orange && a[1][2][2].color[0] == green) {
//					Rotate(4, 3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == green && a[0][2][1].color[3] == orange && a[1][2][2].color[0] == blue) {
//					Rotate(4, 3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[0][2][1].color[3] == orange && a[1][2][2].color[0] == red) {
//					Rotate(4, 3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[0][2][1].color[3] == orange && a[1][2][2].color[0] == green) {
//					Rotate(4, 3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[0][2][1].color[3] == green && a[1][2][2].color[0] == orange) {
//					Rotate(4, 3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[0][2][1].color[3] == green && a[1][2][2].color[0] == blue) {
//					Rotate(4, 3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[0][2][1].color[3] == green && a[1][2][2].color[0] == red) {
//					Rotate(4, 3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[0][2][1].color[3] == green && a[1][2][2].color[0] == blue) {
//					Rotate(4, 3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[0][2][1].color[3] == green && a[1][2][2].color[0] == orange) {
//					Rotate(4, 3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[0][2][1].color[3] == green && a[1][2][2].color[0] == red) {
//					Rotate(4, 3);
//				}
//			}
//			if (a[2][1][2].color[5] == white && a[1][0][2].color[2] == white && a[0][1][0].color[1] == white && a[1][2][2].color[3] == white) {
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == red && a[0][1][0].color[4] == blue && a[1][2][2].color[0] == orange) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[0][1][0].color[4] == blue && a[1][2][2].color[0] == red) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[0][1][0].color[4] == blue && a[1][2][2].color[0] == green) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[0][1][0].color[4] == blue && a[1][2][2].color[0] == red) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == green && a[0][1][0].color[4] == blue && a[1][2][2].color[0] == orange) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[0][1][0].color[4] == blue && a[1][2][2].color[0] == green) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[0][1][0].color[4] == red && a[1][2][2].color[0] == orange) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[0][1][0].color[4] == red && a[1][2][2].color[0] == blue) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[0][1][0].color[4] == red && a[1][2][2].color[0] == green) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[0][1][0].color[4] == red && a[1][2][2].color[0] == blue) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[0][1][0].color[4] == red && a[1][2][2].color[0] == orange) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[0][1][0].color[4] == red && a[1][2][2].color[0] == green) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[0][1][0].color[4] == orange && a[1][2][2].color[0] == red) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == red && a[0][1][0].color[4] == orange && a[1][2][2].color[0] == blue) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[0][1][0].color[4] == orange && a[1][2][2].color[0] == green) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == green && a[0][1][0].color[4] == orange && a[1][2][2].color[0] == blue) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[0][1][0].color[4] == orange && a[1][2][2].color[0] == red) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[0][1][0].color[4] == orange && a[1][2][2].color[0] == green) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[0][1][0].color[4] == green && a[1][2][2].color[0] == orange) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[0][1][0].color[4] == green && a[1][2][2].color[0] == blue) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[0][1][0].color[4] == green && a[1][2][2].color[0] == red) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[0][1][0].color[4] == green && a[1][2][2].color[0] == blue) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[0][1][0].color[4] == green && a[1][2][2].color[0] == orange) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[0][1][0].color[4] == green && a[1][2][2].color[0] == red) {
//					Rotate(4, -3);
//				}
//			}
//			if (a[2][1][2].color[5] == white && a[1][0][2].color[2] == white && a[0][1][0].color[4] == white && a[1][2][2].color[3] == white) {
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == red && a[0][1][0].color[1] == blue && a[1][2][2].color[0] == orange) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[0][1][0].color[1] == blue && a[1][2][2].color[0] == red) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[0][1][0].color[1] == blue && a[1][2][2].color[0] == green) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[0][1][0].color[1] == blue && a[1][2][2].color[0] == red) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == green && a[0][1][0].color[1] == blue && a[1][2][2].color[0] == orange) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[0][1][0].color[1] == blue && a[1][2][2].color[0] == green) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[0][1][0].color[1] == red && a[1][2][2].color[0] == orange) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[0][1][0].color[1] == red && a[1][2][2].color[0] == blue) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[0][1][0].color[1] == red && a[1][2][2].color[0] == green) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[0][1][0].color[1] == red && a[1][2][2].color[0] == blue) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[0][1][0].color[1] == red && a[1][2][2].color[0] == orange) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[0][1][0].color[1] == red && a[1][2][2].color[0] == green) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[0][1][0].color[1] == orange && a[1][2][2].color[0] == red) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == red && a[0][1][0].color[1] == orange && a[1][2][2].color[0] == blue) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[0][1][0].color[1] == orange && a[1][2][2].color[0] == green) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == green && a[0][1][0].color[1] == orange && a[1][2][2].color[0] == blue) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[0][1][0].color[1] == orange && a[1][2][2].color[0] == red) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[0][1][0].color[1] == orange && a[1][2][2].color[0] == green) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[0][1][0].color[1] == green && a[1][2][2].color[0] == orange) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[0][1][0].color[1] == green && a[1][2][2].color[0] == blue) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[0][1][0].color[1] == green && a[1][2][2].color[0] == red) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[0][1][0].color[1] == green && a[1][2][2].color[0] == blue) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[0][1][0].color[1] == green && a[1][2][2].color[0] == orange) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[0][1][0].color[1] == green && a[1][2][2].color[0] == red) {
//					Rotate(4, -3);
//				}
//			}
//			if (a[2][1][2].color[5] == white && a[1][0][2].color[2] == white && a[2][1][0].color[1] == white && a[1][2][2].color[3] == white) {
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == red && a[2][1][0].color[5] == blue && a[1][2][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[2][1][0].color[5] == blue && a[1][2][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[2][1][0].color[5] == blue && a[1][2][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[2][1][0].color[5] == blue && a[1][2][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == green && a[2][1][0].color[5] == blue && a[1][2][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[2][1][0].color[5] == blue && a[1][2][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[2][1][0].color[5] == red && a[1][2][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[2][1][0].color[5] == red && a[1][2][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[2][1][0].color[5] == red && a[1][2][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[2][1][0].color[5] == red && a[1][2][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[2][1][0].color[5] == red && a[1][2][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[2][1][0].color[5] == red && a[1][2][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[2][1][0].color[5] == orange && a[1][2][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == red && a[2][1][0].color[5] == orange && a[1][2][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[2][1][0].color[5] == orange && a[1][2][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == green && a[2][1][0].color[5] == orange && a[1][2][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[2][1][0].color[5] == orange && a[1][2][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[2][1][0].color[5] == orange && a[1][2][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[2][1][0].color[5] == green && a[1][2][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[2][1][0].color[5] == green && a[1][2][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[2][1][0].color[5] == green && a[1][2][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[2][1][0].color[5] == green && a[1][2][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[2][1][0].color[5] == green && a[1][2][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[2][1][0].color[5] == green && a[1][2][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//			}
//			if (a[2][1][2].color[5] == white && a[1][0][2].color[2] == white && a[2][1][0].color[5] == white && a[1][2][2].color[3] == white) {
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == red && a[2][1][0].color[1] == blue && a[1][2][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[2][1][0].color[1] == blue && a[1][2][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[2][1][0].color[1] == blue && a[1][2][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[2][1][0].color[1] == blue && a[1][2][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == green && a[2][1][0].color[1] == blue && a[1][2][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[2][1][0].color[1] == blue && a[1][2][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[2][1][0].color[1] == red && a[1][2][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[2][1][0].color[1] == red && a[1][2][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[2][1][0].color[1] == red && a[1][2][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[2][1][0].color[1] == red && a[1][2][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[2][1][0].color[1] == red && a[1][2][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[2][1][0].color[1] == red && a[1][2][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[2][1][0].color[1] == orange && a[1][2][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == green && a[1][0][2].color[0] == red && a[2][1][0].color[1] == orange && a[1][2][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[2][1][0].color[1] == orange && a[1][2][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == green && a[2][1][0].color[1] == orange && a[1][2][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[2][1][0].color[1] == orange && a[1][2][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[2][1][0].color[1] == orange && a[1][2][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[2][1][0].color[1] == green && a[1][2][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[2][1][0].color[1] == green && a[1][2][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[2][1][0].color[1] == green && a[1][2][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[2][1][0].color[1] == green && a[1][2][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[2][1][0].color[1] == green && a[1][2][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[2][1][0].color[1] == green && a[1][2][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//			}
//			//собрано 0 наверху, но есть 3 белых кроме верхнего 
//			if (a[0][1][2].color[4] == white && a[1][0][2].color[2] == white && a[2][0][1].color[2] == white && a[2][1][2].color[5] == white) {
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[2][0][1].color[5] == blue && a[2][1][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[2][0][1].color[5] == blue && a[2][1][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[2][0][1].color[5] == blue && a[2][1][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[2][0][1].color[5] == blue && a[2][1][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[2][0][1].color[5] == blue && a[2][1][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[2][0][1].color[5] == blue && a[2][1][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[2][0][1].color[5] == red && a[2][1][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[2][0][1].color[5] == red && a[2][1][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[2][0][1].color[5] == red && a[2][1][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[2][0][1].color[5] == red && a[2][1][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[2][0][1].color[5] == red && a[2][1][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[2][0][1].color[5] == red && a[2][1][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[2][0][1].color[5] == orange && a[2][1][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[2][0][1].color[5] == orange && a[2][1][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[2][0][1].color[5] == orange && a[2][1][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[2][0][1].color[5] == orange && a[2][1][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[2][0][1].color[5] == orange && a[2][1][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[2][0][1].color[5] == orange && a[2][1][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[2][0][1].color[5] == green && a[2][1][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[2][0][1].color[5] == green && a[2][1][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[2][0][1].color[5] == green && a[2][1][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[2][0][1].color[5] == green && a[2][1][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[2][0][1].color[5] == green && a[2][1][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[2][0][1].color[5] == green && a[2][1][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//			}
//			if (a[0][1][2].color[4] == white && a[1][0][2].color[2] == white && a[2][0][1].color[5] == white && a[2][1][2].color[5] == white) {
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[2][0][1].color[2] == blue && a[2][1][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[2][0][1].color[2] == blue && a[2][1][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[2][0][1].color[2] == blue && a[2][1][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[2][0][1].color[2] == blue && a[2][1][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[2][0][1].color[2] == blue && a[2][1][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[2][0][1].color[2] == blue && a[2][1][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[2][0][1].color[2] == red && a[2][1][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[2][0][1].color[2] == red && a[2][1][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[2][0][1].color[2] == red && a[2][1][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[2][0][1].color[2] == red && a[2][1][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[2][0][1].color[2] == red && a[2][1][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[2][0][1].color[2] == red && a[2][1][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[2][0][1].color[2] == orange && a[2][1][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[2][0][1].color[2] == orange && a[2][1][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[2][0][1].color[2] == orange && a[2][1][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[2][0][1].color[2] == orange && a[2][1][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[2][0][1].color[2] == orange && a[2][1][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[2][0][1].color[2] == orange && a[2][1][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[2][0][1].color[2] == green && a[2][1][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[2][0][1].color[2] == green && a[2][1][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[2][0][1].color[2] == green && a[2][1][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[2][0][1].color[2] == green && a[2][1][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[2][0][1].color[2] == green && a[2][1][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[2][0][1].color[2] == green && a[2][1][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//			}
//			if (a[0][1][2].color[4] == white && a[1][0][2].color[2] == white && a[1][0][0].color[2] == white && a[2][1][2].color[5] == white) {
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[1][0][0].color[1] == blue && a[2][1][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[1][0][0].color[1] == blue && a[2][1][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[1][0][0].color[1] == blue && a[2][1][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[1][0][0].color[1] == blue && a[2][1][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[1][0][0].color[1] == blue && a[2][1][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[1][0][0].color[1] == blue && a[2][1][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[1][0][0].color[1] == red && a[2][1][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[1][0][0].color[1] == red && a[2][1][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[1][0][0].color[1] == red && a[2][1][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[1][0][0].color[1] == red && a[2][1][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[1][0][0].color[1] == red && a[2][1][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[1][0][0].color[1] == red && a[2][1][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[1][0][0].color[1] == orange && a[2][1][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[1][0][0].color[1] == orange && a[2][1][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[1][0][0].color[1] == orange && a[2][1][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[1][0][0].color[1] == orange && a[2][1][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[1][0][0].color[1] == orange && a[2][1][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[1][0][0].color[1] == orange && a[2][1][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[1][0][0].color[1] == green && a[2][1][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[1][0][0].color[1] == green && a[2][1][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[1][0][0].color[1] == green && a[2][1][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[1][0][0].color[1] == green && a[2][1][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[1][0][0].color[1] == green && a[2][1][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[1][0][0].color[1] == green && a[2][1][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//			}
//			if (a[0][1][2].color[4] == white && a[1][0][2].color[2] == white && a[1][0][0].color[1] == white && a[2][1][2].color[5] == white) {
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[1][0][0].color[2] == blue && a[2][1][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[1][0][0].color[2] == blue && a[2][1][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[1][0][0].color[2] == blue && a[2][1][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[1][0][0].color[2] == blue && a[2][1][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[1][0][0].color[2] == blue && a[2][1][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[1][0][0].color[2] == blue && a[2][1][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[1][0][0].color[2] == red && a[2][1][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[1][0][0].color[2] == red && a[2][1][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[1][0][0].color[2] == red && a[2][1][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[1][0][0].color[2] == red && a[2][1][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[1][0][0].color[2] == red && a[2][1][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[1][0][0].color[2] == red && a[2][1][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[1][0][0].color[2] == orange && a[2][1][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[1][0][0].color[2] == orange && a[2][1][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[1][0][0].color[2] == orange && a[2][1][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[1][0][0].color[2] == orange && a[2][1][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[1][0][0].color[2] == orange && a[2][1][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[1][0][0].color[2] == orange && a[2][1][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[1][0][0].color[2] == green && a[2][1][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[1][0][0].color[2] == green && a[2][1][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[1][0][0].color[2] == green && a[2][1][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[1][0][0].color[2] == green && a[2][1][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[1][0][0].color[2] == green && a[2][1][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[1][0][0].color[2] == green && a[2][1][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//			}
//			if (a[0][1][2].color[4] == white && a[1][0][2].color[2] == white && a[0][0][1].color[2] == white && a[2][1][2].color[5] == white) {
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[0][0][1].color[4] == blue && a[2][1][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[0][0][1].color[4] == blue && a[2][1][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[0][0][1].color[4] == blue && a[2][1][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[0][0][1].color[4] == blue && a[2][1][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[0][0][1].color[4] == blue && a[2][1][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[0][0][1].color[4] == blue && a[2][1][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[0][0][1].color[4] == red && a[2][1][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[0][0][1].color[4] == red && a[2][1][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[0][0][1].color[4] == red && a[2][1][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[0][0][1].color[4] == red && a[2][1][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[0][0][1].color[4] == red && a[2][1][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[0][0][1].color[4] == red && a[2][1][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[0][0][1].color[4] == orange && a[2][1][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[0][0][1].color[4] == orange && a[2][1][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[0][0][1].color[4] == orange && a[2][1][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[0][0][1].color[4] == orange && a[2][1][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[0][0][1].color[4] == orange && a[2][1][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[0][0][1].color[4] == orange && a[2][1][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[0][0][1].color[4] == green && a[2][1][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[0][0][1].color[4] == green && a[2][1][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[0][0][1].color[4] == green && a[2][1][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[0][0][1].color[4] == green && a[2][1][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[0][0][1].color[4] == green && a[2][1][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[0][0][1].color[4] == green && a[2][1][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//			}
//			if (a[0][1][2].color[4] == white && a[1][0][2].color[2] == white && a[0][0][1].color[4] == white && a[2][1][2].color[5] == white) {
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[0][0][1].color[2] == blue && a[2][1][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[0][0][1].color[2] == blue && a[2][1][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[0][0][1].color[2] == blue && a[2][1][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[0][0][1].color[2] == blue && a[2][1][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[0][0][1].color[2] == blue && a[2][1][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[0][0][1].color[2] == blue && a[2][1][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[0][0][1].color[2] == red && a[2][1][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[0][0][1].color[2] == red && a[2][1][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[0][0][1].color[2] == red && a[2][1][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[0][0][1].color[2] == red && a[2][1][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[0][0][1].color[2] == red && a[2][1][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[0][0][1].color[2] == red && a[2][1][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[0][0][1].color[2] == orange && a[2][1][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[0][0][1].color[2] == orange && a[2][1][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[0][0][1].color[2] == orange && a[2][1][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[0][0][1].color[2] == orange && a[2][1][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[0][0][1].color[2] == orange && a[2][1][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[0][0][1].color[2] == orange && a[2][1][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[0][0][1].color[2] == green && a[2][1][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[0][0][1].color[2] == green && a[2][1][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[0][0][1].color[2] == green && a[2][1][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[0][0][1].color[2] == green && a[2][1][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[0][0][1].color[2] == green && a[2][1][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[0][0][1].color[2] == green && a[2][1][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//			}
//			if (a[0][1][2].color[4] == white && a[1][0][2].color[2] == white && a[2][2][1].color[3] == white && a[2][1][2].color[5] == white) {
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[2][2][1].color[5] == blue && a[2][1][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[2][2][1].color[5] == blue && a[2][1][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[2][2][1].color[5] == blue && a[2][1][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[2][2][1].color[5] == blue && a[2][1][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[2][2][1].color[5] == blue && a[2][1][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[2][2][1].color[5] == blue && a[2][1][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[2][2][1].color[5] == red && a[2][1][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[2][2][1].color[5] == red && a[2][1][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[2][2][1].color[5] == red && a[2][1][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[2][2][1].color[5] == red && a[2][1][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[2][2][1].color[5] == red && a[2][1][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[2][2][1].color[5] == red && a[2][1][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[2][2][1].color[5] == orange && a[2][1][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[2][2][1].color[5] == orange && a[2][1][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[2][2][1].color[5] == orange && a[2][1][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[2][2][1].color[5] == orange && a[2][1][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[2][2][1].color[5] == orange && a[2][1][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[2][2][1].color[5] == orange && a[2][1][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[2][2][1].color[5] == green && a[2][1][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[2][2][1].color[5] == green && a[2][1][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[2][2][1].color[5] == green && a[2][1][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[2][2][1].color[5] == green && a[2][1][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[2][2][1].color[5] == green && a[2][1][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[2][2][1].color[5] == green && a[2][1][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//			}
//			if (a[0][1][2].color[4] == white && a[1][0][2].color[2] == white && a[2][2][1].color[5] == white && a[2][1][2].color[5] == white) {
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[2][2][1].color[3] == blue && a[2][1][2].color[0] == orange) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[2][2][1].color[3] == blue && a[2][1][2].color[0] == red) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[2][2][1].color[3] == blue && a[2][1][2].color[0] == green) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[2][2][1].color[3] == blue && a[2][1][2].color[0] == red) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[2][2][1].color[3] == blue && a[2][1][2].color[0] == orange) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[2][2][1].color[3] == blue && a[2][1][2].color[0] == green) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[2][2][1].color[3] == red && a[2][1][2].color[0] == orange) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[2][2][1].color[3] == red && a[2][1][2].color[0] == blue) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[2][2][1].color[3] == red && a[2][1][2].color[0] == green) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[2][2][1].color[3] == red && a[2][1][2].color[0] == blue) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[2][2][1].color[3] == red && a[2][1][2].color[0] == orange) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[2][2][1].color[3] == red && a[2][1][2].color[0] == green) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[2][2][1].color[3] == orange && a[2][1][2].color[0] == red) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[2][2][1].color[3] == orange && a[2][1][2].color[0] == blue) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[2][2][1].color[3] == orange && a[2][1][2].color[0] == green) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[2][2][1].color[3] == orange && a[2][1][2].color[0] == blue) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[2][2][1].color[3] == orange && a[2][1][2].color[0] == red) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[2][2][1].color[3] == orange && a[2][1][2].color[0] == green) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[2][2][1].color[3] == green && a[2][1][2].color[0] == orange) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[2][2][1].color[3] == green && a[2][1][2].color[0] == blue) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[2][2][1].color[3] == green && a[2][1][2].color[0] == red) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[2][2][1].color[3] == green && a[2][1][2].color[0] == blue) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[2][2][1].color[3] == green && a[2][1][2].color[0] == orange) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[2][2][1].color[3] == green && a[2][1][2].color[0] == red) {
//					Rotate(3, -3);
//				}
//			}
//			if (a[0][1][2].color[4] == white && a[1][0][2].color[2] == white && a[1][2][0].color[3] == white && a[2][1][2].color[5] == white) {
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[1][2][0].color[1] == blue && a[2][1][2].color[0] == orange) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[1][2][0].color[1] == blue && a[2][1][2].color[0] == red) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[1][2][0].color[1] == blue && a[2][1][2].color[0] == green) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[1][2][0].color[1] == blue && a[2][1][2].color[0] == red) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[1][2][0].color[1] == blue && a[2][1][2].color[0] == orange) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[1][2][0].color[1] == blue && a[2][1][2].color[0] == green) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[1][2][0].color[1] == red && a[2][1][2].color[0] == orange) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[1][2][0].color[1] == red && a[2][1][2].color[0] == blue) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[1][2][0].color[1] == red && a[2][1][2].color[0] == green) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[1][2][0].color[1] == red && a[2][1][2].color[0] == blue) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[1][2][0].color[1] == red && a[2][1][2].color[0] == orange) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[1][2][0].color[1] == red && a[2][1][2].color[0] == green) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[1][2][0].color[1] == orange && a[2][1][2].color[0] == red) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[1][2][0].color[1] == orange && a[2][1][2].color[0] == blue) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[1][2][0].color[1] == orange && a[2][1][2].color[0] == green) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[1][2][0].color[1] == orange && a[2][1][2].color[0] == blue) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[1][2][0].color[1] == orange && a[2][1][2].color[0] == red) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[1][2][0].color[1] == orange && a[2][1][2].color[0] == green) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[1][2][0].color[1] == green && a[2][1][2].color[0] == orange) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[1][2][0].color[1] == green && a[2][1][2].color[0] == blue) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[1][2][0].color[1] == green && a[2][1][2].color[0] == red) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[1][2][0].color[1] == green && a[2][1][2].color[0] == blue) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[1][2][0].color[1] == green && a[2][1][2].color[0] == orange) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[1][2][0].color[1] == green && a[2][1][2].color[0] == red) {
//					Rotate(3, -3);
//				}
//			}
//			if (a[0][1][2].color[4] == white && a[1][0][2].color[2] == white && a[1][2][0].color[1] == white && a[2][1][2].color[5] == white) {
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[1][2][0].color[3] == blue && a[2][1][2].color[0] == orange) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[1][2][0].color[3] == blue && a[2][1][2].color[0] == red) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[1][2][0].color[3] == blue && a[2][1][2].color[0] == green) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[1][2][0].color[3] == blue && a[2][1][2].color[0] == red) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[1][2][0].color[3] == blue && a[2][1][2].color[0] == orange) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[1][2][0].color[3] == blue && a[2][1][2].color[0] == green) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[1][2][0].color[3] == red && a[2][1][2].color[0] == orange) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[1][2][0].color[3] == red && a[2][1][2].color[0] == blue) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[1][2][0].color[3] == red && a[2][1][2].color[0] == green) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[1][2][0].color[3] == red && a[2][1][2].color[0] == blue) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[1][2][0].color[3] == red && a[2][1][2].color[0] == orange) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[1][2][0].color[3] == red && a[2][1][2].color[0] == green) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[1][2][0].color[3] == orange && a[2][1][2].color[0] == red) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[1][2][0].color[3] == orange && a[2][1][2].color[0] == blue) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[1][2][0].color[3] == orange && a[2][1][2].color[0] == green) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[1][2][0].color[3] == orange && a[2][1][2].color[0] == blue) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[1][2][0].color[3] == orange && a[2][1][2].color[0] == red) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[1][2][0].color[3] == orange && a[2][1][2].color[0] == green) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[1][2][0].color[3] == green && a[2][1][2].color[0] == orange) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[1][2][0].color[3] == green && a[2][1][2].color[0] == blue) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[1][2][0].color[3] == green && a[2][1][2].color[0] == red) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[1][2][0].color[3] == green && a[2][1][2].color[0] == blue) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[1][2][0].color[3] == green && a[2][1][2].color[0] == orange) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[1][2][0].color[3] == green && a[2][1][2].color[0] == red) {
//					Rotate(3, -3);
//				}
//			}
//			if (a[0][1][2].color[4] == white && a[1][0][2].color[2] == white && a[0][2][1].color[3] == white && a[2][1][2].color[5] == white) {
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[0][2][1].color[4] == blue && a[2][1][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[0][2][1].color[4] == blue && a[2][1][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[0][2][1].color[4] == blue && a[2][1][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[0][2][1].color[4] == blue && a[2][1][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[0][2][1].color[4] == blue && a[2][1][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[0][2][1].color[4] == blue && a[2][1][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[0][2][1].color[4] == red && a[2][1][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[0][2][1].color[4] == red && a[2][1][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[0][2][1].color[4] == red && a[2][1][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[0][2][1].color[4] == red && a[2][1][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[0][2][1].color[4] == red && a[2][1][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[0][2][1].color[4] == red && a[2][1][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[0][2][1].color[4] == orange && a[2][1][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[0][2][1].color[4] == orange && a[2][1][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[0][2][1].color[4] == orange && a[2][1][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[0][2][1].color[4] == orange && a[2][1][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[0][2][1].color[4] == orange && a[2][1][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[0][2][1].color[4] == orange && a[2][1][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[0][2][1].color[4] == green && a[2][1][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[0][2][1].color[4] == green && a[2][1][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[0][2][1].color[4] == green && a[2][1][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[0][2][1].color[4] == green && a[2][1][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[0][2][1].color[4] == green && a[2][1][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[0][2][1].color[4] == green && a[2][1][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//			}
//			if (a[0][1][2].color[4] == white && a[1][0][2].color[2] == white && a[0][2][1].color[4] == white && a[2][1][2].color[5] == white) {
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[0][2][1].color[3] == blue && a[2][1][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[0][2][1].color[3] == blue && a[2][1][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[0][2][1].color[3] == blue && a[2][1][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[0][2][1].color[3] == blue && a[2][1][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[0][2][1].color[3] == blue && a[2][1][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[0][2][1].color[3] == blue && a[2][1][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[0][2][1].color[3] == red && a[2][1][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[0][2][1].color[3] == red && a[2][1][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[0][2][1].color[3] == red && a[2][1][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[0][2][1].color[3] == red && a[2][1][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[0][2][1].color[3] == red && a[2][1][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[0][2][1].color[3] == red && a[2][1][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[0][2][1].color[3] == orange && a[2][1][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[0][2][1].color[3] == orange && a[2][1][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[0][2][1].color[3] == orange && a[2][1][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[0][2][1].color[3] == orange && a[2][1][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[0][2][1].color[3] == orange && a[2][1][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[0][2][1].color[3] == orange && a[2][1][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[0][2][1].color[3] == green && a[2][1][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[0][2][1].color[3] == green && a[2][1][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[0][2][1].color[3] == green && a[2][1][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[0][2][1].color[3] == green && a[2][1][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[0][2][1].color[3] == green && a[2][1][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[0][2][1].color[3] == green && a[2][1][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//			}
//			if (a[0][1][2].color[4] == white && a[1][0][2].color[2] == white && a[0][1][0].color[4] == white && a[2][1][2].color[5] == white) {
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[0][1][0].color[1] == blue && a[2][1][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[0][1][0].color[1] == blue && a[2][1][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[0][1][0].color[1] == blue && a[2][1][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[0][1][0].color[1] == blue && a[2][1][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[0][1][0].color[1] == blue && a[2][1][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[0][1][0].color[1] == blue && a[2][1][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[0][1][0].color[1] == red && a[2][1][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[0][1][0].color[1] == red && a[2][1][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[0][1][0].color[1] == red && a[2][1][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[0][1][0].color[1] == red && a[2][1][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[0][1][0].color[1] == red && a[2][1][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[0][1][0].color[1] == red && a[2][1][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[0][1][0].color[1] == orange && a[2][1][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[0][1][0].color[1] == orange && a[2][1][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[0][1][0].color[1] == orange && a[2][1][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[0][1][0].color[1] == orange && a[2][1][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[0][1][0].color[1] == orange && a[2][1][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[0][1][0].color[1] == orange && a[2][1][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[0][1][0].color[1] == green && a[2][1][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[0][1][0].color[1] == green && a[2][1][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[0][1][0].color[1] == green && a[2][1][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[0][1][0].color[1] == green && a[2][1][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[0][1][0].color[1] == green && a[2][1][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[0][1][0].color[1] == green && a[2][1][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//			}
//			if (a[0][1][2].color[4] == white && a[1][0][2].color[2] == white && a[0][1][0].color[1] == white && a[2][1][2].color[5] == white) {
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[0][1][0].color[4] == blue && a[2][1][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[0][1][0].color[4] == blue && a[2][1][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[0][1][0].color[4] == blue && a[2][1][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[0][1][0].color[4] == blue && a[2][1][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[0][1][0].color[4] == blue && a[2][1][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[0][1][0].color[4] == blue && a[2][1][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[0][1][0].color[4] == red && a[2][1][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[0][1][0].color[4] == red && a[2][1][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[0][1][0].color[4] == red && a[2][1][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[0][1][0].color[4] == red && a[2][1][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[0][1][0].color[4] == red && a[2][1][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[0][1][0].color[4] == red && a[2][1][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[0][1][0].color[4] == orange && a[2][1][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[0][1][0].color[4] == orange && a[2][1][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[0][1][0].color[4] == orange && a[2][1][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[0][1][0].color[4] == orange && a[2][1][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[0][1][0].color[4] == orange && a[2][1][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[0][1][0].color[4] == orange && a[2][1][2].color[0] == green) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[0][1][0].color[4] == green && a[2][1][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[0][1][0].color[4] == green && a[2][1][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[0][1][0].color[4] == green && a[2][1][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[0][1][0].color[4] == green && a[2][1][2].color[0] == blue) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[0][1][0].color[4] == green && a[2][1][2].color[0] == orange) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[0][1][0].color[4] == green && a[2][1][2].color[0] == red) {
//					Rotate(1, 3);
//				}
//			}
//			if (a[0][1][2].color[4] == white && a[1][0][2].color[2] == white && a[2][1][0].color[5] == white && a[2][1][2].color[5] == white) {
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[2][1][0].color[1] == blue && a[2][1][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[2][1][0].color[1] == blue && a[2][1][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[2][1][0].color[1] == blue && a[2][1][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[2][1][0].color[1] == blue && a[2][1][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[2][1][0].color[1] == blue && a[2][1][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[2][1][0].color[1] == blue && a[2][1][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[2][1][0].color[1] == red && a[2][1][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[2][1][0].color[1] == red && a[2][1][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[2][1][0].color[1] == red && a[2][1][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[2][1][0].color[1] == red && a[2][1][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[2][1][0].color[1] == red && a[2][1][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[2][1][0].color[1] == red && a[2][1][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[2][1][0].color[1] == orange && a[2][1][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[2][1][0].color[1] == orange && a[2][1][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[2][1][0].color[1] == orange && a[2][1][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[2][1][0].color[1] == orange && a[2][1][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[2][1][0].color[1] == orange && a[2][1][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[2][1][0].color[1] == orange && a[2][1][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[2][1][0].color[1] == green && a[2][1][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[2][1][0].color[1] == green && a[2][1][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[2][1][0].color[1] == green && a[2][1][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[2][1][0].color[1] == green && a[2][1][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[2][1][0].color[1] == green && a[2][1][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[2][1][0].color[1] == green && a[2][1][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//			}
//			if (a[0][1][2].color[4] == white && a[1][0][2].color[2] == white && a[2][1][0].color[1] == white && a[2][1][2].color[5] == white) {
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[2][1][0].color[5] == blue && a[2][1][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[2][1][0].color[5] == blue && a[2][1][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[2][1][0].color[5] == blue && a[2][1][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[2][1][0].color[5] == blue && a[2][1][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[2][1][0].color[5] == blue && a[2][1][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[2][1][0].color[5] == blue && a[2][1][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[2][1][0].color[5] == red && a[2][1][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == orange && a[2][1][0].color[5] == red && a[2][1][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[2][1][0].color[5] == red && a[2][1][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == green && a[2][1][0].color[5] == red && a[2][1][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[2][1][0].color[5] == red && a[2][1][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[2][1][0].color[5] == red && a[2][1][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == blue && a[2][1][0].color[5] == orange && a[2][1][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == green && a[1][0][2].color[0] == red && a[2][1][0].color[5] == orange && a[2][1][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[2][1][0].color[5] == orange && a[2][1][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == green && a[2][1][0].color[5] == orange && a[2][1][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == green && a[2][1][0].color[5] == orange && a[2][1][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[2][1][0].color[5] == orange && a[2][1][2].color[0] == green) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == blue && a[2][1][0].color[5] == green && a[2][1][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == red && a[1][0][2].color[0] == orange && a[2][1][0].color[5] == green && a[2][1][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == blue && a[2][1][0].color[5] == green && a[2][1][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == orange && a[1][0][2].color[0] == red && a[2][1][0].color[5] == green && a[2][1][2].color[0] == blue) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == red && a[2][1][0].color[5] == green && a[2][1][2].color[0] == orange) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][2].color[0] == blue && a[1][0][2].color[0] == orange && a[2][1][0].color[5] == green && a[2][1][2].color[0] == red) {
//					Rotate(1, -3);
//				}
//			}
//			//собрано 0 наверху, но есть 2 белых вертикально
//			if (a[1][0][2].color[2] == white && a[1][2][2].color[3] == white && (a[0][1][2].color[0] != white && a[0][1][2].color[4] != white) && (a[2][1][2].color[0] != white && a[2][1][2].color[5] != white)) {
//				//для синей грани
//				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
//					Rotate(1, -3);
//				}
//				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
//					Rotate(1, -3);
//				}
//				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
//					Rotate(1, -3);
//				}
//				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
//					Rotate(1, -3);
//				}
//				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
//					Rotate(1, -3);
//				}
//				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
//					Rotate(1, -3);
//				}
//				//для зеленой грани
//				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
//					Rotate(1, -3);
//				}
//				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
//					Rotate(1, -3);
//				}
//				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
//					Rotate(1, -3);
//				}
//				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
//					Rotate(1, -3);
//				}
//				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
//					Rotate(1, -3);
//				}
//				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
//					Rotate(1, -3);
//				}
//				//для красной
//				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
//					Rotate(4, -3);
//				}
//				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
//					Rotate(4, -3);
//				}
//				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
//					Rotate(4, -3);
//				}
//				if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
//					Rotate(4, -3);
//				}
//				if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
//					Rotate(4, -3);
//				}
//				if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
//					Rotate(4, -3);
//				}
//				//для оранжевой
//				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
//					Rotate(5, -3);
//				}
//				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
//					Rotate(5, -3);
//				}
//				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
//					Rotate(5, -3);
//				}
//				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
//					Rotate(5, -3);
//				}
//				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
//					Rotate(5, -3);
//				}
//				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
//					Rotate(5, -3);
//				}
//			}
//			//собрано 0 наверху, но есть 2 белых горизонтально
//			if (a[0][1][2].color[4] == white && a[2][1][2].color[5] == white && (a[1][0][2].color[0] != white && a[1][0][2].color[2] != white) && (a[1][2][2].color[0] != white && a[1][2][2].color[3] != white)) {
//				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
//					Rotate(2, -3);
//				}
//				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
//					Rotate(2, -3);
//				}
//				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
//					Rotate(2, -3);
//				}
//				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
//					Rotate(2, -3);
//				}
//				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
//					Rotate(2, -3);
//				}
//				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
//					Rotate(2, -3);
//				}
//				//для зеленой грани
//				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
//					Rotate(3, -3);
//				}
//				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
//					Rotate(3, -3);
//				}
//				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
//					Rotate(3, -3);
//				}
//				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
//					Rotate(3, -3);
//				}
//				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
//					Rotate(3, -3);
//				}
//				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
//					Rotate(3, -3);
//				}
//				//для красной
//				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
//					Rotate(1, -3);
//				}
//				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
//					Rotate(1, -3);
//				}
//				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
//					Rotate(1, -3);
//				}
//				if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
//					Rotate(1, -3);
//				}
//				if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
//					Rotate(1, -3);
//				}
//				if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
//					Rotate(1, -3);
//				}
//				//для оранжевой
//				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
//					Rotate(1, -3);
//				}
//				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
//					Rotate(1, -3);
//				}
//				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
//					Rotate(1, -3);
//				}
//				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
//					Rotate(1, -3);
//				}
//				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
//					Rotate(1, -3);
//				}
//				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
//					Rotate(1, -3);
//				}
//			}
//
//			//2 белых левыи нижним уголком 
//			if (((a[0][1][2].color[4] == white && a[1][0][2].color[2] == white) || (a[0][1][2].color[0] == white && a[1][0][2].color[0] == white) || (a[0][1][2].color[4] == white && a[1][0][2].color[0] == white) || (a[0][1][2].color[0] == white && a[1][0][2].color[2] == white)) && (a[2][1][2].color[0] != white && a[2][1][2].color[5] != white) && (a[1][2][2].color[0] != white && a[1][2][2].color[3] != white)) {
//				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
//					if (a[0][1][0].color[4] || a[0][1][0].color[1] == white) {
//						Rotate(1, -3);
//					}
//				}
//				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
//					Rotate(1, -3);
//				}
//				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
//					Rotate(1, -3);
//				}
//				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
//					Rotate(1, -3);
//				}
//				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
//					if (a[0][1][0].color[4] || a[0][1][0].color[1] == white) {
//						Rotate(1, -3);
//					}
//				}
//				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
//					if (a[0][1][0].color[4] || a[0][1][0].color[1] == white) {
//						Rotate(1, -3);
//					}
//				}
//				//для зеленой грани
//				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
//					Rotate(3, -3);
//				}
//				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
//					Rotate(3, -3);
//				}
//				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
//					Rotate(3, -3);
//				}
//				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
//					Rotate(3, -3);
//				}
//				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
//					Rotate(3, -3);
//				}
//				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
//					Rotate(3, -3);
//				}
//				//для красной
//				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
//					Rotate(1, 3);
//				}
//				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
//					Rotate(1, 3);
//				}
//				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
//					Rotate(1, 3);
//				}
//				if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
//					Rotate(1, 3);
//				}
//				if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
//					Rotate(1, 3);
//				}
//				/*if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
//					Rotate(1, 3);
//				}*/
//				//для оранжевой
//				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
//					Rotate(5, -3);
//				}
//				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
//					Rotate(5, -3);
//				}
//				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
//					Rotate(5, -3);
//				}
//				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
//					Rotate(5, -3);
//				}
//				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
//					Rotate(5, -3);
//				}
//				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
//					Rotate(5, -3);
//				}
//			}
//			//2 белых правым нижним уголком 
//			if (((a[2][1][2].color[5] == white && a[1][0][2].color[2] == white) || (a[2][1][2].color[0] == white && a[1][0][2].color[0] == white) || (a[2][1][2].color[5] == white && a[1][0][2].color[0] == white) || (a[2][1][2].color[0] == white && a[1][0][2].color[2] == white)) && (a[0][1][2].color[0] != white && a[0][1][2].color[4] != white) && (a[1][2][2].color[0] != white && a[1][2][2].color[3] != white)) {
//				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
//					if (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white) {
//						Rotate(1, 3);
//					}
//				}
//				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
//					Rotate(1, 3);
//				}
//				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
//					Rotate(1, 3);
//				}
//				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
//					Rotate(1, 3);
//				}
//				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
//					if (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white) {
//						Rotate(1, 3);
//					}
//				}
//				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
//					if (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white) {
//						Rotate(1, 3);
//					}
//				}
//				//для зеленой грани
//				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
//					Rotate(3, -3);
//				}
//				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
//					Rotate(3, -3);
//				}
//				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
//					Rotate(3, -3);
//				}
//				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
//					Rotate(3, -3);
//				}
//				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
//					Rotate(3, -3);
//				}
//				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
//					Rotate(3, -3);
//				}
//				//для красной
//				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
//					Rotate(4, -3);
//				}
//				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
//					Rotate(4, -3);
//				}
//				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
//					Rotate(4, -3);
//				}
//				if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
//					Rotate(4, -3);
//				}
//				if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
//					Rotate(4, -3);
//				}
//				if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
//					Rotate(4, -3);
//				}
//				//для оранжевой
//				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
//					Rotate(1, -3);
//				}
//				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
//					Rotate(1, -3);
//				}
//				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
//					Rotate(1, -3);
//				}
//				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
//					Rotate(1, -3);
//				}
//				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
//					Rotate(1, -3);
//				}
//				/*if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
//					Rotate(1, -3);
//				}*/
//			}
//			//2 белых правым верхним уголком 
//			if (((a[2][1][2].color[5] == white && a[1][2][2].color[3] == white) || (a[2][1][2].color[0] == white && a[1][2][2].color[0] == white) || (a[2][1][2].color[0] == white && a[1][2][2].color[3] == white) || (a[2][1][2].color[5] == white && a[1][2][2].color[0] == white)) && (a[0][1][2].color[0] != white && a[0][1][2].color[4] != white) && (a[1][0][2].color[0] != white && a[1][0][2].color[2] != white)) {
//				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
//					Rotate(2, -3);
//				}
//				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
//					Rotate(2, -3);
//				}
//				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
//					Rotate(2, -3);
//				}
//				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
//					Rotate(2, -3);
//				}
//				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
//					Rotate(2, -3);
//				}
//				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
//					Rotate(2, -3);
//				}
//				//для зеленой грани
//				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
//					if (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white) {
//						Rotate(1, -3);
//					}
//				}
//				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
//					Rotate(1, -3);
//				}
//				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
//					Rotate(1, -3);
//				}
//				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
//					Rotate(1, -3);
//				}
//				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
//					if (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white) {
//						Rotate(1, -3);
//					}
//				}
//				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
//					if (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white) {
//						Rotate(1, -3);
//					}
//				}
//				//для красной
//				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
//					Rotate(4, -3);
//				}
//				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
//					Rotate(4, -3);
//				}
//				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
//					Rotate(4, -3);
//				}
//				if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
//					Rotate(4, -3);
//				}
//				if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
//					Rotate(4, -3);
//				}
//				if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
//					Rotate(4, -3);
//				}
//				//для оранжевой
//				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
//					Rotate(1, 3);
//				}
//				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
//					Rotate(1, 3);
//				}
//				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
//					Rotate(1, 3);
//				}
//				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
//					Rotate(1, 3);
//				}
//				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
//					Rotate(1, 3);
//				}
//				/*if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
//					Rotate(1, 3);
//				}*/
//			}
//			//2 белых левым верхним уголком 
//			if (((a[0][1][2].color[4] == white && a[1][2][2].color[3] == white) || (a[0][1][2].color[0] == white && a[1][2][2].color[0] == white) || (a[0][1][2].color[4] == white && a[1][2][2].color[0] == white) || (a[0][1][2].color[0] == white && a[1][2][2].color[3] == white)) && (a[2][1][2].color[0] != white && a[2][1][2].color[5] != white) && (a[1][0][2].color[0] != white && a[1][0][2].color[2] != white)) {
//				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
//					Rotate(2, -3);
//				}
//				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
//					Rotate(2, -3);
//				}
//				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
//					Rotate(2, -3);
//				}
//				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
//					Rotate(2, -3);
//				}
//				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
//					Rotate(2, -3);
//				}
//				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
//					Rotate(2, -3);
//				}
//				//для зеленой грани
//				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
//					if (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white) {
//						Rotate(1, 3);
//					}
//				}
//				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
//					Rotate(1, 3);
//				}
//				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
//					Rotate(1, 3);
//				}
//				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
//					Rotate(1, 3);
//				}
//				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
//					if (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white) {
//						Rotate(1, 3);
//					}
//				}
//				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
//					if (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white) {
//						Rotate(1, 3);
//					}
//				}
//				//для красной
//				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
//					Rotate(1, -3);
//				}
//				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
//					Rotate(1, -3);
//				}
//				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
//					Rotate(1, -3);
//				}
//				if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
//					Rotate(1, -3);
//				}
//				if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
//					Rotate(1, -3);
//				}
//				/*if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
//					Rotate(1, -3);
//				}*/
//				//для оранжевой
//				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
//					Rotate(5, -3);
//				}
//				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
//					Rotate(5, -3);
//				}
//				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
//					Rotate(5, -3);
//				}
//				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
//					Rotate(5, -3);
//				}
//				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
//					Rotate(5, -3);
//				}
//				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
//					Rotate(5, -3);
//				}
//			}
//			//1 нижний правильно 2 неправильно горизонтально кроме верхней 
//			if (a[1][0][2].color[0] == white && a[0][1][2].color[4] == white && a[2][1][2].color[5] == white && (a[1][2][2].color[0] != white && a[1][2][2].color[3] != white)) {
//				if (a[2][0][1].color[2] == white || a[2][0][1].color[5] == white) {
//					Rotate(1, -3);
//				}
//				if (a[0][0][1].color[2] == white || a[0][0][1].color[4] == white) {
//					Rotate(1, 3);
//				}
//				if (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white) {
//					Rotate(1, -3);
//				}
//				if (a[2][2][1].color[3] == white || a[2][2][1].color[5] == white) {
//					Rotate(3, -3);
//				}
//				if (a[0][2][1].color[3] == white || a[0][2][1].color[4] == white) {
//					Rotate(3, 3);
//				}
//				if (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white) {
//					Rotate(1, -3);
//				}
//			}
//			//1 нижний правильно 2 неправильно левым уголком кроме правой 
//			if (a[1][0][2].color[0] == white && a[0][1][2].color[4] == white && a[1][2][2].color[3] == white && (a[2][1][2].color[0] != white && a[2][1][2].color[5] != white)) {
//				if (a[2][0][1].color[2] == white || a[2][0][1].color[5] == white) {
//					Rotate(1, -3);
//				}
//				if (a[0][0][1].color[2] == white || a[0][0][1].color[4] == white) {
//					Rotate(1, -3);
//				}
//				if (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white) {
//					Rotate(1, -3);
//				}
//				if (a[2][2][1].color[3] == white || a[2][2][1].color[5] == white) {
//					Rotate(1, 3);
//				}
//				if (a[0][2][1].color[3] == white || a[0][2][1].color[4] == white) {
//					Rotate(1, 3);
//				}
//				if (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white) {
//					Rotate(5, -3);
//				}
//			}
//			//1 нижний правильно 2 неправильно правым уголком кроме левой 
//			if (a[1][0][2].color[0] == white && a[2][1][2].color[5] == white && a[1][2][2].color[3] == white && (a[0][1][2].color[0] != white && a[0][1][2].color[4] != white)) {
//				if (a[2][0][1].color[2] == white || a[2][0][1].color[5] == white) {
//					Rotate(1, 3);
//				}
//				if (a[0][0][1].color[2] == white || a[0][0][1].color[4] == white) {
//					Rotate(1, 3);
//				}
//				if (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white) {
//					Rotate(1, 3);
//				}
//				if (a[2][2][1].color[3] == white || a[2][2][1].color[5] == white) {
//					Rotate(1, -3);
//				}
//				if (a[0][2][1].color[3] == white || a[0][2][1].color[4] == white) {
//					Rotate(1, -3);
//				}
//				if (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white) {
//					Rotate(1, -3);
//				}
//			}
//			//1 левый правильно 2 неправильно вертикально кроме правой 
//			if (a[0][1][2].color[0] == white && a[1][2][2].color[3] == white && a[1][0][2].color[2] == white && (a[2][1][2].color[0] != white && a[2][1][2].color[5] != white)) {
//				if (a[2][0][1].color[2] == white || a[2][0][1].color[5] == white) {
//					Rotate(1, -3);
//				}
//				if (a[0][0][1].color[2] == white || a[0][0][1].color[4] == white) {
//					Rotate(1, -3);
//				}
//				if (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white) {
//					Rotate(1, -3);
//				}
//				if (a[2][2][1].color[3] == white || a[2][2][1].color[5] == white) {
//					Rotate(1, 3);
//				}
//				if (a[0][2][1].color[3] == white || a[0][2][1].color[4] == white) {
//					Rotate(1, 3);
//				}
//				if (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white) {
//					Rotate(5, 3);
//				}
//			}
//			//1 левый правильно 2 неправильно правый верхний уголок кроме нижней 
//			if (a[0][1][2].color[0] == white && a[1][2][2].color[3] == white && a[2][1][2].color[5] == white && (a[1][0][2].color[0] != white && a[1][0][2].color[2] != white)) {
//				if (a[2][0][1].color[2] == white || a[2][0][1].color[5] == white) {
//					Rotate(2, -3);
//				}
//				if (a[0][0][1].color[2] == white || a[0][0][1].color[4] == white) {
//					Rotate(2, -3);
//				}
//				if (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white) {
//					Rotate(2, -3);
//				}
//				if (a[2][2][1].color[3] == white || a[2][2][1].color[5] == white) {
//					Rotate(1, 3);
//				}
//				if (a[0][2][1].color[3] == white || a[0][2][1].color[4] == white) {
//					Rotate(1, 3);
//				}
//				if (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white) {
//					Rotate(1, -3);
//				}
//				if (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white) {
//					Rotate(1, 3);
//				}
//			}
//			//1 левый правильно 2 неправильно правый нижний уголок кроме верхней 
//			if (a[0][1][2].color[0] == white && a[2][1][2].color[5] == white && a[1][0][2].color[2] == white && (a[1][2][2].color[0] != white && a[1][2][2].color[3] != white)) {
//				if (a[2][0][1].color[2] == white || a[2][0][1].color[5] == white) {
//					Rotate(1, -3);
//				}
//				if (a[0][0][1].color[2] == white || a[0][0][1].color[4] == white) {
//					Rotate(1, -3);
//				}
//				if (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white) {
//					Rotate(1, -3);
//				}
//				if (a[2][2][1].color[3] == white || a[2][2][1].color[5] == white) {
//					Rotate(3, -3);
//				}
//				if (a[0][2][1].color[3] == white || a[0][2][1].color[4] == white) {
//					Rotate(3, -3);
//				}
//				if (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white) {
//					Rotate(1, -3);
//				}
//			}
//			//1 верхний правильно 2 неправильно горизонтально кроме нижней
//			if (a[0][1][2].color[4] == white && a[1][2][2].color[0] == white && a[2][1][2].color[5] == white && (a[1][0][2].color[0] != white && a[1][0][2].color[2] != white)) {
//				if (a[2][0][1].color[2] == white || a[2][0][1].color[5] == white) {
//					Rotate(2, -3);
//				}
//				if (a[0][0][1].color[2] == white || a[0][0][1].color[4] == white) {
//					Rotate(2, 3);
//				}
//				if (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white) {
//					Rotate(2, -3);
//				}
//				if (a[2][2][1].color[3] == white || a[2][2][1].color[5] == white) {
//					Rotate(1, -3);
//				}
//				if (a[0][2][1].color[3] == white || a[0][2][1].color[4] == white) {
//					Rotate(1, -3);
//				}
//				if (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white) {
//					Rotate(1, -3);
//				}
//				if (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white) {
//					Rotate(1, 3);
//				}
//			}
//			//1 верхний правильно 2 неправильно правый нижний угол кроме левой
//			if (a[2][1][2].color[5] == white && a[1][2][2].color[0] == white && a[1][0][2].color[2] == white && (a[0][1][2].color[0] != white && a[0][1][2].color[4] != white)) {
//				if (a[2][0][1].color[2] == white || a[2][0][1].color[5] == white) {
//					Rotate(1, 3);
//				}
//				if (a[0][0][1].color[2] == white || a[0][0][1].color[4] == white) {
//					Rotate(1, 3);
//				}
//				if (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white) {
//					Rotate(1, 3);
//				}
//				if (a[2][2][1].color[3] == white || a[2][2][1].color[5] == white) {
//					Rotate(1, -3);
//				}
//				if (a[0][2][1].color[3] == white || a[0][2][1].color[4] == white) {
//					Rotate(1, -3);
//				}
//				if (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white) {
//					Rotate(1, 3);
//				}
//			}
//			//1 верхний правильно 2 неправильно левый нижний угол кроме правой
//			if (a[0][1][2].color[4] == white && a[1][2][2].color[0] == white && a[1][0][2].color[2] == white && (a[2][1][2].color[0] != white && a[2][1][2].color[5] != white)) {
//				if (a[2][0][1].color[2] == white || a[2][0][1].color[5] == white) {
//					Rotate(1, -3);
//				}
//				if (a[0][0][1].color[2] == white || a[0][0][1].color[4] == white) {
//					Rotate(1, -3);
//				}
//				if (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white) {
//					Rotate(1, -3);
//				}
//				if (a[2][2][1].color[3] == white || a[2][2][1].color[5] == white) {
//					Rotate(1, 3);
//				}
//				if (a[0][2][1].color[3] == white || a[0][2][1].color[4] == white) {
//					Rotate(1, 3);
//				}
//				if (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white) {
//					Rotate(5, -3);
//				}
//			}
//			//1 правый правильно 2 неправильно вертикально кроме левой
//			if (a[1][0][2].color[2] == white && a[1][2][2].color[3] == white && a[2][1][2].color[0] == white && (a[0][1][2].color[0] != white && a[0][1][2].color[4] != white)) {
//				if (a[2][0][1].color[2] == white || a[2][0][1].color[5] == white) {
//					Rotate(1, 3);
//				}
//				if (a[0][0][1].color[2] == white || a[0][0][1].color[4] == white) {
//					Rotate(1, 3);
//				}
//				if (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white) {
//					Rotate(1, 3);
//				}
//				if (a[2][2][1].color[3] == white || a[2][2][1].color[5] == white) {
//					Rotate(1, -3);
//				}
//				if (a[0][2][1].color[3] == white || a[0][2][1].color[4] == white) {
//					Rotate(1, -3);
//				}
//				if (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white) {
//					Rotate(4, 3);
//				}
//				if (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white) {
//					Rotate(1, 3);
//				}
//			}
//			//1 правый правильно 2 неправильно левый нижний уголок кроме верхней
//			if (a[1][0][2].color[2] == white && a[0][1][2].color[4] == white && a[2][1][2].color[0] == white && (a[1][2][2].color[0] != white && a[1][2][2].color[3] != white)) {
//				if (a[2][0][1].color[2] == white || a[2][0][1].color[5] == white) {
//					Rotate(1, 3);
//				}
//				if (a[0][0][1].color[2] == white || a[0][0][1].color[4] == white) {
//					Rotate(1, 3);
//				}
//				if (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white) {
//					Rotate(1, 3);
//				}
//				if (a[2][2][1].color[3] == white || a[2][2][1].color[5] == white) {
//					Rotate(3, -3);
//				}
//				if (a[0][2][1].color[3] == white || a[0][2][1].color[4] == white) {
//					Rotate(3, -3);
//				}
//				if (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white) {
//					Rotate(1, -3);
//				}
//			}
//			//1 правый правильно 2 неправильно левый верхний уголок кроме нижней
//			if (a[1][2][2].color[3] == white && a[0][1][2].color[4] == white && a[2][1][2].color[0] == white && (a[1][0][2].color[0] != white && a[1][0][2].color[2] != white)) {
//				if (a[2][0][1].color[2] == white || a[2][0][1].color[5] == white) {
//					Rotate(2, -3);
//				}
//				if (a[0][0][1].color[2] == white || a[0][0][1].color[4] == white) {
//					Rotate(2, 3);
//				}
//				if (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white) {
//					Rotate(2, -3);
//				}
//				if (a[2][2][1].color[3] == white || a[2][2][1].color[5] == white) {
//					Rotate(1, 3);
//				}
//				if (a[0][2][1].color[3] == white || a[0][2][1].color[4] == white) {
//					Rotate(1, 3);
//				}
//				if (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white) {
//					Rotate(1, -3);
//				}
//				if (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white) {
//					Rotate(1, 3);
//				}
//			}
//			//собрано только 2 наверху вертикаль
//			if (((a[1][0][2].color[0] == white && a[1][2][2].color[0] == white) || (a[1][0][2].color[2] == white && a[1][2][2].color[0] == white) || (a[1][0][2].color[0] == white && a[1][2][2].color[3] == white)) && (a[0][1][2].color[0] != white && a[0][1][2].color[4] != white) && (a[2][1][2].color[0] != white && a[2][1][2].color[5] != white)) {
//				//для синей грани
//				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
//					Rotate(1, -3);
//				}
//				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
//					Rotate(1, -3);
//				}
//				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
//					Rotate(1, -3);
//				}
//				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
//					Rotate(1, -3);
//				}
//				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
//					Rotate(1, -3);
//				}
//				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
//					Rotate(1, -3);
//				}
//				//для зеленой грани
//				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
//					Rotate(1, -3);
//				}
//				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
//					Rotate(1, -3);
//				}
//				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
//					Rotate(1, -3);
//				}
//				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
//					Rotate(1, -3);
//				}
//				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
//					Rotate(1, -3);
//				}
//				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
//					Rotate(1, -3);
//				}
//				//для красной
//				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
//					Rotate(4, -3);
//				}
//				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
//					Rotate(4, -3);
//				}
//				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
//					Rotate(4, -3);
//				}
//				if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
//					Rotate(4, -3);
//				}
//				if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
//					Rotate(4, -3);
//				}
//				if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
//					Rotate(4, -3);
//				}
//				//для оранжевой
//				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
//					Rotate(5, -3);
//				}
//				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
//					Rotate(5, -3);
//				}
//				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
//					Rotate(5, -3);
//				}
//				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
//					Rotate(5, -3);
//				}
//				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
//					Rotate(5, -3);
//				}
//				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
//					Rotate(5, -3);
//				}
//			}
//			//собрано только 2 наверху горизонт
//			if (((a[0][1][2].color[0] == white && a[2][1][2].color[0] == white) || (a[0][1][2].color[4] == white && a[2][1][2].color[0] == white) || (a[0][1][2].color[0] == white && a[2][1][2].color[5] == white)) && (a[1][0][2].color[0] != white && a[1][0][2].color[2] != white) && (a[1][2][2].color[0] != white && a[1][2][2].color[3] != white)) {
//				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
//					Rotate(2, -3);
//				}
//				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
//					Rotate(2, -3);
//				}
//				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
//					Rotate(2, -3);
//				}
//				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
//					Rotate(2, -3);
//				}
//				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
//					Rotate(2, -3);
//				}
//				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
//					Rotate(2, -3);
//				}
//				//для зеленой грани
//				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
//					Rotate(3, -3);
//				}
//				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
//					Rotate(3, -3);
//				}
//				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
//					Rotate(3, -3);
//				}
//				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
//					Rotate(3, -3);
//				}
//				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
//					Rotate(3, -3);
//				}
//				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
//					Rotate(3, -3);
//				}
//				//для красной
//				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
//					Rotate(1, -3);
//				}
//				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
//					Rotate(1, -3);
//				}
//				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
//					Rotate(1, -3);
//				}
//				if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
//					Rotate(1, -3);
//				}
//				if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
//					Rotate(1, -3);
//				}
//				if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
//					Rotate(1, -3);
//				}
//				//для оранжевой
//				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
//					Rotate(1, -3);
//				}
//				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
//					Rotate(1, -3);
//				}
//				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
//					Rotate(1, -3);
//				}
//				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
//					Rotate(1, -3);
//				}
//				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
//					Rotate(1, -3);
//				}
//				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
//					Rotate(1, -3);
//				}
//			}
//			//1 нижний неправильно 2 правильно горизонтально кроме верхней 
//			if (a[1][0][2].color[2] == white && a[0][1][2].color[0] == white && a[2][1][2].color[0] == white && (a[1][2][2].color[0] != white && a[1][2][2].color[3] != white)) {
//				if (a[2][0][1].color[2] == white || a[2][0][1].color[5] == white) {
//					Rotate(1, -3);
//				}
//				if (a[0][0][1].color[2] == white || a[0][0][1].color[4] == white) {
//					Rotate(1, 3);
//				}
//				if (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white) {
//					Rotate(1, -3);
//				}
//				if (a[2][2][1].color[3] == white || a[2][2][1].color[5] == white) {
//					Rotate(3, -3);
//				}
//				if (a[0][2][1].color[3] == white || a[0][2][1].color[4] == white) {
//					Rotate(3, 3);
//				}
//				if (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white) {
//					Rotate(1, -3);
//				}
//			}
//			//1 нижний правильно 2 неправильно левым уголком кроме правой 
//			if (a[1][0][2].color[2] == white && a[0][1][2].color[0] == white && a[1][2][2].color[0] == white && (a[2][1][2].color[0] != white && a[2][1][2].color[5] != white)) {
//				if (a[2][0][1].color[2] == white || a[2][0][1].color[5] == white) {
//					Rotate(1, -3);
//				}
//				if (a[0][0][1].color[2] == white || a[0][0][1].color[4] == white) {
//					Rotate(1, -3);
//				}
//				if (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white) {
//					Rotate(1, -3);
//				}
//				if (a[2][2][1].color[3] == white || a[2][2][1].color[5] == white) {
//					Rotate(1, 3);
//				}
//				if (a[0][2][1].color[3] == white || a[0][2][1].color[4] == white) {
//					Rotate(1, 3);
//				}
//				if (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white) {
//					Rotate(5, -3);
//				}
//			}
//			//1 нижний правильно 2 неправильно правым уголком кроме левой 
//			if (a[1][0][2].color[2] == white && a[2][1][2].color[0] == white && a[1][2][2].color[0] == white && (a[0][1][2].color[0] != white && a[0][1][2].color[4] != white)) {
//				if (a[2][0][1].color[2] == white || a[2][0][1].color[5] == white) {
//					Rotate(1, 3);
//				}
//				if (a[0][0][1].color[2] == white || a[0][0][1].color[4] == white) {
//					Rotate(1, 3);
//				}
//				if (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white) {
//					Rotate(1, 3);
//				}
//				if (a[2][2][1].color[3] == white || a[2][2][1].color[5] == white) {
//					Rotate(1, -3);
//				}
//				if (a[0][2][1].color[3] == white || a[0][2][1].color[4] == white) {
//					Rotate(1, -3);
//				}
//				if (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white) {
//					Rotate(1, -3);
//				}
//			}
//			//1 левый неправильно 2 правильно вертикально кроме правой 
//			if (a[0][1][2].color[4] == white && a[1][2][2].color[0] == white && a[1][0][2].color[0] == white && (a[2][1][2].color[0] != white && a[2][1][2].color[5] != white)) {
//				if (a[2][0][1].color[2] == white || a[2][0][1].color[5] == white) {
//					Rotate(1, -3);
//				}
//				if (a[0][0][1].color[2] == white || a[0][0][1].color[4] == white) {
//					Rotate(1, -3);
//				}
//				if (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white) {
//					Rotate(1, -3);
//				}
//				if (a[2][2][1].color[3] == white || a[2][2][1].color[5] == white) {
//					Rotate(1, 3);
//				}
//				if (a[0][2][1].color[3] == white || a[0][2][1].color[4] == white) {
//					Rotate(1, 3);
//				}
//				if (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white) {
//					Rotate(5, 3);
//				}
//			}
//			//1 левый правильно 2 неправильно правый верхний уголок кроме нижней 
//			if (a[0][1][2].color[4] == white && a[1][2][2].color[0] == white && a[2][1][2].color[0] == white && (a[1][0][2].color[0] != white && a[1][0][2].color[2] != white)) {
//				if (a[2][0][1].color[2] == white || a[2][0][1].color[5] == white) {
//					Rotate(2, -3);
//				}
//				if (a[0][0][1].color[2] == white || a[0][0][1].color[4] == white) {
//					Rotate(2, -3);
//				}
//				if (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white) {
//					Rotate(2, -3);
//				}
//				if (a[2][2][1].color[3] == white || a[2][2][1].color[5] == white) {
//					Rotate(1, 3);
//				}
//				if (a[0][2][1].color[3] == white || a[0][2][1].color[4] == white) {
//					Rotate(1, 3);
//				}
//				if (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white) {
//					Rotate(1, -3);
//				}
//				if (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white) {
//					Rotate(1, 3);
//				}
//			}
//			//1 левый правильно 2 неправильно правый нижний уголок кроме верхней 
//			if (a[0][1][2].color[4] == white && a[2][1][2].color[0] == white && a[1][0][2].color[0] == white && (a[1][2][2].color[0] != white && a[1][2][2].color[3] != white)) {
//				if (a[2][0][1].color[2] == white || a[2][0][1].color[5] == white) {
//					Rotate(1, -3);
//				}
//				if (a[0][0][1].color[2] == white || a[0][0][1].color[4] == white) {
//					Rotate(1, -3);
//				}
//				if (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white) {
//					Rotate(1, -3);
//				}
//				if (a[2][2][1].color[3] == white || a[2][2][1].color[5] == white) {
//					Rotate(3, -3);
//				}
//				if (a[0][2][1].color[3] == white || a[0][2][1].color[4] == white) {
//					Rotate(3, -3);
//				}
//				if (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white) {
//					Rotate(1, -3);
//				}
//			}
//			//1 верхний правильно 2 неправильно горизонтально кроме нижней
//			if (a[0][1][2].color[0] == white && a[1][2][2].color[3] == white && a[2][1][2].color[0] == white && (a[1][0][2].color[0] != white && a[1][0][2].color[2] != white)) {
//				if (a[2][0][1].color[2] == white || a[2][0][1].color[5] == white) {
//					Rotate(2, -3);
//				}
//				if (a[0][0][1].color[2] == white || a[0][0][1].color[4] == white) {
//					Rotate(2, 3);
//				}
//				if (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white) {
//					Rotate(2, -3);
//				}
//				if (a[2][2][1].color[3] == white || a[2][2][1].color[5] == white) {
//					Rotate(1, -3);
//				}
//				if (a[0][2][1].color[3] == white || a[0][2][1].color[4] == white) {
//					Rotate(1, -3);
//				}
//				if (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white) {
//					Rotate(1, -3);
//				}
//				if (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white) {
//					Rotate(1, 3);
//				}
//			}
//			//1 верхний правильно 2 неправильно правый нижний угол кроме левой
//			if (a[2][1][2].color[0] == white && a[1][2][2].color[3] == white && a[1][0][2].color[0] == white && (a[0][1][2].color[0] != white && a[0][1][2].color[4] != white)) {
//				if (a[2][0][1].color[2] == white || a[2][0][1].color[5] == white) {
//					Rotate(1, 3);
//				}
//				if (a[0][0][1].color[2] == white || a[0][0][1].color[4] == white) {
//					Rotate(1, 3);
//				}
//				if (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white) {
//					Rotate(1, 3);
//				}
//				if (a[2][2][1].color[3] == white || a[2][2][1].color[5] == white) {
//					Rotate(1, -3);
//				}
//				if (a[0][2][1].color[3] == white || a[0][2][1].color[4] == white) {
//					Rotate(1, -3);
//				}
//				if (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white) {
//					Rotate(4, -3);
//				}
//				if (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white) {
//					Rotate(1, 3);
//				}
//			}
//			//1 верхний правильно 2 неправильно левый нижний угол кроме правой
//			if (a[0][1][2].color[0] == white && a[1][2][2].color[3] == white && a[1][0][2].color[0] == white && (a[2][1][2].color[0] != white && a[2][1][2].color[5] != white)) {
//				if (a[2][0][1].color[2] == white || a[2][0][1].color[5] == white) {
//					Rotate(1, -3);
//				}
//				if (a[0][0][1].color[2] == white || a[0][0][1].color[4] == white) {
//					Rotate(1, -3);
//				}
//				if (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white) {
//					Rotate(1, -3);
//				}
//				if (a[2][2][1].color[3] == white || a[2][2][1].color[5] == white) {
//					Rotate(1, 3);
//				}
//				if (a[0][2][1].color[3] == white || a[0][2][1].color[4] == white) {
//					Rotate(1, 3);
//				}
//				if (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white) {
//					Rotate(5, -3);
//				}
//			}
//			//1 правый правильно 2 неправильно вертикально кроме левой
//			if (a[1][0][2].color[0] == white && a[1][2][2].color[0] == white && a[2][1][2].color[5] == white && (a[0][1][2].color[0] != white && a[0][1][2].color[4] != white)) {
//				if (a[2][0][1].color[2] == white || a[2][0][1].color[5] == white) {
//					Rotate(1, 3);
//				}
//				if (a[0][0][1].color[2] == white || a[0][0][1].color[4] == white) {
//					Rotate(1, 3);
//				}
//				if (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white) {
//					Rotate(1, 3);
//				}
//				if (a[2][2][1].color[3] == white || a[2][2][1].color[5] == white) {
//					Rotate(1, -3);
//				}
//				if (a[0][2][1].color[3] == white || a[0][2][1].color[4] == white) {
//					Rotate(1, -3);
//				}
//				if (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white) {
//					Rotate(4, 3);
//				}
//				if (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white) {
//					Rotate(1, 3);
//				}
//			}
//			//1 правый правильно 2 неправильно левый нижний уголок кроме верхней
//			if (a[1][0][2].color[0] == white && a[0][1][2].color[0] == white && a[2][1][2].color[5] == white && (a[1][2][2].color[0] != white && a[1][2][2].color[3] != white)) {
//				if (a[2][0][1].color[2] == white || a[2][0][1].color[5] == white) {
//					Rotate(1, 3);
//				}
//				if (a[0][0][1].color[2] == white || a[0][0][1].color[4] == white) {
//					Rotate(1, 3);
//				}
//				if (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white) {
//					Rotate(1, 3);
//				}
//				if (a[2][2][1].color[3] == white || a[2][2][1].color[5] == white) {
//					Rotate(3, -3);
//				}
//				if (a[0][2][1].color[3] == white || a[0][2][1].color[4] == white) {
//					Rotate(3, -3);
//				}
//				if (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white) {
//					Rotate(1, -3);
//				}
//			}
//			//1 правый правильно 2 неправильно левый верхний уголок кроме нижней
//			if (a[1][2][2].color[0] == white && a[0][1][2].color[0] == white && a[2][1][2].color[5] == white && (a[1][0][2].color[0] != white && a[1][0][2].color[2] != white)) {
//				if (a[2][0][1].color[2] == white || a[2][0][1].color[5] == white) {
//					Rotate(2, -3);
//				}
//				if (a[0][0][1].color[2] == white || a[0][0][1].color[4] == white) {
//					Rotate(2, 3);
//				}
//				if (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white) {
//					Rotate(2, -3);
//				}
//				if (a[2][2][1].color[3] == white || a[2][2][1].color[5] == white) {
//					Rotate(1, 3);
//				}
//				if (a[0][2][1].color[3] == white || a[0][2][1].color[4] == white) {
//					Rotate(1, 3);
//				}
//				if (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white) {
//					Rotate(1, -3);
//				}
//				if (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white) {
//					Rotate(1, 3);
//				}
//			}
//			//3 белых правильно и все (лево низ верх по часовой) кроме верха
//			if (a[0][1][2].color[0] == white && a[1][0][2].color[0] == white && a[2][1][2].color[0] == white && (a[1][2][2].color[0] != white && a[1][2][2].color[3] != white)) {
//				/*if (a[2][0][1].color[2] == white || a[2][0][1].color[5] == white) {
//					Rotate(1, -3);
//				}*/
//				/*if (a[0][0][1].color[2] == white || a[0][0][1].color[4] == white) {
//					Rotate(1, 3);
//				}*/
//				if (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white) {
//					Rotate(1, -3);
//				}
//				if (a[2][2][1].color[3] == white || a[2][2][1].color[5] == white) {
//					Rotate(3, -3);
//				}
//				if (a[0][2][1].color[3] == white && a[0][2][1].color[4] != white) {
//					Rotate(1, 3);
//				}
//				if (a[0][2][1].color[3] != white && a[0][2][1].color[4] == white) {
//					if (a[0][2][1].color[3] == green) {
//						if (a[0][2][0].color[1] == white) {
//							if (a[0][2][0].color[4] == red && a[0][2][0].color[3] == blue) {
//								Rotate(0, 3);
//							}
//							if (a[0][2][0].color[4] == blue && a[0][2][0].color[3] == orange) {
//								Rotate(0, 3);
//							}
//							if (a[0][2][0].color[4] == orange && a[0][2][0].color[3] == green) {
//								Rotate(0, 3);
//							}
//							if (a[0][2][0].color[4] == green && a[0][2][0].color[3] == red) {
//								Rotate(0, 3);
//							}
//						}
//
//						if (a[0][2][0].color[4] == white) {
//							if (a[0][2][0].color[3] == red && a[0][2][0].color[1] == blue) {
//								Rotate(0, 3);
//							}
//							if (a[0][2][0].color[3] == blue && a[0][2][0].color[1] == orange) {
//								Rotate(0, 3);
//							}
//							if (a[0][2][0].color[3] == orange && a[0][2][0].color[1] == green) {
//								Rotate(0, 3);
//							}
//							if (a[0][2][0].color[3] == green && a[0][2][0].color[1] == red) {
//								Rotate(3, 3);
//							}
//						}
//						if (a[0][0][0].color[1] == white) {
//							if (a[0][0][0].color[4] == blue && a[0][0][0].color[2] == red) {
//								Rotate(3, 3);
//							}
//							if (a[0][0][0].color[4] == orange && a[0][0][0].color[2] == blue) {
//								Rotate(3, 3);
//							}
//							if (a[0][0][0].color[4] == green && a[0][0][0].color[2] == orange) {
//								Rotate(3, 3);
//							}
//							if (a[0][0][0].color[4] == red && a[0][0][0].color[2] == green) {
//								Rotate(3, 3);
//							}
//						}
//						if (a[0][2][0].color[3] == white) {
//							if (a[0][2][0].color[4] == blue && a[0][2][0].color[1] == red) {
//								Rotate(0, 3);
//							}
//							if (a[0][2][0].color[4] == orange && a[0][2][0].color[1] == blue) {
//								Rotate(0, 3);
//							}
//							if (a[0][2][0].color[4] == green && a[0][2][0].color[1] == orange) {
//								Rotate(0, 3);
//							}
//							if (a[0][2][0].color[4] == red && a[0][2][0].color[1] == green) {
//								Rotate(0, 3);
//							}
//						}
//						if (a[0][0][0].color[4] == white) {
//							if (a[0][0][0].color[2] == blue && a[0][0][0].color[1] == red) {
//								Rotate(3, 3);
//							}
//							if (a[0][0][0].color[2] == orange && a[0][0][0].color[1] == blue) {
//								Rotate(3, 3);
//							}
//							if (a[0][0][0].color[2] == green && a[0][0][0].color[1] == orange) {
//								Rotate(3, 3);
//							}
//							if (a[0][0][0].color[2] == red && a[0][0][0].color[1] == green) {
//								Rotate(3, 3);
//							}
//						}
//						if (a[0][0][0].color[2] == white) {
//							if (a[0][0][0].color[4] == red && a[0][0][0].color[1] == blue) {
//								Rotate(3, 3);
//							}
//							if (a[0][0][0].color[4] == blue && a[0][0][0].color[1] == orange) {
//								Rotate(3, 3);
//							}
//							if (a[0][0][0].color[4] == orange && a[0][0][0].color[1] == green) {
//								Rotate(3, 3);
//							}
//							if (a[0][0][0].color[4] == green && a[0][0][0].color[1] == red) {
//								Rotate(0, -3);
//							}
//						}
//						if (a[2][2][0].color[5] == white) {
//							if (a[2][2][0].color[3] == red && a[2][2][0].color[1] == green) {
//								Rotate(0, 3);
//							}
//							if (a[2][2][0].color[3] == blue && a[2][2][0].color[1] == red) {
//								Rotate(3, 3);
//							}
//
//						}
//						if (a[2][2][0].color[3] == white) {
//							if (a[2][2][0].color[1] == red && a[2][2][0].color[5] == green) {
//								Rotate(0, 3);
//							}
//							if (a[2][2][0].color[1] == blue && a[2][2][0].color[5] == red) {
//								Rotate(3, 3);
//							}
//						}
//						if (a[2][2][0].color[1] == white) {
//							if (a[2][2][0].color[5] == blue && a[2][2][0].color[3] == red) {
//								Rotate(3, 3);
//							}
//						}
//						if (a[2][0][0].color[1] == white) {
//							if (a[2][0][0].color[5] == red && a[2][0][0].color[2] == blue) {
//								Rotate(3, 3);
//							}
//							if (a[2][0][0].color[5] == green && a[2][0][0].color[2] == red) {
//								Rotate(0, 3);
//							}
//						}
//						if (a[2][0][0].color[2] == white) {
//							if (a[2][0][0].color[1] == red && a[2][0][0].color[5] == blue) {
//								Rotate(3, 3);
//							}
//							if (a[2][0][0].color[1] == green && a[2][0][0].color[5] == red) {
//								Rotate(0, 3);
//							}
//						}
//						if (a[2][0][0].color[5] == white) {
//							if (a[2][0][0].color[2] == red && a[2][0][0].color[1] == blue) {
//								Rotate(3, 3);
//							}
//							if (a[2][0][0].color[2] == green && a[2][0][0].color[1] == red) {
//								Rotate(0, 3);
//							}
//						}
//					}
//					if (a[0][2][1].color[3] == blue) {
//						Rotate(3, 3);
//					}
//				}
//				if (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white) {
//					Rotate(3, -3);
//				}
//				if (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white) {
//					Rotate(1, -3);
//				}
//			}
//			//кроме права
//			if (a[0][1][2].color[0] == white && a[1][2][2].color[0] == white && a[1][0][2].color[0] == white && (a[2][1][2].color[0] != white && a[2][1][2].color[5] != white)) {
//				/*if (a[2][0][1].color[2] == white || a[2][0][1].color[5] == white) {
//					Rotate(1, -3);
//				}*/
//				if (a[2][0][1].color[2] == white && a[2][0][1].color[5] != white) {
//					if (a[2][0][1].color[5] == orange) {
//						if (a[2][0][0].color[2] == white) {
//							if (a[2][0][0].color[1] == red && a[2][0][0].color[5] == blue) {
//								Rotate(0, 3);
//							}
//						}
//						if (a[2][0][0].color[5] == white) {
//							if (a[2][0][0].color[2] == red && a[2][0][0].color[1] == blue) {
//								Rotate(0, 3);
//							}
//						}
//						if (a[2][0][0].color[1] == white) {
//							if (a[2][0][0].color[5] == red && a[2][0][0].color[2] == blue) {
//								Rotate(0, 3);
//							}
//						}
//						if (a[2][0][0].color[2] != white) {
//							if (a[2][0][0].color[1] != red && a[2][0][0].color[5] != blue) {
//								Rotate(5, -3);
//							}
//						}
//						if (a[2][0][0].color[5] != white) {
//							if (a[2][0][0].color[2] != red && a[2][0][0].color[1] != blue) {
//								Rotate(5, -3);
//							}
//						}
//						if (a[2][0][0].color[1] != white) {
//							if (a[2][0][0].color[5] != red && a[2][0][0].color[2] != blue) {
//								Rotate(5, -3);
//							}
//						}
//					}
//				}
//				if (a[0][0][1].color[2] == white || a[0][0][1].color[4] == white) {
//					Rotate(1, -3);
//				}
//				if (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white) {
//					Rotate(1, -3);
//				}
//				if (a[2][2][1].color[3] != white && a[2][2][1].color[5] == white) {
//					Rotate(1, 3);
//				}
//				if (a[2][2][1].color[3] == white && a[2][2][1].color[5] != white) {
//					if (a[2][2][1].color[5] == orange) {
//						if (a[2][2][0].color[1] == white)
//						{
//							if (a[2][2][0].color[3] == red && a[2][2][0].color[5] == blue) {
//								Rotate(0, 3);
//							}
//							if (a[2][2][0].color[3] == blue && a[2][2][0].color[5] == orange) {
//								Rotate(0, 3);
//							}
//							if (a[2][2][0].color[3] == orange && a[2][2][0].color[5] == green) {
//								Rotate(0, 3);
//							}
//						}
//						if (a[0][2][0].color[1] == white) {
//							if (a[0][2][0].color[4] == red && a[0][2][0].color[3] == blue) {
//								Rotate(5, 3);
//							}
//							if (a[0][2][0].color[4] == blue && a[0][2][0].color[3] == orange) {
//								Rotate(5, 3);
//							}
//							if (a[0][2][0].color[4] == orange && a[0][2][0].color[3] == green) {
//								Rotate(5, 3);
//							}
//							if (a[0][2][0].color[4] == green && a[0][2][0].color[3] == red && (a[2][2][0].color[1] != white && a[2][2][0].color[3] != blue && a[2][2][0].color[5] != orange) && (a[2][2][0].color[5] != white && a[2][2][0].color[1] != blue && a[2][2][0].color[3] != orange) && (a[2][2][0].color[3] != white && a[2][2][0].color[5] != blue && a[2][2][0].color[1] != orange)) {
//								Rotate(5, 3);
//							}
//						}
//						if (a[2][2][0].color[5] == white)
//						{
//							if (a[2][2][0].color[1] == red && a[2][2][0].color[3] == blue) {
//								Rotate(0, 3);
//							}
//							if (a[2][2][0].color[1] == blue && a[2][2][0].color[3] == orange) {
//								Rotate(0, 3);
//							}
//							if (a[2][2][0].color[1] == orange && a[2][2][0].color[3] == green) {
//								Rotate(0, 3);
//							}
//						}
//						if (a[0][2][0].color[3] == white) {
//							if (a[0][2][0].color[4] == blue && a[0][2][0].color[1] == red) {
//								Rotate(5, 3);
//							}
//							if (a[0][2][0].color[4] == orange && a[0][2][0].color[1] == blue) {
//								Rotate(5, 3);
//							}
//							if (a[0][2][0].color[1] == orange && a[0][2][0].color[4] == green) {
//								Rotate(5, 3);
//							}
//							if (a[0][2][0].color[1] == green && a[0][2][0].color[4] == red && (a[2][2][0].color[1] != white && a[2][2][0].color[3] != blue && a[2][2][0].color[5] != orange) && (a[2][2][0].color[5] != white && a[2][2][0].color[1] != blue && a[2][2][0].color[3] != orange) && (a[2][2][0].color[3] != white && a[2][2][0].color[5] != blue && a[2][2][0].color[1] != orange)) {
//								Rotate(5, 3);
//							}
//						}
//						if (a[2][2][0].color[3] == white)
//						{
//							if (a[2][2][0].color[5] == red && a[2][2][0].color[1] == blue) {
//								Rotate(0, 3);
//							}
//							if (a[2][2][0].color[1] == orange && a[2][2][0].color[5] == blue) {
//								Rotate(0, 3);
//							}
//							if (a[2][2][0].color[5] == orange && a[2][2][0].color[1] == green) {
//								Rotate(5, 3);
//							}
//
//						}
//						if (a[0][2][0].color[4] == white) {
//							if (a[0][2][0].color[3] == red && a[0][2][0].color[1] == blue) {
//								Rotate(5, 3);
//							}
//							if (a[0][2][0].color[3] == blue && a[0][2][0].color[1] == orange) {
//								Rotate(5, 3);
//							}
//							if (a[0][2][0].color[3] == orange && a[0][2][0].color[1] == green) {
//								Rotate(0, -3);
//							}
//							if (a[0][2][0].color[1] == red && a[0][2][0].color[3] == green && (a[2][2][0].color[1] != white && a[2][2][0].color[3] != blue && a[2][2][0].color[5] != orange) && (a[2][2][0].color[5] != white && a[2][2][0].color[1] != blue && a[2][2][0].color[3] != orange) && (a[2][2][0].color[3] != white && a[2][2][0].color[5] != blue && a[2][2][0].color[1] != orange)) {
//								Rotate(5, 3);
//							}
//						}
//						if (a[2][0][0].color[2] == white) {
//							if (a[2][0][0].color[1] == orange && a[2][0][0].color[5] == green) {
//								Rotate(0, 3);
//							}
//						}
//						if (a[2][0][0].color[5] == white) {
//							if (a[2][0][0].color[2] == orange && a[2][0][0].color[1] == green) {
//								Rotate(0, 3);
//							}
//						}
//						if (a[2][0][0].color[1] == white) {
//							if (a[2][0][0].color[5] == orange && a[2][0][0].color[2] == green) {
//								Rotate(0, 3);
//							}
//						}
//					}
//				}
//				if (a[0][2][1].color[3] == white && a[0][2][1].color[4] != white) {
//					Rotate(1, 3);
//				}
//				/*if (a[0][2][1].color[3] != white && a[0][2][1].color[4] == white) {
//					if (a[0][2][1].color[3] == green) {
//						if (a[0][2][0].color[1] == white) {
//							if (a[0][2][0].color[4] == red && a[0][2][0].color[3] == blue) {
//								Rotate(0, 3);
//
//							}
//						}
//						if (a[0][0][0].color[1] == white) {
//							if (a[0][0][0].color[4] == blue && a[0][0][0].color[2] == red) {
//								Rotate(3, 3);
//							}
//						}
//						if (a[0][2][0].color[3] == white) {
//							if (a[0][2][0].color[4] == blue && a[0][2][0].color[1] == red) {
//								Rotate(0, 3);
//
//							}
//						}
//						if (a[0][0][0].color[4] == white) {
//							if (a[0][0][0].color[2] == blue && a[0][0][0].color[1] == red) {
//								Rotate(3, 3);
//							}
//						}
//						if (a[0][2][0].color[4] == white) {
//							if (a[0][2][0].color[3] == red && a[0][2][0].color[1] == blue) {
//								Rotate(0, 3);
//
//							}
//						}
//						if (a[0][0][0].color[2] == white) {
//							if (a[0][0][0].color[4] == red && a[0][0][0].color[1] == blue) {
//								Rotate(3, 3);
//							}
//						}
//					}
//				}*/
//				if (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white) {
//					Rotate(1, 3);
//				}
//				if (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white) {
//					Rotate(5, 3);
//				}
//			}
//			//кроме низа
//			if (a[0][1][2].color[0] == white && a[1][2][2].color[0] == white && a[2][1][2].color[0] == white && (a[1][0][2].color[0] != white && a[1][0][2].color[2] != white)) {
//				if (a[2][0][1].color[2] == white && a[2][0][1].color[5] != white) {
//					Rotate(2, -3);
//				}
//				//синий угол правильный
//				if (a[2][0][1].color[2] != white && a[2][0][1].color[5] == white) {
//					if (a[2][0][1].color[2] == blue && a[2][0][2].color[5] == white && a[2][0][2].color[0] == red && a[2][0][2].color[2] == blue) {
//						if (a[0][0][0].color[4] == white) {
//							if (a[0][0][0].color[2] == orange && a[0][0][0].color[1] == blue) {
//								Rotate(0, 3);
//
//							}
//						}
//						if (a[2][0][0].color[2] == white) {
//							if (a[2][0][0].color[1] == blue && a[2][0][0].color[5] == orange) {
//								Rotate(0, 3);
//
//							}
//						}
//						if (a[2][0][0].color[5] == white) {
//							if (a[2][0][0].color[2] == blue && a[2][0][0].color[1] == orange) {
//								Rotate(2, -3);
//
//							}
//						}
//						if (a[0][0][0].color[2] == white) {
//							if (a[0][0][0].color[1] == orange && a[0][0][0].color[4] == blue) {
//								Rotate(0, 3);
//
//							}
//						}
//						if (a[0][0][0].color[1] == white) {
//							if (a[0][0][0].color[4] == orange && a[0][0][0].color[2] == blue) {
//								Rotate(0, 3);
//
//							}
//						}
//						if (a[2][2][0].color[3] == white) {
//							if (a[2][2][0].color[5] == blue && a[2][2][0].color[1] == orange) {
//								Rotate(0, -3);
//							}
//							if (a[2][2][0].color[5] == orange && a[2][2][0].color[1] == green) {
//								Rotate(2, -3);
//							}
//						}
//						if (a[2][0][0].color[1] == white) {
//							if (a[2][0][0].color[5] == blue && a[2][0][0].color[2] == orange) {
//								Rotate(0, 3);
//
//							}
//						}
//						if (a[2][2][0].color[1] == white) {
//							if (a[2][2][0].color[3] == blue && a[2][2][0].color[5] == orange) {
//								Rotate(2, -3);
//							}
//							if (a[2][2][0].color[3] == orange && a[2][2][0].color[5] == green) {
//								Rotate(2, -3);
//							}
//						}
//						if (a[2][2][0].color[5] == white) {
//							if (a[2][2][0].color[1] == blue && a[2][2][0].color[3] == orange) {
//								Rotate(2, -3);
//							}
//							if (a[2][2][0].color[1] == orange && a[2][2][0].color[3] == green) {
//								Rotate(2, -3);
//							}
//						}
//					}
//					else {
//						Rotate(2, -3);
//					}
//				}
//				/*if (a[0][0][1].color[2] == white || a[0][0][1].color[4] == white) {
//					Rotate(2, 3);
//				}*/
//				if (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white) {
//					Rotate(2, -3);
//				}
//				if (a[2][2][1].color[3] == white || a[2][2][1].color[5] == white) {
//					Rotate(1, -3);
//				}
//				if (a[0][2][1].color[3] == white || a[0][2][1].color[4] == white) {
//					Rotate(1, -3);
//				}
//				if (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white) {
//					Rotate(1, -3);
//				}
//				if (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white) {
//					Rotate(1, 3);
//				}
//			}
//			//кроме лева
//			if (a[1][0][2].color[0] == white && a[1][2][2].color[0] == white && a[2][1][2].color[0] == white && (a[0][1][2].color[0] != white && a[0][1][2].color[4] != white)) {
//				if (a[2][0][1].color[2] == white && a[2][0][1].color[5] != white) {
//					Rotate(1, 3);
//				}
//				if (a[2][0][1].color[2] != white && a[2][0][1].color[5] == white) {
//					Rotate(1, 3);
//				}
//				//1 пиф паф левый нижний угол
//				if (a[0][0][1].color[2] == white && a[0][0][1].color[4] != white) {
//					if (a[0][0][1].color[4] == red) {
//						if (a[0][0][0].color[4] == white) {
//							if ((a[0][0][0].color[2] == blue && a[0][0][0].color[1] == red) || (a[0][0][0].color[2] == red && a[0][0][0].color[1] == blue)) {
//								Rotate(0, 3);
//							}
//						}
//						if (a[2][0][0].color[2] == white) {
//							if ((a[2][0][0].color[5] == blue && a[2][0][0].color[1] == red) || (a[2][0][0].color[5] == red && a[2][0][0].color[1] == blue)) {
//								Rotate(4, -3);
//							}
//						}
//						if (a[0][2][0].color[4] == white) {
//							if ((a[0][2][0].color[3] == blue && a[0][2][0].color[1] == red) || (a[0][2][0].color[3] == red && a[0][2][0].color[1] == blue)) {
//								Rotate(0, 3);
//							}
//						}
//						if (a[0][0][0].color[2] == white) {
//							if ((a[0][0][0].color[4] == blue && a[0][0][0].color[1] == red) || (a[0][0][0].color[4] == red && a[0][0][0].color[1] == blue)) {
//								Rotate(4, -3);
//							}
//						}
//						if (a[0][0][0].color[1] == white) {
//							if ((a[0][0][0].color[4] == blue && a[0][0][0].color[2] == red) || (a[0][0][0].color[4] == red && a[0][0][0].color[2] == blue)) {
//								Rotate(0, 3);
//							}
//						}
//						if (a[2][0][0].color[1] == white) {
//							if ((a[2][0][0].color[2] == red && a[2][0][0].color[5] == blue) || (a[2][0][0].color[2] == blue && a[2][0][0].color[5] == red)) {
//								Rotate(4, -3);
//							}
//						}
//						if (a[0][2][0].color[3] == white) {
//							if ((a[0][2][0].color[4] == blue && a[0][2][0].color[1] == red) || (a[0][2][0].color[4] == red && a[0][2][0].color[1] == blue)) {
//								Rotate(0, 3);
//							}
//						}
//						if (a[2][0][0].color[5] == white) {
//							if ((a[2][0][0].color[2] == red && a[2][0][0].color[1] == blue) || (a[2][0][0].color[2] == blue && a[2][0][0].color[1] == red)) {
//								Rotate(0, -3);
//							}
//						}
//					}
//				}
//				/*if (a[0][0][1].color[2] != white && a[0][0][1].color[4] == white) {
//					Rotate(1, 3);
//				}*/
//				if (a[1][0][0].color[2] == white && a[1][0][0].color[1] != white) {
//					Rotate(1, 3);
//				}
//				if (a[1][0][0].color[2] != white && a[1][0][0].color[1] == white) {
//					Rotate(1, 3);
//				}
//				if (a[2][2][1].color[3] == white && a[2][2][1].color[5] != white) {
//					Rotate(1, -3);
//				}
//				if (a[2][2][1].color[3] != white && a[2][2][1].color[5] == white) {
//					Rotate(1, -3);
//				}
//				if (a[0][2][1].color[3] == white && a[0][2][1].color[4] != white) {
//					Rotate(1, -3);
//				}
//				if (a[0][2][1].color[3] != white && a[0][2][1].color[4] == white) {
//					Rotate(1, -3);
//				}
//				if (a[1][2][0].color[3] == white && a[1][2][0].color[1] != white) {
//					Rotate(1, -3);
//				}
//				if (a[1][2][0].color[3] != white && a[1][2][0].color[1] == white) {
//					Rotate(1, -3);
//				}
//				if (a[0][1][0].color[4] == white && a[0][1][0].color[1] != white) {
//					Rotate(4, 3);
//				}
//				if (a[0][1][0].color[4] != white && a[0][1][0].color[1] == white) {
//					Rotate(4, 3);
//				}
//				if (a[2][1][0].color[5] == white && a[2][1][0].color[1] != white) {
//					Rotate(1, 3);
//				}
//				if (a[2][1][0].color[5] != white && a[2][1][0].color[1] == white) {
//					Rotate(1, 3);
//				}
//			}
//			//1 снизу (оба варианта)
//			if ((a[1][0][2].color[0] == white || a[1][0][2].color[2] == white) && (a[0][1][2].color[4] != white && a[0][1][2].color[0] != white) && (a[2][1][2].color[0] != white && a[2][1][2].color[5] != white) && (a[1][2][2].color[0] != white && a[1][2][2].color[3] != white)) {
//				//для синей грани
//				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
//					Rotate(1, -3);
//				}
//				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
//					Rotate(1, -3);
//				}
//				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
//					Rotate(1, -3);
//				}
//				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
//					Rotate(1, -3);
//				}
//				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
//					Rotate(1, -3);
//				}
//				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
//					Rotate(1, -3);
//				}
//				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
//					Rotate(1, -3);
//				}
//				//для зеленой грани
//				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
//					Rotate(3, -3);
//				}
//				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
//					Rotate(3, -3);
//				}
//				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
//					Rotate(3, -3);
//				}
//				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
//					Rotate(3, -3);
//				}
//				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
//					Rotate(3, -3);
//				}
//				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
//					Rotate(3, -3);
//				}
//				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
//					Rotate(3, -3);
//				}
//				//для красной
//				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
//					Rotate(4, 3);
//				}
//				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
//					Rotate(4, -3);
//				}
//				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
//					Rotate(4, 3);
//				}
//				if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
//					Rotate(4, -3);
//				}
//				if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
//					Rotate(4, -3);
//				}
//				if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
//					Rotate(4, -3);
//				}
//				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
//					Rotate(4, -3);
//				}
//				//для оранжевой
//				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
//					Rotate(5, 3);
//				}
//				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
//					Rotate(5, -3);
//				}
//				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
//					Rotate(5, 3);
//				}
//				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
//					Rotate(5, -3);
//				}
//				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
//					Rotate(5, -3);
//				}
//				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
//					Rotate(5, -3);
//				}
//				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
//					Rotate(5, -3);
//				}
//			}
//			//слева
//			if ((a[0][1][2].color[0] == white || a[0][1][2].color[4] == white) && (a[1][0][2].color[0] != white && a[1][0][2].color[2] != white) && (a[2][1][2].color[0] != white && a[2][1][2].color[5] != white) && (a[1][2][2].color[0] != white && a[1][2][2].color[3] != white)) {
//				//для синей грани
//				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
//					Rotate(2, -3);
//				}
//				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
//					Rotate(2, -3);
//				}
//				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
//					Rotate(2, -3);
//				}
//				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
//					Rotate(2, 3);
//				}
//				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
//					Rotate(2, 3);
//				}
//				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
//					Rotate(2, -3);
//				}
//				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
//					Rotate(2, -3);
//				}
//				//для зеленой грани
//				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
//					Rotate(3, -3);
//				}
//				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
//					Rotate(3, -3);
//				}
//				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
//					Rotate(3, -3);
//				}
//				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
//					Rotate(3, 3);
//				}
//				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
//					Rotate(3, 3);
//				}
//				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
//					Rotate(3, -3);
//				}
//				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
//					Rotate(3, -3);
//				}
//				//для красной
//				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
//					Rotate(1, -3);
//				}
//				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
//					Rotate(1, -3);
//				}
//				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
//					Rotate(1, -3);
//				}
//				if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
//					Rotate(1, -3);
//				}
//				if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
//					Rotate(1, -3);
//				}
//				if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
//					Rotate(1, -3);
//				}
//				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
//					Rotate(1, -3);
//				}
//				//для оранжевой
//				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
//					Rotate(5, 3);
//				}
//				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
//					Rotate(5, -3);
//				}
//				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
//					Rotate(5, 3);
//				}
//				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
//					Rotate(5, -3);
//				}
//				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
//					Rotate(5, -3);
//				}
//				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
//					Rotate(5, -3);
//				}
//				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
//					Rotate(5, -3);
//				}
//			}
//
//			//сверху
//			if ((a[1][2][2].color[0] == white || a[1][2][2].color[3] == white) && (a[0][1][2].color[4] != white && a[0][1][2].color[0] != white) && (a[2][1][2].color[0] != white && a[2][1][2].color[5] != white) && (a[1][0][2].color[0] != white && a[1][0][2].color[2] != white)) {
//				//для синей грани
//				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
//					Rotate(2, -3);
//				}
//				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
//					Rotate(2, -3);
//				}
//				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
//					Rotate(2, -3);
//				}
//				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
//					Rotate(2, 3);
//				}
//				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
//					Rotate(2, 3);
//				}
//				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
//					Rotate(2, -3);
//				}
//				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
//					Rotate(2, -3);
//				}
//				//для зеленой грани
//				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
//					Rotate(1, -3);
//				}
//				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
//					Rotate(1, -3);
//				}
//				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
//					Rotate(1, -3);
//				}
//				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
//					Rotate(1, -3);
//				}
//				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
//					Rotate(1, -3);
//				}
//				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
//					Rotate(1, -3);
//				}
//				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
//					Rotate(1, -3);
//				}
//				//для красной
//				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
//					Rotate(4, 3);
//				}
//				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
//					Rotate(4, -3);
//				}
//				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
//					Rotate(4, 3);
//				}
//				if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
//					Rotate(4, -3);
//				}
//				if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
//					Rotate(4, -3);
//				}
//				if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
//					Rotate(4, -3);
//				}
//				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
//					Rotate(4, -3);
//				}
//				//для оранжевой
//				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
//					Rotate(5, 3);
//				}
//				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
//					Rotate(5, -3);
//				}
//				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
//					Rotate(5, 3);
//				}
//				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
//					Rotate(5, -3);
//				}
//				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
//					Rotate(5, -3);
//				}
//				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
//					Rotate(5, -3);
//				}
//				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
//					Rotate(5, -3);
//				}
//			}
//			//справа
//			if ((a[2][1][2].color[0] == white || a[2][1][2].color[5] == white) && (a[0][1][2].color[4] != white && a[0][1][2].color[0] != white) && (a[1][0][2].color[0] != white && a[1][0][2].color[2] != white) && (a[1][2][2].color[0] != white && a[1][2][2].color[3] != white)) {
//				//для синей грани
//				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
//					Rotate(2, -3);
//				}
//				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
//					Rotate(2, -3);
//				}
//				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
//					Rotate(2, -3);
//				}
//				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
//					Rotate(2, 3);
//				}
//				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
//					Rotate(2, 3);
//				}
//				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
//					Rotate(2, -3);
//				}
//				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
//					Rotate(2, -3);
//				}
//				//для зеленой грани
//				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
//					Rotate(3, -3);
//				}
//				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
//					Rotate(3, -3);
//				}
//				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
//					Rotate(3, -3);
//				}
//				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
//					Rotate(3, 3);
//				}
//				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
//					Rotate(3, 3);
//				}
//				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
//					Rotate(3, -3);
//				}
//				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
//					Rotate(3, -3);
//				}
//				//для красной
//				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
//					Rotate(4, 3);
//				}
//				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
//					Rotate(4, -3);
//				}
//				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
//					Rotate(4, 3);
//				}
//				if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
//					Rotate(4, -3);
//				}
//				if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
//					Rotate(4, -3);
//				}
//				if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
//					Rotate(4, -3);
//				}
//				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
//					Rotate(4, -3);
//				}
//				//для оранжевой
//				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
//					Rotate(1, -3);
//				}
//				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
//					Rotate(1, -3);
//				}
//				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
//					Rotate(1, -3);
//				}
//				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
//					Rotate(1, -3);
//				}
//				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
//					Rotate(1, -3);
//				}
//				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
//					Rotate(1, -3);
//				}
//				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
//					Rotate(1, -3);
//				}
//			}
//			//0 правильных 
//			if (a[0][1][2].color[0] != white && a[0][1][2].color[4] != white && a[1][0][2].color[0] != white && a[1][0][2].color[2] != white && a[1][2][2].color[0] != white && a[1][2][2].color[3] != white && a[2][1][2].color[0] != white && a[2][1][2].color[5] != white) {
//				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
//					Rotate(2, -3);
//				}
//				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
//					Rotate(2, -3);
//				}
//				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
//					Rotate(2, -3);
//				}
//				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
//					Rotate(2, 3);
//				}
//				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] != white && a[1][0][0].color[1] != white)) {
//					Rotate(2, 3);
//				}
//				if ((a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
//					Rotate(2, -3);
//				}
//				if ((a[2][0][1].color[2] == white) && (a[0][0][1].color[2] == white) && (a[1][0][0].color[2] == white || a[1][0][0].color[1] == white)) {
//					Rotate(2, -3);
//				}
//				//для зеленой грани
//				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
//					Rotate(3, -3);
//				}
//				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
//					Rotate(3, -3);
//				}
//				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
//					Rotate(3, -3);
//				}
//				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
//					Rotate(3, 3);
//				}
//				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] != white && a[1][2][0].color[1] != white)) {
//					Rotate(3, 3);
//				}
//				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
//					Rotate(3, -3);
//				}
//				if ((a[2][2][1].color[3] == white) && (a[0][2][1].color[3] == white) && (a[1][2][0].color[3] == white || a[1][2][0].color[1] == white)) {
//					Rotate(3, -3);
//				}
//				//для красной
//				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
//					Rotate(4, 3);
//				}
//				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
//					Rotate(4, -3);
//				}
//				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
//					Rotate(4, 3);
//				}
//				if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
//					Rotate(4, -3);
//				}
//				if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] != white && a[0][1][0].color[1] != white)) {
//					Rotate(4, -3);
//				}
//				if ((a[0][2][1].color[3] != white && a[0][2][1].color[4] != white) && (a[0][0][1].color[2] != white && a[0][0][1].color[4] != white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
//					Rotate(4, -3);
//				}
//				if ((a[0][2][1].color[4] == white) && (a[0][0][1].color[4] == white) && (a[0][1][0].color[4] == white || a[0][1][0].color[1] == white)) {
//					Rotate(4, -3);
//				}
//				//для оранжевой
//				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
//					Rotate(5, -3);
//				}
//				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
//					Rotate(5, -3);
//				}
//				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
//					Rotate(5, -3);
//				}
//				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
//					Rotate(5, -3);
//				}
//				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] != white && a[2][1][0].color[1] != white)) {
//					Rotate(5, -3);
//				}
//				if ((a[2][2][1].color[3] != white && a[2][2][1].color[5] != white) && (a[2][0][1].color[2] != white && a[2][0][1].color[5] != white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
//					Rotate(5, -3);
//				}
//				if ((a[2][2][1].color[5] == white) && (a[2][0][1].color[5] == white) && (a[2][1][0].color[5] == white || a[2][1][0].color[1] == white)) {
//					Rotate(5, -3);
//				}
//			}
//		}
//	}
//	void F2L() {
//		//setting combination flags
//		if (start == 0) {
//			if (a[0][2][2].color[0] == white && a[0][2][2].color[4] == red && a[0][2][2].color[3] == green && a[0][1][0].color[1] == green && a[0][1][0].color[4] == red) {
//				rg = 1;
//				combination = 1;
//				start = 1;
//			}
//			else if (a[2][2][2].color[0] == white && a[2][2][2].color[5] == orange && a[2][2][2].color[3] == green && a[1][2][0].color[1] == orange && a[1][2][0].color[3] == green) {
//				og = 1;
//				combination = 1;
//				start = 1;
//			}
//			else if (a[2][0][2].color[0] == white && a[2][0][2].color[5] == orange && a[2][0][2].color[2] == blue && a[2][1][0].color[1] == blue && a[2][1][0].color[5] == orange) {
//				ob = 1;
//				combination = 1;
//				start = 1;
//			}
//			else if (a[0][0][2].color[0] == white && a[0][0][2].color[4] == red && a[0][0][2].color[2] == blue && a[1][0][0].color[1] == red && a[1][0][0].color[2] == blue) {
//				rb = 1;
//				combination = 1;
//				start = 1;
//			}
//			else if (a[0][2][2].color[0] == white && a[0][2][2].color[4] == red && a[0][2][2].color[3] == green && a[1][2][0].color[1] == red && a[1][2][0].color[3] == green) {
//				rg = 1;
//				combination = 2;
//				start = 1;
//			}
//			else if (a[2][2][2].color[0] == white && a[2][2][2].color[5] == orange && a[2][2][2].color[3] == green && a[2][1][0].color[5] == orange && a[2][1][0].color[1] == green) {
//				og = 1;
//				combination = 2;
//				start = 1;
//			}
//			else if (a[2][0][2].color[0] == white && a[2][0][2].color[5] == orange && a[2][0][2].color[2] == blue && a[1][0][0].color[1] == orange && a[1][0][0].color[2] == blue) {
//				ob = 1;
//				combination = 2;
//				start = 1;
//
//			}
//			else if (a[0][0][2].color[0] == white && a[0][0][2].color[4] == red && a[0][0][2].color[2] == blue && a[0][1][0].color[1] == blue && a[0][1][0].color[4] == red) {
//				rb = 1;
//				combination = 2;
//				start = 1;
//
//			}
//			else if (a[0][2][0].color[4] == white && a[0][2][0].color[1] == red && a[0][2][0].color[3] == green && a[1][2][0].color[1] == red && a[1][2][0].color[3] == green) {
//				rg = 1;
//				combination = 3;
//				start = 1;
//
//			}
//			else if (a[2][2][0].color[1] == green && a[2][2][0].color[5] == orange && a[2][2][0].color[3] == white && a[2][1][0].color[5] == orange && a[2][1][0].color[1] == green) {
//				og = 1;
//				combination = 3;
//				start = 1;
//
//			}
//			else if (a[2][0][0].color[1] == orange && a[2][0][0].color[5] == white && a[2][0][0].color[2] == blue && a[1][0][0].color[1] == orange && a[1][0][0].color[2] == blue) {
//				ob = 1;
//				combination = 3;
//				start = 1;
//
//			}
//			else if (a[0][0][0].color[1] == blue && a[0][0][0].color[4] == red && a[0][0][0].color[2] == white && a[0][1][0].color[1] == blue && a[0][1][0].color[4] == red) {
//				rb = 1;
//				combination = 3;
//				start = 1;
//			}
//
//		}
//		if (combination == 1) {
//			if (rg == 1) {
//				if (num_of_comb == 0) {
//					Rotate(3, 3);
//				}
//				if (num_of_comb == 1) {
//					Rotate(0, 3);
//				}
//				if (num_of_comb == 2) {
//					Rotate(3, -3);
//				}
//				if (num_of_comb == 3) {
//					Rotate(0, -3);
//				}
//				if (num_of_comb == 4) {
//					Rotate(4, -3);
//				}
//				if (num_of_comb == 5) {
//					Rotate(0, -3);
//				}
//				if (num_of_comb == 6) {
//					Rotate(4, 3);
//				}
//				if (num_of_comb == 7) {
//					start = 0;
//					num_of_comb = 0;
//					rg = 0;
//				}
//			}
//			if (og == 1) {
//				if (num_of_comb == 0) {
//					Rotate(5, 3);
//				}
//				if (num_of_comb == 1) {
//					Rotate(0, 3);
//				}
//				if (num_of_comb == 2) {
//					Rotate(5, -3);
//				}
//				if (num_of_comb == 3) {
//					Rotate(0, -3);
//				}
//				if (num_of_comb == 4) {
//					Rotate(3, -3);
//				}
//				if (num_of_comb == 5) {
//					Rotate(0, -3);
//				}
//				if (num_of_comb == 6) {
//					Rotate(3, 3);
//				}
//				if (num_of_comb == 7) {
//					start = 0;
//					num_of_comb = 0;
//					og = 0;
//				}
//			}
//			if (ob == 1) {
//				if (num_of_comb == 0) {
//					Rotate(2, 3);
//				}
//				if (num_of_comb == 1) {
//					Rotate(0, 3);
//				}
//				if (num_of_comb == 2) {
//					Rotate(2, -3);
//				}
//				if (num_of_comb == 3) {
//					Rotate(0, -3);
//				}
//				if (num_of_comb == 4) {
//					Rotate(5, -3);
//				}
//				if (num_of_comb == 5) {
//					Rotate(0, -3);
//				}
//				if (num_of_comb == 6) {
//					Rotate(5, 3);
//				}
//				if (num_of_comb == 7) {
//					start = 0;
//					num_of_comb = 0;
//					ob = 0;
//				}
//			}
//			if (rb == 1) {
//				if (num_of_comb == 0) {
//					Rotate(4, 3);
//				}
//				if (num_of_comb == 1) {
//					Rotate(0, 3);
//				}
//				if (num_of_comb == 2) {
//					Rotate(4, -3);
//				}
//				if (num_of_comb == 3) {
//					Rotate(0, -3);
//				}
//				if (num_of_comb == 4) {
//					Rotate(2, -3);
//				}
//				if (num_of_comb == 5) {
//					Rotate(0, -3);
//				}
//				if (num_of_comb == 6) {
//					Rotate(2, 3);
//				}
//				if (num_of_comb == 7) {
//					start = 0;
//					num_of_comb = 0;
//					rb = 0;
//				}
//			}
//		}
//	}
//private:
//	int _angle[4];
//	bool ok[4][4][4];
//	Small_Cube tmp[4][4];
//};
//
//#endif;
//#pragma once
