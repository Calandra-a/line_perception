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
    img_bw = img_gray > 223;

    //display rgb
    //namedWindow("Display Image", WINDOW_AUTOSIZE);
    //imshow("Display Image", image);
    //display gray
    //namedWindow("Display Image gray", WINDOW_AUTOSIZE);
    //imshow("Display Image gray", img_gray);
    //display bw
    //namedWindow("Display Image bw", WINDOW_AUTOSIZE);
    //imshow("Display Image bw", img_bw);

    Mat gray, edge, draw,contourImage;
    //cvtColor(src1, gray, CV_BGR2GRAY);
 
    Canny( img_bw, edge, 55, 163, 3);
 
    edge.convertTo(draw, CV_8U);

    namedWindow("draw", CV_WINDOW_AUTOSIZE);
    imshow("draw", draw);
 

   /* vector<vector<Point> > contours;
    vector<Vec4i> hierarchy;
    findContours(edge, contours, hierarchy, CV_RETR_CCOMP, CV_CHAIN_APPROX_NONE, Point(0,0) );
    for (unsigned int i=0; i<contours.size(); i++)
       if (hierarchy[i][3] >= 0)   //has parent, inner (hole) contour of a closed edge (looks good)
           drawContours(edge, contours, i, Scalar(255, 0, 0), 1, 8);
           //drawContours(contourImage, contours, i, (0,255,0), 3);

    namedWindow("lines", CV_WINDOW_AUTOSIZE);
    imshow("lines", contourImage);
    */
    
    waitKey(0);                                       
    return 0;
}
 
    
