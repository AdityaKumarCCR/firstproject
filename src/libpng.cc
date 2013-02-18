#include <png.h>

#include <v8.h>
#include <node.h>

using namespace v8;

Handle<Value> version(const Arguments& args) {
  HandleScope scope; 
  string ver =  png_libpng_ver();
  return (scope.Close(String::New(ver));
}


void init(Handle<Object> target) {
   NODE_SET_METHOD(target, "ver",version)
}

