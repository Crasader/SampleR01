//
//  TTextureManager.h
//

#ifndef _T_TEXTURE_MANAGER_H_
#define _T_TEXTURE_MANAGER_H_

#include "cocos2d.h"
#include <map>
using namespace std;

typedef std::map<int32_t, cocos2d::Texture2D*> texturemap;

class TTextureManager
{
public:
    TTextureManager();
    virtual ~TTextureManager();

    void addTexture(const texturemap& textures);
    void addTexture(int32_t index, cocos2d::Texture2D* pTexture);
    
protected:
    texturemap _textures;
};

#endif // _T_TEXTURE_MANAGER_H_
