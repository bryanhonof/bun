/*
    This file is part of the WebKit open source project.
    This file has been generated by generate-bindings.pl. DO NOT MODIFY!

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

#pragma once

#if ENABLE(WEB_CRYPTO)

#include "CryptoKey.h"
#include "JSDOMConvertEnumeration.h"
#include "JSDOMWrapper.h"
#include <wtf/NeverDestroyed.h>

namespace WebCore {

class JSCryptoKey : public JSDOMWrapper<CryptoKey> {
public:
    using Base = JSDOMWrapper<CryptoKey>;
    static JSCryptoKey* create(JSC::Structure* structure, JSDOMGlobalObject* globalObject, Ref<CryptoKey>&& impl)
    {
        JSCryptoKey* ptr = new (NotNull, JSC::allocateCell<JSCryptoKey>(globalObject->vm())) JSCryptoKey(structure, *globalObject, WTFMove(impl));
        ptr->finishCreation(globalObject->vm());
        return ptr;
    }

    static JSC::JSObject* createPrototype(JSC::VM&, JSDOMGlobalObject&);
    static JSC::JSObject* prototype(JSC::VM&, JSDOMGlobalObject&);
    static CryptoKey* toWrapped(JSC::VM&, JSC::JSValue);
    static void destroy(JSC::JSCell*);

    DECLARE_INFO;

    static JSC::Structure* createStructure(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(vm, globalObject, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), info(), JSC::NonArray);
    }

    static JSC::JSValue getConstructor(JSC::VM&, const JSC::JSGlobalObject*);
    mutable JSC::WriteBarrier<JSC::Unknown> m_algorithm;
    mutable JSC::WriteBarrier<JSC::Unknown> m_usages;
    template<typename, JSC::SubspaceAccess mode> static JSC::GCClient::IsoSubspace* subspaceFor(JSC::VM& vm)
    {
        if constexpr (mode == JSC::SubspaceAccess::Concurrently)
            return nullptr;
        return subspaceForImpl(vm);
    }
    static JSC::GCClient::IsoSubspace* subspaceForImpl(JSC::VM& vm);
    DECLARE_VISIT_CHILDREN;

    static void analyzeHeap(JSCell*, JSC::HeapAnalyzer&);

protected:
    JSCryptoKey(JSC::Structure*, JSDOMGlobalObject&, Ref<CryptoKey>&&);

    void finishCreation(JSC::VM&);
};

class JSCryptoKeyOwner final : public JSC::WeakHandleOwner {
public:
    bool isReachableFromOpaqueRoots(JSC::Handle<JSC::Unknown>, void* context, JSC::AbstractSlotVisitor&, ASCIILiteral*) final;
    void finalize(JSC::Handle<JSC::Unknown>, void* context) final;
};

inline JSC::WeakHandleOwner* wrapperOwner(DOMWrapperWorld&, CryptoKey*)
{
    static NeverDestroyed<JSCryptoKeyOwner> owner;
    return &owner.get();
}

inline void* wrapperKey(CryptoKey* wrappableObject)
{
    return wrappableObject;
}

JSC::JSValue toJS(JSC::JSGlobalObject*, JSDOMGlobalObject*, CryptoKey&);
inline JSC::JSValue toJS(JSC::JSGlobalObject* lexicalGlobalObject, JSDOMGlobalObject* globalObject, CryptoKey* impl) { return impl ? toJS(lexicalGlobalObject, globalObject, *impl) : JSC::jsNull(); }
JSC::JSValue toJSNewlyCreated(JSC::JSGlobalObject*, JSDOMGlobalObject*, Ref<CryptoKey>&&);
inline JSC::JSValue toJSNewlyCreated(JSC::JSGlobalObject* lexicalGlobalObject, JSDOMGlobalObject* globalObject, RefPtr<CryptoKey>&& impl) { return impl ? toJSNewlyCreated(lexicalGlobalObject, globalObject, impl.releaseNonNull()) : JSC::jsNull(); }

template<> struct JSDOMWrapperConverterTraits<CryptoKey> {
    using WrapperClass = JSCryptoKey;
    using ToWrappedReturnType = CryptoKey*;
};
String convertEnumerationToString(CryptoKey::Type);
template<> JSC::JSString* convertEnumerationToJS(JSC::JSGlobalObject&, CryptoKey::Type);

template<> std::optional<CryptoKey::Type> parseEnumeration<CryptoKey::Type>(JSC::JSGlobalObject&, JSC::JSValue);
template<> ASCIILiteral expectedEnumerationValues<CryptoKey::Type>();

} // namespace WebCore

#endif // ENABLE(WEB_CRYPTO)
