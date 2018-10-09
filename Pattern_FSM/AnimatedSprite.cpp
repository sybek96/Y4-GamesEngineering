#include "AnimatedSprite.h"



AnimatedSprite::AnimatedSprite(SDL_Renderer& renderer)
	: m_currentTime(0)
	, m_currentFrame(0)
	, m_lastTime(0)
	, m_framePerSec(130)
	, m_timePlayingFrame(0)
	, m_deltaTime(0)
	, m_renderer(renderer)
{
}

void AnimatedSprite::addAnimRects(int width, int height, int framesWidth, int framesHeight)
{
	m_frames.clear();

	SDL_Rect textRect;
	textRect.w = width;
	textRect.h = height;

	for (int x = 0; x < (width * framesWidth); x += width)
	{
		for (int y = 0; y < (height * framesHeight); y += height)
		{
			textRect.x = x; textRect.y = y;
			addFrame(textRect);
		}
	}
}

void AnimatedSprite::setCurrentTexture(SDL_Texture & texture)
{
	m_currentTexture = &texture;
}


AnimatedSprite::~AnimatedSprite()
{
}

const std::vector<SDL_Rect>& AnimatedSprite::getFrames()
{
	// TODO: insert return statement here
	return m_frames;
}

const SDL_Rect & AnimatedSprite::getFrame(int frameNr)
{
	// TODO: insert return statement here
	return m_frames[frameNr];
}

void AnimatedSprite::addFrame(SDL_Rect & frame)
{
	m_frames.push_back(frame);
}

const int AnimatedSprite::getCurrentFrame()
{
	return m_currentFrame;
}

void AnimatedSprite::clearVector()
{
	m_frames.clear();
}

void AnimatedSprite::update()
{
	m_currentTime = SDL_GetTicks();
	m_deltaTime = m_currentTime - m_lastTime;
	m_lastTime = m_currentTime;

	m_timePlayingFrame += m_deltaTime;
	if (m_timePlayingFrame > m_framePerSec)
	{
		if (m_frames.size() > m_currentFrame + 1)
		{
			m_currentFrame++;
		}
		else
		{
			m_currentFrame = 0;
		}
		m_timePlayingFrame = 0;
	}
}

void AnimatedSprite::draw()
{
	SDL_RenderCopy(&m_renderer, m_currentTexture, &getFrame(getCurrentFrame()), NULL);
}



