/***************************************************************************
 *
 *  main.cpp
 *
 *
 *
 *  A Canny Filter Use Example of OpenCV
 *
 *
 ***************************************************************************
 * Copyright 2018 whuang022.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 **************************************************************************/

#include "opencv2/opencv.hpp"

cv::Mat process(const cv::Mat frame){
    cv::Mat edges;
    cvtColor(frame, edges, cv::COLOR_BGR2GRAY);
    GaussianBlur(edges, edges, cv::Size(7,7), 1.5, 1.5);
    Canny(edges, edges, 0, 30, 3);
    return edges;
}

int main(int, char**){
    //open camer id=0
    cv::VideoCapture cap(0);
    if(!cap.isOpened())
        return -1;
    //set window name
    cv::namedWindow("edges",1);
    while (true){
        cv::Mat frame;
        cap >> frame;//read frame
        imshow("edges", process(frame));//do process and show
        if(cv::waitKey(30) >= 0) break;//wait each 30
    }
    return 0;
}
