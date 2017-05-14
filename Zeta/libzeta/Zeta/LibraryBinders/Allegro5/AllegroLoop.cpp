/*
 * AllegroLoop.cpp
 *
 *  Created on: 5 Σεπ 2014
 *      Author: klapeto
 */

/*	This file is Part of Zeta Engine
 *
 *	The MIT License
 *
 * Copyright (c) 2014 Ioannis G. Panagiotopoulos (AKA Klapeto)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
 * documentation files (the "Software"), to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software,
 * and to permit persons to whom the Software is furnished to do so, subject to the following conditions.
 *
 * The above copyright notice and this permission notice shall be included in all copies or substantial
 * portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
 * AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#include <allegro5/allegro.h>
#include <Zeta/Core/GeneralLoop.hpp>
#include <Zeta/LibraryBinders/Allegro5/AllegroEvent.hpp>
#include <Zeta/LibraryBinders/Allegro5/AllegroLoop.hpp>

namespace Zeta {

AllegroLoop::AllegroLoop(int targetFps) :
		LoopRunner(), targetFps(targetFps) {
	frame_timer = al_create_timer(1.0 / static_cast<double>(targetFps));
}

void AllegroLoop::start() {
	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();

	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_mouse_event_source());
	//al_register_event_source(event_queue,
	//		al_get_display_event_source(al_get_current_display()));
	al_register_event_source(event_queue,
			al_get_timer_event_source(frame_timer));

	bool redraw = true;

	al_start_timer(frame_timer);
	while (isLoopRunning()) {

		ALLEGRO_EVENT al_event;
		al_wait_for_event(event_queue, &al_event);

		AllegroEvent Z_event(al_event);
		handleEvents(Z_event);

		if (al_event.type == ALLEGRO_EVENT_TIMER) {
			update();
			redraw = true;
		}
		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;

			render();
		}
	}
	al_stop_timer(frame_timer);
	al_destroy_event_queue(event_queue);

}

void AllegroLoop::setTargetFps(int targetFps) {
	this->targetFps = targetFps;
	al_set_timer_speed(frame_timer, 1.0 / static_cast<double>(targetFps));
}

AllegroLoop::~AllegroLoop() {
	al_destroy_timer(frame_timer);
}

} /* namespace Zeta */
