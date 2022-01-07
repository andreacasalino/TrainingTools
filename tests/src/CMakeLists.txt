set(PROJECT_SHORTNAME TestUtils)

MakeLibrary(${PROJECT_SHORTNAME} header)

target_link_libraries(${PROJECT_SHORTNAME} PUBLIC
    gtest
    TrainingTools
)
