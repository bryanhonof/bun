// This file implements the v8 and node C++ APIs
//
// If you have issues linking this file, you probably have to update
// the code in `napi.zig` at `const V8API`
#include "root.h"
#include "ZigGlobalObject.h"

#if defined(WIN32) || defined(_WIN32)
#define BUN_EXPORT __declspec(dllexport)
#else
#define BUN_EXPORT JS_EXPORT
#endif

extern "C" Zig::GlobalObject* Bun__getDefaultGlobal();

namespace v8 {

using Context = JSC::JSGlobalObject;

class Isolate;

template<class T>
class Local final {
public:
    T* ptr;

    T* operator*() const { return ptr; }
};

class Number {
public:
    BUN_EXPORT static Local<Number> New(Isolate* isolate, double value);

    BUN_EXPORT double Value() const;
};

Local<Number> Number::New(Isolate* isolate, double value)
{
    Bun::JSValue jsv(value);
    auto encoded = Bun::JSValue::encode(jsv);
    auto ptr = reinterpret_cast<Number*>(encoded);
    return Local<Number> { ptr };
}

double Number::Value() const
{
    auto encoded = reinterpret_cast<Bun::EncodedJSValue>(this);
    auto jsv = Bun::JSValue::decode(encoded);
    return jsv.asNumber();
}

// This currently is just a pointer to a Zig::GlobalObject*
// We do that so that we can recover the context and the VM from the "Isolate"
class Isolate final {
public:
    Isolate() = default;

    // Returns the isolate inside which the current thread is running or nullptr.
    BUN_EXPORT static Isolate* TryGetCurrent();

    // Returns the isolate inside which the current thread is running.
    BUN_EXPORT static Isolate* GetCurrent();

    BUN_EXPORT Local<Context> GetCurrentContext();

    Zig::GlobalObject* globalObject() { return reinterpret_cast<Zig::GlobalObject*>(this); }
    JSC::VM& vm() { return globalObject()->vm(); }
};

// Returns the isolate inside which the current thread is running or nullptr.
Isolate* Isolate::TryGetCurrent()
{
    auto* global = Bun__getDefaultGlobal();

    return global ? reinterpret_cast<v8::Isolate*>(global) : nullptr;
}

// Returns the isolate inside which the current thread is running.
Isolate* Isolate::GetCurrent()
{
    auto* global = Bun__getDefaultGlobal();

    return global ? reinterpret_cast<v8::Isolate*>(global) : nullptr;
}

Local<Context> Isolate::GetCurrentContext()
{
    return Local<Context> { reinterpret_cast<Context*>(this) };
}

}

namespace node {

BUN_EXPORT void AddEnvironmentCleanupHook(v8::Isolate* isolate,
    void (*fun)(void* arg),
    void* arg)
{
    // TODO
}

BUN_EXPORT void RemoveEnvironmentCleanupHook(v8::Isolate* isolate,
    void (*fun)(void* arg),
    void* arg)
{
    // TODO
}

}
