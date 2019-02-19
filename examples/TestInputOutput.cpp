/**
 * @file    TestInputOutput.cpp
 *
 * @brief   Test Realsense 2
 *
 * @author  Ba Tran
 *
 * @date    2019-02-19
 *
 *
 * Copyright (c) organization
 *
 */

#include <iostream>
#include <librealsense2/rs.hpp>
#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char* argv[])
{
    std::cout << "Test realsense 2"
              << "\n";

    // Contruct a pipeline which abstracts the device
    rs2::pipeline pipe;

    // Create a configuration for configuring the pipeline with a non default profile
    rs2::config cfg;

    // Add desired streams to configuration
    cfg.enable_stream(RS2_STREAM_COLOR, 640, 480, RS2_FORMAT_BGR8, 30);

    // Instruct pipeline to start streaming with the requested configuration
    pipe.start(cfg);

    // Camera warmup - dropping several first frames to let auto-exposure stabilize
    rs2::frameset frames;

    namedWindow("Display Image", WINDOW_AUTOSIZE);

    while (waitKey(1) < 0) {
        frames = pipe.wait_for_frames();
        // Get each frame
        rs2::frame color_frame = frames.get_color_frame();

        // Creating OpenCV Matrix from a color image
        Mat color(Size(640, 480), CV_8UC3, (void*)color_frame.get_data(), Mat::AUTO_STEP);

        imshow("Display Image", color);
    }

    return 0;
}
