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
-Check to see if photo exists
-Run loop for color averaging (+ or - exposure amount) 
    -loop will run by row then go to the next row. (nested loop while column >= current row)
    -run while the rows are >= current row
-if user wanted a border, change the outter 5 pixles to 0 or 255
-say thanks and bye! */

Bitmap image;
vector <vector <Pixel> > bmp;
Pixel rgb;
string PicName;
bool isImg;

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


else
{

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
        image.fromPixelMatrix(bmp);
        image.save("test.bmp");
        cout<< "Done :)"<<endl;
    }
}



return 0;

}
