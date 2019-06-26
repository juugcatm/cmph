cc_binary (
    name = "cxxmph",
    srcs = [
        "cxxmph.cc",
    ],
    deps = [
        ":libcxxmph",
    ]
)

cc_library (
    name = "libcxxmph",
    srcs = [
        "mph_bits.cc",
        "mph_index.cc",
        "string_util.cc",
        "trigraph.cc",
    ],
    hdrs = [
        "hollow_iterator.h",
        "mph_bits.h",
        "mph_index.h",
        "mph_map.h",
        "seeded_hash.h",
        "string_util.h",        
        "trigraph.h",
    ],
    includes = ["."],
    deps = [
        ":murmur_hash_3",
        ":stringpiece",
    ],
)

cc_library (
    name = "murmur_hash_3",
    srcs = [
        "MurmurHash3.cpp",
    ],
    hdrs = [
        "MurmurHash3.h",
    ],
)

cc_library (
    name = "stringpiece",
    hdrs = [
        "stringpiece.h",
    ],
)

cc_library (
    name = "test_utils",
    testonly = True,
    srcs = [
        "map_tester.cc",
    ],
    hdrs = [
        "map_tester.h",
    ],
    deps = [
        ":libcxxmph",
        "//external:gtest",
    ],
)

cc_test (
    name = "mph_index_test",
    srcs = [
        "mph_index_test.cc",
    ],
    deps = [
        ":libcxxmph",
    ],
)

cc_test (
    name = "mph_map_test",
    srcs = [
        "mph_map_test.cc",
    ],
    deps = [
        ":libcxxmph",
        ":test_utils",
        "//external:gtest_main",
    ],
)

cc_test (
    name = "hollow_iterator_test",
    srcs = [
        "hollow_iterator_test.cc",
    ],
    deps = [
        ":libcxxmph",
        "//external:gtest_main",
    ],
)

cc_test (
    name = "seeded_hash_test",
    srcs = [
        "seeded_hash_test.cc",
    ],
    deps = [
        ":libcxxmph",
        "//external:gtest_main",
    ],
)

cc_test (
    name = "trigraph_test",
    srcs = [
        "trigraph_test.cc",
    ],
    deps = [
        ":libcxxmph",
        "//external:gtest_main",
    ],
)
