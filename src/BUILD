cc_binary(
    name = "main",
    srcs = ["main.cc"],
)

cc_binary(
    name = "pattern_gen",
    srcs = ["pattern_gen.cc"],
    hdrs = ["pattern_gen.h"],
    deps = [
        ":pattern",
        ":stitch",
    ],
)

cc_binary(
    name = "pattern",
    srcs = ["pattern.cc"],
    hdrs = ["pattern.h"],
    deps = [
        ":stitch",
    ],
)

cc_binary(
    name = "stitch",
    srcs = ["stitch.cc"],
    hdrs = ["stitch.h"],
    deps = [
        ":pattern",
    ],
)
