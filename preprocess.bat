@echo off
ruby ".\picojson_helper.hpp.erb" ^
  | clang-format -style LLVM ^
  > ".\picojson_helper.hpp"
