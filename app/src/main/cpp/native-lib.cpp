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

