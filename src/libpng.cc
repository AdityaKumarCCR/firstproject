#include <node.h>
#include <v8.h>
#include <png.h>

using namespace v8;

Handle<Value> Version(const Arguments& args) {

  HandleScope scope;
  return scope.Close(String::New(PNG_LIBPNG_VER_STRING));
}

Handle<Value> Test(const Arguments& args) {

  HandleScope scope;
  return scope.Close(String::New(ZLIB_VERSION));
}

Handle<Value> png_create_read_struct(const Arguments& args) {

  HandleScope scope;
  return scope.Close(String::New(ZLIB_VERSION));
}

void init(Handle<Object> target) {
  NODE_SET_METHOD(target, "libpngVer", Version);
  NODE_SET_METHOD(target, "zlibVer", Test);
  NODE_SET_METHOD(target, "png_create_read_struct", Test);
}

NODE_MODULE(hello, init)
