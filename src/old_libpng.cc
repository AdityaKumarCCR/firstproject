//#include <png.h>

#include <v8.h>
#include <node.h>

using namespace v8;

Handle<Value> version(const Arguments& args) {
  HandleScope scope; 
  return (scope.Close(String::New("Adi")));
  //PNG_LIBPNG_VER_STRING)));
}


void init(Handle<Object> target) {
    NODE_SET_METHOD(target, "ver", version);
}

