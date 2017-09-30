#include <jni.h>
#include <time.h>

/* Dimensions of screen in pixels is 480 * 800*/
static double birdPosition = 240;
static double birdVelocity = -9.8;
static int loopCondition = 1;

JNIEXPORT jdouble JNICALL
Java_com_android_andi_androidtest_MainActivity_getBirdPosition(
        JNIEnv *env,
        jobject obj) {
    return birdPosition;
}


JNIEXPORT jstring JNICALL
Java_com_android_andi_androidtest_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject obj) {
    char hello[] = "Hello from C";
    return (*env)->NewStringUTF(env, hello);
}

//Main loop
JNIEXPORT void JNICALL
Java_com_android_andi_androidtest_MainActivity_startGame(
        JNIEnv *env,
        jobject obj) {

    clock_t begin = clock();
    struct timespec sleepTime, interruptTime;
    sleepTime.tv_sec = 0;
    sleepTime.tv_nsec = 417000000;

    while(loopCondition){
        if (birdVelocity < -50)
            birdVelocity = 0;
        if (birdPosition < 0)
            birdPosition = 300;
        birdPosition +=birdVelocity/24;
        birdVelocity -= 0.5;
        nanosleep(&sleepTime, &interruptTime);
    }



}
