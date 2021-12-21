#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include "globalThings.h"

//To use Sleep function included <Windows.h>
#include <Windows.h>

#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <FMOD/fmod.hpp>

#include <rssgl/GLText.h>
#include <fstream>
#include <vector>
#include "cLevelOne.h"

GLuint _width = 1920;
GLuint _height = 1080;

GLFWwindow* _window = NULL;
std::string __applicationName = "Guess the beat";


RSS::GLText* _text;
GLuint _textRowIndex = 2;


bool init();
bool initGLFW();
bool initGL();
bool initFMOD();
void shutdown();
void releaseAllSound();
void shutdownSound(FMOD::Sound* _soundToRelease);

//Main Function
int main(int args, char* argv) {
	//fprintf(stdout,"Hello world");
	if (!init()) {
		fprintf(stderr, "Unable to initialize app");
		exit(EXIT_FAILURE);
	}

	std::stringstream ss;
	float volume = 0.0f;
	float pitch = 0.0f;
	bool isPaused = false;

	GLuint lastKnownRowIndex = _textRowIndex;

	//Main loop
	while (!glfwWindowShouldClose(_window)) {
		//passing color values to change background
		glClearColor(::red, green, blue, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		lastKnownRowIndex = _textRowIndex;

		//Initial starting game
		_text->addLine("Press \"Enter\" to start the game", lastKnownRowIndex++);


		_text->addLine("AUDIO CONTROL STATUS  ", lastKnownRowIndex + 5);
		_result = _selectedChannelGroup->getName(_buffer, 255);
		if (_result != FMOD_OK) 
			fprintf(stderr, "Unable to read selected channel group name");
		ss.str("");
		ss << "SELECTED GROUP NAME : " << _buffer;
		_text->addLine(ss.str(), lastKnownRowIndex+6);

		_result = _selectedChannelGroup->getPaused(&isPaused);
		if (_result != FMOD_OK) 
			fprintf(stderr, "Unable to read selected channel group pause");
		ss.str("");
		ss << "SELECTED GROUP PAUSE : " << ((isPaused) ? "Yes" : "No");
		_text->addLine(ss.str(), lastKnownRowIndex+7);

		_result = _selectedChannelGroup->getVolume(&volume);
		if (_result != FMOD_OK) 
			fprintf(stderr, "Unable to read selected channel group volume");
		ss.str("");
		ss.precision(2);
		ss << "SELECT GROUP VOLUME : " << volume;
		_text->addLine(ss.str(), lastKnownRowIndex+8);

		_result = _selectedChannelGroup->getPitch(&pitch);
		if (_result != FMOD_OK) 
			fprintf(stderr, "Unable to read selected channel group pitch");
		ss.str("");
		ss.precision(2);
		ss << "SELECTED GROUP PITCH" << pitch;
		_text->addLine(ss.str(), lastKnownRowIndex+9);

		bool bypass = false;

		if (zKey) {

			_text->addLine("DSP STATUS", lastKnownRowIndex + 10);
			_dspEcho->getBypass(&bypass);
			ss.str("");
			ss << "Echo Active " << ((!bypass) ? "Yes" : "No");
			_text->addLine(ss.str(), lastKnownRowIndex + 11);

			_dspFlange->getBypass(&bypass);
			ss.str("");
			ss << "Flange Active " << ((!bypass) ? "Yes" : "No");
			_text->addLine(ss.str(), lastKnownRowIndex + 12);

			_dspObjectpan->getBypass(&bypass);
			ss.str("");
			ss << "Object Pan Active " << ((!bypass) ? "Yes" : "No");
			_text->addLine(ss.str(), lastKnownRowIndex + 13);

			_dspHighpass->getBypass(&bypass);
			ss.str("");
			ss << "High Pass Active " << ((!bypass) ? "Yes" : "No");
			_text->addLine(ss.str(), lastKnownRowIndex + 14);

		}
		else if (xKey) {
			_text->addLine("DSP STATUS", lastKnownRowIndex + 10);


			_dspDistortion->getBypass(&bypass);
			ss.str("");
			ss << "Distortion Active " << ((!bypass) ? "Yes" : "No");
			_text->addLine(ss.str(), lastKnownRowIndex + 11);

			_dspTremolo->getBypass(&bypass);
			ss.str("");
			ss << "Tremolo Active " << ((!bypass) ? "Yes" : "No");
			_text->addLine(ss.str(), lastKnownRowIndex + 12);

			_dspOscillator->getBypass(&bypass);
			ss.str("");
			ss << "Oscillator Active " << ((!bypass) ? "Yes" : "No");
			_text->addLine(ss.str(), lastKnownRowIndex + 13);

			_dspNormalize->getBypass(&bypass);
			ss.str("");
			ss << "Normalize Active " << ((!bypass) ? "Yes" : "No");
			_text->addLine(ss.str(), lastKnownRowIndex + 14);
		}
		else if (cKey) {
			_text->addLine("DSP STATUS", lastKnownRowIndex + 10);

			_dspChorus->getBypass(&bypass);
			ss.str("");
			ss << "Chorus Active " << ((!bypass) ? "Yes" : "No");
			_text->addLine(ss.str(), lastKnownRowIndex + 11);

			_dspPan->getBypass(&bypass);
			ss.str("");
			ss << "Pan Active " << ((!bypass) ? "Yes" : "No");
			_text->addLine(ss.str(), lastKnownRowIndex + 12);

			_dspFader->getBypass(&bypass);
			ss.str("");
			ss << "Fader Active " << ((!bypass) ? "Yes" : "No");
			_text->addLine(ss.str(), lastKnownRowIndex + 13);

			_dspLimiter->getBypass(&bypass);
			ss.str("");
			ss << "Limiter Active " << ((!bypass) ? "Yes" : "No");
			_text->addLine(ss.str(), lastKnownRowIndex + 14);

		}
		else if (vKey) {
			_text->addLine("DSP STATUS", lastKnownRowIndex + 10);

			_dspDelay->getBypass(&bypass);
			ss.str("");
			ss << "Delay Active " << ((!bypass) ? "Yes" : "No");
			_text->addLine(ss.str(), lastKnownRowIndex + 11);

			_dspConvolutionreverb->getBypass(&bypass);
			ss.str("");
			ss << "Convolution Reverb Active " << ((!bypass) ? "Yes" : "No");
			_text->addLine(ss.str(), lastKnownRowIndex + 12);

			_dspLowpass->getBypass(&bypass);
			ss.str("");
			ss << "Low Pass Active " << ((!bypass) ? "Yes" : "No");
			_text->addLine(ss.str(), lastKnownRowIndex + 13);

			_dspCompressor->getBypass(&bypass);
			ss.str("");
			ss << "Compressor Active " << ((!bypass) ? "Yes" : "No");
			_text->addLine(ss.str(), lastKnownRowIndex + 14);

		}


		_text->addLine("AUDIO GROUP CONTROLS", lastKnownRowIndex + 16);
		_text->addLine("P - to pause a Selected Channel, Up/Down Increase and decrease Volume,Left/Right Increase and decrease Pitch", lastKnownRowIndex + 17);
		_text->addLine("Z to select BGM Channel,  X to select Question Voice Channel, C to select Options for Questions Channel", lastKnownRowIndex + 18);

		_text->addLine("CONTROLS", lastKnownRowIndex + 19);
		_text->addLine("ENTER - to start the game, ESC to quit game", lastKnownRowIndex + 20);
		_text->addLine("Q - Replay the given beat, R - Replay the given beat options AND 1, 2, 3, 4 - Options to guess the beat", lastKnownRowIndex + 21);

		//LEVEL 1
		if (isStartgame) {
			_text->addLine("LEVEL 1", lastKnownRowIndex++);
			_text->addLine("Identify the sound played. You have 4 option to answer. Press Q to hear the given beat. Press R to hear 4 options of sound. Click 1,2,3 or 4 to select the options. You have 3 attempts to answer", lastKnownRowIndex++);
		}
		//LEVEL 2
		else if (isLevel1) {
			_text->addLine("LEVEL 2", lastKnownRowIndex);
			_text->addLine("Identify which side the sound played. You have 3 option to answer. Press Q to hear the given beat. Press R to hear 3 options of sound. Click 1,2 or 3 to select the options. You have 3 attempts to answer", ++lastKnownRowIndex);

		}
		//LEVEL 3
		else if (isLevel2) {
			_text->addLine("LEVEL 3", lastKnownRowIndex);
			_text->addLine("Identify the matching sound. You have 3 option to answer. Press Q to play the sound. Press R to hear 3 variations of the sound. Which did it match? Click 1,2 or 3. You have 3 attempts to answer ", ++lastKnownRowIndex);

		}
		//Game won
		else if (isLevel3) {
			_text->addLine("CONGRATULATIONS!", lastKnownRowIndex);
			_text->addLine("Looks like we have a winner with a keen ear! Press Esc to Exit. ", ++lastKnownRowIndex);
			_text->addLine("END CREDITS", lastKnownRowIndex + 5);
			_text->addLine("Pradeep & Dennison", lastKnownRowIndex + 6);
			for (int i = 7; i < 22;i++) {
				_text->addLine(" ", lastKnownRowIndex + i);
			}


		}
		if (isEndgame) {
			_text->addLine("Game Over", --lastKnownRowIndex);
			_text->addLine("You Lose", lastKnownRowIndex);
			_text->addLine("Press Esc to quit. Relaunch to try again.", ++lastKnownRowIndex);
			_text->addLine(" ", ++lastKnownRowIndex);
			_text->addLine("END CREDITS", lastKnownRowIndex + 5);
			_text->addLine("Pradeep & Dennison", lastKnownRowIndex + 6);
			for (int i = 7; i < 22; i++) {
				_text->addLine(" ", lastKnownRowIndex + i);
			}
		}

		_text->render();
		glfwSwapBuffers(_window);
		glfwPollEvents();
	}
	shutdown();

	return 0;
}

bool init() {

	if (!initGLFW()) {
		return false;
	}
	if (!initGL()) {
		return false;
	}
	//dependency GLtext and Opengl
	_text = new RSS::GLText(__applicationName, _width, _height);

	if (!initFMOD()) {
		return false;
	}
	return true;
}

bool initGLFW() {
	if (!glfwInit()) {
		fprintf(stderr, "Unable to initalize GLFW");
		return false;
	}

	//error callback
	glfwSetErrorCallback(glfw_error_callback);

	_window = glfwCreateWindow(_width, _height, __applicationName.c_str(), NULL, NULL);
	if (!_window) {
		fprintf(stderr, "Unable to create GLFW window");
		return false;
	}

	//set keyboard callback
	glfwSetKeyCallback(_window, glfw_key_callback);
	glfwMakeContextCurrent(_window);
	glfwSwapInterval(1);

	return true;
}

bool initGL() {
	if (!gladLoadGL(glfwGetProcAddress)) {
		fprintf(stderr, "unable to initialize glad");
		return false;
	}

	glEnable(GL_CULL_FACE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	return true;
}

bool initFMOD() {
	initializeSound();
	assignSound();
	/*cLevel* cLevelone = new cLevelOne();
	cLevelone->playCondition();*/

	_selectedChannelGroup = _channelGroupMaster;


	return true;
}


void shutdown() {
	glfwTerminate();

	//single function to release all sound
	releaseAllSound();

	_result = _system->close();
	if (_result != FMOD_OK) {
		fprintf(stderr, "Unable to close system");
	}

	_result = _system->release();
	if (_result != FMOD_OK) {
		fprintf(stderr, "Unable to release system");
	}

	if (_text) {
		delete _text;
		_text = nullptr;
	}

	exit(EXIT_SUCCESS);
}

void releaseAllSound() {
	shutdownSound(_soundClick);
	shutdownSound(_soundEndBgm);
	shutdownSound(_soundGameLost);
	shutdownSound(_soundGameWon);
	shutdownSound(_soundLevel2Center);
	shutdownSound(_soundLevel2Left);
	shutdownSound(_soundLevel2Right);
	shutdownSound(_soundLevel2Sound);
	shutdownSound(_soundLevel3Sound);
	shutdownSound(_soundMidBgm);
	shutdownSound(_soundQuestion1);
	shutdownSound(_soundQuestion1Sound);
	shutdownSound(_soundQuestion2);
	shutdownSound(_soundQuestion2Sound);
	shutdownSound(_soundQuestion3);
	shutdownSound(_soundQuestion3Sound);
	shutdownSound(_soundQuestionSound);
	shutdownSound(_soundStartBgm);
}

void shutdownSound(FMOD::Sound* _soundToRelease) {
	_result = _soundToRelease->release();
	if (_result != FMOD_OK) {
		fprintf(stderr, "Unable to release sound");
	}
}

//Readfile and get the path

