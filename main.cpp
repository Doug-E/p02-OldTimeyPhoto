#include <iostream>
#include "bitmap.h"
#include "bitmap.cpp"

using namespace std;

int main()
{
-State variables needed

-Ask user what the name of the photo is

-Ask user if they want a border

-Ask user if they want to adjust exposure of photo. if yes what %?

-Ask user if they want to add a border to photo. if yes white or black?

-Check to see if photo exists

-Run loop for color averaging (+ or - exposure amount) 
    -loop will run by row then go to the next row. (nested loop while column >= current row)

    -run while the rows are >= current row

-if user wanted a border, change the outter 5 pixles to 0 or 255

-say thanks and bye!




return 0;

}
