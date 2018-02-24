//
//  main.cpp
//  plotter
//
//  Created by Soubhi Hadri on 02/03/18.
//  Copyright © 2017 plotter. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "../src/plotter.hpp"

int main( ){
 	cv::Mat plate;
    plotter p(plate,cv::Size(800,800));
    p.draw_circle(plate, 7, 5, -7);
    p.draw_line(plate, 2, 5);
}

