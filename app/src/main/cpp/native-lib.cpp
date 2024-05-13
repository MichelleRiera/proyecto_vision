#include <jni.h>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <android/log.h>

extern "C" {

JNIEXPORT void JNICALL
Java_giiata_vision_opencvhelade_MainActivity_openCamera(JNIEnv *env, jobject instance, jlong matAddr) {
    cv::Mat& frame = *(cv::Mat*)matAddr;
    cv::VideoCapture cap(0);
    if (!cap.isOpened()) {
        __android_log_print(ANDROID_LOG_ERROR, "Native-Lib", "Cannot open camera");
        return;
    }

    while (true) {
        cap >> frame;
        if (frame.empty()) {
            __android_log_print(ANDROID_LOG_ERROR, "Native-Lib", "Frame is empty");
            break;
        }
    }
    cap.release();
}

}
