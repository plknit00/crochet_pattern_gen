cc_library(
    name = "circle",
    srcs = ["circle.cc"],
    hdrs = ["circle.h"],
)

cc_library(
    name = "crochet_pattern",
    srcs = ["crochet_pattern.cc"],
    hdrs = ["crochet_pattern.h"],
    deps = [
        ":circle",
        ":rectangle",
        ":sphere",
    ],
)

cc_binary(
    name = "main",
    srcs = ["main.cc"],
    deps = [
        ":crochet_pattern",
    ],
)

cc_test(
    name = "pattern_gen_test",
    srcs = ["pattern_gen_test.cc"],
    deps = [
        ":circle",
        ":rectangle",
        ":sphere",
        "@googletest//:gtest",
        "@googletest//:gtest_main",
    ],
)

cc_library(
    name = "rectangle",
    srcs = ["rectangle.cc"],
    hdrs = ["rectangle.h"],
)

cc_library(
    name = "sphere",
    srcs = ["sphere.cc"],
    hdrs = ["sphere.h"],
)
