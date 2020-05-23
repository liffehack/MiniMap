#include "CPhongMaterialWithTex.h"

CPhongMaterialWithTexture::CPhongMaterialWithTexture()
{
	Texture = NULL;
}

void CPhongMaterialWithTexture::SetTexture(CTexture *tex)
{
	this->Texture = tex;
}

void CPhongMaterialWithTexture::Apply()
{
	CPhongMaterial::Apply();

	if (Texture)
	{
		glActiveTexture(GL_TEXTURE0);
		glEnable(GL_TEXTURE_2D);
		Texture->Apply();
	}
}