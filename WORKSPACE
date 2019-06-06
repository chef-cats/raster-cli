load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive") 

http_archive(
    name = "com_github_nelhage_rules_boost",
    strip_prefix = "rules_boost-master",
    urls = ["https://github.com/nelhage/rules_boost/archive/master.zip"],
)

load("@com_github_nelhage_rules_boost//:boost/boost.bzl", "boost_deps")
boost_deps()