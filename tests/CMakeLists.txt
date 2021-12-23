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

function(MakeTest NAME)
  add_executable(${NAME}  
  ${NAME}.cpp
  Utils.h)

  target_link_libraries(${NAME}
  PUBLIC
      gtest
      TrainingTools
  )

  install(TARGETS ${NAME})
endfunction()


MakeTest(Test01-GradientDescendFixed)
MakeTest(Test02-GradientDescend)
MakeTest(Test03-GradientDescendConjugate)
MakeTest(Test04-QuasiNewton)
