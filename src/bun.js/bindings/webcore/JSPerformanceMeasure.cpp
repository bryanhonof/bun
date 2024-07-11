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

#include "config.h"
#include "JSPerformanceMeasure.h"

#include "ActiveDOMObject.h"
#include "ExtendedDOMClientIsoSubspaces.h"
#include "ExtendedDOMIsoSubspaces.h"
#include "JSDOMAttribute.h"
#include "JSDOMBinding.h"
#include "JSDOMConstructorNotConstructable.h"
#include "JSDOMConvertAny.h"
#include "JSDOMExceptionHandling.h"
#include "JSDOMGlobalObjectInlines.h"
#include "JSDOMWrapperCache.h"
#include "ScriptExecutionContext.h"
#include "WebCoreJSClientData.h"
#include <JavaScriptCore/HeapAnalyzer.h>
#include <JavaScriptCore/JSCInlines.h>
#include <JavaScriptCore/JSDestructibleObjectHeapCellType.h>
#include <JavaScriptCore/SlotVisitorMacros.h>
#include <JavaScriptCore/SubspaceInlines.h>
#include <wtf/GetPtr.h>
#include <wtf/PointerPreparations.h>
#include <wtf/URL.h>

namespace WebCore {
using namespace JSC;

// Attributes

static JSC_DECLARE_CUSTOM_GETTER(jsPerformanceMeasureConstructor);
static JSC_DECLARE_CUSTOM_GETTER(jsPerformanceMeasure_detail);

class JSPerformanceMeasurePrototype final : public JSC::JSNonFinalObject {
public:
    using Base = JSC::JSNonFinalObject;
    static JSPerformanceMeasurePrototype* create(JSC::VM& vm, JSDOMGlobalObject* globalObject, JSC::Structure* structure)
    {
        JSPerformanceMeasurePrototype* ptr = new (NotNull, JSC::allocateCell<JSPerformanceMeasurePrototype>(vm)) JSPerformanceMeasurePrototype(vm, globalObject, structure);
        ptr->finishCreation(vm);
        return ptr;
    }

    DECLARE_INFO;
    template<typename CellType, JSC::SubspaceAccess>
    static JSC::GCClient::IsoSubspace* subspaceFor(JSC::VM& vm)
    {
        STATIC_ASSERT_ISO_SUBSPACE_SHARABLE(JSPerformanceMeasurePrototype, Base);
        return &vm.plainObjectSpace();
    }
    static JSC::Structure* createStructure(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(vm, globalObject, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), info());
    }

private:
    JSPerformanceMeasurePrototype(JSC::VM& vm, JSC::JSGlobalObject*, JSC::Structure* structure)
        : JSC::JSNonFinalObject(vm, structure)
    {
    }

    void finishCreation(JSC::VM&);
};
STATIC_ASSERT_ISO_SUBSPACE_SHARABLE(JSPerformanceMeasurePrototype, JSPerformanceMeasurePrototype::Base);

using JSPerformanceMeasureDOMConstructor = JSDOMConstructorNotConstructable<JSPerformanceMeasure>;

template<> const ClassInfo JSPerformanceMeasureDOMConstructor::s_info = { "PerformanceMeasure"_s, &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSPerformanceMeasureDOMConstructor) };

template<> JSValue JSPerformanceMeasureDOMConstructor::prototypeForStructure(JSC::VM& vm, const JSDOMGlobalObject& globalObject)
{
    return JSPerformanceEntry::getConstructor(vm, &globalObject);
}

template<> void JSPerformanceMeasureDOMConstructor::initializeProperties(VM& vm, JSDOMGlobalObject& globalObject)
{
    putDirect(vm, vm.propertyNames->length, jsNumber(0), JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum);
    JSString* nameString = jsNontrivialString(vm, "PerformanceMeasure"_s);
    m_originalName.set(vm, this, nameString);
    putDirect(vm, vm.propertyNames->name, nameString, JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum);
    putDirect(vm, vm.propertyNames->prototype, JSPerformanceMeasure::prototype(vm, globalObject), JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum | JSC::PropertyAttribute::DontDelete);
}

/* Hash table for prototype */

static const HashTableValue JSPerformanceMeasurePrototypeTableValues[] = {
    { "constructor"_s, static_cast<unsigned>(PropertyAttribute::DontEnum), NoIntrinsic, { HashTableValue::GetterSetterType, jsPerformanceMeasureConstructor, 0 } },
    { "detail"_s, JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::CustomAccessor | JSC::PropertyAttribute::DOMAttribute, NoIntrinsic, { HashTableValue::GetterSetterType, jsPerformanceMeasure_detail, 0 } },
};

const ClassInfo JSPerformanceMeasurePrototype::s_info = { "PerformanceMeasure"_s, &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSPerformanceMeasurePrototype) };

void JSPerformanceMeasurePrototype::finishCreation(VM& vm)
{
    Base::finishCreation(vm);
    reifyStaticProperties(vm, JSPerformanceMeasure::info(), JSPerformanceMeasurePrototypeTableValues, *this);
    JSC_TO_STRING_TAG_WITHOUT_TRANSITION();
}

const ClassInfo JSPerformanceMeasure::s_info = { "PerformanceMeasure"_s, &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSPerformanceMeasure) };

JSPerformanceMeasure::JSPerformanceMeasure(Structure* structure, JSDOMGlobalObject& globalObject, Ref<PerformanceMeasure>&& impl)
    : JSPerformanceEntry(structure, globalObject, WTFMove(impl))
{
}

// static_assert(!std::is_base_of<ActiveDOMObject, PerformanceMeasure>::value, "Interface is not marked as [ActiveDOMObject] even though implementation class subclasses ActiveDOMObject.");

JSObject* JSPerformanceMeasure::createPrototype(VM& vm, JSDOMGlobalObject& globalObject)
{
    auto* structure = JSPerformanceMeasurePrototype::createStructure(vm, &globalObject, JSPerformanceEntry::prototype(vm, globalObject));
    structure->setMayBePrototype(true);
    return JSPerformanceMeasurePrototype::create(vm, &globalObject, structure);
}

JSObject* JSPerformanceMeasure::prototype(VM& vm, JSDOMGlobalObject& globalObject)
{
    return getDOMPrototype<JSPerformanceMeasure>(vm, globalObject);
}

JSValue JSPerformanceMeasure::getConstructor(VM& vm, const JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSPerformanceMeasureDOMConstructor, DOMConstructorID::PerformanceMeasure>(vm, *jsCast<const JSDOMGlobalObject*>(globalObject));
}

JSC_DEFINE_CUSTOM_GETTER(jsPerformanceMeasureConstructor, (JSGlobalObject * lexicalGlobalObject, EncodedJSValue thisValue, PropertyName))
{
    VM& vm = JSC::getVM(lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    auto* prototype = jsDynamicCast<JSPerformanceMeasurePrototype*>(JSValue::decode(thisValue));
    if (UNLIKELY(!prototype))
        return throwVMTypeError(lexicalGlobalObject, throwScope);
    return JSValue::encode(JSPerformanceMeasure::getConstructor(JSC::getVM(lexicalGlobalObject), prototype->globalObject()));
}

static inline JSValue jsPerformanceMeasure_detailGetter(JSGlobalObject& lexicalGlobalObject, JSPerformanceMeasure& thisObject)
{
    auto& vm = JSC::getVM(&lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    if (JSValue cachedValue = thisObject.m_detail.get())
        return cachedValue;
    auto& impl = thisObject.wrapped();
    JSValue result = toJS<IDLAny>(lexicalGlobalObject, throwScope, impl.detail(*jsCast<JSDOMGlobalObject*>(&lexicalGlobalObject)));
    RETURN_IF_EXCEPTION(throwScope, {});
    thisObject.m_detail.set(JSC::getVM(&lexicalGlobalObject), &thisObject, result);
    return result;
}

JSC_DEFINE_CUSTOM_GETTER(jsPerformanceMeasure_detail, (JSGlobalObject * lexicalGlobalObject, EncodedJSValue thisValue, PropertyName attributeName))
{
    return IDLAttribute<JSPerformanceMeasure>::get<jsPerformanceMeasure_detailGetter, CastedThisErrorBehavior::Assert>(*lexicalGlobalObject, thisValue, attributeName);
}

JSC::GCClient::IsoSubspace* JSPerformanceMeasure::subspaceForImpl(JSC::VM& vm)
{
    return WebCore::subspaceForImpl<JSPerformanceMeasure, UseCustomHeapCellType::No>(
        vm,
        [](auto& spaces) { return spaces.m_clientSubspaceForPerformanceMeasure.get(); },
        [](auto& spaces, auto&& space) { spaces.m_clientSubspaceForPerformanceMeasure = std::forward<decltype(space)>(space); },
        [](auto& spaces) { return spaces.m_subspaceForPerformanceMeasure.get(); },
        [](auto& spaces, auto&& space) { spaces.m_subspaceForPerformanceMeasure = std::forward<decltype(space)>(space); });
}

template<typename Visitor>
void JSPerformanceMeasure::visitChildrenImpl(JSCell* cell, Visitor& visitor)
{
    auto* thisObject = jsCast<JSPerformanceMeasure*>(cell);
    ASSERT_GC_OBJECT_INHERITS(thisObject, info());
    Base::visitChildren(thisObject, visitor);
    visitor.append(thisObject->m_detail);
}

DEFINE_VISIT_CHILDREN(JSPerformanceMeasure);

void JSPerformanceMeasure::analyzeHeap(JSCell* cell, HeapAnalyzer& analyzer)
{
    auto* thisObject = jsCast<JSPerformanceMeasure*>(cell);
    analyzer.setWrappedObjectForCell(cell, &thisObject->wrapped());
    if (thisObject->scriptExecutionContext())
        analyzer.setLabelForCell(cell, makeString("url "_s, thisObject->scriptExecutionContext()->url().string()));
    Base::analyzeHeap(cell, analyzer);
}

}
