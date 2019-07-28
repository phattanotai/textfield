#include "TextField.h"

void TextField::setTextField(int x,int y,int w,int h){
     width = round(w*14.5)+5;
     
     height = h;
     x1 = x;
     y1 = y;
     setcolor(0);
     line(x,y,x+width,y);
     line(x,y,x,y+height);
     setcolor(15);
     line(x,y+height,x+width,y+height);
     line(x+width,y,x+width,y+height);
     
     textWidth = w;
}
double TextField::getDoubleText(){
    char* st=new char[textWidth];
    char ch;
    for(int i=0;i<textWidth;i++){
       st[i]='\0'; 
    }
    int i=0;
    int c=0,b=0;
    clearText();
    while(ch!=13){      
        if(kbhit()){
          ch=getch(); 
          if(i<textWidth){                 
               if(ch==8){
                   setcolor(7);
                   outtextxy(x1+5,y1+2,st);
                   st[i-1]='\0';
                   setcolor(1);
                   outtextxy(x1+5,y1+2,st);
                   c=textwidth(st);
                   i--;
                   if(i<=0){i=0;}       
               }else{
                   st[i]=ch;                      
                   setcolor(1);
                   outtextxy(x1+5,y1+2,st);
                   c=textwidth(st);
                   i++; 
               } 
           }else{
              if(ch==8){
                   setcolor(7);
                   outtextxy(x1+5,y1+2,st);
                   st[i-1]='\0';
                   setcolor(1);
                   outtextxy(x1+5,y1+2,st);
                   c=textwidth(st);
                   i--;
                   if(i<=0){i=0;}
              }     
           }       
        }
        setcolor(1);
        line(x1+5+c,y1+2,x1+5+c,y1+height-2);
        delay(100);
        setcolor(7);
        line(x1+5+c,y1+2,x1+5+c,y1+height-2);
        delay(100);           
    }
    ch=0; 
    return atof(st);        
}

char* TextField::getCharText(){
    char* st=new char[textWidth];
    char ch;
    for(int i=0;i<textWidth;i++){
       st[i]='\0'; 
    }
    int i=0;
    int c=0,b=0;
    clearText();
    while(ch!=13){      
        if(kbhit()){
          ch=getch(); 
          if(i<textWidth){                 
               if(ch==8){
                   setcolor(7);
                   outtextxy(x1+5,y1+2,st);
                   st[i-1]='\0';
                   setcolor(1);
                   outtextxy(x1+5,y1+2,st);
                   c=textwidth(st);
                   i--;
                   if(i<=0){i=0;}       
               }else{
                   st[i]=ch;                      
                   setcolor(1);
                   outtextxy(x1+5,y1+2,st);
                   c=textwidth(st);
                   i++; 
               } 
           }else{
              if(ch==8){
                   setcolor(7);
                   outtextxy(x1+5,y1+2,st);
                   st[i-1]='\0';
                   setcolor(1);
                   outtextxy(x1+5,y1+2,st);
                   c=textwidth(st);
                   i--;
                   if(i<=0){i=0;}
              }     
           }       
        }
        setcolor(1);
        line(x1+5+c,y1+2,x1+5+c,y1+height-2);
        delay(100);
        setcolor(7);
        line(x1+5+c,y1+2,x1+5+c,y1+height-2);
        delay(100);           
    } 
    ch=0;
    return st;        
}

void TextField::clearText(){
     setcolor(7);
     int l=0;
     for(int i = 0;i<textWidth;i++){
          outtextxy(x1+5+l,y1+2,"W");
          l+=14.5;
     }  
}
