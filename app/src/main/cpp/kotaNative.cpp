#include "kotaNative.h"
#include <string.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <android/log.h>


JNIEXPORT jstring JNICALL
Java_com_mavpokit_myapplication_MainActivity_stringFromJNI(JNIEnv *env, jobject thiz, jstring s1,
                                                           jint i1) {
    const char *s2 = env->GetStringUTFChars(s1, NULL);
    std::string s2a = env->GetStringUTFChars(s1, NULL);

    char s3a[] = " + String from JNI ®";
    char s3b[50] = "aaaaaaaaaaaaaaaa";

    s2a += s3a;

    int i2 = i1;

    std::ostringstream ss;
    ss << i2;
    std::string s(ss.str());
    s2a += s;
    s2a+=s2;

    strcat(s3b, s3a);

    #define APPNAME "*****"

    __android_log_print(ANDROID_LOG_VERBOSE, APPNAME, s2 , 1);



    jsize j2;

//    return env->NewStringUTF(s3b);
    return env->NewStringUTF(s2a.c_str());
}

JNIEXPORT jdouble JNICALL
Java_com_mavpokit_myapplication_MainActivity_jniAverage(JNIEnv *env, jobject thiz, jint a, jint b) {
    jdouble result = (a + b)/2.0;
    return result;
}

JNIEXPORT jintArray JNICALL
Java_com_mavpokit_myapplication_MainActivity_jniMultiply(JNIEnv *env, jobject thiz, jintArray ja, jint mul) {

    int *array = env->GetIntArrayElements(ja,NULL);
    if (array==NULL) return NULL;
    int size = env->GetArrayLength(ja);

    for (int i=0;i<size;i++)
        *(array+i)=*(array+i)*mul;

    jintArray out = env->NewIntArray(size);
    env->SetIntArrayRegion(out,0,size,array);

    return out;
}

JNIEXPORT jobject JNICALL
Java_com_mavpokit_myapplication_MainActivity_jniSync(JNIEnv *env, jobject instance){
    jclass clazz = env->FindClass("com/mavpokit/myapplication/SyncResult");
    if (NULL == clazz) return NULL;
    jmethodID mid = env->GetMethodID(clazz, "<init>", "(JJ)V");
    if (NULL == mid) return NULL;
    return env->NewObject(clazz, mid, 5l, 7l);

}



//for pure C
//JNIEXPORT jstring JNICALL
//Java_com_mavpokit_myapplication_MainActivity_stringFromJNI( JNIEnv *env,jobject thiz)
//{
//    return (*env)->NewStringUTF(env, "Hello from JNI !  Compiled with ABI");
//}
