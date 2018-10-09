#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <vector>

class AnimatedSprite
{
public:
	AnimatedSprite(SDL_Renderer& renderer);
	~AnimatedSprite();

	const std::vector<SDL_Rect>& getFrames();
	const SDL_Rect& getFrame(int frameNr);
	void addFrame(SDL_Rect&);
	const int getCurrentFrame();
	void clearVector();
	SDL_Texture* loadTexture(std::string path);
	void update();
	void draw();
	void addAnimRects(int width, int height, int framesWidth, int framesHeight);
	void setCurrentTexture(SDL_Texture& texture);


private:
	std::vector<SDL_Rect> m_frames;
	int m_currentFrame;
	Uint32 m_currentTime;
	Uint32 m_lastTime;
	Uint32 m_deltaTime;
	Uint32 m_framePerSec;

	Uint32 m_timePlayingFrame;

	SDL_Renderer& m_renderer;
	SDL_Texture* m_currentTexture;
};

