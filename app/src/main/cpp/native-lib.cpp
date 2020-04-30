#include <jni.h>
#include <string>
#include <sstream>

extern "C" JNIEXPORT jstring JNICALL
Java_com_yandex_samples_nativedemo_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject self) {

    std::ostringstream oss;
    oss << "Hello from C++" << ABI << "\n";

    jmethodID mid = env->GetMethodID(env->GetObjectClass(self), "calledByNative", "()I");
    jint result = env->CallIntMethod(self, mid);

    oss << "Result of jvm method invocation is " << result;

    return env->NewStringUTF(oss.str().c_str());
}