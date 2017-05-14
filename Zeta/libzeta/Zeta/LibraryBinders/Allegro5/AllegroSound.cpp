/*
 * AllegroSound.cpp
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
#include <allegro5/memory.h>
#include <Zeta/Core/UtilityClasses/Exception.hpp>
#include <Zeta/LibraryBinders/Allegro5/AllegroSound.hpp>
#include <Zeta/LibraryBinders/Allegro5/AllegroSoundInstance.hpp>
#include <sys/types.h>

namespace Zeta {

AllegroSound::AllegroSound() :
		Sound("null AllegroSound") {
	unsigned int samples = 44000;

	char *buff = (char*) al_malloc(samples * sizeof(int16_t));

	sample = al_create_sample(buff, samples, 44000, ALLEGRO_AUDIO_DEPTH_INT16,
			ALLEGRO_CHANNEL_CONF_1, true);
}

AllegroSound::AllegroSound(const std::string& path) :
		Sound(path) {
	sample = al_load_sample(path.c_str());
	if (sample == nullptr) {
		throw Exception(path, "Failed Loading Sound (Allegro 5)");
	}
}

SoundInstance& AllegroSound::createNewInstance() const {
	return *new AllegroSoundInstance(al_create_sample_instance(sample));
}

AllegroSound::~AllegroSound() {
	al_destroy_sample(sample);
}

} /* namespace Zeta */
