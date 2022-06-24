#include "DungVN1_Assigment011.h"

using namespace std;

//**********************************************************
// Function:	CLine
// Description:	Constructor of CLine class
// Return:		
//**********************************************************

CLine::CLine(int l, int c)
{

    length = l;
}

//**********************************************************
// Function:	draw
// Description:	Draw line
// Return:		void
//**********************************************************
void CLine::draw(int x, int y, HDC device_context)
{

    HPEN pen = CreatePen(PS_SOLID, 5, RGB(255, 0, 0));
    SelectObject(device_context, pen);

    MoveToEx(device_context, x, y, NULL);
    LineTo(device_context, x + length, y);
}

//**********************************************************
// Function:	CCircle
// Description:	Constructor of CCircle class
// Return:		Object CCircle.
//**********************************************************
CCircle::CCircle(int r, int c)
{
    radium = r;
}

//**********************************************************
// Function:		draw
// Description:	Draw a circle
// Return:		void
//**********************************************************
void CCircle::draw(int x, int y, HDC device_context)
{
    HPEN pen = CreatePen(PS_SOLID, 4, RGB(200, 12, 212));
    SelectObject(device_context, pen);

    Ellipse(device_context, x, y, x + 2 * radium, y + 2 * radium);
}

//**********************************************************
// Function:	CRectangle
// Description:	Constructor of CRectangle class
// Return:		Object CRectangle.
//**********************************************************
CRectangle::CRectangle(int w, int h, int c)
{
    width = w;
    height = h;
}

//**********************************************************
// Function:	draw
// Description:	Draw a Rectangle
// Return:		void
//**********************************************************
void CRectangle::draw(int x, int y, HDC device_context)
{
    HPEN pen = CreatePen(PS_SOLID, 4, RGB(150, 42, 100));
    SelectObject(device_context, pen);

    Rectangle(device_context, x, y, x + width, y + height);
}

//**********************************************************
// Function:	CSquare
// Description:	Constructor of CSquare class
// Return:		Object CSquare.
//**********************************************************
CSquare::CSquare(int length_side, int input_color)
{
    width = length_side;
    height = length_side;
    color = input_color;
}

int main()
{
    //Use the pointer array of the CPicture class to initialize the shapes
    CPicture Picture;
    Picture.s[0] = new CLine(80, 8000);
    Picture.s[1] = new CCircle(50, 3000);
    Picture.s[2] = new CRectangle(50, 30, 1500);
    Picture.s[3] = new CSquare(60, RGB(150, 42, 100));

        //Get Console To Paint
        HWND console_handle = GetConsoleWindow();
        HDC device_context = GetDC(console_handle);
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
                                    for (int i = 0; i < 4; i++) {
                                        Picture.s[k[i]]->draw(20 + i * 140, 200, device_context);
                                    }

                                }

        ReleaseDC(console_handle, device_context);
}
