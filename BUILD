

cc_library (
    name = "libcmph",
    srcs = [f for f in glob(["src/*.c"]) if f != "src/main.c"],
    hdrs = glob(["src/*.h"]),
    copts = [
        "-Wall",
        "-Wno-unused-function",
        "-Wno-unused-but-set-variable",
        "-Wno-return-type",
        "-DNDEBUG",
        "-fomit-frame-pointer",
    ],
    includes = ["src/."],
    visibility = ["//visibility:public"],
)

cc_binary (
    name = "cmph",
    srcs = [
        "src/main.c",
    ],
    deps = [
        "//:libcmph",
    ],
    visibility = ["//visibility:public"],
)
