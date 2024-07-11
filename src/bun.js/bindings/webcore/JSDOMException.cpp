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

#include "root.h"

#include "JSDOMException.h"

#include "ActiveDOMObject.h"
#include "ExtendedDOMClientIsoSubspaces.h"
#include "ExtendedDOMIsoSubspaces.h"
#include "JSDOMAttribute.h"
#include "JSDOMBinding.h"
#include "JSDOMConstructor.h"
#include "JSDOMConvertInterface.h"
#include "JSDOMConvertNumbers.h"
#include "JSDOMConvertStrings.h"
#include "JSDOMExceptionHandling.h"
#include "JSDOMGlobalObjectInlines.h"
#include "JSDOMWrapperCache.h"
#include "ScriptExecutionContext.h"
#include "WebCoreJSClientData.h"
#include <JavaScriptCore/FunctionPrototype.h>
#include <JavaScriptCore/HeapAnalyzer.h>

#include <JavaScriptCore/JSDestructibleObjectHeapCellType.h>
#include <JavaScriptCore/SlotVisitorMacros.h>
#include <JavaScriptCore/SubspaceInlines.h>
#include <wtf/GetPtr.h>
#include <wtf/PointerPreparations.h>
#include <wtf/URL.h>

namespace WebCore {
using namespace JSC;

// Attributes

static JSC_DECLARE_CUSTOM_GETTER(jsDOMExceptionConstructor);
static JSC_DECLARE_CUSTOM_GETTER(jsDOMException_code);
static JSC_DECLARE_CUSTOM_GETTER(jsDOMException_name);
static JSC_DECLARE_CUSTOM_GETTER(jsDOMException_message);

class JSDOMExceptionPrototype final : public JSC::JSNonFinalObject {
public:
    using Base = JSC::JSNonFinalObject;
    static JSDOMExceptionPrototype* create(JSC::VM& vm, JSDOMGlobalObject* globalObject, JSC::Structure* structure)
    {
        JSDOMExceptionPrototype* ptr = new (NotNull, JSC::allocateCell<JSDOMExceptionPrototype>(vm)) JSDOMExceptionPrototype(vm, globalObject, structure);
        ptr->finishCreation(vm);
        return ptr;
    }

    DECLARE_INFO;
    template<typename CellType, JSC::SubspaceAccess>
    static JSC::GCClient::IsoSubspace* subspaceFor(JSC::VM& vm)
    {
        STATIC_ASSERT_ISO_SUBSPACE_SHARABLE(JSDOMExceptionPrototype, Base);
        return &vm.plainObjectSpace();
    }
    static JSC::Structure* createStructure(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(vm, globalObject, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), info());
    }

private:
    JSDOMExceptionPrototype(JSC::VM& vm, JSC::JSGlobalObject*, JSC::Structure* structure)
        : JSC::JSNonFinalObject(vm, structure)
    {
    }

    void finishCreation(JSC::VM&);
};
STATIC_ASSERT_ISO_SUBSPACE_SHARABLE(JSDOMExceptionPrototype, JSDOMExceptionPrototype::Base);

using JSDOMExceptionDOMConstructor = JSDOMConstructor<JSDOMException>;

/* Hash table for constructor */

static const HashTableValue JSDOMExceptionConstructorTableValues[] = {
    { "INDEX_SIZE_ERR"_s, JSC::PropertyAttribute::DontDelete | JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::ConstantInteger, NoIntrinsic, { HashTableValue::ConstantType, 1 } },
    { "DOMSTRING_SIZE_ERR"_s, JSC::PropertyAttribute::DontDelete | JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::ConstantInteger, NoIntrinsic, { HashTableValue::ConstantType, 2 } },
    { "HIERARCHY_REQUEST_ERR"_s, JSC::PropertyAttribute::DontDelete | JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::ConstantInteger, NoIntrinsic, { HashTableValue::ConstantType, 3 } },
    { "WRONG_DOCUMENT_ERR"_s, JSC::PropertyAttribute::DontDelete | JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::ConstantInteger, NoIntrinsic, { HashTableValue::ConstantType, 4 } },
    { "INVALID_CHARACTER_ERR"_s, JSC::PropertyAttribute::DontDelete | JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::ConstantInteger, NoIntrinsic, { HashTableValue::ConstantType, 5 } },
    { "NO_DATA_ALLOWED_ERR"_s, JSC::PropertyAttribute::DontDelete | JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::ConstantInteger, NoIntrinsic, { HashTableValue::ConstantType, 6 } },
    { "NO_MODIFICATION_ALLOWED_ERR"_s, JSC::PropertyAttribute::DontDelete | JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::ConstantInteger, NoIntrinsic, { HashTableValue::ConstantType, 7 } },
    { "NOT_FOUND_ERR"_s, JSC::PropertyAttribute::DontDelete | JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::ConstantInteger, NoIntrinsic, { HashTableValue::ConstantType, 8 } },
    { "NOT_SUPPORTED_ERR"_s, JSC::PropertyAttribute::DontDelete | JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::ConstantInteger, NoIntrinsic, { HashTableValue::ConstantType, 9 } },
    { "INUSE_ATTRIBUTE_ERR"_s, JSC::PropertyAttribute::DontDelete | JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::ConstantInteger, NoIntrinsic, { HashTableValue::ConstantType, 10 } },
    { "INVALID_STATE_ERR"_s, JSC::PropertyAttribute::DontDelete | JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::ConstantInteger, NoIntrinsic, { HashTableValue::ConstantType, 11 } },
    { "SYNTAX_ERR"_s, JSC::PropertyAttribute::DontDelete | JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::ConstantInteger, NoIntrinsic, { HashTableValue::ConstantType, 12 } },
    { "INVALID_MODIFICATION_ERR"_s, JSC::PropertyAttribute::DontDelete | JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::ConstantInteger, NoIntrinsic, { HashTableValue::ConstantType, 13 } },
    { "NAMESPACE_ERR"_s, JSC::PropertyAttribute::DontDelete | JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::ConstantInteger, NoIntrinsic, { HashTableValue::ConstantType, 14 } },
    { "INVALID_ACCESS_ERR"_s, JSC::PropertyAttribute::DontDelete | JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::ConstantInteger, NoIntrinsic, { HashTableValue::ConstantType, 15 } },
    { "VALIDATION_ERR"_s, JSC::PropertyAttribute::DontDelete | JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::ConstantInteger, NoIntrinsic, { HashTableValue::ConstantType, 16 } },
    { "TYPE_MISMATCH_ERR"_s, JSC::PropertyAttribute::DontDelete | JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::ConstantInteger, NoIntrinsic, { HashTableValue::ConstantType, 17 } },
    { "SECURITY_ERR"_s, JSC::PropertyAttribute::DontDelete | JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::ConstantInteger, NoIntrinsic, { HashTableValue::ConstantType, 18 } },
    { "NETWORK_ERR"_s, JSC::PropertyAttribute::DontDelete | JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::ConstantInteger, NoIntrinsic, { HashTableValue::ConstantType, 19 } },
    { "ABORT_ERR"_s, JSC::PropertyAttribute::DontDelete | JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::ConstantInteger, NoIntrinsic, { HashTableValue::ConstantType, 20 } },
    { "URL_MISMATCH_ERR"_s, JSC::PropertyAttribute::DontDelete | JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::ConstantInteger, NoIntrinsic, { HashTableValue::ConstantType, 21 } },
    { "QUOTA_EXCEEDED_ERR"_s, JSC::PropertyAttribute::DontDelete | JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::ConstantInteger, NoIntrinsic, { HashTableValue::ConstantType, 22 } },
    { "TIMEOUT_ERR"_s, JSC::PropertyAttribute::DontDelete | JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::ConstantInteger, NoIntrinsic, { HashTableValue::ConstantType, 23 } },
    { "INVALID_NODE_TYPE_ERR"_s, JSC::PropertyAttribute::DontDelete | JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::ConstantInteger, NoIntrinsic, { HashTableValue::ConstantType, 24 } },
    { "DATA_CLONE_ERR"_s, JSC::PropertyAttribute::DontDelete | JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::ConstantInteger, NoIntrinsic, { HashTableValue::ConstantType, 25 } },
};

template<> JSC::EncodedJSValue JSC_HOST_CALL_ATTRIBUTES JSDOMExceptionDOMConstructor::construct(JSGlobalObject* lexicalGlobalObject, CallFrame* callFrame)
{
    VM& vm = lexicalGlobalObject->vm();
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    auto* castedThis = jsCast<JSDOMExceptionDOMConstructor*>(callFrame->jsCallee());
    ASSERT(castedThis);
    EnsureStillAliveScope argument0 = callFrame->argument(0);
    auto message = argument0.value().isUndefined() ? emptyString() : convert<IDLDOMString>(*lexicalGlobalObject, argument0.value());
    RETURN_IF_EXCEPTION(throwScope, encodedJSValue());
    EnsureStillAliveScope argument1 = callFrame->argument(1);
    auto name = argument1.value().isUndefined() ? "Error"_s : convert<IDLDOMString>(*lexicalGlobalObject, argument1.value());
    RETURN_IF_EXCEPTION(throwScope, encodedJSValue());
    auto object = DOMException::create(WTFMove(message), WTFMove(name));
    if constexpr (IsExceptionOr<decltype(object)>)
        RETURN_IF_EXCEPTION(throwScope, {});
    static_assert(TypeOrExceptionOrUnderlyingType<decltype(object)>::isRef);
    auto jsValue = toJSNewlyCreated<IDLInterface<DOMException>>(*lexicalGlobalObject, *castedThis->globalObject(), throwScope, WTFMove(object));
    if constexpr (IsExceptionOr<decltype(object)>)
        RETURN_IF_EXCEPTION(throwScope, {});
    setSubclassStructureIfNeeded<DOMException>(lexicalGlobalObject, callFrame, asObject(jsValue));
    RETURN_IF_EXCEPTION(throwScope, {});
    return JSValue::encode(jsValue);
}
JSC_ANNOTATE_HOST_FUNCTION(JSDOMExceptionDOMConstructorConstruct, JSDOMExceptionDOMConstructor::construct);

template<> const ClassInfo JSDOMExceptionDOMConstructor::s_info = { "DOMException"_s, &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSDOMExceptionDOMConstructor) };

template<> JSValue JSDOMExceptionDOMConstructor::prototypeForStructure(JSC::VM& vm, const JSDOMGlobalObject& globalObject)
{
    UNUSED_PARAM(vm);
    return globalObject.functionPrototype();
}

template<> void JSDOMExceptionDOMConstructor::initializeProperties(VM& vm, JSDOMGlobalObject& globalObject)
{
    putDirect(vm, vm.propertyNames->length, jsNumber(0), JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum);
    JSString* nameString = jsNontrivialString(vm, "DOMException"_s);
    m_originalName.set(vm, this, nameString);
    putDirect(vm, vm.propertyNames->name, nameString, JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum);
    putDirect(vm, vm.propertyNames->prototype, JSDOMException::prototype(vm, globalObject), JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum | JSC::PropertyAttribute::DontDelete);
    reifyStaticProperties(vm, JSDOMException::info(), JSDOMExceptionConstructorTableValues, *this);
}

/* Hash table for prototype */

static const HashTableValue JSDOMExceptionPrototypeTableValues[] = {
    { "constructor"_s, static_cast<unsigned>(JSC::PropertyAttribute::DontEnum), NoIntrinsic, { HashTableValue::GetterSetterType, jsDOMExceptionConstructor, 0 } },
    { "code"_s, static_cast<unsigned>(JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::CustomAccessor | JSC::PropertyAttribute::DOMAttribute), NoIntrinsic, { HashTableValue::GetterSetterType, jsDOMException_code, 0 } },
    { "name"_s, static_cast<unsigned>(JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::CustomAccessor | JSC::PropertyAttribute::DOMAttribute), NoIntrinsic, { HashTableValue::GetterSetterType, jsDOMException_name, 0 } },
    { "message"_s, static_cast<unsigned>(JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::CustomAccessor | JSC::PropertyAttribute::DOMAttribute), NoIntrinsic, { HashTableValue::GetterSetterType, jsDOMException_message, 0 } },
    { "INDEX_SIZE_ERR"_s, JSC::PropertyAttribute::DontDelete | JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::ConstantInteger, NoIntrinsic, { HashTableValue::ConstantType, 1 } },
    { "DOMSTRING_SIZE_ERR"_s, JSC::PropertyAttribute::DontDelete | JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::ConstantInteger, NoIntrinsic, { HashTableValue::ConstantType, 2 } },
    { "HIERARCHY_REQUEST_ERR"_s, JSC::PropertyAttribute::DontDelete | JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::ConstantInteger, NoIntrinsic, { HashTableValue::ConstantType, 3 } },
    { "WRONG_DOCUMENT_ERR"_s, JSC::PropertyAttribute::DontDelete | JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::ConstantInteger, NoIntrinsic, { HashTableValue::ConstantType, 4 } },
    { "INVALID_CHARACTER_ERR"_s, JSC::PropertyAttribute::DontDelete | JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::ConstantInteger, NoIntrinsic, { HashTableValue::ConstantType, 5 } },
    { "NO_DATA_ALLOWED_ERR"_s, JSC::PropertyAttribute::DontDelete | JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::ConstantInteger, NoIntrinsic, { HashTableValue::ConstantType, 6 } },
    { "NO_MODIFICATION_ALLOWED_ERR"_s, JSC::PropertyAttribute::DontDelete | JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::ConstantInteger, NoIntrinsic, { HashTableValue::ConstantType, 7 } },
    { "NOT_FOUND_ERR"_s, JSC::PropertyAttribute::DontDelete | JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::ConstantInteger, NoIntrinsic, { HashTableValue::ConstantType, 8 } },
    { "NOT_SUPPORTED_ERR"_s, JSC::PropertyAttribute::DontDelete | JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::ConstantInteger, NoIntrinsic, { HashTableValue::ConstantType, 9 } },
    { "INUSE_ATTRIBUTE_ERR"_s, JSC::PropertyAttribute::DontDelete | JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::ConstantInteger, NoIntrinsic, { HashTableValue::ConstantType, 10 } },
    { "INVALID_STATE_ERR"_s, JSC::PropertyAttribute::DontDelete | JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::ConstantInteger, NoIntrinsic, { HashTableValue::ConstantType, 11 } },
    { "SYNTAX_ERR"_s, JSC::PropertyAttribute::DontDelete | JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::ConstantInteger, NoIntrinsic, { HashTableValue::ConstantType, 12 } },
    { "INVALID_MODIFICATION_ERR"_s, JSC::PropertyAttribute::DontDelete | JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::ConstantInteger, NoIntrinsic, { HashTableValue::ConstantType, 13 } },
    { "NAMESPACE_ERR"_s, JSC::PropertyAttribute::DontDelete | JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::ConstantInteger, NoIntrinsic, { HashTableValue::ConstantType, 14 } },
    { "INVALID_ACCESS_ERR"_s, JSC::PropertyAttribute::DontDelete | JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::ConstantInteger, NoIntrinsic, { HashTableValue::ConstantType, 15 } },
    { "VALIDATION_ERR"_s, JSC::PropertyAttribute::DontDelete | JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::ConstantInteger, NoIntrinsic, { HashTableValue::ConstantType, 16 } },
    { "TYPE_MISMATCH_ERR"_s, JSC::PropertyAttribute::DontDelete | JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::ConstantInteger, NoIntrinsic, { HashTableValue::ConstantType, 17 } },
    { "SECURITY_ERR"_s, JSC::PropertyAttribute::DontDelete | JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::ConstantInteger, NoIntrinsic, { HashTableValue::ConstantType, 18 } },
    { "NETWORK_ERR"_s, JSC::PropertyAttribute::DontDelete | JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::ConstantInteger, NoIntrinsic, { HashTableValue::ConstantType, 19 } },
    { "ABORT_ERR"_s, JSC::PropertyAttribute::DontDelete | JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::ConstantInteger, NoIntrinsic, { HashTableValue::ConstantType, 20 } },
    { "URL_MISMATCH_ERR"_s, JSC::PropertyAttribute::DontDelete | JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::ConstantInteger, NoIntrinsic, { HashTableValue::ConstantType, 21 } },
    { "QUOTA_EXCEEDED_ERR"_s, JSC::PropertyAttribute::DontDelete | JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::ConstantInteger, NoIntrinsic, { HashTableValue::ConstantType, 22 } },
    { "TIMEOUT_ERR"_s, JSC::PropertyAttribute::DontDelete | JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::ConstantInteger, NoIntrinsic, { HashTableValue::ConstantType, 23 } },
    { "INVALID_NODE_TYPE_ERR"_s, JSC::PropertyAttribute::DontDelete | JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::ConstantInteger, NoIntrinsic, { HashTableValue::ConstantType, 24 } },
    { "DATA_CLONE_ERR"_s, JSC::PropertyAttribute::DontDelete | JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::ConstantInteger, NoIntrinsic, { HashTableValue::ConstantType, 25 } },
};

const ClassInfo JSDOMExceptionPrototype::s_info = { "DOMException"_s, &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSDOMExceptionPrototype) };

void JSDOMExceptionPrototype::finishCreation(VM& vm)
{
    Base::finishCreation(vm);
    reifyStaticProperties(vm, JSDOMException::info(), JSDOMExceptionPrototypeTableValues, *this);
    JSC_TO_STRING_TAG_WITHOUT_TRANSITION();
}

const ClassInfo JSDOMException::s_info = { "DOMException"_s, &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSDOMException) };

JSDOMException::JSDOMException(Structure* structure, JSDOMGlobalObject& globalObject, Ref<DOMException>&& impl)
    : JSDOMWrapper<DOMException>(structure, globalObject, WTFMove(impl))
{
}

void JSDOMException::finishCreation(VM& vm)
{
    Base::finishCreation(vm);
    ASSERT(inherits(info()));

    // static_assert(!std::is_base_of<ActiveDOMObject, DOMException>::value, "Interface is not marked as [ActiveDOMObject] even though implementation class subclasses ActiveDOMObject.");
}

JSObject* JSDOMException::createPrototype(VM& vm, JSDOMGlobalObject& globalObject)
{
    return JSDOMExceptionPrototype::create(vm, &globalObject, JSDOMExceptionPrototype::createStructure(vm, &globalObject, globalObject.errorPrototype()));
}

JSObject* JSDOMException::prototype(VM& vm, JSDOMGlobalObject& globalObject)
{
    return getDOMPrototype<JSDOMException>(vm, globalObject);
}

JSValue JSDOMException::getConstructor(VM& vm, const JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSDOMExceptionDOMConstructor, DOMConstructorID::DOMException>(vm, *jsCast<const JSDOMGlobalObject*>(globalObject));
}

void JSDOMException::destroy(JSC::JSCell* cell)
{
    JSDOMException* thisObject = static_cast<JSDOMException*>(cell);
    thisObject->JSDOMException::~JSDOMException();
}

JSC_DEFINE_CUSTOM_GETTER(jsDOMExceptionConstructor, (JSGlobalObject * lexicalGlobalObject, JSC::EncodedJSValue thisValue, PropertyName))
{
    VM& vm = JSC::getVM(lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    auto* prototype = jsDynamicCast<JSDOMExceptionPrototype*>(JSValue::decode(thisValue));
    if (UNLIKELY(!prototype))
        return throwVMTypeError(lexicalGlobalObject, throwScope);
    return JSValue::encode(JSDOMException::getConstructor(JSC::getVM(lexicalGlobalObject), prototype->globalObject()));
}

static inline JSValue jsDOMException_codeGetter(JSGlobalObject& lexicalGlobalObject, JSDOMException& thisObject)
{
    auto& vm = JSC::getVM(&lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    auto& impl = thisObject.wrapped();
    RELEASE_AND_RETURN(throwScope, (toJS<IDLUnsignedShort>(lexicalGlobalObject, throwScope, impl.legacyCode())));
}

JSC_DEFINE_CUSTOM_GETTER(jsDOMException_code, (JSGlobalObject * lexicalGlobalObject, JSC::EncodedJSValue thisValue, PropertyName attributeName))
{
    return IDLAttribute<JSDOMException>::get<jsDOMException_codeGetter, CastedThisErrorBehavior::Assert>(*lexicalGlobalObject, thisValue, attributeName);
}

static inline JSValue jsDOMException_nameGetter(JSGlobalObject& lexicalGlobalObject, JSDOMException& thisObject)
{
    auto& vm = JSC::getVM(&lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    auto& impl = thisObject.wrapped();
    RELEASE_AND_RETURN(throwScope, (toJS<IDLDOMString>(lexicalGlobalObject, throwScope, impl.name())));
}

JSC_DEFINE_CUSTOM_GETTER(jsDOMException_name, (JSGlobalObject * lexicalGlobalObject, JSC::EncodedJSValue thisValue, PropertyName attributeName))
{
    return IDLAttribute<JSDOMException>::get<jsDOMException_nameGetter, CastedThisErrorBehavior::Assert>(*lexicalGlobalObject, thisValue, attributeName);
}

static inline JSValue jsDOMException_messageGetter(JSGlobalObject& lexicalGlobalObject, JSDOMException& thisObject)
{
    auto& vm = JSC::getVM(&lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    auto& impl = thisObject.wrapped();
    RELEASE_AND_RETURN(throwScope, (toJS<IDLDOMString>(lexicalGlobalObject, throwScope, impl.message())));
}

JSC_DEFINE_CUSTOM_GETTER(jsDOMException_message, (JSGlobalObject * lexicalGlobalObject, JSC::EncodedJSValue thisValue, PropertyName attributeName))
{
    return IDLAttribute<JSDOMException>::get<jsDOMException_messageGetter, CastedThisErrorBehavior::Assert>(*lexicalGlobalObject, thisValue, attributeName);
}

JSC::GCClient::IsoSubspace* JSDOMException::subspaceForImpl(JSC::VM& vm)
{
    return WebCore::subspaceForImpl<JSDOMException, UseCustomHeapCellType::No>(
        vm,
        [](auto& spaces) { return spaces.m_clientSubspaceForDOMException.get(); },
        [](auto& spaces, auto&& space) { spaces.m_clientSubspaceForDOMException = std::forward<decltype(space)>(space); },
        [](auto& spaces) { return spaces.m_subspaceForDOMException.get(); },
        [](auto& spaces, auto&& space) { spaces.m_subspaceForDOMException = std::forward<decltype(space)>(space); });
}

void JSDOMException::analyzeHeap(JSCell* cell, HeapAnalyzer& analyzer)
{
    auto* thisObject = jsCast<JSDOMException*>(cell);
    analyzer.setWrappedObjectForCell(cell, &thisObject->wrapped());
    // if (thisObject->scriptExecutionContext())
    //     analyzer.setLabelForCell(cell, makeString("url "_s, thisObject->scriptExecutionContext()->url().string()));
    Base::analyzeHeap(cell, analyzer);
}

bool JSDOMExceptionOwner::isReachableFromOpaqueRoots(JSC::Handle<JSC::Unknown> handle, void*, AbstractSlotVisitor& visitor, ASCIILiteral* reason)
{
    UNUSED_PARAM(handle);
    UNUSED_PARAM(visitor);
    UNUSED_PARAM(reason);
    return false;
}

void JSDOMExceptionOwner::finalize(JSC::Handle<JSC::Unknown> handle, void* context)
{
    auto* jsDOMException = static_cast<JSDOMException*>(handle.slot()->asCell());
    auto& world = *static_cast<DOMWrapperWorld*>(context);
    uncacheWrapper(world, &jsDOMException->wrapped(), jsDOMException);
}

// #if ENABLE(BINDING_INTEGRITY)
// #if PLATFORM(WIN)
// #pragma warning(disable : 4483)
// extern "C" {
// extern void (*const __identifier("??_7DOMException@WebCore@@6B@")[])();
// }
// #else
// extern "C" {
// extern void* _ZTVN7WebCore12DOMExceptionE[];
// }
// #endif
// #endif

JSC::JSValue toJSNewlyCreated(JSC::JSGlobalObject*, JSDOMGlobalObject* globalObject, Ref<DOMException>&& impl)
{

    // if constexpr (std::is_polymorphic_v<DOMException>) {
    // #if ENABLE(BINDING_INTEGRITY)
    //         // const void* actualVTablePointer = getVTablePointer(impl.ptr());
    // #if PLATFORM(WIN)
    //         void* expectedVTablePointer = __identifier("??_7DOMException@WebCore@@6B@");
    // #else
    //         // void* expectedVTablePointer = &_ZTVN7WebCore12DOMExceptionE[2];
    // #endif

    //         // If you hit this assertion you either have a use after free bug, or
    //         // DOMException has subclasses. If DOMException has subclasses that get passed
    //         // to toJS() we currently require DOMException you to opt out of binding hardening
    //         // by adding the SkipVTableValidation attribute to the interface IDL definition
    //         // RELEASE_ASSERT(actualVTablePointer == expectedVTablePointer);
    // #endif
    // }
    return createWrapper<DOMException>(globalObject, WTFMove(impl));
}

JSC::JSValue toJS(JSC::JSGlobalObject* lexicalGlobalObject, JSDOMGlobalObject* globalObject, DOMException& impl)
{
    return wrap(lexicalGlobalObject, globalObject, impl);
}

DOMException* JSDOMException::toWrapped(JSC::VM& vm, JSC::JSValue value)
{
    if (auto* wrapper = jsDynamicCast<JSDOMException*>(value))
        return &wrapper->wrapped();
    return nullptr;
}

inline JSC::WeakHandleOwner* wrapperOwner(DOMWrapperWorld&, DOMException*)
{
    static NeverDestroyed<JSDOMExceptionOwner> owner;
    return &owner.get();
}

}
