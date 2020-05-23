#include "CSprite.h"

int CSprite::ScreenWidth = 1024;
int CSprite::ScreenHeight = 768;

CSprite::CSprite(void)
{
	delete[] Data;
};

void CSprite::Load(char *fileName, bool flip)
{
	std::cout << "Load" << std::endl;
	delete[] Data;
	ImageId = ilGenImage();
	ilBindImage(ImageId);
	wchar_t Unicode_String[256];
	wsprintf(Unicode_String, L"%S", fileName);
	bool rezult = ilLoadImage(Unicode_String);
	if (!rezult)std::cout << "file not found " << std::endl;	
	width = ilGetInteger(IL_IMAGE_WIDTH);
	height = ilGetInteger(IL_IMAGE_HEIGHT);
	Data = new ILubyte[width*height * 4];
	ilCopyPixels(0, 0, 0, width, height, 1, IL_RGBA, IL_UNSIGNED_BYTE, Data);
	glGenBuffers(1, &bufferID);
	glBindBuffer(GL_PIXEL_UNPACK_BUFFER, bufferID);
	glBufferData(GL_PIXEL_UNPACK_BUFFER, sizeof(ILubyte)*width*height * 4, Data, GL_STATIC_DRAW);
	glBindBuffer(GL_PIXEL_UNPACK_BUFFER, 0);
	ilDeleteImage(ImageId);
}

int CSprite::GetSpriteWidth(void)
{
	return width;
}

void CSprite::DrawFromLeftUp(int x, int y)
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glWindowPos2i(x, ScreenHeight - height - y);

	// определяем способ выравнивания каждой новой строки (на границу байта)
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glBindBuffer(GL_PIXEL_UNPACK_BUFFER, bufferID);
	glDrawPixels(width, height, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);
	glBindBuffer(GL_PIXEL_UNPACK_BUFFER, 0);
	glDisable(GL_BLEND);
}

void CSprite::DrawFromRightUp(int x, int y)
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glWindowPos2i(ScreenWidth - width - x, ScreenHeight - height - y);

	// определяем способ выравнивания каждой новой строки (на границу байта)
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glBindBuffer(GL_PIXEL_UNPACK_BUFFER, bufferID);
	glDrawPixels(width, height, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);
	glBindBuffer(GL_PIXEL_UNPACK_BUFFER, 0);
	glDisable(GL_BLEND);
}