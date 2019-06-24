load ("@bazel_tools//tools/build_defs/repo:git.bzl",
      "git_repository", "new_git_repository")

# Bazel Skylib: Required for some zlib dependencies.
git_repository (
    name = "bazel_skylib",
    remote = "https://github.com/bazelbuild/bazel-skylib.git",
    tag = "0.8.0",
)

# Google Benchmark Library
git_repository (
    name = "com_github_google_benchmark",
    remote = "https://github.com/google/benchmark",
    tag = "v1.4.1",
)

bind (
    name = "gbench_main",
    actual = "@com_github_google_benchmark//:benchmark_main",
)

# Google Command Line Flags Library
git_repository (
    name = "com_github_gflags_gflags",
    remote = "https://github.com/gflags/gflags",
    tag = "v2.2.2",
)

bind (
    name = "gflags",
    actual = "@com_github_gflags_gflags//:gflags",
)   

# Google Logging Library
git_repository (
    name = "com_github_google_glog",
    remote = "https://github.com/google/glog",
    commit = "41f4bf9cbc3e8995d628b459f6a239df43c2b84a",
)

bind (
    name = "glog",
    actual = "@com_github_google_glog//:glog",
)

# Google Test Library
git_repository (
    name = "com_google_googletest",
    remote = "https://github.com/google/googletest",
    tag = "release-1.8.1",
)

bind (
    name = "gtest",
    actual = "@com_google_googletest//:gtest",
)

bind (
    name = "gtest_main",
    actual = "@com_google_googletest//:gtest_main",
)

