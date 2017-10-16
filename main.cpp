#include <iostream>
#include "bitmap.h"
#include <vector>
#include <string>
using namespace std;

int main()
{
/*-State variables needed
-Ask user what the name of the photo is ||||CHECK
-Ask user if they want a border
-Ask user if they want to adjust exposure of photo. if yes what %?
-Ask user if they want to add a border to photo. if yes white or black?
-Check to see if photo exists ||||CHECK
-Run loop for color averaging (+ or - exposure amount)|||||CHECK 
    -loop will run by row then go to the next row. (nested loop while column >= current row)|||||CHECK
    -run while the rows are >= current row |||||CHECK
-if user wanted a border, change the outter 5 pixles to 0 or 255
-say thanks and bye! */

Bitmap image;
vector <vector <Pixel> > bmp;
Pixel rgb;
string PicName, border, bcolor, exposure;
bool isImg;
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
image.save("test.bmp");

return 0;
}
