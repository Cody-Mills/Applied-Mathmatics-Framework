#pragma once

#include <directxmath.h>
#include <d3d11_1.h>
#include <string>
#include "Transform.h"

using namespace DirectX;
using namespace std;

struct Geometry
{
	ID3D11Buffer* vertexBuffer;
	ID3D11Buffer* indexBuffer;
	int numberOfIndices;

	UINT vertexBufferStride;
	UINT vertexBufferOffset;
};

struct Material
{
	XMFLOAT4 diffuse;
	XMFLOAT4 ambient;
	XMFLOAT4 specular;
};

class GameObject
{
public:
	GameObject(string type, Geometry geometry, Material material);
	~GameObject();

	string GetType() const { return _type; }

	void SetParent(GameObject * parent) { _parent = parent; }

	// Rendering information
	Geometry GetGeometryData() const { return _geometry; }
	Material GetMaterial() const { return _material; }
	XMMATRIX GetWorldMatrix() const { return XMLoadFloat4x4(&_world); }

	void SetTextureRV(ID3D11ShaderResourceView * textureRV) { _textureRV = textureRV; }
	ID3D11ShaderResourceView* const* GetTextureRV() { return &_textureRV; }
	bool HasTexture() const { return _textureRV ? true : false; }
	void Move(XMFLOAT3 direction);
	void Update(float dt);
	void Draw(ID3D11DeviceContext * pImmediateContext);
	Transform* GetTransform() { return _transform; }

private:
	GameObject* _parent = nullptr;

	string _type;
	XMFLOAT4X4 _world;

	Geometry _geometry;
	Material _material;
	//Reference to _transform
	Transform* _transform = new Transform;
	ID3D11ShaderResourceView* _textureRV = nullptr;
};

