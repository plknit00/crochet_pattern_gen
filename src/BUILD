cc_binary(
    name = "main",
    srcs = ["main.cc"],
    deps = [
        ":pattern_gen",
    ],
)

cc_library(
    name = "pattern_gen",
    srcs = ["pattern_gen.cc"],
    hdrs = ["pattern_gen.h"],
    deps = [
        ":pattern",
        ":row",
        ":stitch",
    ],
)

cc_library(
    name = "pattern",
    srcs = ["pattern.cc"],
    hdrs = ["pattern.h"],
    deps = [
        ":row",
        ":stitch",
    ],
)

cc_test(
    name = "pattern_gen_test",
    srcs = ["pattern_gen_test.cc"],
    deps = [
        ":pattern_gen",
        "@googletest//:gtest",
        "@googletest//:gtest_main",
    ],
)

cc_library(
    name = "row",
    srcs = ["row.cc"],
    hdrs = ["row.h"],
    deps = [
        ":stitch",
    ],
)

cc_library(
    name = "stitch",
    srcs = ["stitch.cc"],
    hdrs = ["stitch.h"],
)
