#include "ResourceManager.h"


Snake::ResourceManager::ResourceManager()
{
	loadFonts();
	loadStyles();
}

Snake::ResourceManager::ResourceManager(const ResourceManager &)
{

}

Snake::ResourceManager::~ResourceManager()
{
	mTextures.clear();
	mFonts.clear();
	mThemes.clear();
}

Snake::ResourceManager & Snake::ResourceManager::getInstance()
{
	static ResourceManager instance;
	return instance;
}

void Snake::ResourceManager::loadFonts()
{
	if (!mArial.loadFromFile("Resources/fonts/arial.ttf"))
		EXIT_FAILURE;

	mFonts["arial"] = mArial;
}

void Snake::ResourceManager::loadStyles()
{
	mThemes["menuButton"]      = Snake::GuiStyle({ { "background",          sf::Color(255, 255, 255, 60) },
	                                               { "backgroundHighlight", sf::Color(255, 255, 255, 255) },
	                                               { "text",                sf::Color(255, 255, 255, 255) },
	                                               { "textHighlight",       sf::Color(152, 181, 5, 255) } });
	//////////////////////////////////////////////////////////////////////////////////////////////////
	mThemes["playAgainButton"] = Snake::GuiStyle({ { "background",          sf::Color(55, 55, 55, 255) },
	                                               { "backgroundHighlight", sf::Color(255, 255, 255, 255) },
	                                               { "text",                sf::Color(255, 255, 255, 255) },
	                                               { "textHighlight",       sf::Color(55, 55, 55, 255) } });
	//////////////////////////////////////////////////////////////////////////////////////////////////
	mThemes["board"]           = Snake::GuiStyle({ { "background",          sf::Color(239, 224, 177, 255) },
	                                               { "wallColor",           sf::Color(227, 195, 157, 255) } });
	//////////////////////////////////////////////////////////////////////////////////////////////////
	mThemes["snake"]           = Snake::GuiStyle({ { "headColor",           sf::Color(39, 174, 96, 255) },
	                                               { "bodyColor",           sf::Color(135, 211, 124, 255) } });
	//////////////////////////////////////////////////////////////////////////////////////////////////
	mThemes["score"]           = Snake::GuiStyle({ { "title",               sf::Color(255, 255, 255, 255) },
	                                               { "text",                sf::Color(135, 211, 124, 255) } });
	//////////////////////////////////////////////////////////////////////////////////////////////////
	mThemes["inGameMenu"]      = Snake::GuiStyle({ { "background",          sf::Color(147, 177, 3, 255) },
	                                               { "text",                sf::Color(135, 211, 124, 255) } });
	//////////////////////////////////////////////////////////////////////////////////////////////////
	mThemes["instructions"]    = Snake::GuiStyle({ { "text",                sf::Color(0, 0, 0, 255) } });
	//////////////////////////////////////////////////////////////////////////////////////////////////
	mThemes["gameOver"]        = Snake::GuiStyle({ { "title",               sf::Color(50, 50, 50, 255) },
						       { "score",               sf::Color(202, 105, 36, 255) } });
}

bool Snake::ResourceManager::isTextureLoaded(const std::string & filename) const
{
	return mTextures.count(filename) != 0;
}

sf::Texture & Snake::ResourceManager::getTexture(const std::string & filename)
{
	if (!isTextureLoaded(filename))
	{
		sf::Texture texture;

		if (!texture.loadFromFile("Resources/textures/" + filename))
			EXIT_FAILURE;

		mTextures[filename] = texture;
	}

	return mTextures[filename];

}

sf::Font & Snake::ResourceManager::getFont(const std::string & name)
{
	return mFonts[name];
}

Snake::GuiStyle & Snake::ResourceManager::getTheme(const std::string & name)
{
	return mThemes[name];
}
