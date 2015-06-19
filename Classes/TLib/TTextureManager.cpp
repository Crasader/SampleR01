//
//  TTextureManager.cpp
//

#include "TTextureManager.h"

TTextureManager::TTextureManager()
{
}

TTextureManager::~TTextureManager()
{
}

void TTextureManager::addTexture(const texturemap& textures)
{
    _textures.insert( textures.begin(), textures.end() );
}

void TTextureManager::addTexture(int32_t index, cocos2d::Texture2D* pTexture)
{
    _textures.insert( texturemap::value_type(index, pTexture) );
}
