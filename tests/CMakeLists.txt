if (WIN32)
	set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif (WIN32)
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        main
)
FetchContent_MakeAvailable(googletest)

add_subdirectory(src)

function(MakeTest NAME)
  add_executable(${NAME} ${NAME}.cpp)

  target_link_libraries(${NAME} PUBLIC
    TestUtils
  )

  install(TARGETS ${NAME})
endfunction()

MakeTest(Test01-GradientDescend)
MakeTest(Test02-GradientDescendConjugate)
MakeTest(Test03-QuasiNewton)
