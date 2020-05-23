#pragma once

#include "CPhongMaterial.h"
#include "CTexture.h"
//�����Ѡ��ߠ�����۠Ѡ����������,������������̠�����Ҡ��������ߠ�Π�����
//�Ѡ���������̠����ɠ�������۠�Π�����ӠGL_MODULATE
class CPhongMaterialWithTexture : public CPhongMaterial
{
private:
	//����������������������
	CTexture *Texture;
public:
	//������������
	CPhongMaterialWithTexture();
	//������������������������������
	void SetTexture(CTexture *tex);
	// "����������"����������
	void Apply(void);
};