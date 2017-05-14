/*
 * AllegroSoundInstance.cpp
 *
 *  Created on: 1 Σεπ 2014
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

#include <allegro5/allegro_audio.h>
#include <Zeta/LibraryBinders/Allegro5/AllegroSoundInstance.hpp>

namespace Zeta {

AllegroSoundInstance::AllegroSoundInstance(ALLEGRO_SAMPLE_INSTANCE* instance) :
		SoundInstance(), instance(instance) {
	al_attach_sample_instance_to_mixer(instance, al_get_default_mixer());
}

AllegroSoundInstance::~AllegroSoundInstance() {
	if (instance)
		al_destroy_sample_instance(instance);
}

void AllegroSoundInstance::play() {
	if (instance)
		al_play_sample_instance(instance);
}

void AllegroSoundInstance::stop() {
	if (instance)
		al_stop_sample_instance(instance);
}

void AllegroSoundInstance::setLoop(bool value) {
	loops = value;
	if (instance)
		al_set_sample_instance_playmode(instance,
				value == true ? ALLEGRO_PLAYMODE_LOOP : ALLEGRO_PLAYMODE_ONCE);
}

void AllegroSoundInstance::setGain(float value) {
	gain = value;
	if (instance)
		al_set_sample_instance_gain(instance, value);
}

void AllegroSoundInstance::setPan(float value) {
	pan = value;
	if (instance)
		al_set_sample_instance_pan(instance, value);
}

} /* namespace Zeta */
