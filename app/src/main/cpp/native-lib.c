#include <jni.h>

JNIEXPORT jstring JNICALL
Java_com_android_andi_androidtest_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject obj) {
    char hello[] = "Hello from C";
    return (*env)->NewStringUTF(env, hello);
}
