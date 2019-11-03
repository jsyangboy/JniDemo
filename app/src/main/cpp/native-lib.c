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
#include "libavcodec/avcodec.h"
#include "libavcodec/avcodec.h"
#include "libavformat/avformat.h"
#include "libswscale/swscale.h"
#include "libswresample/swresample.h"

#include "libavutil/time.h"

static AVPacket *gs_packet=NULL;
static AVPacket *gs_packetTemp = NULL;
static AVFormatContext *gs_pformat_ctx = NULL;
static int videoIndex = -1, audioIndex = -1,waitkey = 1;
static char gs_filename[1024];

JNIEXPORT jstring JNICALL Java_itboy_jnidemo_MainActivity_stringFromJNI(
        JNIEnv* env,jobject cls) {
    AVOutputFormat *of = av_guess_format( 0, "file://", 0 );
    gs_pformat_ctx = avformat_alloc_context();

#ifdef ENABLE_RTC
    return (*env)->NewStringUTF(env, "你好,RTC");
#else
    return (*env)->NewStringUTF(env, "你好,我来自C代码 !!!");
#endif
}
#endif


