#include "stdafx.h"
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp> 
#include <iostream>
#include <stdio.h>
 
using namespace std;
using namespace cv;
int main(int argc, const char** argv)
{
    CascadeClassifier nesne;
    nesne.load("haarcascade_frontalface_default.xml");
    VideoCapture vid;
    vid.open(0);
 
    if (!vid.isOpened())
    {
        cout << "webcam yuklenemedi" << endl; system("Pause"); return -1; } Mat frame; Mat grires; namedWindow("Yuz Tanima", 1); while (true) { vid >> frame;
        cvtColor(frame, grires, CV_BGR2GRAY);  //resmi gri yapar
                                               
        vector<Rect> nesvek;
        nesne.detectMultiScale(grires, nesvek, 1.1, 3, 0, Size(30, 30));
        for (int i = 0; i < nesvek.size(); i++)
        {
            Point pt1(nesvek[i].x + nesvek[i].width, nesvek[i].y + nesvek[i].height);
            Point pt2(nesvek[i].x, nesvek[i].y);
            rectangle(frame, pt1, pt2, cvScalar(0, 255, 0, 0), 1, 8, 0);
        }
        imshow("Yuz Tanima", frame);
        waitKey(33);
    }
    return 0;
}