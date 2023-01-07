#====================================================================================================
# For the tests add '-mac' to the end to compile for mac
# 	For example 'make sfml'     becomes 'make sfml-mac'
# 	And         'make sfml-run' becomes 'make sfml-run-mac'
# 
# Here are the main make commands
# 	Use 'make' to compile the project
# 	Use 'make run' to run the compiled project
# 
# 	Use 'make mac' to compile the project for mac
# 	Use 'make mac-run' to run the compiled project for mac
#
# Here are the current basic test commands (see definitions for more details)
# 	'make sfml' to check if SFML works
# 	'make Tmovement' to run a basic test for movement
# 	'make Tcollision' to run a basic test for collision
# 	'make Tframerate' to run a basic test for setting the framerate of a window
# 	'make Tsolver1' to run a basic test for solving collisions between rectangles
#
# Here are the current main functionality tests
#	'make entity1' to run the test for entities (uses the game manager to hold and update them)
#	'make hitbox1' to run the test for collision between rectangle hitboxes
#	'make hitbox2' to run the test for collision between entities handled from within the game manager
#	'make projectile1' to run the test for projectiles handled from within the game manager
#	'make scoreboard1' to run the test for storing, saving and loading scores
#	'make mainmenu1' to run the test for the main menu
#
#====================================================================================================

# The main make command for the project, use 'make' to compile and 'make run' to run the executable
all: main-compile main-link

main-compile:
	g++ -Isrc/include -c GameLibrary/ScoreBoard.cpp -o "object files/ScoreBoard.o"
	g++ -Isrc/include -c GameLibrary/TextMenu.cpp -o "object files/TextMenu.o"
	g++ -Isrc/include -c GameLibrary/Hitbox.cpp -o "object files/Hitbox.o"
	g++ -Isrc/include -c GameLibrary/Entity.cpp -o "object files/Entity.o"
	g++ -Isrc/include -c GameLibrary/BasicEnemy.cpp -o "object files/BasicEnemy.o"
	g++ -Isrc/include -c GameLibrary/FastEnemy.cpp -o "object files/FastEnemy.o"
	g++ -Isrc/include -c GameLibrary/BigEnemy.cpp -o "object files/BigEnemy.o"
	g++ -Isrc/include -c GameLibrary/Player.cpp -o "object files/Player.o"
	g++ -Isrc/include -c GameLibrary/Projectile.cpp -o "object files/Projectile.o"
	g++ -Isrc/include -c GameLibrary/PlayerProjectile.cpp -o "object files/PlayerProjectile.o"
	g++ -Isrc/include -c GameLibrary/GameManager.cpp -o "object files/GameManager.o"
	g++ -Isrc/include -c GameLoop.cpp -o "object files/GameLoop.o"
	g++ -Isrc/include -c main.cpp -o "object files/main.o"

main-link:
	g++ \
	"object files/ScoreBoard.o" \
	"object files/TextMenu.o" \
	"object files/Hitbox.o" \
	"object files/Entity.o" \
	"object files/BasicEnemy.o" \
	"object files/FastEnemy.o" \
	"object files/BigEnemy.o" \
	"object files/Player.o" \
	"object files/Projectile.o" \
	"object files/PlayerProjectile.o" \
	"object files/GameManager.o" \
	"object files/GameLoop.o" \
	"object files/main.o" \
	-o "executables/main.exe" \
	-Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system

run:
	./"executables/main.exe"

mac:
	g++ \
	GameLibrary/ScoreBoard.cpp \
	GameLibrary/TextMenu.cpp \
	GameLibrary/Hitbox.cpp \
	GameLibrary/Entity.cpp \
	GameLibrary/Projectile.cpp \
	GameLibrary/GameManager.cpp \
	main.cpp \
	-o "executables/main-mac" \
	-lsfml-graphics -lsfml-window -lsfml-system


mac-run:
	./"executables/main-mac"


# A test for the behaviour of entities
entity1: entity1-compile entity1-link

entity1-compile:
	g++ -Isrc/include -c GameLibrary/Hitbox.cpp -o "object files/Hitbox.o"
	g++ -Isrc/include -c GameLibrary/Entity.cpp -o "object files/Entity.o"
	g++ -Isrc/include -c GameLibrary/Projectile.cpp -o "object files/Projectile.o"
	g++ -Isrc/include -c GameLibrary/GameManager.cpp -o "object files/GameManager.o"
	g++ -Isrc/include -c entity1-test.cpp -o "object files/entity1-test.o"

entity1-link:
	g++ \
	"object files/Hitbox.o" \
	"object files/Entity.o" \
	"object files/Projectile.o" \
	"object files/GameManager.o" \
	"object files/entity1-test.o" \
	-o "executables/entity1-test.exe" \
	-Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system

entity1-run:
	./"executables/entity1-test.exe"

entity1-mac:
	g++ \
	GameLibrary/Hitbox.cpp \
	GameLibrary/Entity.cpp \
	GameLibrary/GameManager.cpp \
	entity1-test.cpp \
	-o "executables/entity1-test-mac" \
	-lsfml-graphics -lsfml-window -lsfml-system

entity1-mac-run:
	./"executables/entity1-test-mac"


# A test for the hitboxes of entities
hitbox1: hitbox1-compile hitbox1-link

hitbox1-compile:
	g++ -Isrc/include -c GameLibrary/Hitbox.cpp -o "object files/Hitbox.o"
	g++ -Isrc/include -c GameLibrary/Entity.cpp -o "object files/Entity.o"
	g++ -Isrc/include -c GameLibrary/Projectile.cpp -o "object files/Projectile.o"
	g++ -Isrc/include -c GameLibrary/GameManager.cpp -o "object files/GameManager.o"
	g++ -Isrc/include -c hitbox1-test.cpp -o "object files/hitbox1-test.o"

hitbox1-link:
	g++ \
	"object files/Hitbox.o" \
	"object files/Entity.o" \
	"object files/Projectile.o" \
	"object files/GameManager.o" \
	"object files/hitbox1-test.o" \
	-o "executables/hitbox1-test.exe" \
	-Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system

hitbox1-run:
	./"executables/hitbox1-test.exe"

hitbox1-mac:
	g++ \
	GameLibrary/Hitbox.cpp \
	GameLibrary/Entity.cpp \
	GameLibrary/Projectile.cpp \
	GameLibrary/GameManager.cpp \
	hitbox1-test.cpp \
	-o "executables/hitbox1-test-mac" \
	-lsfml-graphics -lsfml-window -lsfml-system

hitbox1-mac-run:
	./"executables/hitbox1-test-mac"


# A more complex test for the hitboxes of entities
hitbox2: hitbox2-compile hitbox2-link

hitbox2-compile:
	g++ -Isrc/include -c GameLibrary/Hitbox.cpp -o "object files/Hitbox.o"
	g++ -Isrc/include -c GameLibrary/Entity.cpp -o "object files/Entity.o"
	g++ -Isrc/include -c GameLibrary/Projectile.cpp -o "object files/Projectile.o"
	g++ -Isrc/include -c GameLibrary/GameManager.cpp -o "object files/GameManager.o"
	g++ -Isrc/include -c hitbox2-test.cpp -o "object files/hitbox2-test.o"

hitbox2-link:
	g++ \
	"object files/Hitbox.o" \
	"object files/Entity.o" \
	"object files/Projectile.o" \
	"object files/GameManager.o" \
	"object files/hitbox2-test.o" \
	-o "executables/hitbox2-test.exe" \
	-Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system

hitbox2-run:
	./"executables/hitbox2-test.exe"

hitbox2-mac:
	g++ \
	GameLibrary/Hitbox.cpp \
	GameLibrary/Entity.cpp \
	GameLibrary/Projectile.cpp \
	GameLibrary/GameManager.cpp \
	hitbox2-test.cpp \
	-o "executables/hitbox2-test-mac" \
	-lsfml-graphics -lsfml-window -lsfml-system

hitbox2-mac-run:
	./"executables/hitbox2-test-mac"


# A  test for projectiles
projectile1: projectile1-compile projectile1-link

projectile1-compile:
	g++ -Isrc/include -c GameLibrary/Hitbox.cpp -o "object files/Hitbox.o"
	g++ -Isrc/include -c GameLibrary/Entity.cpp -o "object files/Entity.o"
	g++ -Isrc/include -c GameLibrary/Projectile.cpp -o "object files/Projectile.o"
	g++ -Isrc/include -c GameLibrary/GameManager.cpp -o "object files/GameManager.o"
	g++ -Isrc/include -c projectile1-test.cpp -o "object files/projectile1-test.o"

projectile1-link:
	g++ \
	"object files/Hitbox.o" \
	"object files/Entity.o" \
	"object files/Projectile.o" \
	"object files/GameManager.o" \
	"object files/projectile1-test.o" \
	-o "executables/projectile1-test.exe" \
	-Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system

projectile1-run:
	./"executables/projectile1-test.exe"

projectile1-mac:
	g++ \
	GameLibrary/Hitbox.cpp \
	GameLibrary/Entity.cpp \
	GameLibrary/Projectile.cpp \
	GameLibrary/GameManager.cpp \
	projectile1-test.cpp \
	-o "executables/projectile1-test-mac" \
	-lsfml-graphics -lsfml-window -lsfml-system

projectile1-mac-run:
	./"executables/projectile1-test-mac"


# A test for the scoreboard
scoreboard1:
	g++ GameLibrary/ScoreBoard.cpp scoreboard1-test.cpp -o executables/scoreboard1-text.exe

scoreboard1-run:
	./executables/scoreboard1-text.exe

scoreboard1-mac:
	g++ GameLibrary/ScoreBoard.cpp scoreboard1-test.cpp -o "executables/scoreboard1-test-mac"

scoreboard1-mac-run:
	./"executables/scoreboard1-test-mac"


# A test for the scoreboard
mainmenu1:
	g++ GameLibrary/TextMenu.cpp mainmenu1-test.cpp -o executables/mainmenu1-text.exe

mainmenu1-run:
	./executables/mainmenu1-text.exe

mainmenu1-mac:
	g++ GameLibrary/TextMenu.cpp mainmenu1-test.cpp -o "executables/mainmenu1-test-mac"

mainmenu1-mac-run:
	./"executables/mainmenu1-test-mac"


# Simple main file for testing if sfml works
sfml: compile-sfml link-sfml

compile-sfml:
	g++ -Isrc/include -c "tests/sfml-works.cpp" -o "object files/sfml-works.o"

link-sfml:
	g++ "object files/sfml-works.o" -o "executables/sfml-works.exe" -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system

sfml-run:
	./"executables/sfml-works.exe"

sfml-mac:
	g++ "tests/sfml-works.cpp" -o "executables/sfml-works-mac" -lsfml-graphics -lsfml-window -lsfml-system

sfml-run-mac:
	./"executables/sfml-works-mac"


# A test for moving an object around the screen
# Use the arrow keys for movement
Tmovement: compile-Tmovement link-Tmovement

compile-Tmovement:
	g++ -Isrc/include -c "tests/Tmovement-test.cpp" -o "object files/Tmovement-test.o"

link-Tmovement:
	g++ "object files/Tmovement-test.o" -o "executables/Tmovement-test.exe" -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system

Tmovement-run:
	./"executables/Tmovement-test.exe"

Tmovement-mac:
	g++ "tests/Tmovement-test.cpp" -o "executables/Tmovement-test-mac" -lsfml-graphics -lsfml-window -lsfml-system

Tmovement-run-mac:
	./"executables/Tmovement-test-mac"


# A test for checking for collisions between shapes
# Use the arrow keys for movement
Tcollision: compile-Tcollision link-Tcollision

compile-Tcollision:
	g++ -Isrc/include -c "tests/Tcollision-test.cpp" -o "object files/Tcollision-test.o"

link-Tcollision:
	g++ "object files/Tcollision-test.o" -o "executables/Tcollision-test.exe" -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system

Tcollision-run:
	./"executables/Tcollision-test.exe"

Tcollision-mac:
	g++ "tests/Tcollision-test.cpp" -o "executables/Tcollision-test-mac" -lsfml-graphics -lsfml-window -lsfml-system

Tcollision-run-mac:
	./"executables/Tcollision-test-mac"


# A test for setting the frame rate of a window to better control time
# Use the arrow keys for movement
# Use 1-9 for setting different framerates, goes from 10 to 90
Tframerate: compile-Tframerate link-Tframerate

compile-Tframerate:
	g++ -Isrc/include -c "tests/Tframerate-test.cpp" -o "object files/Tframerate-test.o"

link-Tframerate:
	g++ "object files/Tframerate-test.o" -o "executables/Tframerate-test.exe" -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system

Tframerate-run:
	./"executables/Tframerate-test.exe"

Tframerate-mac:
	g++ "tests/Tframerate-test.cpp" -o "executables/Tframerate-test-mac" -lsfml-graphics -lsfml-window -lsfml-system

Tframerate-run-mac:
	./"executables/Tframerate-test-mac"


# A test for solving collisions between rectangles
Tsolver1: compile-Tsolver1 link-Tsolver1

compile-Tsolver1:
	g++ -Isrc/include -c "tests/Tsolver1-test.cpp" -o "object files/Tsolver1-test.o"
	
link-Tsolver1:
	g++ "object files/Tsolver1-test.o" -o "executables/Tsolver1-test.exe" -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system

Tsolver1-run:
	./"executables/Tsolver1-test.exe"

Tsolver1-mac:
	g++ "tests/Tsolver1-test.cpp" -o "executables/Tsolver1-test-mac" -lsfml-graphics -lsfml-window -lsfml-system

Tsolver1-run-mac:
	./"executables/Tsolver1-test-mac"

