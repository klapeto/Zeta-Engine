/*
 * AllegroSDK.cpp
 *
 *  Created on: 3 Σεπ 2014
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

#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/keyboard.h>
#include <allegro5/mouse.h>
#include <allegro5/system.h>
#include <Zeta/Core/Logger.hpp>
#include <Zeta/Core/MainLoop.hpp>
#include <Zeta/Core/SingleInstanced.hpp>
#include <Zeta/Core/SynchronousRenderingContext.hpp>
#include <Zeta/Core/SynchronousResourceContext.hpp>
#include <Zeta/Core/System.hpp>
#include <Zeta/LibraryBinders/Allegro5/AllegroAudioContext.hpp>
#include <Zeta/LibraryBinders/Allegro5/AllegroBitmap.hpp>
#include <Zeta/LibraryBinders/Allegro5/AllegroDisplay.hpp>
#include <Zeta/LibraryBinders/Allegro5/AllegroLoop.hpp>
#include <Zeta/LibraryBinders/Allegro5/AllegroRenderer.hpp>
#include <Zeta/LibraryBinders/Allegro5/AllegroSDK.hpp>
#include <Zeta/LibraryBinders/Allegro5/AllegroSound.hpp>
#include <cstdlib>

namespace Zeta {

void AllegroSDK::bootstrap() {

	Logger& log = Logger::getInstance();

	log.write("Initializing Allegro 5...");
	if (!al_init()) {
		log.write("Failed to Initialize Allegro 5. Aborting execution...",
				Logger::MessageType::Error);
		exit(EXIT_FAILURE);
	}

	if (!al_install_keyboard()) {
		log.write(
				"Failed to install keyboard (Allegro 5). Aborting execution...",
				Logger::MessageType::Error);
		exit(EXIT_FAILURE);
	}

	if (!al_install_mouse()) {
		log.write("Failed to install mouse (Allegro 5). Aborting execution...",
				Logger::MessageType::Error);
		exit(EXIT_FAILURE);
	}

	if (!al_install_audio()) {
		log.write("Failed to install audio (Allegro 5). Aborting execution...",
				Logger::MessageType::Error);
		exit(EXIT_FAILURE);
	}

	if (!al_init_image_addon()) {
		log.write(
				"Failed to initialize image addon (Allegro 5). Aborting execution...",
				Logger::MessageType::Error);
		exit(EXIT_FAILURE);
	}

	if (!al_init_primitives_addon()) {
		log.write(
				"Failed to initialize primitives addon (Allegro 5). Aborting execution...",
				Logger::MessageType::Error);
		exit(EXIT_FAILURE);
	}

	if (!al_init_acodec_addon()) {
		log.write(
				"Failed to initialize audio codec addon (Allegro 5). Aborting execution...",
				Logger::MessageType::Error);
		exit(EXIT_FAILURE);
	}

	if (!al_reserve_samples(10)) {
		log.write(
				"Failed to initialize audio samples (Allegro 5). Aborting execution...",
				Logger::MessageType::Error);
		exit(EXIT_FAILURE);
	}

	log.write("Initializing Zeta Engine...");
	System& sys = System::create(
			new SynchronousRenderingContext<AllegroDisplay>,
			new SynchronousResourceContext<AllegroBitmap, AllegroSound>,
			new AllegroAudioContext, new AllegroRenderer);

}
} /* namespace Zeta */
