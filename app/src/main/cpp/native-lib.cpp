#include <jni.h>
#include <string>
#include <sstream>

jmethodID mid;

extern "C" JNIEXPORT jstring JNICALL
Java_com_yandex_samples_nativedemo_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject self) {

    std::ostringstream oss;
    oss << "Hello from C++" << ABI << "\n";

    jint result = env->CallIntMethod(self, mid);

    oss << "Result of jvm method invocation is " << result;

    return env->NewStringUTF(oss.str().c_str());
}


extern "C"
JNIEXPORT void JNICALL
Java_com_yandex_samples_nativedemo_MainActivity_nativeInit(JNIEnv *env, jclass clazz) {
    mid = env->GetMethodID(clazz, "calledByNative", "()I");
}