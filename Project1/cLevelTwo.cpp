#include "cLevelTwo.h"


bool cLevelTwo::playCondition() {
	if (isStartgame) {
		_channelQuestion->isPlaying(&_isPlaying);
		if (!_isPlaying) {
			//Level 1 passed
			isLevel1 = true;
			isStartgame = false;
			changeBackground(0.360f, 0.227f, 0.0f);
			_result = _system->playSound(_soundQuestion2, _channelGroupVoice, false, &_channelQuestion2);
			if (_result != FMOD_OK) {
				fprintf(stderr, "unable to play sound");
			}
		}
		count = 0;
	}
	else if (isLevel1) {
		incrementAndCheck();
	}
	else if (isLevel2) {
		incrementAndCheck();
	}

	return true;
}