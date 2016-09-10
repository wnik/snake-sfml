#pragma once
#include <unordered_map>
#include "GuiStyle.h"

namespace Snake {
	class ResourceManager
	{
	private:

		ResourceManager();
		ResourceManager(const ResourceManager &);
		~ResourceManager();

		void loadFonts();
		void loadStyles();
		bool isTextureLoaded(const std::string & filename) const;

		std::unordered_map<std::string, sf::Texture > mTextures;
		std::unordered_map<std::string, sf::Font>     mFonts;
		std::unordered_map<std::string, GuiStyle>     mThemes;
		sf::Font                                      mArial;
	
	public:

		static ResourceManager & getInstance();
		sf::Texture            & getTexture(const std::string & filename);
		sf::Font               & getFont(const std::string & name);
		GuiStyle               & getTheme(const std::string & name);

	};
}