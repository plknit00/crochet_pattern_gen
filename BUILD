load("@buildifier_prebuilt//:rules.bzl", "buildifier")
load("@hedron_compile_commands//:refresh_compile_commands.bzl", "refresh_compile_commands")

buildifier(
    name = "buildifier",
    exclude_patterns = [
        "./.git/*",
    ],
    lint_mode = "fix",
    mode = "fix",
)

refresh_compile_commands(
    name = "refresh_compile_commands",

    # Specify the targets of interest.
    # For example, specify a dict of targets and any flags required to build.
    targets = {
        # Turn off these flags to not confuse the compile commands generator when building abseil.
        "//...": "--process_headers_in_dependencies=false --features=-parse_headers",
    },
    # No need to add flags already in .bazelrc. They're automatically picked up.
    # If you don't need flags, a list of targets is also okay, as is a single target string.
    # Wildcard patterns, like //... for everything, *are* allowed here, just like a build.
    # As are additional targets (+) and subtractions (-), like in bazel query https://docs.bazel.build/versions/main/query.html#expressions
    # And if you're working on a header-only library, specify a test or binary target that compiles it.
)
