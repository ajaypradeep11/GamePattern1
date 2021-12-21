#include "cLevelOne.h"


bool cLevelOne::playCondition() {
	//When game is entered, this snippet is called
	if (!_isGameEntered) {
		changeBackground(0.15f, 0.15f, 0.15f);
		_isGameEntered = true;
		isStartgame = true;
		_channelStartBgm->stop();

		//_bgm midbgm
		//_soundMidBgm is called as that is the bgm for level1
		_result = _system->playSound(_soundMidBgm, _channelGroupBGM, false, &_channelStartBgm);
		_channelStartBgm->setVolume(0.09);
		if (_result != FMOD_OK) {
			fprintf(stderr, "unable to play sound");
		}

		//_soundQuestion1 is called as that is the automated voice for level1 question
		_result = _system->playSound(_soundQuestion1, _channelGroupVoice, false, &_channelQuestion);
		if (_result != FMOD_OK) {
			fprintf(stderr, "unable to play sound");
		}
	}

	return true;
}