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
//	int current; //����� �����: 1 - �������(�����), 2 - ��������(�����), 3 - ������ (�������), 4 - �����(�������), 5 - ������(���������), 6 - ������(������).
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
//				a[i][j][2].setColor(0, color[0]);// ����� ���� ��� ������� ����� (3 ���������� - ��� z - �� ���)  
//
//		for (i = 0; i < 3; i++)
//			for (j = 0; j < 3; j++)
//				a[i][j][0].setColor(1, color[1]);
//
//		for (k = 0; k < 3; k++)
//			for (j = 0; j < 3; j++)
//				a[j][0][k].setColor(2, color[2]);//����� ���� ��� �������� ����� (2 ���������� - ��� ����� - �����)
//
//		for (k = 0; k < 3; k++)
//			for (j = 0; j < 3; j++)
//				a[j][2][k].setColor(3, color[3]);
//
//		for (i = 0; i < 3; i++)
//			for (k = 0; k < 3; k++)
//				a[0][k][i].setColor(4, color[4]);//������� ���� ��� ����� ����� (1 ���������� - x - ������)
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
//		//a[2][2][2].color[2] = 90; ��������� � ������ ����� ������� �������� �������� ������  
//	}
//
//	void draw()
//	{
//		const double K = 0.55;
//		glPushMatrix();
//		glColor3f(0, 0, 0);
//		glTranslatef(((1.0 - K) / 2) * size + K * size / 2, ((1.0 - K) / 2) * size + K * size / 2, ((1.0 - K) / 2) * size + K * size / 2);//7.5, 7.5, 7.5
//		glutSolidCube(size * K);//������� ������ ��� � ������� � ������ ���������
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
//				glTranslated(size / 2, size / 2, 0); //���������� � ������ 
//				glRotatef(rotate[current], 0, 0, 1);   //������ ����� � ������� �� ����
//				glTranslated(-size / 2, -size / 2, 0); //���������� �������
//				for (i = 0; i < 3; i++)
//					for (j = 0; j < 3; j++)
//						a[i][j][k].draw(size / 3 * i, size / 3 * j, size / 3 * k); //��������� ���������� ������ ����� �������� 
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
//		//1) ���� �� ������� ����� 4  ����� �����
//		if (a[0][1][2].color[0] == white && a[0][1][2].color[4] == red && a[1][2][2].color[0] == white && a[1][2][2].color[3] == green && a[2][1][2].color[0] == white && a[2][1][2].color[5] == orange && a[1][0][2].color[0] == white && a[1][0][2].color[2] == blue && a[0][2][2].color[3] == green && a[0][2][2].color[0] == white && a[0][2][2].color[4] == red && a[2][2][2].color[0] == white && a[2][2][2].color[3] == green && a[2][2][2].color[5] == orange && a[0][0][2].color[0] == white && a[0][0][2].color[4] == red && a[0][0][2].color[2] == blue && a[2][0][2].color[0] == white && a[2][0][2].color[2] == blue && a[2][0][2].color[5] == orange) {
//			timeron = 1;
//			return;
//		}
//		if (timeron == 0){
//			if (a[0][1][2].color[0] == white && a[1][0][2].color[0] == white && a[2][1][2].color[0] == white && a[1][2][2].color[0] == white) {
//				if (a[0][1][2].color[4] == blue && a[1][0][2].color[2] == green && a[2][1][2].color[5] == orange && a[1][2][2].color[3] == red) {//���� ����� ��������� ������ ��������� ����� ����� ������� � ������ �������
//					Rotate(1, 3); //������� ����� ����� � ������� ������ ��� ��������� ���������� �� �����
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
//			//���� 3 ����� ����� (����� ������)
//			if (a[0][1][2].color[0] == white && a[1][0][2].color[0] != white && a[2][1][2].color[0] == white && a[1][2][2].color[0] == white) {
//				if (a[0][1][2].color[4] == red && a[1][2][2].color[3] == blue && a[2][1][2].color[5] == orange) {
//					if (a[2][0][1].color[5] == white && a[2][0][1].color[2] == green) {//���� ����� ����� �������� ������� ����
//						Rotate(1, 3); //������� ������� �����, ����� �� �������� ������� ���� 
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
//					//����� ����� ����� ���������� ����� �����
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
//			//��� ����� (����� ������)
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
//			//��� ����� (����� �������)
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
//			//��� ����� (����� �����)
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
//			//���� 2 ������� ����� �����
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
//			}//���� ������� � ������ ����� �����
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
//			//��� ����� (����-������-����)
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
//			// ��� ����� (�e��-�����-���)
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
//			//2 ����� (���-�����-�����)
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
//			//2 ����� (�����-�����-����)
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
//			//1 ����� ������  
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
//			//1 ����� �������
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
//			//����� �����
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
//			//����� ������
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
//			//������� 0 �������, �� ���� 4 �����
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
//			//������� 0 �������, �� ���� 3 ����� ����� �������
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
//			//������� 0 �������, �� ���� 3 ����� ����� ������� 
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
//			//������� 0 �������, �� ���� 3 ����� ����� ������ 
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
//			//������� 0 �������, �� ���� 3 ����� ����� �������� 
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
//			//������� 0 �������, �� ���� 2 ����� �����������
//			if (a[1][0][2].color[2] == white && a[1][2][2].color[3] == white && (a[0][1][2].color[0] != white && a[0][1][2].color[4] != white) && (a[2][1][2].color[0] != white && a[2][1][2].color[5] != white)) {
//				//��� ����� �����
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
//				//��� ������� �����
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
//				//��� �������
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
//				//��� ���������
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
//			//������� 0 �������, �� ���� 2 ����� �������������
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
//				//��� ������� �����
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
//				//��� �������
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
//				//��� ���������
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
//			//2 ����� ����� ������ ������� 
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
//				//��� ������� �����
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
//				//��� �������
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
//				//��� ���������
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
//			//2 ����� ������ ������ ������� 
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
//				//��� ������� �����
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
//				//��� �������
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
//				//��� ���������
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
//			//2 ����� ������ ������� ������� 
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
//				//��� ������� �����
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
//				//��� �������
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
//				//��� ���������
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
//			//2 ����� ����� ������� ������� 
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
//				//��� ������� �����
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
//				//��� �������
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
//				//��� ���������
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
//			//1 ������ ��������� 2 ����������� ������������� ����� ������� 
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
//			//1 ������ ��������� 2 ����������� ����� ������� ����� ������ 
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
//			//1 ������ ��������� 2 ����������� ������ ������� ����� ����� 
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
//			//1 ����� ��������� 2 ����������� ����������� ����� ������ 
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
//			//1 ����� ��������� 2 ����������� ������ ������� ������ ����� ������ 
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
//			//1 ����� ��������� 2 ����������� ������ ������ ������ ����� ������� 
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
//			//1 ������� ��������� 2 ����������� ������������� ����� ������
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
//			//1 ������� ��������� 2 ����������� ������ ������ ���� ����� �����
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
//			//1 ������� ��������� 2 ����������� ����� ������ ���� ����� ������
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
//			//1 ������ ��������� 2 ����������� ����������� ����� �����
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
//			//1 ������ ��������� 2 ����������� ����� ������ ������ ����� �������
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
//			//1 ������ ��������� 2 ����������� ����� ������� ������ ����� ������
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
//			//������� ������ 2 ������� ���������
//			if (((a[1][0][2].color[0] == white && a[1][2][2].color[0] == white) || (a[1][0][2].color[2] == white && a[1][2][2].color[0] == white) || (a[1][0][2].color[0] == white && a[1][2][2].color[3] == white)) && (a[0][1][2].color[0] != white && a[0][1][2].color[4] != white) && (a[2][1][2].color[0] != white && a[2][1][2].color[5] != white)) {
//				//��� ����� �����
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
//				//��� ������� �����
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
//				//��� �������
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
//				//��� ���������
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
//			//������� ������ 2 ������� ��������
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
//				//��� ������� �����
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
//				//��� �������
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
//				//��� ���������
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
//			//1 ������ ����������� 2 ��������� ������������� ����� ������� 
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
//			//1 ������ ��������� 2 ����������� ����� ������� ����� ������ 
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
//			//1 ������ ��������� 2 ����������� ������ ������� ����� ����� 
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
//			//1 ����� ����������� 2 ��������� ����������� ����� ������ 
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
//			//1 ����� ��������� 2 ����������� ������ ������� ������ ����� ������ 
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
//			//1 ����� ��������� 2 ����������� ������ ������ ������ ����� ������� 
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
//			//1 ������� ��������� 2 ����������� ������������� ����� ������
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
//			//1 ������� ��������� 2 ����������� ������ ������ ���� ����� �����
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
//			//1 ������� ��������� 2 ����������� ����� ������ ���� ����� ������
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
//			//1 ������ ��������� 2 ����������� ����������� ����� �����
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
//			//1 ������ ��������� 2 ����������� ����� ������ ������ ����� �������
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
//			//1 ������ ��������� 2 ����������� ����� ������� ������ ����� ������
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
//			//3 ����� ��������� � ��� (���� ��� ���� �� �������) ����� �����
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
//			//����� �����
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
//			//����� ����
//			if (a[0][1][2].color[0] == white && a[1][2][2].color[0] == white && a[2][1][2].color[0] == white && (a[1][0][2].color[0] != white && a[1][0][2].color[2] != white)) {
//				if (a[2][0][1].color[2] == white && a[2][0][1].color[5] != white) {
//					Rotate(2, -3);
//				}
//				//����� ���� ����������
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
//			//����� ����
//			if (a[1][0][2].color[0] == white && a[1][2][2].color[0] == white && a[2][1][2].color[0] == white && (a[0][1][2].color[0] != white && a[0][1][2].color[4] != white)) {
//				if (a[2][0][1].color[2] == white && a[2][0][1].color[5] != white) {
//					Rotate(1, 3);
//				}
//				if (a[2][0][1].color[2] != white && a[2][0][1].color[5] == white) {
//					Rotate(1, 3);
//				}
//				//1 ��� ��� ����� ������ ����
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
//			//1 ����� (��� ��������)
//			if ((a[1][0][2].color[0] == white || a[1][0][2].color[2] == white) && (a[0][1][2].color[4] != white && a[0][1][2].color[0] != white) && (a[2][1][2].color[0] != white && a[2][1][2].color[5] != white) && (a[1][2][2].color[0] != white && a[1][2][2].color[3] != white)) {
//				//��� ����� �����
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
//				//��� ������� �����
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
//				//��� �������
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
//				//��� ���������
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
//			//�����
//			if ((a[0][1][2].color[0] == white || a[0][1][2].color[4] == white) && (a[1][0][2].color[0] != white && a[1][0][2].color[2] != white) && (a[2][1][2].color[0] != white && a[2][1][2].color[5] != white) && (a[1][2][2].color[0] != white && a[1][2][2].color[3] != white)) {
//				//��� ����� �����
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
//				//��� ������� �����
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
//				//��� �������
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
//				//��� ���������
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
//			//������
//			if ((a[1][2][2].color[0] == white || a[1][2][2].color[3] == white) && (a[0][1][2].color[4] != white && a[0][1][2].color[0] != white) && (a[2][1][2].color[0] != white && a[2][1][2].color[5] != white) && (a[1][0][2].color[0] != white && a[1][0][2].color[2] != white)) {
//				//��� ����� �����
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
//				//��� ������� �����
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
//				//��� �������
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
//				//��� ���������
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
//			//������
//			if ((a[2][1][2].color[0] == white || a[2][1][2].color[5] == white) && (a[0][1][2].color[4] != white && a[0][1][2].color[0] != white) && (a[1][0][2].color[0] != white && a[1][0][2].color[2] != white) && (a[1][2][2].color[0] != white && a[1][2][2].color[3] != white)) {
//				//��� ����� �����
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
//				//��� ������� �����
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
//				//��� �������
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
//				//��� ���������
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
//			//0 ���������� 
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
//				//��� ������� �����
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
//				//��� �������
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
//				//��� ���������
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
