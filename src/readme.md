1. Make sure the exported function is wrapped in an `extern "C" { ... }` block (when compiling with em++). Otherwise, it is
interpreted as C++ code where names are "mangled" (prefixed/suffixed with padding characters by the compiler):
``` 
extern "C" {
      float __attribute__((used)) compute_emd(...)
}
```
Prefix the function name with an `__attribute__((used))` to avoid it from being eliminated by LLVM.

3. Compile like so:
```
em++ emd.c -O2 -s EXPORTED_FUNCTIONS="['_compute_emd']" -o emd.js
```
Mind the underscore ("_") before the real function name.

4. Access the function from JavaScript like so:
```
var compute_emd = Module['_compute_emd'];
```
5. Make sure to transform C-string (`char*`) parameters from JavaScript strings like so::
```
var parameter = Module.intArrayFromString("my javascript string");
```


