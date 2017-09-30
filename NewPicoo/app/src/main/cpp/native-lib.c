#include <jni.h>
#include <stdio.h>
//extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_andi_newpicoo_MainActivity_sayHello(
        JNIEnv* env,
        jobject obj) {
        char hello[] = "Hello from C";
        return (*env)->NewStringUTF(env, hello);
}

