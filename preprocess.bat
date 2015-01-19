@echo off
ruby -r erb -e 'puts ERB.new(ARGF.read).result' ".\picojson_helper.hpp.erb" ^
  | clang-format -style LLVM ^
  > ".\picojson_helper.hpp"
