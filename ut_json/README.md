# utl_jsn

A lightweight, C++20 header-only JSON parsing and formatting library designed in the STB style. It features a safe extraction view, an ergonomic builder context, and native `std::format` integration.

> I am using exceptions instead of error values because it may get tedious handling so many errors since you'd need to do that a lot when dealing with json.

## Integration

`utl_jsn` is a single-header library. 

1. Drop `utl_jsn.hpp` into your project.
2. In **exactly one** `.cpp` file, define the implementation macro before including the header:

```cpp
// json_impl.cpp
#define UTL_JSN_IMPLEMENTATION
#include "utl_jsn.hpp"
```

3. In all other files where you need JSON functionality, just include the header normally:

```cpp
#include "utl_jsn.hpp"
```

## Parsing JSON

Use `utl::jsn::parse` to read a JSON string into a `utl::jsn::Json` object (which is a `std::variant<Object, Array>`).

```cpp
#include "utl_jsn.hpp"
#include <iostream>

int main() {
    std::string_view raw = R"({
        "name": "engine",
        "version": 1.5,
        "modules": ["render", "physics"]
    })";

    try {
        utl::jsn::Json document = utl::jsn::parse(raw);
        // ...
    } catch (const std::runtime_error& e) {
        std::cerr << "Parse error: " << e.what() << '\n';
    }
}

```

*Note: All numbers in JSON are parsed as `double`.*

## Reading Data (Safe Extraction)

Direct variant access can be verbose and dangerous. Wrap your parsed JSON in a `utl::jsn::View` for safe, chainable navigation. If a key or index does not exist, the view simply returns an invalid view rather than throwing.

```cpp
utl::jsn::View v = utl::jsn::view(document);

// Extract with a fallback value if the key is missing or the type is wrong
std::string name = v["name"].as_or<std::string>("unknown");
double version   = v["version"].as_or<double>(1.0);

// Chain accesses safely
std::string first_mod = v["modules"][0].as_or<std::string>("none");
std::string bad_mod   = v["modules"][99].as_or<std::string>("none"); // Safely returns "none"

// Strict access (throws if missing or type mismatch)
double strict_version = v["version"].get<double>();

```

## Building JSON

Use `utl::jsn::Context` to build JSON programmatically. The API utilizes a stack-based builder state, allowing you to fluently open and close objects (`obj_b`, `obj_e`) and arrays (`arr_b`, `arr_e`).

```cpp
utl::jsn::Context ctx;

ctx.obj_b()
    .obj_k("status").inject("running")
    .obj_k("uptime").inject(3600)
    .obj_k("workers").arr_b()
        .inject("thread_1")
        .inject("thread_2")
    .arr_e()
.obj_e();

utl::jsn::Json generated_json = ctx.get();

```

### Custom Type Serialization

You can extend `utl::jsn::Context` to support custom user-defined types by providing a `to_json` overload in the `utl::jsn` namespace:

```cpp
struct Server_config {
    std::string ip;
    int port;
};

namespace utl::jsn {
    void to_json(utl::jsn::Context &ctx, const Server_config &cfg) {
        ctx.obj_b()
            .obj_k("ip").inject(cfg.ip)
            .obj_k("port").inject(static_cast<double>(cfg.port))
        .obj_e();
    }
}

// Usage:
Server_config my_config{"192.168.1.1", 8080};
utl::jsn::Context ctx;
ctx.inject(my_config); // Automatically calls to_json

```

## Printing and Formatting

`utl_jsn` natively specializes `std::formatter` for C++20 standard formatting (`std::format`, and `std::print` in C++23).

```cpp
// Default formatting (4 spaces)
std::string out1 = std::format("{}", generated_json);

// Minified formatting (0 spaces, no newlines)
std::string out2 = std::format("{:0w}", generated_json);

// 2-space indentation
std::string out3 = std::format("{:2w}", generated_json);

// Format doubles with exactly 2 decimal places
std::string out4 = std::format("{:2f}", generated_json);

```

### Format Specifiers Summary

* `<n>w`: Indent size (e.g., `4w` for 4 spaces, `0w` for minified).
* `<n>f`: Format floats/doubles to `<n>` decimal places.
* `<n>g`: Format floats/doubles to `<n>` significant figures.
* `E`: Do not escape strings (raw string output).

Would you like me to add a section to the README explaining the error handling (specifically the `utl::jsn::errors` namespace) in more detail?
