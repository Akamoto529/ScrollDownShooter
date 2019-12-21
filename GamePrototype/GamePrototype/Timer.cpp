#include "Timer.h"

Timer::Timer() {
	paused = false;
	runtime = sf::microseconds(0);
	clock.restart();
}

sf::Time Timer::getElapsedTime() {
	if (!paused) {
		return sf::microseconds(runtime.asMicroseconds() + clock.getElapsedTime().asMicroseconds());
	}
	return runtime;
}

void Timer::pause() {
	if (!paused) {
		runtime = sf::microseconds(runtime.asMicroseconds() + clock.getElapsedTime().asMicroseconds());
	}
	paused = true;
}

void Timer::reset() {
	clock.restart();
	runtime = sf::microseconds(0);
	paused = false;
}

void Timer::start() {
	if (paused) {
		clock.restart();
	}
	paused = false;
}