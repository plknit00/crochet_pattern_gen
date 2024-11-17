cc_binary(
    name = "main",
    srcs = ["main.cc"],
    deps = [
        ":pattern",
    ],
)

cc_library(
    name = "pattern_gen",
    srcs = ["pattern_gen.cc"],
    hdrs = ["pattern_gen.h"],
    deps = [
        ":pattern",
        ":stitch",
    ],
)

cc_library(
    name = "pattern",
    srcs = ["pattern.cc"],
    hdrs = ["pattern.h"],
    deps = [
        ":stitch",
    ],
)

cc_library(
    name = "stitch",
    srcs = ["stitch.cc"],
    hdrs = ["stitch.h"],
)
