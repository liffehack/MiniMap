#pragma once

#include "CPhongMaterial.h"
#include "CTexture.h"
// КЛАСС ДЛЯ РАБОТЫ С МАТЕРИАЛОМ, ИСПОЛЬЗУЮЩИМ РАСЧЕТ ОСВЕЩЕНИЯ ПО ФОНГУ
// С НАЛОЖЕНИЕМ ОДНОЙ ТЕКСТУРЫ ПО МЕТОДУ GL_MODULATE
class CPhongMaterialWithTexture : public CPhongMaterial
{
private:
	// используемая текстура
	CTexture *Texture;
public:
	// конструктор 
	CPhongMaterialWithTexture();
	// установка используемой текстуры
	void SetTexture(CTexture *tex);
	// "применение" материала
	void Apply(void);
};