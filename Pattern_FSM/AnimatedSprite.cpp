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
	m_playerIdle = loadTexture("player_idle.png");
	addAnimRects(199, 288, 5, 4);
	//m_playerJump = loadTexture("player_jump_loop.png");
	//addAnimRects(234, 344, 5, 4);

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
	SDL_RenderCopy(&m_renderer, m_playerIdle, &getFrame(getCurrentFrame()), NULL);
}


SDL_Texture * AnimatedSprite::loadTexture(std::string path)
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(&m_renderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;
}
