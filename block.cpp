#include "block.h"
#include <iostream>

#include <cmath>
#include <cstdlib>

int Block::width() const {
    //TODO: Returns the width of the current block.
    return data[1].size();
}

int Block::height() const {
    //TODO: Returns the height of the current block.
    return data.size();
}

void Block::render(PNG &im, int upLeftX, int upLeftY) const {
    //TODO: Draws the current block at position (upLeftX,upLeftY) in im.
    int yMax = min(upLeftY+height(),(int)im.height());
    int xMax = min(upLeftX + width(),(int)im.width());

    for (int y = upLeftY; y < yMax; y++) {
        //std::cout<<"line"<<__LINE__<<": y = "<<y<<std::endl;
        for (int x = upLeftX; x <xMax; x++) {
            *(im.getPixel(x,y)) = data[y-upLeftY][x - upLeftX];
            //std::cout<<"line"<<__LINE__<<": x = "<<x<<std::endl;
        }
    }

}

void Block::build(PNG &im, int upLeftX, int upLeftY, int cols, int rows) {
    //TODO: From im, grabs the rows by cols block of pixels whose upper left corner is position (upLeftX,upLeftY).
    //PNG *ptr_im = &im; // setting the value of ptr_im be the address of im
    data = vector< vector < HSLAPixel > > (rows, vector <HSLAPixel> (cols));

    for (int y = upLeftY; y < upLeftY + rows; y++) {
        //vector<HSLAPixel> row_vector;
        //std::cout<<"line"<<__LINE__<<": y = "<<y<<std::endl;
        for (int x = upLeftX; x < upLeftX + cols; x++) {
            // (y1,y2,y3...)
            // std::cout<<"line"<<__LINE__<<": x = "<<x<<std::endl;
            HSLAPixel *pixel = im.getPixel(x, y);
            data[y-upLeftY][x - upLeftX]=*pixel;

            //row_vector.push_back(*pixel);
        }
        //data.push_back(row_vector);
    }}

//    //std::cout<<"num of cols: "<<data[1].size()<<std::endl;
//    //std::cout<<"num of rows: "<<data.size()<<std::endl;
//
//void Block::build(PNG & im, int upLeftX, int upLeftY, int cols, int rows) {
//
//    //    int i=0;
//    //    int j=0;
//    data =vector<vector<HSLAPixel>>(rows, vector<HSLAPixel>(cols));
//
//    for (int y = upLeftY; y < upLeftY+rows; y++) {
//        for (int x = upLeftX; x < upLeftX+cols; x++) {
//            HSLAPixel* hp= im.getPixel(x,y);
//                       data[y-upLeftY][x-upLeftX]= *hp;
//            // data[i][j]= *hp;
//            //            j++;
//        }
//        //        i++;
//    }
//}
//void Block::render(PNG & im, int upLeftX, int upLeftY) const {
//
//    //    int i=0;
//    //    int j=0;
//    for (int y = upLeftY; y < upLeftY+height(); y++) {  // TODO: y < data.size()??
//
//        for (int x = upLeftX; x < upLeftX+width(); x++) {
//
//            HSLAPixel hpBlock= data[y-upLeftY][x-upLeftX];
//            //            HSLAPixel hpBlock= data[i][j];
//            *im.getPixel(x,y)=hpBlock;
//            //            j++;
//        }
//        //         i++;
//    }
//
//}

    
    
   

