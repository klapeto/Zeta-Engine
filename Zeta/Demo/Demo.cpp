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

#include <Zeta/Core/Logger.hpp>
#include <Zeta/Core/System.hpp>
#include <Zeta/Core/LuaEngine.hpp>
#include <Zeta/Core/XMLSchemaValidator.hpp>
#include <Zeta/Core/RenderingContext.hpp>
#include <Zeta/Core/FunctorContextOperation.hpp>
#include <Zeta/Core/MainLoop.hpp>
#include <Zeta/Core/GUIManager.hpp>
#include <Zeta/Core/Settings.hpp>
#include <Zeta/Core/RPGClasses/AI/FactionManager.hpp>
#include <Zeta/LibraryBinders/Allegro5/AllegroSDK.hpp>
#include <Zeta/LibraryBinders/Allegro5/AllegroLoop.hpp>
#include <getopt.h>
#include <iostream>

static void printHelp() {
	std::cout << "\n\tZeta Engine Demo\n\n"
			"\t --fps=x\t\tSet the game running speed to x FPS\n"
			"\t\t\t\t(default: 60)\n"
			"\t --datafolder=path\tSet the folder that contains the data\n"
			"\t\t\t\tIt does not affect the other arguments\n"
			"\t\t\t\t(eg. boofile) (default: Demo)\n"
			"\t --bootfile=file\tSet the Lua Script file to execute after \n"
			"\t\t\t\tthe Engine and CEGUI initialization\n"
			"\t\t\t\t(default: Demo/Boot.lua)\n"
			"\t --ceguiconf=file\tSet the CEGUI Configuration XML file\n"
			"\t\t\t\t(default: Demo/CEGUI_Settiings.xml)\n"
			"\t --gameconf=file\tSet the game configuration XML File \n"
			"\t\t\t\t(default: GameSettings.xml)\n"
			"\t --factionfile=file\tSet the faction XML File\n"
			"\t\t\t\t(default: Demo/Factions.xml)\n"
			"\t --help\t\t\tPrint this help\n\n"
			"The game will not run when passed the --help argument.\n\n";
}

int main(int argC, char** argV) {

	/* Get the Logger Instance so we can output Messages to Log File */
	Zeta::Logger& log = Zeta::Logger::getInstance();

	int fps = 60;

	struct argumentPass {
		std::string bootFile = "Demo/Boot.lua";
		std::string dataFolder = "Demo";
		std::string ceguiConf = "Demo/CEGUI_Settings.xml";
		std::string gameConf = "GameSettings.xml";
		std::string factionsFile = "Demo/Factions.xml";
	} args;

	{
		enum Opts {
			Arg_FPS,
			Arg_BootFile,
			Arg_DataFolder,
			Arg_CEGUI,
			Arg_GameConf,
			Arg_FactionFile,
			Arg_Help
		};
		struct option options[] = { { "fps", 1, nullptr, 0 }, { "bootfile", 1,
				nullptr, 0 }, { "datafolder", 1, nullptr, 0 }, { "ceguiconf", 1,
				nullptr, 0 }, { "gameconf", 1, nullptr, 0 }, { "factionfile", 1,
				nullptr, 0 }, { "help", 0, nullptr, 0 }, { nullptr, 0, nullptr,
				0 } };

		int option_index = 0;
		int c = 0;
		while ((c = getopt_long(argC, argV, "", options, &option_index)) != -1) {
			switch (option_index) {
			case Opts::Arg_FPS:
				if (optarg != nullptr) {
					fps = strtol(optarg, nullptr, 0);
				} else {
					return EXIT_SUCCESS;
				}
				break;
			case Opts::Arg_BootFile:
				if (optarg != nullptr) {
					args.bootFile = optarg;
				} else {
					return EXIT_SUCCESS;
				}
				break;
			case Opts::Arg_DataFolder:
				if (optarg != nullptr) {
					args.dataFolder = optarg;
				} else {
					return EXIT_SUCCESS;
				}
				break;
			case Opts::Arg_CEGUI:
				if (optarg != nullptr) {
					args.ceguiConf = optarg;
				} else {
					return EXIT_SUCCESS;
				}
				break;
			case Opts::Arg_GameConf:
				if (optarg != nullptr) {
					args.gameConf = optarg;
				} else {
					return EXIT_SUCCESS;
				}
				break;
			case Opts::Arg_FactionFile:
				if (optarg != nullptr) {
					args.factionsFile = optarg;
				} else {
					return EXIT_SUCCESS;
				}
				break;
			case Opts::Arg_Help:
				printHelp();
				return EXIT_SUCCESS;
				break;
			default:
				return EXIT_SUCCESS;
				break;
			}
		}
	}

	/* Let this do some magic. Don't ask what it does unless you really want to.
	 * ***Whispering*** (It Initializes the Engine with Allegro as the SDK!) */
	Zeta::AllegroSDK::bootstrap();

	/* Get The engine's System Instance to get access to the Engine's Contexts.
	 * Don't ever call this before you call System::create(...). You will just crash the game before it starts.
	 * Here, AllegroSDK::bootstrap() did it for you because when you create the system, you need to
	 * pass a RenderingContext, and a ResourceContext. Unless you know what are these, and how they work
	 * on Zeta, don't bother with them. Just call Zeta::(X)SDK::bootstrap() at the start of the program
	 * and carry on. */
	Zeta::System& sys = Zeta::System::getInstance();

	/* Get the XML Schemas Container.
	 * We need to tell this where the XSDs are.
	 * If we don't do this, no XML based Resource will be accepted by the engine. When a resource is asked and
	 * the Engine rejects the resource, the asker will be given a NullResource. NullResource is a valid resource,
	 * the asker can use is perfectly, but contain garbage. E.g. NullBitmap will draw a non-sense rectangle with
	 * garbage of the GPU Memory. You don't want this unless you want to play something like "Pokemon: Glitch World Version"!
	 * Keep in mind that NullResources are Singletons. This means that every NullBitmap will draw the same garbage */
	auto& validators = Zeta::XMLSchemaValidator::getInstance();

	log.write("Loading XML Validators...");
	validators.setSchemaFile(
			args.dataFolder + "/XMLFiles/Schemas/AnimationClasses.xsd",
			Zeta::XMLSchemaValidator::ResourceValidator::AnimationClass);
	validators.setSchemaFile(
			args.dataFolder + "/XMLFiles/Schemas/DarkFunctionAnim.xsd",
			Zeta::XMLSchemaValidator::ResourceValidator::Animations);
	validators.setSchemaFile(
			args.dataFolder + "/XMLFiles/Schemas/DarkFunctionSprites.xsd",
			Zeta::XMLSchemaValidator::ResourceValidator::Sprites);
	validators.setSchemaFile(
			args.dataFolder + "/XMLFiles/Schemas/LifeformClasses.xsd",
			Zeta::XMLSchemaValidator::ResourceValidator::LifeformClass);
	validators.setSchemaFile(args.dataFolder + "/XMLFiles/Schemas/TiledMap.xsd",
			Zeta::XMLSchemaValidator::ResourceValidator::Map);
	validators.setSchemaFile(
			args.dataFolder + "/XMLFiles/Schemas/TiledTileset.xsd",
			Zeta::XMLSchemaValidator::ResourceValidator::Tileset);
	validators.setSchemaFile(args.dataFolder + "/XMLFiles/Schemas/Factions.xsd",
			Zeta::XMLSchemaValidator::ResourceValidator::Faction);

	log.write("Initiating GuiManager/LuaEngine/GameSettings...");
	sys.getRenderingContext().addOperationToQueue(
			*new Zeta::FunctorContextOperation<Zeta::RenderingContext>(
					[args](Zeta::RenderingContext& context) {
						Zeta::GUIManager::getInstance().initializeContext(args.ceguiConf);
						Zeta::Settings::getInstance().loadFile(args.gameConf);

						Zeta::LuaEngine& lua = Zeta::LuaEngine::getInstance();
						lua.includePath(".");
						lua.excecuteScriptFile(args.bootFile);
					}));

	Zeta::FactionManager::getInstance().parseFactionFile(args.factionsFile);
	log.write("Zeta Engine Initialization is over.");
	log.write(
			"Starting Main Loop... Anything beyond this line, are messages from provoked by User Configurations/Actions");
	log.write("===========================================================");

	{

		Zeta::AllegroLoop loop(fps);
		loop.setLoop(&Zeta::MainLoop::getInstance());
		loop.start();
	}

	Exit: return EXIT_SUCCESS;
}
