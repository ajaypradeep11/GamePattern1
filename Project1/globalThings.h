#pragma once
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <FMOD/fmod.hpp>
#include <vector>
#include <string>
#include <Windows.h>

extern bool _isPaused;
extern bool _isPlaying;
extern bool _isGameEntered;
extern bool isStartgame;
extern bool isEndgame;
extern bool isLevel1;
extern bool isLevel2;
extern bool isLevel3;

extern bool zKey;
extern bool xKey;
extern bool cKey;
extern bool vKey;

extern float red;
extern float blue;
extern float green;

extern int count;

extern char _buffer[];

extern FMOD::System* _system;
extern FMOD_RESULT _result;

//Sound variable for Background music
extern FMOD::Sound* _soundStartBgm;
extern FMOD::Sound* _soundMidBgm;
extern FMOD::Sound* _soundEndBgm;

//Sound variable for Game won or lose
extern FMOD::Sound* _soundGameWon;
extern FMOD::Sound* _soundGameLost;

//Sound variable for automated question sound
extern FMOD::Sound* _soundQuestion1;
extern FMOD::Sound* _soundQuestion2;
extern FMOD::Sound* _soundQuestion3;

//Sound variable for click sound when clicking options
extern FMOD::Sound* _soundClick;

//LEVEL 1
//Sound variable for LEVEL 1 questions options
extern FMOD::Sound* _soundQuestionSound;
extern FMOD::Sound* _soundQuestion1Sound;
extern FMOD::Sound* _soundQuestion2Sound;
extern FMOD::Sound* _soundQuestion3Sound;

//LEVEL 2
//Sound variable for LEVEL 2 question sound
extern FMOD::Sound* _soundLevel2Sound;

//Sound variable for automated sound LEVEL 2 answer
extern FMOD::Sound* _soundLevel2Left;
extern FMOD::Sound* _soundLevel2Center;
extern FMOD::Sound* _soundLevel2Right;

//LEVEL 3
//Sound variable for automated sound LEVEL 3 question and answer
extern FMOD::Sound* _soundLevel3Sound;

//Channel for sounds
extern FMOD::Channel* _channel;
extern FMOD::Channel* _channelStartBgm;
extern FMOD::Channel* _channelQuestion;
extern FMOD::Channel* _channelQuestion2;
extern FMOD::Channel* _channelQuestion3;

extern FMOD::ChannelGroup* _channelGroupBGM;
extern FMOD::ChannelGroup* _channelGroupVoice;
extern FMOD::ChannelGroup* _channelGroupOption;
extern FMOD::ChannelGroup* _channelGroupSong;
extern FMOD::ChannelGroup* _channelGroupMaster;
extern FMOD::ChannelGroup* _selectedChannelGroup;

extern FMOD::DSP* _dspEcho;
extern FMOD::DSP* _dspFlange;
extern FMOD::DSP* _dspDistortion;
extern FMOD::DSP* _dspChorus;
extern FMOD::DSP* _dspDelay;
extern FMOD::DSP* _dspTremolo;
extern FMOD::DSP* _dspPan;
extern FMOD::DSP* _dspConvolutionreverb;
extern FMOD::DSP* _dspObjectpan;
extern FMOD::DSP* _dspOscillator;
extern FMOD::DSP* _dspFader;
extern FMOD::DSP* _dspLowpass;
extern FMOD::DSP* _dspHighpass;
extern FMOD::DSP* _dspNormalize;
extern FMOD::DSP* _dspLimiter;
extern FMOD::DSP* _dspCompressor;

extern std::vector<std::string> _audioList;
extern std::vector<std::string> _audioBGM;
extern std::vector<std::string> _audioQuestionLevel1;
extern std::vector<std::string> _audioQuestionLevel2and3;
extern std::vector<std::string> _audioAutomatedSound;
extern std::vector<std::string> _audioGameWonOrLose;

void changeBackground(float r, float g , float b);
void glfw_key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void glfw_error_callback(int error, const char* description);
void incrementAndCheck();
void callOptionLvl3();
void callOptionLvl2();
void callOption();


void initializeSound();
void assignSound();