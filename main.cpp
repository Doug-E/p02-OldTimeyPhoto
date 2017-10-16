#include <iostream>
#include "bitmap.h"
#include <vector>
#include <string>
using namespace std;

int main()
{
/*-State variables needed
-Ask user what the name of the photo is ||||CHECK
-Ask user if they want a border ||||CHECK
-Ask user if they want to adjust exposure of photo. if yes what %? (turned to 4 bit)||||CHECK
-Ask user if they want to add a border to photo. if yes white or black? ||||CHECK
-Check to see if photo exists ||||CHECK
-Run loop for color averaging (+ or - exposure amount)|||||CHECK 
    -loop will run by row then go to the next row. (nested loop while column >= current row)|||||CHECK
    -run while the rows are >= current row |||||CHECK
-if user wanted a border, change the outter 5 pixles to 0 or 255 ||||CHECK
-say thanks and bye! */

Bitmap image;
vector <vector <Pixel> > bmp;
Pixel rgb;
string PicName, border, bcolor, exposure, twobit;
bool isImg, istwobit;
int bcol, width, hight;

PicChoice:
cout<< "What picture would you like to make black and white?" <<endl;
cin>> PicName;
image.open(PicName);
isImg = image.isImage();

if (isImg == false)
{
    cout<< "Invalid file." << endl;
    goto PicChoice;
}

cout<< "Would you like a border? Yes/No" <<endl;
cin>> border;

if (border == "yes" || border == "Yes" || border == "y" || border == "Y")
{
    border = "yes";

    cout<< "What color border? Black or white?"<<endl;
    cin>> bcolor;
    
    if (bcolor == "black" || bcolor == "Black") bcol = 0;
    
    else bcol = 255;
}

cout<< "Would you like to make this a photo 4 bit?" <<endl;
cin>> twobit;

if (twobit == "yes" || twobit == "Yes" || twobit == "y" || twobit == "Y") istwobit = true;

bmp = image.toPixelMatrix();
cout<< "Picture loaded. It is " << bmp[0].size() <<" pixels wide by " <<bmp.size() <<" pixels tall." <<endl;
if (bmp.size() > 0 && bmp[0].size() > 0) 
{
    int x,y,grey;
    for(x = 0; x < bmp.size(); x++)
    {
        for (y = 0; y < bmp[0].size(); y++)
        {
            rgb = bmp[x][y];
            grey =(rgb.red + rgb.blue + rgb.green) /3;

            if (istwobit == true)
            {
                if (grey < 16) grey = 8; 
                if (grey >= 16 && grey < 32) grey = 24;
                if (grey >= 32 && grey < 48) grey = 40;
                if (grey >= 48 && grey < 64) grey = 56;
                if (grey >= 64 && grey < 80) grey = 72;
                if (grey >= 80 && grey < 96) grey = 88;
                if (grey >= 96 && grey < 112) grey = 104;
                if (grey >= 112 && grey < 128) grey = 120;
                if (grey >= 128 && grey < 144) grey = 136;
                if (grey >= 144 && grey < 160) grey = 152;
                if (grey >= 160 && grey < 176) grey = 168;
                if (grey >= 176 && grey < 192) grey = 184;
                if (grey >= 192 && grey < 208) grey = 200;
                if (grey >= 208 && grey < 224) grey = 216;
                if (grey >= 224 && grey < 240) grey = 232;
                if (grey >= 240) grey = 248;
            }

            rgb.red = grey;
            rgb.blue = grey;
            rgb.green = grey;
            bmp[x][y] = rgb;
        }
    }
}

if (border == "yes")
{
    cout<< bcol << endl;
    if (bmp.size() > 40 && bmp[0].size() > 40)
    {
        hight = bmp.size();
        width = bmp[0].size();
        for (int x2 = 0; x2 < bmp.size(); x2++)
        {
            for (int index = 0; index <= 10; index++)
            {
                rgb = bmp[x2][0+index];
                rgb.red = bcol;
                rgb.blue = bcol;
                rgb.green = bcol;
                bmp[x2][0+index] = rgb;

                rgb = bmp[x2][width - 1 - index];
                rgb.red = bcol;
                rgb.blue = bcol;
                rgb.green = bcol;
                bmp[x2][width - 1 - index] = rgb;
            }
        }
        for (int y2 = 0; y2 < bmp[0].size(); y2++)
        {
            for (int index = 0; index <= 10; index++)
            {
                rgb = bmp[0+index][y2];
                rgb.red = bcol;
                rgb.blue = bcol;
                rgb.green = bcol;
                bmp[0+index][y2] = rgb;

                rgb = bmp[hight - 1 - index][y2];
                rgb.red = bcol;
                rgb.blue = bcol;
                rgb.green = bcol;
                bmp[hight - 1 - index][y2] = rgb;
            }
        }
    }
    else
    {
        cout<< "Picture too small for a border!"<<endl;
    }
}
image.fromPixelMatrix(bmp);
image.save("OldTimeyPhoto.bmp");

return 0;
}
