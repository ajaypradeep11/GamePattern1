#include "cLevel.h"

cLevel::cLevel() {
	
}

cLevel::~cLevel() {

}

bool cLevel::playCondition() {
	_result = _system->playSound(_soundStartBgm, _channelGroupBGM, false, &_channelStartBgm);
	_channelStartBgm->setVolume(0.09);
	if (_result != FMOD_OK) {
		fprintf(stderr, "Unable to play sound");
		return false;
	}
} 