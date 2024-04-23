CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_STANDARD 11)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(test
        unit_test.cpp
)

ADD_EXECUTABLE(ascend
	ashenProject.cpp
	slowPrints.cpp
	player.cpp
	Enemy.cpp
	bag.cpp
	weapon.cpp
	armor.cpp
	DeathPrint.cpp
	character.cpp
	combat.cpp
	generatePlayer.cpp
	generateRooms.cpp
	potion.cpp
	room.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
