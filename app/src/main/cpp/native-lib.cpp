#include <jni.h>
#include <string>
#include <fbjni/fbjni.h>

class MainActivity : public facebook::jni::JavaClass<MainActivity> {
public:
    static constexpr auto kJavaDescriptor = "Lcom/example/fbjniapplicatioin1/MainActivity;";

    static std::string stringFromJNI(facebook::jni::alias_ref<facebook::jni::JClass> clazz) {
        return std::string{"Hello from fbjni"};
    }

    static void registerNatives() {
        javaClassStatic()->registerNatives({
            makeNativeMethod("stringFromJNI", MainActivity::stringFromJNI)
        });
    }
};

extern "C" JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved) {
    return facebook::jni::initialize(vm, [] {
        MainActivity::registerNatives();
    });
}
