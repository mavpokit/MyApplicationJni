#include <jni.h>

#ifndef MYAPPLICATION23_KOTANATIVE_H
#define MYAPPLICATION23_KOTANATIVE_H

#ifdef __cplusplus
extern "C"
{
#endif

JNIEXPORT jstring JNICALL
        Java_com_mavpokit_myapplication_MainActivity_stringFromJNI(JNIEnv *, jobject, jstring,
                                                                   jint);

JNIEXPORT jdouble JNICALL
        Java_com_mavpokit_myapplication_MainActivity_jniAverage(JNIEnv *, jobject, jint, jint);

JNIEXPORT jintArray JNICALL
        Java_com_mavpokit_myapplication_MainActivity_jniMultiply(JNIEnv *, jobject, jintArray, jint);



#ifdef __cplusplus
}
#endif

#endif //MYAPPLICATION23_KOTANATIVE_H
