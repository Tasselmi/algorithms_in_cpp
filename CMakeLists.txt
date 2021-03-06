cmake_minimum_required(VERSION 3.15)
project(algorithms_in_cpp)

set(CMAKE_CXX_STANDARD 14)
include_directories(croaring)

message(STATUS "start running cmake...")

find_package(Boost 1.73.0 COMPONENTS system filesystem REQUIRED)

if(Boost_FOUND)
    message(STATUS "BOOST_ROOT: ${BOOST_ROOT}")
    message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
    message(STATUS "Boost_VERSION: ${Boost_VERSION}")

    include_directories(${Boost_INCLUDE_DIRS})
endif()

add_executable(BoostTest main.cpp)

if(Boost_FOUND)

    target_link_libraries(BoostTest ${Boost_LIBRARIES})

endif()

add_executable(algorithms_in_cpp main.cpp chapter10/Dictionary.h chapter01/permutations.cpp chapter01/factorial.cpp chapter01/fibonacci.cpp chapter01/gcd.cpp chapter01/subsets.cpp chapter01/accumulate.cpp exception/myExceptions.h chapter05/changeLength1D.h chapter05/ArrayList.h chapter05/LinearList.h chapter05/ArrayList.cpp chapter05/Iterator.h chapter05/VectorList.h chapter06/Chain.h chapter06/ExtendedLinearList.h chapter06/ExtendedChain.h chapter06/CircularListWithHeader.h chapter06/ChainNode.h chapter06/StudentRecord.h chapter08/Stack.h chapter08/DerivedArrayStack.h chapter08/ArrayStack.h chapter08/LinkedStack.h chapter08/printMatchedPairs.cpp chapter08/hanoiWithStacks.cpp chapter08/hanoiRecursive.cpp chapter08/railroadWithStacks.cpp chapter08/switchBox.cpp chapter08/equivalenceClasses.cpp chapter08/maze.cpp chapter09/Queue.h chapter09/ArrayQueue.h chapter09/LinkedQueue.h chapter10/PairNode.h chapter10/SortedChain.h chapter10/testDictionary.cpp chapter10/SkipNode.h chapter10/hash.h chapter10/HashTable.h chapter10/HashChains.h chapter10/compress.cpp chapter11/BinaryTreeNode.h chapter11/BinaryTree.h chapter11/LinkedBinaryTree.h chapter14/BSTree.h chapter14/IndexedBSTree.h chapter14/BinarySearchTree.h)