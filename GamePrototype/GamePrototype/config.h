#pragma once

const int FPS = 60;
const int MSEC_PER_FRAME = 1000 / FPS;

const int WINDOW_X = 600;
const int WINDOW_Y = 700;

const int PLAYER_POS_X = WINDOW_X / 2;
const int PLAYER_POS_Y = WINDOW_Y - 100;

const float SQRT_2 = 1.41421356f;

const enum ObjectID {
	player_ID = 0, pl_ID,
	enemy_ID, enemy1_ID, enemy2_ID, enemy5_ID,
	proj_ID, bullet_ID, proj1_1ID, proj2_ID, proj3_ID,
	hp0_ID, hp1_ID,
	background_ID, polytech_ID, space_ID,
	ID_count
};

const enum Hostility { friendly, hostile, neutral };