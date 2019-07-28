#include <dos.h>
#include <stdio.h>
#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <string>
#include <stdlib.h>

using namespace std;

void button(int look,int x,int y,int width,int height){
     if(look==0){
         setcolor(0);
         line(x,y,x+width,y);
         line(x,y,x,y+height);
         setcolor(15);
         line(x,y+height,x+width,y+height);
         line(x+width,y,x+width,y+height);
     }else{
         setcolor(15);
         line(x,y,x+width,y);
         line(x,y,x,y+height);
         setcolor(0);
         line(x,y+height,x+width,y+height);
         line(x+width,y,x+width,y+height);      
     }
}

void textfield1(int x1,int y1,int x2,int y2,int width,int *l){
   char st[width];
   char ch;
   for(int i=0;i<width;i++){
       st[i]=NULL; 
   }
    int i=0;
    int c=0;
    button(0,x1,y1,x2,y2);
    while(ch!=13){      
        if(kbhit()){                 
           ch=getch(); 
           if(ch==8){
               cout<<c;
               setcolor(7);
               outtextxy(x1+5,y1+2,st);
               st[i-1]=NULL;
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
        }
        setcolor(1);
        line(x1+5+c,y1+2,x1+5+c,y2-2);
        delay(100);
        setcolor(7);
        line(x1+5+c,y1+2,x1+5+c,y2-2);
        delay(200);           
    } 
    *l=90;          
}

double double_textfield(int x1,int y1,int width,int height){
    char* st=new char[width];
    height+=4;
    char ch;
    for(int i=0;i<width;i++){
       st[i]='\0'; 
    }
    int i=0;
    int c=0,b=0;
    button(0,x1,y1,(width*10)+5,height);
    while(ch!=13){      
        if(kbhit()){
          ch=getch(); 
          if(i<width){                 
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

char* char_textfield(int x1,int y1,int width,int height){
    char* st=new char[width];
    height+=4;
    char ch;
    for(int i=0;i<width;i++){
       st[i]='\0'; 
    }
    int i=0;
    int c=0,b=0;
    button(0,x1,y1,(width*10)+5,height);
    while(ch!=13){      
        if(kbhit()){
          ch=getch(); 
          if(i<width){                 
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

int main (){  
   initwindow(400,200,"test");
   setbkcolor(7);
   clearviewport();
   //char* ch=textfield(100,50,20,16);
   while(true){
       button(0,100,30,20*10+5,16+4);
       button(0,100,70,20*10+5,16+4); 
       button(1,150,110,100,20);
       double l=double_textfield(100,30,20,16); 
       double i=double_textfield(100,70,20,16);
       char ch[4];
       cout<<l+i;
       itoa(l+i,ch,10);
       setcolor(1);
       outtextxy(150+40,110+2,ch);
       getch();
       clearviewport();
   }
   getch();
}
