#pragma once;

// БАЗОВЫЙ КЛАСС ДЛЯ ВСЕХ МАТЕРИАЛОВ
class CMaterial
{
public:
	static int MaterialMode;
	// "применение" материала
	virtual void Apply(void) = 0;
	virtual bool IsTransparent() = 0;
};
