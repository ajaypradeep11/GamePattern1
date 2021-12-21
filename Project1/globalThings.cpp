#include "globalThings.h"

bool _isPaused = false;
bool _isPlaying = false;
bool _isGameEntered = false;
bool isStartgame = false;
bool isEndgame = false;
bool isLevel1 = false;
bool isLevel2 = false;
bool isLevel3 = false;

bool zKey = false;
bool xKey = false;
bool cKey = false;
bool vKey = false;

float red = 0.0f;
float blue = 0.0f;
float green = 0.0f;

//Sound variable for Background music
FMOD::Sound* _soundStartBgm = NULL;
FMOD::Sound* _soundMidBgm = NULL;
FMOD::Sound* _soundEndBgm = NULL;

//Sound variable for Game won or lose
FMOD::Sound* _soundGameWon = NULL;
FMOD::Sound* _soundGameLost = NULL;

//Sound variable for automated question sound
FMOD::Sound* _soundQuestion1 = NULL;
FMOD::Sound* _soundQuestion2 = NULL;
FMOD::Sound* _soundQuestion3 = NULL;

//Sound variable for click sound when clicking options
FMOD::Sound* _soundClick = NULL;

//LEVEL 1
//Sound variable for LEVEL 1 questions options
FMOD::Sound* _soundQuestionSound = NULL;
FMOD::Sound* _soundQuestion1Sound = NULL;
FMOD::Sound* _soundQuestion2Sound = NULL;
FMOD::Sound* _soundQuestion3Sound = NULL;

//LEVEL 2
//Sound variable for LEVEL 2 question sound
FMOD::Sound* _soundLevel2Sound = NULL;

//Sound variable for automated sound LEVEL 2 answer
FMOD::Sound* _soundLevel2Left = NULL;
FMOD::Sound* _soundLevel2Center = NULL;
FMOD::Sound* _soundLevel2Right = NULL;

//LEVEL 3
//Sound variable for automated sound LEVEL 3 question and answer
FMOD::Sound* _soundLevel3Sound = NULL;

//Channel for sounds
FMOD::Channel* _channel = NULL;
FMOD::Channel* _channelStartBgm = NULL;
FMOD::Channel* _channelQuestion = NULL;
FMOD::Channel* _channelQuestion2 = NULL;
FMOD::Channel* _channelQuestion3 = NULL;


FMOD::ChannelGroup* _channelGroupBGM = nullptr;

FMOD::ChannelGroup* _channelGroupVoice = nullptr;

FMOD::ChannelGroup* _channelGroupOption = nullptr;

FMOD::ChannelGroup* _channelGroupSong = nullptr;

FMOD::ChannelGroup* _channelGroupMaster = nullptr;

FMOD::ChannelGroup* _selectedChannelGroup = nullptr;

//To check whether the max attempts is 3. if greater than 3, then gameover.
int count = 0;
FMOD::System* _system = NULL;

char _buffer[255];
//To get audio from filelist
std::vector<std::string> _audioList;
std::vector<std::string> _audioBGM;
std::vector<std::string> _audioQuestionLevel1;
std::vector<std::string> _audioQuestionLevel2and3;
std::vector<std::string> _audioAutomatedSound;
std::vector<std::string> _audioGameWonOrLose;

FMOD_RESULT _result = FMOD_OK;

FMOD::DSP* _dspEcho = nullptr;
FMOD::DSP* _dspFlange = nullptr;
FMOD::DSP* _dspDistortion = nullptr;
FMOD::DSP* _dspChorus = nullptr;
FMOD::DSP* _dspDelay = nullptr;
FMOD::DSP* _dspTremolo = nullptr;
FMOD::DSP* _dspPan = nullptr;
FMOD::DSP* _dspConvolutionreverb = nullptr;
FMOD::DSP* _dspObjectpan = nullptr;
FMOD::DSP* _dspOscillator = nullptr;
FMOD::DSP* _dspFader = nullptr;
FMOD::DSP* _dspLowpass = nullptr;
FMOD::DSP* _dspHighpass = nullptr;
FMOD::DSP* _dspNormalize = nullptr;
FMOD::DSP* _dspLimiter = nullptr;
FMOD::DSP* _dspCompressor = nullptr;
