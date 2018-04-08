/**
 * @file main.cpp
 * A simple C++ program that manipulates an image.
 *
 * @author CS 221: Basic Algorithms and Data Structures
**/

#include "chain.h"
#include "block.h"
#include "PNGutil.h"
#include "cs221util/PNG.h"
using namespace cs221util;
using namespace std;

int main() {
   PNG png1;

   png1.readFromFile("images/rosegarden.png");
   PNG result1 = grayscale(png1);
   result1.writeToFile("images/out-ubcRose.png");

   Block b;
   b.build(png1,0,150,450,225);
   
   b.render(result1,450,300);
   result1.writeToFile("images/out-blocktest.png");

  
   Chain c(png1,1,16);
   
//    PNG result8 = c.render(1,16);
//    result8.writeToFile("images/out-rotate.png");
   
   for (int i = 1; i < c.size(); i*=2){
      c.moveToBack(1+c.size()*(i-1)/i, c.size()/(2*i));
   }

   PNG result2 = c.render(1,16);
   result2.writeToFile("images/out-moveToBack.png");
    
//    c.insertFront(b);
//    PNG result3 = c.render(1,16);
//    result3.writeToFile("images/out-moveToFront.png");
    
    
    

   Chain d(png1,2,8);
//   d.swap(4,5);
//   d.swap(15,16);
    //d.swap(16,15);
//d.swap(1,2);
//   d.swap(2,1);
//  d.swap(0,5);
//   d.swap(1,17);
//    d.swap(2,13);
   d.swap(13,12);
    
    
    
    
    
    
   PNG result3 = d.render(2,8);
   result3.writeToFile("images/out-swapEasy.png");

   Chain e(png1,4,18);
    Chain g(e);
   Chain f(result1,4,18);
    g.twist(f);//g.twist(f);
   PNG result6 = g.render(4,18);//PNG result6 = g.render(4,18);
   PNG result7 = f.render(4,18);
   result6.writeToFile("images/out-twistSame1.png");
   result7.writeToFile("images/out-twistSame2.png");

    Chain h(png1,1,16);
    h.rotate(5);
    PNG result8 = h.render(1,16);
    result8.writeToFile("images/out-origionImg.png");

    g = f;
    PNG result11 = g.render(4,18);
    result11.writeToFile("images/out-twistSame2(1).png");
    
    
//    Chain x(png1,1,18);
//    x.insertBack(x.head_->next->data);
//    Chain y(png1,1,18);
//    
    
    
//    x.twist(y);
//    PNG result9 = x.render(1,19);
//    PNG result10 = y.render(1,18);
//    result9.writeToFile("images/1.png");
//    result10.writeToFile("images/2.png");
    
    Chain i(png1,1,16);
   // i.moveToBack(1,1);
//    i.moveToBack(16,1);
//   i.moveToBack(16,2);
   i.moveToBack(4,8);
//
    PNG result9 = i.render(1,16);
    result9.writeToFile("images/out-mvb1.png");



    

   return 0;
}
