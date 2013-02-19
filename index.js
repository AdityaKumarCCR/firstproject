var addon = require('./build/Release/hello');
console.log(addon.libpngVer()); 
console.log(addon.zlibVer()); 
var p = addon.png_create_read_struct(addon.libpngVer(), "test");
if (!p) {
    console.log("This is the undefined");
}
console.log(p);
