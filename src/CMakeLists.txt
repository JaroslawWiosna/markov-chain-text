cmake_minimum_required (VERSION 2.6)

include_directories( 
  Random
  Node
  Chain
)
set(files
  Node/Node.cpp
  Chain/Chain.cpp
)

######

project (markov-chain-text)
add_executable(markov-chain-text main.cpp ${files} ${COMPILED_RESOURCES}) 
include_directories(${GTEST_INCLUDE_DIRS})
target_link_libraries(markov-chain-text pthread stdc++fs)

enable_testing()


