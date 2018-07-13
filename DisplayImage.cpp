#include <stdio.h>
#include <opencv2/opencv.hpp>
using namespace cv;
int main(int argc, char** argv )
{
   /* if ( argc != 2 )
    {
        printf("usage: load.out ~/Pictures/image.png\n");
        return -1;
    }*/
    Mat image;
    image = imread( argv[1], 1 );
/*    if ( !image.data )
    {
        printf("No image data \n");
        return -1;
    }*/

    //Converting the Image into GrayScale and Storing it in a Matrix 'img_gray'
    Mat img_gray;
    img_gray = imread(argv[1], CV_LOAD_IMAGE_GRAYSCALE);

    namedWindow("Display Image", WINDOW_AUTOSIZE);
    imshow("Display Image", image);
    namedWindow("Display Image gray", WINDOW_AUTOSIZE);
    imshow("Display Image gray", img_gray);
    waitKey(0);
    return 0;
}
