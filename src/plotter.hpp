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
#include <vector>
#include <opencv2/core/core.hpp>

class plotter{

public:
    plotter(cv::Mat &plot_img, const cv::Size plot_size, const int step=20);
    
    void plot_line(cv::Mat &plot_img, const float slope, const float y_intersection, const cv::Scalar plot_colorplot_color=cv::Scalar(0,0,255));
    void plot_line(cv::Mat &plot_img, const cv::Point p1, const cv::Point p2, const cv::Scalar plot_color=cv::Scalar(0,0,255));
    void plot_line(cv::Mat &plot_img, const float x_intersection, const cv::Scalar plot_color=cv::Scalar(0,0,255));
    
    void plot_circle(cv::Mat &plot_img, const float raduis, const float circle_center_x, const float circle_center_y, const cv::Scalar plot_color=cv::Scalar(0,0,255));
    
    void plot_ellipse(cv::Mat &plot_img, const float horizontal_raduis, const float vertical_raduis, const float ellipse_center_x, const float ellipse_center_y, const cv::Scalar plot_color=cv::Scalar(0,0,255));
    
    void plot_polynomial(cv::Mat &plot_img, const int degree, const std::vector<double>coefficient, const cv::Scalar plot_color=cv::Scalar(0,0,255));
    
private:
    const int step_{10};

};


#endif /* plotter_hpp */
