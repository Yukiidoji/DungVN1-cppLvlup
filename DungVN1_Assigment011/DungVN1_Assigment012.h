#pragma once


class CShape
{
private:
	int color;
public:
	CShape(int c);
	int getcolor();
	virtual void draw(int x, int y);
};

class CLine : public CShape
	{
	private:
		int length;
	public:
		CLine(int l, int c);
		virtual void draw(int x, int y);
		int setcolor();
		int line();
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