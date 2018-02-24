//
//  plotter.cpp
//  plotter
//
//  Created by Soubhi Hadri on 2/23/18.
//  Copyright © 2018 plotter. All rights reserved.
//

#include "plotter.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

plotter::plotter(cv::Mat &plot_img, const cv::Size plot_size, const int step):
                                                                    step_(step/10){
    plot_img = cv::Mat::zeros(plot_size, CV_8UC3);
    plot_img = cv::Scalar(255,255,255);
    
    //draw coordiates axises
    cv::Point center = cv::Point(plot_img.rows/2,plot_img.cols/2);

    ////x-axis
    auto counter = 0;
    for (int i=0; i<plot_img.cols/2; i++) {
        if(i!=0 && i%step_==0){
            counter++;
            
            if(counter==10){
                counter=0;
                cv::line(plot_img, cv::Point(center.y+i,0), cv::Point(center.y+i,plot_img.rows-1), cv::Scalar(222,222,222));
                cv::line(plot_img, cv::Point(center.y-i,0), cv::Point(center.y-i,plot_img.rows-1), cv::Scalar(222,222,222));
                
                
            }
        }
    }    
    ///Y-axis
    counter = 0;
    for (int i=0; i<plot_img.rows/2; i++) {
        if(i%step_==0){
            counter++;
            if(counter==10){
                counter=0;
                cv::line(plot_img, cv::Point(0,center.x+i), cv::Point(plot_img.cols-1,center.x+i), cv::Scalar(222,222,222));
                cv::line(plot_img, cv::Point(0,center.x-i), cv::Point(plot_img.cols-1,center.x-i), cv::Scalar(222,222,222));
            }
        }
    }
    
    cv::line(plot_img, cv::Point(0,center.x), cv::Point(plot_img.cols-1,center.x), cv::Scalar(0,0,0));
    cv::line(plot_img, cv::Point(center.y,0), cv::Point(center.y,plot_img.rows), cv::Scalar(0,0,0));
//    imshow("Plate", plot_img);
//    cv::waitKey();
}

void plotter::draw_circle(cv::Mat &plot_img, const float raduis, const float circle_center_x, const float circle_center_y, const cv::Scalar plot_color){
    double x = 0;
    cv::Point center = cv::Point(plot_img.rows/2,plot_img.cols/2);
    auto step=step_*10;
    while (x<=raduis*step) {
        
        auto y = std::sqrt(std::pow(raduis, 2)-(std::pow(x-circle_center_x, 2)))+circle_center_y;
        if (center.x-step*y<plot_img.rows && center.x-step*y>=0 && center.y+step*x<plot_img.cols && center.y+step*x>=0){
            plot_img.at<cv::Vec3b>(int(center.x-step*y),int(center.y+step*x))[0] = plot_color[0];
            plot_img.at<cv::Vec3b>(int(center.x-step*y),int(center.y+step*x))[1] = plot_color[1];
            plot_img.at<cv::Vec3b>(int(center.x-step*y),int(center.y+step*x))[2] = plot_color[2];
            
            y = std::sqrt(std::pow(raduis, 2)-(std::pow(x-circle_center_x, 2)))-circle_center_y;
            
            plot_img.at<cv::Vec3b>(int(center.x-step*(-1*y)),int(center.y+step*x))[0] = plot_color[0];
            plot_img.at<cv::Vec3b>(int(center.x-step*(-1*y)),int(center.y+step*x))[1] = plot_color[1];
            plot_img.at<cv::Vec3b>(int(center.x-step*(-1*y)),int(center.y+step*x))[2] = plot_color[2];
        }
        
        y = std::sqrt(std::pow(raduis, 2)-(std::pow(-x-circle_center_x, 2)))+circle_center_y;
        if (center.x-step*y<plot_img.rows && center.x-step*y>=0 && center.y+step*x<plot_img.cols && center.y+step*x>=0){
            if(std::pow(raduis, 2)>=(std::pow(-x-circle_center_x, 2))){
                plot_img.at<cv::Vec3b>(int(center.x-step*y),int(center.y-step*x))[0] = plot_color[0];
                plot_img.at<cv::Vec3b>(int(center.x-step*y),int(center.y-step*x))[1] = plot_color[1];
                plot_img.at<cv::Vec3b>(int(center.x-step*y),int(center.y-step*x))[2] = plot_color[2];
                
                y = std::sqrt(std::pow(raduis, 2)-(std::pow(-x-circle_center_x, 2)))-circle_center_y;
                plot_img.at<cv::Vec3b>(int(center.x-step*(-1*y)),int(center.y-step*x))[0] = plot_color[0];
                plot_img.at<cv::Vec3b>(int(center.x-step*(-1*y)),int(center.y-step*x))[1] = plot_color[1];
                plot_img.at<cv::Vec3b>(int(center.x-step*(-1*y)),int(center.y-step*x))[2] = plot_color[2];
            }

        }

        x = x + 1.0/(step_*150);;
        
    }
//    imshow("output", plot_img);
//    cv::waitKey(0);
}

void plotter::draw_line(cv::Mat &plot_img, const float x_intersection, const cv::Scalar plot_color){
    cv::Point center = cv::Point(plot_img.rows/2,plot_img.cols/2);
    auto step=step_*10;
    cv::line(plot_img,cv::Point(center.y+x_intersection*step,0),cv::Point(center.y+x_intersection*step,plot_img.rows-1),plot_color);
    imshow("output", plot_img);
    cv::waitKey(0);
}


void plotter::draw_line(cv::Mat &plot_img, const cv::Point p1, const cv::Point p2, const cv::Scalar plot_color){
    auto slope = 0.0;
    if(p2.x != p1.x){
        slope = (p2.y-p1.y)/(p2.x-p1.x);
        auto y_interection = p1.y-slope*p1.x;
        draw_line(plot_img,slope,y_interection,plot_color);
    }else{
        draw_line(plot_img,p2.x,plot_color);
    }
}



void plotter::draw_line(cv::Mat &plot_img, const float slope, const float y_intersection, const cv::Scalar plot_color){
    double x = 0;
    cv::Point center = cv::Point(plot_img.rows/2,plot_img.cols/2);
    auto step=step_*10;
    while (x<plot_img.cols) {
        
        auto y = slope*x+y_intersection;
        
        if (center.x-step*y<plot_img.rows && center.x-step*y>0 && center.y+step*x<plot_img.cols && center.y+step*x>0){
            plot_img.at<cv::Vec3b>(int(center.x-step*y),int(center.y+step*x))[0] = plot_color[0];
            plot_img.at<cv::Vec3b>(int(center.x-step*y),int(center.y+step*x))[1] = plot_color[1];
            plot_img.at<cv::Vec3b>(int(center.x-step*y),int(center.y+step*x))[2] = plot_color[2];
        }
        
        y = -1*slope*x+y_intersection;
        if(center.x-step*y>0 && center.y-step*x>0 && center.x-step*y < plot_img.rows && center.y-step*x<plot_img.cols){
            plot_img.at<cv::Vec3b>(center.x-step*y,center.y-step*x)[0] = plot_color[0];
            plot_img.at<cv::Vec3b>(center.x-step*y,center.y-step*x)[1] = plot_color[1];
            plot_img.at<cv::Vec3b>(center.x-step*y,center.y-step*x)[2] = plot_color[2];
            
        }
        x = x + 1.0/(step_*150);
        
    }
//    imshow("output", plot_img);
//    cv::waitKey(0);
}


void plotter::draw_ellipse(cv::Mat &plot_img, const float horizontal_raduis, const float vertical_raduis, const float ellipse_center_x, const float ellipse_center_y, const cv::Scalar plot_color){
    double x = 0;
    cv::Point center = cv::Point(plot_img.rows/2,plot_img.cols/2);
    auto step=step_*10;
    while (x<=horizontal_raduis*step) {
        
        auto y = std::sqrt(((1-(std::pow(x-ellipse_center_x, 2)/std::pow(horizontal_raduis,2))))*vertical_raduis)+ellipse_center_y;
        if (center.x-step*y<plot_img.rows && center.x-step*y>=0 && center.y+step*x<plot_img.cols && center.y+step*x>=0){
            plot_img.at<cv::Vec3b>(int(center.x-step*y),int(center.y+step*x))[0] = plot_color[0];
            plot_img.at<cv::Vec3b>(int(center.x-step*y),int(center.y+step*x))[1] = plot_color[1];
            plot_img.at<cv::Vec3b>(int(center.x-step*y),int(center.y+step*x))[2] = plot_color[2];
            
            y = std::sqrt(((1-(std::pow(x-ellipse_center_x, 2))/std::pow(horizontal_raduis,2)))*vertical_raduis)-ellipse_center_y;
            
            plot_img.at<cv::Vec3b>(int(center.x-step*(-1*y)),int(center.y+step*x))[0] = plot_color[0];
            plot_img.at<cv::Vec3b>(int(center.x-step*(-1*y)),int(center.y+step*x))[1] = plot_color[1];
            plot_img.at<cv::Vec3b>(int(center.x-step*(-1*y)),int(center.y+step*x))[2] = plot_color[2];
        }
        
        y = std::sqrt(((1-(std::pow(-x-ellipse_center_x, 2)/std::pow(horizontal_raduis,2))))*vertical_raduis)+ellipse_center_y;
        if (center.x-step*y<plot_img.rows && center.x-step*y>=0 && center.y+step*x<plot_img.cols && center.y+step*x>=0){
            if(1-(std::pow(-x-ellipse_center_x, 2)/std::pow(horizontal_raduis,2))>=0){
                plot_img.at<cv::Vec3b>(int(center.x-step*y),int(center.y-step*x))[0] = plot_color[0];
                plot_img.at<cv::Vec3b>(int(center.x-step*y),int(center.y-step*x))[1] = plot_color[1];
                plot_img.at<cv::Vec3b>(int(center.x-step*y),int(center.y-step*x))[2] = plot_color[2];

                y = std::sqrt(((1-(std::pow(-x-ellipse_center_x, 2))/std::pow(horizontal_raduis,2)))*vertical_raduis)-ellipse_center_y;
                plot_img.at<cv::Vec3b>(int(center.x-step*(-1*y)),int(center.y-step*x))[0] = plot_color[0];
                plot_img.at<cv::Vec3b>(int(center.x-step*(-1*y)),int(center.y-step*x))[1] = plot_color[1];
                plot_img.at<cv::Vec3b>(int(center.x-step*(-1*y)),int(center.y-step*x))[2] = plot_color[2];
            }

        }
        
        x = x + 1.0/(step_*150);;
        
    }
}
