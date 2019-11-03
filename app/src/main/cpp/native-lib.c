//c ++ 的写法
#if 0
#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring JNICALL
Java_itboy_jnidemo_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {

#ifdef ENABLE_RTC
    std::string hello = "Hello RTC";
    return env->NewStringUTF(hello.c_str());
#else
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
#endif

}
#else
//c的写法
#include <jni.h>
#include <stdlib.h>
#include <stdio.h>
JNIEXPORT jstring JNICALL Java_itboy_jnidemo_MainActivity_stringFromJNI(
        JNIEnv* env,jobject cls) {
#ifdef ENABLE_RTC
    return (*env)->NewStringUTF(env, "你好,RTC");
#else
    return (*env)->NewStringUTF(env, "你好,我来自C代码 !!!");
#endif
}
#endif


