#include "cLevelThree.h"


bool cLevelThree::playCondition() {
	if (isStartgame) {
		incrementAndCheck();
	}
	else if (isLevel1) {
		_channelQuestion2->isPlaying(&_isPlaying);
		if (!_isPlaying) {
			//Level 2 passed
			isLevel2 = true;
			isLevel1 = false;
			changeBackground(0.074f, 0.0f, 0.360f);
			count = 0;
			_result = _system->playSound(_soundQuestion3, _channelGroupVoice, false, &_channelQuestion3);
			if (_result != FMOD_OK) {
				fprintf(stderr, "unable to play sound");
			}
		}
		count = 0;
	}
	else if (isLevel2) {
		_channelQuestion3->isPlaying(&_isPlaying);
		if (!_isPlaying) {
			//Level 3 passed
			isLevel3 = true;
			isLevel2 = false;
			changeBackground(0.0f, 0.239f, 0.066f);
			count = 0;
			//_sampledsound beats for game won
			_result = _system->playSound(_soundGameWon, _channelGroupSong, false, &_channelQuestion3);
			if (_result != FMOD_OK) {
				fprintf(stderr, "unable to play sound");
			}
		}
		count = 0;
	}

	return true;
}