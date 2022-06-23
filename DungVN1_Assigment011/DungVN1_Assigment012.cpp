#include "DungVN1_Assigment012.h"
#include "graphics.h"
#include <conio.h>

class CShape
{
private:
	int color;
public:
	CShape(int c) {
		color = c;
	}
	int getcolor() {
		return color;
	}
	virtual void draw(int x, int y) = 0;
};

class CLine : public CShape
{
private:
	int length;
public:
	CLine(int l, int c) : CShape(c) {
		length = l;
	}
	virtual void draw(int x, int y) 
	{
		setcolor(getcolor());
		line(x, y, x + length, y);
	}

};


class CRectangle :public CShape
{
	private:
		int width, height;
	public:
		CRectangle(int w, int h, int c):CShape(c)
		{
			width = w;
			height = h;
		}
		virtual void draw(int x, int y)
		{
			setcolor(getcolor());
			rectangle(x, y, x + width, y + height);
			setfillstyle(1, getcolor());
			floodfill(x + width / 2, y + height / 2, getcolor());
		}
};

class CSquare : public CRectangle
{
	public:
		CSquare(int a, int c) : CRectangle(a, a, c){}
};

class CCircle : public CShape
{
	private:
		int radium;
	public:
		CCircle(int r, int c) : CShape(c)
		{
			radium = r;
		}
		virtual void draw(int x, int y)
		{
			setcolor(getcolor());
			circle(x + radium, y + radium, radium);
			setfillstyle(1, getcolor());
			floodfill(x + radium, y + radium, getcolor());
		}
};

class picture
{
	private:
		CShape* s[4];
	public:
		picture(CShape* s0, CShape* s1, CShape* s2, CShape* s3)
		{
			s[0] = s0;
			s[1] = s1;
			s[2] = s2;
			s[3] = s3;
		}
		void paint(int* k);
		void listpaint();
};

void picture::paint(int* k)
{
	for (int i = 0; i < 4; i++) {
		s[k[i]]->draw(10 + i * 150, 200);
	}
}
void picture::listpaint()
{
		int k[4], i1, i2, i3, i4;
		for (i1 = 0; i1 < 4; ++i1)
			for (i2 = 0; i2 < 4; ++i2)
				if (i2 != i1)
					for (i3 = 0; i3 < 4; ++i3)
						if (i3 != i2 && i3 != i1)
							for (i4 = 0; i4 < 4; ++i4)
								if (i4 != i3 && i4 != i2 && i4 != i1)
								{
									k[0] = i1;
									k[1] = i2;
									k[2] = i3;
									k[3] = i4;
									paint(k);
									getch();
									cleardevice();

								}
};
		CLine line(120, 14);
		CCircle cirle(60, RED);
		CRectangle rectangle(120, 100, YELLOW);
		CSquare square(120, CYAN);



	void main()
	{
		int mh = 0, mode = 0;
		initgraph(&mh, &mode, "");
		picture pic(&line, &circle, &rectangle, &square);
		pic.listpaint(); 
		getch(); 
		closegraph();
	}