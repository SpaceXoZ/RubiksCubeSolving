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
//	unsigned char* at(int i)//преобразует цвет в 16 системе в формат 3 параметров для цвета (RGB)
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
//		glColor3ubv(at(0)); //цвет в RGB
//		glNormal3f(0, 0, 1);/*Компоненты нормали на плоскость должны быть нормированы и иметь длину равную 1, потому что нормаль используется для определения ориентации поверхности и расчета освещения.
//		Если нормаль не будет нормализована, то ее длина будет влиять на интенсивность освещения, что может привести к искажениям визуальной информации.
//		Кроме того, если нормаль имеет длину, отличную от 1, то при ее умножении на матрицу преобразования может произойти изменение длины, что повлияет на правильность расчета освещения.
//		Поэтому нормаль должна быть нормализована.*/
//		glVertex3f(size, size, size);//правый верхний дальний угол
//		glVertex3f(0, size, size);//правый верхний ближний угол
//		glVertex3f(0, 0, size);//правый нижний ближний угол
//		glVertex3f(size, 0, size);//правый нижний дальний угол
//		//фронтальная
//		glColor3ubv(at(1));
//		glNormal3f(0, 0, -1);
//		glVertex3f(size, 0, 0);//левый нижний дальний угол
//		glVertex3f(0, 0, 0);//левый нижний ближний угол
//		glVertex3f(0, size, 0);//левый верхний ближний угол
//		glVertex3f(size, size, 0);//левый верхний дальний угол
//		//задняя
//		glColor3ubv(at(2));
//		glNormal3f(0, -1, 0);
//		glVertex3f(size, 0, size);//правый нижний дальний угол
//		glVertex3f(0, 0, size);//правый нижний ближний угол
//		glVertex3f(0, 0, 0);//левый нижний ближний угол
//		glVertex3f(size, 0, 0);//левый нижний дальний угол
//		//нижняя грань
//		glColor3ubv(at(3));
//		glNormal3f(0, 1, 0);
//		glVertex3f(size, size, 0);//левый верхний дальний угол
//		glVertex3f(0, size, 0);//левый верхний ближний угол
//		glVertex3f(0, size, size);//правый верхний ближний угол
//		glVertex3f(size, size, size);//правый верхний дальний угол
//		//верхняя
//		glColor3ubv(at(4));
//		glNormal3f(-1, 0, 0);
//		glVertex3f(0, size, size);//правый верхний ближний угол
//		glVertex3f(0, size, 0);//левый верхний ближний угол
//		glVertex3f(0, 0, 0);//левый нижний ближний угол
//		glVertex3f(0, 0, size);//правый нижний ближний угол
//		//левая
//		glColor3ubv(at(5));
//		glNormal3f(1, 0, 0);
//		glVertex3f(size, size, 0);//левый верхний дальний угол
//		glVertex3f(size, size, size);//правый верхний дальний угол
//		glVertex3f(size, 0, size);//правый нижний дальний угол
//		glVertex3f(size, 0, 0);//левый нижний дальний угол
//		//правая
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

