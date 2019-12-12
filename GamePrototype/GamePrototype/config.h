#pragma once

const int FPS = 60;
const int MSEC_PER_FRAME = 1000 / FPS;

const int WINDOW_X = 800;
const int WINDOW_Y = 900;

const float SQRT_2 = 1.41421356f;

const enum ObjectID {
	player_ID = 0, pl_ID,
	enemy_ID, enemy1_ID, enemy2_ID, enemy5_ID,
	proj_ID, bullet_ID, proj1_1ID, proj2_ID, proj3_ID,
	hp0_ID, hp1_ID,
	background_ID,
	ID_count
};