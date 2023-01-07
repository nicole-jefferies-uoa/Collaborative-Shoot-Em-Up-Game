#ifndef OOP_GROUP_PROJECT_GAMELOOP_H
#define OOP_GROUP_PROJECT_GAMELOOP_H

#include "GameLibrary/GameLibrary.h"

class GameLoop {
public:
    GameLoop();

    // Runs the whole game loop
    void runGameLoop();

    // Resets all values
    void reset();

    // Frame counting
    int frame_counter;

    // Difficulty, increases spawn rate, increases every 7 seconds
    int difficulty;

    // Time in frames that the difficulty increases
    int difficulty_increase;

    // Spawn delay is the delay in frames that it takes for the enemies to spawn.
    // Spawn threshold is the shortest time in frames for the enemies to spawn.
    int basic_enemy_spawn_delay;
    int basic_enemy_max_spawn_threshold;

    int fast_enemy_spawn_delay;
    int fast_enemy_max_spawn_threshold;

    int big_enemy_spawn_delay;
    int big_enemy_max_spawn_threshold;

    // The frame the lose condition was reached
    int lose_frame;
};

#endif //OOP_GROUP_PROJECT_GAMELOOP_H
