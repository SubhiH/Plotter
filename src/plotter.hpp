//
//  plotter.hpp
//  plotter
//
//  Created by Soubhi Hadri on 2/23/18.
//  Copyright © 2018 plotter. All rights reserved.
//

#ifndef plotter_hpp
#define plotter_hpp

#include <stdio.h>
#include <opencv2/core/core.hpp>

class plotter{

public:
    plotter(cv::Mat &plot_img, const cv::Size plot_size, const int step=20);
    void draw_circle(cv::Mat &plot_img, const float raduis, const float circle_center_x, const float circle_center_y, const cv::Scalar plot_color=cv::Scalar(0,0,255));
    void draw_line(cv::Mat &plot_img, const float slope, const float y_intersection, const cv::Scalar plot_colorplot_color=cv::Scalar(0,0,255));
    void draw_line(cv::Mat &plot_img, const cv::Point p1, const cv::Point p2, const cv::Scalar plot_color=cv::Scalar(0,0,255));
    void draw_line(cv::Mat &plot_img, const float x_intersection, const cv::Scalar plot_color=cv::Scalar(0,0,255));
    
private:
    const int step_{10};

};


#endif /* plotter_hpp */
