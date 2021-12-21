#include "globalThings.h"

#include "cReadWrite.h"

void initializeSound() 
{

		_system = NULL;
		_result = FMOD::System_Create(&_system);
		if (_result != FMOD_OK) {
			fprintf(stderr, "Unable to create FMOD system");
			
		}
		_result = _system->init(32, FMOD_INIT_NORMAL, NULL);
		if (_result != FMOD_OK) {
			fprintf(stderr, "Unable to initialize FMOD system");
			
		}
	


};


void assignSound() {
	cReadWrite readWrite;

	//Create groups
	_result = _system->createChannelGroup("Group BGM", &_channelGroupBGM);
	if (_result != FMOD_OK) {
		fprintf(stderr, "Unable to create channel group");
	}

	_result = _system->createChannelGroup("Group Voice", &_channelGroupVoice);
	if (_result != FMOD_OK) {
		fprintf(stderr, "Unable to create channel group");
	}

	_result = _system->createChannelGroup("Group Option", &_channelGroupOption);
	if (_result != FMOD_OK) {
		fprintf(stderr, "Unable to create channel group");
	}

	_result = _system->createChannelGroup("Group Song", &_channelGroupSong);
	if (_result != FMOD_OK) {
		fprintf(stderr, "Unable to create channel group");
	}

	//Get master channel
	_result = _system->getMasterChannelGroup(&_channelGroupMaster);
	if (_result != FMOD_OK) {
		fprintf(stderr, "Unable to get master channel group");
	}


	//AudioBGM text file
	_audioBGM = readWrite.getSoundFromFile("audioBGM.txt");
	std::stringstream bgm[4];
	for (int i = 0; i < _audioBGM.size(); i++) {
		//_file using external
		bgm[i] << SOLUTION_DIR << "common\\assets\\audio\\" << _audioBGM.at(i);
	}
	_result = _system->createSound(bgm[0].str().c_str(), FMOD_LOOP_NORMAL, 0, &_soundStartBgm);
	_result = _system->createSound(bgm[1].str().c_str(), FMOD_LOOP_NORMAL, 0, &_soundMidBgm);
	_result = _system->createSound(bgm[2].str().c_str(), FMOD_LOOP_NORMAL, 0, &_soundEndBgm);


	/*LEVEL 1 starts*/
	//AudioQuestion LEVEL 1 text file
	_audioQuestionLevel1 = readWrite.getSoundFromFile("audioQuestionLevel1.txt");
	std::stringstream questionsLevel1[4];
	for (int i = 0; i < _audioQuestionLevel1.size(); i++) {
		//_file using external
		questionsLevel1[i] << SOLUTION_DIR << "common\\assets\\audio\\" << _audioQuestionLevel1.at(i);
	}
	_result = _system->createSound(questionsLevel1[0].str().c_str(), FMOD_LOOP_OFF, 0, &_soundQuestionSound);
	_result = _system->createSound(questionsLevel1[1].str().c_str(), FMOD_LOOP_OFF, 0, &_soundQuestion1Sound);
	_result = _system->createSound(questionsLevel1[2].str().c_str(), FMOD_LOOP_OFF, 0, &_soundQuestion2Sound);
	_result = _system->createSound(questionsLevel1[3].str().c_str(), FMOD_LOOP_OFF, 0, &_soundQuestion3Sound);
	/*LEVEL 1 ends*/


	/*LEVEL 2 and 3 starts*/
	//AudioQuestion LEVEL 2 and LEVEL 3 text file
	_audioQuestionLevel2and3 = readWrite.getSoundFromFile("audioQuestionLevel2and3.txt");
	std::stringstream questionLevel2and3[2];
	for (int i = 0; i < _audioQuestionLevel2and3.size(); i++) {
		//_file using external
		questionLevel2and3[i] << SOLUTION_DIR << "common\\assets\\audio\\" << _audioQuestionLevel2and3.at(i);
	}
	_result = _system->createSound(questionLevel2and3[0].str().c_str(), FMOD_LOOP_OFF, 0, &_soundLevel2Sound);
	_result = _system->createSound(questionLevel2and3[1].str().c_str(), FMOD_LOOP_OFF, 0, &_soundLevel3Sound);
	/*LEVEL 2 and 3 ends*/


	/*Automated sound starts*/
	//Audio for automated sound
	_audioAutomatedSound = readWrite.getSoundFromFile("audioAutomatedSound.txt");
	std::stringstream audioAutomatedSound[7];
	for (int i = 0; i < _audioAutomatedSound.size(); i++) {
		//_file using external
		audioAutomatedSound[i] << SOLUTION_DIR << "common\\assets\\audio\\" << _audioAutomatedSound.at(i);
	}
	_result = _system->createSound(audioAutomatedSound[0].str().c_str(), FMOD_LOOP_OFF, 0, &_soundLevel2Left);
	_result = _system->createSound(audioAutomatedSound[1].str().c_str(), FMOD_LOOP_OFF, 0, &_soundLevel2Center);
	_result = _system->createSound(audioAutomatedSound[2].str().c_str(), FMOD_LOOP_OFF, 0, &_soundLevel2Right);
	_result = _system->createSound(audioAutomatedSound[3].str().c_str(), FMOD_LOOP_OFF, 0, &_soundClick);
	_result = _system->createSound(audioAutomatedSound[4].str().c_str(), FMOD_LOOP_OFF, 0, &_soundQuestion1);
	_result = _system->createSound(audioAutomatedSound[5].str().c_str(), FMOD_LOOP_OFF, 0, &_soundQuestion2);
	_result = _system->createSound(audioAutomatedSound[6].str().c_str(), FMOD_LOOP_OFF, 0, &_soundQuestion3);
	/*Automated sound ends*/



	/*Game win or lose starts*/
	//Audio for game won/lose
	_audioGameWonOrLose = readWrite.getSoundFromFile("audioGameWonOrLose.txt");
	std::stringstream audioGameWonOrLose[2];
	for (int i = 0; i < _audioGameWonOrLose.size(); i++) {
		//_file using external
		audioGameWonOrLose[i] << SOLUTION_DIR << "common\\assets\\audio\\" << _audioGameWonOrLose.at(i);
	}
	_result = _system->createSound(audioGameWonOrLose[1].str().c_str(), FMOD_LOOP_OFF, 0, &_soundGameLost);
	_result = _system->createSound(audioGameWonOrLose[0].str().c_str(), FMOD_LOOP_OFF, 0, &_soundGameWon);
	/*Game win or lose ends*/

}