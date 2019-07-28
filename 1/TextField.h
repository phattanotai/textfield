#include <stdio.h>
#include <iostream>
#include <graphics.h>
#include <string.h>
#include <math.h>
using namespace std;
class TextField{
      private:
              int x1,y1,width,height,textWidth;
      public:
             void setTextField(int x,int y,int w,int h);
             double getDoubleText();
             char* getCharText();     
             void clearText();
};

