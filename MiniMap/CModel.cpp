#include "CModel.h"
#include <iostream>
using namespace std;

//bool CModel::VBO_Use = true;
bool CModel::USING_NORMALS = true;

CModel::CModel()
{
	IndexCount = 0;
}
CModel::~CModel()
{
	delete[] Points;
	Points = 0;
	delete[] Indeces;
	Indeces = 0;
}
void CModel::CreateBox(GLfloat Width, GLfloat Length, GLfloat Height)
{
	Points = new ModelPoint[24];
	Points[0].Coord[0] = -(Width / 2);		Points[0].Coord[1] = (Height / 2);				Points[0].Coord[2] = (Length / 2);
	Points[0].Color[0] = 255;				Points[0].Color[1] = 0;							Points[0].Color[2] = 0;
	Points[0].Normal[0] = 0.0;				Points[0].Normal[1] = 0.0;						Points[0].Normal[2] = 1.0;
	//Points[0].TexCoord[0] = ;				Points[0].TexCoord[1] = ;
	Points[1].Coord[0] = (Width / 2);		Points[1].Coord[1] = (Height / 2);				Points[1].Coord[2] = (Length / 2);
	Points[1].Color[0] = 255;				Points[1].Color[1] = 0;							Points[1].Color[2] = 0;
	Points[1].Normal[0] = 0.0;				Points[1].Normal[1] = 0.0;						Points[1].Normal[2] = 1.0;
	//Points[1].TexCoord[0] = ;				Points[1].TexCoord[1] = ;
	Points[2].Coord[0] = -(Width / 2);		Points[2].Coord[1] = -(Height / 2);				Points[2].Coord[2] = (Length / 2);
	Points[2].Color[0] = 255;				Points[2].Color[1] = 0;							Points[2].Color[2] = 0;
	Points[2].Normal[0] = 0.0;				Points[2].Normal[1] = 0.0;						Points[2].Normal[2] = 1.0;
	//Points[2].TexCoord[0] = ;				Points[2].TexCoord[1] = ;
	Points[3].Coord[0] = (Width / 2);		Points[3].Coord[1] = -(Height / 2);				Points[3].Coord[2] = (Length / 2);
	Points[3].Color[0] = 255;				Points[3].Color[1] = 0;							Points[3].Color[2] = 0;
	Points[3].Normal[0] = 0.0;				Points[3].Normal[1] = 0.0;						Points[3].Normal[2] = 1.0;
	//Points[3].TexCoord[0] = ;				Points[3].TexCoord[1] = ;

	Points[4].Coord[0] = Points[1].Coord[0]; Points[4].Coord[1] = Points[1].Coord[1];		Points[4].Coord[2] = Points[1].Coord[2];
	Points[4].Color[0] = 0;					Points[4].Color[1] = 0;							Points[4].Color[2] = 255;
	Points[4].Normal[0] = 1.0;				Points[4].Normal[1] = 0.0;						Points[4].Normal[2] = 0.0;
	//Points[4].TexCoord[0] = ;				Points[4].TexCoord[1] = ;
	Points[5].Coord[0] = (Width / 2);		Points[5].Coord[1] = (Height / 2);				Points[5].Coord[2] = -(Length / 2);
	Points[5].Color[0] = 0;					Points[5].Color[1] = 0;							Points[5].Color[2] = 255;
	Points[5].Normal[0] = 1.0;				Points[5].Normal[1] = 0.0;						Points[5].Normal[2] = 0.0;
	//Points[5].TexCoord[0] = ;				Points[5].TexCoord[1] = ;
	Points[6].Coord[0] = Points[3].Coord[0]; Points[6].Coord[1] = Points[3].Coord[1];		Points[6].Coord[2] = Points[3].Coord[2];
	Points[6].Color[0] = 0;					Points[6].Color[1] = 0;							Points[6].Color[2] = 255;
	Points[6].Normal[0] = 1.0;				Points[6].Normal[1] = 0.0;						Points[6].Normal[2] = 0.0;
	//Points[6].TexCoord[0] = ;				Points[6].TexCoord[1] = ;
	Points[7].Coord[0] = (Width / 2);		Points[7].Coord[1] = -(Height / 2);				Points[7].Coord[2] = -(Length / 2);
	Points[7].Color[0] = 0;					Points[7].Color[1] = 0;							Points[7].Color[2] = 255;
	Points[7].Normal[0] = 1.0;				Points[7].Normal[1] = 0.0;						Points[7].Normal[2] = 0.0;
	//Points[7].TexCoord[0] = ;				Points[7].TexCoord[1] = ;

	Points[8].Coord[0] = Points[5].Coord[0];	Points[8].Coord[1] = Points[5].Coord[1];	Points[8].Coord[2] = Points[5].Coord[2];
	Points[8].Color[0] = 0;						Points[8].Color[1] = 255;					Points[8].Color[2] = 0;
	Points[8].Normal[0] = 0.0;					Points[8].Normal[1] = 0.0;					Points[8].Normal[2] = -1.0;
	//Points[8].TexCoord[0] = ;					Points[8].TexCoord[1] = ;
	Points[9].Coord[0] = -(Width / 2);			Points[9].Coord[1] = (Height / 2);			Points[9].Coord[2] = -(Length / 2);
	Points[9].Color[0] = 0;						Points[9].Color[1] = 255;					Points[9].Color[2] = 0;
	Points[9].Normal[0] = 0.0;					Points[9].Normal[1] = 0.0;					Points[9].Normal[2] = -1.0;
	//Points[0].TexCoord[9] = ;					Points[9].TexCoord[1] = ;
	Points[10].Coord[0] = Points[7].Coord[0];	Points[10].Coord[1] = Points[7].Coord[1];	Points[10].Coord[2] = Points[7].Coord[2];
	Points[10].Color[0] = 0;					Points[10].Color[1] = 255;					Points[10].Color[2] = 0;
	Points[10].Normal[0] = 0.0;					Points[10].Normal[1] = 0.0;					Points[10].Normal[2] = -1.0;
	//Points[10].TexCoord[0] = ;					Points[10].TexCoord[1] = ;
	Points[11].Coord[0] = -(Width / 2);			Points[11].Coord[1] = -(Height / 2);		Points[11].Coord[2] = -(Length / 2);
	Points[11].Color[0] = 0;					Points[11].Color[1] = 255;					Points[11].Color[2] = 0;
	Points[11].Normal[0] = 0.0;					Points[11].Normal[1] = 0.0;					Points[11].Normal[2] = -1.0;
	//Points[11].TexCoord[0] = ;					Points[11].TexCoord[1] = ;

	Points[12].Coord[0] = Points[9].Coord[0];	Points[12].Coord[1] = Points[9].Coord[1];	Points[12].Coord[2] = Points[9].Coord[2];
	Points[12].Color[0] = 255;					Points[12].Color[1] = 0;					Points[12].Color[2] = 255;
	Points[12].Normal[0] = -1.0;				Points[12].Normal[1] = 0.0;					Points[12].Normal[2] = 0.0;
	//Points[12].TexCoord[0] = ;					Points[12].TexCoord[1] = ;
	Points[13].Coord[0] = Points[0].Coord[0];	Points[13].Coord[1] = Points[0].Coord[1];	Points[13].Coord[2] = Points[0].Coord[2];
	Points[13].Color[0] = 255;					Points[13].Color[1] = 0;					Points[13].Color[2] = 255;
	Points[13].Normal[0] = -1.0;				Points[13].Normal[1] = 0.0;					Points[13].Normal[2] = 0.0;
	//Points[13].TexCoord[0] = ;					Points[13].TexCoord[1] = ;
	Points[14].Coord[0] = Points[11].Coord[0];	Points[14].Coord[1] = Points[11].Coord[1];	Points[14].Coord[2] = Points[11].Coord[2];
	Points[14].Color[0] = 255;					Points[14].Color[1] = 0;					Points[14].Color[2] = 255;
	Points[14].Normal[0] = -1.0;				Points[14].Normal[1] = 0.0;					Points[14].Normal[2] = 0.0;
	//Points[14].TexCoord[0] = ;					Points[14].TexCoord[1] = ;
	Points[15].Coord[0] = Points[2].Coord[0];	Points[15].Coord[1] = Points[2].Coord[1];	Points[15].Coord[2] = Points[2].Coord[2];
	Points[15].Color[0] = 255;					Points[15].Color[1] = 0;					Points[15].Color[2] = 255;
	Points[15].Normal[0] = -1.0;				Points[15].Normal[1] = 0.0;					Points[15].Normal[2] = 0.0;
	//Points[15].TexCoord[0] = ;					Points[15].TexCoord[1] = ;

	Points[16].Coord[0] = Points[2].Coord[0];	Points[16].Coord[1] = Points[2].Coord[1];	Points[16].Coord[2] = Points[2].Coord[2];
	Points[16].Color[0] = 0;					Points[16].Color[1] = 255;					Points[16].Color[2] = 255;
	Points[16].Normal[0] = 0.0;					Points[16].Normal[1] = -1.0;				Points[16].Normal[2] = 0.0;
	//Points[16].TexCoord[0] = ;				Points[16].TexCoord[1] = ;
	Points[17].Coord[0] = Points[3].Coord[0];	Points[17].Coord[1] = Points[3].Coord[1];	Points[17].Coord[2] = Points[3].Coord[2];
	Points[17].Color[0] = 0;					Points[17].Color[1] = 255;					Points[17].Color[2] = 255;
	Points[17].Normal[0] = 0.0;					Points[17].Normal[1] = -1.0;				Points[17].Normal[2] = 0.0;
	Points[18].Coord[0] = Points[7].Coord[0];	Points[18].Coord[1] = Points[7].Coord[1];	Points[18].Coord[2] = Points[7].Coord[2];
	Points[18].Color[0] = 0;					Points[18].Color[1] = 255;					Points[18].Color[2] = 255;
	Points[18].Normal[0] = 0.0;					Points[18].Normal[1] = -1.0;				Points[18].Normal[2] = 0.0;
	Points[19].Coord[0] = Points[11].Coord[0];	Points[19].Coord[1] = Points[11].Coord[1];	Points[19].Coord[2] = Points[11].Coord[2];
	Points[19].Color[0] = 0;					Points[19].Color[1] = 255;					Points[19].Color[2] = 255;
	Points[19].Normal[0] = 0.0;					Points[19].Normal[1] = -1.0;				Points[19].Normal[2] = 0.0;

	Points[20].Coord[0] = Points[0].Coord[0];	Points[20].Coord[1] = Points[0].Coord[1];	Points[20].Coord[2] = Points[0].Coord[2];
	Points[20].Color[0] = 255;					Points[20].Color[1] = 255;					Points[20].Color[2] = 0;
	Points[20].Normal[0] = 0.0;					Points[20].Normal[1] = 1.0;					Points[20].Normal[2] = 0.0;
	Points[21].Coord[0] = Points[1].Coord[0];	Points[21].Coord[1] = Points[1].Coord[1];	Points[21].Coord[2] = Points[1].Coord[2];
	Points[21].Color[0] = 255;					Points[21].Color[1] = 255;					Points[21].Color[2] = 0;
	Points[21].Normal[0] = 0.0;					Points[21].Normal[1] = 1.0;					Points[21].Normal[2] = 0.0;
	Points[22].Coord[0] = Points[5].Coord[0];	Points[22].Coord[1] = Points[5].Coord[1];	Points[22].Coord[2] = Points[5].Coord[2];
	Points[22].Color[0] = 255;					Points[22].Color[1] = 255;					Points[22].Color[2] = 0;
	Points[22].Normal[0] = 0.0;					Points[22].Normal[1] = 1.0;					Points[22].Normal[2] = 0.0;
	Points[23].Coord[0] = Points[9].Coord[0];	Points[23].Coord[1] = Points[9].Coord[1];	Points[23].Coord[2] = Points[9].Coord[2];
	Points[23].Color[0] = 255;					Points[23].Color[1] = 255;					Points[23].Color[2] = 0;
	Points[23].Normal[0] = 0.0;					Points[23].Normal[1] = 1.0;					Points[23].Normal[2] = 0.0;

	//	массив индексов модели
	PointCount = 24;
	IndexCount = 36;
	Indeces = new GLushort[IndexCount];
	GLubyte Arr[36] = { 0,2,1,	1,2,3,  4,6,7,	7,5,4,	 8,10,11,	11,9,8, 	12,14,13,	13,14,15,	18,17,16,	16,19,18,	20,21,22,	22,23,20 };
	for (int i = 0; i < 36; i++)
	{
		Indeces[i] = Arr[i];
	}
	this->FillVBO();
}
void CModel::CreatePlane(GLfloat Size,GLuint Width, GLuint Height)
{
	delete[] Points;
	delete[] Indeces;

	Points = new ModelPoint[(Width + 1) * (Height + 1)];
	Indeces = new GLushort[6 * Width*Height];

	float HSize = Size / Height;
	float WSize = Size / Width;
	int i = 0;
	float x = -Size / 2;
	float z = x;
	float def_x = x, def_z = z;
	int counter = 0;
	for (unsigned int i = 0; i < ((Width + 1) * (Height + 1)); i++)
	{
		counter++;
		Points[i].Coord[0] = x;     Points[i].Coord[1] = 0;    Points[i].Coord[2] = z;
		Points[i].Color[0] = 143;   Points[i].Color[1] = 143;  Points[i].Color[2] = 143;
		Points[i].Normal[0] = 0.0;  Points[i].Normal[1] = 1.0;   Points[i].Normal[2] = 0.0;
		Points[i].TexCoord[0] = (x+(Size/2))/Size;   Points[i].TexCoord[1] = (z+(Size/2))/Size;
		z = z + WSize;
		if (counter == Width + 1)
		{
			counter = 0;
			x = x + HSize;
			z = def_z;
		}
	}
	counter = 0;
	unsigned int point_count = 0;
	Indeces[0] = 0;
	for (unsigned int i = 0; i < (6 * Width*Height); i++)
	{
		point_count++;
		counter++;

		switch (counter)
		{
		case 1: if (i != 0)
		{
			if (point_count == (6 * Width + 1))
			{
				Indeces[i] = Indeces[i - 1] - Width;
				point_count = 1;
				break;
			}
			else
			{
				Indeces[i] = Indeces[i - 1] - Width-1;
				break;
			}
		}
				else {
					Indeces[i] = 0;
					break;
				}
		case 2: Indeces[i] = Indeces[i - 1] + 1;
			break;
		case 3: Indeces[i] = Indeces[i - 1] + Width;
			break;
		case 4: Indeces[i] = Indeces[i - 1];
			break;
		case 5: Indeces[i] = Indeces[i - 1] - Width;
			break;
		case 6: Indeces[i] = Indeces[i - 1] + Width+1;
			counter = 0;
			break;
		}
	}
	PointCount = (Width + 1) * (Height + 1);
	IndexCount = 6 * Width*Height;
	this->FillVBO();
}

void CModel::Draw()
{
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_VERTEX_ARRAY); 

	glBindBuffer(GL_ARRAY_BUFFER, VBO_Index[0]);
	glClientActiveTexture(GL_TEXTURE0);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	glVertexPointer(3, GL_FLOAT, sizeof(ModelPoint), (GLvoid*)offsetof(ModelPoint, Coord));
	glNormalPointer(GL_FLOAT, sizeof(ModelPoint), (GLvoid*)offsetof(ModelPoint, Normal));
	glTexCoordPointer(2, GL_FLOAT, sizeof(ModelPoint), (GLvoid*)offsetof(ModelPoint, TexCoord));

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, VBO_Index[1]);
	glDrawElements(GL_TRIANGLES, IndexCount, GL_UNSIGNED_SHORT, 0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
}

void CModel::FillVBO()
{
	glGenBuffers(2, VBO_Index);
	glBindBuffer(GL_ARRAY_BUFFER, VBO_Index[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(ModelPoint) * PointCount, Points, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, VBO_Index[1]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLushort) * IndexCount, Indeces, GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void CModel::LoadModel(char* FileName)
{
	std::ifstream modelFile(FileName, std::ios::in | std::ios::binary);
	ModelPoint *Points = NULL;
	WORD *Indeces = NULL;
	ModelPoint *sortPoints = NULL;
	t_chunc_header chunc_header;
	short count;

	std::cout << "[MODEL]: load file \'" << FileName << "\'." << std::endl;

	if (modelFile.is_open())
	{
		while (modelFile.read((char*)&chunc_header, sizeof(t_chunc_header)))
		{
			switch (chunc_header.id)
			{
			case 0x4d4d:
			case 0x3d3d:
			case 0x4100:  break;
			case 0x4000:
				char c;
				do modelFile.read(&c, 1);
				while (c != 0);
				break;
			case 0x4110:
				modelFile.read((char*)&PointCount, sizeof(GLushort));
				Points = new ModelPoint[PointCount];
				for (int i = 0; i < PointCount; i++)
				{
					modelFile.read((char *)&Points[i].Coord, sizeof(float) * 3);
				}
				break;
			case 0x4120:
				modelFile.read((char*)&IndexCount, sizeof(GLushort));
				Indeces = new GLushort[IndexCount * 3];
				for (int i = 0; i < IndexCount; i++)
				{
					modelFile.read((char *)&Indeces[i * 3 + 0], sizeof(GLushort));
					modelFile.read((char *)&Indeces[i * 3 + 1], sizeof(GLushort));
					modelFile.read((char *)&Indeces[i * 3 + 2], sizeof(GLushort));
					modelFile.seekg(sizeof(GLushort), std::ios::cur);
				}
				IndexCount *= 3;
				break;
			case 0x4140:
				modelFile.read((char*)&count, sizeof(short));
				saveTexCoords(&modelFile, count, Points);
				break;
			default:
				modelFile.seekg(chunc_header.len - 6, std::ios::cur);
			}
		}
		modelFile.close();
		sortPoints = new ModelPoint[IndexCount];
		for (WORD i = 0; i < IndexCount; i++)
		{
			sortPoints[i] = Points[Indeces[i]];
			Indeces[i] = i;
		}
		PointCount = IndexCount;

		for (WORD i = 0; i < PointCount; i += 3)
		{
			ModelPoint &a = sortPoints[i + 0];
			ModelPoint &b = sortPoints[i + 1];
			ModelPoint &c = sortPoints[i + 2];
			CalcNormals(&a, &b, &c);
		}

		delete[] Points;
		Points = sortPoints;
		
		glGenBuffers(2, VBO_Index);
		glBindBuffer(GL_ARRAY_BUFFER, VBO_Index[0]);
		glBufferData(GL_ARRAY_BUFFER, sizeof(ModelPoint) * PointCount, Points, GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, VBO_Index[1]);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(WORD) * IndexCount, Indeces, GL_STATIC_DRAW);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

		delete[] Points;
		delete[] Indeces;
	}
	else
		std::cout << "[MODEL]: error uploading file." << std::endl;
}

void CModel::CalcNormals(ModelPoint *a, ModelPoint *b, ModelPoint *c)
{
	GLfloat cross_1[3];
	GLfloat cross_2[3];
	GLfloat normal[3];
	GLfloat distance;

	for (int i = 0, j; i < (PointCount / 3); i++)
	{
		for (j = 0; j < 3; j++)
		{
			cross_1[j] = c->Coord[j] - b->Coord[j];
			cross_2[j] = a->Coord[j] - b->Coord[j];
		}
		normal[0] = cross_1[1] * cross_2[2] - cross_1[2] * cross_2[1];
		normal[1] = cross_1[2] * cross_2[0] - cross_1[0] * cross_2[2];
		normal[2] = cross_1[0] * cross_2[1] - cross_1[1] * cross_2[0];
		distance = sqrt(pow(normal[0], 2) + pow(normal[1], 2) + pow(normal[2], 2));
		normal[0] /= distance;
		normal[1] /= distance;
		normal[2] /= distance;
		a->Normal[0] = normal[0]; a->Normal[1] = normal[1]; a->Normal[2] = normal[2];
		b->Normal[0] = normal[0]; b->Normal[1] = normal[1]; b->Normal[2] = normal[2];
		c->Normal[0] = normal[0]; c->Normal[1] = normal[1]; c->Normal[2] = normal[2];
	}
}

// Считывание текстурных координат
void CModel::saveTexCoords(std::ifstream *file, short count, ModelPoint *pointArray)
{
	for (int i = 0; i < count; i++)
	{
		file->read((char*)pointArray[i].TexCoord, 2 * sizeof(GLfloat));
	}
}