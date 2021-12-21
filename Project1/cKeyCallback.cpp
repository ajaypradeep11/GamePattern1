#include "globalThings.h"

void glfw_key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) {

	float volume = 0.0f;
	float pitch = 0.0f;
	bool isPaused = false;
	float stepSize = 0.02f;
	float volumeMax = 1.0f;
	float volumeMin = 0.0f;
	float pitchMax = 2.0f;
	float pitchMin = 0.0f;

	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
	else if (key == GLFW_KEY_ENTER && action == GLFW_PRESS) {

		
	}

	// LEVEL 1,2 and 3
	//Q press to hear question
	else if (key == GLFW_KEY_Q && action == GLFW_PRESS) {
		//we check isStartgame,isLevel1 and isLevel2 to check whether user is in LEVEL 1, 2 or 3 respectively
		if (isStartgame) {
			_channelQuestion->isPlaying(&_isPlaying);
			if (!_isPlaying) {

				_result = _system->playSound(_soundQuestion1Sound, _channelGroupOption, false, &_channelQuestion);
				if (_result != FMOD_OK) {
					fprintf(stderr, "unable to play sound");
				}
			}
		}
		else if (isLevel1) {
			_channelQuestion2->isPlaying(&_isPlaying);
			if (!_isPlaying) {
				_result = _system->playSound(_soundLevel2Sound, _channelGroupOption, false, &_channelQuestion2);
				//_attrib balance is changed. Left/Right
				_channelQuestion2->setPan(1);
				if (_result != FMOD_OK) {
					fprintf(stderr, "unable to play sound");
				}
			}
		}
		else if (isLevel2) {
			_channelQuestion3->isPlaying(&_isPlaying);
			if (!_isPlaying) {
				_result = _system->playSound(_soundLevel3Sound, _channelGroupOption, false, &_channelQuestion3);
				//_attrib Pitch is changed
				_channelQuestion3->setPitch(2.0);
				if (_result != FMOD_OK) {
					fprintf(stderr, "unable to play sound");
				}
			}
		}
	}

	//R press to hear options DEPENDS ON LEVEL
	else if (key == GLFW_KEY_R && action == GLFW_PRESS) {
		if (isStartgame) {
			_channelQuestion->isPlaying(&_isPlaying);
			callOption();
		}
		else if (isLevel1) {
			_channelQuestion2->isPlaying(&_isPlaying);
			callOptionLvl2();
		}
		else if (isLevel2) {
			_channelQuestion3->isPlaying(&_isPlaying);
			callOptionLvl3();
		}


	}

	//pause background music we have three bgm. Initial bgm, game start bgm and game lost bgm.
	else if (key == GLFW_KEY_TAB && action == GLFW_PRESS) {
		//_pauseplay pause and play used
		if (_channelStartBgm) {
			_result = _channelStartBgm->getPaused(&_isPaused);
			_result = _channelStartBgm->setPaused(!_isPaused);
			_result = _channelStartBgm->getPaused(&_isPaused);
		}
	}

	//Level 1,2 and 3 answer options
	else if (((key == GLFW_KEY_1) || (key == GLFW_KEY_KP_1)) && action == GLFW_PRESS) {
		if (isStartgame) {
			incrementAndCheck();
		}
		else if (isLevel1) {
			incrementAndCheck();
		}
		else if (isLevel2) {
			incrementAndCheck();
		}
	}
	else if (((key == GLFW_KEY_2) || (key == GLFW_KEY_KP_2)) && action == GLFW_PRESS) {
		
	}
	else if (((key == GLFW_KEY_3) || (key == GLFW_KEY_KP_3)) && action == GLFW_PRESS) {
		
	}
	else if (key == GLFW_KEY_Z && action == GLFW_PRESS) {
		_selectedChannelGroup = _channelGroupBGM;

		_result = _system->createDSPByType(FMOD_DSP_TYPE_ECHO, &_dspEcho);
		if (FMOD_OK != _result) {
			fprintf(stderr, "Unable to create dsp\n");

		}
		//Append dsp to channel index 0
		//_result = _vecChannels.at(0)->addDSP(0, _dspEcho);
		_result = _selectedChannelGroup->addDSP(0, _dspEcho);
		if (FMOD_OK != _result) {
			fprintf(stderr, "Unable to add dsp to channel\n");

		}
		//Enalbe dsp
		_result = _dspEcho->setActive(true);
		if (FMOD_OK != _result) {
			fprintf(stderr, "Unable set dsp to active\n");

		}
		//Bypass dsp for now
		_result = _dspEcho->setBypass(true);
		if (FMOD_OK != _result) {
			fprintf(stderr, "Unable set dsp bypass\n");

		}



		//Flange
		_result = _system->createDSPByType(FMOD_DSP_TYPE_FLANGE, &_dspFlange);
		if (FMOD_OK != _result) {
			fprintf(stderr, "Unable to create dsp\n");
		}
		//Append dsp to channel index 0

		_result = _selectedChannelGroup->addDSP(0, _dspFlange);
		if (FMOD_OK != _result) {
			fprintf(stderr, "Unable to add dsp to channel\n");
		}
		//Enalbe dsp
		_result = _dspFlange->setActive(true);
		if (FMOD_OK != _result) {
			fprintf(stderr, "Unable set dsp to active\n");
		}
		//Bypass dsp for now
		_result = _dspFlange->setBypass(true);
		if (FMOD_OK != _result) {
			fprintf(stderr, "Unable set dsp bypass\n");
		}


		//NINE - objectpan

		_result = _system->createDSPByType(FMOD_DSP_TYPE_OBJECTPAN, &_dspObjectpan);
		if (FMOD_OK != _result) {
			fprintf(stderr, "Unable to create dsp\n");
		}
		//Append dsp to channel index 0

		_result = _selectedChannelGroup->addDSP(2, _dspObjectpan);
		if (FMOD_OK != _result) {
			fprintf(stderr, "Unable to add dsp to channel8\n");
		}
		//Enalbe dsp
		_result = _dspObjectpan->setActive(true);
		if (FMOD_OK != _result) {
			fprintf(stderr, "Unable set dsp to active\n");
		}
		//Bypass dsp for now
		_result = _dspObjectpan->setBypass(true);
		if (FMOD_OK != _result) {
			fprintf(stderr, "Unable set dsp bypass\n");
		}


		//THIRTEEN - highpass

		_result = _system->createDSPByType(FMOD_DSP_TYPE_HIGHPASS, &_dspHighpass);
		if (FMOD_OK != _result) {
			fprintf(stderr, "Unable to create dsp\n");
		}
		//Append dsp to channel index 0

		_result = _selectedChannelGroup->addDSP(3, _dspHighpass);
		if (FMOD_OK != _result) {
			fprintf(stderr, "Unable to add dsp to channel4\n");
		}
		//Enalbe dsp
		_result = _dspHighpass->setActive(true);
		if (FMOD_OK != _result) {
			fprintf(stderr, "Unable set dsp to active\n");
		}
		//Bypass dsp for now
		_result = _dspHighpass->setBypass(true);
		if (FMOD_OK != _result) {
			fprintf(stderr, "Unable set dsp bypass\n");
		}


		zKey = true;
		xKey = false;
		cKey = false;
		vKey = false;
	}
	else if (key == GLFW_KEY_X && action == GLFW_PRESS) {
		_selectedChannelGroup = _channelGroupVoice;

		//Distortion
		_result = _system->createDSPByType(FMOD_DSP_TYPE_DISTORTION, &_dspDistortion);
		if (FMOD_OK != _result) {
			fprintf(stderr, "Unable to create dsp\n");
		}

		_result = _selectedChannelGroup->addDSP(0, _dspDistortion);
		if (FMOD_OK != _result) {
			fprintf(stderr, "Unable to add dsp to channel14\n");
		}
		//Enalbe dsp
		_result = _dspDistortion->setActive(true);
		if (FMOD_OK != _result) {
			fprintf(stderr, "Unable set dsp to active\n");
		}
		//Bypass dsp for now
		_result = _dspDistortion->setBypass(true);
		if (FMOD_OK != _result) {
			fprintf(stderr, "Unable set dsp bypass\n");
		}



		_result = _system->createDSPByType(FMOD_DSP_TYPE_TREMOLO, &_dspTremolo);
		if (FMOD_OK != _result) {
			fprintf(stderr, "Unable to create dsp\n");
		}
		//Append dsp to channel index 0

		_result = _selectedChannelGroup->addDSP(1, _dspTremolo);
		if (FMOD_OK != _result) {
			fprintf(stderr, "Unable to add dsp to channel11\n");
		}
		//Enalbe dsp
		_result = _dspTremolo->setActive(true);
		if (FMOD_OK != _result) {
			fprintf(stderr, "Unable set dsp to active\n");
		}
		//Bypass dsp for now
		_result = _dspTremolo->setBypass(true);
		if (FMOD_OK != _result) {
			fprintf(stderr, "Unable set dsp bypass\n");
		}


		//TEN - oscillator

		_result = _system->createDSPByType(FMOD_DSP_TYPE_OSCILLATOR, &_dspOscillator);
		if (FMOD_OK != _result) {
			fprintf(stderr, "Unable to create dsp\n");
		}
		//Append dsp to channel index 0

		_result = _selectedChannelGroup->addDSP(2, _dspOscillator);
		if (FMOD_OK != _result) {
			fprintf(stderr, "Unable to add dsp to channel7\n");
		}
		//Enalbe dsp
		_result = _dspOscillator->setActive(true);
		if (FMOD_OK != _result) {
			fprintf(stderr, "Unable set dsp to active\n");
		}
		//Bypass dsp for now
		_result = _dspOscillator->setBypass(true);
		if (FMOD_OK != _result) {
			fprintf(stderr, "Unable set dsp bypass\n");
		}

		//FOURTEEN - normalize

		_result = _system->createDSPByType(FMOD_DSP_TYPE_NORMALIZE, &_dspNormalize);
		if (FMOD_OK != _result) {
			fprintf(stderr, "Unable to create dsp\n");
		}
		//Append dsp to channel index 0

		_result = _selectedChannelGroup->addDSP(3, _dspNormalize);
		if (FMOD_OK != _result) {
			fprintf(stderr, "Unable to add dsp to channel3\n");
		}
		//Enalbe dsp
		_result = _dspNormalize->setActive(true);
		if (FMOD_OK != _result) {
			fprintf(stderr, "Unable set dsp to active\n");
		}
		//Bypass dsp for now
		_result = _dspNormalize->setBypass(true);
		if (FMOD_OK != _result) {
			fprintf(stderr, "Unable set dsp bypass\n");
		}



		zKey = false;
		xKey = true;
		cKey = false;
		vKey = false;

	}
	else if (key == GLFW_KEY_C && action == GLFW_PRESS) {
		_selectedChannelGroup = _channelGroupOption;


		//Chorus
		_result = _system->createDSPByType(FMOD_DSP_TYPE_CHORUS, &_dspChorus);
		if (FMOD_OK != _result) {
			fprintf(stderr, "Unable to create dsp\n");
		}
		_result = _selectedChannelGroup->addDSP(0, _dspChorus);
		if (FMOD_OK != _result) {
			fprintf(stderr, "Unable to add dsp to channel13\n");
		}
		_result = _dspChorus->setActive(true);
		if (FMOD_OK != _result) {
			fprintf(stderr, "Unable set dsp to active\n");
		}
		_result = _dspChorus->setBypass(true);
		if (FMOD_OK != _result) {
			fprintf(stderr, "Unable set dsp bypass\n");
		}

		//SEVEN - pan

		_result = _system->createDSPByType(FMOD_DSP_TYPE_PAN, &_dspPan);
		if (FMOD_OK != _result) {
			fprintf(stderr, "Unable to create dsp\n");
		}
		//Append dsp to channel index 0

		_result = _selectedChannelGroup->addDSP(1, _dspPan);
		if (FMOD_OK != _result) {
			fprintf(stderr, "Unable to add dsp to channel10\n");
		}
		//Enalbe dsp
		_result = _dspPan->setActive(true);
		if (FMOD_OK != _result) {
			fprintf(stderr, "Unable set dsp to active\n");
		}
		//Bypass dsp for now
		_result = _dspPan->setBypass(true);
		if (FMOD_OK != _result) {
			fprintf(stderr, "Unable set dsp bypass\n");
		}


		//ELEVEN - fader

		_result = _system->createDSPByType(FMOD_DSP_TYPE_FADER, &_dspFader);
		if (FMOD_OK != _result) {
			fprintf(stderr, "Unable to create dsp\n");
		}
		//Append dsp to channel index 0

		_result = _selectedChannelGroup->addDSP(2, _dspFader);
		if (FMOD_OK != _result) {
			fprintf(stderr, "Unable to add dsp to channel6\n");
		}
		//Enalbe dsp
		_result = _dspFader->setActive(true);
		if (FMOD_OK != _result) {
			fprintf(stderr, "Unable set dsp to active\n");
		}
		//Bypass dsp for now
		_result = _dspFader->setBypass(true);
		if (FMOD_OK != _result) {
			fprintf(stderr, "Unable set dsp bypass\n");
		}



		//FIFTEEN - limiter

		_result = _system->createDSPByType(FMOD_DSP_TYPE_LIMITER, &_dspLimiter);
		if (FMOD_OK != _result) {
			fprintf(stderr, "Unable to create dsp\n");
		}
		//Append dsp to channel index 0

		_result = _selectedChannelGroup->addDSP(3, _dspLimiter);
		if (FMOD_OK != _result) {
			fprintf(stderr, "Unable to add dsp to channel2\n");
		}
		//Enalbe dsp
		_result = _dspLimiter->setActive(true);
		if (FMOD_OK != _result) {
			fprintf(stderr, "Unable set dsp to active\n");
		}
		//Bypass dsp for now
		_result = _dspLimiter->setBypass(true);
		if (FMOD_OK != _result) {
			fprintf(stderr, "Unable set dsp bypass\n");
		}

		zKey = false;
		xKey = false;
		cKey = true;
		vKey = false;

	}
	else if (key == GLFW_KEY_V && action == GLFW_PRESS) {
		_selectedChannelGroup = _channelGroupSong;

		//Delay
		_result = _system->createDSPByType(FMOD_DSP_TYPE_DELAY, &_dspDelay);
		if (FMOD_OK != _result) {
			fprintf(stderr, "Unable to create dsp\n");
		}
		//Append dsp to channel index 0

		_result = _selectedChannelGroup->addDSP(1, _dspDelay);
		if (FMOD_OK != _result) {
			fprintf(stderr, "Unable to add dsp to channel12\n");
		}
		//Enalbe dsp
		_result = _dspDelay->setActive(true);
		if (FMOD_OK != _result) {
			fprintf(stderr, "Unable set dsp to active\n");
		}
		//Bypass dsp for now
		_result = _dspDelay->setBypass(true);
		if (FMOD_OK != _result) {
			fprintf(stderr, "Unable set dsp bypass\n");
		}

		//EIGHT - convolutionreverb

		_result = _system->createDSPByType(FMOD_DSP_TYPE_CONVOLUTIONREVERB, &_dspConvolutionreverb);
		if (FMOD_OK != _result) {
			fprintf(stderr, "Unable to create dsp\n");
		}
		//Append dsp to channel index 0

		_result = _selectedChannelGroup->addDSP(1, _dspConvolutionreverb);
		if (FMOD_OK != _result) {
			fprintf(stderr, "Unable to add dsp to channel9\n");
		}
		//Enalbe dsp
		_result = _dspConvolutionreverb->setActive(true);
		if (FMOD_OK != _result) {
			fprintf(stderr, "Unable set dsp to active\n");
		}
		//Bypass dsp for now
		_result = _dspConvolutionreverb->setBypass(true);
		if (FMOD_OK != _result) {
			fprintf(stderr, "Unable set dsp bypass\n");
		}

		//TWELVE - lowpass

		_result = _system->createDSPByType(FMOD_DSP_TYPE_LOWPASS, &_dspLowpass);
		if (FMOD_OK != _result) {
			fprintf(stderr, "Unable to create dsp\n");
		}
		//Append dsp to channel index 0

		_result = _selectedChannelGroup->addDSP(2, _dspLowpass);
		if (FMOD_OK != _result) {
			fprintf(stderr, "Unable to add dsp to channel5\n");
		}
		//Enalbe dsp
		_result = _dspLowpass->setActive(true);
		if (FMOD_OK != _result) {
			fprintf(stderr, "Unable set dsp to active\n");
		}
		//Bypass dsp for now
		_result = _dspLowpass->setBypass(true);
		if (FMOD_OK != _result) {
			fprintf(stderr, "Unable set dsp bypass\n");
		}


		//SIXTEEN - compressor

		_result = _system->createDSPByType(FMOD_DSP_TYPE_COMPRESSOR, &_dspCompressor);
		if (FMOD_OK != _result) {
			fprintf(stderr, "Unable to create dsp\n");
		}
		//Append dsp to channel index 0

		_result = _selectedChannelGroup->addDSP(3, _dspCompressor);
		if (FMOD_OK != _result) {
			fprintf(stderr, "Unable to add dsp to channel1\n");
		}
		//Enalbe dsp
		_result = _dspCompressor->setActive(true);
		if (FMOD_OK != _result) {
			fprintf(stderr, "Unable set dsp to active\n");
		}
		//Bypass dsp for now
		_result = _dspCompressor->setBypass(true);
		if (FMOD_OK != _result) {
			fprintf(stderr, "Unable set dsp bypass\n");
		}
		zKey = false;
		xKey = false;
		cKey = false;
		vKey = true;
	}
	else if (key == GLFW_KEY_M && action == GLFW_PRESS) {
		_selectedChannelGroup = _channelGroupMaster;
	}
	else if (((key == GLFW_KEY_4) || (key == GLFW_KEY_KP_4)) && action == GLFW_PRESS) {
		if (isStartgame) {
			incrementAndCheck();
		}
	}
	else if (key == GLFW_KEY_P && action == GLFW_PRESS) {
		_result = _selectedChannelGroup->getPaused(&isPaused);
		if (_result != FMOD_OK) {
			fprintf(stderr, "Unable to read pause");
		}
		_result = _selectedChannelGroup->setPaused(!isPaused);
		if (_result != FMOD_OK) {
			fprintf(stderr, "Unable to set pause");
		}

	}
	else if (key == GLFW_KEY_UP && action == GLFW_PRESS) {
		_result = _selectedChannelGroup->getVolume(&volume);
		if (_result != FMOD_OK) {
			fprintf(stderr, "Unable to read volume");
		}
		//Clamp volume
		volume = (volume >= volumeMax) ? volumeMax : (volume + stepSize);
		_result = _selectedChannelGroup->setVolume(volume);
		if (_result != FMOD_OK) {
			fprintf(stderr, "Unable to set volume");
		}
	}
	else if (key == GLFW_KEY_DOWN && action == GLFW_PRESS) {
		_result = _selectedChannelGroup->getVolume(&volume);
		if (_result != FMOD_OK) {
			fprintf(stderr, "Unable to read volume");
		}
		//Clamp volume
		volume = (volume <= volumeMin) ? volumeMin : (volume - stepSize);
		_result = _selectedChannelGroup->setVolume(volume);
		if (_result != FMOD_OK) {
			fprintf(stderr, "Unable to set volume");
		}
	}
	else if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS) {
		_result = _selectedChannelGroup->getPitch(&pitch);
		if (_result != FMOD_OK) {
			fprintf(stderr, "Unable to get pitch");
		}
		//Clamp pitch
		pitch = (pitch >= pitchMax) ? pitchMax : (pitch + stepSize);
		//Set pitch
		_result = _selectedChannelGroup->setPitch(pitch);
		if (_result != FMOD_OK) {
			fprintf(stderr, "Unable to set pitch");
		}
	}
	else if (key == GLFW_KEY_LEFT && action == GLFW_PRESS) {
		_result = _selectedChannelGroup->getPitch(&pitch);
		if (_result != FMOD_OK) {
			fprintf(stderr, "Unable to get pitch");
		}
		//Clamp pitch
		pitch = (pitch <= pitchMin) ? pitchMin : (pitch - stepSize);
		//Set pitch
		_result = _selectedChannelGroup->setPitch(pitch);
		if (_result != FMOD_OK) {
			fprintf(stderr, "Unable to set pitch");
		}
	}
	else if (key == GLFW_KEY_0 && action == GLFW_PRESS) {
		//you can do better
		if (zKey) {
			bool bypass = false;
			_result = _dspEcho->getBypass(&bypass);
			if (FMOD_OK != _result) {
				fprintf(stderr, "Unable to get bypass!\n");
			}
			_result = _dspEcho->setBypass(!bypass);
			if (FMOD_OK != _result) {
				fprintf(stderr, "Unable to set bypass!\n");
			}
		}
		else if (xKey) {
			bool bypass = false;
			_result = _dspDistortion->getBypass(&bypass);
			if (FMOD_OK != _result) {
				fprintf(stderr, "Unable to get bypass!\n");
			}
			_result = _dspDistortion->setBypass(!bypass);
			if (FMOD_OK != _result) {
				fprintf(stderr, "Unable to set bypass!\n");
			}

		}
		else if (cKey) {
			bool bypass = false;
			_result = _dspChorus->getBypass(&bypass);
			if (FMOD_OK != _result) {
				fprintf(stderr, "Unable to get bypass!\n");
			}
			_result = _dspChorus->setBypass(!bypass);
			if (FMOD_OK != _result) {
				fprintf(stderr, "Unable to set bypass!\n");
			}

		}
		else if (vKey) {
			bool bypass = false;
			_result = _dspDelay->getBypass(&bypass);
			if (FMOD_OK != _result) {
				fprintf(stderr, "Unable to get bypass!\n");
			}
			_result = _dspDelay->setBypass(!bypass);
			if (FMOD_OK != _result) {
				fprintf(stderr, "Unable to set bypass!\n");
			}
		}

	}
	else if (key == GLFW_KEY_9 && action == GLFW_PRESS) {
		////you can do better
		if (zKey) {
			bool bypass = false;
			_result = _dspFlange->getBypass(&bypass);
			if (FMOD_OK != _result) {
				fprintf(stderr, "Unable to get bypass!\n");
			}
			_result = _dspFlange->setBypass(!bypass);
			if (FMOD_OK != _result) {
				fprintf(stderr, "Unable to set bypass!\n");
			}
		}
		else if (xKey) {
			bool bypass = false;
			_result = _dspTremolo->getBypass(&bypass);
			if (FMOD_OK != _result) {
				fprintf(stderr, "Unable to get bypass!\n");
			}
			_result = _dspTremolo->setBypass(!bypass);
			if (FMOD_OK != _result) {
				fprintf(stderr, "Unable to set bypass!\n");
			}

		}
		else if (cKey) {
			bool bypass = false;
			_result = _dspPan->getBypass(&bypass);
			if (FMOD_OK != _result) {
				fprintf(stderr, "Unable to get bypass!\n");
			}
			_result = _dspPan->setBypass(!bypass);
			if (FMOD_OK != _result) {
				fprintf(stderr, "Unable to set bypass!\n");
			}

		}
		else if (vKey) {
			bool bypass = false;
			_result = _dspConvolutionreverb->getBypass(&bypass);
			if (FMOD_OK != _result) {
				fprintf(stderr, "Unable to get bypass!\n");
			}
			_result = _dspConvolutionreverb->setBypass(!bypass);
			if (FMOD_OK != _result) {
				fprintf(stderr, "Unable to set bypass!\n");
			}
		}
	}
	else if (key == GLFW_KEY_8 && action == GLFW_PRESS) {
		if (zKey) {
			bool bypass = false;
			_result = _dspObjectpan->getBypass(&bypass);
			if (FMOD_OK != _result) {
				fprintf(stderr, "Unable to get bypass!\n");
			}
			_result = _dspObjectpan->setBypass(!bypass);
			if (FMOD_OK != _result) {
				fprintf(stderr, "Unable to set bypass!\n");
			}
		}
		else if (xKey) {
			bool bypass = false;
			_result = _dspOscillator->getBypass(&bypass);
			if (FMOD_OK != _result) {
				fprintf(stderr, "Unable to get bypass!\n");
			}
			_result = _dspOscillator->setBypass(!bypass);
			if (FMOD_OK != _result) {
				fprintf(stderr, "Unable to set bypass!\n");
			}

		}
		else if (cKey) {
			bool bypass = false;
			_result = _dspFader->getBypass(&bypass);
			if (FMOD_OK != _result) {
				fprintf(stderr, "Unable to get bypass!\n");
			}
			_result = _dspFader->setBypass(!bypass);
			if (FMOD_OK != _result) {
				fprintf(stderr, "Unable to set bypass!\n");
			}

		}
		else if (vKey) {
			bool bypass = false;
			_result = _dspLowpass->getBypass(&bypass);
			if (FMOD_OK != _result) {
				fprintf(stderr, "Unable to get bypass!\n");
			}
			_result = _dspLowpass->setBypass(!bypass);
			if (FMOD_OK != _result) {
				fprintf(stderr, "Unable to set bypass!\n");
			}
		}
	}
	else if (key == GLFW_KEY_7 && action == GLFW_PRESS) {
		if (zKey) {
			bool bypass = false;
			_result = _dspHighpass->getBypass(&bypass);
			if (FMOD_OK != _result) {
				fprintf(stderr, "Unable to get bypass!\n");
			}
			_result = _dspHighpass->setBypass(!bypass);
			if (FMOD_OK != _result) {
				fprintf(stderr, "Unable to set bypass!\n");
			}
		}
		else if (xKey) {
			bool bypass = false;
			_result = _dspNormalize->getBypass(&bypass);
			if (FMOD_OK != _result) {
				fprintf(stderr, "Unable to get bypass!\n");
			}
			_result = _dspNormalize->setBypass(!bypass);
			if (FMOD_OK != _result) {
				fprintf(stderr, "Unable to set bypass!\n");
			}

		}
		else if (cKey) {
			bool bypass = false;
			_result = _dspLimiter->getBypass(&bypass);
			if (FMOD_OK != _result) {
				fprintf(stderr, "Unable to get bypass!\n");
			}
			_result = _dspLimiter->setBypass(!bypass);
			if (FMOD_OK != _result) {
				fprintf(stderr, "Unable to set bypass!\n");
			}

		}
		else if (vKey) {
			bool bypass = false;
			_result = _dspCompressor->getBypass(&bypass);
			if (FMOD_OK != _result) {
				fprintf(stderr, "Unable to get bypass!\n");
			}
			_result = _dspCompressor->setBypass(!bypass);
			if (FMOD_OK != _result) {
				fprintf(stderr, "Unable to set bypass!\n");
			}
		}
	}
}

void changeBackground(float r, float g, float b) {
	red = r;
	green = g;
	blue = b;
}


void glfw_error_callback(int error, const char* description) {
	fprintf(stderr, "FMOD Error(%d): %s", error, description);
}

void callOption() {
	if (!_isPlaying) {
		//_sampledsound beats for Level 1
		_result = _system->playSound(_soundQuestionSound, _channelGroupOption, false, &_channelQuestion);
		Sleep(1000);
		//_sampledsound beats for Level 1
		_result = _system->playSound(_soundQuestion1Sound, _channelGroupOption, false, &_channelQuestion);
		Sleep(1000);
		//_sampledsound beats for Level 1
		_result = _system->playSound(_soundQuestion2Sound, _channelGroupOption, false, &_channelQuestion);
		Sleep(1000);
		//_sampledsound beats for Level 1
		_result = _system->playSound(_soundQuestion3Sound, _channelGroupOption, false, &_channelQuestion);
		if (_result != FMOD_OK) {
			fprintf(stderr, "unable to play sound");
		}
	}
}

void callOptionLvl2() {
	if (!_isPlaying) {
		//_sampledsound for left side voice
		_result = _system->playSound(_soundLevel2Left, _channelGroupOption, false, &_channelQuestion);
		Sleep(1000);
		//_sampledsound for center voice
		_result = _system->playSound(_soundLevel2Center, _channelGroupOption, false, &_channelQuestion);
		Sleep(1000);
		//_sampledsound for right side voice
		_result = _system->playSound(_soundLevel2Right, _channelGroupOption, false, &_channelQuestion);
		if (_result != FMOD_OK) {
			fprintf(stderr, "unable to play sound");
		}
	}
}

void callOptionLvl3() {
	if (!_isPlaying) {
		//_sampledsound beats for Level 3
		_result = _system->playSound(_soundLevel3Sound, _channelGroupOption, false, &_channelQuestion3);
		//_attrib Reverb is changed
		_channelQuestion3->setReverbProperties(4, 1.0f);

		Sleep(1000);

		_result = _system->playSound(_soundLevel3Sound, _channelGroupOption, false, &_channelQuestion3);
		//_attrib LowpassGain is changed
		_channelQuestion3->setLowPassGain(1.0f);
		Sleep(1000);


		_result = _system->playSound(_soundLevel3Sound, _channelGroupOption, false, &_channelQuestion3);
		_channelQuestion3->setPitch(2.0);

		if (_result != FMOD_OK) {
			fprintf(stderr, "unable to play sound");
		}
	}
}



void incrementAndCheck() {

	if (isStartgame)
	{
		_channelQuestion->isPlaying(&_isPlaying);
	}
	else if (isLevel1)
	{
		_channelQuestion2->isPlaying(&_isPlaying);
	}
	else if (isLevel2)
	{
		_channelQuestion3->isPlaying(&_isPlaying);
	}

	if (!_isPlaying) {
		//_sampledsound click sound when option are clicked
		_result = _system->playSound(_soundClick, 0, false, &_channelQuestion);
		if (_result != FMOD_OK) {
			fprintf(stderr, "unable to play sound");
		}
		count++;
		if (count >= 3) {
			isEndgame = true;
			isStartgame = false;
			isLevel1 = false;
			isLevel2 = false;
			changeBackground(0.341f, 0.0f, 0.023f);
			count = 0;
			_channelStartBgm->stop();

			//_bgm endbgm
			_result = _system->playSound(_soundEndBgm, _channelGroupBGM, false, &_channelStartBgm);
			//_attrib volume attribute is changed
			_channelStartBgm->setVolume(0.09);
			//_sampledsound beats for game lose
			_result = _system->playSound(_soundGameLost, _channelGroupSong, false, &_channelQuestion);
			if (_result != FMOD_OK) {
				fprintf(stderr, "unable to play sound");
			}
		}
	}

}