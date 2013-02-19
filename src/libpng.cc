#include <node.h>
#include <v8.h>
#include <png.h>
#include <string>
#include <iostream>

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

  /*  if (args.Length()!= 2 || 
      !args[0]->IsString() ||
      !args[1]->IsUint32()) 
    {
      return ThrowException(Exception::Error(String::New("Invalid first argument for png_creat_read_struct")));
    }
  */
  // libpng version arg[0]
  std::string tempString(*v8::String::Utf8Value(args[0]));
  png_const_charp user_png_ver = tempString.c_str();


  ///* Allocate and initialize png_ptr struct for reading, and any other memory. */
  // extern PNG_EXPORT(png_structp,png_create_read_struct)
  // PNGARG((png_const_charp user_png_ver, png_voidp error_ptr,
  // png_error_ptr error_fn, png_error_ptr warn_fn)) PNG_ALLOCATED;


  //error_ptr arg[1]
  // png_voidp error_ptr = arg[1]->ToFunction();

  //error_fn agr[2]
  //  png_error_ptr error_fn = arg[2];

  //warn_fn arg[3]
  //  png_error_ptr warn_fn = arg[3];

  //  png_structp png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL,NULL);
  png_structp png_ptr = png_create_read_struct(user_png_ver, NULL, NULL,NULL);
  
  if (png_ptr == NULL) {
    return scope.Close(Undefined());
  }
  
  return scope.Close(True());
  
}

void init(Handle<Object> target) {

  NODE_SET_METHOD(target, "libpngVer", Version);
  NODE_SET_METHOD(target, "zlibVer", Test);
  NODE_SET_METHOD(target, "png_create_read_struct", png_create_read_struct);
}

NODE_MODULE(hello, init)
