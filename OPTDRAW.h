#ifndef OPTDRAW
#define OPTDRAW

//#include "glut.h"
//#include <cstring>
//struct Small_Cube
//{
//	unsigned int color[6];
//	double size;
//
//	Small_Cube()
//	{
//		memset(color, 0, sizeof(color));
//		size = 0.0;
//	}
//
//	// U, D'
//	void rotateZoX()
//	{
//		unsigned int tmp = color[5];
//		color[5] = color[3];
//		color[3] = color[4];
//		color[4] = color[2];
//		color[2] = tmp;
//	}
//
//	// R, L'
//	void rotateZoY()
//	{
//		unsigned int tmp = color[2];
//		color[2] = color[1];
//		color[1] = color[3];
//		color[3] = color[0];
//		color[0] = tmp;
//	}
//
//	// F, B'
//	void rotateXoY()
//	{
//		unsigned int tmp = color[0];
//		color[0] = color[4];
//		color[4] = color[1];
//		color[1] = color[5];
//		color[5] = tmp;
//	}
//	// U', D
//	void rotateZoX1()
//	{
//		unsigned int tmp = color[4];
//		color[4] = color[3];
//		color[3] = color[5];
//		color[5] = color[2];
//		color[2] = tmp;
//	}
//
//	// R', L
//	void rotateZoY1()
//	{
//		unsigned int tmp = color[2];
//		color[2] = color[0];
//		color[0] = color[3];
//		color[3] = color[1];
//		color[1] = tmp;
//	}
//
//	// F', B
//	void rotateXoY1()
//	{
//		unsigned int tmp = color[0];
//		color[0] = color[5];
//		color[5] = color[1];
//		color[1] = color[4];
//		color[4] = tmp;
//	}
//
//	void setColor(int i, int color)
//	{
//		this->color[i] = color;
//	}
//
//	unsigned char* at(int i)//����������� ���� � 16 ������� � ������ 3 ���������� ��� ����� (RGB)
//	{
//
//		_color[0] = color[i] >> 16;
//		_color[1] = color[i] >> 8;
//		_color[2] = color[i];
//		return _color;
//	}
//
//
//	void draw()
//	{
//		glPushMatrix();
//		glBegin(GL_QUADS);
//
//		glColor3ubv(at(0)); //���� � RGB
//		glNormal3f(0, 0, 1);/*���������� ������� �� ��������� ������ ���� ����������� � ����� ����� ������ 1, ������ ��� ������� ������������ ��� ����������� ���������� ����������� � ������� ���������.
//		���� ������� �� ����� �������������, �� �� ����� ����� ������ �� ������������� ���������, ��� ����� �������� � ���������� ���������� ����������.
//		����� ����, ���� ������� ����� �����, �������� �� 1, �� ��� �� ��������� �� ������� �������������� ����� ��������� ��������� �����, ��� �������� �� ������������ ������� ���������.
//		������� ������� ������ ���� �������������.*/
//		glVertex3f(size, size, size);//������ ������� ������� ����
//		glVertex3f(0, size, size);//������ ������� ������� ����
//		glVertex3f(0, 0, size);//������ ������ ������� ����
//		glVertex3f(size, 0, size);//������ ������ ������� ����
//		//�����������
//		glColor3ubv(at(1));
//		glNormal3f(0, 0, -1);
//		glVertex3f(size, 0, 0);//����� ������ ������� ����
//		glVertex3f(0, 0, 0);//����� ������ ������� ����
//		glVertex3f(0, size, 0);//����� ������� ������� ����
//		glVertex3f(size, size, 0);//����� ������� ������� ����
//		//������
//		glColor3ubv(at(2));
//		glNormal3f(0, -1, 0);
//		glVertex3f(size, 0, size);//������ ������ ������� ����
//		glVertex3f(0, 0, size);//������ ������ ������� ����
//		glVertex3f(0, 0, 0);//����� ������ ������� ����
//		glVertex3f(size, 0, 0);//����� ������ ������� ����
//		//������ �����
//		glColor3ubv(at(3));
//		glNormal3f(0, 1, 0);
//		glVertex3f(size, size, 0);//����� ������� ������� ����
//		glVertex3f(0, size, 0);//����� ������� ������� ����
//		glVertex3f(0, size, size);//������ ������� ������� ����
//		glVertex3f(size, size, size);//������ ������� ������� ����
//		//�������
//		glColor3ubv(at(4));
//		glNormal3f(-1, 0, 0);
//		glVertex3f(0, size, size);//������ ������� ������� ����
//		glVertex3f(0, size, 0);//����� ������� ������� ����
//		glVertex3f(0, 0, 0);//����� ������ ������� ����
//		glVertex3f(0, 0, size);//������ ������ ������� ����
//		//�����
//		glColor3ubv(at(5));
//		glNormal3f(1, 0, 0);
//		glVertex3f(size, size, 0);//����� ������� ������� ����
//		glVertex3f(size, size, size);//������ ������� ������� ����
//		glVertex3f(size, 0, size);//������ ������ ������� ����
//		glVertex3f(size, 0, 0);//����� ������ ������� ����
//		//������
//		glEnd();
//		glPopMatrix();
//	}
//
//	void draw(double x, double y, double z)
//	{
//		glPushMatrix();
//		glTranslated(x, y, z);
//		draw();
//		glPopMatrix();
//	}
//
//private:
//	unsigned char _color[4];
//};


#endif;
#pragma once

