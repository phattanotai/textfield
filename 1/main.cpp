#include <dos.h>
#include <stdio.h>
#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <string>
#include <stdlib.h>
#include "TextField.h"
using namespace std;


int main(){
   initwindow(600,200,"test");
   setbkcolor(7);
   clearviewport();
   TextField tf1,tf2;
   tf1.setTextField(100,30,10,20);
   tf2.setTextField(100,70,20,20); 
   while(true){
       char *i= tf1.getCharText();
       char *l= tf2.getCharText(); 
   }       
      // getch();
       clearviewport();
   
}
