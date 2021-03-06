function(LINK_EIGEN TARGET_NAME MODE)

SET(EIGEN_BUILD_DOC OFF CACHE BOOL "Avoid eigen doc" FORCE)

if(EIGEN_INSTALL_FOLDER)
	message(STATUS "using Eigen from local folder at ${EIGEN_INSTALL_FOLDER} for target ${TARGET_NAME}")

	target_include_directories(${TARGET_NAME} ${MODE} ${EIGEN_INSTALL_FOLDER})
else()
	if (TARGET Eigen3::Eigen)
	else()
		message(STATUS "fetching Eigen from git")

		include(FetchContent)
		FetchContent_Declare(
		  eigen
		  GIT_REPOSITORY https://gitlab.com/libeigen/eigen.git
		  GIT_TAG        b3bea43a2da484d420e20c615cb5c9e3c04024e5
		)
		FetchContent_MakeAvailable(eigen)
	endif()
	
	target_link_libraries(${TARGET_NAME} ${MODE} Eigen3::Eigen)
endif()

endfunction()

