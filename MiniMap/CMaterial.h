#pragma once;

//�������ɠ����Ѡ��ߠ���ՠ����������
class CMaterial
{
public:
	static int MaterialMode;
	// "����������"����������
	virtual void Apply(void) = 0;
	virtual bool IsTransparent() = 0;
};
