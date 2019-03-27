/*
 
 chat/platform/java/test.cpp
 
 */

#include <utility>
#include <iostream>
#include <scapix/java_api/java/lang/RuntimeException.h>
#include <scapix/java_api/java/lang/Class.h>
#include <scapix/java_api/java/lang/String.h>
#include <scapix/java_api/java/util/HashSet.h>
#include <scapix/java_api/java/io/File.h>
#include <scapix/java_api/java/io/FileReader.h>
#include <scapix/link/java/ref.h>
#include <scapix/link/java/array.h>
#include <scapix/link/java/vm_exception.h>
#include <scapix/meta/string.h>

using namespace scapix::link::java;
using namespace scapix::java_api;

void test_exception()
{
    try
    {
        auto file1 = java::io::File::new_object(string::new_("//file.txt"));
        auto reader = java::io::FileReader::new_object(file1);
//      auto file2 = java::io::File::new_object(ref<java::lang::String>(nullptr));
    }
    catch (const vm_exception& e)
    {
        std::cout << e.class_name() << "\n";

        if (e == "java.io.FileNotFoundException")
        {
            std::cout << "FileNotFoundException\n";
        }
        else if (e == "java.lang.NullPointerException")
        {
            std::cout << "NullPointerException\n";
        }
    }
}

void test()
{
	local_ref<java::lang::RuntimeException> r1;
	local_ref<SCAPIX_META_STRING("java/lang/RuntimeException")> r2;

	r2 = std::move(r1);
	r1 = std::move(r2);
}

void test2()
{
    local_ref<java::lang::Object> r1;
    local_ref<java::lang::String> r2;

    r1 = r2;

    r2 = static_pointer_cast<java::lang::String>(r1);
    r2 = dynamic_pointer_cast<java::lang::String>(r1);

    r2 = static_pointer_cast<java::lang::String>(std::move(r1));
    r2 = dynamic_pointer_cast<java::lang::String>(std::move(r1));

    if (r1 == r2)
    {
    }

    if (r1 != r2)
    {
    }
}

void test_string()
{
    auto s = java::lang::String::new_object();
    
    auto b = s->getBytes();
    b->elements()[0] = 5;

    s->length();
    s->charAt(0);
}

void test_primitive_array()
{
    auto a = array<jint>::new_(10);

    auto e = a->elements();

    e[0] = 1;
    e[1] = e[2];
}

void test_object_array()
{
    auto s = java::lang::String::new_object();

    auto a = array<java::lang::String>::new_(10);

    a[0] = a[1];
    a[2] = s;
}

void test_object_array2()
{
    auto a = array<SCAPIX_META_STRING("java/lang/String")>::new_(10);

    ref<array<SCAPIX_META_STRING("java/lang/String")>> b = a;
    ref<SCAPIX_META_STRING("java/lang/String")[]> c = a;
    ref<SCAPIX_META_STRING("[java/lang/String")> d = a;
}

void test_ambiguity()
{
    auto s = java::lang::String::new_object();
//    s->getClass(); // Non-static member 'getClass' found in multiple base-class subobjects of type 'scapix::java_api::java::lang::Object'
//    s->java::lang::Object::getClass(); // Ambiguous conversion from derived class 'scapix::java_api::java::lang::String' to base class 'scapix::java_api::java::lang::Object'
    s->base_class<java::lang::Object>::getClass();
    ref<java::lang::Object> s1 = s;

    auto r = java::lang::RuntimeException::new_object();
    r->base_class<java::lang::Object>::getClass();
    ref<java::lang::Object> r1 = r;

    auto h = java::util::HashSet::new_object();
//    h->toArray(); // Member 'toArray' found in multiple base classes of different types
//    h->java::util::Collection::toArray(); // Ambiguous conversion from derived class 'scapix::java_api::java::util::HashSet' to base class 'scapix::java_api::java::util::Collection'
    h->base_class<java::util::Collection>::toArray();
    ref<java::util::Collection> h1 = h;
}

void test_call()
{
    // canonical form

    ref<SCAPIX_META_STRING("java/lang/Object")> r1; // same as: ref<>
    ref<java::lang::RuntimeException> r2;

	ref<SCAPIX_META_STRING("java/lang/String")[]> r3; // same as: ref<SCAPIX_META_STRING("[Ljava/lang/String;")>
    ref<java::lang::RuntimeException[]> r4;

    // static access
    
    ref<SCAPIX_META_STRING("java/lang/Object")>::element_type::call_static_method<SCAPIX_META_STRING("method"), void()>();
//	ref<java::lang::RuntimeException>::element_type::getClass(); // same as: java::lang::RuntimeException::getClass()
    ref<java::lang::RuntimeException[]>::element_type::call_static_method<SCAPIX_META_STRING("method"), void()>();
    
    // examples

    ref<SCAPIX_META_STRING("java/lang/String")> r10;
    ref<SCAPIX_META_STRING("[java/lang/String")> r11;
    ref<SCAPIX_META_STRING("[I")> r12;

//  r10->length(); // jstring specific JNI API
//  r11[0] = r10;  // jobjectArray specific JNI API
//  r12[0] = 5;    // jintArray specific JNI API

    // shortcuts
    // static access

//  java::lang::RuntimeException::getClass();
//  array<java::lang::RuntimeException>::getClass();

    // array
    
    ref<jint[]> r20;

    array<jint>::call_static_method<SCAPIX_META_STRING("method"), void()>();
    
    // object array
    
    ref<object<>[]> r21;
//  ref<array<>> r22; // same as: ref<object<>[]> or base array?
//  r3[0] = r2;

	ref<> r23 = array<object<>>::new_(10);
}
