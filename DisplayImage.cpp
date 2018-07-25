#include <stdio.h>
#include <opencv2/opencv.hpp>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "iostream"
 
using namespace cv;
using namespace std;
int main(int argc, char** argv )
{
    //loads rgb image
    Mat image;
    image = imread( argv[1], 1 );

    //convert rgb to gray
    Mat img_gray;
    img_gray = imread(argv[1], CV_LOAD_IMAGE_GRAYSCALE);
    
    //convert gray to bw
    Mat img_bw;
    img_bw = img_gray > 230;

    //display rgb
    //namedWindow("Display Image", WINDOW_AUTOSIZE);
    //imshow("Display Image", image);
    //display gray
    //namedWindow("Display Image gray", WINDOW_AUTOSIZE);
    //imshow("Display Image gray", img_gray);
    //display bw
    //namedWindow("Display Image bw", WINDOW_AUTOSIZE);
    //imshow("Display Image bw", img_bw);

    Mat gray, edge, draw,contourImage, cdst;
    //cvtColor(src1, gray, CV_BGR2GRAY);
 
    Canny( img_bw, edge, 50, 150, 3);
 
    edge.convertTo(draw, CV_8U);

    //namedWindow("draw", CV_WINDOW_AUTOSIZE);
    //imshow("draw", draw);
    cvtColor(edge, cdst, COLOR_GRAY2BGR);

    // Standard Hough Line Transform
    /*vector<Vec2f> lines; // will hold the results of the detection
    HoughLines(edge, lines, 1, CV_PI/1, 150,0, 0 ); // runs the actual detection
    // Draw the lines
    for( size_t i = 0; i < lines.size(); i++ )
    {
        float rho = lines[i][0], theta = lines[i][1];
        Point pt1, pt2;
        double a = cos(theta), b = sin(theta);
        double x0 = a*rho, y0 = b*rho;
        pt1.x = cvRound(x0 + 1000*(-b));
        pt1.y = cvRound(y0 + 1000*(a));
        pt2.x = cvRound(x0 - 1000*(-b));
        pt2.y = cvRound(y0 - 1000*(a));
        line(cdst, pt1, pt2, Scalar(255,255,255), 3, CV_AA);
    }*/
        // Probabilistic Line Transform
    vector<Vec4i> linesP; // will hold the results of the detection
    HoughLinesP(edge, linesP, 1, CV_PI/10, 10, 50, 35 ); // runs the actual detection
    // Draw the lines
    for( size_t i = 0; i < linesP.size(); i++ )
    {
        Vec4i l = linesP[i];
        line( cdst, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(255,255,255), 3, LINE_AA);
    }

    imshow("Detected Lines (in white) - Standard Hough Line Transform", cdst);
    waitKey(0);                                       
    return 0;
}
 
    
