###############################################################################
# Bazel now uses Bzlmod by default to manage external dependencies.
# Please consider migrating your external dependencies from WORKSPACE to MODULE.bazel.
#
# For more details, please check https://github.com/bazelbuild/bazel/issues/18958
###############################################################################

# Hedron's Compile Commands Extractor for Bazel
# https://github.com/hedronvision/bazel-compile-commands-extractor
bazel_dep(
    name = "hedron_compile_commands",
    dev_dependency = True,
)

git_override(
    module_name = "hedron_compile_commands",
    commit = "a14ad3a64e7bf398ab48105aaa0348e032ac87f8",
    remote = "https://github.com/hedronvision/bazel-compile-commands-extractor.git",
    # Replace the commit hash (above) with the latest (https://github.com/hedronvision/bazel-compile-commands-extractor/commits/main).
    # Even better, set up Renovate and let it do the work for you (see "Suggestion: Updates" in the README).
)

bazel_dep(
    name = "euler-util",
    dev_dependency = True,
)

git_override(
    module_name = "euler-util",
    commit = "23a2585bfb427b4cc398448dfa6387ebe9570df3",
    remote = "https://github.com/ClaytonKnittel/euler-util.git",
    # Replace the commit hash (above) with the latest (https://github.com/hedronvision/bazel-compile-commands-extractor/commits/main).
    # Even better, set up Renovate and let it do the work for you (see "Suggestion: Updates" in the README).
)

bazel_dep(
    name = "buildifier_prebuilt",
    version = "6.4.0",
    dev_dependency = True,
)

bazel_dep(
    name = "abseil-cpp",
    version = "20240116.2",
)

bazel_dep(
    name = "googletest",
    version = "1.14.0.bcr.1",
)
