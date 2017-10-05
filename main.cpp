#include <iostream>
#include "bitmap.h"
#include <vector>

using namespace std;

int main()
{
/*-State variables needed

-Ask user what the name of the photo is

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

image.open("machupicchu.bmp");
bmp = image.toPixelMatrix();


cout<< "Picture loaded. It is " << bmp.size() <<" by " <<bmp[0].size() <<endl;

    if (bmp.size() > '0') 
    {
     
    }

return 0;

}
